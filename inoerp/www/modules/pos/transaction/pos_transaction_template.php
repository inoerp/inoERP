<div class="row small-left-padding">
 <div id="form_all">
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
          <a name="show" href="form.php?class_name=pos_transaction_header&<?php echo "mode=$mode"; ?>" class="show document_id pos_transaction_header_id">
           <i  class="fa fa-refresh"></i></a> 
         </li>
         <li><?php $f->l_text_field_dm('terminal_name'); ?> </li>
         <li><?php $f->l_number_field_d('header_amount'); ?> </li>
         <li><?php $f->l_number_field_d('tax_amount', $$class->tax_amount, '', 'tax_amount'); ?> </li>
         <li><?php $f->l_number_field_d('discount_amount', $$class->discount_amount, '', 'discount_amount'); ?> </li>
         <li><?php $f->l_number_field_d('total_amount', $$class->total_amount, '', 'total_amount'); ?> </li>
         <li><?php $f->l_text_field_d('description'); ?></li>
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Sales Items') ?> </span>
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
          <th><?php echo gettext('Discount Amount') ?></th>
          <th><?php echo gettext('Line Amount') ?></th>
          <th><?php echo gettext('Final Amount') ?></th>
          <th><?php echo gettext('Status') ?></th>
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
           <td>
            <?php
            echo ino_inline_action($pos_transaction_line->pos_transaction_line_id, array('pos_transaction_header_id' => $$class->pos_transaction_header_id));
            ?>
           </td>
           <td><?php form::number_field_wid2sr('pos_transaction_line_id'); ?></td>
           <td><?php $f->text_field_wid2('item_number'); ?></td>
           <td><?php echo $f->number_field('unit_price', $$class_second->unit_price, '', '', 'medium'); ?></td>
           <td><?php echo $f->number_field('quantity', $$class_second->quantity); ?></td>
           <td><?php $f->text_field_wid2('discount_code'); ?></td>
           <td><?php echo $f->number_field('discount_amount', $$class_second->discount_amount, '', '', 'medium'); ?></td>
           <td><?php echo $f->number_field('line_amount', $$class_second->line_amount, '', '', 'medium'); ?></td>
           <td><?php echo $f->number_field('amount_after_discount', $$class_second->amount_after_discount, '', '', 'medium'); ?></td>
           <td><?php echo $f->select_field_from_array('status', pos_transaction_line::$status_a, $$class_second->status, '', '', 'small'); ?></td>
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
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
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
