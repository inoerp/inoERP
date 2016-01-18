<div class="row small-left-padding">
<div id="form_all">
 <div id="form_headerDiv">
  <form  method="post" id="mdm_tax_code_line"  name="tax_code_line">
   <span class="heading"><?php echo gettext('Tax Codes') ?></span>
   <div id="form_serach_header" class="tabContainer">
    <label><?php echo gettext('Business Org') ?></label></label>
    <?php echo $f->select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $org_id_h, 'org_id', 'action'); ?>
    <a name="show" href="form.php?class_name=mdm_tax_code&<?php echo "mode=$mode"; ?>" class="show document_id mdm_tax_code_id action">
     <i class="fa fa-refresh"></i></a> 
   </div>
   <div id ="form_line" class="mdm_tax_code"><span class="heading">Tax Details </span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Tax Code') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Control') ?></a></li>
      <li><a href="#tabsLine-3"><?php echo gettext('Reporting') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Id') ?></th>
          <th><?php echo gettext('Code') ?>#</th>
          <th><?php echo gettext('Type') ?>#</th>
          <th><?php echo gettext('Description') ?></th>
          <th><?php echo gettext('In or Out') ?></th>
          <th><?php echo gettext('Dr or Cr') ?></th>
          <th><?php echo gettext('Region Calculation') ?></th>
          <th><?php echo gettext('Percentage') ?></th>
          <th><?php echo gettext('Amount') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody tax_code_values" >
         <?php
         $count = 0;
         $tax_code_object_ai = new ArrayIterator($tax_code_object);
         $tax_code_object_ai->seek($position);
         while ($tax_code_object_ai->valid()) {
          $mdm_tax_code = $tax_code_object_ai->current();
          ?>         
          <tr class="mdm_tax_code<?php echo $count ?>">
           <td><?php
            echo ino_inline_action($$class->mdm_tax_code_id, array('org_id' => $org_id_h));
            ?>    
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php form::number_field_drs('mdm_tax_code_id') ?></td>
           <td><?php form::text_field_widm('tax_code'); ?></td>
           <td><?php echo form::select_field_from_object('tax_type', mdm_tax_code::tax_type(), 'option_line_code', 'option_line_value', $$class->tax_type, '', $readonly); ?></td>
           <td><?php form::text_field_wid('description'); ?></td>
           <td><?php echo $f->select_field_from_array('in_out', mdm_tax_code::$in_out_a, $$class->in_out, 'in_out', '', '', $readonly, $readonly1) ?></td>
           <td><?php echo $f->select_field_from_array('dr_cr', mdm_tax_code::$dr_cr_a, $$class->dr_cr, 'dr_cr', '', '', $readonly, $readonly1) ?></td>
           <td><?php echo $f->select_field_from_array('calculation_method', mdm_tax_code::$calculation_method_a, $$class->calculation_method, 'calculation_method', '', '', $readonly, $readonly1) ?></td>
           <td><?php form::number_field_ds('percentage') ?></td>
           <td><?php form::number_field_ds('tax_amount') ?></td>
          </tr>
          <?php
          $tax_code_object_ai->next();
          if ($tax_code_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?>#</th>
          <th><?php echo gettext('Account') ?>#</th>
          <th><?php echo gettext('Ad hoc Rate') ?></th>
          <th><?php echo gettext('Exemption') ?></th>
          <th><?php echo gettext('Status') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody tax_code_values" >
         <?php
         $count = 0;
         $tax_code_object_ai = new ArrayIterator($tax_code_object);
         $tax_code_object_ai->seek($position);
         while ($tax_code_object_ai->valid()) {
          $mdm_tax_code = $tax_code_object_ai->current();
          ?>         
          <tr class="mdm_tax_code<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php
            echo $f->date_fieldAnyDay_m('effective_start_date', $$class->effective_start_date, '');
            ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class->effective_end_date); ?></td>
           <td><?php $f->ac_field_dm('tax_ac_id'); ?></td>
           <td><?php $f->checkBox_field_d('allow_adhoc_rate_cb'); ?></td>
           <td><?php $f->checkBox_field_d('allow_tax_exemptions_cb'); ?></td>
           <td><?php $f->status_field_d('status'); ?></td>
          </tr>
          <?php
          $tax_code_object_ai->next();
          if ($tax_code_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-3" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Regime') ?></th>
          <th><?php echo gettext('Jurisdiction') ?>#</th>
          <th><?php echo gettext('Printed Name') ?>#</th>
          <th><?php echo gettext('Offset Tax') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody tax_code_values" >
         <?php
         $count = 0;
         $tax_code_object_ai = new ArrayIterator($tax_code_object);
         $tax_code_object_ai->seek($position);
         while ($tax_code_object_ai->valid()) {
          $mdm_tax_code = $tax_code_object_ai->current();
          ?>         
          <tr class="mdm_tax_code<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php form::text_field_wid('tax_regime'); ?></td>
           <td><?php form::text_field_wid('tax_jurisdiction'); ?></td>
           <td><?php form::text_field_wid('printed_tax_name'); ?></td>
           <td><?php form::text_field_wid('offset_tax_code'); ?></td>
          </tr>
          <?php
          $tax_code_object_ai->next();
          if ($tax_code_object_ai->key() == $position + $per_page) {
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
   </div> 
  </form>
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
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="lineClassName" data-lineClassName="mdm_tax_code" ></li>
  <li class="line_key_field" data-line_key_field="tax_code" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="mdm_tax_code" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="mdm_tax_code_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="mdm_tax_code" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>