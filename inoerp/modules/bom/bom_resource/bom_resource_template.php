<div id ="form_header">
 <form action=""  method="post" id="bom_resource"  name="bom_resource"><span class="heading">Resources</span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Costing</a></li>
    <li><a href="#tabsHeader-3">OSP</a></li>
    <li><a href="#tabsHeader-4">Employee</a></li>
    <li><a href="#tabsHeader-5">Equipment</a></li>
    <li><a href="#tabsHeader-6">Attachments</a></li>
    <li><a href="#tabsHeader-7">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box">
      <ul class="column header_field">
       <li>
        <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_resource_id select_popup clickable">
         Resource Id</label><?php $f->text_field_dsr('bom_resource_id'); ?>
        <a name="show" href="form.php?class_name=bom_resource&<?php echo "mode=$mode"; ?>" class="show document_id bom_resource_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Inventory</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1); ?>      </li>
       <li><label>Resource</label><?php echo form::text_field_d('resource'); ?> </li>
       <li><label>Description</label><?php echo form::text_field_d('description'); ?></li>
       <li><label>Resource Type</label><?php echo $f->select_field_from_object('resource_type', bom_resource::resource_type(), 'option_line_code', 'option_line_code', $$class->resource_type, '', '', 1, $readonly1); ?>       </li>
       <li><label>Charge Type</label><?php echo $f->select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_code', $$class->charge_type, '', '', 1, $readonly); ?>       </li> 
       <li><label>UOM</label><?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom', '', 1, $readonly1); ?>       </li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
      </ul>
     </div>
    </div>

    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box">
      <ul class="column four_column"> 
       <li><label>Costed : </label>
        <?php echo form::checkBox_field('costed_cb', $$class->costed_cb, 'costed_cb', $readonly); ?>
       </li>
       <li><label>Absorption Ac: </label><?php $f->ac_field_d('absorption_ac_id'); ?></li>
       <li><label>Variance Ac: </label><?php $f->ac_field_d('variance_ac_id'); ?></li>
       <li><label>Standard Rate : </label>
        <?php echo form::checkBox_field('standard_rate_cb', $$class->standard_rate_cb, 'standard_rate_cb', $readonly); ?>
       </li>
      </ul>
     </div>
    </div>

    <div id="tabsHeader-3" class="tabContent">
     <div class="large_shadow_box">
      <ul class="column five_column"> 
       <li><label>OSP Resource : </label> 
        <?php echo form::checkBox_field('osp_cb', $$class->osp_cb, '', $readonly); ?>
       </li>
       <li><label>Item Id : </label><?php $f->text_field_wids('osp_item_id', 'item_id'); ?></li>
       <li><label>Item Number : </label>
        <?php $f->text_field_wid('osp_item_number', 'select_item_number'); ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup">
       </li>
       <li><label>Description: </label><?php $f->text_field_wid('osp_item_description', 'item_description'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="large_shadow_box">

     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div class="large_shadow_box">

     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'bom_resource';
        $reference_id = $$class->bom_resource_id;
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

<div id="form_line" class="form_line"><span class="heading">Resource Cost Lines </span>
 <form action=""  method="post" id="bom_resource_cost"  name="bom_resource_cost">
  <div id="tabsLine">
   <div class="tabContainer">
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th>Action</th>
       <th>Seq#</th>
       <th>Resource Cost Id</th>
       <th>Cost Type</th>
       <th>Description</th>
       <th>Rate</th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      $count = 0;
      foreach ($bom_resource_cost_object as $bom_resource_cost) {
       if (!empty($bom_resource_cost->bom_cost_type)) {
        $bcy = new bom_cost_type();
        $bcy_i = $bcy->find_by_keyColumn($bom_resource_cost->bom_cost_type);
        $bom_resource_cost->bom_cost_type_description = $bcy_i->description;
       } else {
        $bom_resource_cost->bom_cost_type_description = null;
       }
       ?>         
       <tr class="bom_resource_cost<?php echo $count ?>">
        <td>    
         <ul class="inline_action">
          <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
          <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
          <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->bom_resource_cost_id); ?>"></li>           
          <li><?php echo form::hidden_field('bom_resource_id', $$class->bom_resource_id); ?></li>
         </ul>
        </td>
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php form::text_field_wid2sr('bom_resource_cost_id'); ?></td>
        <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->bom_cost_type, '', '', 1, $readonly); ?></td>
        <td><?php $f->text_field_wid2r('bom_cost_type_description'); ?></td>
        <td><?php echo $f->number_field('resource_rate', $$class_second->resource_rate); ?></td>
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
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_resource" ></li>
  <li class="lineClassName" data-lineClassName="bom_resource_cost" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_resource_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_resource" ></li>
  <li class="line_key_field" data-line_key_field="bom_cost_type" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="bom_resource_cost" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_resource_id" ></li>
  <li class="docLineId" data-docLineId="bom_resource_cost_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_resource" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-doctrClass="bom_resource_cost" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>