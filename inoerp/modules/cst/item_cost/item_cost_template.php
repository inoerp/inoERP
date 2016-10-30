<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Item Cost Header') ?></span>
 <form method="post" id="cst_item_cost_header"  name="cst_item_cost_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('cst_item_cost_header_id'); ?>
        <a name="show" href="form.php?class_name=cst_item_cost_header&<?php echo "mode=$mode"; ?>" class="show document_id cst_item_cost_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class->bom_cost_type, 'bom_cost_type', '', 1, $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
       <li><label><?php echo gettext('Item Number') ?></label><?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
        <?php $f->text_field_d('item_number', 'select_item_number'); ?>
        <i class="select_item_number select_popup clickable fa fa-search"></i>
       </li>
       <li><?php $f->l_text_field_d('item_description'); ?></li>
       <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', 'uom_id', '', $readonly); ?>       </li>
      </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('based_on_rollup_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('include_in_rollup_cb'); ?></li>
       <li><?php $f->l_number_field('sales_price', $$class->sales_price); ?></li>
       <li><?php $f->l_number_field('purchase_price', $$class->purchase_price); ?> </li>
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
       <?php echo extn_file::attachment_statement($file); ?>
      </div>
     </div>
    </div>

    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label><?php echo gettext('Action') ?></label>
        <?php echo $f->select_field_from_object('cost_action', cst_item_cost_header::transaction_action(), 'option_line_code', 'option_line_value', '', 'cost_action', '', '', $readonly); ?>
       </li>
       <li id="document_print"><label><?php echo gettext('Document Print') ?> : </label>
        <a class="button disabled" target="_blank"
           disabled href="po_print.php?cst_item_cost_header_id=<?php echo!(empty($$class->cst_item_cost_header_id)) ? $$class->cst_item_cost_header_id : ""; ?>" ><?php echo gettext('Indented BOM') ?></a>
       </li>
       <li id="document_print"><label><?php echo gettext('Document Print') ?> : </label>
        <a class="button disabled" target="_blank"
          disabled href="po_print.php?cst_item_cost_header_id=<?php echo!(empty($$class->cst_item_cost_header_id)) ? $$class->cst_item_cost_header_id : ""; ?>" ><?php echo gettext('BOM Cost') ?></a>
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Cost Lines') ?></span>
 <form method="post" id="cst_item_cost_line"  name="cst_item_cost_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Element Type') ?></th>
        <th><?php echo gettext('Element Id') ?></th>
        <th><?php echo gettext('Basis') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('This Level Cost ?') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($cst_item_cost_line_object as $cst_item_cost_line) {
        $element_id_stmt = "<select class='select cost_element_id large' name='cost_element_id[]'>";
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
          <?php $f = new inoform();
          echo ino_inline_action($$class_second->cst_item_cost_line_id, array('cst_item_cost_header_id' => $$class->cst_item_cost_header_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('cst_item_cost_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('cost_element_type', cst_item_cost_line::cost_element_types(), 'option_line_code', 'option_line_value', $$class_second->cost_element_type, '', 'large', 1, $readonly); ?></td>
         <td><?php echo $element_id_stmt; ?>	</td>
         <td><?php echo $f->select_field_from_object('cost_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_second->cost_basis, '', 'large', 1, $readonly); ?></td>
         <td><?php echo $f->number_field('amount', $$class_second->amount); ?></td>
         <td><?php $f->checkBox_field_wid2('this_level_cb'); ?></td>
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
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
