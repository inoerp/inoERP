<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form action="<?php echo $post_link ?>"  method="post" id="ec_cart_line"  name="ec_cart_line">
    <span class="heading"></span>
    <div id ="form_line" class="ec_cart">
     <div class="panel panel-info">
      <div class="panel-heading">
       <h3><?php echo gettext('Cart Details - Verify & Confirm Order') ?></h3>
      </div>
      <div class="panel-body">
       <p><?php echo gettext('Free Standard Delivery if total order amount is $50 or above.') ?></p>
      </div>
      <table class="table table-bordered table-large cart ">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Product') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Quantity') ?></th>
         <th><?php echo gettext('Price') ?></th>
         <th><?php echo gettext('Delivery Instruction') ?></th>
         <th><?php echo gettext('Sub Total') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody cart_values" >
        <?php
        $count = 1;
        $total = 0;
        $tax_p = 0;
        $tax_code = 'NA';
        $precision = 2;
        $cart_object_ai = new ArrayIterator($cart_object);
        $cart_object_ai->seek($position);
        $curr = '$ ';
        while ($cart_object_ai->valid()) {
         $ec_user_cart = $cart_object_ai->current();

         if (!empty($$class->ec_product_id)) {
          $product_name = $$class->product_name;
          $product_description = $$class->product_description;
         } else {
          $product_name = $product_description = null;
         }
         if (empty($$class->quantity)) {
          $$class->quantity = 1;
         }
         if (empty($$class->ec_cart_id)) {
          $$class->ec_cart_id = null;
         }
         ?>         
         <tr class="ec_cart<?php echo $count ?>">
          <td class="action-td">
           <ul class="inline_action">
            <li  class="remove_row_img remove_from_cart clickable"><i class="fa fa-2x fa-minus-circle" title="Remove Product"></i></li>
            <li><?php echo '<a href="' . HOME_URL . 'product.php?ec_product_id=' . $$class->ec_product_id . '" title="View Product Details"><i class="fa fa-2x fa-info-circle clickable"></i></a>'; ?>
             <?php echo form::hidden_field('ec_cart_id', $$class->ec_cart_id); ?>
             <?php echo form::hidden_field('user_id', $user_id_h); ?>
             <?php echo form::hidden_field('ec_product_id', $$class->ec_product_id); ?>
             <?php echo $f->hidden_field('currency', $curr) ?>
             <?php echo $f->hidden_field('tax_code', $tax_code) ?>
             <?php echo $f->hidden_field('sales_price', $$class->sales_price) ?>
             <?php echo $f->hidden_field('product_name', $product_name) ?>
            </li>
           </ul>
          </td>
          <td><?php echo $count; ?></td>
          <td><?php echo $product_name; ?></td>
          <td class="long-td"><?php echo ('<a href="' . HOME_URL . 'product.php?ec_product_id=' . $$class->ec_product_id . '" title="' . $product_description . '">' . substr($product_description, 0, 100) . '</a>'); ?></td>
          <td><?php $f->text_field_wids('quantity') ?></td>
          <td class="unit-price"><?php
           echo '<span class="currency">' . $curr . '</span>';
           $unit_price = round($$class->sales_price, $precision);
           echo '<span class="unit-price-value">' . $unit_price . '</span>';
           ?></td>
          <td><?php echo $f->text_area('description', $$class->description) ?></td>
          <td  class="line-price" data-currency="<?php echo $curr; ?>"><?php
           echo '<span class="currency">' . $curr . '</span>';
           $sub_total = round($$class->sales_price * $$class->quantity, $precision);
           $total += $sub_total;
           echo '<span class="line-price-value">' . $sub_total . '</span>';
           ?></td>
         </tr>
         <?php
         $cart_object_ai->next();
         if ($cart_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
      <div class="panel-footer">
       <div class="row">
        <div class="col-md-5"><label><?php echo gettext('Discount Code') ?> </label>
         <?php echo $f->text_field('discount_code', '', '', 'discount_code', 'big-input') ?>
         <button class="btn btn-default continue-shopping" role="button">Apply Discount</button></div>
        <div class="col-md-5"><label>Pin Code </label>
         <?php echo $f->text_field('pin_code', '', '', 'pin_code', 'big-input') ?>
         <button class="btn btn-default save-cart" role="button">Check Shipping</button></div>
        <div class="col-md-2"><span class="btn btn-lg"> Tax Amount : <?php
          $tax_amount = round((($total * $tax_p) / 100), $precision);
          $total += $tax_amount;
          echo $curr . $tax_amount;
          ?></span></div>
        <?php echo $f->hidden_field('tax_amount', $tax_amount) ?>
        <?php echo $f->hidden_field('total_amount', $total) ?>
       </div>
      </div>

     </div> 
    </div>
   </form>
   <div class="panel-footer">
    <div class="row">
     <div class="col-md-4"><a class="btn btn-lg btn-default continue-shopping" role="button" href="product.php"><?php echo gettext('Continue Shopping') ?></a></div>
     <div class="col-md-3"><button class="btn btn-lg btn-default save-cart" role="button"><?php echo gettext('Save Cart') ?></button></div>
     <div class="col-md-3"><input type="submit" role="button" class="btn btn-lg btn-primary place-order" value="Place Order" form="ec_cart_line"></div>
     <div class="col-md-2"><span class="btn btn-lg"><?php echo gettext('Total Amount') ?> : <?php echo $curr;
        echo '<span class="total-amount">' . $total . '</span>'; ?></span></div>
    </div>
   </div>
  </div>
 </div>
</div>
<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
<?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="lineClassName" data-lineClassName="ec_cart" ></li>
  <li class="line_key_field" data-line_key_field="cart" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ec_cart" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="ec_cart_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="ec_cart" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>