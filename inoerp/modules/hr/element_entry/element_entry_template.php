<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="hr_element_entry_header"  name="hr_element_entry_header"><span class="heading">Element Entry </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_element_entry_header_id select_popup clickable">
               Hierarchy Id : </label><?php $f->text_field_dsr('hr_element_entry_header_id') ?>
              <a name="show" href="form.php?class_name=hr_element_entry_header_id" class="show hr_element_entry_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
               Employee Name : </label><?php $f->text_field_d('employee_name'); ?>
              <?php echo $f->hidden_field_withId('employee_id', $$class->employee_id); ?>
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
               Identification # : </label><?php $f->text_field_d('identification_id'); ?>
             </li>
            </ul>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Element Entry Lines </span>
       <form action=""  method="post" id="hr_element_entry_line"  name="hr_element_entry_line">
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
              <th>Element Name</th>
              <th>Element Value</th>
              <th>Monetary Value</th>
              <th>Inactive Date</th>
              <th>Description</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($hr_element_entry_line_object as $hr_element_entry_line) {
               ?>         
               <tr class="hr_element_entry_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_element_entry_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('hr_element_entry_header_id', $hr_element_entry_header->hr_element_entry_header_id); ?></li>
                 </ul>
                </td>
                <td><?php $f->text_field_wid2sr('hr_element_entry_line_id'); ?></td>
                <td><?php echo $f->select_field_from_object('element_id', hr_compensation_element::find_all(), 'hr_compensation_element_id', 'element_name', $$class_second->element_id, '', '', 1, $readonly); ?></td>
                <td><?php $f->text_field_wid2m('element_value'); ?></td>
                <td><?php $mon_val = hr_element_entry_line::find_monetary_value_by_id($$class_second->hr_element_entry_line_id); 
                         echo $f->text_field('monetary_value', $mon_val,'','','','',1); ?></td>
                <td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
                <td><?php $f->text_field_wid2l('description'); ?></td>

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
  <li class="headerClassName" data-headerClassName="hr_element_entry_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_element_entry_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_element_entry_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_element_entry_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_element_entry_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_element_entry_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_element_entry_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
