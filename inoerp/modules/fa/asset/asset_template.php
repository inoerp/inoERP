<div id="form_all">
 <form method="post" id="fa_asset"  name="fa_asset">
  <span class="heading"><?php echo gettext('Fixed Asset Details') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Tracking Info') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('fa_asset_id') ?>
        <a name="show" href="form.php?class_name=fa_asset&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('asset_number'); ?></li>
       <li><?php $f->l_select_field_from_object('fa_asset_category_id', fa_asset_category::find_all(), 'fa_asset_category_id', 'asset_category', $$class->fa_asset_category_id, 'fa_asset_category_id', '', 1); ?></li>
       <li><?php $f->l_select_field_from_array('status', fa_asset::$status_a, $$class->status, 'status'); ?></li>
       <li><?php $f->l_text_field_dm('units'); ?></li>
       <li><?php $f->l_select_field_from_array('type', fa_asset::$type_a, $$class->type, '', '', 1); ?></li>
       <li><?php $f->l_text_field_d('parent_asset_id'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('tag_number'); ?></li>
       <li><?php $f->l_text_field_d('serial_number'); ?></li>
       <li><?php $f->l_text_field_d('key_number'); ?></li>
       <li><?php $f->l_text_field_d('manufacturer'); ?></li>
       <li><?php $f->l_text_field_d('model_number'); ?></li>
       <li><?php $f->l_text_field_d('warrranty_number'); ?></li>
       <li><?php $f->l_text_field_d('lease_number'); ?></li>
       <li><label>Physical Inv?</label><?php echo $f->checkBox_field('physical_inventory_cb', $$class->physical_inventory_cb); ?></li>
       <li><?php $f->l_text_field_d('rev_number'); ?></li>
      </ul>
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
        $reference_table = 'fa_asset';
        $reference_id = $$class->fa_asset_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Asset Line Details') ?></span>

   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Assignments') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Other Details') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Units') ?>#</th>
         <th><?php echo gettext('Employee') ?></th>
         <th><?php echo gettext('Expense') ?></th>
         <th><?php echo gettext('Address') ?></th>
         <th><?php echo gettext('Description') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody fa_asset_assignment_values" >
        <?php
        $count = 0;
        $fa_asset_assignment_object_ai = new ArrayIterator($fa_asset_assignment_object);
        $fa_asset_assignment_object_ai->seek($position);
        while ($fa_asset_assignment_object_ai->valid()) {
         $fa_asset_assignment = $fa_asset_assignment_object_ai->current();
         if (!empty($fa_asset_assignment->hr_employee_id)) {
          $emp_details_l = hr_employee::find_by_id($fa_asset_assignment->hr_employee_id);
          $fa_asset_assignment->employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
         } else {
          $fa_asset_assignment->employee_name = null;
         }

         if (!empty($fa_asset_assignment->address_id)) {
          $address_l = address::find_by_id($fa_asset_assignment->address_id);
          $fa_asset_assignment->address_name = $address_l->address_name;
         } else {
          $fa_asset_assignment->address_name = null;
         }
         ?>         
         <tr class="fa_asset_assignment<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($fa_asset_assignment->fa_asset_assignment_id, array('fa_asset_id' => $$class->fa_asset_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('fa_asset_assignment_id', 'always_readonly'); ?></td>
          <td><?php echo $f->number_field('units', $$class_second->units, '', '', 'line_units'); ?></td>
          <td><?php
          echo $f->val_field('employee_name', $$class_second->employee_name, '', '', 'vf_select_member_employee_name', '', '', 'hr_employee_v', 'employee_name');
          echo $f->hidden_field('hr_employee_id', $$class_second->hr_employee_id);
           ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></td>
          <td><?php $f->ac_field_d2m('expense_ac_id' , 'xlarge'); ?></td>
          <td><?php
          echo $f->val_field('address_name', $$class_second->address_name, '', '', 'vf_select_address_name', '', '', 'address', 'address_name');
          echo $f->hidden_field('address_id', $$class_second->address_id);
           ?><i class="generic g_select_address select_popup clickable fa fa-search" data-class_name="address"></i></td>
          <td><?php $f->text_field_wid2('description' ,'xlarge'); ?></td>
         </tr>
         <?php
         $fa_asset_assignment_object_ai->next();
         if ($fa_asset_assignment_object_ai->key() == $position + $per_page) {
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
      <ul class='column header_field'>
       <li>
        <div class="btn-group row">
         <button type="button" class="btn btn-primary btn-lg">
          <span  aria-hidden="true"></span><i class='fa fa-book white-font-link'></i> Asset Books</button>
         <button type="button" class="btn btn-primary dropdown-toggle btn-lg" data-toggle="dropdown" aria-expanded="false">
          <span class="caret"></span>
          <span class="sr-only"><?php echo gettext('Toggle Dropdown')?></span>
         </button>
         <ul class="dropdown-menu" role="menu">
          <?php
          $ab = fa_asset_book::find_all();
          foreach ($ab as $ab_i) {
           echo '<li><a target="_blank" href="form.php?mode=9&class_name=fa_asset_book_info&fa_asset_book_id=' .
           $ab_i->fa_asset_book_id . '&fa_asset_id=' . $$class->fa_asset_id . '">' . $ab_i->asset_book_name . '</a></li>';
          }
          ?>
         </ul>
        </div>
       </li>
       <li><a target="_blank" role="button"  class="btn btn-primary btn-lg white-font-link" href="form.php?mode=9&class_name=fa_asset_source&fa_asset_id=<?php echo $$class->fa_asset_id ?>"> <i class="fa fa-reorder white-font-link"></i> Source Lines </a>  </li>
       <li> <button type="button" class="btn btn-primary btn-lg "> <i class="fa fa-list-ul white-font-link"></i> Components </button>  </li>
       <li> <button type="button" class="btn btn-primary btn-lg "> <i class="fa fa-bolt white-font-link"></i> Retirements </button>  </li>
       <li> <button type="button" class="btn btn-primary btn-lg "> <i class="fa fa-money white-font-link"></i> Financial Inquiry </button>  </li>
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
  <li class="headerClassName" data-headerClassName="fa_asset" ></li>
  <li class="lineClassName" data-lineClassName="fa_asset_assignment" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fa_asset_assignment" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_id" ></li>
  <li class="docLineId" data-docLineId="fa_asset_assignment_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_asset_assignment" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
