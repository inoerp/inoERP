<div id="form_all">
 <div id="form_headerDiv">
  <form  method="post" id="lms_student_education_line"  name="student_education_line">
   <span class="heading"><?php echo gettext('Student Education') ?></span>
   <div class="tabContainer">
    <label><?php echo gettext('Student Name') ?></label>
    <?php echo $f->select_field_from_object('lms_student_id', lms_student::find_all(), 'lms_student_id', array('first_name', 'last_name'), $lms_student_id_h, 'lms_student_id', 'medium'); ?>
    <a name="show" href="form.php?class_name=lms_student_education&<?php echo "mode=$mode"; ?>" class="show document_id lms_student_id">
     <i class="fa fa-refresh"></i></a> 
   </div>
   <div id ="form_line" class="lms_student_education">
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Details Info') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Degree Name') ?></th>
          <th><?php echo gettext('University') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
          <th><?php echo gettext('Mode') ?></th>
          <th><?php echo gettext('Percentage') ?></th>
          <th><?php echo gettext('Grade') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody student_education_values" >
         <?php
         $count = 0;
         $student_education_object_ai = new ArrayIterator($student_education_object);
         $student_education_object_ai->seek($position);
         while ($student_education_object_ai->valid()) {
          $lms_student_education = $student_education_object_ai->current();
          ?>         
          <tr class="lms_student_education<?php echo $count ?>">
           <td>
            <?php
            echo ino_inline_action($$class->lms_student_education_id, array('lms_student_id' => $lms_student_id_h));
            ?>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_widsr('lms_student_education_id' , 'always_readonly') ?></td>
           <td><?php $f->text_field_widm('degree_name'); ?></td>
           <td><?php $f->text_field_widm('university'); ?></td>
           <td><?php echo $f->date_fieldAnyDay('edu_start_date', $$class->edu_start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('edu_end_date', $$class->edu_end_date); ?></td>
           <td><?php $f->text_field_wid('mode_of_education'); ?></td>
           <td><?php $f->text_field_wids('marks_percentage'); ?></td>
           <td><?php $f->text_field_wids('grade'); ?></td>
          </tr>
          <?php
          $student_education_object_ai->next();
          if ($student_education_object_ai->key() == $position + $per_page) {
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
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Specialization') ?></th>
          <th><?php echo gettext('University Address') ?>#</th>
          <th><?php echo gettext('Notes') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody student_education_values" >
         <?php
         $count = 0;
         $student_education_object_ai = new ArrayIterator($student_education_object);
         $student_education_object_ai->seek($position);
         while ($student_education_object_ai->valid()) {
          $lms_student_education = $student_education_object_ai->current();
          ?>         
          <tr class="lms_student_education<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_wid('specialization'); ?></td>
           <td><?php $f->text_field_widl('university_address'); ?></td>
           <td><?php
            echo $f->text_area_ap(array('name' => 'comments', 'value' => $$class->comments,
             'row_size' => '1', 'column_size' => '60'));
            ?> 	
           </td> 
          </tr>
          <?php
          $student_education_object_ai->next();
          if ($student_education_object_ai->key() == $position + $per_page) {
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="lms_student_id" ></li>
  <li class="lineClassName" data-lineClassName="lms_student_education" ></li>
  <li class="line_key_field" data-line_key_field="degree_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="lms_student_education" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="lms_student_education_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="lms_student_education" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>