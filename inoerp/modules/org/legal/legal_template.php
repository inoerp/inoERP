<span class="heading">Legal Org Header </span>
<div id ="form_header">
 <form action=""  method="post" id="legal"  name="legal">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><label><img class="legal select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
          Legal Org Id</label><?php echo $f->text_field_dsr('legal_id'); ?>
         <a name="show" href="form.php?class_name=legal&<?php echo "mode=$mode"; ?>" class="show document_id legal_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_legal(), 'org_id', 'org', $legal->org_id, 'org', $readonly); ?>					</li>
        <li><label>Status</label><?php echo form::status_field($legal->status, $readonly); ?></li>
        <li><label>Revision</label><?php echo form::revision_enabled_field($legal->rev_enabled, $readonly); ?></li>
        <li><label>Revision No</label><?php echo form::text_field('rev_number', $legal->rev_number, '10', '', '', '', '', $readonly); ?></li>
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
  <div id ="form_line" class="form_line"><span class="heading">Legal Org Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Basic Info</a></li>
     <li><a href="#tabsLine-2">Ledger Details</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column four_column"> 
        <li><label>Type of Legal Org : </label>
         <?php form::text_field_d('legal_org_type'); ?>
        </li> 
        <li><label>Registration Number : </label> 
         <?php form::text_field_d('registration_number'); ?>
        </li>
        <li><label>Place of Registration : </label> 
         <?php form::text_field_d('place_of_registration'); ?>
        </li> 
        <li><label>Country of Registration : </label> 
         <?php form::text_field_d('country_of_registration'); ?>
        </li>
        <li><label>Identification No : </label> 
         <?php form::text_field_d('identification_number'); ?>
        </li>
        <li><label>EIN/TIN/TAN : </label>
         <?php form::text_field_d('ein_tin_tan'); ?>
        </li> 
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2">
      <div class="column four_column" class="tabContent"> 
       <ul>
        <li> 
         <label>Ledger Id : </label> 
         <?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, '', $readonly) ?>
        </li> 
        <li><label>Balancing Segments : </label> 
         <?php echo form::text_field('balancing_segments', $$class->balancing_segments, 90, '', '', '', '', 1); ?>
        </li> 
       </ul>
      </div> 
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
  <li class="docHedadeId" data-docHedadeId="legal_id" ></li>
  <li class="btn1DivId" data-btn1DivId="legal_id" ></li>
 </ul>
</div>