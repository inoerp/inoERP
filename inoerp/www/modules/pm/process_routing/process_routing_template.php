<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="form_header"><span class="heading"><?php echo gettext('Process Routing') ?></span>
 <form  method="post" id="pm_process_routing_header"  name="pm_process_routing_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('pm_process_routing_header_id') ?>
       <a name="show" href="form.php?class_name=pm_process_routing_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_process_routing_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('routing_name'); ?></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1, 1, ''); ?>						 </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_select_field_from_array('status', pm_process_routing_header::$status_a,  $$class->status); ?></li>
      <li><?php $f->l_text_field_d('revision'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
      <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date) ?></li>
      <li><?php $f->l_text_field_d('routing_class'); ?></li>
      <li><?php $f->l_text_field_d('quantity'); ?></li>
      <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, '', '', 'uom_id medium'); ?></li>
      <li><?php $f->l_text_field_d('planned_loss'); ?></li>
      <li><?php $f->l_text_field_d('theoretical_loss'); ?></li>
      <li><?php $f->l_text_field_d('fixed_loss'); ?></li>
      <li><label><?php echo gettext('Owner') ?></label><?php $f->text_field_d('pm_employee_name', 'employee_name'); ?>
       <?php echo $f->hidden_field_withId('owner_employee_id', $$class->owner_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'pm_process_routing_header';
        $reference_id = $$class->pm_process_routing_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
     <span class="hidden"><?php echo $f->select_field_from_object('pm_process_operation_header_id', $all_operation_objs, 'pm_process_operation_header_id', array('operation_name' ,'org_id') , $$class_second->pm_process_operation_header_id, 'pm_process_operation_header_id', 'medium' ,'','','','','','org_id'); ?></span>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Routing Lines') ?></span>
 <form method="post" id="pm_process_routing_line"  name="pm_process_routing_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Routing Steps') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Step') ?></th>
        <th><?php echo gettext('Operation') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Step Qty') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Min Qty') ?></th>
        <th><?php echo gettext('Release Type') ?></th>
        <th><?php echo gettext('Operation Details') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php $f = new inoform();
       $count = 0;
       foreach ($pm_process_routing_line_object as $pm_process_routing_line) {
        ?>         
        <tr class="pm_process_routing_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_process_routing_line->pm_process_routing_line_id, array('pm_process_routing_header_id' => $$class->pm_process_routing_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('pm_process_routing_line_id'); ?></td>
         <td><?php $f->text_field_wid2s('step_no'); ?></td>
         <td><?php echo $f->select_field_from_object('pm_process_operation_header_id', $all_operation_objs, 'pm_process_operation_header_id', array('operation_name' ,'org_id') , $$class_second->pm_process_operation_header_id, '', 'medium' ,'','','','','','org_id'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2s('step_quantity'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id medium'); ?></td>
         <td><?php $f->text_field_wid2s('min_quantity'); ?></td>
         <td><?php echo $f->select_field_from_array('release_type', pm_process_routing_line::$release_type_a,  $$class_second->release_type, '', 'uom_id medium'); ?></td>
         <td><a target="_new" class="popup popup-form-i view-operation-details medium" href="form.php?class_name=pm_process_operation_header&mode=9&pm_process_operation_header_id=<?php echo $$class_second->pm_process_operation_header_id ; ?>"> 
           <i class="fa fa-edit"></i></a></td>
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
  <li class="headerClassName" data-headerClassName="pm_process_routing_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_process_routing_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_process_routing_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_process_routing_header" ></li>
  <li class="line_key_field" data-line_key_field="header_type_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_process_routing_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_process_routing_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_process_routing_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_process_routing_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>