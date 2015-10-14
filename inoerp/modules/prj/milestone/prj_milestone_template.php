<form method="post" id="prj_milestone"  name="prj_milestone">
 <div id="tabsHeader"><span class="heading"><?php echo gettext('Project Milestone') ?></span>
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Project Info') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><?php
      echo $f->l_val_field_dm('project_number', 'prj_project_header', 'project_number', '', 'project_number', 'vf_select_project_number action');
      echo $f->hidden_field_withIdClass('prj_project_header_id', $prj_project_header_id_h, 'action');
      ?><i class="generic g_select_project_number select_popup getform clickable fa fa-search" data-class_name="prj_project_header"></i>
      <a name="show" href="form.php?class_name=prj_milestone&<?php echo "mode=$mode"; ?>" class="show document_id prj_project_header_id">
       <i class="fa fa-refresh"></i></a> 
     </li>
     <li><?php $f->l_text_field_dr('project_description'); ?> </li>
    </ul>
   </div>
  </div>

 </div>
 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Milestone Status') ?></span>

  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Task') ?></th>
        <th><?php echo gettext('Task Id') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Revenue Amount') ?></th>
        <th><?php echo gettext('Invoice Amount') ?></th>
        <th><?php echo gettext('Sign-Off') ?></th>
        <th><?php echo gettext('Comment') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
//       pa($prj_milestone_object);
       foreach ($prj_milestone_object as $prj_milestone) {
        if ($prj_milestone->status == 'BILLED') {
         $billed_readoly = true;
         $status_a = prj_milestone::$status_a;
        } else {
         $billed_readoly = false;
         $status_a = [ 'ENTERED' => 'Entered',    'APPROVED' => 'Approved'];
        }

        
        ?>         
        <tr class="prj_milestone<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_milestone->prj_milestone_id, array('prj_project_header_id' => $prj_project_header_id_h));
          ?>
         </td>
         <td><?php $f->text_field_widsr('prj_milestone_id', 'always_readonly line_id'); ?></td>
         <td><?php $f->text_field_widr('task_number', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widsr('prj_project_line_id', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widr('task_description', 'always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_array('status', $status_a, $$class->status, '', 'medium', '', $billed_readoly, $billed_readoly); ?></td>
         <td><?php $f->text_field_wid('revenue_amount'); ?></td>
         <td><?php $f->text_field_wid('invoice_amount'); ?></td>
         <td><?php echo $f->checkBox_field('signoff_cb', $$class->signoff_cb, '', '', $billed_readoly); ?></td>
         <td><?php $f->text_field_wid('comment'); ?></td>

         <td></td>

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


 </div>
</form>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_milestone" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_milestone_id" ></li>
  <li class="lineClassName" data-lineClassName="prj_milestone" ></li>
  <li class="line_key_field" data-line_key_field="prj_project_line_id" ></li>
  <li class="no_headerid_check" data-no_headerid_check="9" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_milestone" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="prj_milestone_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="prj_milestone" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>