<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="form_header"><span class="heading"><?php echo gettext('Process Operation') ?></span>
 <form  method="post" id="pm_process_operation_header"  name="pm_process_operation_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('pm_process_operation_header_id') ?>
       <a name="show" href="form.php?class_name=pm_process_operation_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_process_operation_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('operation_name'); ?></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_text_field_d('status'); ?></li>
      <li><?php $f->l_text_field_d('revision'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
      <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date) ?></li>
      <li><?php $f->l_text_field_d('operation_class'); ?></li>
      <li><?php $f->l_text_field_d('min_quantity'); ?></li>
      <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id medium'); ?></li>
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
        $reference_table = 'pm_process_operation_header';
        $reference_id = $$class->pm_process_operation_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Operation Lines') ?></span>
 <form method="post" id="pm_process_operation_line"  name="pm_process_operation_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('process Steps') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Activity') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Factor') ?></th>
        <th><?php echo gettext('Seq Dependency') ?>?</th>
        <th><?php echo gettext('Offset Interval') ?></th>
        <th><?php echo gettext('Breakable') ?>?</th>
        <th><?php echo gettext('Material Scheduled') ?>?</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php $f = new inoform();
       $count = 0;
       foreach ($pm_process_operation_line_object as $pm_process_operation_line) {
        ?>         
        <tr class="pm_process_operation_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_process_operation_line->pm_process_operation_line_id, array('pm_process_operation_header_id' => $$class->pm_process_operation_header_id));
          ?>
         </td>
        
         <td><?php form::text_field_wid2sr('pm_process_operation_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('activity_code', option_header::find_options_byName('PM_OPERATION_ACTIVITY' ), 'option_line_code' , 'option_line_value', $$class_second->activity_code ,'','medium'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2('activity_factror'); ?></td>
         <td><?php $f->checkBox_field_wid2('sequence_dependency_cb'); ?></td>
         <td><?php $f->text_field_wid2('offset_interval'); ?></td>
         <td><?php $f->checkBox_field_wid2('breakable_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('material_scheduled_cb'); ?></td>
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
  <li class="headerClassName" data-headerClassName="pm_process_operation_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_process_operation_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_process_operation_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_process_operation_header" ></li>
  <li class="line_key_field" data-line_key_field="header_type_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_process_operation_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_process_operation_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_process_operation_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_process_operation_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>