<div id ="form_all"><span class="heading"><?php 

echo gettext('Burden Expenditure') ?></span>
 <form  method="post" id="prj_burden_expenditure"  name="prj_burden_expenditure">
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
       <li><?php $f->l_text_field_dr_withSearch('prj_burden_expenditure_id') ?>
        <a name="show" href="form.php?class_name=prj_burden_expenditure&<?php echo "mode=$mode"; ?>" class="show document_id prj_burden_expenditure_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_dr('prj_expenditure_line_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_burden_cost_base_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_expenditure_type_header_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_burden_list_header_id'); ?></li>
       <li><?php $f->l_text_field_dr('expenditure_date'); ?></li>
       <li><?php $f->l_text_field_dr('prj_project_header_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_project_line_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_burden_structure_header_id'); ?></li>
       <li><?php $f->l_text_field_dr('prj_burden_costcode_id'); ?></li>
       <li><?php $f->l_text_field_dr('multiplier'); ?></li>
       <li><?php $f->l_text_field_dr('burden_value'); ?></li>
       <li><?php $f->l_text_field_dr('burden_amount'); ?></li>
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
         $reference_table = 'prj_burden_expenditure';
         $reference_id = $$class->prj_burden_expenditure_id;
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
</div>


<div id="js_data">
  <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_burden_expenditure" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_burden_expenditure_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_burden_expenditure"></li>
 </ul>
</div>