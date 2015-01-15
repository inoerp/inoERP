<div id="form_all">
 <form action=""  method="post" id="fa_depreciation_method"  name="fa_depreciation_method"><span class="heading">Depreciation Method</span>
  <div id ="form_header">
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
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fa_depreciation_method_id select_popup clickable">
          Method Id</label><?php echo form::number_field_drs('fa_depreciation_method_id'); ?>
         <a name="show" href="form.php?class_name=fa_depreciation_method&<?php echo "mode=$mode"; ?>" class="show document_id fa_depreciation_method_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Method Name</label><?php echo$f->text_field_dm('depreciation_method'); ?> </li>
        <li><label>Type</label><?php echo $f->select_field_from_array('method_type', fa_depreciation_method::$method_type_a, $$class->method_type, 'method_type', '', 1, $readonly1); ?></li>
        <li><label>Calculation Basis</label><?php echo $f->select_field_from_array('calculation_basis', fa_depreciation_method::$calculation_basis_a, $$class->calculation_basis, 'calculation_basis', '', 1, $readonly1); ?></li>
        <li><label>Description</label><?php echo form::text_field_dm('description'); ?></li>
        <li><label>Life in Months</label><?php echo $f->text_field_dm('life_month'); ?> </li>
        <li><label>Status</label><?php echo $f->select_field_from_array('status', fa_depreciation_method::$status_a,$$class->status,'status','',1,1,1); ?> </li>
        <li><label>Validate</label><?php echo $f->checkBox_field('validate_cb', $$class->validate_cb); ?> </li>
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
         $reference_table = 'fa_depreciation_method';
         $reference_id = $$class->fa_depreciation_method_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>
 </form>
 <div id ="form_line" class="form_line"><span class="heading">Depreciation Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Rates</a></li>
    <li><a href="#tabsLine-2">Calculation</a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="fa_depreciation_method_rate_line"  name="fa_depreciation_method_rate_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Line Id</th>
         <th>Year</th>
         <th>Period</th>
         <th>Rate Percentage</th>
         <th>Description</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody fa_depreciation_method_rate_values" >
        <?php
        $count = 0;
        $fa_depreciation_method_rate_object_ai = new ArrayIterator($fa_depreciation_method_rate_object);
        $fa_depreciation_method_rate_object_ai->seek($position);
        while ($fa_depreciation_method_rate_object_ai->valid()) {
         $fa_depreciation_method_rate = $fa_depreciation_method_rate_object_ai->current();
         ?>         
         <tr class="fa_depreciation_method_rate<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($fa_depreciation_method_rate->fa_depreciation_method_rate_id); ?>"></li>           
            <li><?php echo form::hidden_field('fa_depreciation_method_id', $$class->fa_depreciation_method_id); ?></li>
           </ul>
          </td>
          <td><?php form::number_field_wid2sr('fa_depreciation_method_rate_id'); ?></td>
          <td><?php form::number_field_wid2('year'); ?></td>
          <td><?php form::number_field_wid2('period'); ?></td>
          <td><?php form::number_field_wid2('rate'); ?></td>
          <td><?php form::number_field_wid2('description'); ?></td>
         </tr>
         <?php
         $fa_depreciation_method_rate_object_ai->next();
         if ($fa_depreciation_method_rate_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">

     </div>
    </form>
   </div>

  </div>
 </div> 
</div>


<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_depreciation_method" ></li>
  <li class="lineClassName" data-lineClassName="fa_depreciation_method_rate" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_depreciation_method_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_depreciation_method" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fa_depreciation_method_rate" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_depreciation_method_id" ></li>
  <li class="docLineId" data-docLineId="fa_depreciation_method_rate_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_depreciation_method" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_depreciation_method_rate" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>