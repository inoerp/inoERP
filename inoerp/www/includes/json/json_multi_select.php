<?php 
require_once __DIR__.'/../basics/wloader.inc';
include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc'); ?>
<div id="header_top_container" style="display: block;">
 <?php
 $f->form_button_withImage();
 ?>
</div>
<?php
if (!empty($_GET['search_class_name'])) {

 require_once __DIR__ . '/../../../inoerp_server/locale/gettext.inc';
 $locale = (isset($_SESSION['lang'])) ? $_SESSION['lang'] : DEFAULT_LOCALE;
 $encoding = 'UTF-8';
 T_setlocale(LC_MESSAGES, $locale);
 $domain = 'messages';
 T_bindtextdomain($domain, LOCALE_DIR);
 T_bind_textdomain_codeset($domain, $encoding);
 T_textdomain($domain);

 $class = $class_names = $_GET['search_class_name'];
 $$class = new $class;
 $mode = !empty($_GET['mode']) ? $_GET['mode'] : 9;
 $action_message_asis = !(empty($_GET['action'])) ? $_GET['action'] : null;
 $action_message = is_array($action_message_asis) ? $action_message_asis[0] : $action_message_asis;
 $hidden_field_a = [];
 if (!empty($_GET['action_class_name'])) {
  $action_class = $_GET['action_class_name'];
 } else if (!empty($_GET['class_name'])) {
  $action_class = $_GET['class_name'];
 } else {
  $action_class = $_GET['search_class_name'];
 }

 if (!empty($action_class)) {
  if (is_array($action_class)) {
   $action_class = $action_class[0];
  }
  $action_class_i = new $action_class;
  if (method_exists($action_class_i, 'multi_select_verification')) {
   $action_class_i->multi_select_verification($error_msg);
  }

  IF (property_exists($action_class_i, 'multi_search_primary_column')) {
   $header_id_name = $action_class_i::$multi_search_primary_column;
  } else {
   $header_id_name = null;
  }
  $header_id_value = null;

  if (!empty($_GET[$header_id_name])) {
   $header_id_value = is_array($_GET[$header_id_name]) ? $_GET[$header_id_name][0] : $_GET[$header_id_name];
  }

  if (method_exists($action_class, 'multi_select_tabs')) {
   $multi_select_tabs = $action_class_i->multi_select_tabs();
  }

  if (method_exists($action_class, 'multi_select_actions')) {
   $multi_select_actions = $action_class_i->multi_select_actions();
  }


  if (method_exists($action_class, 'multi_select_input_fields')) {
   $multi_selct_input_fields = $action_class_i->multi_select_input_fields();
  }

  if (method_exists($action_class, 'multi_select_select_fields')) {
   $multi_select_select_fields = $action_class_i->multi_select_select_fields();
  }

  $search_param_values = get_postArray_From_jqSearializedArray($_GET['search_parameters']);

  if (method_exists($action_class, 'multi_select_hidden_fields')) {
   $hidden_field_names = $action_class_i->multi_select_hidden_fields();
   if (!empty($search_param_values)) {
    foreach ($hidden_field_names as $hiden_field_name) {
     if (!empty($search_param_values[$hiden_field_name])) {
      $hidden_field_a[$hiden_field_name] = is_array($search_param_values[$hiden_field_name]) ? $search_param_values[$hiden_field_name][0] : $search_param_values[$hiden_field_name];
     } else {
      $hidden_field_a[$hiden_field_name] = null;
     }
    }
   }
  }
 } else {
  $multi_selct_input_fields = null;
  $hidden_field_names = null;
  $multi_select_select_fields = null;
 }

 /* Start of Search */
 $search = new search();
 if (!empty($_GET['search_order_by'][0])) {
  $s->setProperty('_search_order_by', $_GET['search_order_by'][0]);
 }
 if (!empty($_GET['search_asc_desc'][0])) {
  $s->setProperty('_search_asc_desc', $_GET['search_asc_desc'][0]);
 }
 if (!empty($_GET['per_page'][0])) {
  $s->setProperty('_per_page', $_GET['per_page'][0]);
 }
 $search->setProperty('_searching_class', $class);
 $search->setProperty('_form_post_link', 'multi_select');
 $search->setProperty('_initial_search_array', $$class->initial_search);
 $search->setProperty('_hidden_fields', $hidden_field_a);
 if (is_array($mode)) {
  $search->setProperty('_search_mode', $mode[0]);
 } else {
  $search->setProperty('_search_mode', $mode);
 }
 if (property_exists($$class, 'search_functions')) {
  $s->setProperty('_search_functions', $$class->search_functions);
 }
 $search_form = $search->search_form($$class);

 $table_name = empty($table_name) ? $class::$table_name : $table_name;
 $primary_column = property_exists($$class, 'primary_column') ? $class::$primary_column : $table_name . '_id';


  if (!(empty($_GET['pageno']))) {
  $pageno = is_array($_GET['pageno']) ? (int) $_GET['pageno'][0] : (int) $_GET['pageno'];
 } else {
  $pageno = 1;
 }

 if (!(empty($_GET['per_page']))) {
  $per_page = is_array($_GET['per_page']) ? (int) $_GET['per_page'][0] : (int) $_GET['per_page'];
 } else {
  $per_page = null;
 }

$_GET = $search_param_values;

 $_GET['pageno'] = $pageno;
 $_GET['class_name'] = $class;
 $_GET['per_page'] = !empty($per_page) ? $per_page : $_GET['per_page'];

 if (!empty($_GET['per_page'])) {
  if (!empty($_GET['per_page']) && ($_GET['per_page'] == "all" || $_GET['per_page'][0] == "all")) {
   $per_page = 50000;
  } else if (!empty($_GET['per_page'])) {
   $per_page = (is_array($_GET['per_page'])) ? $_GET['per_page'][0] : $_GET['per_page'];
  }
  $per_page = empty($per_page) ? 10 : $per_page;
 }
 
 
 $search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'][0] : '';
 $search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'][0] : '';
 echo '<div id="json_search_result">';

 //start search
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

 //column details
 if (empty($_GET['column_array'][0])) {
  if (property_exists($class, 'column')) {
   $column_array = $$class->column;
  } else {
   $column_array = $$class->field_a;
  }
 } else {
  $column_array = unserialize(base64_decode($_GET['column_array'][0]));
 }
 if (!empty($_GET['new_column'][0])) {
  $new_column = $_GET['new_column'][0];
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
   array_push($existing_search, $value);
   if (strpos($_GET[$value][0], ',') != false) {
    $comma_sep_search_parameters = explode(',', trim($_GET[$value][0]));
    $comma_sep_search_parameters_in_str = '(\'' . implode('\', \'', $comma_sep_search_parameters) . '\')';
    $whereFields[] = sprintf("%s IN %s ", $value, $comma_sep_search_parameters_in_str);
   } else {
    $entered_search_criteria = str_replace(' ', '%', trim($_GET[$value][0]));
    $entered_search_criteria_1s = substr($entered_search_criteria, 0, 1); //1 character
    $entered_search_criteria_2s = substr($entered_search_criteria, 0, 2); //2 characters
    $entered_search_criteria_m1s = substr($entered_search_criteria, 1); //minus 1 string
    $is_id_eq_search = !(in_array($entered_search_criteria_1s, ['=', '>', '<']) || in_array($entered_search_criteria_2s, ['!=', '>=', '<=']));

    if (($is_id_eq_search) && (strpos($value, '_ID') !== false || strpos($value, '_id') !== false)) {
     if ($entered_search_criteria == 'null') {
      $whereFields[] = " $value IS NULL ";
     } else {
      $whereFields[] = sprintf("%s = %s ", $value, trim(str_replace('=', '', $entered_search_criteria)));
     }
    } else if ($entered_search_criteria_1s == '=') {
     if ($entered_search_criteria_m1s == 'null') {
      $whereFields[] = " $value IS NULL ";
     } else {
      $whereFields[] = sprintf("%s = '%s' ", $value, trim(substr($entered_search_criteria, 1)));
     }
    } else if ($entered_search_criteria_2s == '!=') {
     $whereFields[] = sprintf("%s != '%s' ", $value, trim(substr($entered_search_criteria, 2)));
    } else if ($entered_search_criteria_1s == '>') {
     $whereFields[] = sprintf("%s > '%s' ", $value, trim(substr($entered_search_criteria, 1)));
    } else if ($entered_search_criteria_1s == '<') {
     $whereFields[] = sprintf("%s < '%s' ", $value, trim(substr($entered_search_criteria, 1)));
    } else {
     $whereFields[] = sprintf("%s LIKE '%%%s%%'", $value, trim(mysql_prep($entered_search_criteria)));
    }
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
// pa($whereFields);
 if (count($whereFields) > 0) {
  $whereClause = " WHERE " . implode(" AND ", $whereFields);
  // And then create the SQL query itself.
  $sql = "SELECT * FROM " . $table_name . $whereClause;
  $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
  $all_download_sql = "SELECT * FROM  " . $table_name . $whereClause;
 } else {
  $sql = "SELECT * FROM " . $table_name;
  $count_sql = "SELECT COUNT(*) FROM " . $table_name;
  $all_download_sql = "SELECT * FROM  " . $table_name;
  $whereClause = null;
 }

 if (!empty($_GET['group_by'][0])) {
  $sum_element = $$class->search_groupBy_sum;
  $fetch_as = 'sum_' . $sum_element;
  $sql = "SELECT * , SUM($sum_element) as $fetch_as FROM " . $table_name . $whereClause;
  $sql .= " GROUP BY " . $_GET['group_by'][0];
  $count_sql .= " GROUP BY " . $_GET['group_by'][0];
  $all_download_sql = "SELECT  * , SUM($sum_element) FROM  " . $table_name . $whereClause;
  $all_download_sql .= " GROUP BY " . $_GET['group_by'][0];
 }

 if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
  if (is_array($search_order_by)) {
   $sql .= ' ORDER BY ';
   $all_download_sql .= ' ORDER BY ';
   foreach ($search_order_by as $key_oby => $value_oby) {
    if (empty($search_asc_desc[$key_oby])) {
     $search_asc_desc[$key_oby] = ' DESC ';
    }
    $sql .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
    $all_download_sql .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
   }
   $sql = rtrim($sql, ',');
   $all_download_sql = rtrim($all_download_sql, ',');
  } else {
   $sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
   $all_download_sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
  }
 }

 $total_count = $class::count_all_by_sql($count_sql);

 if (!empty($per_page)) {
  $pagination = new pagination($pageno, $per_page, $total_count);
  $pagination_statement = $pagination->show_pagination();

  $sql .=" LIMIT {$per_page} ";
  $sql .=" OFFSET {$pagination->offset()}";
 }
 
// echo $sql;
 $search_result = $class::find_by_sql($sql);

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
 $s->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
 $s->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
 $s->setProperty('_per_page', $per_page);
 $s->setProperty('primary_column_s', $primary_column);
 $s->setProperty('column_array_s', $column_array);
 if (property_exists($$class, 'option_lists')) {
  $s->option_lists = $$class->option_lists;
 }
 $s->setProperty('_initial_search_array', $$class->initial_search);
// $search_result_statement = $search->search_result();

 /* Start of Search */

 $hidden_field_stmt = $s->hidden_fields();
 if (!empty($pagination)) {
  $pagination->setProperty('_path', 'multi_select');
  $pagination_statement = $pagination->show_pagination();
 }

// echo '<div id="json_search_result">';
 if (!empty($$class) && property_exists($$class, 'multi_select_template_path')) {
  if (empty($readonly)) {
   $s->setProperty('_form_post_link', 'multi_select');
   $search_form = $s->search_form($$class);
  }
  require_once('../../' . $class::$multi_select_template_path);
 } else {
  require_once("../template/json_multi_select_template.inc");
 }

 echo '</div>';
}
?>