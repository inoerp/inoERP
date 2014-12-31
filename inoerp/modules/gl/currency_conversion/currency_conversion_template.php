<form action=""  method="post" id="gl_currency_conversion_line"  name="currency_conversion_line"><span class="heading">Currency Conversions</span>
 <div id="form_serach_header">
  <label>Conversion Type :</label>
  <?php echo $f->select_field_from_object('currency_conversion_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_value', $currency_conversion_type_h, 'currency_conversion_type', '', 1); ?>
  <a name="show" href="form.php?class_name=gl_currency_conversion&<?php echo "mode=$mode"; ?>" class="show document_id gl_currency_conversion_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 

 </div> 
 <div id ="form_line" class="gl_currency_conversion"><span class="heading">Region Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Rates </a></li>
    <li><a href="#tabsLine-2">Future </a></li>
   </ul>
   <div class="tabContainer"> 

    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Id</th>
        <th>From Currency</th>
        <th>To Currency</th>
        <th>Start Date</th>
        <th>End Date</th>
        <th>Rate</th>
        <th>Use Reverse Conversion</th>
        <th>Description</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody currency_conversion_values" >
       <?php
       $count = 0;
       $currency_conversion_object_ai = new ArrayIterator($currency_conversion_object);
       $currency_conversion_object_ai->seek($position);
       while ($currency_conversion_object_ai->valid()) {
        $gl_currency_conversion = $currency_conversion_object_ai->current();
        if (empty($gl_currency_conversion->currency_conversion_type)) {
         $gl_currency_conversion->currency_conversion_type = $currency_conversion_type_h;
        }
        ?>         
        <tr class="gl_currency_conversion<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->gl_currency_conversion_id); ?>"></li>           
           <li><?php echo form::hidden_field('currency_conversion_type', $currency_conversion_type_h); ?></li>
          </ul>
         </td>
         <td><?php $f->text_field_dsr('gl_currency_conversion_id') ?></td>
         <td><?php echo $f->select_field_from_object('from_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->from_currency, '', 'currency', 1); ?></td>
         <td><?php echo $f->select_field_from_object('to_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->to_currency, '', 'currency', 1); ?></td>
         <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
         <td><?php echo $f->number_field('rate', $$class->rate); ?></td>
         <td><?php $f->checkBox_field_wid('use_reverse_conversion'); ?></td>
         <td><?php $f->text_field_widl('description'); ?></td>
        </tr>
        <?php
        $currency_conversion_object_ai->next();
        if ($currency_conversion_object_ai->key() == $position + $per_page) {
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
   </div>

  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="gl_currency_conversion" ></li>
  <li class="line_key_field" data-line_key_field="rate" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_currency_conversion" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="gl_currency_conversion_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="currency_conversion_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>