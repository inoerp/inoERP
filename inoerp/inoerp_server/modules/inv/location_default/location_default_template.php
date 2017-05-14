<div class="row small-left-padding">
 <div id="form_all">
 <div id="form_headerDiv">
  <form  method="post" id="inv_location_default_line"  name="location_default_line"><span class="heading">
   <?php echo gettext('Item Transaction Location Default') ?></span>
   <div class="tabContainer">
    <label><?php echo gettext('Inventory Org') ?> </label>
    <?php echo $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $org_id_h, 'org_id' , 'action medium'); ?>
    <a name="show" href="form.php?class_name=inv_location_default&<?php echo "mode=$mode"; ?>" class="show document_id inv_location_default_id">
     <i class='fa fa-refresh '></i></a> 
   </div>
   <div id ="form_line" class="inv_location_default"><span class="heading"><?php echo gettext('Location Defaults') ?></span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Item-Location') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Others') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?></th>
          <th><?php echo gettext('Id') ?></th>
          <th><?php echo gettext('Item') ?></th>
          <th><?php echo gettext('Default Type') ?></th>
          <th><?php echo gettext('Subinventory') ?></th>
          <th><?php echo gettext('Locator') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody location_default_values" >
         <?php
         $count = 0;
         $location_default_object_ai = new ArrayIterator($location_default_object);
         $location_default_object_ai->seek($position);
         while ($location_default_object_ai->valid()) {
          $inv_location_default = $location_default_object_ai->current();
          if (!empty($$class->item_id_m)) {
           $item_i = item::find_by_item_id_m($$class->item_id_m);
           $$class->item_number = !empty($item_i->item_number) ? $item_i->item_number : false;
          } else {
           $$class->item_number = '';
          }
          ?>         
          <tr class="inv_location_default<?php echo $count ?>">
           <td><?php
            echo ino_inline_action($$class->inv_location_default_id, array('org_id' => $org_id_h));
            ?>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php form::number_field_drs('inv_location_default_id' , 'always_readonly') ?></td>
           <td><?php
            echo $f->hidden_field('item_id_m', $$class->item_id_m);
            $f->text_field_wid('item_number', 'select_item_number');
            ?><i class="select_item_number select_popup clickable fa fa-search"></i></td>
           <td><?php echo $f->select_field_from_object('default_type', inv_location_default::location_default_types(), 'option_line_code', 'option_line_value', $$class->default_type, '' ,'meidum'); ?></td>
           <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, '', 'subinventory_id copyValue large', ''); ?>           </td>
           <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, '', 'locator_id copyValue large', ''); ?>       </td>
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
          <th><?php echo gettext('Seq') ?></th>
          <th><?php echo gettext('Location') ?></th>
          <th><?php echo gettext('Priority') ?></th>
          <th><?php echo gettext('Description') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody location_default_values" >
         <?php
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
</div>


<div class="row small-top-margin" >
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
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
