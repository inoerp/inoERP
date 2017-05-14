<?php
set_time_limit(300);
/* $header_id_name and $header_id_value is used only in case of AP/PO matching
 * Serach class is PO and action class is AP Line but to save AP line, AP Header Id is required and teh value
 * is stored in $header_id_value
 * 
 */
 require_once __DIR__.'/includes/basics/wloader.inc';
$hideContextMenu = true;
$hideBlock = true;
$show_block = 1;
if ((!empty($_GET['show_block'])) && (($_GET['show_block'][0] == 1) || ($_GET['show_block'] == 1))) {
 $hideBlock = false;
 $show_block = 1;
}
if (!empty($_GET['search_class_name'])) {
 $class_names = $_GET['search_class_name'];
 $pageTitle = " $class_names - Select value of $class_names ";
} else if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
 $pageTitle = " $class_names - Select value of $class_names ";
} else {
 $access_denied_msg = 'In correct class defination/election. Error @ multi_select @@ line '.__LINE__;
}


if (!empty($class_names)) {

include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
 if (empty($access_level) || ($access_level < 3 )) {
  access_denied();
  return;
 }
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

  if (method_exists($action_class, 'multi_select_hidden_fields')) {
   $hidden_field_names = $action_class_i->multi_select_hidden_fields();
   if (!empty($_GET)) {
    foreach ($hidden_field_names as $hiden_field_name) {
     if (!empty($_GET[$hiden_field_name])) {
      $hidden_field_a[$hiden_field_name] = is_array($_GET[$hiden_field_name]) ? $_GET[$hiden_field_name][0] : $_GET[$hiden_field_name];
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
// 
// pa($hidden_field_names);
//// pa($multi_selct_input_fields);
//// pa($hidden_field_a);

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
 $search->setProperty('_show_block', $show_block);
 if (property_exists($$class, 'search_functions')) {
  $s->setProperty('_search_functions', $$class->search_functions);
 }

 $search_form = $search->search_form($$class);

 $hidden_field_stmt = $search->hidden_fields();
 if (!empty($pagination)) {
  $pagination->setProperty('_path', 'multi_select');
  $pagination_statement = $pagination->show_pagination();
 }
}
?>

<?php
if ($continue) {
 if (!empty($$class) && property_exists($$class, 'multi_select_template_path')) {
  $template_file_names = [$class::$multi_select_template_path];
 } else if (!empty($$class)) {
  $template_file_names = ['includes/basics/multi_select_page.inc'];
 }
 if (!empty($_GET['window_type']) && $_GET['window_type'] == 'popup') {
  include_once(THEME_DIR . '/popup_main_template.inc');
 } else {
  include_once(THEME_DIR . '/main_template.inc');
 }
} else {
 $continue = false;
 echo "<h2>Could n't call the header</h2>";
 return;
}
If (!empty($action_class_i) && property_exists($action_class_i, 'js_fileName')) {
 ?>
 <script src="<?php echo HOME_URL . $action_class_i::$js_fileName; ?>"></script>	 
<?php } ?>


<!--<script type="text/javascript">
 $(document).ready(function () {
//  $.getScript("includes/js/erp.js");
    if (!$("link[href='includes/ecss/search.css']").length) {
   $('<link href="includes/ecss/search.css" rel="stylesheet">').appendTo("head");
  }
 });
</script>-->