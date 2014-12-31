<div id="form_all"><span class="heading">Tax Regions</span>
 <div id="form_headerDiv">
  <form action=""  method="post" id="mdm_tax_region_line"  name="tax_region_line">
   <div id="form_serach_header">
    <label>Country :</label>
    <?php echo form::select_field_from_object('country_code', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $country_code_h, 'country_code', $readonly1); ?>
    <a name="show" href="form.php?class_name=mdm_tax_region&<?php echo "mode=$mode"; ?>" class="show document_id mdm_tax_region_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
   </div>
   <div id ="form_line" class="mdm_tax_region">
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1">Location </a></li>
      <li><a href="#tabsLine-2">Reporting </a></li>
     </ul>
     <div class="tabContainer"> 

      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Action</th>
          <th>Seq#</th>
          <th>Id</th>
          <th>Country Code</th>
          <th>State</th>
          <th>City</th>
          <th>Region Name</th>
          <th>Description</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody tax_region_values" >
         <?php
         $count = 0;
         $tax_region_object_ai = new ArrayIterator($tax_region_object);
         $tax_region_object_ai->seek($position);
         while ($tax_region_object_ai->valid()) {
          $mdm_tax_region = $tax_region_object_ai->current();
          if (empty($mdm_tax_region->country_code)) {
           $mdm_tax_region->country_code = $country_code_h;
          }
          ?>         
          <tr class="mdm_tax_region<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
             <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->mdm_tax_region_id); ?>"></li>           
             <li><?php echo form::hidden_field('country_code', $country_code_h); ?></li>
            </ul>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php form::number_field_drs('mdm_tax_region_id') ?></td>
           <td><?php $f->text_field_widrm('country_code', 'line_data'); ?></td>
           <td><?php $f->text_field_wid('state', 'dontCopy'); ?></td>
           <td><?php $f->text_field_wid('city', 'dontCopy'); ?></td>
           <td><?php $f->text_field_wid('tax_region_name', 'dontCopy'); ?></td>
           <td><?php $f->text_field_wid('description', 'dontCopy'); ?></td>
          </tr>
          <?php
          $tax_region_object_ai->next();
          if ($tax_region_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Seq#</th>
          <th>Status</th>
          <th>Regime</th>
          <th>Jurisdiction</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody tax_region_values" >
         <?php
         $count = 0;
         $tax_region_object_ai = new ArrayIterator($tax_region_object);
         $tax_region_object_ai->seek($position);
         while ($tax_region_object_ai->valid()) {
          $mdm_tax_region = $tax_region_object_ai->current();
          ?>         
          <tr class="mdm_tax_region<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->status_field_d('status'); ?></td>
           <td><?php form::text_field_wid('tax_regime'); ?></td>
           <td><?php form::text_field_wid('tax_jurisdiction'); ?></td>
          </tr>
          <?php
          $tax_region_object_ai->next();
          if ($tax_region_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>

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
  <li class="lineClassName" data-lineClassName="mdm_tax_region" ></li>
  <li class="line_key_field" data-line_key_field="tax_region_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="mdm_tax_region" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="mdm_tax_region_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="mdm_tax_region" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>