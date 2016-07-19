
<div class="row small-left-padding">
 <div id="form_all">
  <span class="heading"><?php echo gettext('Approval Limit Assignment') ?></span>
  <div id="form_serach_header" class="tabContainer"><ul class="inline_list">
    <li><?php $f->l_select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $position_id_h, 'position_id', $readonly1); ?>   </li>
    <li><?php $f->l_select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $job_id_h, 'job_id', $readonly1); ?>   </li>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $bu_org_id_h, 'bu_org_id', $readonly1); ?>   </li>
    <li><a name="show" href="form.php?class_name=hr_approval_limit_assignment&<?php echo "mode=$mode"; ?>" 
           class="show2 document_id hr_approval_limit_assignment_id"><i class="fa fa-refresh"></i></a> </li>
   </ul>
  </div>
  <div id="form_headerDiv">
   <form action=""  method="post" id="hr_approval_limit_assignment_line"  name="approval_limit_assignment_line">
    <div id="tabsLine">
     <div id ="form_line" class="hr_approval_limit_assignment">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Seq') ?>#</th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Document Type') ?></th>
           <th><?php echo gettext('Approval Limit') ?></th>
           <th><?php echo gettext('Start Date') ?></th>
           <th><?php echo gettext('End Date') ?></th>
           <th><?php echo gettext('Job') ?></th>
           <th><?php echo gettext('Position') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody approval_limit_assignment_values" >
          <?php
          $count = 0;
          $approval_limit_assignment_object_ai = new ArrayIterator($approval_limit_assignment_object);
          $approval_limit_assignment_object_ai->seek($position);
          while ($approval_limit_assignment_object_ai->valid()) {
           $hr_approval_limit_assignment = $approval_limit_assignment_object_ai->current();
           $position_id_crnt = $job_id_crnt = null;
           if (!empty($hr_approval_limit_assignment->position_id)) {
            $position_id_crnt = $hr_approval_limit_assignment->position_id;
           } else if (empty($hr_approval_limit_assignment->position_id) && !empty($position_id_h)) {
            $position_id_crnt = $position_id_h;
           }

           if (!empty($hr_approval_limit_assignment->job_id) && empty($hr_approval_limit_assignment->position_id)) {
            $job_id_crnt = $hr_approval_limit_assignment->job_id;
           } else if (empty($hr_approval_limit_assignment->job_id) && !empty($job_id_h)) {
            $job_id_crnt = $job_id_h;
           }
           ?>         
           <tr class="hr_approval_limit_assignment<?php echo $count ?>">
            <td><?php
             echo ino_inline_action($$class->hr_approval_limit_assignment_id, array('bu_org_id' => $bu_org_id_h));
             ?>    
            </td>
            <td><?php  $f->seq_field_d($count)  ?></td>
            <td><?php $f->text_field_widsr('hr_approval_limit_assignment_id') ?></td>
            <td><?php echo $f->select_field_from_object('document_type', option_header::document_types(), 'option_line_code', 'option_line_value', $$class->document_type, '', '', 1, $readonly); ?></td>
            <td><?php echo $f->select_field_from_object('hr_approval_limit_header_id', hr_approval_limit_header::find_all(), 'hr_approval_limit_header_id', 'limit_name', $$class->hr_approval_limit_header_id, '', '', 1, $readonly); ?></td>
            <td><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></td>
            <td><?php echo $f->date_fieldAnyDay('end_date', $$class->end_date); ?></td>
            <td><?php echo $f->select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $job_id_crnt, 'job_id', '', '', 1); ?>   </td>
            <td><?php echo $f->select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $position_id_crnt, 'position_id', '', '', 1); ?></td>

           </tr>
           <?php
           $approval_limit_assignment_object_ai->next();
           if ($approval_limit_assignment_object_ai->key() == $position + $per_page) {
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
           <th><?php echo gettext('BU Org Id') ?></th>
           <th><?php echo gettext('Job Id') ?></th>
           <th><?php echo gettext('Position Id') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody approval_limit_assignment_values" >
          <?php
          $count = 0;
//         $approval_limit_assignment_object_ai = new ArrayIterator($approval_limit_assignment_object);
          $approval_limit_assignment_object_ai->seek($position);
          while ($approval_limit_assignment_object_ai->valid()) {
           $hr_approval_limit_assignment = $approval_limit_assignment_object_ai->current();
           ?>         
           <tr class="hr_approval_limit_assignment<?php echo $count ?>">
            <td><?php $f->seq_field_d($count) ?></td>
            <td><?php echo $$class->bu_org_id; ?></td>
            <td><?php echo $$class->job_id; ?></td>
            <td><?php echo $$class->position_id; ?></td>
           </tr>
           <?php
           $approval_limit_assignment_object_ai->next();
           if ($approval_limit_assignment_object_ai->key() == $position + $per_page) {
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
  <li class="primary_column_id" data-primary_column_id="bu_org_id" ></li>
  <li class="lineClassName" data-lineClassName="hr_approval_limit_assignment" ></li>
  <li class="line_key_field" data-line_key_field="hr_approval_limit_header_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_approval_limit_assignment" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_approval_limit_assignment_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_approval_limit_assignment" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>