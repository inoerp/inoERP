<?php require_once('bom_overhead.inc') ?>
<script type='text/javascript' src="bom_overhead.js" ></script>
<?php
$search_form = search::search_form('bom_overhead', 'find_bom_overhead', 'bom_overhead_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_overhead', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>