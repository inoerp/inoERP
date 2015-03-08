<div id ="pos_terminal_divId">
 <form action=""  method="post" id="pos_terminal"  name="pos_terminal">
  <span class="heading"><?php echo gettext('POS Terminal') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php echo $f->l_text_field_dr_withSearch('pos_terminal_id'); ?>
         <a name="show" href="form.php?class_name=pos_terminal&<?php echo "mode=$mode"; ?>" class="show document_id pos_terminal_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('sd_store_id', sd_store::find_all(), 'sd_store_id', 'store_name', $$class->sd_store_id, 'sd_store_id', '', 1, $readonly); ?>    </li>
        <li><?php $f->l_text_field_dm('terminal_name'); ?></li>
        <li><?php $f->l_select_field_from_object('location_id', address::find_all(), 'address_id', 'address_name', $$class->location_id, 'location_id'); ?>    </li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_status_field_d('status'); ?>    </li>
       </ul>
      </div>
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
         $reference_table = 'pos_terminal';
         $reference_id = $$class->pos_terminal_id;
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
  <li class="headerClassName" data-headerClassName="pos_terminal" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="pos_terminal_id" ></li>
  <li class="form_header_id" data-form_header_id="pos_terminal" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pos_terminal_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pos_terminal" ></li>
 </ul>
</div>