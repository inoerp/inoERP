<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Resource Transaction') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Other Details') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
       <li><?php
        $f->l_val_field_d('wo_number' ,'wip_wo_header', 'wo_number' ,'org_id', '');
        echo $f->hidden_field_withId('wip_wo_header_id', $$class->wip_wo_header_id);
        echo $f->hidden_field_withCLass('wo_status','RELEASED','popup_value');
        ?>
        <i class="generic g_select_wo_number select_popup clickable fa fa-search" data-class_name="wip_wo_header"></i>
        <a name="show2" href="form.php?class_name=wip_resource_transaction&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wo_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
      <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
      <li><?php $f->l_select_field_from_object('transaction_type', wip_move_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', '', 1, 1, 1); ?>       
       <a name="show2" href="form.php?class_name=wip_resource_transaction&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_resource_transaction_id">
        <i class="fa fa-refresh"></i></a> 
      </li> 
     </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr('item_id_m'); ?></li>
      <li><?php $f->l_text_field_dr('item_number'); ?></li>
      <li><?php $f->l_text_field_dr('item_description'); ?></li>
      <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', '', '', 1); ?> </li>
      <li><?php $f->l_number_field_dr('total_quantity'); ?></li>
      <li><?php $f->l_number_field('completed_quantity', $$class_second->completed_quantity); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_header_id'); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_line_id'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Operation Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Operation') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="wip_resource_transaction"  name="wip_resource_transaction">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Routing Seq') ?></th>
        <th><?php echo gettext('Department') ?></th>
        <th><?php echo gettext('Resource Seq') ?></th>
        <th><?php echo gettext('Resource') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Required') ?></th>
        <th><?php echo gettext('Applied') ?></th>
        <th><?php echo gettext('Reason') ?></th>
        <th><?php echo gettext('Reference') ?></th>
        <th><?php echo gettext('Trnx Id') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
       <?php
       $detailCount = 0;
       foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
        $class_third = 'wip_wo_routing_detail';
        $$class_third = &$wip_wo_routing_detail;
        ?>
        <tr class="wip_resource_transaction<?php echo $detailCount ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_routing_line->wip_wo_routing_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>
           <li><?php echo form::hidden_field('org_id', $$class->org_id); ?></li>
           <li><?php echo form::hidden_field('transaction_type', $$class->transaction_type); ?></li>
           <li><?php echo form::hidden_field('transaction_date', $$class->transaction_date); ?></li>
           <li><?php echo form::hidden_field('wip_wo_routing_line_id', $$class_third->wip_wo_routing_line_id); ?></li>
           <li><?php echo form::hidden_field('wip_wo_routing_detail_id', $$class_third->wip_wo_routing_detail_id); ?></li>
          </ul>
         </td>
         <td><?php form::number_field_wid3sr('routing_sequence'); ?></td>
         <td><?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_third->department_id, 'department_id', 1); ?></td>
         <td><?php form::text_field_wid3sr('resource_sequence'); ?></td>
         <td><?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', 1, 'resource_id', '', 1); ?></td>
         <td><?php form::number_field_wids('transaction_quantity'); ?></td>
         <td><?php form::number_field_wid3sr('required_quantity'); ?></td>
         <td><?php form::number_field_wid3sr('applied_quantity'); ?></td>
         <td><?php $f->text_field_wid('reason'); ?></td>
         <td><?php $f->text_field_wids('reference'); ?></td>
         <td><?php echo form::text_field_dsr('wip_resource_transaction_id'); ?></td>
        </tr>
        <?php
        $detailCount++;
       }
       ?>

      </tbody>
     </table>


    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
      </ul>
     </div>
     <div class="second_rowset">

     </div> 
     <!--                end of tab2 div three_column-->
    </div>
   </form>
  </div>
 </div>
</div> 


<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="wip_resource_transaction" ></li>
  <li class="line_key_field" data-line_key_field="name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="wip_resource_transaction" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="wip_resource_transaction_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="wip_resource_transaction" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>