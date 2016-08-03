<div id ="form_header"><span class="heading">Indented BOM </span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1">Basic Info</a></li>
   <li><a href="#tabsHeader-2">Details</a></li>
   <li><a href="#tabsHeader-3">Common BOM</a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><label>Org Name</label>
      <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', 1); ?>
     </li>
     <li><?php echo $f->l_val_field_d('bom_header_id', 'bom_header', 'bom_header_id', 'org_id') ?>
      <i class="generic g_select_bom_header_id select_popup clickable fa fa-search" data-class_name="bom_header"></i>
      <a name="show" href="form.php?class_name=bom_indented_bom&<?php echo "mode=$mode"; ?>" class="show document_id bom_header_id">
       <i class='fa fa-refresh'></i></a> 
     </li>
     <li><label>Item Id</label>
      <?php form::text_field_drm('item_id_m'); ?>
     </li>
     <li><label>Item Number</label>
      <?php form::text_field_dm('item_number'); ?>
     </li>
     <li><label>Description</label>
      <?php form::text_field_widr('item_description'); ?>
     </li>
     <li><label>UOM</label>
      <?php echo form::select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom'); ?>
     </li>
    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div> 
     <ul class="column header_field">
      <li><label>Alternate Bom</label>
       <?php echo form::text_field_d('alternate_bom'); ?>
      </li>
      <li><label>Revision</label>
       <?php form::text_field_dm('bom_revision'); ?>
      </li>
      <li><label>Effective Date</label>
       <?php echo form::date_fieldAnyDay_m('effective_date', $$class->effective_date); ?>
      </li>
     </ul>
    </div>
   </div>
   <div id="tabsHeader-3" class="tabContent">
    <div> 
     <ul class="column header_field">
      <li><label>Common BOM Item Id</label>
       <?php form::text_field_widsr('item_id_m'); ?>
      </li>
      <li><label>Item Number</label>
       <?php form::text_field_wid('commonBom_item_number'); ?>
      </li>
      <li><label>Description</label>
       <?php form::text_field_wid('commonBom_item_description'); ?>
      </li>
     </ul>
    </div>
   </div>
  </div>

 </div>
</div>

<div id="form_line" class="form_line"><span class="heading">BOM Lines </span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1">Main</a></li>
   <li><a href="#tabsLine-2">Effectivity</a></li>
   <li><a href="#tabsLine-3">Control</a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsLine-1" class="tabContent">
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th>Row#</th>
       <th>Level</th>
       <th>BOM Line Id</th>
       <th>BOM Sequence</th>
       <th>Op. Sequence</th>
       <th>Item Id</th>
       <th>Item Number</th>
       <th>Item Description</th>
       <th>UOM</th>
       <th>Usage Basis</th>
       <th>Quantity</th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      global $rowCount;
      $rowCount = 0;
      foreach ($bom_line_object as &$indented_bom_lines0) {
       if (!empty($indented_bom_lines0->component_item_id_m)) {
        $item = item::find_by_id($indented_bom_lines0->component_item_id_m);
        $indented_bom_lines0->component_item_number = $item->item_number;
        $indented_bom_lines0->component_description = $item->item_description;
        $indented_bom_lines0->component_uom = $item->uom_id;
       }
       $level = 0;
       ?>         
       <tr class="bom_line<?php echo $rowCount ?>">
        <td> <?php echo $rowCount; ?> </td>
        <td class="<?php echo 'L' . $level; ?>"> <?php echo $f->text_field('level', $level); ?> </td>
        <?php
        $indented_bom_statment = indentedBom_tab1($indented_bom_lines0);
        echo $indented_bom_statment;
        ?>
       </tr>
       <?php
       show_indentedBom($indented_bom_lines0, 'tab1', 1);
       ?>
       <?php
//							 End of check of indented BOM Level 1
       $rowCount = $rowCount + 1;
      }
      ?>
     </tbody>
    </table>
   </div>
   <div id="tabsLine-2" class="scrollElement tabContent">
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th>Row#</th>
       <th>Level</th>
       <th>Start Date</th>
       <th>End Date</th>
       <th>ECO Number</th>
       <th>ECO implemented</th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      global $rowCount;
      $rowCount = 0;
      foreach ($bom_line_object as &$indented_bom_lines0) {
       $level = 0;
       ?>         
       <tr class="bom_line<?php echo $rowCount ?>">
        <td> <?php echo $rowCount; ?> </td>
        <td class="<?php echo 'L' . $level; ?>"> <?php echo $f->text_field('level', $level); ?> </td>
        <?php
        $indented_bom_statment = indentedBom_tab2($indented_bom_lines0);
        echo $indented_bom_statment;
        ?>
       </tr>
       <?php
       show_indentedBom($indented_bom_lines0, 'tab2', 1);
       $rowCount = $rowCount + 1;
      }
      ?>
     </tbody>
    </table>
   </div>
   <div id="tabsLine-3" class="tabContent">
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th>Row#</th>
       <th>Level</th>
       <th>Planning %</th>
       <th>Yield</th>
       <th>WIP Supply Type</th>
       <th>Sub inventory</th>
       <th>Locator</th>
       <th>In cost rollup</th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      global $rowCount;
      $rowCount = 0;
      foreach ($bom_line_object as &$indented_bom_lines0) {
       $level = 0;
       ?>         
       <tr class="bom_line<?php echo $rowCount ?>">
        <td> <?php echo $rowCount; ?> </td>
        <td class="<?php echo 'L' . $level; ?>"> <?php echo $f->text_field('level', $level); ?> </td>
        <?php
        $indented_bom_statment = indentedBom_tab3($indented_bom_lines0);
        echo $indented_bom_statment;
        ?>
       </tr>
       <?php
       show_indentedBom($indented_bom_lines0, 'tab3', 1);
       $rowCount = $rowCount + 1;
      }
      ?>
     </tbody>

    </table>
   </div>
  </div>
 </div>
</div>

<div id="js_data">
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_header_id" ></li>
  <li class="docLineId" data-docLineId="bom_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>