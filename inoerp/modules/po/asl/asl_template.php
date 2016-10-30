<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Approved Supplier List') ?></span>
 <form method="post" id="asl_header"  name="asl_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('po_asl_header_id') ?>
       <a name="show" href="form.php?class_name=po_asl_header&<?php echo "mode=$mode"; ?>" class="show document_id po_asl_header_id">
        <i class='fa fa-refresh'></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_select_field_from_array('asl_type', po_asl_header::$asl_type_a, $$class->asl_type, 'asl_type', '', 1, $readonly1, $readonly1); ?>      </li>
      <li><label><?php echo gettext('Item') ?></label><?php
       echo $f->hidden_field('item_id_m', $$class->item_id_m);
       echo $f->text_field_d('item_number', 'select_item_number');
       ?>
       <i class="select_item_number select_popup clickable fa fa-search"></i></li>
      <li><?php $f->l_text_field_d('description', 'item_description'); ?>     </li>
     </ul>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('ASL Lines') ?></span>
 <form method="post" id="asl_line"  name="asl_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Others') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Supplier Id') ?>#</th>
        <th><?php echo gettext('Supplier Name') ?></th>
        <th><?php echo gettext('Supplier Site') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Manufacturer') ?></th>
        <th><?php echo gettext('MPN') ?></th>
        <th><?php echo gettext('Comment') ?></th>
        <th><?php echo gettext('Documents') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_asl_line_object as $po_asl_line) {
        if (!empty($$class_second->supplier_id)) {
         $sup = new supplier();
         $sup->findBy_id($$class_second->supplier_id);
         $$class_second->supplier_name = $sup->supplier_name;
         $supplier_site = supplier_site::find_by_id($$class_second->supplier_site_id);
         $supplier_site_obj = [];
         array_push($supplier_site_obj, $supplier_site);
         $supplier_site_name_statement = $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class_second->supplier_site_id, '', 'supplier_site_id', '', $readonly);
        } else {
         $$class_second->supplier_name = null;
         $supplier_site_name_statement = form::text_field('supplier_site_id', $$class_second->supplier_site_id);
        }
        ?>         
        <tr class="po_asl_line<?php echo $count ?>">
         <td>    
          <?php
          echo ino_inline_action($$class_second->po_asl_line_id, array('po_asl_header_id' => $$class->po_asl_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('po_asl_line_id'); ?></td>
         <td><?php $f->text_field_wid2sr('supplier_id'); ?></td>
         <td><?php $f->text_field_wid2('supplier_name', 'select_supplier_name'); ?>
          <i class="fa fa-search select_supplier_name select_popup clickable"></i></td>
         <td><?php echo $supplier_site_name_statement; ?></td>
         <td><?php $f->status_field_d2('status'); ?></td>
         <td><?php $f->text_field_wid2s('manufacturer'); ?></td>
         <td><?php $f->text_field_wid2('mfg_part_number'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><a target="_blank" href="form.php?class_name=po_asl_document&mode=9&po_asl_line_id=<?php echo $$class_second->po_asl_line_id; ?>"><i class="fa fa-edit"></i></a></td>
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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Release Method') ?></th>
        <th><?php echo gettext('Min Order Qty') ?>#</th>
        <th><?php echo gettext('Lot Multiplier') ?></th>
        <th><?php echo gettext('Country Of Origin') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_asl_line_object as $po_asl_line) {
        ?>         
        <tr class="po_asl_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->select_field_from_array('release_method', po_asl_line::$release_method_a, $$class_second->release_method); ?></td>
         <td><?php echo $f->number_field('min_order_quantity', $$class_second->min_order_quantity); ?></td>
         <td><?php echo $f->number_field('fix_lot_multiplier', $$class_second->fix_lot_multiplier); ?></td>
         <td><?php echo $f->select_field_from_object('country_of_origin', option_header::countries(), 'option_line_code', 'option_line_value', $$class_second->country_of_origin); ?></td>
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
  <li class="headerClassName" data-headerClassName="po_asl_header" ></li>
  <li class="lineClassName" data-lineClassName="po_asl_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_asl_header_id" ></li>
  <li class="form_header_id" data-form_header_id="asl_header" ></li>
  <li class="line_key_field" data-line_key_field="po_asl_header_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="po_asl_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_asl_header_id" ></li>
  <li class="docLineId" data-docLineId="po_asl_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_asl_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-doctrClass="po_asl_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
