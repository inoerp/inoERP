<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Membership Application') ?></span>
 <form  method="post" id="hd_subscription_header"  name="hd_subscription_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Address Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hd_subscription_header_id') ?>
       <a name="show" href="form.php?class_name=hd_subscription_header&<?php echo "mode=$mode"; ?>" class="show document_id hd_subscription_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_array('subscription_type', hd_subscription_header::$subscription_type_a, $$class->subscription_type, 'subscription_type'); ?></li>
      <li><?php $f->l_select_field_from_object('document_type', option_header::find_options_byName('HD_SUBSCR_DOC_TYPE'), 'option_line_code', 'option_line_value', $hd_subscription_header->document_type, 'document_type', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_text_field_d('first_name'); ?></li>
      <li><?php $f->l_text_field_d('last_name'); ?></li>
      <li><?php $f->l_text_field_d('full_name'); ?></li>
      <li><?php $f->l_text_field_d('passport_number'); ?></li>
      <li><?php $f->l_select_field_from_object('gender', hr_employee::gender(), 'option_line_code', 'option_line_value', $$class->gender, '', 'gender', '', $readonly); ?>              </li>
      <li><?php $f->l_select_field_from_object('marital_status', hr_employee::marital_status(), 'option_line_code', 'option_line_value', $$class->marital_status, '', 'marital_status', '', $readonly); ?>              </li>
      <li><?php $f->l_text_field_d('nationality'); ?></li>
      <li><?php $f->l_text_field_d('occupation'); ?></li>
      <li><?php $f->l_text_field_dr('so_status') ?></li>
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
     <div class="shipto_address"><?php $f->address_field_d('address_id'); ?></div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
      <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'hd_subscription_header';
        $reference_id = $$class->hd_subscription_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li id="document_status"><label><?php echo gettext('Action') ?></label>
        <?php echo $f->select_field_from_object('action', hd_subscription_header::so_status(), 'option_line_code', 'option_line_value', '', 'action'); ?>
       </li>
      </ul>

      <div id="comment" class="shoe_comments">
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Membership Plan') ?></span>
 <form action=""  method="post" id="so_site"  name="hd_subscription_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Compulsory') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Supplementary Child') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Supplementary Driver') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Additional Car') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Membership') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Price') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($hd_subscription_line->hd_subscription_line_id, array('hd_subscription_header_id' => $hd_subscription_header->hd_subscription_header_id,
           'tax_code_value' => $$class_second->tax_code_value));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_subscription_line_id', 'line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', sd_document_type::find_all_line_levels(), 'sd_document_type_id', 'document_type_name', $$class_second->line_type, '', 'medium', 1, $readonly, '', '', '', 'process_flow_id'); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'shipping_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
          echo $f->hidden_field_withCLass('customer_ordered_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid2s('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>

         <td><?php form::number_field_wid2s('line_quantity'); ?></td>
         <td><?php form::number_field_wid2('unit_price'); ?></td>
        </tr>
        <?php
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hd_subscription_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_subscription_line" ></li>
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
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>