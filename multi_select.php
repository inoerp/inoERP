<?php
$hideContextMenu = true;
$hideBlock = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
 $pageTitle = " $class_names - Select value of $class_names ";
} else {
 $path_access = -1;
}
if (!empty($class_names)) {
 include_once("includes/functions/loader.inc");
	$action_message = !(empty($_GET['action'])) ? $_GET['action'] : null;
  $hidden_field_a = [];
	
	if (!empty($_GET['action_class_name'])) {
	$action_class = $_GET['action_class_name'];
	}else{
	 $action_class = $_GET['class_name'];
	}
	
 if (!empty($action_class)) {
	$action_class_i = new $action_class();
	IF(property_exists($action_class_i, 'multi_search_primary_column')){
	$header_id_name = $action_class_i::$multi_search_primary_column;
	}else{
	 $header_id_name = null;
	}
	$header_id_value = null;

	if(!empty($_GET[$header_id_name])){
	$header_id_value = $_GET[$header_id_name];
	}
	if (method_exists($action_class, 'multi_select_input_fields')) {
	 $multi_selct_input_fields = $action_class_i->multi_select_input_fields();
	}
	if (method_exists($action_class, 'multi_select_hidden_fields')) {
	 	 $hidden_field_names = $action_class_i->multi_select_hidden_fields();
	 if (!empty($_GET)) {
		foreach ($hidden_field_names as $hiden_field_name) {
		 if (!empty($_GET[$hiden_field_name])) {
			$hidden_field_a[$hiden_field_name] = $_GET[$hiden_field_name];
		 } else {
			$hidden_field_a[$hiden_field_name] = null;
		 }
		}
	 }
	}
 } else {
	$multi_selct_input_fields = null;
	$hidden_field_names = null;
 }
// 
// pa($hidden_field_names);
//// pa($multi_selct_input_fields);
//// pa($hidden_field_a);

 $search = new search();
 $search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
 $search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
 $search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
 $search->setProperty('_searching_class', $class);
 $search->setProperty('_form_post_link', 'multi_select');
 $search->setProperty('_initial_search_array', $$class->initial_search);
 $search->setProperty('_hidden_fields', $hidden_field_a);
 $search_form = $search->search_form($$class);



 if (!empty($pagination)) {
	$pagination->setProperty('_path', 'select');
	$pagination_statement = $pagination->show_pagination();
 }
}
?>
<?php require_once(INC_BASICS . DS . "multi_select_page.inc") ?>