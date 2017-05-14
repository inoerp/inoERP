<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header">
 <span class="heading"><?php echo gettext('Delivery Header') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
   <li><a href="#tabsHeader-3"><?php echo gettext('Actions') ?></a></li>
   <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
  </ul>
  <div class="tabContainer">
   <form method="post" id="sd_delivery_header"  name="sd_delivery_header">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('sd_delivery_header_id'); ?>
       <a name="show" href="form.php?class_name=sd_delivery_header&<?php echo "mode=$mode"; ?>" class="show document_id sd_delivery_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->shipping_org_id, '', '', 1, $readonly1); ?>       </li>
      <li><?php $f->l_text_field_d('delivery_number'); ?></li>
      <li><?php $f->l_select_field_from_array('status', sd_delivery_header::$status_a, $$class->status, '', '', 1, 1, 1) ?>       </li>
      <li><?php $f->l_date_fieldFromToday('delivery_date', ino_date($$class->delivery_date)); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
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
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><label><?php echo gettext('Action') ?></label>
        <?php
        if ($$class->status == 'SHIPPED') {
         $$class->action_a = [];
         $$class->action_a['REMOVE_LINE'] = 'Remove Line';
         $$class->action_a['STATUS_AWAITING_SHIPPING'] = 'Reverse Status';
        }
        echo $f->select_field_from_array('action', $$class->action_a, '', 'action')
        ?>
       </li>
       <li><label></label><a  role="button" class="quick_select button btn btn-info" target="_blank" 
       href="<?php echo HOME_URL ?>form.php?class_name=sd_delivery_all_v&amp;router=pdf_print&amp;sd_delivery_header_id=<?php echo!(empty($$class->sd_delivery_header_id)) ? $$class->sd_delivery_header_id : ""; ?>" >
         <?php echo gettext('Print Delivery') ?></a></li>
      </ul>
     </div>
    </div>
   </form>		
   <div id="tabsHeader-4" class="tabContent">
    <div> 
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <?php
      $reference_table = 'sd_delivery_header';
      $reference_id = $$class->sd_delivery_header_id;
      include_once WWW_DIR . '/comment.php';
      ?>
      <div id="new_comment">
      </div>
     </div>
    </div>
   </div>
  </div>
 </div>

</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Delivery Lines') ?></span>
 <form  method="post" id="sd_delivery_line"  name="sd_delivery_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('SO Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Delivery') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Customer') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('References') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><label class="ino-label"><?php echo gettext('Delivery Line Id') ?></label></th>
        <th><?php echo gettext('SO Id') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('SO') ?>#</th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Shipment Qty') ?></th>
        <th><?php echo gettext('Shipped Qty') ?></th>
        <th><?php echo gettext('SO Qty Change') ?></th>
        <th><?php echo gettext('Delivery Status') ?></th>
        <th><?php echo gettext('Line Action') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;  
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        $f->readonly2 = !empty($sd_delivery_line->sd_delivery_line_id) ? true : false;
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($sd_delivery_line->sd_delivery_line_id, array('sd_delivery_header_id' => $$class->sd_delivery_header_id,
           'shipping_org_id' => $$class->shipping_org_id, 'transaction_type_id' => $$class->transaction_type_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('sd_delivery_line_id'); ?>
          <i class="select_delivery_line select_popup clickable fa fa-search"></i></td>
         <td><?php $f->text_field_wid2sr('sd_so_header_id' , 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2sr('sd_so_line_id' , 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2sr('so_number', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2sr('so_line_number' , 'always_readonly'); ?></td>
         <td><?php echo $f->number_field('quantity', $sd_delivery_line->quantity); ?></td>
         <td><?php echo $f->number_field('shipped_quantity', $sd_delivery_line->shipped_quantity, '8', '', 'always_readonly', '', 1); ?></td>
         <td><?php echo $f->number_field('so_qty_change', '', '', '', 'small', '', 1); ?></td>
         <td><?php $f->text_field_wid2r('delivery_status' ,'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2r('action' ,'always_readonly'); ?></td>
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
        <th><?php echo gettext('Item Id') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Subinventory') ?></th>
        <th><?php echo gettext('Locator') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php $f->text_field_wid2sr('item_id_m' ,'always_readonly'); ?></td>
         <td><?php $f->text_field_d2s('item_number' ,'always_readonly'); ?></td>
         <td><?php $f->text_field_d2('item_description' ,'always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_object('line_uom_id', uom::find_all(), 'uom_id', 'uom_name', $sd_delivery_line->line_uom_id, '', '', '', $readonly1); ?></td>
         <td><?php echo $f->select_field_from_object('staging_subinventory_id', subinventory::find_all_of_org_id($$class->shipping_org_id), 'subinventory_id', 'subinventory', $$class_second->staging_subinventory_id, '', 'subinventory_id', '', $readonly1); ?></td>
         <td><?php echo $f->select_field_from_object('staging_locator_id', locator::find_all_of_subinventory($$class_second->staging_subinventory_id), 'locator_id', 'locator', $$class_second->staging_locator_id, '', 'locator_id', '', $readonly1); ?></td>
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
        <th><?php echo gettext('Customer Id') ?></th>
        <th><?php echo gettext('Customer Number') ?></th>
        <th><?php echo gettext('Customer Name') ?></th>
        <th><?php echo gettext('Site Id') ?></th>
        <th><?php echo gettext('Site Number') ?></th>
        <th><?php echo gettext('Site Name') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php form::text_field_wid2r('ar_customer_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_number'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_name'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_number'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_name'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->

     </table>
    </div>

    <div id="tabsLine-4" class="form_data_line_tbody">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Weight UOM') ?></th>
        <th><?php echo gettext('Total Weight') ?></th>
        <th><?php echo gettext('Volume UOM') ?></th>
        <th><?php echo gettext('Total Volume') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php echo form::select_field_from_object('weight_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->weight_uom_id, 'weight_uom_id', $readonly); ?></td>
         <td><?php echo form::number_field_wid2('total_weight'); ?></td>
         <td><?php echo form::select_field_from_object('volume_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->volume_uom_id, 'volume_uom_id', $readonly); ?></td>
         <td><?php echo form::number_field_wid2('total_volume'); ?></td>
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
  <li class="headerClassName" data-headerClassName="sd_delivery_header" ></li>
  <li class="lineClassName" data-lineClassName="sd_delivery_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_delivery_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_delivery_header" ></li>
  <li class="line_key_field" data-line_key_field="sd_so_line_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sd_delivery_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_delivery_header_id" ></li>
  <li class="docLineId" data-docLineId="sd_delivery_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_delivery_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
