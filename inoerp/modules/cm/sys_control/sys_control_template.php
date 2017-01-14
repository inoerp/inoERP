<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Sales Control') ?></span>
 <form method="post" id="sd_sales_control"  name="sd_sales_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('sd_sales_control_id', $$class->sd_sales_control_id); ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=sd_sales_control&<?php echo "mode=$mode"; ?>" class="show document_id sd_sales_control_id">
      <i class='fa fa-refresh'></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Defaulting Rules') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future Rules') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field two_column_form"> 
        <li><label><?php echo gettext('Price List') ?></label><?php echo $f->select_field_from_object('mdm_price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->mdm_price_list_header_id); ?>        </li>
        <li><label><?php echo gettext('Order Type') ?></label><?php echo $f->select_field_from_object('h_default_document_type_id', sd_document_type::find_all_header_levels($$class->org_id), 'sd_document_type_id', 'document_type_name', $$class->h_default_document_type_id, 'h_default_document_type_id', '', '', $readonly); ?></li>
        <li><label><?php echo gettext('Line Type') ?></label><?php echo $f->select_field_from_object('l_default_document_type_id', sd_document_type::find_all_line_levels($$class->org_id), 'sd_document_type_id', 'document_type_name', $$class->l_default_document_type_id, 'l_default_document_type_id', '', '', $readonly); ?></li>
        <li><label><?php echo gettext('ISO Order Type') ?></label><?php echo $f->select_field_from_object('iso_h_default_document_type_id', sd_document_type::find_all_header_levels($$class->org_id), 'sd_document_type_id', 'document_type_name', $$class->iso_h_default_document_type_id, 'iso_h_default_document_type_id', '', '', $readonly); ?></li>
        <li><label><?php echo gettext('ISO Line Type') ?></label><?php echo $f->select_field_from_object('iso_l_default_document_type_id', sd_document_type::find_all_line_levels($$class->org_id), 'sd_document_type_id', 'document_type_name', $$class->iso_l_default_document_type_id, 'iso_l_default_document_type_id', '', '', $readonly); ?></li>
        <li><label><?php echo gettext('AR Transaction Type') ?></label><?php echo $f->select_field_from_object('ar_transaction_type_id', ar_transaction_type::find_by_ColumnNameVal('bu_org_id', $$class->org_id), 'ar_transaction_type_id', 'ar_transaction_type', $$class->ar_transaction_type_id, 'ar_transaction_type_id', '', '', $readonly); ?>	</li>
        <li><?php $f->l_checkBox_field_d('default_requested_date_cb') ?>  </li>
        <li><?php  $f->l_checkBox_field_d('default_schedule_ship_date_cb') ?></li>
        <li><?php  $f->l_checkBox_field_d('default_promise_date_cb') ?> </li>
        <li><?php  $f->l_checkBox_field_d('deffer_invoicing_cb') ?> </li>

       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column five_column"> 

       </ul> 
      </div> 
     </div>
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sd_sales_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_sales_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_sales_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_sales_control_id" ></li>
 </ul>
</div>