<div id="hr_location_divId" class="pagination_page">
 <div class='row small-left-padding'>
  <div id="form_header">
   <span class="heading"><?php echo gettext('HR Locations') ?></span> 
  </div>
  <div id ="form_line" class="hr_location">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Location Details') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <form method="post" id="hr_location_line"  name="hr_location_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Location Id') ?></th>
          <th><?php echo gettext('Country') ?></th>
          <th><?php echo gettext('State') ?></th>
          <th><?php echo gettext('City') ?></th>
          <th><?php echo gettext('Location') ?></th>
          <th><?php echo gettext('Description') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody hr_location_values" >
         <?php
         $count = 0; 
         $hr_location_object_ai = new ArrayIterator($hr_location_object);
         $hr_location_object_ai->seek($position);
         while ($hr_location_object_ai->valid()) {
          $hr_location = $hr_location_object_ai->current();
          ?>         
          <tr class="hr_location<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
             <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_location->hr_location_id); ?>"></li>           
            </ul>
           </td>
           <td><?php form::number_field_widsr('hr_location_id'); ?></td>
           <td><?php echo $f->select_field_from_object('country', sys_value_group_line::find_by_parent_id('14'), 'code', 'code_value', $hr_location->country ,'','medium field_values'); ?></td>
           <td><?php echo $f->select_field_from_object('state', sys_value_group_line::find_by_parent_id('15'), 'code', 'code_value', $hr_location->state,'','medium field_values'); ?></td>
           <td><?php echo$f->select_field_from_object('city', sys_value_group_line::find_by_parent_id('13'), 'code', 'code_value', $hr_location->city,'','medium field_values'); ?></td>

           <td><?php echo $f->text_field_widr('combination', 'always_readonly large'); ?></td>
           <td><?php echo $f->text_field_wid('description', 'large') ?></td>
          </tr>
          <?php
          $hr_location_object_ai->next();
          if ($hr_location_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
     </form>
    </div>

   </div>
  </div> 
 </div>
 <div class='row small-top-margin'>
  <div id="pagination" style="clear: both;">
   <?php echo $pagination->show_pagination(); ?>
  </div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_location" ></li>
  <li class="primary_column_id" data-primary_column_id="coa_id" ></li>
  <li class="lineClassName" data-lineClassName="hr_location" ></li>
  <li class="line_key_field" data-line_key_field="combination" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_location" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_location_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_location_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>