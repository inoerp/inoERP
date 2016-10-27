<div id="sys_rfid_interface_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="sys_rfid_interface"  name="sys_rfid_interface">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('RFID Interface') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Basics-2') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('RFID Interface Id') ?></th>
           <th><?php echo gettext('EPC') ?></th>
           <th><?php echo gettext('Tag Number') ?></th>
           <th><?php echo gettext('Antena Number') ?></th>
           <th><?php echo gettext('Time Stamp') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Read Count') ?></th>
           <th><?php echo gettext('Org Id') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $sys_rfid_interface) {
            ?>         
            <tr class="sys_rfid_interface_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sys_rfid_interface->sys_rfid_interface_id); ?>"></li>           
              </ul>
             </td>
             <td><?php $f->text_field_d('sys_rfid_interface_id') ?></td>
             <td><?php $f->text_field_d('epc'); ?></td>
             <td><?php $f->text_field_d('tag_number'); ?></td>
             <td><?php $f->text_field_d('antena_number'); ?></td>
             <td><?php $f->text_field_d('time_stamp'); ?></td>
             <td><?php $f->text_field_d('description'); ?></td>
             <td><?php $f->text_field_d('readcount'); ?></td>
             <td><?php $f->text_field_d('org_id'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>

       <div id="tabsLine-2" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('RFID Interface Id') ?></th>
           <th><?php echo gettext('Item Id') ?></th>
           <th><?php echo gettext('From Subinventory Id') ?></th>
           <th><?php echo gettext('From Subinventory') ?></th>
           <th><?php echo gettext('Transaction Type Id') ?></th>
           <th><?php echo gettext('Transaction Type') ?></th>
           <th><?php echo gettext('Quantity') ?></th>
           <th><?php echo gettext('Item Description') ?></th>
           <th><?php echo gettext('Status') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $sys_rfid_interface) {
            ?>         
            <tr class="sys_rfid_interface_line<?php echo $count ?>">
             <td><?php $$class->sys_rfid_interface_id; ?></td>
             <td><?php $f->text_field_d('item_id_m'); ?></td>
             <td><?php $f->text_field_d('from_subinventory_id'); ?></td>
             <td><?php $f->text_field_d('from_subinventory'); ?></td>
             <td><?php $f->text_field_d('transaction_type_id'); ?></td>
             <td><?php $f->text_field_d('transaction_type'); ?></td>
             <td><?php $f->text_field_d('quantity'); ?></td>
             <td><?php $f->text_field_d('item_description'); ?></td>
             <td><?php $f->text_field_d('status'); ?></td>
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
  <li class="lineClassName" data-lineClassName="sys_rfid_interface" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="sys_rfid_interface" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="sys_rfid_interface"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
