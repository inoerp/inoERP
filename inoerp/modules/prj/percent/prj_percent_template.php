<div id ="form_header"><span class="heading"><?php echo gettext('Project Completion Status') ?></span>
 <form method="post" id="prj_percent_header"  name="prj_percent_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Revisions') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php
       echo $f->l_val_field_dm('project_number', 'prj_project_header', 'project_number', '', 'project_number', 'vf_select_project_number action');
       echo $f->hidden_field_withIdClass('prj_percent_header_id', $$class->prj_percent_header_id, 'action');
       echo $f->hidden_field_withIdClass('prj_project_header_id', $$class->prj_project_header_id, 'action');
       ?><i class="generic g_select_project_number select_popup getform clickable fa fa-search" data-class_name="prj_percent_all_v"></i>
       <a name="show" href="form.php?class_name=prj_percent_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_percent_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('project_description'); ?> </li>
      <li><?php
       $f->l_date_fieldAnyDay('as_of_date', $$class->as_of_date);
       echo $f->hidden_field_withId('as_of_date_old', $$class->as_of_date);
       ?> </li>
      <li><?php
       $f->l_text_field_d('percent');
       echo $f->hidden_field_withId('percent_old', $$class->percent);
       ?> </li>
      <li><?php $f->l_text_field_d('description'); ?> </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      
      <table class="table  table-bordered form_line_data_table text-center">
       <thead> 
        <tr>
         <th class='col-md-2 text-center'><?php echo gettext('Revision Id') ?></th>
         <th class='col-md-2 text-center'><?php echo gettext('Percent Header Id') ?></th>
         <th class='col-md-2 text-center'><?php echo gettext('Project Header Id') ?></th>
         <th class='col-md-1 text-center'><?php echo gettext('Percent') ?></th>
         <th class='col-md-2 text-center'><?php echo gettext('Description') ?></th>
         <th class='col-md-1 text-center'><?php echo gettext('Date') ?></th>
         <th class='col-md-1 text-center'><?php echo gettext('Status') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
//       pa($prj_percent_line_v_object);
        foreach ($revision_obj as $revision_i) {
         ?>         
         <tr class="prj_percent_line<?php echo $count ?>">
          <td><?php echo $revision_i->prj_percent_headerrev_id ?></td>
          <td><?php echo $revision_i->prj_percent_header_id ?></td>
          <td><?php echo $revision_i->prj_project_header_id ?></td>
          <td><?php echo $revision_i->percent ?></td>
          <td><?php echo $revision_i->description ?></td>
          <td><?php echo $revision_i->as_of_date ?></td>
          <td><?php echo $revision_i->status ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'prj_percent_header';
       $reference_id = $$class->prj_percent_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Task Completion Status') ?></span>
 <form method="post" id="prj_percent_line"  name="prj_percent_line">
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
        <th><?php echo gettext('Task Id') ?></th>
        <th><?php echo gettext('Task') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Date') ?></th>
        <th><?php echo gettext('Completion') ?> %</th>
        <th><?php echo gettext('Comment') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
//       pa($prj_percent_line_v_object);
       foreach ($prj_percent_line_v_object as $prj_percent_line_v) {
        ?>         
        <tr class="prj_percent_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->prj_percent_line_id, array('prj_percent_header_id' => $$class->prj_percent_header_id,
           'prj_project_header_id' => $$class->prj_project_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('prj_percent_line_id', 'always_readonly line_id'); ?></td>
         <td><?php $f->text_field_wid2sr('prj_project_line_id', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2r('task_number', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2r('task_description', 'always_readonly'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('as_of_date', $$class_second->as_of_date); ?></td>
         <td><?php $f->text_field_wid2('percent'); ?></td>
         <td><?php $f->text_field_wid2l('comment'); ?></td>

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
 </form>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_percent_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_percent_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_percent_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_percent_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_percent_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_percent_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_percent_line_id" ></li>
  <li class="docDetailId" data-docDetailId="prj_percent_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_percent_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>