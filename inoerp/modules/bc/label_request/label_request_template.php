<div id ="form_header">
 <form action=""  method="post" id="bc_label_request"  name="bc_label_request"><span class="heading">Label Request </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bc_label_request_id select_popup clickable">
          Request Id</label><?php $f->text_field_dsr('bc_label_request_id') ?>
         <a name="show" href="form.php?class_name=bc_label_request&<?php echo "mode=$mode"; ?>" class="show document_id bc_label_request_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Printer Name</label><?php echo $f->select_field_from_object('sys_printer_id', sys_printer::find_all(), 'sys_printer_id', 'printer_name', $$class->sys_printer_id, 'sys_printer_id', '', '', 1); ?> 					</li>
        <li><label>Transaction Type</label><?php echo $f->select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', '', '', 1); ?>        </li>
        <li><label>Label Format</label><?php echo $f->select_field_from_object('bc_label_format_header_id', bc_label_format_header::find_all(), 'bc_label_format_header_id', 'format_name', $$class->bc_label_format_header_id, 'bc_label_format_header_id', '', '', 1); ?>              </li>
        <li><label>Status</label><?php $f->text_field_d('status'); ?> 					</li>
        <li><label>No Of Copies</label><?php echo $f->text_field_ap(array('name' => 'no_of_copies', 'value' => '', 'id' => 'no_of_copies')); ?> 					</li>
        <li><button class="button" id="print_label">Reprint</button></li>
       </ul>
      </div>
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
  <div id ="form_line" class="form_line"><span class="heading">Content </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Label Content</a></li>
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