<?php require_once('bom_cost_type.inc') ?>
<script type='text/javascript' src="bom_cost_type.js" ></script>
<?php
$search_form = search::search_form('bom_cost_type', 'find_bom_cost_type', 'bom_cost_type_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_cost_type', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>