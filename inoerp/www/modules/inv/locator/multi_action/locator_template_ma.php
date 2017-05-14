<div id="locator_divId" class="multi_select_page">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form method="post" id="locator"  name="locator">
    <div id ="form_line" class="form_line"><span class="heading">Locator Details </span>
     <table class="form_table">
      <?php echo locator::$view_table_line_tr ?>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       if (!empty($search_result)) {
        foreach ($search_result as $locator) {
         ?>         
         <tr class="locator_line<?php echo $count ?>">
          <td><?php echo ino_inline_action($$class->locator_id, array('locator_id' => $$class->locator_id)); ?> </td>
          <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, '' ,'medium'); ?></td>
          <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all(), 'subinventory_id', 'subinventory', $$class->subinventory_id, '' ,'medium'); ?>        </td>
          <td class="single_line"><?php echo locator::locator_structure(); ?></td>
          <td><?php echo form::text_field_widsr('locator_id'); ?></td>
          <td><?php form::text_field_wid('locator'); ?></td>
          <td><?php form::text_field_wid('alias'); ?></td>
          <td><?php echo form::extra_field($$class->ef_id, '10', $readonly); ?></td>
          <td><?php echo form::status_field($$class->status, $readonly); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
       }
       ?>
      </tbody>
     </table>
    </div> 
   </form>
  </div>
  <!--END OF FORM HEADER-->

  </div>
 
  <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";   ?>
  </div>
 </div>
 
 </div>



<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="locator" ></li>
  <li class="lineClassName" data-lineClassName="locator" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="locator" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="locator"></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>

