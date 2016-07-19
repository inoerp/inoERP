<div id="coa_combination_divId" class="pagination_page">
 <div class='row small-left-padding'>
  <div id="form_header">
   <span class="heading"><?php echo gettext('Chart Of Account Code Combinations') ?></span> 
   <div class="tabContainer">
    <?php $f->l_select_field_from_object('coa_id', coa::find_all(), 'coa_id', 'coa_name', $coa_id_h, 'coa_id', '', 1, $readonly); ?>
    <a name="show" href="form.php?class_name=coa_combination&<?php echo "mode=$mode"; ?>" class="show document_id coa_id">
     <i class='fa fa-refresh'></i></a> 
   </div>
  </div>
  <div id ="form_line" class="coa_combination"><span class="heading"><?php echo gettext('Value Group Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic - View Only') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Field Values') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Effectivity') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <form action=""  method="post" id="coa_combination_line"  name="coa_combination_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('CC Id') ?>#</th>
          <th><?php echo gettext('Code Combination') ?></th>
          <th><?php echo gettext('Description') ?>#</th>
          <th><?php echo gettext('Account Type') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody coa_combination_values" >
         <?php
         $count = 0;
         $coa_combination_object_ai = new ArrayIterator($coa_combination_object);
         $coa_combination_object_ai->seek($position);
         while ($coa_combination_object_ai->valid()) {
          $coa_combination = $coa_combination_object_ai->current();
          ?>         
          <tr class="coa_combination<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><i class="fa fa-plus-circle"  alt="add new line"></i></li>
             <li class="remove_row_img"><i class="fa fa-minus-circle" alt="remove this line"></i></li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($coa_combination->coa_combination_id); ?>"></li>           
             <li><?php echo form::hidden_field('coa_id', $coa_id_h); ?></li>
            </ul>
           </td>
           <td><?php form::number_field_widsr('coa_combination_id'); ?></td>
           <td><?php echo form::text_field('combination', $$class->combination, 30, '', 1, '', 'Non editable - Enter segment/field values', 1); ?></td>
           <td><?php echo form::text_field('description', $$class->description, 60, '', 1, '', 'Non editable - Enter segment/field values', 1) ?></td>
           <td><?php echo $f->select_field_from_object('ac_type', coa::coa_account_types(), 'option_line_code', 'option_line_value', $$class->ac_type, '', 'dontCopy dont_copy', 1, $readonly); ?></td>
          </tr>
          <?php
          $coa_combination_object_ai->next();
          if ($coa_combination_object_ai->key() == $position + $per_page) {
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
         <tr><?php
          if (!empty($coa_id_h)) {
           foreach (coa::coa_display_by_coaId($coa_id_h) as $key => $value) {
            echo!empty($value) ? "<th>$value : </th>" : '';
           }
          }
          ?>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody coa_combination_values" >
         <?php
         $count = 0;
//       $coa_combination_object_ai = new ArrayIterator($coa_combination_object);S
         $coa_combination_object_ai->seek($position);
         while ($coa_combination_object_ai->valid()) {
          $coa_combination = $coa_combination_object_ai->current();
          if (!empty($coa_combination->coa_id)) {
           $$class_second->findBy_id($coa_combination->coa_id);
          } else if (!empty($coa_id_h)) {
           $$class_second->findBy_id($coa_id_h);
          }

          echo '<tr class="coa_combination' . $count . '">';
          if (!empty($$class_second->coa_id)) {
           $datacount = 1;
           foreach (coa::coa_display_by_coaId($$class_second->coa_id) as $key => $value) {
            if (!empty($value)) {
             $option_line = option_line::find_by_optionId_lineCode($$class_second->coa_structure_id, $value);
             $field_name = 'field' . $datacount;
             $descArray = ['code', 'description'];
             echo '<td>' .
             $f->select_field_from_object($field_name, sys_value_group_line::find_by_header_id($option_line->value_group_id), 'code', $descArray, $$class->$field_name, '', 'ac field_values', 1, $readonly, '', '', '', 'account_qualifier')
             . '</td>';
             $datacount++;
            }
           }
          }
          echo '</tr>';
          $coa_combination_object_ai->next();
          if ($coa_combination_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-3" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Status') ?></th>
          <th><?php echo gettext('Start Date') ?>#</th>
          <th><?php echo gettext('End Date') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody coa_combination_values" >
         <?php
         $count = 0;
         
//       $coa_combination_object_ai = new ArrayIterator($coa_combination_object);
         $coa_combination_object_ai->seek($position);
         while ($coa_combination_object_ai->valid()) {
          $coa_combination = $coa_combination_object_ai->current();
          ?>         
          <tr class="coa_combination<?php echo $count ?>">
           <td><?php echo form::status_field_d('status'); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_start_date', $$class->effective_start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class->effective_end_date); ?></td>
          </tr>
          <?php
          $coa_combination_object_ai->next();
          if ($coa_combination_object_ai->key() == $position + $per_page) {
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
  <li class="headerClassName" data-headerClassName="coa_combination" ></li>
  <li class="primary_column_id" data-primary_column_id="coa_id" ></li>
  <li class="lineClassName" data-lineClassName="coa_combination" ></li>
  <li class="line_key_field" data-line_key_field="combination" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="coa_combination" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="coa_combination_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="coa_combination_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>