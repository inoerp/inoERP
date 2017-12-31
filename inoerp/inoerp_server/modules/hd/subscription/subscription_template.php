<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header" class="erp-form"><span class="heading"><?php echo gettext('Membership Application') ?></span>
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
      <li><?php $f->l_select_field_from_array('subscription_type', hd_subscription_header::$subscription_type_a, $$class->subscription_type, 'subscription_type', '', 1); ?></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>        </li>
			<li><?php $f->l_select_field_from_object('document_type', option_header::find_options_byName('HD_SUBSCR_DOC_TYPE'), 'option_line_code', 'option_line_value', $hd_subscription_header->document_type, 'document_type', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_text_field_d('first_name'); ?></li>
      <li><?php $f->l_text_field_d('last_name'); ?></li>
      <li><?php $f->l_text_field_d('full_name'); ?></li>
      <li><?php $f->l_text_field_d('passport_number'); ?></li>
      <li><?php $f->l_select_field_from_object('gender', hr_employee::gender(), 'option_line_code', 'option_line_value', $$class->gender, '', 'gender', '', $readonly); ?>              </li>
      <li><?php $f->l_select_field_from_object('marital_status', hr_employee::marital_status(), 'option_line_code', 'option_line_value', $$class->marital_status, '', 'marital_status', '', $readonly); ?>              </li>
      <li><?php $f->l_text_field_d('nationality'); ?></li>
      <li><?php $f->l_text_field_d('occupation'); ?></li>
      <li><?php $f->l_text_field_dr('status') ?></li>
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
 <form action=""  method="post" id="hd_subscription_line"  name="hd_subscription_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Compulsory') ?></a></li>
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
        <th><?php echo gettext('Line Price') ?></th>
        <th><?php echo gettext('Additional') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        $$class_second->line_type = empty($hd_subscription_line->hd_subscription_line_id) ? 'COMPULSORY' : $$class_second->line_type;
        $$class_second->uom_id = empty($$class_second->uom_id) ? '46' : $$class_second->uom_id;
        $$class_second->item_number = !empty($$class_second->item_id_m) ? item::find_by_item_id_m($$class_second->item_id_m)->item_number : '';
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($hd_subscription_line->hd_subscription_line_id, array('hd_subscription_header_id' => $hd_subscription_header->hd_subscription_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_subscription_line_id', 'line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', option_header::find_options_byName('HD_SUBSCR_LINE_TYPE'), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'medium', 1); ?>						 </td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'shipping_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
          echo $f->hidden_field_withCLass('customer_ordered_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php form::number_field_wid2('line_quantity'); ?></td>
         <td><?php form::number_field_wid2('unit_price'); ?></td>
         <td><?php form::number_field_wid2('line_price'); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <!--</td></tr>-->	
          <?php
          $hd_subscription_line_id = $hd_subscription_line->hd_subscription_line_id;
          if (!empty($hd_subscription_line_id)) {
           $hd_subscription_detail_object = hd_subscription_detail::find_by_hd_subscription_lineId($hd_subscription_line_id);
          } else {
           $hd_subscription_detail_object = array();
          }
          if (count($hd_subscription_detail_object) == 0) {
           $hd_subscription_detail = new hd_subscription_detail();
           $hd_subscription_detail_object = array();
           array_push($hd_subscription_detail_object, $hd_subscription_detail);
          }
          ?>
                                  <!--						 <tr><td>-->
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Additional Plan') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
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
                 foreach ($hd_subscription_detail_object as $hd_subscription_detail) {
                  $class_third = 'hd_subscription_detail';
                  $$class_third = &$hd_subscription_detail;
//												pa($hd_subscription_detail);
                  ?>
                  <tr class="hd_subscription_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>
                    <?php
                    echo ino_inline_action($$class_third->hd_subscription_detail_id, array('hd_subscription_header_id' => $$class->hd_subscription_header_id,
                     'hd_subscription_line_id' => $$class_second->hd_subscription_line_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->text_field_wid3sr('hd_subscription_detail_id'); ?></td>
                   <td><?php $f->text_field_wid3r('line_type','copyValue always_readonly'); ?></td>
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
              </div>
             </div>
            </div>


           </fieldset>

          </div>

         </td>
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