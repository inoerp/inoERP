<div id="prj_burden_cost_base_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="prj_event_type"  name="prj_event_type">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Event Type') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Event Type') ?></th>
           <th><?php echo gettext('Event Class') ?></th>
           <th><?php echo gettext('Revenue Category') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Eff. From') ?></th>
           <th><?php echo gettext('Eff. To') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $prj_event_type) {
            ?>         
            <tr class="prj_event_type_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_event_type->prj_event_type_id); ?>"></li>           
              </ul>
             </td>
             <td><?php $f->l_text_field_d('event_type'); ?></td>
             <td><?php $f->l_select_field_from_object('event_class', option_header::find_options_byName('PRJ_EVENT_CLASS'), 'option_tdne_code', 'option_tdne_value', $$class->event_class, 'event_class'); ?></td>
             <td><?php $f->l_select_field_from_object('revenue_category', option_header::find_options_byName('PRJ_REVENUE_CATEGORY'), 'option_tdne_code', 'option_tdne_value', $$class->revenue_category, 'revenue_category'); ?></td>
             <td><?php $f->l_text_field_d('description'); ?></td>
             <td><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></td>
             <td><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></td>
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
  <li class="lineClassName" data-lineClassName="prj_event_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="prj_event_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="prj_event_type"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
