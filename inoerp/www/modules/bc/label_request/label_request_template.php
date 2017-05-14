<div id ="form_header">
 <form  method="post" id="bc_label_request"  name="bc_label_request">
  <span class="heading"><?php echo gettext('Label Request') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('bc_label_request_id') ?>
         <a name="show" href="form.php?class_name=bc_label_request&<?php echo "mode=$mode"; ?>" class="show document_id bc_label_request_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('sys_printer_id', sys_printer::find_all(), 'sys_printer_id', 'printer_name', $$class->sys_printer_id, 'sys_printer_id', '', '', 1); ?> 					</li>
        <li><?php $f->l_select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', '', '', 1); ?>        </li>
        <li><?php $f->l_select_field_from_object('bc_label_format_header_id', bc_label_format_header::find_all(), 'bc_label_format_header_id', 'format_name', $$class->bc_label_format_header_id, 'bc_label_format_header_id', '', '', 1); ?>              </li>
        <li><?php $f->l_text_field_d('status'); ?> 					</li>
        <li><label><?php echo gettext('No Of Copies') ?></label><?php echo $f->text_field_ap(array('name' => 'no_of_copies', 'value' => '', 'id' => 'no_of_copies')); ?> 					</li>
        <li><label><?php echo gettext('Label') ?></label><button class="button btn btn-warning" id="print_label"><?php echo gettext('Reprint') ?></button></li>
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
         $reference_table = 'bc_label_request';
         $reference_id = $$class->bc_label_request_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Content') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Label Content') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <?php echo $f->text_area_ap(array('name' => 'label_content', 'value' => $$class->label_content, 'row_size' => 10, 'column_size' => 100)) ?>
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
    </div>

   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bc_label_request" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bc_label_request_id" ></li>
  <li class="form_header_id" data-form_header_id="bc_label_request" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bc_label_request_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bc_label_request_id" ></li>
 </ul>
</div>