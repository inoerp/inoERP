<div id ="form_header">
 <form   method="post" id="hr_approval_limit_header"  name="hr_approval_limit_header">
  <span class="heading"><?php echo gettext('Approval Limit Header') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hr_approval_limit_header_id') ?>
       <a name="show" href="form.php?class_name=hr_approval_limit_header&<?php echo "mode=$mode"; ?>" 
          class="show document_id hr_approval_limit_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'org_id', '', 1, $readonly1); ?>       </li>
      <li><?php $f->l_text_field_d('limit_name'); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Approval Limit Lines') ?></span>
 <form   method="post" id="hr_approval_limit_line"  name="hr_approval_limit_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Limit Object') ?>#</th>
        <th><?php echo gettext('Limit Type') ?></th>
        <th><?php echo gettext('Lowest Range') ?></th>
        <th><?php echo gettext('Highest Range') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Inactive Date') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_approval_limit_line_object as $hr_approval_limit_line) {
        if (!empty($$class_second->limit_object)) {
         $appr_obj = hr_approval_object::find_by_keyColumn($$class_second->limit_object);
         if (DB_TYPE == 'ORACLE') {
          $appr_obj->object_value = stream_get_contents($appr_obj->object_value);
         }
         $appr_obj_val = $appr_obj->object_value;
         $value_result = ($appr_obj->value_type == 'DYNAMIC') ? dbObject::find_by_sql_array($appr_obj_val) : null;
//                pa($value_result);
        }
        ?>         
        <tr class="hr_approval_limit_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->hr_approval_limit_line_id, array('hr_approval_limit_header_id' => $hr_approval_limit_header->hr_approval_limit_header_id));
          ?>    
         </td>
         <td><?php $f->text_field_wid2sr('hr_approval_limit_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('limit_object', hr_approval_object::find_all(), 'object_code', 'object_name', $$class_second->limit_object, '', 'medium', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_array('limit_type', hr_approval_limit_line::$limit_type_a, $$class_second->limit_type, '', 'medium'); ?></td>
         <td><select class="status select" name="limit_range_low[]" class="limit_range_low medium">
           <?php
           if (!empty($value_result)) {
            foreach ($value_result as $arr) {
             $strcomp_low = strcasecmp(trim($arr[0]), trim($$class_second->limit_range_low)) == 0 ? ' selected ' : '';
             echo "<option value='" . $arr[0] . "' " . $strcomp_low . ">" . $arr[0] . "</option>";
             unset($selected_low);
            }
           }
           ?> </select></td>
         <td><select class="status select" name="limit_range_high[]" class="limit_range_high medium">
           <?php
           if (!empty($value_result)) {
            foreach ($value_result as $arr) {
             $strcomp_high = strcasecmp(trim($arr[0]), trim($$class_second->limit_range_high)) == 0 ? ' selected ' : '';
             echo "<option value='" . $arr[0] . "' $strcomp_high >" . $arr[0] . "</option>";
            }
           }
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