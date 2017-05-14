<?php
 $hideContextMenu = true;
 $hideBlock = true;
 if (!empty($_GET['search_class_name'])) {
  $class_names = $_GET['search_class_name'];
  $pageTitle = " $class_names - Select value of $class_names ";
 } else if (!empty($_GET['class_name'])) {
  $class_names = $_GET['class_name'];
  $pageTitle = " $class_names - Select value of $class_names ";
 } else {
  $path_access = -1;
 }
 if (!empty($class_names)) {
  $_GET['window_type'] = 'popover';
  
 include_once(__DIR__.'/includes/functions/loader.inc');
  
  $hidden_field_a = [];
  $hidden_field_a['window_type'] = 'popover';
  //pre populate
  if (method_exists($$class, 'search_pre_populate')) {
   $ppl = call_user_func(array($$class, 'search_pre_populate'));
   if (!empty($ppl)) {
    foreach ($ppl as $search_key => $search_val) {
     $_GET[$search_key] = $search_val;
    }
   }
  }

  //hidden fields used for mandatory fields
  if (method_exists($$class, 'select_hidden_fields')) {
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

  $search = new search();
  $search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
  $search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
  $search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
  $search->setProperty('_searching_class', $class);
  $search->setProperty('_form_post_link', 'select');
  $search->setProperty('_initial_search_array', $$class->initial_search);
  $search_form = $search->search_form($$class);

  if (!empty($pagination)) {
   $pagination->setProperty('_path', 'select');
   $pagination_statement = $pagination->show_pagination();
  }
 }
?>
<?php include_once(THEME_DIR . '/popover_select_page.inc'); ?>
