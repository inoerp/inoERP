<div id ="form_header">
 <form action=""  method="post" id="sys_program"  name="sys_program">
  <div class="tabContainer"> 
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('sys_program_id') ?>
     <a name="show" href="form.php?class_name=sys_program&<?php echo "mode=$mode"; ?>" class="show document_id sys_program_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
    <li><label>Program : </label> <?php $f->text_field_dm('program_name'); ?> </li> 
    <li><label>Status : </label> <?php $f->text_field_d('status'); ?> </li> 
    <li><label>Module : </label> <?php $f->text_field_d('module_name'); ?> </li> 
    <li><label>Class : </label> <?php $f->text_field_d('class'); ?> </li> 
    <li><?php $f->l_text_field_dr('program_source'); ?> </li>
    <li><label>Description : </label> <?php $f->text_field_d('description'); ?> </li> 
   </ul> 
  </div>
 </form>
</div>

<!--END OF FORM HEADER-->
<div id ="form_line" class="form_line">
 <span class="heading">Output </span><?php
 if (!empty($$class->output_path)) {
  $home_url_wos = rtrim(HOME_URL, '/');
  echo "<a href='" . $home_url_wos . $$class->output_path . "' target='new'> View </a> ";
 }
 ?>
 <span class="heading">Parameters </span>
 <?php
 echo '<pre>';
 print_r(unserialize($$class->parameters));
 echo '</pre>';
 ?>
 <span class="heading">Message Details </span><?php echo $$class->message; ?>
</div>     

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_program" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_program_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_program" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_program_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_program_id" ></li>
 </ul>
</div>