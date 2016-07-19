<div class="row small-left-padding">
 <form  method="post" id="gl_currency_conversion_line"  name="currency_conversion_line">
  <span class="heading"><?php echo gettext('Currency Conversions') ?></span>
  <div id="form_serach_header" class="tabContainer">
   <?php $f->l_select_field_from_object('currency_conversion_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_value', $currency_conversion_type_h, 'currency_conversion_type', '', 1); ?>
   <a name="show" href="form.php?class_name=gl_currency_conversion&<?php echo "mode=$mode"; ?>" class="show document_id gl_currency_conversion_id">
    <i class="fa fa-refresh"></i></a> 
  </div> 
  <div id ="form_line" class="gl_currency_conversion"><span class="heading">
    <?php echo gettext('Conversion Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Rates') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Id') ?>#</th>
         <th><?php echo gettext('From Currency') ?></th>
         <th><?php echo gettext('To Currency') ?>#</th>
         <th><?php echo gettext('Start Date') ?></th>
         <th><?php echo gettext('End Date') ?></th>
         <th><?php echo gettext('Rate') ?></th>
         <th><?php echo gettext('Use Reverse Conversion') ?></th>
         <th><?php echo gettext('Description') ?></th>
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
           <?php
           echo ino_inline_action($$class->gl_currency_conversion_id, array('currency_conversion_type' => $currency_conversion_type_h));
           ?>
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
    </div>

   </div>
  </div> 
 </form>
</div>

<div class="row small-top-margin">
 <div id="pagination">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="currency_conversion_type" ></li>
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