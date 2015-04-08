<hr>
<div class="col-md-4 left">
   <div class="panel panel-success">
    <h3 class='filter-title'>Refine by</h3>
    <div class='panel-body vertical-list'>
     <?php
     if (!empty($category_detials->filter_catalog_id)) {
      if (!empty($_GET['sys_catalog_line_id_value'])) {
       $filtered_values = $_GET['sys_catalog_line_id_value'];
      }
      $catalog_line_details = sys_catalog_line::find_by_parent_id($category_detials->filter_catalog_id);
      $filter_count = 0;
      foreach ($catalog_line_details as $key => $catalog_line_v) {
       if (!empty($catalog_line_v->sys_value_group_header_id)) {
        $odd_even_class = ($filter_count % 2 == 0 ) ? 'even' : 'odd';
        echo '<h3 class="' . $odd_even_class . '">' . $catalog_line_v->line_name . '</h3>';
        $line_values = sys_value_group_line::find_by_header_id($catalog_line_v->sys_value_group_header_id);
        echo '<ul>';
        foreach ($line_values as $line_value) {
         if ( !empty($filtered_values) && in_array($line_value->code, $filtered_values)) {
          echo '<li class="clickable" data-sys_catalog_line_id="' . $catalog_line_v->sys_catalog_line_id . '" data-sys_catalog_line_id_value="' . $line_value->code . '">' 
           . $f->checkBox_field($line_value->code, 1 , '','filter-checkbox') . '&nbsp;'
          . ' <a class="not-active" href="' . $_SERVER['REQUEST_URI'] . '&sys_catalog_line_id[]=' . $catalog_line_v->sys_catalog_line_id . '&sys_catalog_line_id_value[]=' . $line_value->code . '">' . $line_value->code_value . '</a></li>';
         } else {
          echo '<li class="clickable" data-sys_catalog_line_id="' . $catalog_line_v->sys_catalog_line_id . '" data-sys_catalog_line_id_value="' . $line_value->code_value . '">' 
          . $f->checkBox_field($line_value->code, '', '' , 'filter-checkbox',1) . '&nbsp;'
          . ' <a href="' . $_SERVER['REQUEST_URI'] . '&sys_catalog_line_id[]=' . $catalog_line_v->sys_catalog_line_id . '&sys_catalog_line_id_value[]=' . $line_value->code . '">' . $line_value->code_value . '</a></li>';
         }
        }
        echo '</ul>';
        $filter_count++;
       }
      }
     }
     ?>
    </div>
   </div>
  </div>

  <div class="col-md-8 right">
   <?php
//      pa($_SESSION['user_profile']);
//      pa(get_declared_classes());

   $all_products = ec_product::find_by_category_id($category_detials->category_id, $_GET);
   $no_of_char = '60';
   $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
   $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 12;
   $total_count = count($all_products);
   $pagination = new pagination($pageno, $per_page, $total_count);
   $pagination->setProperty('_path', 'product.php?');
   $position = ($pageno - 1) * $per_page;

   if (!empty($all_products)) {
    $all_products_ai = new ArrayIterator($all_products);
    if ($position > 0) {
     $all_products_ai->seek($position);
    }
    $cont_count = 1;
    while ($all_products_ai->valid()) {
     $this_product = $all_products_ai->current();
     if ($cont_count == 1 || $cont_count == 4) {
      $count_class_val = ' first ';
     } else if ($cont_count == 2 || $cont_count == 5) {
      $count_class_val = ' last ';
     } else {
      $count_class_val = '';
     }

     if (!empty($this_product->list_price)) {
      $list_price = $this_product->list_price;
      $sales_price = number_format($this_product->sales_price);
      $save_p = round((($list_price - $sales_price) / $list_price) * 100);
     } else {
      $sales_price = $save_p = null;
     }


     echo '<div class="col-lg-4' . $count_class_val . ' ">
              <div class="panel panel-success">';
     echo '<a href="' . HOME_URL . 'product.php?ec_product_id=' . $this_product->ec_product_id . '">';
     echo "<div class='panel-body'>" . $f->show_existing_image($this_product->image_file_id, 'sm-image') . "</div>";
     echo '</a>';
     echo '<div class="panel-footer">';
     echo '<a href="' . HOME_URL . 'product.php?ec_product_id=' . $this_product->ec_product_id . '">';
     echo substr($this_product->item_description, 0, $no_of_char);
     echo '</a>';
     echo '<h4 class="bgc"> Price $' . $sales_price;
     if (!empty($save_p)) {
      echo '. You Save <span class="label label-warning">' . $save_p . '%</span>';
     }
     echo '</h3>'; //end of h3
     echo '<ul class="button-lists inline">
     <li><a href="#" role="button" class="btn btn-default add-to-cart" role="button">Add To Cart </a></li>
     <li><a href="'.HOME_URL.'?dtype=product&class_name=ec_user_cart&ec_product_id='.$$class->ec_product_id.'"
      role="button" class="btn btn-success buy-now" role="button">Buy Now </a></li>
   </ul>';
     echo '</div>'; //end of footer

     echo '</div></div>';
     $cont_count++;
     $all_products_ai->next();
     if ($all_products_ai->key() == $position + $per_page) {
      $cont_count = 1;
      break;
     }
    }
   }
   ?>
   <div id="pagination1" class="pagination small-top-margin">
    <?php echo $pagination->show_pagination(); ?>
   </div>
  </div>