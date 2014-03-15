<?php require_once('bom_resource.inc') ?>
<script type='text/javascript' src="bom_resource.js" ></script>
<?php
$search_form = search::search_form('bom_resource', 'find_bom_resource', 'bom_resource_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_resource', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>