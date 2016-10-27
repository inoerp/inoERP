<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id='bom_routing_divId'>
 <span class="heading"><?php   echo gettext('Routing Header');   echo!empty($form_name_header) ? ' - ' . gettext($form_name_header) : ' ';   ?></span>
 <div id="form_header">
 <form  method="bom_routingst" id="bom_routing_header"  name="bom_routing_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Common Routing') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('bom_routing_header_id') ?>
       <a name="show" href="form.php?class_name=bom_routing_header&<?php echo "mode=$mode"; ?>" class="show document_id bom_routing_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $bom_routing_header->org_id, 'org_id', ' ', 1, $readonly1); ?>        </li>
      <li><label>
        <?php echo gettext('Item Number') ?></label>
       <?php
       echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
       echo $f->hidden_field_withCLass('bom_enabled_cb', '1', 'popup_value');
       echo!empty($hidden_field) ? $hidden_field : '';
       $f->text_field_dm('item_number', 'select_item_number_all');
       ?>
       <i class="select_item_number select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, '', ' ', '', $readonly); ?>        </li>
      <li><?php $f->l_text_field_d('item_description'); ?> </li>
      <li><?php $f->l_text_field_d('routing_revision'); ?> </li>
      <li><?php $f->l_date_fieldAnyDay('effective_date', $$class->effective_date); ?>              </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><label><?php echo gettext('Item Number') ?></label><?php echo $f->hidden_field_withIdClass('common_routing_item_id_m', $$class->common_routing_item_id_m, 'item_id_m'); ?>
        <?php $f->text_field_d('commonRouting_item_number', 'select_item_number'); ?>
        <i class="select_item_number2 select_popup clickable fa fa-search"></i>
       </li>
       <li><label><?php echo gettext('Description') ?></label><?php $f->text_field_d('commonRouting_item_description', 'commonRouting_item_description'); ?>  </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'bom_routing_header';
       $reference_id = $$class->bom_routing_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>

 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Operation & Resource Details') ?> </span>
  <form method="bom_routingst" id="bom_routing_line"  name="bom_routing_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Effectivity') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Data Collection') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Routing Seq') ?></th>
         <th><?php echo gettext('Standard Op') ?></th>
         <th><?php echo gettext('Referenced') ?></th>
         <th><?php echo gettext('Department') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Count Point') ?></th>
         <th><?php echo gettext('Auto Charge') ?></th>
         <th><?php echo gettext('Back flush') ?></th>
         <th><?php echo gettext('MTQ') ?></th>
         <th><?php echo gettext('Lead Time') ?>%</th>
         <th><?php echo gettext('Operation Details') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($bom_routing_line_object as $bom_routing_line) {
         ?>         
         <tr class="bom_routing_line<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->bom_routing_line_id, array('bom_routing_header_id' => $$class->bom_routing_header_id));
           ?>
          </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php $f->text_field_wid2sr('bom_routing_line_id' ,'line_id always_readonly'); ?></td>
          <td><?php $f->text_field_d2s('routing_sequence', 'lines_number'); ?></td>
          <td><?php echo form::select_field_from_object('standard_operation_id', bom_standard_operation::find_all(), 'bom_standard_operation_id', 'standard_operation', $$class_second->standard_operation_id, '', $readonly); ?></td>
          <td><?php echo form::checkBox_field('referenced_cb', $$class_second->referenced_cb); ?></td>
          <td><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, '', $readonly, '', '', 1); ?></td>
          <td><?php form::text_field_wid2('description' , 'large'); ?></td>
          <td><?php echo form::checkBox_field('count_point_cb', $$class_second->count_point_cb); ?></td>
          <td><?php echo form::checkBox_field('auto_charge_cb', $$class_second->auto_charge_cb); ?></td>
          <td><?php echo form::checkBox_field('backflush_cb', $$class_second->backflush_cb); ?></td>
          <td><?php form::number_field_wid2s('minimum_transfer_quantity'); ?></td>
          <td><?php form::number_field_wid2('lead_time_percentage'); ?></td>
          <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
           <?php
           $bom_routing_line_id = $bom_routing_line->bom_routing_line_id;
           if (!empty($bom_routing_line_id)) {
            $bom_routing_detail_object = bom_routing_detail::find_by_routing_lineId($bom_routing_line_id);
           } else {
            $bom_routing_detail_object = array();
           }
           if (count($bom_routing_detail_object) == 0) {
            $bom_routing_detail = new bom_routing_detail();
            $bom_routing_detail_object = array();
            array_push($bom_routing_detail_object, $bom_routing_detail);
           }
           ?>
           <div class="class_detail_form">
            <fieldset class="form_detail_data_fs">
             <div class="tabsDetail">
              <ul class="tabMain">
               <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Resource') ?></a></li>
               <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Future') ?></a></li>
              </ul>
              <div class="tabContainer">
               <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
                <table class="form form_detail_data_table detail">
                 <thead>
                  <tr>
                   <th><?php echo gettext('Action') ?></th>
                   <th><?php echo gettext('Detail Id') ?></th>
                   <th><?php echo gettext('Resource Seq') ?></th>
                   <th><?php echo gettext('Resource') ?></th>
                   <th><?php echo gettext('Basis') ?></th>
                   <th><?php echo gettext('Usage') ?></th>
                   <th><?php echo gettext('Schedule') ?></th>
                   <th><?php echo gettext('Units') ?></th>
                   <th><?php echo gettext('24 Hours') ?></th>
                   <th><?php echo gettext('Stnd. Rate') ?></th>
                   <th><?php echo gettext('Charge Type') ?></th>
                  </tr>
                 </thead>
                 <tbody class="form_data_detail_tbody">
                  <?php
                  $detailCount = 0;
                  foreach ($bom_routing_detail_object as $bom_routing_detail) {
                   $class_third = 'bom_routing_detail';
                   $$class_third = &$bom_routing_detail;
                   ?>
                   <tr class="bom_routing_detail<?php echo $count . '-' . $detailCount; ?>">
                    <td>   
                     <ul class="inline_action">
                      <li class="add_row_detail_img"><i class="fa fa-plus-circle"></i></li>
                      <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
                      <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($bom_routing_detail->bom_routing_detail_id); ?>"></li>           
                      <li><?php echo form::hidden_field('bom_routing_line_id', $bom_routing_line->bom_routing_line_id); ?></li>
                      <li><?php echo form::hidden_field('bom_routing_header_id', $bom_routing_header->bom_routing_header_id); ?></li>
                     </ul>
                    </td>
                    <td><?php form::text_field_wid3sr('bom_routing_detail_id'); ?></td>
                    <td><?php $f->text_field_d3s('resource_sequence', 'detail_number'); ?></td>
                    <td><?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', $readonly, 'resource_id', '', 1); ?></td>
                    <td><?php echo form::select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->charge_basis, '', $readonly, 'default_basis', '', 1); ?></td>
                    <td><?php form::number_field_wid3sm('resource_usage') ?></td>
                    <td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_third->resource_schedule, '', $readonly, '', '', 1); ?></td>
                    <td><?php form::number_field_wid3s('assigned_units') ?></td>
                    <td><?php echo form::checkBox_field('twenty_four_hr_cb', $$class_third->twenty_four_hr_cb); ?></td>
                    <td><?php echo form::checkBox_field('standard_rate_cb', $$class_third->standard_rate_cb); ?></td>
                    <td><?php echo form::select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class_third->charge_type, '', $readonly, '', '', 1); ?></td>
                   </tr>
                   <?php
                   $detailCount++;
                  }
                  ?>
                 </tbody>
                </table>
               </div>
               <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">

               </div>
              </div>
             </div>
            </fieldset>

           </div>

          </td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?></th>
         <th><?php echo gettext('Start Date') ?></th>
         <th><?php echo gettext('End Date') ?></th>
         <th><?php echo gettext('ECO Implemented') ?></th>
         <th><?php echo gettext('ECO Number') ?></th>
         <th><?php echo gettext('Roll up') ?></th>
         <th><?php echo gettext('Yield') ?>%</th>
         <th><?php echo gettext('Cumm. Yield') ?>%</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($bom_routing_line_object as $bom_routing_line) {
         ?>         
         <tr class="bom_routing_line<?php echo $count ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php echo form::date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
          <td><?php echo form::date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
          <td><?php echo form::checkBox_field('eco_implemented_cb', $$class_second->eco_implemented_cb, 'eco_implemented_cb', $readonly); ?></td>
          <td><?php form::text_field_wid2('eco_number'); ?></td>

          <td><?php echo form::checkBox_field('include_in_rollup_cb', $$class_second->include_in_rollup_cb); ?></td>
          <td><?php form::number_field_wid2('yield'); ?></td>
          <td><?php form::number_field_wid2('cumm_yield'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
       <!--                  Showing a blank form for new entry-->
      </table>
     </div>

     <div id="tabsLine-3" class="tabContent">
      <?php
      $extra_element_label = 'Data Collection Element';
      $class_name_object = $bom_routing_line_object;
      $ef_refer_key = 'bom_routing_line';
      $ef_refer_value = 'bom_routing_line_id';
      $tr_class = 'bom_routing_line';
      include_once __DIR__ . '/../../sys/extra_field/form/add_field_template.php';
      ?>

     </div>
    </div>
   </div>
  </form>

 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_routing_header" ></li>
  <li class="lineClassName" data-lineClassName="bom_routing_line" ></li>
  <li class="detailClassName" data-detailClassName="bom_routing_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_routing_header_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_routing_header" ></li>
  <li class="line_key_field" data-line_key_field="department_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="bom_routing_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_routing_header_id" ></li>
  <li class="docLineId" data-docLineId="bom_routing_line_id" ></li>
  <li class="docDetailId" data-docDetailId="bom_routing_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_routing_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
