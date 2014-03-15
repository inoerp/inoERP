<?php require_once('bom_material_element.inc') ?>
<script type='text/javascript' src="bom_material_element.js" ></script>
<?php
$search_form = search::search_form('bom_material_element', 'find_bom_material_element', 'bom_material_element_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_material_element', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>