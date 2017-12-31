<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_header">
   <h2 class="bgc">Final Confirmation & Payment</h2>

   <div id="accordion0" class="accordion">
    <h3><i class="fa fa-minus-circle"></i> Customer Information</h3>
    <div>
     <p><?php if (!empty($ino_user->ino_user_id)) { ?>
     <ul class="column header_field">
      <li><?php
        echo $f->hidden_field('user_id', $ino_user->ino_user_id);
        $f->l_text_field('username', $ino_user->username, '', '', '', 1, 1);
        ?></li>
       <li><?php $f->l_text_field('first_name', $ino_user->first_name, '', '', '', 1, 1); ?></li>
       <li><?php $f->l_text_field('last_name', $ino_user->last_name, '', '', '', 1, 1); ?></li>
       <li><?php $f->l_text_field('email', $ino_user->email, '', '', '', 1, 1); ?></li>
       <li><?php $f->l_text_field('phone', $ino_user->phone, '', '', '', '', 1); ?></li>
       <li><label>Update</label><a role="button" href="<?php echo HOME_URL . 'form.php?class_name=user&mode=9&user_id=' . $ino_user->ino_user_id; ?>"><i class="fa fa-edit"></i> Details</a></li>
      </ul>
      <?php
     } else {
      include_once __DIR__ . '/../../../extensions/ino_user/page_login/user_login_template.php';
     }
     ?>
     </p>
    </div>
    <h3><i class="fa fa-plus-circle"></i> Delivery Details</h3>
    <div>
     <?php
     $all_address = address_reference::find_by_reference_detailts('ino_user', $ino_user->ino_user_id);
     if ($all_address) {
      $ship_add = $bill_add = $all_address[0];
      $ship_to_id = $bill_to_id = $all_address[0]->address_id;
     } else {
      $ship_add = $bill_add = new address();
     }
     ?>
     <div class="row">    
      <div class="col-md-6">
       <div><h3>Shipping Address | Add a new address <a class="popup popup-form view-addrees medium" href="form.php?class_name=address&mode=9&window_type=popup&ref_class_name=ec_confirm_order">
               <i class="fa fa-plus-circle clickable"></i></a></h3>
				<div id="selected_ship_to_address"> <?php echo address_reference::show_address(array($ship_add), 'ship_to_address_id', 'ec_confirm_order'); ?> </div>
        <label>Select a different shipping address</label>
        <?php echo $f->select_field_from_object('ship_to_address_id', $all_address, 'address_id', ['address','country','postal_code','phone'], '', 'ship_to_address_id'); ?>
       </div>
      </div>
      <div class="col-md-6">
       <div><h3>Billing Address | <span >  Same as shipping  <?php $f = new inoform();  echo $f->checkBox_field('bill_same_as_ship', '' ,'' ,'small') ?>  </span></h3>
        <div id="selected_bill_to_address"> <?php echo address_reference::show_address(array($bill_add), 'bill_to_address_id', 'ec_confirm_order'); ?> </div>
        <label>Select a different billing address</label>
        <?php echo $f->select_field_from_object('bill_to_address_id', $all_address, 'address_id', 'address', '', 'bill_to_address_id'); ?>

       </div>
      </div>
     </div>  
    </div>
    <h3><i class="fa fa-plus-circle"></i> Order Summary</h3>
    <div>
     <table class="table table-bordered table-large cart ">
      <thead> 
       <tr>
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Product') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Price') ?></th>
        <th><?php echo gettext('Sub Total') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody cart_values" >
       <?php
       if (empty($cart_object)) {
//        pa($cart_object);
        $total_amount = $tax_amount = 0;
        echo '<div class="alert alert-danger" role="alert">
        <strong>Cart Empty</strong> Please select any product to proceed further.
      </div>';
       } else {
        $count = 1;
        $total = 0;
        $tax_p = 0;
        $precision = 2;
        $cart_object_ai = new ArrayIterator($cart_object);
        $cart_object_ai->seek($position);
        $curr = 'USD';
        while ($cart_object_ai->valid()) {
         $ec_user_cart = $cart_object_ai->current();
         ?>         
         <tr class="ec_cart<?php echo $count ?>">
          <td><?php echo $count; ?></td>
          <td><?php echo $ec_user_cart->product_name; ?></td>
          <td><?php echo $ec_user_cart->quantity ?></td>
          <td><?php echo $curr . round($ec_user_cart->sales_price, $precision) ?></td>
          <td data-currency="<?php echo $curr; ?>"><?php
           echo $curr;
           $sub_total = round($ec_user_cart->sales_price * $ec_user_cart->quantity, $precision);
           $total += $sub_total;
           echo $sub_total;
           ?></td>
         </tr>
         <?php
         $cart_object_ai->next();
         if ($cart_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
       }
       ?>
       <tr class="summar_details">
        <td></td>
        <td></td>
        <td></td>
        <td>Tax : <?php echo $tax_amount ?></td>
        <td>Total : <?php echo $total_amount ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <h3><i class="fa fa-plus-circle"></i> Payment Details</h3>
    <div>
     <?php
     if (empty($ship_to_id) || empty($bill_to_id)) {
      echo '<div class="alert alert-danger" role="alert">
        <strong>No Address Found!</strong> Please <a href="#accordion0">login</a> to proceed further.
      </div>';
     } else if (empty($cart_object)) {
      echo '<div class="alert alert-danger" role="alert">
        <strong>Cart Empty</strong> Please select any product to proceed further.
      </div>';
     } else {
      echo ec_payment_method::show_payment_methods($total_amount, $curr, $ship_to_id, $bill_to_id);
     }
     ?>
    </div>
   </div>
  </div>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="lineClassName" data-lineClassName="confirm_order" ></li>
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