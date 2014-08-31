<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="asl_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading">Approved Supplier List </span>
       <form action=""  method="post" id="asl_header"  name="asl_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="asl_header_id select_popup clickable">
               ASL Id : </label>
              <?php echo $f->text_field_dr('po_asl_header_id') ?>
              <a name="show" href="form.php?class_name=po_asl_header" class="show po_asl_header_id">	
               <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
             </li>
             <li><label>BU Name(1) : </label>
              <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>ASL Type : </label>
              <?php echo $f->select_field_from_array('asl_type', po_asl_header::$asl_type_a, $$class->asl_type, 'asl_type', '', 1, $readonly1, $readonly1); ?>
             </li>
             <li><label>Item : </label><?php
               echo $f->hidden_field('item_id_m', $$class->item_id_m);
               echo $f->text_field_d('item_number', 'select_item_number');
              ?>
              <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></li>
             <li><label>Description: </label>    <?php $f->text_field_d('description', 'item_description'); ?>     </li>
            </ul>
           </div>
          </div>
         </div>

        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">ASL Lines </span>
       <form action=""  method="post" id="asl_line"  name="asl_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Others</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Seq#</th>
              <th>Line Id</th>
              <th>Supplier Id</th>
              <th>Supplier Name</th>
              <th>Supplier Site</th>
              <th>Status</th>
              <th>Manufacturer</th>
              <th>MPN </th>
              <th>Comment</th>
              <th>Documents</th>
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
               <tr class="asl_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->po_asl_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('po_asl_header_id', $$class->po_asl_header_id); ?></li>
                 </ul>
                </td>
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php form::text_field_wid2sr('po_asl_line_id'); ?></td>
                <td><?php $f->text_field_wid2sr('supplier_id'); ?></td>
                <td><?php $f->text_field_wid2('supplier_name', 'select_supplier_name'); ?>
                 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_supplier_name select_popup clickable"></td>
                <td><?php echo $supplier_site_name_statement; ?></td>
                <td><?php $f->status_field_d2('status'); ?></td>
                <td><?php $f->text_field_wid2('manufacturer'); ?></td>
                <td><?php $f->text_field_wid2('mfg_part_number'); ?></td>
                <td><?php $f->text_field_d2l('description'); ?></td>
                <td><a href="form.php?class_name=po_asl_document&mode=9&po_asl_line_id=<?php echo $$class_second->po_asl_line_id ;?>">View/Update</a></td>
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
              <th>Seq#</th>
              <th>Release Method</th>
              <th>Min Order Qty</th>
              <th>Lot Multiplier</th>
              <th>Country of Origin</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($po_asl_line_object as $po_asl_line) {
               ?>         
               <tr class="asl_line<?php echo $count ?>">
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

      <!--END OF FORM HEADER-->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

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

<?php include_template('footer.inc') ?>
