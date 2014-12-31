<div id ="form_header"><span class="heading">Sourcing Rule Header</span>
 <form action=""  method="post" id="po_sourcing_rule_header"  name="po_sourcing_rule_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Attachments</a></li>
    <li><a href="#tabsHeader-3">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sourcing_rule_header_id select_popup clickable">
         Sourcing Rule Id : </label>
        <?php echo $f->text_field_dr('po_sourcing_rule_header_id') ?>
        <a name="show" href="form.php?class_name=po_sourcing_rule_header&<?php echo "mode=$mode"; ?>" class="show document_id po_sourcing_rule_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Sourcing Rule : </label>
        <?php form::text_field_dm('sourcing_rule'); ?>
       </li>
       <li><label>Description: </label>
        <?php form::text_field_dm('description'); ?>
       </li>
       <li><label>Status : </label>                      
        <?php echo form::status_field($$class->status, $readonly); ?>
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'po_sourcing_rule_header';
        $reference_id = $$class->po_sourcing_rule_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading">Sourcing Lines </span>
 <form action=""  method="post" id="sourcing_rule_line"  name="sourcing_rule_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Future</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Sourcing Line Id</th>
        <th>Source Type</th>
        <th>Rank</th>
        <th>Allocation % </th>
        <th>Org</th>
        <th>Supplier Id</th>
        <th>Supplier Name</th>
        <th>Supplier Site</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_sourcing_rule_line_object as $po_sourcing_rule_line) {
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
        <tr class="po_sourcing_rule_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->po_sourcing_rule_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('po_sourcing_rule_header_id', $$class->po_sourcing_rule_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid2sr('po_sourcing_rule_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('sourcing_type', po_sourcing_rule_line::po_sourcing_type(), 'option_line_code', 'option_line_value', $$class_second->sourcing_type, 'sourcing_type', '', 1, $readonly); ?></td>
         <td><?php $f->text_field_d2s('rank'); ?></td>
         <td><?php $f->text_field_d2s('allocation'); ?></td>
         <td><?php echo form::select_field_from_object('source_from_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->source_from_org_id, 'source_from_org_id', $readonly); ?></td>
         <td><?php $f->text_field_wid2sr('supplier_id'); ?></td>
         <td><?php $f->text_field_wid2('supplier_name', 'select_supplier_name'); ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_supplier_name select_popup clickable"></td>
         <td><?php echo $supplier_site_name_statement; ?></td>
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
  <li class="headerClassName" data-headerClassName="po_sourcing_rule_header" ></li>
  <li class="lineClassName" data-lineClassName="po_sourcing_rule_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_sourcing_rule_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_sourcing_rule_header" ></li>
  <li class="line_key_field" data-line_key_field="rank" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="po_sourcing_rule_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_sourcing_rule_header_id" ></li>
  <li class="docLineId" data-docLineId="po_sourcing_rule_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_sourcing_rule_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>