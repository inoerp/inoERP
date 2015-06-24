<div id ="form_header">
 <form action=""  method="post" id="hr_position_hierarchy_header"  name="hr_position_hierarchy_header"><span class="heading">Position Hierarchy </span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">

      <li><?php $f->l_text_field_dr_withSearch('hr_position_hierarchy_header_id') ?>
       <a name="show" href="form.php?class_name=hr_position_hierarchy_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_position_hierarchy_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><label>Name</label><?php $f->text_field_d('hierarchy_name'); ?></li>
      <li><label>Starting Position</label><?php echo $f->select_field_from_object('starting_position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $$class->starting_position_id, 'starting_position_id', '', 1, $readonly); ?>   </li>
      <li><label>Description</label><?php $f->text_field_dl('description'); ?> </li>
      <li><label>Start Date</label><?php echo $f->date_fieldAnyDay('effective_date', $$class->effective_date); ?> </li>
      <li><label>Revision</label><?php echo $f->number_field('revision', $$class->revision); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading">Hierarchy Lines </span>
 <form action=""  method="post" id="hr_position_hierarchy_line"  name="hr_position_hierarchy_line">
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
        <th>Position</th>
        <th>Start Date</th>
        <th>End Date</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_position_hierarchy_line_object as $hr_position_hierarchy_line) {
        ?>         
        <tr class="hr_position_hierarchy_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_position_hierarchy_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('hr_position_hierarchy_header_id', $hr_position_hierarchy_header->hr_position_hierarchy_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid2sr('hr_position_hierarchy_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $$class_second->position_id, '', '', 1, $readonly); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_position_hierarchy_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_position_hierarchy_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_position_hierarchy_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_position_hierarchy_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_position_hierarchy_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_position_hierarchy_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_position_hierarchy_header_id" ></li>
 </ul>
</div>