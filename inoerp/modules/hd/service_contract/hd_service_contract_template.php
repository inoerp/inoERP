<div id ="form_header"><span class="heading"><?php   echo gettext('Service Contract')   ?></span>
 <form  method="post" id="hd_service_contract_header"  name="hd_service_contract_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic-2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Address') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Others') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-8"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hd_service_contract_header_id'); ?>
       <a name="show" href="form.php?class_name=hd_service_contract_header&<?php echo "mode=$mode"; ?>" class="show document_id hd_service_contract_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('contract_number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>             </li>
      <li><?php $f->l_select_field_from_array('category', hd_service_contract_header::$category_a, $$class->category, 'category', '', 1, $readonly1); ?>             </li>
      <li><?php $f->l_date_fieldAnyDay_m('start_date', $$class->start_date) ?></li>
      <li><?php $f->l_date_fieldAnyDay_m('end_date', $$class->end_date) ?></li>
      <li><?php $f->l_select_field_from_object('duration_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->duration_uom_id, 'duration_uom_id', 'uom_id', '', $readonly1); ?>         </li>
      <li><?php
       $f->hidden_field_withId('duration_days', '');
       $f->l_text_field_d('duration')
       ?></li>
      <li><?php $f->l_text_field_d('description') ?></li>
      <li><?php $f->l_text_field_dr('status') ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?>
       <label class="auto_complete"><?php echo gettext('Customer Name') ?></label>
       <?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1); ?>
       <i class="ar_customer_id select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('customer_number'); ?></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><?php $f->l_text_field_d('document_owner'); ?></li> 
      <li><?php $f->l_text_field_d('sales_person_employee_id') ?></li>
     </ul>					 
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>

    <div id="tabsHeader-4" class="tabContent">
     <div>
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>						 </li></li>
       <li><?php $f->l_date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
       <li><?php $f->l_checkBox_field_d('billing_cb') ?></li>
       <li><?php $f->l_text_field_d('invoicing_rule') ?></li>
       <li><?php $f->l_text_field_d('accounting_rule') ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('renewal_process') ?></li>
      <li><?php $f->l_text_field_d('renew_upto_date') ?></li>
      <li><?php $f->l_text_field_d('rewnew_pricing_method') ?></li>
      <li><?php $f->l_text_field_d('rewnew_price_list_id') ?></li>
      <li><?php $f->l_text_field_dr('reference_type') ?></li>
      <li><?php $f->l_text_field_dr('reference_key_name') ?></li>
      <li><?php $f->l_text_field_dr('reference_key_value') ?></li>
     </ul>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'hd_service_contract_header';
       $reference_id = $$class->hd_service_contract_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>

    <div id="tabsHeader-7" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-8" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_array('transaction_action', $$class->action_a, '', 'transaction_action', '', '', $readonly); ?>       </li>
       <li id="document_status"><label><?php echo gettext('Change Status') ?></label>
        <?php echo form::select_field_from_object('approval_status', hd_service_contract_header::ar_approval_status(), 'option_line_code', 'option_line_value', $hd_service_contract_header->approval_status, 'set_approval_status', $readonly, '', ''); ?>
       </li>
      </ul>

      <div id="comment" class="show_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Contract Lines') ?></span>
 <form action=""  method="post" id="hd_service_contract_line"  name="hd_service_contract_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Renewal') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('References') ?> </a></li>

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
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Contract Details') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_contract_line_object as $hd_service_contract_line) {
        ?>         
        <tr class="hd_service_contract_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->hd_service_contract_line_id, array('hd_service_contract_header_id' => $$class->hd_service_contract_header_id,
           'category' => $$class->category));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_service_contract_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_array('line_type', hd_service_contract_line::$line_type_a, $$class_second->line_type , '' , 'medium'); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          $f->text_field_wid2('item_number', 'select_item_number');
          ?>
          <i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php $f->text_field_wid2m('item_description' ,'xlarge'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $hd_service_contract_line->uom_id , '' , 'medium'); ?></td>
         <td><?php form::number_field_wid2sm('line_quantity'); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <!--</td></tr>-->	
          <?php
          $hd_service_contract_line_id = $$class_second->hd_service_contract_line_id;
          if (!empty($hd_service_contract_line_id)) {
           $hd_service_contract_detail_object = hd_service_contract_detail::find_by_hd_service_contract_lineId($hd_service_contract_line_id);
          } else {
           $hd_service_contract_detail_object = array();
          }

          if (empty($hd_service_contract_detail_object)) {
           $hd_service_contract_detail = new hd_service_contract_detail();
           $hd_service_contract_detail_object = array();
           array_push($hd_service_contract_detail_object, $hd_service_contract_detail);
          }
          ?>
                                         <!--						 <tr><td>-->
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Price') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-3-<?php echo $count ?>"><?php echo gettext('References') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Detail Id') ?></th>
                  <th><?php echo gettext('Detail') ?>#</th>
                  <th><?php echo gettext('Level') ?></th>
                  <th><?php echo gettext('Item') ?></th>
                  <th><?php echo gettext('Serial') ?></th>
                  <th><?php echo gettext('Start Date') ?></th>
                  <th><?php echo gettext('End Date') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($hd_service_contract_detail_object as $hd_service_contract_detail) {
                  $class_third = 'hd_service_contract_detail';
                  $$class_third = &$hd_service_contract_detail;
                  $$class_third->item_number = !empty($$class_third->item_id_m) ? item::find_by_item_id_m($$class_third->item_id_m)->item_number : '';
                  $$class_third->serial_number = !empty($$class_third->inv_serial_number_id) ? inv_serial_number::find_by_id($$class_third->inv_serial_number_id)->serial_number : '';
                  ?>
                  <tr class="hd_service_contract_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>
                    <?php
                    echo ino_inline_action($$class_third->hd_service_contract_detail_id, array('hd_service_contract_header_id' => $$class->hd_service_contract_header_id,
                     'hd_service_contract_line_id' => $$class_second->hd_service_contract_line_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3sr('hd_service_contract_detail_id'); ?></td>
                   <td><?php $f->text_field_wid3s('detail_number'); ?></td>
                   <td><?php echo $f->select_field_from_array('level', hd_service_contract_detail::$level_a, $$class_third->level , '' , 'medium'); ?></td>
                   <td><?php
                    echo $f->hidden_field('item_id_m', $$class_third->item_id_m);
                    $f->text_field_wid3('item_number', 'select_item_number');
                    ?>
                    <i class="select_item_number select_popup clickable fa fa-search"></i></td>
                   <td><?php
                    echo $f->hidden_field_withId('inv_serial_number_id', $$class_third->inv_serial_number_id);
                    $f->text_field_wid3('serial_number', 'select_serial_number');
                    echo $f->hidden_field_withCLass('serial_status', 'OUT_STORE', 'popup_value');
                    echo $f->hidden_field_withCLass('serial_item_id_m', $$class_third->item_id_m, 'item_id_m');
                    ?><i class="select_serial_number select_popup clickable fa fa-search"></i>
                   </td>
                   <td><?php echo $f->date_fieldAnyDay_m('start_date', $$class_third->start_date, '') ?></td>
                   <td><?php echo $f->date_fieldAnyDay_m('end_date', $$class_third->end_date, '') ?></td>

                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Unit Price') ?></th>
                  <th><?php echo gettext('Line Price') ?></th>
                  <th><?php echo gettext('Tax Code') ?></th>
                  <th><?php echo gettext('Tax Amount') ?></th>
                  <th><?php echo gettext('Duration UOM') ?></th>
                  <th><?php echo gettext('Duration') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($hd_service_contract_detail_object as $hd_service_contract_detail) {
                  $class_third = 'hd_service_contract_detail';
                  $$class_third = &$hd_service_contract_detail;
                  ?>
                  <tr class="hd_service_contract_detail<?php echo $count . '-' . $detailCount; ?> ">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php form::number_field_wid2m('unit_price'); ?></td>
                   <td><?php form::text_field_wid2m('line_price'); ?></td>
                   <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium', '', $readonly1, '', '', '', 'percentage') ?></td>
                   <td><?php form::number_field_wid2('tax_amount'); ?></td>
                   <td><?php echo $f->select_field_from_object('duration_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->duration_uom_id, 'duration_uom_id', 'uom_id', '', $readonly1); ?>         </td>
                   <td><?php echo $f->text_field_d2('duration') ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-3-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Ref Type') ?>#</th>
                  <th><?php echo gettext('Ref Key Name') ?></th>
                  <th><?php echo gettext('Ref Key Value') ?>#</th>
                  <th><?php echo gettext('Renewal Type') ?></th>

                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($hd_service_contract_detail_object as $hd_service_contract_detail) {
                  $class_third = 'hd_service_contract_detail';
                  $$class_third = &$hd_service_contract_detail;
                  ?>
                  <tr class="hd_service_contract_detail<?php echo $count . '-' . $detailCount; ?> ">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3('reference_type') ?></td>
                   <td><?php $f->text_field_wid3('reference_key_name'); ?></td>
                   <td><?php $f->text_field_wid3('reference_key_value'); ?></td>
                   <td><?php $f->text_field_wid3('renewal_type'); ?></td>
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

         </td></tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Unit Price') ?></th>
        <th><?php echo gettext('Line Price') ?></th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('Tax Amount') ?></th>
        <th><?php echo gettext('Line Description') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_contract_line_object as $hd_service_contract_line) {
        ?>         
        <tr class="hd_service_contract_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::number_field_wid2m('unit_price'); ?></td>
         <td><?php form::text_field_wid2m('line_price'); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium', '', $readonly1, '', '', '', 'percentage') ?></td>
         <td><?php form::number_field_wid2('tax_amount'); ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>
         <td><?php $f->text_field_wid2sr('status'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-3" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Source') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
        <th><?php echo gettext('Duration UOM') ?></th>
        <th><?php echo gettext('Duration') ?></th>
        <th><?php echo gettext('Termination Date') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_contract_line_object as $hd_service_contract_line) {
        ?>         
        <tr class="hd_service_contract_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->text_field_wid2sr('line_source'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('start_date', $$class_second->start_date) ?></td>
         <td><?php echo $f->date_fieldAnyDay('end_date', $$class_second->end_date) ?></td>
         <td><?php echo $f->select_field_from_object('duration_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->duration_uom_id, 'duration_uom_id', 'uom_id', '', $readonly1); ?>         </td>
         <td><?php echo $f->text_field_d2('duration') ?></td>
         <td><?php echo $f->date_fieldAnyDay('termination_date', $$class_second->termination_date) ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-4" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Source') ?></th>
        <th><?php echo gettext('Ref Type') ?></th>
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Key Value') ?></th>
        <th><?php echo gettext('Counter') ?></th>
        <th><?php echo gettext('Event') ?>#</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_contract_line_object as $hd_service_contract_line) {
        ?>         
        <tr class="hd_service_contract_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2r('line_source'); ?></td>
         <td><?php $f->text_field_wid2r('reference_type'); ?></td>
         <td><?php $f->text_field_d2('reference_key_name'); ?></td>
         <td><?php $f->text_field_wid2r('reference_key_value'); ?></td>
         <td><?php $f->text_field_wid2r('counter_instance_id'); ?></td>
         <td><?php $f->text_field_wid2r('event_id'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hd_service_contract_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_service_contract_line" ></li>
  <li class="detailClassName" data-detailClassName="hd_service_contract_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_service_contract_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_service_contract_header" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hd_service_contract_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_service_contract_header_id" ></li>
  <li class="docLineId" data-docLineId="hd_service_contract_line_id" ></li>
  <li class="docDetailId" data-docDetailId="hd_service_contract_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_service_contract_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="hd_service_contract_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
