<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div class="row product level-1">
 <div id ="form_header" class="erp-form"><span class="heading"><?php echo gettext('Membership Application') ?></span>
  <form  method="post" id="hd_subscription_header"  action="<?php echo $header_post_link ?>" name="hd_subscription_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Address Details') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form ">
       <li><?php
        
        echo $f->hidden_field_withIdClass('hd_subscription_header_id', $$class->hd_subscription_header_id, 'hd_subscription_header_id');
        $f->l_select_field_from_array('subscription_type', hd_subscription_header::$subscription_type_a, $$class->subscription_type, 'subscription_type', '', 1);
        ?></li>
       <li><label>Membership Type</label><?php echo $f->select_field_from_object('document_type', option_header::find_options_byName('HD_SUBSCR_DOC_TYPE'), 'option_line_code', 'option_line_value', $$class->document_type, 'document_type', $readonly1, '', ''); ?>						 </li>
       <li><?php $f->l_text_field_d('first_name'); ?></li>
       <li><?php $f->l_text_field_d('last_name'); ?></li>
       <li><?php $f->l_text_field_d('full_name'); ?></li>
       <li><?php $f->l_text_field_dm('passport_number'); ?></li>
       <li><?php $f->l_select_field_from_object('gender', hr_employee::gender(), 'option_line_code', 'option_line_value', $$class->gender, '', 'gender', '', $readonly); ?>              </li>
        <!--<li><?php // $f->l_radio_field_from_object('gender', hr_employee::gender(), 'option_line_code', 'option_line_value', $$class->gender, 'gender', '', $readonly);        ?>              </li>-->
       <li><?php $f->l_select_field_from_object('marital_status', hr_employee::marital_status(), 'option_line_code', 'option_line_value', $$class->marital_status, '', 'marital_status', '', $readonly); ?>              </li>
       <li><?php $f->l_text_field_d('nationality'); ?></li>
       <li><?php $f->l_text_field_d('occupation'); ?></li>
       <li><?php $f->l_text_field_dr('status') ?></li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('address_line1'); ?></li> 
       <li><?php $f->l_text_field_d('address_line2'); ?></li> 
       <li><?php $f->l_text_field_d('postal_code'); ?></li> 
       <li><?php $f->l_text_field_d('state'); ?> </li> 
       <li><?php $f->l_text_field_d('office_phone'); ?></li> 
       <li><?php $f->l_text_field_d('mobile_phone1'); ?></li> 
       <li><?php $f->l_text_field_d('mobile_phone2'); ?></li> 
       <li><?php $f->l_text_field_d('fax_no'); ?></li> 
       <li><?php $f->l_text_field_d('email'); ?></li> 
      </ul>
      <div class="row">    
       <div class="col-md-6">
        <div><h3>Shipping Address</h3>
         <?php echo address_reference::show_address(array($ship_add), true); ?>
         <label>Select a different shipping address</label>
         <?php echo $f->select_field_from_object('ship_to_address_id', $all_address, 'address_id', 'address', '', 'ship_to_address_id'); ?>
        </div>
       </div>
       <div class="col-md-6">
        <div><h3>Billing Address</h3>
         <?php echo address_reference::show_address(array($bill_add), true); ?>
         <label>Select a different billing address</label>
         <?php echo $f->select_field_from_object('bill_to_address_id', $all_address, 'address_id', 'address', '', 'bill_to_address_id'); ?>

        </div>
       </div>
      </div>  
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
    </div>
   </div>
  </form>
 </div>
 <div id="form_line" class="form_line erp-form"><span class="heading"><?php echo gettext('Edit Membership Plan') ?></span>
  <form action=""  method="post" id="hd_subscription_line"  name="hd_subscription_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Compulsory') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="table table-bordered table-large cart ">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?> #</th>
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
         if (!empty($ec_user_cart->ec_product_id)) {
          $product_name = $ec_user_cart->product_name;
          $product_description = $ec_user_cart->product_description;
         } else {
          $product_name = $product_description = null;
         }
         if (empty($ec_user_cart->quantity)) {
          $ec_user_cart->quantity = 1;
         }
         if (empty($ec_user_cart->ec_cart_id)) {
          $ec_user_cart->ec_cart_id = null;
         }
         $category = category::find_by_reference_table_and_id('ec_product', $ec_user_cart->ec_product_id);
         ?>         
         <tr class="ec_cart<?php echo $count ?>">
          <td><?php
           echo $count;
           echo form::hidden_field('ec_cart_id', $ec_user_cart->ec_cart_id);
           echo form::hidden_field('user_id', $user_id_h);
           echo form::hidden_field('ec_product_id', $ec_user_cart->ec_product_id);
           echo $f->hidden_field('currency', $curr);
           echo $f->hidden_field('tax_code', $tax_code);
           echo $f->hidden_field('sales_price', $ec_user_cart->sales_price);
           echo $f->hidden_field('product_name', $product_name)
           ?>
          </td>
          <td><?php echo $product_name; ?></td>
          <td class="long-td"><?php echo ('<a href="' . HOME_URL . 'product.php?ec_product_id=' . $ec_user_cart->ec_product_id . '" title="' . $product_description . '">' . substr($product_description, 0, 100) . '</a>'); ?></td>
          <td><?php echo $ec_user_cart->quantity ?></td>
          <td class="unit-price"><?php
           echo '<span class="currency">' . $curr . '</span>';
           $unit_price = round($ec_user_cart->sales_price, $precision);
           echo '<span class="unit-price-value">' . $unit_price . '</span>';
           ?></td>
          <td><?php echo $f->text_area('description', $ec_user_cart->description) ?></td>
          <td  class="line-price" data-currency="<?php echo $curr; ?>"><?php
           echo '<span class="currency">' . $curr . '</span>';
           $sub_total = round($ec_user_cart->sales_price * $ec_user_cart->quantity, $precision);
           $total += $sub_total;
           echo '<span class="line-price-value">' . $sub_total . '</span>';
           ?></td>
         </tr>
         <tr><td></td>
          <td colspan="6">
           <table class="form form_detail_data_table detail">
            <thead>
             <tr>
              <th ><?php echo gettext('Action') ?></th>
              <th><?php echo gettext('Detail Id') ?></th>
              <th><?php echo gettext('Line Type') ?></th>
              <th><?php echo gettext('Member Name') ?></th>
              <th><?php echo gettext('DOB') ?></th>
              <th><?php echo gettext('Vehcile No') ?></th>
              <th><?php echo gettext('Vehcile Reg') ?></th>
              <th><?php echo gettext('Tax Expiry Date') ?></th>
              <th><?php echo gettext('Vehcile Details') ?></th>
              <th><?php echo gettext('Description') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_detail_tbody <?php echo $count ?>">
             <?php
             $detailCount = 0;
             $hd_subscription_detail = new hd_subscription_detail();
             $hd_subscription_detail_object = array();
             array_push($hd_subscription_detail_object, $hd_subscription_detail);
             foreach ($hd_subscription_detail_object as $hd_subscription_detail) {
              $class_third = 'hd_subscription_detail';
              $$class_third = &$hd_subscription_detail;
//												pa($hd_subscription_detail);
              ?>
              <tr class="hd_subscription_detail<?php echo $count . '-' . $detailCount; ?>">
               <td class="min-width-100">
                <?php
                echo ino_inline_action($$class_third->hd_subscription_detail_id, array('hd_subscription_header_id' => $$class->hd_subscription_header_id,
                 'hd_subscription_line_id' => $$class_second->hd_subscription_line_id), 'add_row_detail_img', 'detail_id_cb');
                ?>
               </td>
               <td><?php $f->text_field_wid3sr('hd_subscription_detail_id'); ?></td>
               <td><?php $f->text_field_wid3r('line_type', 'copyValue always_readonly'); ?></td>
               <td><?php $f->text_field_wid3('member_name'); ?></td>
               <td><?php echo $f->date_fieldAnyDay('member_dob', $$class_third->member_dob); ?></td>
               <td><?php $f->text_field_wid3('vehcile_no'); ?></td>
               <td><?php $f->text_field_wid3('vehcile_registration'); ?></td>
               <td><?php $f->text_field_wid3('road_tax_expiry_date'); ?></td>
               <td><?php $f->text_field_wid3('vehcile_details'); ?></td>
               <td><?php $f->text_field_wid3('description'); ?></td>
              </tr>
              <?php
              $detailCount++;
             }
             ?>
            </tbody>
           </table>
          </td>
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
     </div>
    </div>
   </div>
  </form>

 </div>
</div>


<div class="row product level-2 small-top-margin small-top-padding">
 <div class="col-md-6"></div>
 <div class="col-md-2"><a role="button" class="btn btn-lg btn-info save-cart" href="?dtype=product&class_name=ec_user_cart">Modify Cart</a></div>
 <div class="col-md-2"><input type="button" id="save" role="button" class="btn btn-lg btn-primary place-order" value="Confirm Order"></div>
 <div class="col-md-2"><input type="submit" id="make_payment" role="button"  class="btn btn-lg btn-primary place-order" value="Make Payment" form="hd_subscription_header"></div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hd_subscription_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_subscription_line" ></li>
  <li class="detailClassName" data-detailClassName="hd_subscription_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_subscription_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_subscription_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hd_subscription_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_subscription_header_id" ></li>
  <li class="docLineId" data-docLineId="hd_subscription_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_subscription_header" ></li>
  <li class="docDetailId" data-docDetailId="hd_subscription_detail_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>