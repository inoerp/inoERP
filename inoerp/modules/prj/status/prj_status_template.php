<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php
  echo gettext('Service Order')
  ?></span>
 <form method="post" id="prj_status_header"  name="prj_status_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic - 2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Address Details') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_status_header_id') ?>
       <a name="show" href="form.php?class_name=prj_status_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_status_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('order_number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><label>Service Type</label>
       <?php echo $f->select_field_from_object('hd_service_type_header_id', hd_service_type_header::find_all(), 'hd_service_type_header_id', 'service_type', $$class->hd_service_type_header_id, 'hd_service_type_header_id', 'medium', 1, $readonly1); ?>						 </li>
      <li><label class="auto_complete"><?php echo gettext('Customer Name') ?></label><?php
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1);
       ?>
       <i class="ar_customer_id select_popup clickable fa fa-search"></i></li>
      <li><label class="auto_complete"><?php echo gettext('Customer Number') ?></label><?php $f->text_field_d('customer_number'); ?></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><label><?php echo gettext('Item Number') ?></label><?php
       echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
       $f->text_field_dm('item_number', 'select_item_number');
       echo $f->hidden_field_withCLass('build_in_wip_cb', '1', 'popup_value');
       ?><i class="select_item_number select_popup clickable fa fa-search"></i>
      </li>
      <li><?php
       echo $f->hidden_field_withId('serial_status', 'OUT_STORE');
       $f->l_text_field_d('inv_serial_number_id', 'select inv_serial_number_id');
       ?>
       <i class="select inv_serial_number_id fa fa-refresh clickable select_popup"></i></li>
      <li><?php $f->l_text_field_d('item_description'); ?></li>
      <li><?php $f->l_text_field_dr('repair_status') ?></li>
      <li><?php $f->l_text_field_d('hd_service_request_id', '1', 'popup_value'); ?><i class="hd_service_request_id select_popup clickable fa fa-search"></i>      </li>
     </ul> 
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('service_team_id', hr_team_header::find_all_by_type('SERVICE'), 'team_name', 'hr_team_header_id', $$class->service_team_id, 'service_team_id'); ?>
      </li>
      <li><label><?php echo gettext('Service Person') ?></label><?php $f->text_field_d('service_person', 'employee_name'); ?>
       <?php echo $f->hidden_field_withIdClass('service_person_employee_id', $$class->service_person_employee_id, 'hr_employee_id'); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_text_field_dr('order_reference_id'); ?> </li> 
      <li><?php $f->l_text_field_dr('order_reference_table'); ?></li> 
      <li><?php echo empty($$class->primary_sd_so_header_id) ? $f->l_text_field_d('primary_sd_so_header_id', 'dont_copy') : $f->l_text_field_dr('primary_sd_so_header_id', 'dont_copy'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', '', $readonly1); ?>						 </li>
      <li><?php $f->l_date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?></li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
      <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?></li>
      <li><?php $f->l_number_field('estimate_amount', $$class->estimate_amount, '15', 'estimate_amount'); ?></li>
      <li><?php $f->l_number_field('prepaid_amount', $$class->prepaid_amount, '15', 'prepaid_amount'); ?></li>
      <li><?php $f->l_text_field_d('prepaid_status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_status_header';
        $reference_id = $$class->prj_status_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-7" class="tabContent">
     <ul class="column header_field">
      <li id="document_status"><label><?php echo gettext('Action') ?></label>
       <?php echo $f->select_field_from_array('action', $$class->action_a, '', 'action'); ?>
      </li>
      <li><label><?php echo gettext('Add To Order') ?></label>
       <?php echo $f->select_field_from_array('add_to_order', $add_to_order_a, '', 'add_to_order', '', '', '', 1); ?>
      </li>
     </ul>
    </div>
   </div>

  </div>
 </form>
</div>

<span class="heading"><?php echo gettext('Order Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Logistics') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Logistics-2') ?></a></li>
  <li><a href="#tabsLine-3"><?php echo gettext('Estimates') ?> </a></li>
  <li><a href="#tabsLine-4"><?php echo gettext('Estimates-2') ?> </a></li>
  <li><a href="#tabsLine-5"><?php echo gettext('Repair WO') ?> </a></li>
  <li><a href="#tabsLine-6"><?php echo gettext('Actuals-1') ?> </a></li>
  <li><a href="#tabsLine-7"><?php echo gettext('Actuals-2') ?> </a></li>
 </ul>
 <div class="tabContainer">
  <form action=""  method="post" id="prj_status_line"  name="prj_status_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq#') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Inv Org') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Add To Order') ?></th>
        <th><?php echo gettext('Logistic Action') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_status_line_object as $prj_status_line) {
        ?>         
        <tr class="prj_status_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_status_line->prj_status_line_id, array('prj_status_header_id' => $prj_status_header->prj_status_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('prj_status_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('service_activity_header_id', hd_service_activity_header::find_all(), 'hd_service_activity_header_id', 'activity_name', $$class_second->service_activity_header_id, '', 'medium', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('inv_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->inv_org_id, '', '', 1, $readonly); ?></td>
         <td><?php
          echo $f->text_field('item_number', $$class_second->item_number, '20', '', 'select_item_number', '', $readonly);
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          ?>
          <i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php form::text_field_wid2s('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php form::number_field_wid2s('quantity'); ?></td>
         <td><?php echo empty($$class_second->sd_so_header_id) ? $f->select_field_from_array('add_to_order', $add_to_order_a, '') : ''; ?></td>
         <td><?php echo $f->select_field_from_array('logistic_action', prj_status_line::$action_a, ''); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>

    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq#') ?></th>
        <th><?php echo gettext('SO Line Id') ?></th>
        <th><?php echo gettext('SO Header Id') ?></th>
        <th><?php echo gettext('Line Status') ?></th>
        <th><?php echo gettext('Price List') ?></th>
        <th><?php echo gettext('Price Date') ?></th>
        <th><?php echo gettext('Unit Price') ?></th>
        <th><?php echo gettext('Line Price') ?></th>
        <th><?php echo gettext('View Details') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_status_line_object as $prj_status_line) {
        ?>         
        <tr class="prj_status_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2r('sd_so_line_id', 'dontCopy'); ?></td>
         <td><?php $f->text_field_wid2r('sd_so_header_id', 'dontCopy'); ?></td>
         <td><?php $f->text_field_wid2r('line_status', 'dontCopy'); ?></td>
         <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>         </td>
         <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date) ?></td>
         <td><?php form::number_field_wid2('unit_price'); ?></td>
         <td><?php form::number_field_wid2('line_price'); ?></td>
         <td><a target="_blank" href="form.php?class_name=sd_so_header&sd_so_header_id=<?php echo $prj_status_line->sd_so_header_id ?>" ><i class="fa fa-file-text-o margin-left-20"></i></a></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form method="post" id="prj_status_next"  name="prj_status_next">
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Estimate Id') ?></th>
        <th><?php echo gettext('Billing Source') ?></th>
        <th><?php echo gettext('Billing Category') ?></th>
        <th><?php echo gettext('Item Id') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_status_next_object as $prj_status_next) {
        if (!empty($prj_status_next->item_id_m)) {
         $item = item::find_by_item_id_m($prj_status_next->item_id_m);
         $$class_third->billing_item_number = $item->item_number;
         $$class_third->billing_description = $item->item_description;
         $$class_third->billing_uom = $item->uom_id;
        }
        ?>         
        <tr class="prj_status_next<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_status_next->prj_status_next_id); ?>"></li>           
           <li><?php echo form::hidden_field('prj_status_header_id', $$class->prj_status_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('prj_status_next_id'); ?></td>
         <td><?php echo $f->select_field_from_array('billing_source', prj_status_next::$billing_source_a, $$class_third->billing_source, '', 'medium'); ?></td>
         <td><?php echo $f->select_field_from_object('billing_type', hd_service_type_header::billing_type(), 'option_line_code', 'option_line_value', $$class_third->billing_type, '', 'medium'); ?></td>
         <td><?php echo $f->text_field('item_id_m', $$class_third->item_id_m, '8', '', 'item_id_m', 1, 1); ?></td>
         <td><?php echo $f->text_field('billing_item_number', $$class_third->billing_item_number, '20', '', 'select_item_number', '', $readonly);
        ?><i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php echo $f->text_field('billing_description', $$class_third->billing_description, '20', '', 'item_description', '', $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('billing_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_third->billing_uom, '', 'uom_id', '', $readonly); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Estimate Id') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Price List') ?></th>
        <th><?php echo gettext('Unit Price') ?></th>
        <th><?php echo gettext('Line Price') ?></th>
        <th><?php echo gettext('Line Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_status_next_object as $prj_status_next) {
        ?>         
        <tr class="prj_status_next<?php echo $count ?>">
         <td><?php echo $$class_third->prj_status_next_id; ?></td>
         <td><?php form::number_field_wid3sm('quantity'); ?></td>
         <td><?php echo $f->text_field_wid3('price_list_header_id'); ?></td>
         <td><?php echo $f->text_field_wid3('unit_price'); ?></td>
         <td><?php echo $f->text_field_wid3('line_price'); ?></td>
         <td><?php echo $f->text_field_wid3('line_status'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>
  <div id="tabsLine-5" class="tabContent">
  </div>
  <div id="tabsLine-6" class="tabContent">
   <table class="form_line_data_table3">
    <thead> 
     <tr>
      <th><?php echo gettext('Action') ?></th>
      <th><?php echo gettext('Actuals Id') ?></th>
      <th><?php echo gettext('Source') ?></th>
      <th><?php echo gettext('Billing Category') ?></th>
      <th><?php echo gettext('Item Id') ?></th>
      <th><?php echo gettext('Item Number') ?></th>
      <th><?php echo gettext('Item Description') ?></th>
      <th><?php echo gettext('UOM') ?></th>
     </tr>
    </thead>
    <tbody class="form_data_line_tbody3 wip_wo_bom_values" >
     <?php
     $count = 0;
     foreach ($prj_status_actuals_object as $prj_status_actuals) {
      if (!empty($prj_status_actuals->item_id_m)) {
       $item = item::find_by_item_id_m($prj_status_actuals->item_id_m);
       $$class_fourth->billing_item_number = $item->item_number;
       $$class_fourth->billing_description = $item->item_description;
       $$class_fourth->billing_uom = $item->uom_id;
      }
      ?>         
      <tr class="prj_status_actuals<?php echo $count ?>">
       <td>    
        <ul class="inline_action">
         <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
         <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
         <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_status_actuals->prj_status_actuals_id); ?>"></li>           
         <li><?php echo form::hidden_field('prj_status_header_id', $$class->prj_status_header_id); ?></li>
        </ul>
       </td>
       <td><?php form::text_field_wid4sr('prj_status_actuals_id'); ?></td>
       <td><?php echo $f->select_field_from_array('source', prj_status_actuals::$source_a, $$class_fourth->source, '', 'medium'); ?></td>
       <td><?php echo $f->select_field_from_object('billing_type', hd_service_type_header::billing_type(), 'option_line_code', 'option_line_value', $$class_fourth->billing_type, '', 'medium', '', 1); ?></td>
       <td><?php echo $f->text_field('item_id_m', $$class_fourth->item_id_m, '8', '', 'item_id_m', '', 1); ?></td>
       <td><?php echo $f->text_field('billing_item_number', $$class_fourth->billing_item_number, '20', '', '', '', $readonly); ?></td>
       <td><?php echo $f->text_field('billing_description', $$class_fourth->billing_description, '20', '', 'item_description', '', $readonly); ?></td>
       <td><?php echo $f->select_field_from_object('billing_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_fourth->billing_uom, '', 'uom_id', '', 1); ?></td>
      </tr>
      <?php
      $count = $count + 1;
     }
     ?>
    </tbody>
   </table>
  </div>
  <div id="tabsLine-7" class="tabContent">
   <table class="form_line_data_table3">
    <thead> 
     <tr>
      <th><?php echo gettext('Actual Id') ?></th>
      <th><?php echo gettext('Quantity') ?></th>
      <th><?php echo gettext('Unit Price') ?></th>
      <th><?php echo gettext('Line Price') ?></th>
      <th><?php echo gettext('Line Status') ?></th>
      <th><?php echo gettext('SO Line Id') ?></th>
     </tr>
    </thead>
    <tbody class="form_data_line_tbody3 wip_wo_bom_values" >
     <?php
     $count = 0;
     foreach ($prj_status_actuals_object as $prj_status_actuals) {
      ?>         
      <tr class="prj_status_actuals<?php echo $count ?>">
       <td><?php echo $$class_fourth->prj_status_actuals_id; ?></td>
       <td><?php form::number_field_wid4sr('quantity'); ?></td>
       <td><?php echo $f->text_field_wid4r('unit_price'); ?></td>
       <td><?php echo $f->text_field_wid4('line_price'); ?></td>
       <td><?php echo $f->text_field_wid4r('line_status'); ?></td>
       <td><?php echo $f->text_field_wid4r('sd_so_line_id'); ?></td>
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




<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_status_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_status_line" ></li>
  <li class="lineClassName2" data-lineClassName2="prj_status_next" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_status_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_status_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_status_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_status_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_status_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_status_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>