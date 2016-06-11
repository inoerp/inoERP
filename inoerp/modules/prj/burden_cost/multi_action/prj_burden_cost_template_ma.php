<div id="prj_burden_cost_base_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="prj_burden_cost_base"  name="prj_burden_cost_base">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Expenditure Type') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Cost Base Id') ?></th>
           <th><?php echo gettext('Cost Base') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Eff. From') ?></th>
           <th><?php echo gettext('Eff. To') ?></th>
           <th><?php echo gettext('Cost Base Type') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $prj_burden_cost_base) {
            ?>         
            <tr class="prj_burden_cost_base_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_burden_cost_base->prj_burden_cost_base_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('prj_burden_cost_base_id'); ?></td>
             <td><?php $f->l_text_field_d('cost_base'); ?></td>
             <td><?php $f->l_text_field_d('description'); ?></td>
             <td><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></td>
             <td><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></td>
             <td><?php $f->l_text_field_d('cost_base_type'); ?></td>
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
  <li class="lineClassName" data-lineClassName="prj_burden_cost_base" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="prj_burden_cost_base" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="prj_burden_cost_base"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
