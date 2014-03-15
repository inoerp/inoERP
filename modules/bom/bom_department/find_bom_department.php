<?php require_once('bom_department.inc') ?>
<script type='text/javascript' src="bom_department.js" ></script>
<?php
$search_form = search::search_form('bom_department', 'find_bom_department', 'bom_department_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_department', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>