<div id ="form_header">
 <form  method="post" id="fp_kanban_release"  name="fp_kanban_release">
  <span class="heading"><?php echo gettext('Mass Kanban Release') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('fp_kanban_release_id') ?>
        <a name="show" href="form.php?class_name=fp_kanban_release&<?php echo "mode=$mode"; ?>" class="show document_id fp_kanban_release_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_dr('status', 'always_readonly'); ?></li>
       <li><?php $f->l_text_field_dr('no_of_cards', 'always_readonly'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Card Details') ?></span>
   <span class="label label-primary"><?php echo gettext('Enter Card Numbers /Scan Barcode /Read RFID Tags &nbsp; <br>&nbsp; Leave empty space between two cards') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Entered Cards') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Invalid Cards') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <div><?php echo $f->text_area_ap(array('name' => 'card_numbers', 'value' => $$class->card_numbers, 'row_size' => '10')); ?> </div> 
     </div> 

     <div id="tabsLine-2" class="tabContent">
      <div><?php echo $$class->invalid_card_numbers ; ?></div> 
    </div>
     </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_kanban_release" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_kanban_release_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_kanban_release" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_kanban_release_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_kanban_release_id" ></li>
 </ul>
</div>