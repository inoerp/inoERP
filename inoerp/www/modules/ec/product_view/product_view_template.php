<div id='product-view-divId'>
 <div class="row">
  <?php category::breadCrum_by_category($priority_category); ?>
 </div>
 <div class="row product level-1">
  <div class="col-md-6 left">
   <div>
    <?php
    echo $f->hidden_field_withId('ec_product_id', $$class->ec_product_id);
    echo $f->hidden_field_withId('class_name', 'ec_product');
    $extn_img = new extn_image();
    $extn_img->reference_table = 'ec_product';
    $extn_img->reference_id = $$class->ec_product_id;
    echo $extn_img->simple_carousel();
    ?> 
   </div>
  </div>
  <div class="col-md-6 right">
   <div class="row product-top">
    <div class="col-md-12">
     <h2><?php echo $$class->product_name; ?> 
      <?php
      if ($allow_content_update) {
       echo '<a href="' . HOME_URL . 'form.php?mode=9&amp;class_name=ec_product&amp;ec_product_id=' . $$class->ec_product_id . '"><i class="fa fa-edit"></i></a>';
      }
      ?></h2>
    </div>
    <div class="col-md-12">
     <div class="col-md-4">   
      <div class="rate_widget">
       <ul class="inline rate-list">
        <li class="<?php echo $star_1 ?> clickable ratings_stars" data-rating="1" title="1 Star"></li>
        <li class="<?php echo $star_2 ?> clickable ratings_stars" data-rating="2" title="2 Stars"></li>
        <li class="<?php echo $star_3 ?> clickable ratings_stars" data-rating="3" title="3 Stars"></li>
        <li class="<?php echo $star_4 ?> clickable ratings_stars" data-rating="4" title="4 Stars"></li>
        <li class="<?php echo $star_5 ?> clickable ratings_stars" data-rating="5" title="5 Stars"></li>
        <li class="no-of-votes" data-no_of_votes="" title="<?php echo gettext('Average') . " $rating_avg "; ?>"><?php echo "($rating_count Votes )"; ?></li>
       </ul>
      </div>
     </div>
     <div class="col-md-4">
      <div class="no-of-comments"><a href="#comment_list"> <?php echo!empty($comments) ? count($comments) . ' ' . gettext('Comment') . '(s)' : gettext('No Comments'); ?>  </a></div>
     </div>
     <div class="col-md-4">

     </div>
    </div>
    <hr class="col-md-12 light">
    <div class="col-md-7">
     <p><?php echo nl2br(substr($$class->long_description, 0, 50)); ?></p>
    </div>
    <div class="col-md-5">
     <h3 class="bgc"> Price <span class="label label-warning"><?php echo "$ $sales_price"; ?></span>
      <br><?php echo!empty($save_p) ? "You Save <span class='label label-warning'>$save_p%</span>" : ''; ?></h3>
    </div>
   </div>
   <div class="row product-buttons">
    <ul class="button-lists inline">
     <li><a href="#" role="button" class="btn btn-lg btn-default add-to-cart" role="button"><?php echo gettext('Add To Cart') ?> </a></li>
     <li><a href="#" role="button" class="btn btn-lg btn-default add-to-wl"  role="button"><?php echo gettext('Add To Wish List') ?></a></li>
     <li><a href="<?php echo HOME_URL ?>?dtype=product&class_name=ec_user_cart&ec_product_id=<?php echo $$class->ec_product_id ?>" role="button" class="btn btn-lg  btn-success buy-now" role="button"><?php echo gettext('Buy Now') ?> </a></li>
    </ul>
   </div>
   <div class="row product-description">
    <p><a href="#product-description-details"><?php echo ino_show_collapse_content(nl2br($$class->product_description)); ?></a></p>
   </div>

  </div>
 </div>
 <div class="row product level-2">
  <div id="tabsDetailA">
   <ul class="tabMain">
    <li><a href="#tabsDetailA-1"><?php echo gettext('Additional Information') ?></a></li>
    <li><a href="#tabsDetailA-2"><?php echo gettext('Reviews') ?></a></li>
    <li><a href="#tabsDetailA-3"><?php echo gettext('Related Products') ?></a></li>
    <li><a href="#tabsDetailA-4"><?php echo gettext('Categories') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsDetailA-1" class="tabContent">
     <div id="catalog-details"><?php echo $catalog_stmt; ?></div>
    </div>
    <div id="tabsDetailA-2" class="tabContent">

    </div>
    <div id="tabsDetailA-3" class="tabContent">

    </div> 
    <div id="tabsDetailA-4" class="tabContent">
     <div class="category-div">
      <div class="existing-category">
       <label><?php echo gettext('Existing Categories'); ?></label><?php echo!empty($category) ? category::category_stmt($category) : ''; ?>
      </div>
      <div class="add-category">
       <label><?php echo gettext('New Category'); ?></label><?php echo $categoriey_select_option; ?>
      </div>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
   </div>
  </div>
 </div>

 <div class="row featurette product level-3">
  <h2 class="featurette-heading bgc"><?php echo gettext('Product Description'); ?></h2>
  <div id="product-description-details" class="product-summary">
   <?php
   echo nl2br($$class->product_description);
   ?>
  </div>

 </div>

 <div class="row featurette product level-3">
  <h2 class="featurette-heading bgc"><?php echo gettext('YOU MAY ALSO BE INTERESTED IN THE FOLLOWING'); ?> <span class="text-muted"> <?php echo gettext('PRODUCT'); ?>(S).</span></h2>
  <div id="product-summary-cs" class="product-summary">
   <?php
   $result = ec_product::find_similar_products($$class->ec_product_id);
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
