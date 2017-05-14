<div id ="form_header">
 <form  method="post" id="sys_printer"  name="sys_printer">
  <span class="heading"><?php echo gettext('Printer') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_dr_withSearch('sys_printer_id') ?>
        <a name="show" href="form.php?class_name=sys_printer&<?php echo "mode=$mode"; ?>" class="show document_id sys_printer_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('printer_name'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('printer_type', sys_printer::printer_type(), 'option_line_code', 'option_line_value', $$class->printer_type, 'printer_type'); ?> </li>
       <li><?php $f->l_text_field_d('manufacturer'); ?> 					</li>
       <li><?php $f->l_text_field_dm('ip_address'); ?> 					</li>
       <li><?php $f->l_text_field_dm('port_number'); ?> 					</li>
       <li><?php $f->l_text_field_d('description'); ?> 					</li>
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
         $reference_table = 'sys_printer';
         $reference_id = $$class->sys_printer_id;
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
  <li class="headerClassName" data-headerClassName="sys_printer" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_printer_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_printer" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_printer_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_printer_id" ></li>
 </ul>
</div>