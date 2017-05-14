<form method="post" id="locator"  name="locator"><span class="heading"><?php echo gettext('Storage Locator') ?></span>
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
       <li><?php $f->l_text_field_dr_withSearch('locator_id') ?>
        <a name="show" href="form.php?class_name=locator&<?php echo "mode=$mode"; ?>" class="show document_id locator_id">
         <i class="fa fa-refresh"></i></a> 
       </li> 
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly); ?>    </li>
       <li><?php $f->l_select_field_from_object('subinventory_id', subinventory::find_all(), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'subinventory_id', '', '', $readonly); ?>    </li>
       <li><label><?php echo gettext('Locator Structure') ?></label><?php echo locator::locator_structure(); ?></li>
       <li><?php $f->l_text_field_d('locator'); ?></li>
       <li><?php $f->l_text_field_d('alias'); ?></li>
       <li><?php $f->l_status_field_d('status'); ?></li>
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
        $reference_table = 'locator';
        $reference_id = $$class->locator_id;
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

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Locator Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Dimensions') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Capacity') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div> 
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_select_field_from_object('dimension_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->dimension_uom_id, 'dimension_uom_id');        ?></li>
       <li><?php $f->l_number_field('height', $$class->height); ?></li> 
       <li><?php $f->l_number_field('length', $$class->length); ?></li> 
       <li><?php $f->l_number_field('width', $$class->width); ?></li> 
       <li><?php $f->l_number_field('x_coordinate', $$class->x_coordinate); ?></li> 
       <li><?php $f->l_number_field('y_coordinate', $$class->y_coordinate); ?></li> 
       <li><?php $f->l_number_field('z_coordinate', $$class->z_coordinate); ?></li> 
      </ul> 
     </div> 
     <!--end of tab1 div three_column-->
    </div> 
    <!--              end of tab1-->

    <div id="tabsLine-2" class="tabContent">
     <div> 
      <ul class="column header_field two_column_form"> 
       <li><?php echo $f->l_number_field('max_units', $$class->max_units, '', 'max_units', 'medium'); ?></li> 
       <li><?php echo $f->l_select_field_from_object('max_volume_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->max_volume_uom_id, 'max_volume_uom_id'); ?></li>
       <li><?php echo $f->l_number_field('max_volume', $$class->max_volume, '', 'max_volume', 'medium'); ?></li> 
       <li><?php echo $f->l_select_field_from_object('max_weight_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->max_weight_uom_id, 'max_weight_uom_id'); ?></li>
       <li><?php echo $f->l_number_field('max_weight', $$class->max_weight, '', 'max_weight', 'medium'); ?></li> 
      </ul> 
     </div> 
    </div>
   </div>
  </div> 
 </div> 
</form>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="locator" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="locator_id" ></li>
  <li class="form_header_id" data-form_header_id="locator" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="locator_id" ></li>
  <li class="btn1DivId" data-btn1DivId="locator" ></li>
 </ul>
</div>