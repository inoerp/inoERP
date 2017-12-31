<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="form_header"><span class="heading"><?php  echo gettext('Recipe Material') ?></span>
 <form  method="post" id="pm_recipe_material_header"  name="pm_recipe_material_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('pm_recipe_material_header_id') ?>
       <a name="show" href="form.php?class_name=pm_recipe_material_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_recipe_material_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php
       echo $f->l_val_field_dm('recipe_name', 'pm_recipe_header', 'recipe_name', '', 'recipe_name', 'vf_select_recipe_name ');
       echo $f->hidden_field_withId('pm_recipe_header_id', $$class->pm_recipe_header_id);
       ?><i class="generic g_select_routing_name select_popup clickable fa fa-search" data-class_name="pm_recipe_header"></i> 
       <a name="show" href="form.php?class_name=pm_recipe_material_header&<?php echo "mode=$mode"; ?>" class="show2 document_id pm_recipe_material_header_id_withRecipeName"><i class="fa fa-refresh"></i></a></li>
      <li><?php $f->l_text_field_dr('routing_name'); ?></li>
      <li><?php $f->l_text_field_dr('routing_description'); ?></li>
      <li><?php $f->l_text_field_dr('formula_name'); ?></li>
      <li><?php $f->l_text_field_dr('formula_description'); ?></li>
      <li><?php $f->l_text_field_d('status'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'pm_recipe_material_header';
        $reference_id = $$class->pm_recipe_material_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
     <span class="hidden"><?php echo $f->select_field_from_object('pm_operion_header_id', $all_operation_objs, 'pm_process_operation_header_id', array('operation_name', 'org_id'), $$class_second->pm_operion_header_id, 'pm_operion_header_id', 'medium', '', '', '', '', '', 'org_id'); ?></span>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Materials @ Operation') ?></span>
 <form method="post" id="pm_recipe_material_line"  name="pm_recipe_material_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Routing Steps') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Ingredient') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Product') ?></th>
        <th><?php echo gettext('By Product') ?></th>
          <th><?php echo gettext('Routing Line') ?></th>
        <th><?php echo gettext('Step') ?> #</th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $f = new inoform();
       $count = 0;
       foreach ($pm_recipe_material_line_object as $pm_recipe_material_line) {
        ?>         
        <tr class="pm_recipe_material_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_recipe_material_line->pm_recipe_material_line_id, array('pm_recipe_material_header_id' => $$class->pm_recipe_material_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('pm_recipe_material_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('pm_formula_ingredient_id', $forumla_ingredients, 'pm_formula_ingredient_id', ['item_number', 'revision_name', 'item_description', 'description'], $$class_second->pm_formula_ingredient_id, '', 'one_value', '', '', '', '', '', ['quantity', 'uom_id']); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small always_readonly', '', '1'); ?></td>
         <td><?php form::number_field_wid2s('quantity'); ?></td>
         <td><?php echo $f->select_field_from_object('pm_formula_line_id', $pm_formula_lines, 'pm_formula_line_id', ['item_number', 'item_description'], $$class_second->pm_formula_line_id, '', 'one_value'); ?></td>
         <td><?php echo $f->select_field_from_object('pm_formula_byproduct_id', $pm_formula_byproducts, 'pm_formula_byproduct_id', ['item_number', 'item_description'], $$class_second->pm_formula_byproduct_id, '', 'one_value medium'); ?></td>
         <td><?php echo $f->select_field_from_object('pm_process_routing_line_id', $pm_process_routing_lines, 'pm_process_routing_line_id', [ 'step_no', 'operation_name'], $$class_second->pm_process_routing_line_id, '', '', 1, '', '', '', '', 'step_no'); ?></td>
         <td><?php $f->text_field_wid2r('step_no', 'always_readonly small'); ?></td>
         <td><?php $f->text_field_wid2('description', 'large'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>

   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="pm_recipe_material_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_recipe_material_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_recipe_material_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_recipe_material_header" ></li>
  <li class="line_key_field" data-line_key_field="header_type_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_recipe_material_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_recipe_material_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_recipe_material_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_recipe_material_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>