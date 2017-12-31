<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form action=""  method="post" id="ec_cart_line"  name="cart_line">
    <span class="heading"><?php echo gettext('Cart'); ?></span>
    <div id="form_serach_header" class="tabContainer">
     <label><?php echo gettext('User Name') ?></label>
     <?php echo $f->select_field_from_object('user_id', ino_user::find_all(), 'ino_user_id', 'username', $user_id_h, 'user_id' ,'xlarge'); ?>
     <a name="show" href="form.php?class_name=ec_cart&<?php echo "mode=$mode"; ?>" class="show document_id ec_cart_id">
      <i class="fa fa-refresh"></i></a> 
    </div>
    <div id ="form_line" class="ec_cart"><span class="heading"><?php echo gettext('Product Details') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Current Cart') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Saved Cart') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Seq') ?>#</th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Product') ?>#</th>
           <th><?php echo gettext('Qty') ?>#</th>
           <th><?php echo gettext('Price') ?>#</th>
           <th><?php echo gettext('Delivery Instruction') ?></th>
           <th><?php echo gettext('Sub Total') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody cart_values" >
          <?php
          $count = 0;
          $cart_object_ai = new ArrayIterator($cart_object);
          $cart_object_ai->seek($position);
          while ($cart_object_ai->valid()) {
           $ec_cart = $cart_object_ai->current();
           ?>         
           <tr class="ec_cart<?php echo $count ?>">
            <td><?php   echo ino_inline_action($$class->ec_cart_id, array('user_id' => $user_id_h));        ?>                </td>
            <td><?php $f->seq_field_d($count) ?></td>
            <td><?php $f->text_field_dsr('ec_cart_id') ?></td>
            <td><?php $f->text_field_dsr('ec_product_id'); ?></td>
            <td><?php $f->text_field_ds('quantity') ?></td>
            <td><?php $f->text_field_dr('price') ?></td>
            <td><?php $f->text_field_d('price') ?></td>
            <td><?php $f->text_field_d('line_price') ?></td>
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
       <div id="tabsLine-2" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Seq') ?>#</th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Product') ?>#</th>
           <th><?php echo gettext('Qty') ?>#</th>
           <th><?php echo gettext('Price') ?>#</th>
           <th><?php echo gettext('Delivery Instruction') ?></th>
           <th><?php echo gettext('Sub Total') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody cart_values" >
          <?php
          $count = 0;
          $cart_object_ai = new ArrayIterator($cart_object);
          $cart_object_ai->seek($position);
          while ($cart_object_ai->valid()) {
           $ec_cart = $cart_object_ai->current();
           ?>         
           <tr class="ec_cart<?php echo $count ?>">
            <td><?php
             echo ino_inline_action($$class->ec_cart_id, array('user_id' => $user_id_h));
             ?>    
            </td>
            <td><?php $f->seq_field_d($count) ?></td>
            <td><?php $f->text_field_dsr('ec_cart_id') ?></td>
            <td><?php $f->text_field_dsr('ec_product_id'); ?></td>
            <td><?php $f->text_field_ds('quantity') ?></td>
            <td><?php $f->text_field_dr('price') ?></td>
            <td><?php $f->text_field_d('price') ?></td>
            <td><?php $f->text_field_d('line_price') ?></td>
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
    </div> 
   </form>
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
