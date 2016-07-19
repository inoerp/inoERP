<div id="hr_grade_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="hr_grade"  name="hr_grade">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('HR Grade') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1">Basics</a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Grade Id') ?></th>
           <th><?php echo gettext('Grade') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Rank') ?></th>
           <th><?php echo gettext('Alt Name') ?></th>
           <th><?php echo gettext('Alt Description') ?></th>
           <th><?php echo gettext('Grade') ?></th>
           <th><?php echo gettext('Inactive Date') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $hr_grade) {
            ?>         
            <tr class="hr_grade_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_grade->hr_grade_id); ?>"></li>           
              </ul>
             </td>
             <td><?php $f->text_field_dr('hr_grade_id', 'always_readonly'); ?></td>
             <td><?php $f->text_field_d('grade'); ?></td>
             <td><?php $f->text_field_d('description'); ?></td>
             <td><?php $f->text_field_ds('rank'); ?></td>
             <td><?php $f->text_field_d('alt_name'); ?></td>
             <td><?php $f->text_field_d('alt_description'); ?></td>
             <td><?php echo $f->select_field_from_object('hr_element_entry_tpl_header_id', hr_element_entry_tpl_header::find_all(),'hr_element_entry_tpl_header_id' ,'template_name',$$class->hr_element_entry_tpl_header_id,'hr_element_entry_tpl_header_id','medium' , 1); ?></td>
             <td><?php echo $f->date_fieldAnyDay('inactive_date', $$class->inactive_date); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
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
  <li class="lineClassName" data-lineClassName="hr_grade" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="hr_grade" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="hr_grade"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
