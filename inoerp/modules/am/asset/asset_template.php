<div id="form_all">
 <form action=""  method="post" id="am_asset"  name="am_asset"><span class="heading">Asset Numbers</span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic</a></li>
     <li><a href="#tabsHeader-2">Tracking Info</a></li>
     <li><a href="#tabsHeader-3">References</a></li>
     <li><a href="#tabsHeader-4">Attachments</a></li>
     <li><a href="#tabsHeader-5">Note</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('am_asset_id') ?>
        <a name="show" href="form.php?class_name=am_asset&<?php echo "mode=$mode"; ?>" class="show document_id am_asset_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php echo $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?></li>
       <li><?php $f->l_text_field_d('asset_number'); ?></li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup clickable">
        <?php  echo __('Inv Item Number').'</label>'; 
        echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
        <?php $f->text_field_dm('item_number', 'select_item_number_am_asset_item'); ?>
        <?php echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ITEM' , 'popup_value'); ?>
       </li>
       <li><?php $f->l_text_field_d('item_description'); ?></li>
       <li><?php echo $f->l_select_field_from_object('am_asset_category_id', fa_asset_category::find_all(), 'fa_asset_category_id', 'asset_category', $$class->am_asset_category_id, 'am_asset_category_id', '', 1); ?></li>
       <li><?php echo $f->l_select_field_from_array('status', am_asset::$status_a, $$class->status, 'status'); ?></li>
       <li><?php $f->l_text_field_dm('serial_number'); ?></li>
       <li><?php echo $f->l_select_field_from_array('type', am_asset::$type_a, $$class->type, '', '', 1, 1, 1); ?></li>
       <li><?php $f->l_text_field_d('parent_asset_id'); ?></li>
       <li><?php $f->l_text_field_d('accounting_class_id'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><label>Tag Number</label><?php $f->text_field_d('tag_number'); ?></li>
       <li><label>Owning Department</label><?php echo $f->select_field_from_object('owning_department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->owning_department_id, '', $readonly, '', '', 1); ?></li>
       <li><label>Location</label><?php $f->address_field_d('address_id'); ?></li>
       <li><label>Subinventory</label><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, '', 'subinventory_id', '', $readonly); ?>       </li>
       <li><label>Locator</label><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, '', 'locator_id', '', $readonly); ?>       </li>
       <li><label>Maintainable?</label><?php echo $f->checkBox_field('maintainable_cb', $$class->maintainable_cb); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <ul class="column header_field">
       <li><label>Equipment Item</label><?php $f->text_field_d('equipment_item_id_m'); ?></li>
       <li><label>Fixed Asset Id</label><?php $f->text_field_d('fa_asset_id'); ?></li>
       <li><label>Production Org</label><?php $f->text_field_d('production_org_id'); ?></li>
       <li><label>Manufacturer</label><?php $f->text_field_d('manufacturer'); ?></li>
       <li><label>Model#</label><?php $f->text_field_d('model_number'); ?></li>
       <li><label>Warranty#</label><?php $f->text_field_d('warranty_number'); ?></li>
       <li><label>Expiration</label><?php $f->text_field_d('warranty_exp_date'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'am_asset';
        $reference_id = $$class->am_asset_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
      <div> 
      </div>
     </div>
    </div>
   </div>
  </div>

  <div id ="form_line" class="form_line"><span class="heading">Asset Activities </span>

   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Activity Reference</a></li>
     <li><a href="#tabsLine-2">Reference2</a></li>
     <li><a href="#tabsLine-3">Other Details</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Seq#</th>
         <th>Line Id</th>
         <th>Priority</th>
         <th>Start Date</th>
         <th>End Date</th>
         <th>Cause</th>
         <th>Description</th>
         <th>Activity Type</th>

        </tr>
       </thead>
       <tbody class="form_data_line_tbody am_activity_reference_values" >
        <?php
        $f = new inoform();
        $count = 0;
        $am_activity_reference_object_ai = new ArrayIterator($am_activity_reference_object);
        $am_activity_reference_object_ai->seek($position);
        while ($am_activity_reference_object_ai->valid()) {
         $am_activity_reference = $am_activity_reference_object_ai->current();
         if (!empty($am_activity_reference->hr_employe_id)) {
          $emp_details_l = hr_employee::find_by_id($am_activity_reference->hr_employe_id);
          $am_activity_reference->employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
         } else {
          $am_activity_reference->employee_name = null;
         }
         ?>         
         <tr class="am_activity_reference<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->am_activity_reference_id, array('am_asset_id' => $$class->am_asset_id));
           ?>
          </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php form::number_field_wid2sr('am_activity_reference_id'); ?></td>
          <td><?php echo $f->number_field('priority', $$class_second->priority, '', '', 'priority'); ?></td>
          <td><?php echo $f->date_field('start_date', $$class_second->start_date); ?></td>
          <td><?php echo $f->date_field('end_date', $$class_second->end_date); ?></td>
          <td><?php $f->text_field_wid2('cause'); ?></td>
          <td><?php $f->text_field_wid2('description'); ?></td>
          <td><?php $f->text_field_wid2('activity_type'); ?></td>

         </tr>
         <?php
         $am_activity_reference_object_ai->next();
         if ($am_activity_reference_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th>Seq#</th>
         <th>Source</th>
         <th>Shutdown Type</th>
         <th>Accounting Class</th>
         <th>Owning Department</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody am_activity_reference_values" >
        <?php
        $count = 0;
        $am_activity_reference_object_ai = new ArrayIterator($am_activity_reference_object);
        $am_activity_reference_object_ai->seek($position);
        while ($am_activity_reference_object_ai->valid()) {
         $am_activity_reference = $am_activity_reference_object_ai->current();
         if (!empty($am_activity_reference->hr_employe_id)) {
          $emp_details_l = hr_employee::find_by_id($am_activity_reference->hr_employe_id);
          $am_activity_reference->employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
         } else {
          $am_activity_reference->employee_name = null;
         }
         ?>         
         <tr class="am_activity_reference<?php echo $count ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php $f->text_field_wid2('activity_source'); ?></td>
          <td><?php $f->text_field_wid2('shutdown_type'); ?></td>
          <td><?php $f->text_field_wid2('accounting_class_id'); ?></td>
          <td><?php $f->text_field_wid2('owning_department_id'); ?></td>
         </tr>
         <?php
         $am_activity_reference_object_ai->next();
         if ($am_activity_reference_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-3" class="tabContent">
      <ul class='column four_column'>
       <li>      <button type="button" class="btn btn-primary btn-lg disabled">
         <span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Source Lines
        </button>
       </li>

       <li>      <button type="button" class="btn btn-primary btn-lg disabled">
         <span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Components
        </button>
       </li>

       <li>      <button type="button" class="btn btn-primary btn-lg disabled">
         <span class="glyphicon glyphicon-remove-sign" aria-hidden="true"></span> Retirements
        </button>
       </li>

       <li class=" margin-top">      <button type="button" class="btn btn-primary btn-lg disabled">
         <i class="fa fa-money" aria-hidden="true"></i> Financial Inquiry
        </button>
       </li>

      </ul>

     </div>

    </div>


   </div>



  </div> 
 </form>
 <div id="pagination" style="clear: both;">
  <?php echo ($total_count > 9 ) ? $pagination->show_pagination() : ''; ?>
 </div>
</div>




<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_asset" ></li>
  <li class="lineClassName" data-lineClassName="am_activity_reference" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="am_asset_id" ></li>
  <li class="form_header_id" data-form_header_id="am_asset" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="am_activity_reference" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_asset_id" ></li>
  <li class="docLineId" data-docLineId="am_activity_reference_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_asset" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="am_activity_reference" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>