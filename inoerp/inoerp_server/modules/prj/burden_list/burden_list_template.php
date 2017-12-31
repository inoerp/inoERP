<div class="row small-left-padding">
 <div id="form_all">
  <form method="post" id="prj_burden_list_header"  name="prj_burden_list_header">
   <span class="heading"><?php echo gettext('Burden List') ?></span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('prj_burden_list_header_id'); ?>
         <a name="show" href="form.php?class_name=prj_burden_list_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_burden_list_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_dm('burden_list'); ?> </li>
        <li><?php $f->l_select_field_from_object('prj_burden_structure_header_id', prj_burden_structure_header::find_all(), 'prj_burden_structure_header_id', 'structure', $$class->prj_burden_structure_header_id, 'prj_burden_structure_header_id', '', 1, $readonly); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li>
        <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
       </ul>
      </div>
      <div id="tabsHeader-2" class="tabContent">
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <div> 
        <div id="comments">
         <div id="comment_list">
          <?php echo!(empty($comments)) ? $comments : ""; ?>
         </div>
         <div id ="display_comment_form">
          <?php
          $reference_table = 'prj_burden_list_header';
          $reference_id = $$class->prj_burden_list_header_id;
          ?>
         </div>
         <div id="new_comment">
         </div>
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </form>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Burden List Lines') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Values') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <form action=""  method="post" id="prj_burden_list_line_line"  name="prj_burden_list_line_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Cost Code') ?></th>
          <th><?php echo gettext('BU') ?></th>
          <th><?php echo gettext('Multiplier') ?></th>
          <th><?php echo gettext('Value') ?></th>
          <th><?php echo gettext('Formula') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody prj_burden_list_line_values" >
         <?php 
         $count = 0;
         $prj_burden_list_line_object_ai = new ArrayIterator($prj_burden_list_line_object);
         $prj_burden_list_line_object_ai->seek($position);
         while ($prj_burden_list_line_object_ai->valid()) {
          $prj_burden_list_line = $prj_burden_list_line_object_ai->current();
          ?>         
          <tr class="prj_burden_list_line<?php echo $count ?>">
           <td><?php
            echo ino_inline_action($$class_second->prj_burden_list_line_id, array('prj_burden_list_header_id' => $$class->prj_burden_list_header_id));
            ?>    
           </td>
           <td><?php form::number_field_wid2sr('prj_burden_list_line_id'); ?></td>
           <td><?php echo $f->select_field_from_object('prj_burden_costcode_id', prj_burden_costcode::find_all(), 'prj_burden_costcode_id', 'costcode', $$class_second->prj_burden_costcode_id, '', 'medium', 1, $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class_second->bu_org_id, '', 'bu_org_id copyValue medium', 1, $readonly); ?></td>
           <td><?php echo $f->number_field('multiplier', $$class_second->multiplier); ?></td>
           <td><?php echo $f->number_field('burden_value', $$class_second->burden_value); ?></td>
           <td><?php echo $f->text_field('formula', $$class_second->formula); ?></td>
           <td><?php echo $f->date_fieldAnyDay_m('effective_start_date', $$class_second->effective_start_date, $readonly); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
          </tr>
          <?php
          $prj_burden_list_line_object_ai->next();
          if ($prj_burden_list_line_object_ai->key() == $position + $per_page) {
           break;
          }
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
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_burden_list_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_burden_list_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_burden_list_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_burden_list_header" ></li>
  <li class="line_key_field" data-line_key_field="prj_burden_costcode_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_burden_list_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_burden_list_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_burden_list_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_burden_list_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="prj_burden_list_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
