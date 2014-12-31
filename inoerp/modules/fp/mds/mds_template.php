<div id='fp_mds_header_divId'>
 <div id ="form_header"><span class="heading">MDS Header  </span>
  <form action=""  method="post" id="fp_mds_header"  name="fp_mds_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
     <li><a href="#tabsHeader-4">Actions</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mds_header_id select_popup clickable">
          MDS Id</label><?php echo $f->text_field_dsr('fp_mds_header_id') ?>
         <a name="show" href="form.php?class_name=fp_mds_header&<?php echo "mode=$mode"; ?>" class="show document_id fp_mds_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Inventory Org (1)</label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>        </li>
        <li><label>MDS (2)</label><?php form::text_field_dm('mds_name'); ?></li>
        <li><label>Description</label><?php form::text_field_dm('description'); ?></li>
        <li><label>Source List (3)</label><?php echo $f->select_field_from_object('fp_source_list_header_id', fp_source_list_header::find_all_demandPlan(), 'fp_source_list_header_id', 'source_list', $$class->fp_source_list_header_id, '', '', 1, $readonly); ?>        </li>
        <li><label>Include SO</label><?php echo $f->checkBox_field_d('include_so_cb'); ?></li>
        <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
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
         $reference_table = 'fp_mds_header';
         $reference_id = $$class->fp_mds_header_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <ul class="column five_column">
        <li><label>Action</label>
         <select name="mds_action[]" class=" select  mds_action" id="mds_action" >
          <option value="" ></option>
          <option value="LOAD_MDS" >Load MDS</option>
         </select>
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

 <div id="form_line" class="form_line"><span class="heading">MDS Lines </span>
  <form action=""  method="post" id="mds_line"  name="mds_line">
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
         <th>Seq#</th>
         <th>Line Id</th>
         <th>Item Id</th>
         <th>Item Number</th>
         <th>Date</th>
         <th>Source Type</th>
         <th>Source Header</th>
         <th>Source Line</th>
         <th>Quantity</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        $fp_mds_line_object_ai = new ArrayIterator($fp_mds_line_object);
        $fp_mds_line_object_ai->seek($position);
        while ($fp_mds_line_object_ai->valid()) {
         $fp_mds_line = $fp_mds_line_object_ai->current();
         if (!empty($fp_mds_line->item_id_m)) {
          $item_i = item::find_by_id($fp_mds_line->item_id_m);
          $fp_mds_line->item_number = $item_i->item_number;
         } else {
          $fp_mds_line->item_number = null;
         }
         ?>         
         <tr class="fp_mds_line<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->fp_mds_line_id); ?>"></li>           
            <li><?php echo form::hidden_field('fp_mds_header_id', $$class->fp_mds_header_id); ?></li>
           </ul>
          </td>
          <td><?php $f->seq_field_d($count); ?></td>
          <td><?php form::text_field_wid2sr('fp_mds_line_id'); ?></td>
          <td><?php form::text_field_wid2sr('item_id_m'); ?></td>
          <td><?php form::text_field_wid2('item_number', 'select_item_number'); ?>
           <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
          <td><?php echo $f->date_fieldAnyDay('demand_date', $$class_second->demand_date); ?></td>
          <td><?php $f->text_field_wid2s('source_type'); ?></td>
          <td><?php $f->text_field_wid2s('source_header_id'); ?></td>
          <td><?php $f->text_field_wid2s('source_line_id'); ?></td>
          <td><?php echo $f->number_field('quantity', $$class_second->quantity); ?></td>
         </tr>
         <?php
         $fp_mds_line_object_ai->next();
         if ($fp_mds_line_object_ai->key() == $position + $per_page) {
          break;
         }
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

</div>


<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_mds_header" ></li>
  <li class="lineClassName" data-lineClassName="fp_mds_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_mds_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_mds_header" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fp_mds_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_mds_header_id" ></li>
  <li class="docLineId" data-docLineId="fp_mds_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_mds_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>