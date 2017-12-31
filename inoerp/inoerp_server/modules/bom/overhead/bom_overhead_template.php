<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id="form_all"><span class="heading"><?php echo gettext('Overhead') ?></span>
 <form  method="post" id="bom_overhead"  name="bom_overhead">
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
        <li><?php $f->l_text_field_dr_withSearch('bom_overhead_id'); ?>
         <a name="show" href="form.php?class_name=bom_overhead&<?php echo "mode=$mode"; ?>" class="show document_id bom_overhead_id"><i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>      </li>
        <li><?php $f->l_text_field_d('overhead'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_object('overhead_type', bom_header::bom_overhead_type(), 'option_line_code', 'option_line_value', $$class->overhead_type, 'overhead_type', '', 1, $readonly); ?>      </li>
        <li><?php $f->l_select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class->default_basis, 'default_basis', '', '', $readonly); ?>      </li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_ac_field_d('absorption_ac_id'); ?></li>
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
 <span class="heading"><?php echo gettext('Overhead Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Resource Assignment') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Rate Assignment') ?> </a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsLine-1" class="tabContent">
    <div id ="form_line" class="form_line">
     <form  method="post" id="bom_oh_res_assignment_line"  name="bom_oh_res_assignment_line">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Resource Assignment Id') ?></th>
         <th><?php echo gettext('Cost Type') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Resource') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody bom_oh_res_assignment_values" >
        <?php
        $count = 0;
        foreach ($bom_oh_res_assignment_object as $bom_oh_res_assignment) {
         if (!empty($bom_oh_res_assignment->bom_cost_type)) {
          $bcy = new bom_cost_type();
          $bcy_i = $bcy->find_by_keyColumn($bom_oh_res_assignment->bom_cost_type);
          $bom_oh_res_assignment->bom_cost_type_description = $bcy_i->description;
         } else {
          $bom_oh_res_assignment->bom_cost_type_description = null;
         }
         ?>         
         <tr class="bom_oh_res_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->bom_oh_res_assignment_id, array('bom_overhead_id' => $$class->bom_overhead_id));
           ?>
          </td>
          <td><?php form::text_field_wid2('bom_oh_res_assignment_id', 'always_readonly'); ?></td>
          <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->bom_cost_type, '', 'large', 1, $readonly); ?></td>
          <td><?php $f->text_field_wid2r('bom_cost_type_description' ,'xlarge'); ?></td>
          <td><?php echo $f->select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_second->resource_id, '', 'resource_id large',  '', $readonly); ?></td>
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
     <form  method="post" id="bom_oh_rate_assignment_line"  name="bom_oh_rate_assignment_line">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Rate Assignment Id') ?></th>
         <th><?php echo gettext('Cost Type') ?></th>
         <th><?php echo gettext('Default Basis') ?></th>
         <th><?php echo gettext('Rate') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody2 bom_oh_rate_assignment_values" >
        <?php
        $count = 0;
        foreach ($bom_oh_rate_assignment_object as $bom_oh_rate_assignment) {
         $class_third = 'bom_oh_rate_assignment';
         $$class_third = & $bom_oh_rate_assignment;
         ?>         
         <tr class="bom_oh_rate_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_third->bom_oh_rate_assignment_id, array('bom_overhead_id' => $$class->bom_overhead_id));
           ?>
          </td>
          <td><?php form::text_field_wid3('bom_oh_rate_assignment_id' ,'always_readonly'); ?></td>
          <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_third->bom_cost_type, '', 'large', 1, $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->default_basis, '', 'default_basis large', '', $readonly); ?> </td>
          <td><?php form::text_field_wid3('rate' , 'large'); ?></td>
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
  <li class="lineClassName" data-lineClassName="bom_oh_res_assignment" ></li>
  <li class="lineClassName2" data-lineClassName2="bom_oh_rate_assignment" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_overhead_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_overhead" ></li>
  <li class="line_key_field" data-line_key_field="resource_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_overhead_id" ></li>
  <li class="docLineId" data-docLineId="bom_oh_res_assignment_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_overhead" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="bom_overhead" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
