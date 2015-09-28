<span class="heading"><?php echo gettext('Legal Org Header') ?></span>
<div id ="form_header">
 <form action=""  method="post" id="legal"  name="legal">
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
       <li><?php echo $f->l_text_field_dr_withSearch('legal_id'); ?>
        <a name="show" href="form.php?class_name=legal&<?php echo "mode=$mode"; ?>" class="show document_id legal_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_legal(), 'org_id', 'org', $legal->org_id, 'org', '', '', $readonly); ?>					</li>
       <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
       <li><?php $f->l_text_field_d('rev_number'); ?>    </li>
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
         $reference_table = 'legal';
         $reference_id = $$class->legal_id;
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
  <div id ="form_line" class="form_line">
   <span class="heading"><?php echo gettext('Legal Org Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Ledger Details') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_d('legal_org_type'); ?></li>
        <li><?php $f->l_text_field_d('registration_number'); ?></li>
        <li><?php $f->l_text_field_d('place_of_registration'); ?></li>
        <li><?php $f->l_text_field_d('country_of_registration'); ?></li>
        <li><?php $f->l_text_field_d('identification_number'); ?></li>
        <li><?php $f->l_text_field_d('ein_tin_tan'); ?></li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2" class="tabContent">
      <ul class="column header_field" > 
        <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '' , '' , $readonly) ?>        </li> 
        <li><label><?php echo gettext('Balancing Segments') ?></label> 
         <?php echo form::text_field('balancing_segments', $$class->balancing_segments, 90, '', '', '', '', 1); ?>
        </li> 
       </ul>
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab2-->	 
    </div>


   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="legal" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="legal_id" ></li>
  <li class="form_header_id" data-form_header_id="legal" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="legal_id" ></li>
  <li class="btn1DivId" data-btn1DivId="legal" ></li>
 </ul>
</div>