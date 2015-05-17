<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function autoLoadFromCwd($className) {
 $filename = getcwd() . DS . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
  require $filename;
 }
}

function autoLoadModules($className) {
 $paths = explode('_', $className);
 // echo "paths $paths";
 $path = $paths[0] . '/';
 if (!empty($paths[1])) {
  $path .= $paths[1] . '/';
 }
// $path .= $paths[2] . '/';
 $filename = getcwd() . "/modules/" . $path . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
  require $filename;
 } elseif (is_readable(HOME_DIR . '/modules/' . $path . 'class_' . $className . ".inc")) {
  require HOME_DIR . '/modules/' . $path . 'class_' . $className . ".inc";
 } elseif (!empty($paths[2])) {
  $path .= $paths[2] . '/';
  $filename = HOME_DIR . '/modules/' . $path . 'class_' . $className . ".inc";
  if (is_readable($filename)) {
   require $filename;
  }
 } elseif (!empty($paths[3])) {
  $path .= $paths[3] . '/';
  $filename = HOME_DIR . '/modules/' . $path . 'class_' . $className . ".inc";
  if (is_readable($filename)) {
   require $filename;
  }
 }
}

function autoLoadExtensions($className) {
 $paths = explode('_', $className);
// foreach($paths as $key=>$value){
//	$path .= $key>0 ? str_replace('.inc', '', $value).'/' : null;
// }
 $path = $paths[0] . '/';
 if (!empty($paths[1])) {
  $path .= $paths[1] . '/';
 }
 $filename = getcwd() . "/extensions/" . $path . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
  require $filename;
 } else {
  $filename = HOME_DIR . '/extensions/' . $path . 'class_' . $className . ".inc";
  if (is_readable($filename)) {
   require $filename;
  }
 }
}

function autoLoadTparty($className) {
 $paths = explode('_', $className);
 // echo "paths $paths";
 $path = $paths[0] . '/';
 if (!empty($paths[1])) {
  $path .= $paths[1] . '/';
 }
// $path .= $paths[2] . '/';
 $filename = getcwd() . "/tparty/extensions/" . $path . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
  require $filename;
 } elseif (is_readable(HOME_DIR . '/tparty/extensions/' . $path . 'class_' . $className . ".inc")) {
  require HOME_DIR . '/tparty/extensions/' . $path . 'class_' . $className . ".inc";
 } elseif (is_readable(getcwd() . '/tparty/modules/' . $path . 'class_' . $className . ".inc")) {
  require getcwd() . '/tparty/modules/' . $path . 'class_' . $className . ".inc";
 } elseif (is_readable(HOME_DIR . '/tparty/modules/' . $path . 'class_' . $className . ".inc")) {
  require HOME_DIR . '/tparty/modules/' . $path . 'class_' . $className . ".inc";
 }
}

spl_autoload_register("autoLoadFromCwd");
spl_autoload_register("autoLoadModules");
spl_autoload_register("autoLoadExtensions");
spl_autoload_register("autoLoadTparty");

function pa($array = "") {
 echo '<div class="message">Printing array/object <pre>';
 print_r($array);
 echo '</pre></div>';
}

function ino_protocol() {
 $protocol = (!empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off' || $_SERVER['SERVER_PORT'] == 443) ? "https://" : "http://";
 return $protocol;
}

function getBreadCrumb($class_first) {
 if (property_exists($class_first, 'module') && !property_exists($class_first, 'dont_show_bread_crum')) {
  $module_name = $class_first::$module;
  $module_line = option_line::find_by_optionId_lineCode('182', $module_name);
  if ($module_line) {
   $module_name_c = ucwords($module_line->option_line_value);
   $module_description = ucwords($module_line->description);
  } else {
   $module_name_c = $module_description = strtoupper($module_name);
  }

  $form_bread_crum = '<ul class="inline-list imp-link ino-breadcrumb-simple">';
  $form_bread_crum .= "<li title=\"My Dashboard\" >" . '<a  class="ajax-link" href="' . HOME_URL . 'form.php?class_name=user_dashboard_v"> Dashboard  >> </a></li>';
  $form_bread_crum .= '<li title="' . $module_description . '" ><a  class="ajax-link" href="' . HOME_URL . 'form.php?module_code=' . $module_name . '">&nbsp; ' . $module_name_c . ' </a></li>';
  $form_bread_crum .= '</ul>';
  return $form_bread_crum;
 } else {
  return false;
 }
}

function show_reference_doc($class_name, $primar_column_value) {
 $primary_column = $class_name::$primary_column;
 if ((!empty($class_name)) && (!empty($primar_column_value)) && (!empty($primary_column))) {
  return '<a  href=\'form.php?class_name=' . $class_name . '&' . $primary_column . '=' . $primar_column_value . '&mode=2\' target="_blank">View Reference Doc</a>';
 } else {
  return false;
 }
}

function get_class_name_from_path($path) {
 if (strpos($path, '/') !== false) {
  $arr = explode('/', $path);
 } else {
  $arr = explode('\\', $path);
 }
 $last_el = array_pop($arr);
 $class = str_replace('class_', '', $last_el);
 $class1 = str_replace('class.', '', $class);
 $data['class_name'] = str_replace('.inc', '', $class1);
 $data['module_name'] = isset($arr[1]) ? $arr[1] : '';
 return $data;
}

function ino_arrayObj_to_array($array_obj, $keyname) {
 $ret_a = [];
 foreach ($array_obj as $obj) {
  $ret_a[] = $obj->$keyname;
 }
 return $ret_a;
}

function get_dbColumns($table_name) {
 if (!empty($table_name)) {
  global $dbc;
  $sql_fields = " SHOW COLUMNS FROM  " . $table_name;
  $prepare = $dbc->connection->prepare($sql_fields);
  try {
   $prepare->execute();
  } catch (Exception $e) {
   return false;
  }

  $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
  return !empty($fields) ? ($fields) : false;
 }
}

function get_dbColumns_valIndex($table_name) {
 if (!empty($table_name)) {
  global $dbc;
  $sql_fields = " SHOW COLUMNS FROM  " . $table_name;
  $prepare = $dbc->connection->prepare($sql_fields);
  try {
   $prepare->execute();
  } catch (Exception $e) {
   echo " $table_name not found. Error on functions @L72 " . $e->getMessage();
  }

  $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//   $fields = sort($fields);
  return !empty($fields) ? array_combine($fields, $fields) : false;
 }
}

function check_browser() {
 if (preg_match('/(?i)msie [5-8]/', $_SERVER['HTTP_USER_AGENT'])) {
  echo ($_SERVER['HTTP_USER_AGENT']);
  echo "<h2>Sorry! Your browser is outdated and not compatible with this site!!!</h2> "
  . "Please use any modern browsers such as Firefox, Opera, Chrome, IE 10+ ";
  exit;
 }
}

function ino_inline_action($line_id_cb_val, $hidden_field_a = '', $add_image_class = 'add_row_img', $line_id_cb = 'line_id_cb') {
 global $f;
 $ret_stmt = ' <ul class="inline_action">
           <li class="' . $add_image_class . ' clickable"> <i class="fa fa-plus-circle"></i> </li>
           <li class="remove_row_img clickable"> <i class="fa fa-minus-circle"></i> </li>';
 $ret_stmt .= '<li><input type="checkbox" name="' . $line_id_cb . '" value="' . $line_id_cb_val . '"></li>';
 $ret_stmt .= '<li class="hidden">';
 if (!empty($hidden_field_a)) {
  foreach ($hidden_field_a as $k => $v) {
   $ret_stmt .= $f->hidden_field($k, $v);
  }
 }

 $ret_stmt .= '</li></ul>';

 return $ret_stmt;
}

function access_denied($msg = '') {
// header("Location: access_denied.php?message=$msg");
// redirect_to(HOME_URL . 'access_denied.php');
 $stmt = '<div class="alert alert-danger">
        <div class="jumbotron">
        <h1>Access Denied</h1>
        <p class="lead">ou dont have enough privillage to access the requested page.</p>
        <p><a class="btn btn-success" role="button" href="javascript:history.go(-1)"><span class="button">Click Here </a> to go back to the previous page </p>
';
 if (!empty($msg)) {
  $stmt .= '<p>' . $msg . '</p>';
 }
 $stmt .= ' </div></div>';
 return $stmt;
}

function ino_access_denied_organizationAcess($msg = '') {
 $stmt = ' <div class="alert alert-danger">
        <div class="jumbotron">
        <h1>Access Denied</h1>
        <p class="lead">You dont have organization access required for this document.</p>
        <p><a class="btn btn-success" role="button" href="form.php?class_name=user&mode=2&user_id=' . $_SESSION['user_id'] . '">Click Here </a> to check your access privileges </p>
      </div>
 </div>';
 return $stmt;
}

function ino_access_denied($msg = '') {
 $stmt = ' <div class="alert alert-danger">
        <div class="jumbotron">
        <h1>Access Denied</h1>';
 if (empty($msg)) {
  $stmt .= '<p class="lead">You dont have organization access to this page.</p>';
 } else {
  $stmt .= '<p class="lead">' . $msg . '</p>';
 }

 $stmt .='</div>
 </div>';
 return $stmt;
}

function site_maintenance($msg) {
 echo "<div id='site_maintenance'>";
 include_once(THEME_DIR . '/header.inc');
 echo ("<div class='error message noaccess'> $msg </div></div>");
 include_template('footer.inc');
}

function getrwuPrivilage($rwu_role, $user_role) {

 $prv = 0;
 if ($user_role == 'ADMIN') {
  $prv = 2;
 } else if (!empty($rwu_role) && empty($user_role)) {
  $prv = 0;
 } else if (empty($rwu_role) || ($rwu_role == 'ANONYMOUS')) {
  $prv = 2;
 } else if ($rwu_role == 'BASIC') {
  $prv = (!empty($user_role) && ($user_role != 'ANONYMOUS')) ? 2 : 0;
 }

 return $prv;
}

function ino_icon($icon_type) {
 $fa_icon = '';
 switch ($icon_type) {
  case 'FORM':
   $fa_icon = '<i class="fa fa-list-alt"></i>';
   break;

  case 'SEARCH':
   $fa_icon = '<i class="fa fa-search"></i>';
   break;

  case 'SETUP':
   $fa_icon = '<i class="fa fa-cogs"></i>';
   break;

  case 'PROGRAM':
   $fa_icon = '<i class="fa fa-terminal"></i>';
   break;

  case 'TRANSACTION':
   $fa_icon = '<i class="fa fa-tasks"></i>';
   break;

  case 'REPORT':
   $fa_icon = '<i class="fa fa-pie-chart"></i>';
   break;

  case 'UPLOAD':
   $fa_icon = '<i class="fa fa-upload"></i>';
   break;

  case 'DOCUMENT':
  case 'CONTENT':
   $fa_icon = '<i class="fa fa-file-text-o"></i>';
   break;

  default:
   $fa_icon = '<i class="fa fa-dot-circle-o"></i>';
   break;
 }
 return $fa_icon;
}

function find_by_sql($sql = "") {
 global $dbc;
 $prepare = $dbc->connection->prepare($sql);
 $prepare->execute();
 $result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
 return $result_fetchAll;
}

function number_thousand_converted($number) {
 if ($number > 1000000) {
  $number = round($number / 1000000, 1) . 'M';
 } elseif ($number > 1000) {
  $number = round($number / 1000, 1) . 'K';
 }
 return $number;
}

function ino_number_thousand_converted($number) {
 if ($number > 1000000) {
  $number = round($number / 1000000, 1) . 'M';
 } elseif ($number > 1000) {
  $number = round($number / 1000, 1) . 'K';
 }
 return $number;
}

//search function with $_GET criterias
function ino_getSearch() {
 $whereFields = array();
 if (!empty($_GET['submit_search']) && (!empty($_GET['search_class']))) {
  $class = $_GET['search_class'];
  $$class = new $class;
  $per_page = (int) $_GET['per_page'];
  $pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;
  $column_array = $class::$column_array;
  $search_array = $class::$search_array;
  $table_name = $class::$table_name;
  $key_column = (isset($class::$key_column)) ? $class::$key_column : false;

  if (!empty($_GET['new_column'])) {
   $new_column = $_GET['new_column'];
   array_push($column_array, $new_column);
  }
//to check number of criterias
  $noof_criteria = 0;
  foreach ($search_array as $key => $value) {
   if (!empty($_GET[$value])) {
    if (strpos($value, '_id') !== false) {
     $whereFields[] = sprintf("`%s` = %s ", $value, trim(mysql_prep($_GET[$value])));
    } else {
     $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
    }
    $noof_criteria++;
   }
  }

  if (count($whereFields) > 0) {
// Construct the WHERE clause by gluing the fields - together with a " AND " separator.
   $whereClause = " WHERE " . implode(" AND ", $whereFields);
// And then create the SQL query itself.
   $sql = "SELECT * FROM " . $table_name . $whereClause;
   $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
  } else {
   $sql = "SELECT * FROM " . $table_name;
   $count_sql = "SELECT COUNT(*) FROM " . $table_name;
  }

  if ($key_column) {
   $sql .= ' ORDER BY ' . $key_column . ' ' . 'DESC';
  }

  $total_count = $class::count_all_by_sql($count_sql);

  if (!empty($per_page)) {
   global $pagination;
   $pagination = new pagination($pageno, $per_page, $total_count);
   $sql .=" LIMIT {$per_page} ";
   $sql .=" OFFSET {$pagination->offset()}";
  }

  echo "<br><br><br>sql is $sql";
  $search_result = $class::find_by_sql($sql);
  return !(empty($search_result)) ? $search_result : false;
 }
}

function array_shift2($array) {
 $x = array_shift($array);
 return array_shift($x);
}

function null_instantitae($className) {
 $class = new $className;
 foreach ($class::$field_array as $key => $value) {
  $class->$value = "";
 }
 return $class;
}

function remove_querystring_var($url, $key) {
 $url = preg_replace('/(.*)(\?|&)' . $key . '=[^&]+?(&)(.*)/i', '$1$2$4', $url . '&');
 $url = substr($url, 0, -1);
 return $url;
}

function thisPage_url() {
 $current_page = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
 $protocol = 'http' . (!empty($_SERVER['HTTPS']) ? 's' : '');
 $root = $protocol . '://' . $_SERVER['SERVER_NAME'];
 $current_path = $root . $current_page;
 if (!empty($_GET['class_name'])) {
  $current_path .= '?class_name=' . $_GET['class_name'];
 }
 if ((!empty($_GET['mode'])) && (empty($_GET['class_name']))) {
  if (is_array($_GET['mode'])) {
   $current_path .= '?mode=' . $_GET['mode'][0];
  } else {
   $current_path .= '?mode=' . $_GET['mode'];
  }
 } else if (!empty($_GET['mode'])) {
  if (is_array($_GET['mode'])) {
   $current_path .= '&mode=' . $_GET['mode'][0];
  } else {
   $current_path .= '&mode=' . $_GET['mode'];
  }
 }
 return $current_path;
}

function select_per_page($per_page = '10') {
 $link = $_SERVER['PHP_SELF'] . '?';
 $content_string = '<div class="noOfcontents">';
 $content_string .= 'Show<select name="per_page" class="per_page small">';
 $content_string .= '<option value="3" ';
 $content_string .= ( $per_page == 3) ? ' selected > 3 </option>' : ' > 3 </option>';
 $content_string .= '<option value="5" ';
 $content_string .= ( $per_page == 5) ? ' selected > 5 </option>' : '> 5 </option>';
 $content_string .= '<option value="10" ';
 $content_string .= ( $per_page == 10) ? ' selected > 10 </option>' : '> 10 </option>';
 $content_string .= '<option value="20" ';
 $content_string .= ( $per_page == 20) ? ' selected > 20 </option>' : '> 20 </option>';
 $content_string .= '<option value="50" ';
 $content_string .= ( $per_page == 50) ? ' selected > 50 </option>' : '> 50 </option>';
 $content_string .= '</select>';
 $content_string .= '<a name="content_per_page" '
  . 'href="' . $link . '" class="content_per_page button">Per Page</a>';
 $content_string .= '</div>';
 return $content_string;
}

function select_per_page_array() {
 $array = [
  3 => 3,
  5 => 5,
  10 => 10,
  20 => 20,
  50 => 50,
  'ALL' => 'All'];
 return $array;
}

function ino_print_error($error = "") {
 if (!empty($error)) {
  foreach ($error as $key => $value) {
   echo "<br/> $key : $value ";
  }
 }
}

function ino_date($date, $format = 'Y-m-d') {
 if (empty($date)) {
  return NUll;
 } elseif ($date == '0000-00-00') {
  return NUll;
 } else {
  $date = new DateTime($date);
  return $date->format('Y-m-d');
 }
}

function ino_dateTime($date, $format = 'Y-m-d H:m:s') {
 if (empty($date)) {
  return NUll;
 } elseif ($date == '0000-00-00') {
  return NUll;
 } else {
  $date = new DateTime($date);
  return $date->format('Y-m-d H:i:s');
 }
}

function current_time($only_date = "") {
 $date = new DateTime('NOW');
 if ($only_date) {
  return $date->format('Y-m-d');
 } else {
  return $date->format('Y-m-d H:i:s');
 }
}

// function current_time($only_date = "") {
//  $time = time();
//  if ($only_date) {
//   return strftime("Y-m-d", $time);
//  } else {
//   return strftime("Y-m-d H:m:s", $time);
//  }
// }

function ino_eval($string) {
 ob_start();
 echo eval($string);
 $evaled_string = ob_get_contents();
 ob_end_clean();
 return $evaled_string;
}

//function ino_eval($string) {
// $verify_code = substr($string, 0, 2);
// if ($verify_code == '<?') {
//	ob_start();
//	$string_value = substr($string, 5, strlen($string));
//	print eval($string_value);
//	$evaled_string = ob_get_contents();
//	ob_end_clean();
// } else {
//	$evaled_string = $string;
// }
//
// return $evaled_string;
//}

function include_template($template = "") {
 defined('THEME_DIR') ? null : define('THEME_DIR', DS . 'themes' . DS . 'default');
 if (is_readable(THEME_DIR . DS . $template)) {
  require_once(THEME_DIR . DS . $template);
 } else {
  require_once(INC_BASICS . DS . $template);
 }
}

function show_footer($showBlock = "false") {
 if ($showBlock) {
  include_template('footer.inc');
 } else {
  include_template('footer_simple.inc');
 }
}

function ino_include($theme_dir, $template = "") {
 $include_path = false;
 if (is_readable("$theme_dir/$template")) {
  $include_path = "$theme_dir/$template";
 } elseif (is_readable("$theme_dir/modules/$template")) {
  $include_path = "$theme_dir/modules/$template";
 } elseif (is_readable("$theme_dir/extensions/$template")) {
  $include_path = "$theme_dir/extensions/$template";
 } elseif (is_readable("$template")) {
  $include_path = "$template";
 } else {
  $error = "No template found! for $template in $theme_dir ";
  throw new Exception($error);
 }
 return $include_path;
}

function include_find_page() {
 require_once(INC_BASICS . DS . "find_page.inc");
}

function current_dir_path() {
 $path = dirname($_SERVER[PHP_SELF]);
 $position = strrpos($path, '/');
 $url_wo_file = substr($path, 1, $position);
 $dir_path = 'http://' . $_SERVER['SERVER_NAME'] . '/' . $url_wo_file;
 return $dir_path;
}

function redirect_to($location = NULL) {
 if ($location != NULL) {
  header("Location: {$location}");
  exit;
 }
}

function query_result_issue($result) {
 if (!$result) {
  die("Data base error " . mysql_error());
 }
}

function mysql_prep($value) {
 return $value;
}

function ino_showDecimal($number, $decimal = '.') {
 if ((!empty($number))) {
  $is_neg = ($number < 0 ) ? true : false;
  $exploded_number = explode($decimal, $number);
  if ((!empty($exploded_number[1])) && ((int) $exploded_number[1] > 0 )) {
   $final_number = rtrim(number_format($exploded_number[0]) . $decimal . $exploded_number[1], '0');
//	 echo ' in 1 ';
  } else {
//	 echo ' in 2 ';
   $final_number = number_format($exploded_number[0]);
  }
  $final_number = ($is_neg == true ) ? (-$final_number) : $final_number;
 } else {
//	echo ' in 3 ';
  $final_number = $number;
 }
// echo "$number is $final_number ";
 return $final_number;
}

function get_user_ip() {
 $ipaddress = '';
 if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
  $ipaddress = $_SERVER['HTTP_CLIENT_IP'];
 } else if (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
  $ipaddress = $_SERVER['HTTP_X_FORWARDED_FOR'];
 } else if (!empty($_SERVER['HTTP_X_FORWARDED'])) {
  $ipaddress = $_SERVER['HTTP_X_FORWARDED'];
 } else if (!empty($_SERVER['HTTP_FORWARDED_FOR'])) {
  $ipaddress = $_SERVER['HTTP_FORWARDED_FOR'];
 } else if (!empty($_SERVER['HTTP_FORWARDED'])) {
  $ipaddress = $_SERVER['HTTP_FORWARDED'];
 } else if (!empty($_SERVER['REMOTE_ADDR'])) {
  $ipaddress = $_SERVER['REMOTE_ADDR'];
 } else {
  $ipaddress = 'NOTFOUND';
 }
 return $ipaddress;
}

function get_postArray_From_jqSearializedArray($serialezed_postedArray) {
 $nameArray = [];
 $valueArray = [];
 $postArray = [];
 foreach ($serialezed_postedArray as $array_var) {
  $name = str_replace("[]", "", $array_var['name']);
  $value = $array_var['value'];
  if (!(in_array($name, $nameArray))) {
   array_push($nameArray, $name);
  }
  array_push($valueArray, array($name => $value));
 }

 foreach ($nameArray as $key => $value) {
  $$value = array();
  foreach ($valueArray as $finalArray) {
   if (!empty($value) && array_key_exists($value, $finalArray)) {
    array_push($$value, $finalArray[$value]);
   }
  }

  $postArray[$value] = $$value;
 }
 return $postArray;
}

function content_view_statement($extension_obj, $extension) {
 if (!empty($extension::$view_fields)) {
  $view_filed_array = $extension::$view_fields;
  $content_view_statement = "<ul id=\"content_view_ulid\">";
  foreach ($view_filed_array as $key => $value) {
   $content_view_statement .= "<li class=\"content_details $value \"><ul class=\"content_details_inner_ul\">";
   $content_view_statement .= "<li class=\"key \">$value</li>";
   $object_value = $extension_obj->{$value};
   $content_view_statement .= "<li class=\"value \">$object_value</li>";
   $content_view_statement .= "</ul></li>";
  }
  $content_view_statement .= "</ul>";
 } else {
  $content_view_statement = "<ul id=\"content_view_ulid\">";
  foreach ($extension_obj as $key => $values) {
   $content_view_statement .= "<li class=\"content_details $key \"><ul class=\"content_details_inner_ul\">";
   $content_view_statement .= "<li class=\"key \">$key</li>";
   $content_view_statement .= "<li class=\"value \">$values</li>";
   $content_view_statement .= "</ul></li>";
  }
  $content_view_statement .= "</ul>";
 }
 return $content_view_statement;
}

function ino_delete($data_array) {
 if (empty($data_array)) {
  return false;
 }
 switch ($data_array['deleteType']) {
  case 'header':
   $class = $data_array['class_name'];
   $delete_id = !empty($data_array['delete_id']) ? $data_array['delete_id'] : null;
   break;

  case 'line':
   $class = $data_array['line_class_name'];
   $delete_id = !empty($data_array['delete_id']) ? $data_array['delete_id'] : null;
   break;

  case 'line2':
   $class = $data_array['line2_class_name'];
   $delete_id = !empty($data_array['delete_id']) ? $data_array['delete_id'] : null;
   break;

  case 'detail':
   $class = $data_array['detail_class_name'];
   $delete_id = !empty($data_array['delete_id']) ? $data_array['delete_id'] : null;
   break;

  default :
   break;
 }

 if (empty($delete_id)) {
  echo "<br>Delete Failed!!! No Id selected for delete.";
 }

 $$class = new $class;
 $primary_column = $class::$primary_column;
 $$class->$primary_column = $delete_id;
 $before_delete_result = 1;
 if (method_exists($$class, '_before_delete')) {
  $$class->findBy_Id($delete_id);
  $before_delete_result = $$class->_before_delete();
 }
 if ($before_delete_result == 1) {
  $$class->delete();
 } else {
  echo "<br>Delete is not allowed!";
 }
 return true;
}

//not used can be deleted
//function json_delete($class, $lineName = "") {
// if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
//
//	if (!empty($_GET['line_id'])) {
//	 $delete_id = $_GET['line_id'];
//	} elseif (!empty($_GET['detail_id'])) {
//	 $delete_id = $_GET['detail_id'];
//	} elseif (!empty($_GET[$lineName])) {
//	 $delete_id = $_GET[$lineName];
//	} else {
//	 $delete_id = "";
//	}
//
//	if (!empty($delete_id)) {
//	 $result = $class::delete($delete_id);
//	} else {
//	 $result = "Id to delete is not found";
//	}
//
//	if ($result == 1) {
//	 echo 'Line is deleted!';
//	} else {
//	 global $ie_array_page;
//	 global $ie;
//	 echo '<div class="message"> Error Code - F04! </div> ';
//	 if (!empty($ie_array_page)) {
//		echo $ie->show_pageErrors($ie_array_page);
//	 }
//	}
// }
//}

function ra_conevrt_data($data_a, $label, &$legend_a) {
 $ra_data_a = [];
 $legend_count = 0;
 foreach ($data_a as $data) {
  $data_a = (array) $data;
  $ra_data_element = [];
  $ra_data_element['label'] = $data->$label;
  $ra_data_element['value'] = [];
  unset($data_a[$label]);
  foreach ($data_a as $key => $val) {
   array_push($ra_data_element['value'], $val);
   if ($legend_count == 0) {
    array_push($legend_a, $key);
   }
  }
  array_push($ra_data_a, $ra_data_element);
  $legend_count++;
 }
 return $ra_data_a;
}

function ra_conevrt_data_bar_column($data_a, &$legend, $first_value_legend = true) {
 $legend_a = [];
 $label_a = [];
 $final_data_a = [];
 $count = 0;
 foreach ($data_a[0] as $key1 => $val1) {
  if ($count == 0) {
   $legend_key_name = $key1;
  }
  if ($count == 1) {
   $label_key_name = $key1;
  }
  if ($count == 2) {
   $value_key_name = $key1;
  }
  $count++;
 }


 if ($first_value_legend) {
  $checking_for_legend = 0;
  $checking_for_label = 1;
 } else {
  $checking_for_legend = 1;
  $checking_for_label = 0;
 }
 foreach ($data_a as $data) {
  $count = 0;
  foreach ($data as $key => $val) {
   if ($count == $checking_for_legend) {
    !in_array($val, $legend_a) ? array_push($legend_a, $val) : '';
    break;
   }
   $count++;
  }
 }

 foreach ($data_a as $data1) {
  $count = 0;
  foreach ($data1 as $key1 => $val1) {
   if ($count == $checking_for_label) {
    !in_array($val1, $label_a) ? array_push($label_a, $val1) : '';
    break;
   }
   $count++;
  }
 }

 $legend = $legend_a;

 foreach ($label_a as $label_key => $label_val) {
  $data = [];
  $data['label'] = $label_val;
  $data['value'] = [];
  foreach ($legend_a as $legend_key => $legend_val) {
   $not_found_value = true;
   foreach ($data_a as $this_data_a_key => $this_data_a) {
    if (($this_data_a->$legend_key_name == $legend_val) && ($this_data_a->$label_key_name == $label_val)) {
     array_push($data['value'], $this_data_a->$value_key_name);
     $not_found_value = false;
     unset($data_a[$this_data_a_key]);
     break;
    }
   }
   if ($not_found_value) {
    array_push($data['value'], null);
   }
  }
  array_push($final_data_a, $data);
 }
 return $final_data_a;
}

//bar & column
function ra_conevrt_data_bar_column_wolegend($data_a) {
 $ra_data_a = [];
 foreach ($data_a as $data) {
  $ra_data_element = [];
  $count = 0;
  foreach ($data as $key => $val) {
   if ($count == 0) {
    $ra_data_element['label'] = $val;
   } else {
    $ra_data_element['value'] = $val;
   }
   $count++;
  }
  array_push($ra_data_a, $ra_data_element);
 }
 return $ra_data_a;
}

//pie
function ra_conevrt_data_pie($data_a) {
 $ra_data_a = [];
 foreach ($data_a as $data) {
  $count = 0;
  foreach ($data as $key => $value) {
   if ($count == 0) {
    $pie_k = $value;
   }
   if ($count == 1) {
    $pie_value = $value;
   }
   $count++;
   $ra_data_a[$pie_k] = !empty($pie_value) ? $pie_value : null;
  }
 }
 return $ra_data_a;
}

function search_bom_cost_type() {
 $stmt = '';
 $stmt .= '<select id="bom_cost_type" class="select bom_cost_type" name="bom_cost_type" style="background-color: pink;">';
 $stmt .= '<option value=""></option>';
 $stmt .= '<option value="FROZEN">Frozen</option>
 <option value="PENDING">Pending</option>
<option value="GLOBAL">Global</option>
<option value="FUTURE">Future</option>
<option value="AVERAGE">Average</option>
</select>';
 return $stmt;
}

function search_inv_count_entry_status() {
 global $f;
 return $f->select_field_from_array('status', inv_count_schedule::$status_a, '');
}

function search_depreciation_id() {
 $stmt = '<input id="fa_depreciation_header_id" class="number fa_depreciation_header_id"  required type="text" value=" " name="fa_depreciation_header_id[]">
<img class="fa_depreciation_header_id select_popup clickable" src="http://localhost/inoerp/themes/images/serach.png" style="display: inline-block;">';

 return $stmt;
}

function search_asset_book() {
 global $f;
 $stmt = $f->select_field_from_object('fa_asset_book_id', fa_asset_book::find_all(), 'fa_asset_book_id', 'asset_book_name', '', 'fa_asset_book_id', '', 1);
 return $stmt;
}

//function search_depreciation_period() {
// global $f;
// $stmt = $f->text_field_dm('period_id');
// return $stmt;
//}

function search_depreciation_period() {
 $stmt = '<input id="gl_period_id" class="number gl_period_id"  required type="text" value=" " name="gl_period_id[]">';
 return $stmt;
}

function search_gl_period_name() {
 global $f;
 return $f->select_field_from_object('gl_period_id', gl_period::find_all(), 'gl_period_id', array('period_name', 'ledger_id'), '', 'gl_period_id', '', 1);
}

function search_show_details_cb() {
 global $f;
 return $f->checkBox_field('show_details', '', 'show_details');
}

function search_mds_name() {
 global $f;
 return $f->select_field_from_object('fp_mds_header_id', fp_mds_header::find_all(), 'fp_mds_header_id', 'mds_name', '', 'fp_mds_header_id', '', 1);
}

function search_mrp_name() {
 global $f;
 return $f->select_field_from_object('fp_mrp_header_id', fp_mrp_header::find_all(), 'fp_mrp_header_id', 'mrp_name', '', 'fp_mrp_header_id', '', 1);
}

function search_mrp_name_onevalue() {
 $f = new inoform();
 return $f->select_field_from_object('fp_mrp_header_id', fp_mrp_header::find_all(), 'fp_mrp_header_id', 'mrp_name', '', 'fp_mrp_header_id', '', 1, '', '', 1);
}

function search_minmax_planner() {
 global $f;
 return $f->select_field_from_object('fp_minmax_header_id', fp_minmax_header::find_all(), 'fp_minmax_header_id', 'plan_name', '', 'fp_minmax_header_id', '', 1);
}

function search_org_name() {
 global $f;
 $stmt = $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', '', '', '', 1);
 return $stmt;
}

function search_cut_off_date() {
 global $f;
 $stmt = $f->date_fieldFromToday('date', '');
 return $stmt;
}

function search_asset_number() {
 global $f;
 $stmt = $f->text_field('am_asset_number', '');
 $stmt .= $f->hidden_field_withId('am_asset_id', '');
 $stmt .= '<i class="select_am_asset_number select_popup clickable fa fa-search"></i>';
 return $stmt;
}

function search_sd_store() {
 global $f;
 $stmt = $f->select_field_from_object('sd_store_id', sd_store::find_all(), 'sd_store_id', 'store_name', '', 'sd_store_id');
 return $stmt;
}

function search_legal_org_name() {
 global $f;
 $stmt = $f->select_field_from_object('org_id', org::find_all_legal(), 'org_id', 'org', '', 'org_id');
 return $stmt;
}

function search_legal_org_name_m() {
 global $f;
 $stmt = $f->select_field_from_object('org_id', org::find_all_legal(), 'org_id', 'org', '', 'org_id', '', 1);
 return $stmt;
}

function search_co_number() {
 global $f;
 return $f->text_field('co_number', '');
}

function search_implement_all_cb() {
 $f = new inoform();
 return $f->checkBox_field('implement_all_cb', '');
}

function search_program_mode() {
 global $f;
 $stmt = $f->select_field_from_array('program_mode', array('TEST' => 'Test', 'FINAL' => 'Final'), '', 'program_mode');
 return $stmt;
}

function search_db_name_old() {
 global $f;
 $stmt = $f->text_field_ap(array('name' => 'db_name', 'value' => DB_NAME2, 'readonly' => true));
 return $stmt;
}

function search_convert_to_prod_mode() {
 global $f;
 $stmt = $f->select_field_from_array('convert_to_prod_mode', array('TEST' => 'Test', 'FINAL' => 'Final'), '', 'convert_to_prod_mode');
 return $stmt;
}

function search_exclusion_mode() {
 global $f;
 $stmt = $f->select_field_from_array('exclusion_mode', array('ALL_SETUP' => 'Keep All Setups - Remove Transaction Data', 'LIMITED_SETUP' => 'Keep Important Setups - Remove Transaction & Some Setups ',
  'ONLY_SETUP' => 'Remove All - I Know What I\'m Doing '), '', 'exclusion_mode');
 return $stmt;
}

function search_db_name() {
 global $f;
 $stmt = $f->text_field_ap(array('name' => 'db_name', 'value' => DB_NAME, 'readonly' => true));
 return $stmt;
}

function search_payroll_schedule() {
 global $f;
 $stmt = $f->text_field('hr_payroll_schedule_id', '', '25', 'hr_payroll_schedule_id');
 return $stmt;
}

function search_payroll_process() {
 global $f;
 $stmt = $f->select_field_from_object('hr_payroll_process_id', hr_payroll_process::find_payroll_available_for_cancelAndConfirmation(), 'hr_payroll_process_id', array('proces_name', 'hr_payroll_process_id'), '', 'hr_payroll_process_id');
 return $stmt;
}

function search_forecast_group() {
 global $f;
 $stmt = $f->select_field_from_object('fp_forecast_group_id', fp_forecast_group::find_all(), 'fp_forecast_group_id', 'forecast_group', '', 'fp_forecast_group_id');
 return $stmt;
}

function search_forecast_name() {
 global $f;
 $stmt = $f->select_field_from_object('fp_forecast_header_id', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', '', 'fp_forecast_group_id');
 return $stmt;
}

function search_consume_orders() {
 global $f;
 $stmt = $f->select_field_from_array('consume_orders', fp_forecast_consumption::$consume_orders_a, '', 'consume_orders');
 return $stmt;
}

function search_offset_days() {
 global $f;
 $f = new inoform();
 $stmt = $f->number_field('offset_days', '');
 return $stmt;
}

function search_date() {
 global $f;

 $stmt = $f->date_fieldAnyDay('user_entered_date', '');
 $stmt .= '&nbsp;&nbsp; <label> Use System Date </label>';
 $stmt .= $f->checkBox_field('use_sys_date_cb', '');
 return $stmt;
}

function search_abc_valuation_name() {
 global $f;
 $f = new inoform();
 $stmt = "<span class='abcValuation_withSearchImage'>";
 $stmt .= $f->hidden_field_withId('inv_abc_valuation_id', '');
 $stmt .= "<input type=\"text\" name=\"valuation_name\" value=\" \" 
	  size=\"60\" class=\"textfield abc valuation_name \" "
  . "placeholder=\"Enter the ABC Valuation Name\"  required id=\"valuation_name\" >";
 $stmt .= "<img src=\"" . HOME_URL . "/themes/images/serach.png\" class=\"valuation_name select_popup clickable\" >";
 $stmt .= "</span>";
 return $stmt;
}

function search_org_name_onevalue() {
 global $f;
 $stmt = $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', '', '', '', 1, '', 1);
 return $stmt;
}

function search_business_org() {
 global $f;
 $stmt = $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', '', 'bu_org_id', '', 1, '', '', 1);
 return $stmt;
}

function search_minmax_type() {
 $stmt = '<select class="select planning_method" name="planning_method[]">
<option value=""></option>
<option value="MINMAX">Min Max</option>
<option selected="" value="MULTI_MINMAX">Multi Bin Min Max</option>
</select>';
 return $stmt;
}

function search_quantity() {
 $stmt = '<input id="quantity" class="textfield number quantity" '
  . 'type="number" title="" placeholder="Number" size="20" maxlength="256" value="" '
  . 'name="quantity" >';
 return $stmt;
}

function search_item_id_from() {
 $stmt = '<input id="item_id_from" class="textfield select_item_id item_id_from" '
  . 'type="text" title="" placeholder="From Item Id" size="20" maxlength="256" value="" '
  . 'name="from_item_id" >';
 return $stmt;
}

function search_item_id_m_from() {
 $stmt = '<input id="item_id_from" class="textfield select_item_id item_id_from" '
  . 'type="text" title="" placeholder="From Item Id" size="20" maxlength="256" value="" '
  . 'name="from_item_id_m" >';
 return $stmt;
}

function adjustment_ac_id() {
 $stmt = "<input id='adjustment_ac_id' class='textfield select_account adjustment_ac_id' 
type='text' title='' placeholder='Adjustment Ac' size='28' maxlength='256' 
name='adjustment_ac_id'>
<img class='account_popup' src=" . HOME_URL . "themes/images/serach.png>";
 return $stmt;
}

function search_item_id_to() {
 $stmt = '<input id="item_id_to" class="textfield select_item_id item_id_to" '
  . 'type="text" title="" placeholder="To Item Id" size="20" maxlength="256" value="" '
  . 'name="to_item_id" >';
 return $stmt;
}

function search_item_id_m_to() {
 $stmt = '<input id="item_id_to" class="textfield select_item_id item_id_to" '
  . 'type="text" title="" placeholder="To Item Id" size="20" maxlength="256" value="" '
  . 'name="to_item_id_m" >';
 return $stmt;
}

function search_item_number_from() {

 $stmt = '<input id="item_number_from" class="textfield select_item_number item_number item_number_from" '
  . 'type="text" title="" placeholder="From Item" size="20" maxlength="256" value="" '
  . 'name="from_item_number" >';
 $stmt .= '<i class="select_item_number select_popup clickable fa fa-search"></i>';
 return $stmt;
}

function search_item_number_to() {
 $stmt = '<input id="item_number_to" class="textfield select_item_number item_number item_number_to" '
  . 'type="text" title="" placeholder="To Item" size="20" maxlength="256" value="" '
  . 'name="to_item_number" >';
 $stmt .= '<i class="select_item_number select_popup clickable fa fa-search"></i>';
 return $stmt;
}

function search_payroll() {
 global $f;
 $stmt = $f->select_field_from_object('hr_payroll_id', hr_payroll::find_all(), 'hr_payroll_id', 'payroll', '', 'hr_payroll_id', '', 1);
 return $stmt;
}

function add_new_search_criteria() {
 if (!empty($_GET["new_search_criteria"])) {
  $new_search_criteria = $_GET["new_search_criteria"];
  $new_search_criteria_statment = "<li><label> $new_search_criteria  : </label>";
  $new_search_criteria_statment .= "<input type=\"search\" name=\"$new_search_criteria\" id=\"$new_search_criteria\" 
           value=\"\"  maxlength=\"50\" >";
  echo "$new_search_criteria_statment";
 }
}

function ino_attachement($file, $file_name = 'attachments') {
 $stmt = '<div id="show_attachment" class="show_attachment">
						 <div id="file_upload_form" class="form-group">
							<ul class="inRow asperWidth">
                  <li class="btn btn-info active inline input_file clickable" role="button">
                  <input id="attachments" class="input_file_btn clickable" type="file" multiple="" name="' . $file_name . '[]"></input>
    <i class="fa fa-paperclip clickable"> &nbsp;&nbsp;&nbsp;</i>Select File </li>
							 <li> <button  form="file_upload" name="attach_submit" id="attach_submit" class="btn btn-info active submit button">Attach</button></li>';
 $stmt.='<li class="show_loading_small"><img alt="Loading..." src="' . HOME_URL . 'themes/images/small_loading.gif"/></li>
							</ul>
							<div class="uploaded_file_details"></div>
						 </div>';

 $stmt .= file::attachment_statement($file);
 $stmt .= '</div>';
 return $stmt;
}

function execution_time($only_value = false) {
 $start_time = $_SERVER["REQUEST_TIME"];
 if ($only_value) {
  return (microtime(true) - $start_time);
 } else {
  echo "<br />Execution time :" . (microtime(true) - $start_time) . "</br>";
 }
}

function show_download_button($result_data) {
 $return_stmt = '<div id="searchResultMessages">';
 $return_stmt .='<ul class="inline_list"><li>';
 $return_stmt .='<h3>Total records : ' . count($result_data) . '</h3></li>';
 $return_stmt .= '<li>Download All Data in </li><li>';
 $result_data_all = json_decode(json_encode($result_data), true);
 $return_stmt .= '<form action="' . HOME_URL . 'download.php"  method="POST" name="download_all" id="download_all" target="_blank">';
 $return_stmt .= '<input type="hidden"  name="data" value="' . base64_encode(serialize($result_data_all)) . '" >';
 $return_stmt .= '<input type="radio" name="download_format" checked="checked" value="excel_format">Excel 
     <input type="radio" name="download_format" value="text_format">Text
     <input type="radio" name="download_format" value="pdf_format">Pdf
     <input type="radio" name="download_format" value="xml_format">XML
     <input type="radio" name="download_format" value="worddoc_format">Word Doc
     <input type="submit"  name="export_allResult" value="Download" id="export_excel_allResult" class="clickable button"  >
    </form></li>';
 $return_stmt .= '<li id="export_excel_searchResult" class="clickable"><i class="fa fa-file-excel-o"></i></li>
  <li id="print_searchResult" class="print clickable" title="Print"><i class="fa fa-print"></i></li>
</ul>
</div>';
 return $return_stmt;
}

function array2csv(array &$array) {
 if (count($array) == 0) {
  return null;
 }
 ob_start();
 $df = fopen("php://output", 'w');
 fputcsv($df, array_keys(reset($array)));
 foreach ($array as $row) {
  fputcsv($df, $row);
 }
 fclose($df);
 return ob_get_clean();
}

function array2text(array &$array) {
 if (count($array) == 0) {
  return null;
 }
 ob_start();
 $df = fopen("php://output", 'w');
 fwrite($df, implode('|', array_keys(reset($array))));
 foreach ($array as $row) {
  fwrite($df, PHP_EOL);
  fwrite($df, trim(preg_replace('/\s+/', ' ', implode('|', $row))));
 }
 fclose($df);
 return ob_get_clean();
}

function array2pdf(array &$array, $print_in_browser = true) {
 if (count($array) == 0) {
  return null;
 }
 include(dirname(__FILE__) . "/../../tparty/mpdf/mpdf.php");
 $mpdf = new mPDF('c');

 $html = '';
 foreach ($array as $data) {
  foreach ($data as $key => $value) {
   $html .= "<br> $key : $value";
  }
  $html .= '<br><br>';
 }

 ob_start();
// send the captured HTML from the output buffer to the mPDF class for processing
 $mpdf->WriteHTML($html);
 if ($print_in_browser) {
  download_send_headers("search_record" . date("Y-m-d") . ".pdf", 'pdf_format');
 }
 echo $mpdf->Output();
 return ob_get_clean();
}

function array2worddoc(array &$array) {
 if (count($array) == 0) {
  return null;
 }
 include(dirname(__FILE__) . "/../../tparty/inodoc/class_ino_doc.inc");
 $ino_doc = new ino_doc();

 $ino_data_a = [];
 foreach ($array as $data) {
  $each_para = '';
  foreach ($data as $key => $value) {
   $each_para .= "<br> $key : $value";
  }
  $each_para .='<br><br>';
  array_push($ino_data_a, $each_para);
 }
 ob_start();
 echo $ino_doc->get_document($array);
 return ob_get_clean();
}

function array2xml(array &$array) {
 if (count($array) == 0) {
  return null;
 }

 function createXml($array, $level = 0) {
  $xml = ($level == 0) ? '<?xml version="1.0" encoding="ISO-8859-1"?>' . PHP_EOL : '';
  $tab = str_pad('', $level, '  ', STR_PAD_LEFT);
  foreach ($array as $node => $value) {
   $xml .= "{$tab}<{$node}>";
   if (!is_array($value)) {
    $xml .= $value;
   } else {
    $xml .= PHP_EOL . createXml($value, $level + 1) . $tab;
   }
   $xml .= "</{$node}>" . PHP_EOL;
  }
  return $xml;
 }

 ob_start();
 echo createXml($array, 0);
 return ob_get_clean();
}

function download_send_headers($filename, $download_format = 'text_format') {
 header("Pragma: public");
 header("Expires: 0");
 header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
 header("Content-Type: application/force-download");
 header("Content-Type: application/octet-stream");

 switch ($download_format) {
  case 'excel_format':
   header("Content-Type: text/csv;charset=utf-8");
   break;

  case 'pdf_format':
   header("Content-type:application/pdf");
   break;

  case 'xml_format':
   header("Content-Type: text;charset=utf-8");
   break;

  case 'worddoc_format':
   header("Content-Type: text/doc;charset=utf-8");
   break;

  case 'text_format':
  case 'default' :
   header("Content-Type: text;charset=utf-8");
   break;
 }

// header("Content-Type: application/vnd.ms-excel");
 header("Content-Disposition: attachment;filename={$filename}");
 header("Content-Transfer-Encoding: binary");
}

function translation($string, $namespace = null, array $values = null) {
// Redefine arguments
 $string = (string) $string;

// Find translation
// Return string
 return empty($values) ? $string : strtr($string, $values);
}

function next_monday($date_p) {
 $date = new DateTime($date_p);
 if ($date->format('D') == 'Mon') {
  return $date->format('Y-m-d');
 } else {
  $date = new DateTime("next monday $date_p");
  return $date->format('Y-m-d');
 }
}

function convert_to_url($str) {
 $string = str_replace(' ', '-', trim($str));
 $string_1 = preg_replace('/[^A-Za-z0-9\-]/', '', $string); // Removes special chars.

 return preg_replace('/-+/', '-', $string_1); // Replaces multiple hyphens with single one.
}

function searching_tips() {
 $stmt = '';
 $stmt .= '<div><ul id="search_message">';
 $stmt .= '<li>1. Use = for exact such.';
 $stmt .= '<br>Ex : Supplier name inoerp in supplier field \'ll show all results such as ainoerp, aainoerp, inoerpa, etc';
 $stmt .= '<br>=inoerp in supplier field \'ll show only inoerp </li>';
 $stmt .= '<li>2. Use > for searching values greater than entered value. </li>';
 $stmt .='<li>3. Use < for searching values less than entered value. </li>';
 $stmt .= '<li>4. Use != for searching all values not equal to entered value. </li>';
 $stmt .= '<li>5. Use comma(, ) for searching multiple values. </li>';
 $stmt .= '<li>5. Use one < field & one > field for searching all values in between two values. </li>';
 $stmt .= '</ul></div>';
 return $stmt;
}

function ino_strip_html($text, $max_length) {
 $tags = array();
 $result = "";

 $is_open = false;
 $grab_open = false;
 $is_close = false;
 $in_double_quotes = false;
 $in_single_quotes = false;
 $tag = "";

 $i = 0;
 $stripped = 0;

 $stripped_text = strip_tags($text);

 while ($i < strlen($text) && $stripped < strlen($stripped_text) && $stripped < $max_length) {
  $symbol = $text{$i};
  $result .= $symbol;

  switch ($symbol) {
   case '<':
    $is_open = true;
    $grab_open = true;
    break;

   case '"':
    if ($in_double_quotes)
     $in_double_quotes = false;
    else
     $in_double_quotes = true;

    break;

   case "'":
    if ($in_single_quotes)
     $in_single_quotes = false;
    else
     $in_single_quotes = true;

    break;

   case '/':
    if ($is_open && !$in_double_quotes && !$in_single_quotes) {
     $is_close = true;
     $is_open = false;
     $grab_open = false;
    }

    break;

   case ' ':
    if ($is_open)
     $grab_open = false;
    else
     $stripped++;

    break;

   case '>':
    if ($is_open) {
     $is_open = false;
     $grab_open = false;
     array_push($tags, $tag);
     $tag = "";
    } else if ($is_close) {
     $is_close = false;
     array_pop($tags);
     $tag = "";
    }

    break;

   default:
    if ($grab_open || $is_close)
     $tag .= $symbol;

    if (!$is_open && !$is_close)
     $stripped++;
  }

  $i++;
 }

 while ($tags)
  $result .= "</" . array_pop($tags) . ">";

 return $result;
}

function ino_search_dropDownSettings() {
 $drop_down_icon = '     <div class="dropdown ino_serch_setting">
  <button class="btn btn-default dropdown-toggle btn-group-xs" type="button"  data-toggle="dropdown" aria-expanded="true">
    <i class="glyphicon glyphicon-cog"></i>
    <span class="caret"></span>
  </button>
  <ul class="dropdown-menu" role="menu" aria-labelledby="dropdownMenu1">
    <li role="presentation" class="ino_filter"><a role="menuitem" tabindex="-1" href="#">Filter</a></li>
    <li role="presentation" class="ino_sort_a_z"><a role="menuitem" tabindex="-1" href="#">Sort (a to z)</a></li>
    <li role="presentation" class="ino_sort_z_a"><a role="menuitem" tabindex="-1" href="#">Sort (z to a)</a></li>
  </ul>
</div>';
 return $drop_down_icon;
}

function ino_filter_form() {
 $ino_filter_form = '<div class="filter_area" id="filter_area">
       <div class="well">
        <div class="list_filter row">  
         <div class="col-md-3 col-sm-3  form-group">
          <span role="status" aria-live="polite" class="ui-helper-hidden-accessible"></span>
          <input type="text" class="form-control field_name" name="field_name">
         </div>  
         <div class="col-md-2 col-sm-2  form-group">   
          <select class="condition_name form-control" name="condition_name">    <option value="=">=</option>    
           <option value="">Like</option>    <option value="&gt;=">&gt;=</option>    
           <option value="&lt;=">&lt;=</option>    <option value="&gt;">&gt;</option>    <option value="&lt;">&lt;</option>    
           <option value="IN">In</option>    <option value="!=">!=</option>   </select>  
         </div>  
         <div class="col-md-3 col-sm-3">
          <div class="form-group control">
           <input type="text" class="input-with-feedback form-control condition_value" name="condition_value"  data-fieldtype="Link" data-fieldname="name">
          </div>
         </div>  
         <div class="col-md-4 col-sm-4  condition_action">
          <button class="button btn btn-success apply-filter" type="submit"  name="applyFilter">Apply</button>  
          <button class="button btn btn-info add-element" name="addElement"> + </button> 
          <button class="button btn btn-info remove-element" name="removeElement"> - </button> 
         </div>  
        </div>
       </div>
   </div>
<div class="applied_filters">
      <div class="btn-group">
       <button title="Edit Filter" class="btn btn-default btn-sm toggle-filter"><i class="fa fa-filter"></i></button>
       <button title="Remove Filter" class="btn btn-default btn-sm remove-filter"><i class="fa fa-remove text-muted"></i></button>
      </div>
</div>
';
// <button class="button btn btn-warning remove-filter" type="submit"  name="removeFilter">Remove</button>  
 return $ino_filter_form;
}

function ino_recent_visits() {
 if (isset($_SESSION['recent_visit'])) {
  $recent_visit = '<ul id="recent_visit">';
  $rev_a = array_reverse($_SESSION['recent_visit']);
  $count = 0;
  foreach ($rev_a as $k => $v) {
   $count++;
   if ($count >= 15) {
    break;
   }
   if (!is_numeric($k)) {
    $recent_visit .= '<li><a href="' . $v . '">' . str_replace('_', ' ', substr($k, 0, 30)) . '</a>';
   } else {
    $recent_visit .= '<li><a href="' . $v . '"> Vsiti ' . $k . '</a>';
   }
  }
  $recent_visit .= '<li class="view_all"><a href="' . HOME_URL . 'form.php?class_name=user_activity_v&mode=2"> View More ...</a>';
  $recent_visit .= '</ul>';
 }
 return $recent_visit;
}

function ino_show_collapse_content($content, $length = '350', $divid = 'collapse', $readmore = 'Read More..') {
 if (strlen($content) <= $length) {
  return $content;
 } else {
  $content_small = substr($content, 0, $length);
 }
 $stmt = '<div class="small-content">' . $content_small . '</div>';
 $content_full = substr($content, $length);
 $stmt .= '<button class="btn btn-info" type="button" data-toggle="collapse" data-target="#' . $divid . '" 
  aria-expanded="false" aria-controls="collapseExample">
  ' . $readmore . '
</button>
<div class="collapse" id="' . $divid . '">
  <div class="well">
    ' . $content_full . '
  </div>
</div>';
 return $stmt;
}

function ino_noOfItems_inCart() {
 if (!empty($_SESSION['ec_product_id'])) {
  return count($_SESSION['ec_product_id']);
 } else {
  return 0;
 }
}

?>
