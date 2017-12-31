<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form action=""  method="post" id="hr_perdiem_rate_line"  name="perdiem_rate_line">
    <span class="heading"><?php echo gettext('Per Diem Rate') ?></span>
    <div id="form_serach_header" class="tabContainer">
     <?php echo $f->select_field_from_object('hr_location_id',  hr_location::find_all(), 'hr_location_id', 'combination', $hr_location_id_h, 'hr_location_id', 'action'); ?>
     <a name="show" href="form.php?class_name=hr_perdiem_rate&<?php echo "mode=$mode"; ?>" class="show document_id hr_perdiem_rate_id action">
      <i class="fa fa-refresh"></i></a> 
    </div>
    <div id ="form_line" class="hr_perdiem_rate">
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Grade') ?></th>
           <th><?php echo gettext('Currency') ?></th>
           <th><?php echo gettext('Rate') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('From Date') ?></th>
           <th><?php echo gettext('To Date') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody perdiem_rate_values" >
          <?php
          $count = 0;
          $perdiem_rate_object_ai = new ArrayIterator($perdiem_rate_object);
          $perdiem_rate_object_ai->seek($position);
          while ($perdiem_rate_object_ai->valid()) {
           $hr_perdiem_rate = $perdiem_rate_object_ai->current();
           ?>         
           <tr class="hr_perdiem_rate<?php echo $count ?>">
            <td><?php
             echo ino_inline_action($$class->hr_perdiem_rate_id, array('hr_location_id' => $hr_location_id_h));
             ?>    
            </td>
            <td><?php $f->text_field_widr('hr_perdiem_rate_id') ?></td>
            <td><?php echo $f->select_field_from_object('hr_grade_id', hr_grade::find_all(), 'hr_grade_id', 'grade', $$class->hr_grade_id, '', 'medium'); ?></td>
            <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, '', 'medium currency', 1, $readonly); ?></td>
            <td><?php echo $f->number_field('rate', $$class->rate,'','','',1) ?></td>
            <td><?php $f->text_field_wid('description'); ?></td>
            <td><?php echo $f->date_fieldAnyDay_m('from_date', $$class->from_date, false); ?></td>
            <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
           </tr>
           <?php
           $perdiem_rate_object_ai->next();
           if ($perdiem_rate_object_ai->key() == $position + $per_page) {
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
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="hr_location_id" ></li>
  <li class="lineClassName" data-lineClassName="hr_perdiem_rate" ></li>
  <li class="line_key_field" data-line_key_field="perdiem_rate" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_perdiem_rate" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_perdiem_rate_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_perdiem_rate" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
