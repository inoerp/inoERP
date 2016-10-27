<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->


<div id ="form_header">
 <form method="post" id="bom_header"  name="bom_header">
  <span class="heading"><?php
   echo gettext('Bill Of Materials');
   echo!empty($form_name_header) ? ' - ' . gettext($form_name_header) : ' ';
   ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Common BOM') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $bom_header->org_id, 'org_id', '', '', $readonly); ?>       </li>
      <li><label><?php echo gettext('Item Number') ?></label><?php
       echo $f->hidden_field_withId('bom_header_id', $$class->bom_header_id);
       echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
       echo $f->hidden_field_withCLass('bom_enabled_cb', '1', 'popup_value');
       echo !empty($hidden_field) ? $hidden_field : '';
       $f->text_field_dm('item_number', 'select_item_number_all');
       ?>
       <i class="select_item_number select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_select_field_from_object('revision_name', $revision_name_a, 'revision_name', array('revision_name', 'effective_start_date'), $revision_name_val, 'revision_name', 'medium', '', '', '', '', '', 'effective_start_date'); ?>
       <a name="show" href="form.php?class_name=bom_header&<?php echo "mode=$mode"; ?>" class="show2 document_id bom_header_withRev_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', 'uom_id'); ?>       </li>
      <li><?php $f->l_text_field_dr('item_description'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('alternate_bom'); ?>   </li>
       <li><label><?php echo gettext('Revision') ?></label><?php
        echo $f->text_field_ap(array('name' => 'bom_revision',
         'value' => $$class->bom_revision, 'readonly' => $readonly1));
        ?>     </li>
       <li><?php $f->l_date_fieldAnyDay_r('effective_date', $$class->effective_date); ?></li>
       <li><?php $f->l_text_field_dr('bom_header_id'); ?>   </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('common_bom_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->common_bom_org_id, 'common_bom_org_id', '', '', $readonly); ?>       </li>
       <li><?php echo $f->hidden_field_withIdClass('common_bom_item_id_m', $$class->common_bom_item_id_m, 'item_id_m'); ?>
        <?php $f->l_text_field_dr('commonBom_item_number', 'item_number'); ?>
       <i class="select_item_number select_popup clickable fa fa-search"></i>
       </li>
       <li><?php $f->l_text_field_dr('commonBom_item_description', 'item_description'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'bom_header';
       $reference_id = $$class->bom_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('BOM Lines') ?></span>
 <form  method="post" id="bom_line"  name="bom_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Effectivity') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Control') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('BOM Line Id') ?></th>
        <th><?php echo gettext('BOM Sequence') ?></th>
        <th><?php echo gettext('Routing Seq') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Revision') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Usage Basis') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0; 
       foreach ($bom_line_object as $bom_line) {
        ?>         
        <tr class="bom_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->bom_line_id, array('bom_header_id' => $$class->bom_header_id,
           'bom_commonbom_line_id' => $$class_second->bom_commonbom_line_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('bom_line_id','line_id always_readonly'); ?></td>
         <td><?php $f->text_field_d2s('bom_sequence', 'lines_number'); ?></td>
         <td><?php echo!empty($routing_line_details) ? form::select_field_from_object('routing_sequence', $routing_line_details, 'bom_routing_line_id', 'routing_sequence', $$class_second->routing_sequence, '', $readonly, 'usage_basis', '', 1) : form::text_field_wid2s('routing_sequence'); ?></td>
         <td><?php
          $f->text_field_wid2('component_item_number', 'select_item_number xlarge');
          echo $f->hidden_field_withCLass('component_item_id_m', $$class_second->component_item_id_m, 'item_id_m');
          ?><i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php
          if (!empty($$class_second->component_item_id_m) && !empty($$class->org_id)) {
           $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class_second->component_item_id_m, $$class->org_id);
          } else {
           $revision_name_a = array();
          }
          echo $f->select_field_from_object('component_revision', $revision_name_a, 'revision_name', 'revision_name', $$class_second->component_revision, '', 'medium');
          ?></td>
         <td><?php $f->text_field_wid2('component_description', 'item_description xlarge'); ?></td>
         <td><?php echo $f->select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_second->component_uom, '', 'medium', '', $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('usage_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_second->usage_basis, '', 'usage_basis medium',  '', $readonly); ?></td>
         <td><?php echo $f->number_field('usage_quantity', $$class_second->usage_quantity, '', '', 'small'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
        <th><?php echo gettext('ECO Number') ?></th>
        <th><?php echo gettext('ECO implemented') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($bom_line_object as $bom_line) {
        ?>         
        <tr class="bom_line<?php echo $count ?>">
         <td><?php echo $f->date_fieldFromToday('effective_start_date', $$class_second->effective_start_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
         <td><?php form::text_field_wid2('eco_number'); ?></td>
         <td>
          <?php echo form::checkBox_field('eco_implemented_cb', $$class_second->eco_implemented_cb, 'eco_implemented_cb', $readonly); ?>
         </td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Planning') ?> %</th>
        <th><?php echo gettext('Yield') ?></th>
        <th><?php echo gettext('WIP Supply Type') ?></th>
        <th><?php echo gettext('Subinventory') ?></th>
        <th><?php echo gettext('Locator') ?></th>
        <th><?php echo gettext('In cost Rollup') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($bom_line_object as $bom_line) {
        ?>         
        <tr class="bom_line<?php echo $count ?>">
         <td><?php form::text_field_wid2('planning_percentage'); ?></td>
         <td><?php form::text_field_wid2('yield'); ?></td>
         <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_second->wip_supply_type, '', 'medium', '', $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->supply_sub_inventory, '', 'subinventory_id medium', '', $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_second->supply_sub_inventory), 'locator_id', 'locator', $$class_second->supply_locator, '',  'locator_id medium', '', $readonly); ?></td>
         <td>
          <?php echo form::checkBox_field('include_in_cost_rollup_cb', $$class_second->include_in_cost_rollup_cb, 'include_in_cost_rollup_cb', $readonly); ?>
         </td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->

     </table>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_header" ></li>
  <li class="lineClassName" data-lineClassName="bom_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_header_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_header" ></li>
  <li class="line_key_field" data-line_key_field="component_item_id_m" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="bom_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_header_id" ></li>
  <li class="docLineId" data-docLineId="bom_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
