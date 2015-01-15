<form action=""  method="post" id="sd_document_type"  name="sd_document_type"><span class="heading">Document Type </span>
 <div class="large_shadow_box tabContainer">
  <ul class="column header_field"> 
   <li> 
    <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_document_type_id select_popup clickable">
     Document Type Id</label><?php $f->text_field_dsr('sd_document_type_id') ?>
    <a name="show" href="form.php?class_name=sd_document_type&<?php echo "mode=$mode"; ?>" class="show document_id sd_document_type_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
   </li> 
   <li><label>Document Type</label><?php form::text_field_wid('document_type_name'); ?></li>
   <li><label>Description</label><?php $f->text_field_wid('description'); ?> 					</li>
   <li><label>Restrict to BU</label><?php echo form::select_field_from_object('bu_org_id_r', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id_r, 'bu_org_id_r', $readonly, '', ''); ?>   </li>
   <li><label>Level</label><?php echo $f->select_field_from_array('level', sd_document_type::$level_a, $$class->level); ?></li>
  </ul>
 </div>
 <div id ="form_line" class="form_line"><span class="heading">Document Type Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic Info</a></li>
    <li><a href="#tabsLine-2">Defaults</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div> 
      <ul class="column four_column"> 
       <li><label>Type :</label>
        <?php echo $f->select_field_from_array('type', sd_document_type::$type_a, $$class->type); ?>
       </li>
       <li><label>Category :</label>
        <?php echo $f->select_field_from_array('category', sd_document_type::$category_a, $$class->category); ?>
       </li>
       <li><label>Supply Source : </label>
        <?php echo $f->select_field_from_array('supply_source', sd_document_type::$supply_source_a, $$class->supply_source); ?>							 
       </li>
       <li><label>Process Flow :</label>
        <?php $f->text_field_wid('process_flow_id'); ?>
       </li>
      </ul> 
     </div> 
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-2"  class="tabContent">
     <div> 
      <ul class="column four_column"> 
       <li><label>Default Line :</label>
        <?php echo $f->select_field_from_object('default_line_document', sd_document_type::find_all(), 'sd_document_type_id', 'document_type_name', $$class->default_line_document); ?>
       </li>
       <li><label>Price List :</label> 
        <?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>
       </li>
       <li><label>Ship From Org :</label> 
        <?php echo $f->select_field_from_object('default_shipfrom_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->default_shipfrom_org_id, '', '', '', $readonly); ?>
       </li>
       <li><label>Destination Type : </label>
        <?php echo $f->select_field_from_array('destination_type', sd_document_type::$destination_type_a, $$class->destination_type); ?>							 
       </li>

       <li><label>AR Transaction Type :</label> 
        <?php echo $f->select_field_from_object('ar_transaction_type', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->ar_transaction_type, 'ar_transaction_type', '', 1, $readonly); ?>	</li>
       <li><label>AR Transaction Source :</label> <?php $f->text_field_wid('ar_transaction_source'); ?>	</li>
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
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_document_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_document_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_document_type" ></li>
 </ul>
</div>