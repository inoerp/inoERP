<div id="form_all">
 <div id="form_headerDiv">
  <form action=""  method="post" id="inv_location_default_line"  name="location_default_line">
   <div id="form_serach_header"><span class="heading">Item Transaction Location Default</span>
    <label>Inventory Org :</label>
    <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $org_id_h, 'org_id'); ?>
    <a name="show" href="form.php?class_name=inv_location_default&<?php echo "mode=$mode"; ?>" class="show document_id inv_location_default_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
   </div>
   <div id ="form_line" class="inv_location_default"><span class="heading">Location Defaults </span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1">Item-Location </a></li>
      <li><a href="#tabsLine-2">Others </a></li>
     </ul>
     <div class="tabContainer"> 

      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Action</th>
          <th>Seq#</th>
          <th>Id</th>
          <th>Item</th>
          <th>Default Type</th>
          <th>Sub inventory</th>
          <th>Locator</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody location_default_values" >
         <?php
         $f = new inoform();
         $count = 0;
         $location_default_object_ai = new ArrayIterator($location_default_object);
         $location_default_object_ai->seek($position);
         while ($location_default_object_ai->valid()) {
          $inv_location_default = $location_default_object_ai->current();
          if(!empty( $$class->item_id_m)){
           $item_i = item::find_by_item_id_m($$class->item_id_m);
           $$class->item_number = !empty($item_i->item_number) ? $item_i->item_number : false;
          }else{
           $$class->item_number = '';
          }
          ?>         
          <tr class="inv_location_default<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
             <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->inv_location_default_id); ?>"></li>           
             <li><?php echo form::hidden_field('org_id', $org_id_h); ?></li>
            </ul>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php form::number_field_drs('inv_location_default_id') ?></td>
           <td><?php
            echo $f->hidden_field('item_id_m', $$class->item_id_m);
            $f->text_field_wid('item_number', 'select_item_number');
            ?><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
           <td><?php echo $f->select_field_from_object('default_type', inv_location_default::location_default_types(), 'option_line_code', 'option_line_value', $$class->default_type); ?></td>
           <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, '', 'subinventory_id copyValue', ''); ?>           </td>
           <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, '', 'locator_id copyValue', ''); ?>       </td>
          </tr>
          <?php
          $location_default_object_ai->next();
          if ($location_default_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Seq#</th>
          <th>Location</th>
          <th>Priority</th>
          <th>Description</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody location_default_values" >
         <?php
         $f = new inoform();
         $count = 0;
         $location_default_object_ai = new ArrayIterator($location_default_object);
         $location_default_object_ai->seek($position);
         while ($location_default_object_ai->valid()) {
          $inv_location_default = $location_default_object_ai->current();
          ?>         
          <tr class="inv_location_default<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_wid('address_id'); ?></td>
           <td><?php echo $f->select_field_From_array('priority', dbObject::$position_array, $$class->priority); ?></td>
           <td><?php form::text_field_wid('description'); ?></td>
          </tr>
          <?php
          $location_default_object_ai->next();
          if ($location_default_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
     </div>

    </div>
   </div> 
  </form>
 </div>
</div>

<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="inv_location_default" ></li>
  <li class="line_key_field" data-line_key_field="location_default" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_location_default" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_location_default_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="inv_location_default" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>