<?php require_once('bom_routing.inc') ?>
<script type='text/javascript' src="bom_routing.js" ></script>
<?php
$search_form = search::search_form('bom_routing', 'find_bom_routing', 'bom_routing_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_routing', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>