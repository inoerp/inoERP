<?php

if (!empty($$class->item_id_m)) {
 $item = new item();
 $item_i = $item->findBy_id($$class->item_id_m);
 if (!empty($item_i)) {
  $$class->item_number = $item_i->item_number;
  $$class->item_description = $item_i->item_description;
 }
}

//category for new content
$cat = new category();
$item_category = category::parent_category_ofType('PRODUCT');
if (!empty($item_category)) {
 $categoriey_select_option = $cat->all_child_category_select_option('category_id', $item_category->category_id);
} else {
 $categoriey_select_option = [];
}

?>
