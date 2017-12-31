<!--/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */-->

<div id="po_quote_divId">
<div id ="form_header"><span class="heading"><?php echo gettext('Quotation') ?></span>
 <form   method="post" id="po_quote_header"  name="po_quote_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Conditions') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Description') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Address Details') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"><li>
       <?php $f->l_text_field_dr_withSearch('po_quote_header_id') ?>
       <a name="show" href="form.php?class_name=po_quote_header&<?php echo "mode=$mode"; ?>" class="show document_id po_quote_header_id"><i class="fa fa-refresh"></i></a>     </li>
      <li><label><?php echo gettext('RFQ Number') ?></label><?php echo $f->hidden_field('po_rfq_header_id', $$class->po_rfq_header_id) ?>
       <?php echo $f->text_field_dsrm('rfq_number') ?>
      </li>
      <li><label><?php echo gettext('Quote Type') ?>(2)</label><?php echo $f->hidden_field_withId('bu_org_id', $$class->bu_org_id); ?>
       <?php echo $f->select_field_from_array('quote_type', po_quote_header::$po_quote_type_a, $$class->quote_type, 'quote_type', '', 1); ?>
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_text_field_d('quote_number', 'primary_column2'); ?> </li>
      <li><?php 
        echo $f->l_val_field_dm('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
        echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
        ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
      <li><?php
       echo $f->l_val_field_d('supplier_number', 'supplier', 'supplier_number', '', '', 'vf_select_supplier_number');
       ?><i class="generic g_select_supplier_number select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
      <li><label><?php echo gettext('Supplier Site') ?></label><?php
       $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
       echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
       ?> </li>
      <li><?php $f->l_select_field_from_array('quote_status', po_quote_header::$po_quote_status_a, $$class->quote_status, 'quote_status' , 'always_readonly', '',1); ?>       </li>
      <li><?php $f->l_checkBox_field_d('active_cb') ?>   </li>
      <li><?php $f->l_text_field_d('buyer'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_date_fieldAnyDay('effective_start_date', $$class->effective_start_date) ?>       </li>
      <li><?php $f->l_date_fieldAnyDay('effective_end_date', $$class->effective_end_date) ?> </li>
      <li><?php $f->l_date_fieldAnyDay('valid_date', $$class->valid_date) ?></li>
      <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'doc_currency', '', 1, $readonly); ?>       </li>
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?>       </li>
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div><label class="text_area_label"><?php echo gettext('Detailed Description') ?></label><?php
      echo $f->text_area_ap(array('name' => 'description', 'value' => $$class->description,
       'row_size' => '10', 'column_size' => '90'));
      ?> 	
     </div> 
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'po_quote_header';
        $reference_id = $$class->po_quote_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <div> 
      <ul class="column four_column">
       <li id="document_print"><label><?php echo gettext('Document Print') ?></label>
        <a class="button" target="_blank"
           href="<?php echo HOME_URL ?>modules/po/po_quote_print.php?po_quote_header_id=<?php echo!(empty($$class->po_quote_header_id)) ? $$class->po_quote_header_id : ""; ?>" >Print quote</a>
       </li>
       <li><label><?php echo gettext('Action') ?></label>
        <?php
        $action_readonly = ($$class->quote_status == 'CLOSED') ? 1 : '';
        echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
        ?>
       </li>
      </ul>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Quote Lines') ?></span>
 <form method="post" id="po_quote_line"  name="po_quote_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Factors') ?></a></li>

   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('Mfg Part Number') ?></th>
        <th><?php echo gettext('Manufacturer') ?></th>
        <th><?php echo gettext('Min Quantity') ?></th>
        <th><?php echo gettext('Max Quantity') ?></th>
        <th><?php echo gettext('Requirements') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_quote_line_object as $po_quote_line) {
        ?>         
        <tr class="po_quote_line<?php echo $count ?>">
         <td> 
          <?php
          echo ino_inline_action($$class_second->po_quote_line_id, array('po_quote_header_id' => $$class->po_quote_header_id,
           'po_rfq_line_id' => $$class_second->po_rfq_line_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('po_quote_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          form::text_field_wid2('item_number', 'select_item_number');
          ?>
          <i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php $f->text_field_wid2m('item_description'); ?></td>
         <td><?php $f->text_field_wid2('mfg_part_number'); ?></td>
         <td><?php $f->text_field_wid2('manufacturer'); ?></td>
         <td><?php echo ino_showDecimal($$class_second->minimum_quantity); ?></td>
         <td><?php echo ino_showDecimal($$class_second->maximum_quantity); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <!--</td></tr>-->	
          <?php
          $po_quote_detail_object = [];
          if (!empty($$class_second->po_rfq_line_id)) {

           $rfq_detail_a = po_rfq_detail::find_by_parent_id($$class_second->po_rfq_line_id);
           foreach ($rfq_detail_a as $rfq_detail) {
            $po_quote_detail_value = new po_quote_detail();
            foreach ($rfq_detail as $k => $v) {
             $po_quote_detail_value->$k = $v;
            }
            array_push($po_quote_detail_object, $po_quote_detail_value);
           }
           if (!empty($po_quote_detail_object)) {
            foreach ($po_quote_detail_object as &$po_quote_detail2) {
             $quote_i = po_quote_detail::find_by_lineId_rfqDetailId($$class_second->po_quote_line_id, $po_quote_detail2->po_rfq_detail_id);
             if ($quote_i) {
              foreach ($quote_i as $k => $v) {
               $po_quote_detail2->$k = $v;
              }
             }
            }
           }
          }

          if (count($po_quote_detail_object) == 0) {
           $po_quote_detail = new po_quote_detail();
           $po_quote_detail_object = array();
           array_push($po_quote_detail_object, $po_quote_detail);
          }
          ?>
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Description') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Requirement Id') ?></th>
                  <th><?php echo gettext('Requirement Number') ?></th>
                  <th><?php echo gettext('Requirement Name') ?></th>
                  <th><?php echo gettext('Type') ?></th>
                  <th><?php echo gettext('Max Evaluation Points') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_quote_detail_object as $po_quote_detail) {
                  $class_third = 'po_quote_detail';
                  $$class_third = &$po_quote_detail;
                  ?>
                  <tr class="po_quote_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>
                    <?php
                    echo ino_inline_action($$class_third->po_quote_detail_id, array('po_quote_header_id' => $$class->po_quote_header_id,
                     'po_quote_line_id' => $$class_second->po_quote_line_id, 'po_rfq_detail_id' => $$class_third->po_rfq_detail_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php form::text_field_wid3sr('po_quote_detail_id'); ?></td>
                   <td><?php echo $f->number_field('requirement_number', $$class_third->requirement_number, '', '', 'detail_number', '', 1); ?></td>
                   <td><?php $f->text_field_wid3r('requirement_name'); ?></td>
                   <td><?php echo $f->select_field_from_array('requirement_type', po_rfq_detail::$requirement_type_a, $$class_third->requirement_type, '', '', '', 1, 1); ?></td>
                   <td><?php echo $f->number_field('max_evaludation_points', $$class_third->max_evaludation_points, '', '', '', '', 1); ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Target Value') ?></th>
                  <th><?php echo gettext('Description') ?></th>
                  <th><?php echo gettext('Supplier Value') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_quote_detail_object as $po_quote_detail) {
                  $class_third = 'po_quote_detail';
                  $$class_third = &$po_quote_detail;
                  ?>

                  <tr class="po_quote_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3('target_value'); ?></td>

                   <td><?php
                    echo $f->text_area_ap(array('name' => 'description', 'value' => $$class_third->description,
                     'row_size' => '2', 'column_size' => '35'));
                    ?> 	
                   </td> 
                   <td><?php
                    echo $f->text_area_ap(array('name' => 'requirement_value', 'value' => $$class_third->requirement_value,
                     'row_size' => '2', 'column_size' => '35'));
                    ?> 	
                   </td> 
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
             </div>
            </div>


           </fieldset>

          </div>

         </td>
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
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Unit Price') ?></th>
        <th><?php echo gettext('Target Price') ?></th>
        <th><?php echo gettext('Quote Price') ?></th>
        <th><?php echo gettext('Min Agreement Qty') ?></th>
        <th><?php echo gettext('Min Order Qty') ?>#</th>
        <th><?php echo gettext('Lot Multiplier') ?></th>
        <th><?php echo gettext('Processing LT') ?></th>
        <th><?php echo gettext('Replenishment LT') ?></th>
        <th><?php echo gettext('Daily Capacity') ?></th>
        <th><?php echo gettext('Others') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_quote_line_object as $po_quote_line) {
        ?>         
        <tr class="po_quote_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php
          echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
          ?></td>
         <td><?php echo ino_showDecimal($$class_second->unit_price); ?></td>
         <td><?php echo ino_showDecimal($$class_second->target_price); ?></td>
         <td><?php $f->text_field_wid2s('quote_unit_price'); ?></td>
         <td><?php echo $f->number_field('minimum_agreement_quantity', $$class_second->minimum_agreement_quantity); ?></td>
         <td><?php echo $f->number_field('minimum_order_quantity', $$class_second->minimum_order_quantity); ?></td>
         <td><?php echo $f->number_field('fix_lot_multiplier', $$class_second->fix_lot_multiplier); ?></td>
         <td><?php $f->text_field_wid2s('processing_lead_time'); ?></td>
         <td><?php $f->text_field_wid2s('replenishment_lead_time'); ?></td>
         <td><?php $f->text_field_wid2s('daily_capacity'); ?></td>

         <td><?php
          $stmt = '<a class="button" href="';
          $stmt .= HOME_URL . "form.php?class_name=po_quote_breaks&mode=9&reference_table=po_quote_line&reference_id=" . $$class_second->po_quote_line_id;
          $stmt .= '">Price Break</a>';
//                 echo $stmt;
          echo '<a class="button" href="">Price Break</a>';
          ?>
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
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_quote_header" ></li>
  <li class="lineClassName" data-lineClassName="po_quote_line" ></li>
  <li class="detailClassName" data-detailClassName="po_quote_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_quote_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_quote_header" ></li>
  <li class="line_key_field" data-line_key_field="po_quote_header_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="po_quote_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_quote_header_id" ></li>
  <li class="docLineId" data-docLineId="po_quote_line_id" ></li>
  <li class="docDetailId" data-docDetailId="po_quote_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_quote_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="po_quote_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
