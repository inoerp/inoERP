<div id='fp_source_list_header_divId'>
 <div id ="form_header"><span class="heading">Source List Header  </span>
  <form action=""  method="post" id="fp_source_list_header"  name="fp_source_list_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="source_list_header_id select_popup clickable">
          Source List Id</label><?php echo $f->text_field_dr('fp_source_list_header_id') ?>
          <a name="show" href="form.php?class_name=fp_source_list_header&<?php echo "mode=$mode"; ?>" class="show document_id fp_source_list_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Inventory Org (1)</label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>        </li>
        <li><label>Type (2)</label><?php echo $f->select_field_from_object('source_list_type', fp_source_list_header::source_list_type(), 'option_line_code', 'option_line_value', $$class->source_list_type, 'source_list_type', '', 1, $readonly); ?>        </li>
        <li><label>Source List (3)</label><?php form::text_field_dm('source_list'); ?></li>
        <li><label>Description</label><?php form::text_field_d('description'); ?></li>
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
         $reference_table = 'fp_source_list_header';
         $reference_id = $$class->fp_source_list_header_id;
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

 <div id="form_line" class="form_line"><span class="heading">Source List Lines </span>
  <form action=""  method="post" id="source_list_line"  name="source_list_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Main</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Line Id</th>
         <th>Type</th>
         <th>Source List</th>
         <th>Comments</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($fp_source_list_line_object as $fp_source_list_line) {
         ?>         
         <tr class="fp_source_list_line<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->fp_source_list_line_id); ?>"></li>           
            <li><?php echo form::hidden_field('fp_source_list_header_id', $$class->fp_source_list_header_id); ?></li>
           </ul>
          </td>
          <td><?php form::text_field_wid2sr('fp_source_list_line_id'); ?></td>
          <td><?php echo $f->select_field_from_object('source_list_line_type', fp_source_list_line::source_list_line_type(), 'option_line_code', 'option_line_value', $$class_second->source_list_line_type, '', '', 1, $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('source_list_id', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class_second->source_list_id, '', '', 1, $readonly); ?></td>
          <td><?php form::text_field_wid2('description'); ?></td>
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
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_source_list_header" ></li>
  <li class="lineClassName" data-lineClassName="fp_source_list_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_source_list_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_source_list_header" ></li>
  <li class="line_key_field" data-line_key_field="source_list_line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fp_source_list_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_source_list_header_id" ></li>
  <li class="docLineId" data-docLineId="fp_source_list_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_source_list_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>