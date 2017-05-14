<?php

$continue = true;
$readonly1 = false;
$read_access = false;
$write_access = false;
$update_access = false;
$access_level = null;
$no_organization_access = false;
$access_denied_msg = null;
$verify_web_form_allowed = true;
$catalog_stmt = '';
//$_SESSION['debug'] = empty($_SESSION['debug']) ? true : $_SESSION['debug'];

if (empty($mode)) {
 if (!empty($_GET['mode'])) {
  $mode = $_GET['mode'];
 } else {
  $path_access = -99;
  $mode = 1;
 }
}
if ($mode > 8) {
 $readonly = false;
} else {
 $readonly = true;
}
if ($continue) {
 include_once (dirname(__FILE__) . '/../basics/basics.inc');
 $current_url = $protocol_g . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; //$protocol_g defined in define_const files

 global $f;
 global $ie;
 global $s;
 global $dbc;
 global $si;
 $file = null;
 if (count($_SESSION['recent_visit']) >= 10) {
  array_shift($_SESSION['recent_visit']);
 }
 if (!empty($_SERVER['REDIRECT_QUERY_STRING'])) {
  $_SESSION['recent_visit'][$_SERVER['REDIRECT_QUERY_STRING']] = $current_url;
 } else if (!empty($_REQUEST['class_name'])) {
  if (is_array($_REQUEST['class_name'])) {
   $id = $_REQUEST['class_name'][0] . '_id';
   $request_class_name = $_REQUEST['class_name'][0];
  } else {
   $id = $_REQUEST['class_name'] . '_id';
   $request_class_name = $_REQUEST['class_name'];
  }
  if (!empty($_REQUEST[$id]) && !is_array($_REQUEST[$id])) {
   $_SESSION['recent_visit'][$request_class_name . ' Id ' . $_REQUEST[$id]] = $current_url;
  } else {
   $_SESSION['recent_visit'][$request_class_name] = $current_url;
  }
 } else {
  if (isset($_SERVER['QUERY_STRING'])) {
   $_SESSION['recent_visit'][$_SERVER['QUERY_STRING']] = $current_url;
  } else {
   $_SESSION['recent_visit']['QUERY_STRING'] = $current_url;
  }
 }

 /*
  * Check if class is content. If yes, check if any url alias exists
  */
 if (!empty($class_names) && is_array($class_names) && (in_array('content', $class_names))) {
  if (strpos($_SERVER['REQUEST_URI'], "?") !== false) {
   $request_url_lo_a = explode('?', $_SERVER['REQUEST_URI'])[1];
  }
  $alias = htmlentities($_SERVER['QUERY_STRING']);
  $orginal_path_i = ext_url_alias::find_by_urlAlias($alias);
  if (!empty($orginal_path_i)) {
   $_GET['is_alias'] = 1;
   $orginal_path = $orginal_path_i->original_url;
   $path_links = explode('&', $orginal_path);
   foreach ($path_links as $path_link) {
    $path_link_i = explode('=', $path_link);
    $_GET[$path_link_i[0]] = $path_link_i[1];
   }
  }
  if (!empty($request_url_lo_a)) {
   $request_url_lo = explode('&', $request_url_lo_a);
   foreach ($request_url_lo as $request_url_lo_val) {
    if (strpos($request_url_lo_val, "=") !== false) {
     $request_url_lo_val_exp = explode('=', $request_url_lo_val);
     $_GET[$request_url_lo_val_exp[0]] = $request_url_lo_val_exp[1];
    }
   }
  }
 }
 /* --------------------------------------------------------------------------------------------------------------
  * First call the theme class to find out the selected theme.
  * Select the default theme if no theme found
  */
//   $_SESSION['default_theme'] = 'default';
 if (!empty($_SESSION['default_theme'])) {
  $selected_theme = $_SESSION['default_theme'];
 } else {
  set_default_theme();
  $selected_theme = $_SESSION['default_theme'];
 }

 defined('THEME_DIR') ? null : define('THEME_DIR', WWW_DIR . DS . 'themes' . DS . $selected_theme);
 defined('THEME_URL') ? null : define("THEME_URL", HOME_URL . 'themes/' . $selected_theme);
// if(!empty($si->maintenance_cb) && ($si->maintenance_cb == 1) && ($_SESSION['user_roles'][0] !='ADMIN')){
//	site_maintenance($si->maintenance_msg);
// }
} else {
 return;
}
/* Check session */
if (empty($_SESSION['user_id'])) {
 $_SESSION['orginal_page'] = $_SERVER["HTTP_HOST"] . $_SERVER["REQUEST_URI"];
}
/* -----------------------------------------------------------------------------------------------------
  Check if delete request. If yes, complete and return
 */
if ((!empty($_GET['delete'])) && ($_GET['delete'] == 1)) {
 $data_array = $_GET;
 ino_delete($data_array);
 $continue = false;
 return;
}

/* ---------------------------------------------------------------------------------------------------------------
  check if its a search or select page
 * First search for select if not found then check for search page
 * use $noContextMenu or $noBlock
 */
if ((isset($hideContextMenu)) && ($hideContextMenu)) {
 $showContextMenu = false;
} else {
 $showContextMenu = true;
}

if ((isset($hideBlock)) && ($hideBlock)) {
 $showBlock = false;
} else {
 $showBlock = true;
}



/* --------------------------------------------------------------------------------------------------------------
 * First call the role path to verify if the role/user has access to the page.
 * If the page need login, redirect users to login page
 */

if (!empty($_REQUEST['className']) && $_REQUEST['className'] == 'extn_comment') {
 $dont_check_login = true;
}
if (!empty($dont_check_login)) {
 //do nothing
} else {
 $session->redirect_login();
}

/* --------------------------------------------------------------------------------------------------------------
 * Get all the varibles fro $_GET 
 * 
 */

$pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;
if (!empty($_GET['per_page']) && ($_GET['per_page'] == "all" || $_GET['per_page'][0] == "all")) {
 $per_page = 50000;
} else if (!empty($_GET['per_page'])) {
 $per_page = (is_array($_GET['per_page'])) ? $_GET['per_page'][0] : $_GET['per_page'];
}
$per_page = empty($per_page) ? 10 : $per_page;
$search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'] : '';
$search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'] : '';
$query_string = isset($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';

/*
  ---------------------------------------------------------------------------------------------------------------
 *  Determine the class names in case of POST data
 *  
 */
if (!empty($_POST['className'])) {
 unset($class_names);
 $class_names[] = $_POST['className'];
}

//if class names comes as a single value then convert it to an array and all dependent class names
if ((!empty($class_names)) && (!(is_array($class_names)))) {
 $class_names_str = $class_names;
 unset($class_names);
 $class_names = [];
 $class_names[] = $class_names_str;
 if (!(strpos($_SERVER['SCRIPT_NAME'], '/search.php'))) {
  //check if class name is a view. if, yes then change class name for a form_class_name
  if (!empty($form_page) && property_exists($class_names_str, 'form_class_name')) {
   $class_names[0] = $class_names_str = $class_names_str::$form_class_name;
  }
  if (property_exists($class_names_str, 'dependent_classes')) {
   foreach ($class_names_str::$dependent_classes as $key => $dep_class_name) {
    array_push($class_names, $dep_class_name);
   }
  }
 }
} else if ((!empty($class_names)) && (is_array($class_names))) {
 $class_names_str = $class_names[0];
 if (!empty($form_page) && property_exists($class_names_str, 'form_class_name')) {
  $class_names[0] = $class_names_str::$form_class_name;
 }
}


//add comment class for all if not POST
if (empty($_POST) && !in_array('extn_comment', $class_names)) {
 array_push($class_names, 'extn_comment');
}

/* --------------------------------------------------------------------------------------------------------------
 * Initalize all the classes in the module
 */
if (($continue) && (!empty($class_names))) {
 foreach ($class_names as $class_k => $class) {

  //check if site is in disbaled mode and the module is disabled
  if (!empty($si->disabled_action)) {
   $eng_info = engine::find_by_className($class);
   if ($eng_info && $eng_info->enabled_cb != 1) {
    access_denied('Module is disabled and Disable action is activated.<br>Either enable the module to de-activate disable action to proceed further');
   }
  }

  //	$table_name = $class;
  if (class_exists($class)) {
   $$class = new $class;
  } else if ($class == 'index') {
   $continue = false;
   return;
  } else {
   $class = 'user_dashboard_v';
   $class_names[0] = $class;
   $$class = new $class;
  }

  $module = property_exists($class, 'module') ? $class::$module : 'module';
  $primary_column = property_exists($class, 'primary_column') ? $class::$primary_column : false;
  $primary_column2 = property_exists($class, 'primary_column2') ? $class::$primary_column2 : false;
  $primary_column3 = property_exists($class, 'primary_column3') ? $class::$primary_column3 : false;
  $key_field = property_exists($class, 'key_column') ? $class::$key_column : $class . '_id';
  $table_name = property_exists($class, 'table_name') ? $class::$table_name : $class;


  if (property_exists($class, 'field_a')) {
   if ((empty($$class->field_a))) {
    $$class->field_a = get_dbColumns($class);
   }
   if (!empty($$class->field_a)) {
    foreach ($$class->field_a as $key => $value) {
     $$class->$value = NULL;
    }
   }
  }

  //if not posted
  if (empty($_POST)) {
   $class_id = property_exists($class, 'primary_column') ? $class::$primary_column : $table_name . '_id';
   if (!empty($_GET[$class_id])) {
    $class_id_value = filter_var($_GET[$class_id], FILTER_SANITIZE_NUMBER_INT);
    $verify_web_form_allowed = false;
   } else if ($class == 'ino_user' && !empty($_SESSION['ino_user_id'])) {
    $class_id_value = $_SESSION['ino_user_id'];
   } else {
    $class_id_value = null;
    if (property_exists($$class, 'profile_default')) {
     if (!empty($$class->profile_default) && (is_array($$class->profile_default))) {
      foreach ($$class->profile_default as $field_name => $profile_name) {
       $$class->$field_name = $prl->find_default_profile($profile_name)->level_value;
      }
     }
    }
   }

   //-------------------------------------------------------------------------------------
   if (!empty($class_id_value) && (!is_array($class_id_value))) {
    $$class->findBy_id($class_id_value);

    //catalog statement
    if (!empty($class_id_value)) {
     $cat_val = new sys_catalog_value();
     $cat_val->reference_table = $class;
     $cat_val->reference_id = $class_id_value;
     $catalog_stmt = $cat_val->catalog_stmt();
    }

//validate organization access where applicable
    if (property_exists($$class, 'org_id') && (!in_array($class, array('org', 'legal', 'ec_product_view')))) {
     if (empty($_SESSION['user_org_access'])) {
      $no_organization_access = true;
      return;
     }
     $doc_org_id_loader = $$class->org_id;
     if (!empty($doc_org_id_loader) && !in_array($doc_org_id_loader, array_keys($_SESSION['user_org_access']))) {
      $no_organization_access = true;
      return;
     } else if (isset($_SESSION['user_org_access'][$doc_org_id_loader])) {
      $mode = $_SESSION['user_org_access'][$doc_org_id_loader];
     }
    } else if (property_exists($$class, 'bu_org_id') && (!in_array($class, array('org', 'ec_product_view')))) {
     if (empty($_SESSION['user_org_access'])) {
      $no_organization_access = true;
      return;
     }
     $doc_org_id_loader = $$class->bu_org_id;
     if (!empty($doc_org_id_loader) && !in_array($doc_org_id_loader, array_keys($_SESSION['user_org_access']))) {
      $no_organization_access = true;
      return;
     } else if (isset($_SESSION['user_org_access'][$doc_org_id_loader])) {
      $mode = $_SESSION['user_org_access'][$doc_org_id_loader];
     }
    }

    try {
     $file = extn_file::find_by_reference_table_and_id($table_name, $class_id_value);
    } catch (Exception $e) {
     
    }

    try {
     $comments = extn_comment::comment_list($table_name, $class_id_value, $class_id_value);
    } catch (Exception $e) {
     
    }
    if (($class != 'extn_contact')) {
     $all_contacts = extn_contact::find_by_reference($table_name, $class_id_value);
    }
    if ($class != 'category') {
     $category = category::find_by_reference_table_and_id($table_name, $class_id_value);
    }
    if (method_exists($$class, '_before_showing')) {
     $$class->_before_showing();
    }
   }

   /* --------------------------------Check for Secondary Fields------------------------------------------------------ */
   $sec_field_i = new sys_secondary_field_inst();
   $secondary_field_object = sys_secondary_field_inst::find_by_referenceKey($class);
   if ($secondary_field_object) {
    $secondary_field_stmt = sys_secondary_field_inst::secondary_field_stmt($secondary_field_object, $class_id_value);
   }

   /* --------------------------------End of Secondary Fields------------------------------------------------------ */
   unset($class_id_value);
   /*
    * ---------------------------------------------------SEARCH-----------------------------------------------
    */

   if ((!empty($_GET['submit_search'])) && (!empty($_GET['search_class_name'])) && ($_GET['search_class_name'] === $class)) {
//	 if ((!empty($_GET['submit_search'])) && (!empty($_GET['search_class_name']) && $class !='comment' )) {
    $search_array = $$class->field_a;
    global $search_result_statement;

    //pre populate
    if (method_exists($$class, 'search_pre_populate')) {
     $ppl = call_user_func(array($$class, 'search_pre_populate'));
     if (!empty($ppl)) {
      foreach ($ppl as $search_key => $search_val) {
       $_GET[$search_key] = $search_val;
      }
     }
    }

    if (empty($_GET['column_array'])) {
     if (property_exists($class, 'column')) {
      $column_array = $$class->column;
     } else {
      $column_array = $$class->field_a;
     }
    } else {
     $column_array = unserialize(base64_decode($_GET['column_array']));
    }
    if (!empty($_GET['new_column'])) {
     $new_column = $_GET['new_column'];
     if (!empty($new_column)) {
      foreach ($new_column as $key => $value) {
       if ((!(is_array($value))) && (!empty($value))) {
        array_push($column_array, $value);
       }
      }
     }
    }

    $whereFields = [];
    $sqlWhereFields = [];
    $existing_search = [];
//to check number of criterias
    $noof_criteria = 0;
    foreach ($search_array as $key => $value) {

     if (!empty($_GET[$value][0])) {
      $entered_search_criteria = str_replace(' ', '%', trim($_GET[$value][0]));
      array_push($existing_search, $value);
      if (strpos($value, '_ID') !== false) {
       $whereFields[] = sprintf("%s = %s ", $value, trim(str_replace('=', '', $entered_search_criteria)));
      } else if (substr($entered_search_criteria, 0, 1) == '=') {
       $whereFields[] = sprintf("%s = '%s' ", $value, trim(substr($entered_search_criteria, 1)));
      } else if (substr($entered_search_criteria, 0, 2) == '!=') {
       $whereFields[] = sprintf("%s != '%s' ", $value, trim(substr($entered_search_criteria, 2)));
      } else if (substr($entered_search_criteria, 0, 1) == '>') {
       $whereFields[] = sprintf("%s > '%s' ", $value, trim(substr($entered_search_criteria, 1)));
      } else if (substr($entered_search_criteria, 0, 1) == '<') {
       $whereFields[] = sprintf("%s < '%s' ", $value, trim(substr($entered_search_criteria, 1)));
      } else if (strpos($entered_search_criteria, ',') != false) {
       $comma_sep_search_parameters = explode(',', $entered_search_criteria);
       $comma_sep_search_parameters_in_str = '(\'' . implode('\', \'', $comma_sep_search_parameters) . '\')';
       $whereFields[] = sprintf("%s IN %s ", $value, $comma_sep_search_parameters_in_str);
      } else {
       $whereFields[] = sprintf("%s LIKE '%%%s%%'", $value, trim(mysql_prep($entered_search_criteria)));
      }
      $noof_criteria++;
     }

     if (!empty($_GET[$value][1])) {
      array_push($existing_search, $value);
      if (substr($_GET[$value][1], 0, 1) == '>') {
       $whereFields[] = sprintf("%s > '%s' ", $value, trim(substr($_GET[$value][1], 1)));
      } else if (substr($_GET[$value][1], 0, 1) == '<') {
       $whereFields[] = sprintf("%s < '%s' ", $value, trim(substr($_GET[$value][1], 1)));
      }
      $noof_criteria++;
     }
    }
    if (!empty($_GET['report_name'])) {
     $report_name = is_array($_GET['report_name']) ? $_GET['report_name'][0] : $_GET['report_name'];
     if (method_exists($$class, $report_name)) {
      $search_result_statement = call_user_func(array($$class, $report_name), $_GET);
     }
    } else if ((!empty($_GET['function_name']))) {
     $function_name = is_array($_GET['function_name']) ? $_GET['function_name'][0] : $_GET['function_name'];
     if (method_exists($$class, $function_name)) {
      $search_counts = $function_name . '_search_counts';
      $search_records = $function_name . '_search_records';
      $whereClause = implode(" AND ", $whereFields);
      $_GET['whereClause'] = $whereClause;
      $total_count = call_user_func(array($$class, $search_counts), $_GET);
      $search_result = call_user_func(array($$class, $search_records), $_GET);
      if (!empty($per_page) && !empty($total_count)) {
       $pagination = new pagination($pageno, $per_page, $total_count);
       $pagination->setProperty('_query_string', $query_string);
       $pagination_statement = $pagination->show_pagination();
      }
     }
    } else if (method_exists($$class, 'search_records')) {
     $whereClause = implode(" AND ", $whereFields);
     $_GET['whereClause'] = $whereClause;
     $total_count = call_user_func(array($$class, 'search_counts'), $_GET);
     $search_result = call_user_func(array($$class, 'search_records'), $_GET);
     if (!empty($per_page) && !empty($total_count)) {
      $pagination = new pagination($pageno, $per_page, $total_count);
      $pagination->setProperty('_query_string', $query_string);
      $pagination_statement = $pagination->show_pagination();
     }
    } else {
     require_once 'loader_search.inc';
    }

    if (empty($search_result_statement)) {
     if (method_exists($class, 'search_add_extra_fields')) {
      $class::search_add_extra_fields($search_result);
     }

     if (property_exists($class, 'search')) {
      foreach ($$class->search as $searchParaKey => $searchParaValue) {
       $s->setProperty($searchParaKey, $searchParaValue);
      }
     }

     $s->setProperty('result', $search_result);
     $s->setProperty('_searching_class', $class);
     $s->setProperty('_per_page', $per_page);
     $s->setProperty('primary_column_s', $primary_column);
     $s->setProperty('column_array_s', $column_array);
     $search_result_statement = $search->search_result_op();
    }
   }
  }
  //---------------------------------------END OF SEARCH------------------------------------------------

  /* -------------------------------------START OF SAVE---------------------------------------------------- */ elseif ((empty($_POST['download'])) && !empty($_POST['className'])) {
   $inosave = new inosave();
   $inosave->setProperty('_module', $module);
   $inosave->setProperty('_classname', $class);
   if (!empty($_POST['detail_classname'])) {
    $inosave->setProperty('_detail_classname', $_POST['detail_classname']);
   }
   $inosave->setProperty('_key_field', $key_field);
   $inosave->setProperty('_primary_column', $primary_column);
   $inosave->setProperty('_primary_column2', $primary_column2);
   $inosave->setProperty('_primary_column3', $primary_column3);
   $inosave->json_save();
//    pa($inosave);
   $dbc->confirm();
   $continue = false;
   return;
  }
  /* -------------------------------------END OF SAVE---------------------------------------------------- */
 }
 /* -------------------------------------START OF SAVE---------------------------------------------------- */
} else {

 $continue = false;
 return;
}

//Assign dependet classes to class_second & class_third and so on
$class_first = $class = $class_names[0];
//$$class_first = $$class_names[0];
$class_id_first = property_exists($class, 'primary_column') ? $class::$primary_column : $class_id = $class . '_id';

if (isset($class_names[1])) {
 $class_second = $class_names[1];
 $$class_second = new $class_second;
 //$$class_second = $$class_names[1];
 $line_obj = $class_second . '_object';
 if (property_exists($class, 'primary_column')) {
  $primar_column_class1 = $class::$primary_column;
  $order_by_field = !empty($class_second::$query_order_by_field) ? $class_second::$query_order_by_field : '';
  $order_by_value = !empty($class_second::$query_order_by_value) ? $class_second::$query_order_by_value : ' ASC ';
  $$line_obj = [];
  array_push($$line_obj, $$class_second);
  if (!empty($$class->$primar_column_class1) && (!empty($class_second::$parent_primary_column))) {
   $$line_obj = $$class_second->findBy_parentId($$class->$primar_column_class1, $order_by_field, $order_by_value);
   if (empty($$line_obj)) {
    $$line_obj = [];
    array_push($$line_obj, $$class_second);
   }
  }
 }
// echo($line_obj);
}

if (isset($class_names[2])) {
 $class_third = $class_names[2];
 //$$class_third = $$class_names[2];
}

if (isset($class_names[3])) {
 $class_fourth = $class_names[3];
 //$$class_fourth = $$class_names[3];
}


///////////////////////////set the mode & readonly - readonly1
if (property_exists($class, 'primary_column')) {
 $primary_column = $class::$primary_column;
}
if (!empty($$class->$primary_column)) {
 $readonly1 = true;
 $readonly1_class = ' always_readonly ';
} else {
 $readonly1 = false;
 $readonly1_class = '  ';
}

if ($readonly) {
 $f->readonly = $readonly;
}


if (($class == 'content') && (!empty($content->subject))) {
 $pageTitle = $content->subject;
} else if (is_object($$class)) {
 $pageTitle = property_exists($$class, 'pageTitle') ? $$class->pageTitle : 'inoERP';
}



if (!empty($_GET['delete'])) {
 $continue = false;
 return;
}
//change mode for contents

if (!empty($_SESSION['user_roles'])) {
 if (in_array('ADMIN', $_SESSION['user_roles'])) {
  $access_level = 9;
  $read_access = $write_access = $update_access = true;
 } else {
  if (!empty($_SESSION['role_access'])) {
//    pa($_SESSION['role_access']);
   foreach ($_SESSION['role_access'] as $obj_name => $acc_level) {
    if ($obj_name == $class) {
     $access_level = $acc_level;
     break;
    }
   }
  }
 }

 require_once 'loader_access.inc';
} else {
 $mode = 2;
}

// echo "<br> class_first is $class_first access_level is $access_level .line ".__LINE__; pa($$class_first);

/* -----------------------------------------include all include files -------------------------------------- */
if ($continue && !empty($form_page)) {
 $reflector = new ReflectionClass($class);
 $fnname = $reflector->getFileName();
 $fdir = dirname($fnname);

 $include_file_names = glob($fdir . DS . "*.inc");
 $css_file_names = glob($fdir . "/*.css");

 if ($showContextMenu) {
  $js_file_names = glob($fdir . "/*.js");
  $js_file_paths = [];
  foreach ($js_file_names as $key => $js_file_name) {
   if (strpos($js_file_name, 'modules')) {
    $js_file_path = str_replace('\\', '/', substr($js_file_name, strpos($js_file_name, 'modules')));
   } else if (strpos($js_file_name, 'extensions')) {
    $js_file_path = str_replace('\\', '/', substr($js_file_name, strpos($js_file_name, 'extensions')));
   }
   array_push($js_file_paths, $js_file_path);
  }
 }

 $css_file_paths = [];
 foreach ($css_file_names as $key => $css_file_name) {
  if (strpos($css_file_name, 'modules')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'modules')));
  } else if (strpos($css_file_name, 'extensions')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'extensions')));
  } else if (strpos($css_file_name, 'engine')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'engine')));
  }
  array_push($css_file_paths, $css_file_path);
 }

 foreach ($include_file_names as $key => $pathname) {
  include_once "$pathname";
 }
 $custom_inc_file_name = HOME_DIR . '/custom/include/' . $class . '_include.inc';
 if (file_exists($custom_inc_file_name)) {
  include_once "$custom_inc_file_name";
 }

 if (empty($template_file_names)) {
  $custom_template_name = THEME_DIR . '/template/' . $class . '_template.php';
  $role_custom_template_name = '';
  if (isset($_SESSION['user_roles']) && !empty($_SESSION['user_roles'])) {
   $primary_user_role = $_SESSION['user_roles'][0];
   $role_custom_template_name = THEME_DIR . '/template/' . $primary_user_role . '_' . $class . '_template.php';
  }
  if (!empty($role_custom_template_name) && file_exists($role_custom_template_name)) {
   $template_file_names = [$role_custom_template_name];
  } else if (file_exists($custom_template_name)) {
   $template_file_names = [$custom_template_name];
  } else {
   $template_file_names = glob($fdir . DS . "*_template.php");
   if (empty($template_file_names)) {
    $template_file_names = [THEME_DIR . '/template/default_template.inc'];
   }
  }
 }
} else {
 return;
}
?>
