<hr>
<div class="row featurette product">
 <h2 class="featurette-heading bgc"><span class="text-muted"> <?php echo gettext('Category Browser') ?></span></h2>
 <div class="category-browser">
  <?php
  
  $desc_no_of_char = '60';
  $cb_string = '';
  $cc_count = 0;
  if (!empty($all_child_category) && count($all_child_category) > 0) {
   $cb_string .= '<ul class="category-browser-list inline">';
   foreach ($all_child_category as $cc_records) {
    $cc_count++;
    $cb_string .= "<li class=\"summary cc_count_$cc_count\">";
    $cb_string .= '<a href="' . HOME_URL . 'product.php?category_id=' . $cc_records->category_id . '&category_name='.$cc_records->category.'">';
    $cb_string .= $f->show_existing_image($cc_records->image_file_id, 'sm-image');
    $cb_string .= substr($cc_records->description, 0, $desc_no_of_char);
    $cb_string .= '</a></li>';
   }
   $cb_string .= '</ul>';
  }
  echo $cb_string;
  ?>
 </div>

</div>
