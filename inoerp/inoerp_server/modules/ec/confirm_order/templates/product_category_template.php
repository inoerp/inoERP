<div id='product-category-view-divId'>

 <div class="row">
  <?php
   category::breadCrum_by_category($priority_category);
  ?>
 </div>
 <div class="row product level-1">
  <div class="col-md-6 left">
   <div>
    <?php
    echo $f->hidden_field_withId('category_id', $category_detials->category_id);
    echo $f->hidden_field_withId('class_name', 'category');
    $url_with_category = HOME_URL . 'product.php?category_id=' . $category_detials->category_id;
    echo $f->hidden_field_withId('current_page_url', $url_with_category);
    $extn_img = new extn_image();
    $extn_img->reference_table = 'category';
    $extn_img->reference_id = $category_detials->category_id;
    echo $extn_img->simple_carousel();
    ?> 
   </div>
  </div>
  <div class="col-md-6 right">
   <?php
   if (!empty($category_detials->content_block_id)) {
    echo $block->show_block_content_by_BlockId($category_detials->content_block_id);
   } else {
    echo '  <div class="jumbotron">
   <h1>Block Content</h1>
   <p class="lead">Place reserved to show block content but no block is assigned to this category.</p>
   <p><a class="btn btn-lg btn-success" href="#" role="button">Assign a block</a></p>
  </div>';
   }
   ?>

  </div>
 </div>

 <div class="row product level-2">
  <?php
  $all_child_category = category::child_of_parent_woparent($category_detials->category_id);
  if (!empty($all_child_category)) {
   include_once 'category_browser_template.php';
  }
  ?>
 </div>

 <div class="row product level-3">
  <?php
  $all_products = ec_product::find_by_category_id($category_detials->category_id, $_GET);
  if (!empty($all_products)) {
   include_once 'produt_section_template.php';
  }
  ?>
 </div>

 <div class="row featurette product level-4">
  <h2 class="featurette-heading bgc">Featured <span class="text-muted"> Products.</span></h2>
  <div id="product-summary-cs" class="product-summary">
   <?php
   $result = ec_product::find_featured_products_id($category_detials->category_id);
   $subject_no_of_char = '60';
   $page_string = '';
   $con_count = 0;
   if (!empty($result) && count($result) > 0) {
    $page_string .= '<ul class="summary_list inline">';
    $page_string .= "<li class='non-content move-left'><span class='glyphicon glyphicon-chevron-left clickable' aria-hidden='true'></span>";
    foreach ($result as $records) {
     $con_count++;
     $page_string .= "<li class=\"summary count_$con_count\">";
     $page_string .= '<a href="' . HOME_URL . 'product.php?ec_product_id=' . $records->ec_product_id . '">';
     $page_string .= $f->show_existing_image($records->image_file_id, 'sm-image');
     $page_string .= substr($records->item_description, 0, $subject_no_of_char);
     $page_string .= '</a></li>';
    }
    $page_string .= "<li class='non-content move-right'><span class='glyphicon glyphicon-chevron-right clickable' aria-hidden='true'></span>";
    $page_string .= '</ul>';
   }
   echo $page_string;
   ?>
  </div>

 </div>

<?php echo (!empty($comments) && count($comments) > 1) ? "<hr class='grey-divider'>" : ""; ?>

 <div id="comments">
  <div id="comment_list">
<?php echo!(empty($comments)) ? $comments : ""; ?>
  </div>
  <hr class="grey-divider">
  <div id ="display_comment_form">
   <?php
   $reference_table = 'ec_product';
   $reference_id = $$class->ec_product_id;
   ?>
  </div>
  <div id="new_comment">
  </div>
 </div>

</div>