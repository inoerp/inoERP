<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Burden Structure')   ?></span>
 <form  method="post" id="prj_burden_structure_header"  name="prj_burden_structure_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_burden_structure_header_id') ?>
       <a name="show" href="form.php?class_name=prj_burden_structure_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_burden_structure_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('structure'); ?></li>
      <li><?php $f->l_select_field_from_array('structure_type', prj_burden_structure_header::$structure_type_a, $$class->structure_type,'structure_type'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_checkBox_field_d('allow_override_cb'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
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
        $reference_table = 'prj_burden_structure_header';
        $reference_id = $$class->prj_burden_structure_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>

  </div>
 </form>
</div>

<span class="heading"><?php echo gettext('Burden Structure Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Cost Code') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Expenditure Type') ?></a></li>
 </ul>
 <div class="tabContainer">
  <form action=""  method="post" id="prj_burden_struct_costcode"  name="prj_burden_struct_costcode" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Cost Code') ?></th>
        <th><?php echo gettext('Cost Base') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Priority') ?>?</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_burden_struct_costcode_object as $prj_burden_struct_costcode) {
//        if (!empty($$class_second->prj_category_header_id)) {
//         $$class_second->category_description = prj_category_header::find_by_id($$class_second->prj_category_header_id)->description;
//        }
        ?>         
        <tr class="prj_burden_struct_costcode<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_burden_struct_costcode->prj_burden_struct_costcode_id, array('prj_burden_structure_header_id' => $prj_burden_structure_header->prj_burden_structure_header_id));
          ?>
         </td>

         <td><?php form::text_field_wid2sr('prj_burden_struct_costcode_id'); ?></td>
         <td><?php echo $f->select_field_from_object('burden_cost_code_id', prj_burden_costcode::find_all(), 'prj_burden_costcode_id', 'costcode', $$class_second->burden_cost_code_id, '', 'large', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('burden_cost_base_id', prj_burden_cost_base::find_all(), 'prj_burden_cost_base_id', 'cost_base', $$class_second->burden_cost_base_id, '', 'large', 1, $readonly); ?></td>
         <td><?php form::text_field_wid2r('description'); ?></td>
         <td><?php form::text_field_wid2('priority'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form action=""  method="post" id="prj_burden_struct_exptype"  name="prj_burden_struct_exptype">
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Expenditure Type') ?></th>
        <th><?php echo gettext('Cost Base') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_burden_struct_exptype_object as $prj_burden_struct_exptype) {
        ?>         
        <tr class="prj_burden_struct_exptype<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_burden_struct_exptype->prj_burden_struct_exptype_id); ?>"></li>           
           <li><?php echo form::hidden_field('prj_burden_structure_header_id', $$class->prj_burden_structure_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('prj_burden_struct_exptype_id'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_type_id', prj_expenditure_type_header::find_all(), 'prj_expenditure_type_header_id', 'expenditure_type', $$class_third->prj_expenditure_type_id, '', 'large', 1, ''); ?></td>
         <td><?php echo $f->select_field_from_object('burden_cost_base_id', prj_burden_cost_base::find_all(), 'prj_burden_cost_base_id', 'cost_base', $$class_third->burden_cost_base_id, '', 'large', 1, ''); ?></td>
         <td><?php form::text_field_wid3('description'); ?></td>        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_burden_structure_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_burden_struct_costcode" ></li>
  <li class="lineClassName2" data-lineClassName2="prj_burden_struct_exptype" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_burden_structure_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_burden_structure_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_burden_struct_costcode" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_burden_structure_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_burden_struct_costcode_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_burden_structure_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>