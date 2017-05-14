<div id="prj_expenditure_type_header_divId">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form method="post" id="prj_expenditure_type_header"  name="prj_expenditure_type_header">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Expenditure Type') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Controls') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Expn Type Id') ?></th>
           <th><?php echo gettext('Expenditure Type') ?></th>
           <th><?php echo gettext('Expn Category') ?></th>
           <th><?php echo gettext('Revenue Category') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Eff. From') ?></th>
           <th><?php echo gettext('Eff. To') ?></th>
           <th><?php echo gettext('UOM') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $prj_expenditure_type_header) {
            ?>         
            <tr class="prj_expenditure_type_header_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_expenditure_type_header->prj_expenditure_type_header_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('prj_expenditure_type_header_id'); ?></td>
             <td><?php form::text_field_wid('expenditure_type'); ?></td>
             <td><?php echo $f->select_field_from_object('expenditure_category', prj_expenditure_type_header::prj_expenditure_category(), 'option_line_code', 'option_line_value', $$class->expenditure_category, 'expenditure_category', '', '', $readonly); ?>    </td>
             <td><?php echo $f->select_field_from_object('revenue_category', prj_expenditure_type_header::prj_revenue_category(), 'option_line_code', 'option_line_value', $$class->revenue_category, 'revenue_category', '', '', $readonly); ?>    </td>
             <td><?php form::text_field_wid('description'); ?></td>
             <td><?php echo $f->date_fieldAnyDay('effective_from', $$class->effective_from); ?></td>
             <td><?php echo $f->date_fieldAnyDay('effective_to', $$class->effective_to); ?></td>
             <td><?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', 'uom_id', '', $readonly); ?>         </td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-2" class="scrollElement" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Inventory') ?></th>
           <th><?php echo gettext('Burden') ?></th>
           <th><?php echo gettext('Expense Reports') ?></th>
           <th><?php echo gettext('Misc. Transaction') ?></th>
           <th><?php echo gettext('Overtime') ?></th>
           <th><?php echo gettext('Invoice') ?></th>
           <th><?php echo gettext('Usage') ?></th>
           <th><?php echo gettext('Work In Process') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $prj_expenditure_type_header) {
            ?>         
            <tr class="prj_expenditure_type_header_line<?php echo $count ?>">
             <td><?php $f->checkBox_field_d('inventory_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('burden_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('expense_reports_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('misc_transaction_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('over_time_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('invoice_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('usages_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('wip_cb'); ?></td> 
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
         <!--                  Showing a blank form for new entry-->

        </table>
       </div>
      </div>
     </div>
    </div> 
   </form>
  </div>
 </div>
 <!--END OF FORM HEADER-->
 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="prj_expenditure_type_header" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="prj_expenditure_type_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="prj_expenditure_type_header"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
