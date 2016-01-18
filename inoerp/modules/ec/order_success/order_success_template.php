<div class='row small-top-margin'>
 <div class="jumbotron">
  <h2><?php echo $ino_user->first_name . ' ' . $ino_user->first_name; ?>, Thank you for your order!</h2>
  <p class="lead">
   Order Confirmation Number: <?php echo!empty($_SESSION['ec_paid_order_id']) ? $_SESSION['ec_paid_order_id'] : ''; ?>
  <p>Your order has been placed successfully. Please print this message, or record the Order Confirmation number. 

  <h3> Order Summary</h3>
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
     $count = 1;
     $total = 0;
     $tax_p = 0;
     $precision = 2;
     $cart_object_ai = new ArrayIterator($cart_object);
     $cart_object_ai->seek($position);
     $curr = 'USD ';
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
  <p>
   This number can be used to verify that your order has been placed. You will
   also be emailed a confirmation message containing important information regarding your order.
  <p>You can check the status of your order in
  <p><a class="btn btn-lg btn-warning" href="form.php?class_name=user&user_id=<?php echo $_SESSION['user_id'] ?>" role="button">Order Status Page</a> </p>
 </div>
</div> 