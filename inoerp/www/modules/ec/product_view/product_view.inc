<?php

if (!empty($$class->item_id_m)) {
 $item = new item();
 $item_i = $item->findBy_id($$class->item_id_m);
 if (!empty($item_i)) {
  $$class->item_number = $item_i->item_number;
  $$class->item_description = $item_i->item_description;
  $$class->long_description = $item_i->long_description;
 }
} else {
 $$class->item_description = $$class->long_description = null;
}

//category for new content
$cat = new category();
$item_category = category::parent_category_ofType('PRODUCT');
if (!empty($item_category)) {
 $categoriey_select_option = $cat->all_child_category_select_option('category_id', $item_category->category_id);
} else {
 $categoriey_select_option = [];
}

if (empty($category) && !empty($_GET['category_id'])) {
 $category_detials = $cat->findBy_id($_GET['category_id']);
}


//Priority Category
$priority_category = null;
if (!empty($category)) {
 foreach ($category as $cat1) {
  if (empty($priority_category)) {
   $priority_category = $cat1->category_id;
   $priority = $cat1->priority;
  } else if ($cat1->priority > $priority) {
   $priority_category = $cat1->category_id;
   $priority = $cat1->priority;
  }
 }
}else if(!empty($_GET['category_id'])){
 $priority_category = $_GET['category_id'];
}else if(!empty($item_category)){
 $priority_category = $item_category->category_id;
 $category_detials = $cat->findBy_id($priority_category);
}

//catalog
$cat_val = new sys_catalog_value();
$cat_val->reference_table = 'ec_product';
$cat_val->reference_id = $$class->ec_product_id;
$catalog_stmt = $cat_val->catalog_stmt();

//rating info
$rating_details = extn_rating_values::find_by_reference('ec_product', $$class->ec_product_id);
if (!empty($rating_details) && !empty($rating_details->rating_count)) {
 $rating_count = $rating_details->rating_count;
 $rating_avg = round($rating_details->rating_value / $rating_details->rating_count);
} else {
 $rating_count = $rating_avg = 0;
}
for ($i = 0; $i <= 5; $i++) {
 $star_v = 'star_' . $i;
 if ($rating_avg >= $i) {
  $$star_v = 'fa fa-star ';
 } else {
  $$star_v = 'fa fa-star-o ';
 }
}

if (!empty($$class->list_price)) {
 $list_price = $$class->list_price;
 $sales_price = number_format($$class->sales_price);
 $save_p = round((($list_price - $sales_price) / $list_price) * 100);
} else {
 $sales_price = $save_p = null;
}


if (!empty($$class->ec_product_id)) {
 $custom_template_name = __DIR__ . DS . 'product_view_template.php';
 if (file_exists($custom_template_name)) {
  $template_file_names = [$custom_template_name];
 }
} else if (!empty($category_detials)) {
 $custom_template_name = __DIR__ . DS . 'templates' . DS . 'product_category_template.php';
 if (file_exists($custom_template_name)) {
  $template_file_names = [$custom_template_name];
 }
}


//check if user is allowed to update the content
$allow_content_update = false;
if((!empty($_SESSION['username'])) && ($$class->created_by == $_SESSION['username'])){
 $allow_content_update = true;
}elseif((!empty($_SESSION['user_roles']))&&(in_array('ADMIN',$_SESSION['user_roles']))){
 $allow_content_update = true;
}

$mode = 2;
$readonly = 1;
?>
