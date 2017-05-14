<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id="form_all">
 <span class="heading"><?php echo gettext('Standard Operation') ?></span>
 <form action=""  method="post" id="bom_standard_operation"  name="bom_standard_operation">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php echo $f->l_text_field_dr_withSearch('bom_standard_operation_id'); ?>
        <a name="show" href="form.php?class_name=bom_standard_operation&<?php echo "mode=$mode"; ?>" class="show document_id bom_standard_operation_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly); ?>        </li>
       <li><?php $f->l_select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->department_id, 'department_id', '', '', $readonly); ?>        </li>
       <li><?php $f->l_text_field_d('standard_operation'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_checkBox_field_d('count_point_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('auto_charge_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('count_point_cb'); ?></li>
       <li><?php $f->l_status_field_d('status'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'bom_standard_operation';
        $reference_id = $$class->bom_standard_operation_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
    </div>

   </div>
  </div>
 </form>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Standard Operation Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Resource Assignment') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="bom_stnd_op_res_assignment_line"  name="bom_stnd_op_res_assignment_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Assignment Id') ?>#</th>
         <th><?php echo gettext('Resource Seq') ?></th>
         <th><?php echo gettext('Resource') ?></th>
         <th><?php echo gettext('Basis') ?></th>
         <th><?php echo gettext('Usage') ?></th>
         <th><?php echo gettext('Schedule') ?></th>
         <th><?php echo gettext('Units') ?></th>
         <th><?php echo gettext('24 Hours') ?></th>
         <th><?php echo gettext('Stnd. Rate') ?></th>
         <th><?php echo gettext('Charge Type') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody bom_stnd_op_res_assignment_values" >
        <?php
        $count = 0;
        foreach ($bom_stnd_op_res_assignment_object as $bom_stnd_op_res_assignment) {
         ?>         
         <tr class="bom_stnd_op_res_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->bom_stnd_op_res_assignment_id, array('bom_standard_operation_id' => $$class->bom_standard_operation_id));
           ?>
          </td>
          <td><?php $f->text_field_wid2sr('bom_stnd_op_res_assignment_id' ,'always_readonly'); ?></td>
          <td><?php form::number_field_wid2s('resource_sequence') ?></td>
          <td>
           <?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_second->resource_id, '', $readonly, 'resource_id'); ?>
          </td>
          <td><?php echo $f->select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_second->charge_basis, '', ' default_basis medium' , '' , $readonly); ?></td>
          <td><?php form::number_field_wid2s('resource_usage') ?></td>
          <td><?php echo $f->select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_second->resource_schedule, '',  'medium', '' , $readonly); ?></td>
          <td><?php form::number_field_wid2('assigned_units') ?></td>
          <td><?php echo form::checkBox_field('twenty_four_hr_cb', $$class_second->twenty_four_hr_cb); ?></td>
          <td><?php echo form::checkBox_field('standard_rate_cb', $$class_second->standard_rate_cb); ?></td>
          <td><?php echo $f->select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class_second->charge_type, '', 'medium' , '' , $readonly); ?></td>
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

  </div>
 </div> 
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_standard_operation" ></li>
  <li class="lineClassName" data-lineClassName="bom_stnd_op_res_assignment" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_standard_operation_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_standard_operation" ></li>
  <li class="line_key_field" data-line_key_field="resource_sequence" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_standard_operation_id" ></li>
  <li class="docLineId" data-docLineId="bom_stnd_op_res_assignment_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_standard_operation" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="bom_standard_operation" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>