<div id ="form_all"><span class="heading"><?php echo gettext('Unit Of Measure') ?></span>
 <form method="post" id="uom"  name="uom">
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
       <li><?php $f->l_text_field_dr_withSearch('uom_id') ?>
        <a name="show" href="form.php?class_name=uom&<?php echo "mode=$mode"; ?>" class="show document_id uom_id"><i class='fa fa-refresh'></i></a> 
       </li> 
       <li><?php $f->l_text_field_d('uom_name'); ?></li>
       <li><?php $f->l_select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', '', '', $readonly); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_checkBox_field_d('primary_cb'); ?></li>
       <li><?php $f->l_status_field_d('status'); ?></li>
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
       <table class="form form_detail_data_table detail">
        <thead>
         <tr>
          <th><?php echo gettext('UOM') ?></th>
          <th><?php echo gettext('Equals') ?></th>
          <th><?php echo gettext('Primary UOM Id') ?></th>
          <th><?php echo gettext('Primary UOM') ?></th>
          <th><?php echo gettext('Operator') ?></th>
          <th><?php echo gettext('Relation Value') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_detail_tbody">
         <tr class="uom_line_tr">
          <td><?php echo $$class->uom_name; ?> </td>
          <td class="large-text small-left-padding">&#61;</td>
          <td><?php $f->text_field_d('primary_uom_id'); ?><i class="primary_uom_id select_popup clickable fa fa-search"></i></td>
          <td><?php $f->text_field_d('primary_uom'); ?></td>
          <td class="large-text small-left-padding">&#120;</td>
          <td><?php $f->text_field_d('primary_relation'); ?></td>
         </tr>
        </tbody>
       </table>
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