<?php require_once('bom_material_element.inc') ?>
<?php
$search_form = search::search_form('bom_material_element', 'bom_material_elements', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'bom_material_elements', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>