<div id ="form_all"><span class="heading"><?php echo gettext('Unit Of Measure') ?></span>
 <form action=""  method="post" id="uom"  name="uom">
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
        <li><?php $f->l_text_field_dr_withSearch('uom_id') ?>
         <a name="show" href="form.php?class_name=uom&<?php echo "mode=$mode"; ?>" class="show document_id uom_id"><i class='fa fa-refresh'></i></a> 
        </li> 
        <li><?php $f->l_text_field_d('uom_name'); ?></li>
        <li><?php $f->l_select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', '','' ,$readonly); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_checkBox_field_d('primary_cb'); ?></li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li>
        <li><?php $f->l_text_field_d('rev_number'); ?></li>
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
         $reference_table = 'uom';
         $reference_id = $$class->uom_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('UOM Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Relationship') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column four_column" > 
        <li><?php $f->l_text_field_dr('primary_uom_id'); ?></li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="primary_uom_id select_popup clickable">
          <?php echo gettext('Primary UOM') ?></label><?php $f->text_field_d('primary_uom'); ?></li>
        <li><label> Operator</label>
         <input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
        </li> 
        <li><?php $f->l_text_field_d('primary_relation'); ?></li> 
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab5-->
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="uom" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="uom_id" ></li>
  <li class="form_header_id" data-form_header_id="uom" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="uom_id" ></li>
  <li class="btn1DivId" data-btn1DivId="uom" ></li>
 </ul>
</div>