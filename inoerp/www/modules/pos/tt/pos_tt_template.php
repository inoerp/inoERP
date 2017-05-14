<div id="pos_terminal">
  <div id="tabsDetailA">
  <ul class="tabsDetail">
   <li><a href="#tabsDetailA-1"><i class="fa fa-laptop" title="Transaction Display"></i></a></li>
   <li><a href="#tabsDetailA-2"><i class="fa fa-shopping-cart" title="Customer Display"></i></a></li>
  </ul>
  <div class="tabContainer-none">
   <div id="tabsDetailA-1" class="tabContent">
    <div class="row">
     <div class="col-md-8 col-sm-8 col-lg-8">
      <div id="form_all">
       <div id ="form_line" class="form_line">
        <span class="heading"><?php echo gettext('Sales Items') ?></span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Lines') ?></a></li>
         </ul>
         <div class="tabContainer"> 
          <form action=""  method="post" id="pos_transaction_line_line"  name="pos_transaction_line_line">
           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th><?php echo gettext('Action') ?></th>
               <th><?php echo gettext('Line Id') ?></th>
               <th><?php echo gettext('Item') ?>#</th>
               <th><?php echo gettext('Unit Price') ?></th>
               <th><?php echo gettext('Quantity') ?></th>
               <th><?php echo gettext('Discount Code') ?></th>
               <th><?php echo gettext('Discount') ?></th>
               <th><?php echo gettext('Line Amount') ?></th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody pos_transaction_line_values" >
              <?php
//        pa($pos_transaction_line_object);
              $count = 0;
              $pos_transaction_line_object_ai = new ArrayIterator($pos_transaction_line_object);
              $pos_transaction_line_object_ai->seek($position);
              while ($pos_transaction_line_object_ai->valid()) {
               $pos_transaction_line = $pos_transaction_line_object_ai->current();
               ?>         
               <tr class="pos_transaction_line<?php echo $count ?>">
                <td><?php
                 echo ino_inline_action($pos_transaction_line->pos_transaction_line_id, array('pos_transaction_header_id' => $$class->pos_transaction_header_id));
                 ?>
                </td>
                <td><?php form::number_field_wid2sr('pos_transaction_line_id'); ?></td>
                <td><?php $f->text_field_wid2('item_number'); ?></td>
                <td><?php echo $f->number_field('unit_price', $$class_second->unit_price, '', '', 'medium'); ?></td>
                <td><?php echo $f->number_field('quantity', $$class_second->quantity); ?></td>
                <td><?php $f->text_field_wid2('discount_code', 'medium'); ?></td>
                <td><?php echo $f->number_field('discount_amount', $$class_second->discount_amount, '', '', 'medium'); ?></td>
                <td><?php echo $f->hidden_field('line_amount', $$class_second->line_amount); ?>
                 <?php echo $f->number_field('amount_after_discount', $$class_second->amount_after_discount, '', '', 'medium'); ?></td>
               </tr>
               <?php
               $pos_transaction_line_object_ai->next();
               if ($pos_transaction_line_object_ai->key() == $position + $per_page) {
                break;
               }
               $count = $count + 1;
              }
              ?>
             </tbody>
            </table>
           </div>
          </form>
         </div>

        </div>
       </div> 
       <form action=""  method="post" id="pos_transaction_header"  name="pos_transaction_header">
        <span class="heading"><?php echo gettext('POS Transaction') ?></span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
           <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
           <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column header_field">
              <li><?php $f->l_text_field_dr_withSearch('pos_transaction_header_id'); ?>
               <a name="show" href="form.php?class_name=pos_tt_header&<?php echo "mode=$mode"; ?>" class="show document_id pos_transaction_header_id">
                <i class='fa fa-refresh'></i></a> 
              </li>
              <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="pos_terminal_header_id select_popup clickable">
                <?php echo gettext('Terminal') ?>#</label><?php echo $f->text_field_dm('terminal_name'); ?> 
               <i class="fa fa-save save_terminal_name clickable" title="save terminal name for the current session"></i></li>
              <li><?php $f->l_number_field('header_amount', $$class->header_amount, '', 'header_amount'); ?> </li>
              <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '', 'tax_amount'); ?> </li>
              <li><?php $f->l_number_field('discount_amount', $$class->discount_amount, '', 'discount_amount'); ?> </li>
              <li><?php $f->l_number_field('total_amount', $$class->total_amount, '', 'total_amount'); ?> </li>
              <li><?php $f->l_text_field_d('description'); ?></li>
              <li><?php $f->l_number_field('return_amount', '', '', 'return_amount'); ?> </li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div> <?php echo ino_attachement($file) ?> </div>
           </div>
           <div id="tabsHeader-3" class="tabContent">
            <div> 
             <div id="comments">
              <div id="comment_list">
               <?php echo!(empty($comments)) ? $comments : ""; ?>
              </div>
              <div id ="display_comment_form">
               <?php
               $reference_table = 'pos_transaction_header';
               $reference_id = $$class->pos_transaction_header_id;
               ?>
              </div>
              <div id="new_comment">
              </div>
             </div>
            </div>
           </div>
          </div>
         </div>
        </div>
       </form>

      </div>
     </div>
     <div class="col-md-3 col-sm-3 col-lg-3">
      <div class="row">
       <div>
        <div id="calculator">
         <!-- Screen and clear key -->
         <div id="scanner_field" class="above_top">
          <input type="text" name="scanned_item" id="scanned_item" autofocus="true" placeholder="Scan Here">
         </div>

         <div class="top">
          <div class="screen">
           <input type="text" name="screen_number" id="screen_number" >
          </div>
          <span class="clear" data-btn_value="C" >C</span>
         </div>

         <div class="keys">
          <!-- operators and other keys -->
          <span class="number" data-btn_value="7" >7</span>
          <span class="number" data-btn_value="8">8</span>
          <span class="number" data-btn_value="9">9</span>
          <span class="operator"  data-btn_value="+" >+</span>
          <span class="cash-amount" data-btn_value="10">10</span>
          <span class="number" data-btn_value="4">4</span>
          <span class="number" data-btn_value="5">5</span>
          <span class="number" data-btn_value="6">6</span>
          <span class="operator" data-btn_value="-">-</span>
          <span class="cash-amount" data-btn_value="50">50</span>
          <span class="number" data-btn_value="1">1</span>
          <span class="number" data-btn_value="2">2</span>
          <span class="number" data-btn_value="3">3</span>
          <span class="operator" data-btn_value="÷">÷</span>
          <span class="cash-amount" data-btn_value="100">100</span>
          <span class="number" data-btn_value="0">0</span>
          <span class="number" data-btn_value=".">.</span>
          <span class="enter" data-btn_value="="></span>
          <span class="operator" data-btn_value="x">x</span>
          <span class="cash-amount" data-btn_value="1000">1000</span>
         </div>

         <div class="large-keys">
          <span class="number"  data-btn_value="new_transaction" >New</span>
          <span class="number"  data-btn_value="cancel"  disabled>Cancel</span>
          <span class="number"  data-btn_value="done">Done</span>
          <span class="number"  data-btn_value="return" >Return</span>
          <span class="number"  data-btn_value="card_payment" >Card Payment</span>
          <span class="number"  data-btn_value="reprint">Reprint</span>
          <span class="number"  data-btn_value="" >Unused</span>
          <span class="number"  data-btn_value="" >Unused</span>
          <span class="number"  data-btn_value="recalculate">Recalculate</span>
         </div>
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
   <div id="tabsDetailA-2" class="tabContent">
    <div class="row">
     <div class="col-md-8 col-sm-8 col-lg-8">
      <div id="pos_transaction_line_cust_view">
       <div class="form_line">
        <span class="heading"><?php echo gettext('Items') ?></span>
        <div>
         <table class="form_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Item') ?></th>
            <th><?php echo gettext('Unit Price') ?></th>
            <th><?php echo gettext('Quantity') ?>#</th>
            <th><?php echo gettext('Line Amount') ?></th>
           </tr>
          </thead>
          <tbody class="form_data_line_tbody pos_transaction_line_values" >
           <?php
//        pa($pos_transaction_line_object);
           $count = 0;
           $pos_transaction_line_object_ai = new ArrayIterator($pos_transaction_line_object);
           $pos_transaction_line_object_ai->seek($position);
           while ($pos_transaction_line_object_ai->valid()) {
            $pos_transaction_line = $pos_transaction_line_object_ai->current();
            ?>         
            <tr class="pos_transaction_line<?php echo $count ?>">
             <td><?php $f->text_field_wid2('item_number'); ?></td>
             <td><?php echo $f->number_field('unit_price', $$class_second->unit_price, '', '', 'medium'); ?></td>
             <td><?php echo $f->number_field('quantity', $$class_second->quantity); ?></td>
             <td><?php echo $f->number_field('amount_after_discount', $$class_second->amount_after_discount, '', '', 'medium'); ?></td>
            </tr>
            <?php
            $pos_transaction_line_object_ai->next();
            if ($pos_transaction_line_object_ai->key() == $position + $per_page) {
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

      <div id="form_header_total_cust"><span class="heading">Total</span>
       <div class="large_shadow_box"> 
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('terminal_name', ''); ?> </li>
         <li><?php $f->l_number_field_d('header_amount', $$class->header_amount); ?> </li>
         <li><?php $f->l_number_field_d('tax_amount', $$class->tax_amount); ?> </li>
         <li><?php $f->l_number_field_d('discount_amount', $$class->discount_amount); ?> </li>
         <li><?php $f->l_number_field_d('total_amount', $$class->total_amount); ?> </li>
         <li><?php $f->l_number_field('return_amount', '', '', 'return_amount'); ?> </li>
        </ul>
       </div>
      </div>
     </div>
     <div class="col-md-3 col-sm-3 col-lg-3">
      <div class="row">

       <div id="form_header_total_cust"><span class="heading">Offers</span>
        <div class="large_shadow_box"> 

        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>
 </div>


</div>
<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="pos_transaction_header" ></li>
  <li class="lineClassName" data-lineClassName="pos_transaction_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pos_transaction_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pos_transaction_header" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pos_transaction_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pos_transaction_header_id" ></li>
  <li class="docLineId" data-docLineId="pos_transaction_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pos_transaction_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="pos_transaction_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>