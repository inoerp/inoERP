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
      <?php echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="hr_approval_limit_header"  name="hr_approval_limit_header"><span class="heading">Approval Limit Header </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_approval_limit_header_id select_popup clickable">
               Header Id : </label><?php $f->text_field_dsr('hr_approval_limit_header_id') ?>
              <a name="show" href="form.php?class_name=hr_approval_limit_header_id" class="show hr_approval_limit_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Business Org :</label>
<?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>Limit Name : </label><?php $f->text_field_d('limit_name'); ?></li>
             <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
             <li><label>Description: </label><?php $f->text_field_dl('description'); ?></li>
            </ul>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Approval Limit Lines </span>
       <form action=""  method="post" id="hr_approval_limit_line"  name="hr_approval_limit_line">
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
              <th>Limit Object</th>
              <th>Limit Type</th>
              <th>Lowest Range</th>
              <th>Highest Range</th>
              <th>Amount</th>
              <th>Inactive date</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($hr_approval_limit_line_object as $hr_approval_limit_line) {
               if (!empty($$class_second->limit_object)) {
                $appr_obj = hr_approval_object::find_by_id($$class_second->limit_object);
                $appr_obj_val = $appr_obj->object_value;
                $value_result = ($appr_obj->value_type == 'DYNAMIC') ? dbObject::find_by_sql_array($appr_obj_val) : null;
//                pa($value_result);
               }
               ?>         
               <tr class="hr_approval_limit_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_approval_limit_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('hr_approval_limit_header_id', $hr_approval_limit_header->hr_approval_limit_header_id); ?></li>
                 </ul>
                </td>
                <td><?php $f->text_field_wid2sr('hr_approval_limit_line_id'); ?></td>
                <td><?php echo $f->select_field_from_object('limit_object', hr_approval_object::find_all(), 'hr_approval_object_id', 'object_name', $$class_second->limit_object, '', '', 1, $readonly); ?></td>
                <td><?php echo $f->select_field_from_array('limit_type', hr_approval_limit_line::$limit_type_a, $$class_second->limit_type); ?></td>
                <td><select class="status select" name="limit_range_low[]" class="limit_range_low">
                  <?php if(!empty($value_result)){
                  foreach ($value_result as $arr) {
                   $strcomp_low = strcasecmp(trim($arr[0]), trim($$class_second->limit_range_low)) == 0 ? ' selected ' : '';
                   echo "<option value='" . $arr[0] . "' ". $strcomp_low . ">" . $arr[0] . "</option>";
                   unset($selected_low);
                  }
                  }
                  ?> </select></td>
                <td><select class="status select" name="limit_range_high[]" class="limit_range_high">
                  <?php if(!empty($value_result)){
                  foreach ($value_result as $arr) {
                   $strcomp_high = strcasecmp(trim($arr[0]), trim($$class_second->limit_range_high)) == 0 ? ' selected ' : '';
                   echo "<option value='" . $arr[0] . "' $strcomp_high >" . $arr[0] . "</option>";
              }}
                  ?> </select></td>
                <td><?php $f->text_field_wid2('amount_limit'); ?></td>
                <td><?php echo $f->date_fieldFromToday('inactive_date', $$class_second->inactive_date); ?></td>

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
  <li class="headerClassName" data-headerClassName="hr_approval_limit_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_approval_limit_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_approval_limit_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_approval_limit_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_approval_limit_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_approval_limit_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_approval_limit_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
