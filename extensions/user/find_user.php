<?php
$module_info = [
		array(
				"module" => "user",
				"class" => "user",
				"key_field" => "username",
				"primary_column" => "user_id"
		)
];
$pageTitle = " User - Create & Update all Users ";
$view_path = "user_view";
?>
<?php include_once('../../include/basics/header.inc'); ?>
<script type='text/javascript' src="user.js" ></script>

<?php
$search_form = search::search_form('user', 'find_user', 'user_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'users', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>