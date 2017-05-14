<div id ="form_header">
 <span class="heading"><?php echo gettext('Enterprise Header') ?></span>
 <form action=""  method="post" id="enterprise"  name="enterprise">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr_withSearch('enterprise_id'); ?>
       <a name="show" href="form.php?class_name=enterprise&<?php echo "mode=$mode"; ?>" class="show document_id enterprise_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_enterprise(), 'org_id', 'org', $enterprise->org_id, 'org', '', '', $readonly1); ?> </li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
      <li><?php $f->l_text_field_d('rev_number'); ?></li>
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
        $reference_table = 'enterprise';
        $reference_id = $$class->enterprise_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>


  <span class="heading"><?php echo gettext('Other Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Enterprise') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('designation_option_header_id'); ?>       </li>
       <li><?php $f->l_text_field_d('type_option_header_id'); ?>       </li>
      </ul>
     </div>
     <div id="tabsLine-2" class="tabContent">
     </div>
    </div>

   </div>
  </div>

 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="enterprise" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="enterprise_id" ></li>
  <li class="form_header_id" data-form_header_id="enterprise" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="enterprise_id" ></li>
  <li class="btn1DivId" data-btn1DivId="enterprise" ></li>
 </ul>
</div>