<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<form  method="post" id="sd_document_type"  name="sd_document_type" class="form_header_l">
 <span class="heading"><?php echo gettext('Sales Document Type') ?></span>
 <div class="large_shadow_box tabContainer">
  <ul class="column header_field"> 
   <li><?php $f->l_text_field_dr_withSearch('sd_document_type_id') ?>
    <a name="show" href="form.php?class_name=sd_document_type&<?php echo "mode=$mode"; ?>" class="show document_id sd_document_type_id"><i class="fa fa-refresh"></i></a> 
   </li> 
   <li><?php $f->l_text_field_d('document_type_name'); ?></li>
   <li><?php $f->l_text_field_d('description'); ?> 					</li>
   <li><?php $f->l_select_field_from_object('bu_org_id_r', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id_r, 'bu_org_id_r', '', '', $readonly); ?>   </li>
   <li><?php $f->l_select_field_from_array('level', sd_document_type::$level_a, $$class->level); ?></li>
  </ul>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Document Type Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Defaults') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_array('type', sd_document_type::$type_a, $$class->type); ?> </li>
       <li><?php $f->l_select_field_from_array('category', sd_document_type::$category_a, $$class->category); ?></li>
       <li><?php $f->l_select_field_from_array('supply_source', sd_document_type::$supply_source_a, $$class->supply_source); ?>       </li>
       <li><?php $f->l_select_field_from_object('process_flow_id', sys_process_flow_header::find_by_type(), 'sys_process_flow_header_id', 'process_flow', $$class->process_flow_id); ?>       </li>
      </ul> 
     </div> 
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-2"  class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('default_line_document', sd_document_type::find_all(), 'sd_document_type_id', 'document_type_name', $$class->default_line_document); ?>       </li>
       <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>       </li>
       <li><?php $f->l_select_field_from_object('default_shipfrom_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->default_shipfrom_org_id, '', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_array('destination_type', sd_document_type::$destination_type_a, $$class->destination_type); ?>							        </li>
       <li><?php $f->l_select_field_from_object('ar_transaction_type', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->ar_transaction_type, 'ar_transaction_type', '', 1, $readonly); ?>	</li>       
       <li><?php $f->l_text_field_d('ar_transaction_source'); ?>	</li>
      </ul> 
     </div> 
    </div>
    <!--end of tab5-->
   </div>

  </div> 
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sd_document_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_document_type_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_document_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_document_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_document_type" ></li>
 </ul>
</div>