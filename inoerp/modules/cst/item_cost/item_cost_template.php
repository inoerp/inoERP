
<div id ="form_header"><span class="heading">Item Cost Header </span>
 <form action=""  method="post" id="cst_item_cost_header"  name="cst_item_cost_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Finance</a></li>
    <li><a href="#tabsHeader-3">Notes</a></li>
    <li><a href="#tabsHeader-4">Attachments</a></li>
    <li><a href="#tabsHeader-5">Actions</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="cst_item_cost_header_id select_popup clickable">
         Header Id</label><?php $f->text_field_dsr('cst_item_cost_header_id'); ?>
        <a name="show" href="form.php?class_name=cst_item_cost_header&<?php echo "mode=$mode"; ?>" class="show document_id cst_item_cost_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Cost Type(1)</label><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class->bom_cost_type, 'bom_cost_type', '', 1, $readonly); ?>       </li>
       <li><label>Inventory Org</label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup clickable">Item Number(2) : </label>
        <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
        <?php $f->text_field_d('item_number', 'select_item_number'); ?>
       </li>
       <li><label>Description</label><?php $f->text_field_d('item_description'); ?></li>
       <li><label>UOM</label><?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', 'uom_id', '', $readonly); ?>       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label>Base on RollUp : </label>
        <?php echo form::checkBox_field('based_on_rollup_cb', $$class->based_on_rollup_cb, 'based_on_rollup_cb'); ?>
       </li>
       <li><label>Include in RollUp : </label>
        <?php echo form::checkBox_field('include_in_rollup_cb', $$class->include_in_rollup_cb, 'include_in_rollup_cb'); ?>
       </li>
       <li><label>Purchase Prices : </label>
        <?php $f->text_field_d('sales_price'); ?>
       </li>
       <li><label>Sales Price : </label>
        <?php form::number_field_dm('purchase_price'); ?>
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'cst_item_cost_header';
       $reference_id = $$class->cst_item_cost_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="show_attachment" class="show_attachment">
       <div id="file_upload_form">
        <ul class="inRow asperWidth">
         <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
         <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
         <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
        </ul>
       </div>
       <div id="uploaded_file_details"></div>
       <?php echo file::attachment_statement($file); ?>
      </div>
     </div>
    </div>

    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label>Action</label>
        <?php echo $f->select_field_from_object('cost_action', cst_item_cost_header::transaction_action(), 'option_line_code', 'option_line_value', '', 'cost_action', '', '', $readonly); ?>
       </li>
       <li id="document_print"><label>Document Print : </label>
        <a class="button" target="_blank"
           href="po_print.php?cst_item_cost_header_id=<?php echo!(empty($$class->cst_item_cost_header_id)) ? $$class->cst_item_cost_header_id : ""; ?>" >Indented BOM</a>
       </li>
       <li id="document_print"><label>Document Print : </label>
        <a class="button" target="_blank"
           href="po_print.php?cst_item_cost_header_id=<?php echo!(empty($$class->cst_item_cost_header_id)) ? $$class->cst_item_cost_header_id : ""; ?>" >BOM Cost</a>
       </li>
      </ul>

      <div id="comment" class="shoe_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading">Cost Lines</span>
 <form action=""  method="post" id="cst_item_cost_line"  name="cst_item_cost_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">Future</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Line Id</th>
        <th>Element Type</th>
        <th>Element Id</th>
        <th>Basis</th>
        <th>Amount</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($cst_item_cost_line_object as $cst_item_cost_line) {
        $element_id_stmt = "<select class='select cost_element_id' name='cost_element_id[]'>";
        $cost_element_type = $cst_item_cost_line->cost_element_type;
        switch ($cost_element_type) {
         case 'MAT' :
          $class_name = 'bom_material_element';
          break;

         case 'MOH' :
         case 'OH' :
          $class_name = 'bom_overhead';
          break;

         case 'RES' :
          $class_name = 'bom_resource';
          break;

         case 'default':
          $class_name = false;
          break;
        }

        if (!empty($class_name)) {
         $cost_element_class = new $class_name;
         $key_column = $class_name::$key_column;
         $primary_column = $class_name::$primary_column;
         $all_data = $cost_element_class->findAll();
         foreach ($all_data as $obj) {
          $selected = ($cst_item_cost_line->cost_element_id == $obj->$primary_column) ? ' selected ' : null;
          $element_id_stmt .= '<option value="' . $obj->$primary_column . '"' . $selected . '>' . $obj->$key_column . '</option>';
         }
        }
        $element_id_stmt .= '</select>';
        $f->readonly2 = !empty($cst_item_cost_line->cst_item_cost_line_id) ? true : false;
        ?>         
        <tr class="cst_item_cost_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo $$class_second->cst_item_cost_line_id; ?>"></li>           
           <li><?php echo form::hidden_field('cst_item_cost_header_id', $$class->cst_item_cost_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid2sr('cst_item_cost_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('cost_element_type', cst_item_cost_line::cost_element_types(), 'option_line_code', 'option_line_value', $$class_second->cost_element_type, '', '', 1, $readonly); ?></td>
         <td><?php echo $element_id_stmt; ?>	</td>
         <td><?php echo $f->select_field_from_object('cost_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_second->cost_basis, '', '', 1, $readonly); ?></td>
         <td><?php form::number_field_wid2sm('amount'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">

    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="cst_item_cost_header" ></li>
  <li class="lineClassName" data-lineClassName="cst_item_cost_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="cst_item_cost_header_id" ></li>
  <li class="form_header_id" data-form_header_id="cst_item_cost_header" ></li>
  <li class="line_key_field" data-line_key_field="cost_element_type" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="cst_item_cost_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="cst_item_cost_header_id" ></li>
  <li class="docLineId" data-docLineId="cst_item_cost_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="cst_item_cost_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>