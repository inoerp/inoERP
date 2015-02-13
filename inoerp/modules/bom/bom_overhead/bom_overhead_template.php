<div id="form_all"><span class="heading">Over Head</span>
 <form action=""  method="post" id="bom_overhead"  name="bom_overhead">
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
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_overhead_id select_popup clickable">
          Overhead Id</label><?php $f->text_field_dsr('bom_overhead_id'); ?>
         <a name="show" href="form.php?class_name=bom_overhead&<?php echo "mode=$mode"; ?>" class="show document_id bom_overhead_id"><i class="fa fa-refresh"></i></a> 
        </li>
        <li><label>Inventory</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>      </li>
        <li><label>Overhead (2)</label><?php echo form::text_field_d('overhead'); ?></li>
        <li><label>Description</label><?php echo form::text_field_d('description'); ?></li>
        <li><label>Overhead Type</label><?php echo form::select_field_from_object('overhead_type', bom_header::bom_overhead_type(), 'option_line_code', 'option_line_value', $$class->overhead_type, 'overhead_type', $readonly, 'overhead_type'); ?>      </li>
        <li><label>Default Basis</label><?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class->default_basis, 'default_basis', $readonly, 'default_basis'); ?>      </li>
        <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
        <li><label>Absorption Ac</label><?php $f->ac_field_d('absorption_ac_id'); ?></li>
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
         $reference_table = 'bom_overhead';
         $reference_id = $$class->bom_overhead_id;
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
 </form>
 <span class="heading"> Over Head Details </span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1">Resource Assignment</a></li>
   <li><a href="#tabsLine-2">Rate Assignment</a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsLine-1" class="tabContent">
    <div id ="form_line" class="form_line">
     <form action=""  method="post" id="bom_overhead_resource_assignment_line"  name="bom_overhead_resource_assignment_line">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Resource Assignment Id</th>
         <th>Cost Type</th>
         <th>Description</th>
         <th>Resource</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody bom_overhead_resource_assignment_values" >
        <?php
        $count = 0;
        foreach ($bom_overhead_resource_assignment_object as $bom_overhead_resource_assignment) {
         if (!empty($bom_overhead_resource_assignment->bom_cost_type)) {
          $bcy = new bom_cost_type();
          $bcy_i = $bcy->find_by_keyColumn($bom_overhead_resource_assignment->bom_cost_type);
          $bom_overhead_resource_assignment->bom_cost_type_description = $bcy_i->description;
         } else {
          $bom_overhead_resource_assignment->bom_cost_type_description = null;
         }
         ?>         
         <tr class="bom_overhead_resource_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->bom_overhead_resource_assignment_id, array('bom_overhead_id' => $$class->bom_overhead_id));
           ?>
          </td>
          <td><?php form::text_field_wid2('bom_overhead_resource_assignment_id'); ?></td>
          <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->bom_cost_type, '', '', 1, $readonly); ?></td>
          <td><?php $f->text_field_wid2r('bom_cost_type_description'); ?></td>
          <td>
           <?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_second->resource_id, '', $readonly, 'resource_id'); ?>
          </td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </form>
    </div>
   </div> 

   <div id="tabsLine-2" class="tabContent">
    <div id ="form_line2" class="form_line2">
     <form action=""  method="post" id="bom_overhead_rate_assignment_line"  name="bom_overhead_rate_assignment_line">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Rate Assignment Id</th>
         <th>Cost Type</th>
         <th>Default Basis</th>
         <th>Rate</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody2 bom_overhead_rate_assignment_values" >
        <?php
        $count = 0;
        foreach ($bom_overhead_rate_assignment_object as $bom_overhead_rate_assignment) {
         $class_third = 'bom_overhead_rate_assignment';
         $$class_third = & $bom_overhead_rate_assignment;
         ?>         
         <tr class="bom_overhead_rate_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_third->bom_overhead_rate_assignment_id, array('bom_overhead_id' => $$class->bom_overhead_id));
           ?>
          </td>
          <td><?php form::text_field_wid3('bom_overhead_rate_assignment_id'); ?></td>
          <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_third->bom_cost_type, '', '', 1, $readonly); ?></td>
          <td><?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->default_basis, '', $readonly, 'default_basis'); ?> </td>
          <td><?php form::text_field_wid3('rate'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </form>
    </div>
   </div>

  </div>

 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_overhead" ></li>
  <li class="lineClassName" data-lineClassName="bom_overhead_resource_assignment" ></li>
  <li class="lineClassName2" data-lineClassName2="bom_overhead_rate_assignment" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_overhead_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_overhead" ></li>
  <li class="line_key_field" data-line_key_field="resource_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_overhead_id" ></li>
  <li class="docLineId" data-docLineId="bom_overhead_resource_assignment_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_overhead" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="bom_overhead" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>