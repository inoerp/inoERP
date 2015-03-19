<?php

if (!empty($_GET['am_asset_id']) && empty($am_activity_reference_object)) {
 $am_activity_reference_object = am_activity_reference::find_by_parent_id($_GET['am_asset_id']);
}

if (empty($am_activity_reference_object)) {
 $am_activity_reference_object = [new am_activity_reference()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($am_activity_reference_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

if (empty($$class->type)) {
 $$class->type = 'CAPITALIZED';
}

if (!empty($$class->item_id_m)) {
 $item = new item();
 $item_i = $item->findBy_id($$class->item_id_m);
 if (!empty($item_i)) {
  $$class->item_number = $item_i->item_number;
  $$class->item_description = $item_i->item_description;
 }
}
?>
