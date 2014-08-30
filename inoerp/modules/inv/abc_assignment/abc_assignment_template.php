<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_abc_assignment_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header"><span class="heading">ABC Assignment Header </span>
       <form action=""  method="post" id="inv_abc_assignment_header"  name="inv_abc_assignment_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Assign Items</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li>
              <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_abc_assignment_header_id select_popup clickable">
               Assignment Header Id : </label>
              <?php echo form::number_field_drs('inv_abc_assignment_header_id'); ?>
              <a name="show" class="show inv_abc_assignment_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Assignment Name : </label><?php echo form::text_field_dm('abc_assignment_name'); ?></li>
             <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_abc_valuation_id select_popup clickable">
               ABC Valuation : </label> <?php
              echo $f->hidden_field_withId('inv_abc_valuation_id', $$class->inv_abc_valuation_id);
              $f->text_field_dm('valuation_name');
              ?> </li>
             <li><label>Inventory: </label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>Description : </label> <?php echo $f->text_field_dl('description'); ?></li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column three_column">
             <li> <label> Total Items : <?php $f->text_field_dr('total_no_of_items'); ?> </label></li>
             <li> <label> Total Value : <?php $f->text_field_dr('total_value'); ?> </label></li>
             <li> <label> Action : 
              <?php echo $f->select_field_from_array('assignment_action', inv_abc_assignment_header::$assignment_action_a, ''); ?> </label></li>
             </u>
           </div>
           <div id="data_table">
            <table class="form_table">
             <thead> 
              <tr>
               <th>ABC Class</th>
               <th>Sequence Number</th>
               <th>Value</th>
               <th>% of Items</th>
               <th>% of Value </th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody inv_abc_assignment_header_values" >
              <?php
              $count = 0;
              $all_abc_codes = inv_abc_assignment_header::inv_abc_codes();
              $no_of_class_codes = count($all_abc_codes);
              foreach ($all_abc_codes as $abc_code) {
               if ($count == $no_of_class_codes - 1) {
                $assign_seq_number_v = $$class->total_no_of_items;
                $assign_value_v = $$class->total_value;
                $assign_item_percentage_v = 100;
                $assign_value_percentage_ = 100;
               } else {
                $assign_seq_number_v = $assign_value_v = $assign_item_percentage_v = $assign_value_percentage_ = null;
               }
               ?>   
               <tr class="inv_abc_assignment_header<?php echo $count ?>">
                <td><?php echo $f->text_field('assign_abc_class_value', $abc_code->option_line_code, '8', '', '', '', 1); ?></td>
                <td><?php echo $f->text_field('assign_seq_number', $assign_seq_number_v); ?></td>
                <td><?php echo $f->text_field('assign_value', $assign_value_v, '30'); ?></td>
                <td><?php echo $f->text_field('assign_item_percentage', $assign_item_percentage_v, 30); ?></td>
                <td><?php echo $f->text_field('assign_value_percentage', $assign_value_percentage_, 30); ?></td>
               </tr>
               <?php
               $count++;
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

      <div id ="form_line" class="form_line"><span class="heading">View & Update Items </span>
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">Item ABC Class</a></li>
        </ul>
        <div class="tabContainer"> 
         <form action=""  method="post" id="inv_abc_assignment_line_line"  name="inv_abc_assignment_line_line">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Line Id</th>
              <th>Master Item Id </th>
              <th>Item Number</th>
              <th>Item Description</th>
              <th>ABC Class</th>
              <th>Comments</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_abc_assignment_line_values" >
             <?php
             $count = 0;
             foreach ($inv_abc_assignment_line_object as $inv_abc_assignment_line) {
              ?>         
              <tr class="inv_abc_assignment_line<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($inv_abc_assignment_line->inv_abc_assignment_line_id); ?>"></li>           
                 <li><?php echo form::hidden_field('inv_abc_assignment_header_id', $$class->inv_abc_assignment_header_id); ?></li>
                </ul>
               </td>
               <td><?php form::number_field_wid2sr('inv_abc_assignment_line_id'); ?></td>
               <td><?php $f->text_field_d2sr('item_id_m'); ?></td>
               <td><?php $f->text_field_wid2('item_number', 'select_item_number');
                ?> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number_only select_popup"></td>
               <td><?php $f->text_field_wid2l('item_description'); ?></td>
               <td><?php $f->text_field_wid2s('abc_class'); ?></td>

               <td><?php $f->text_field_wid2l('description'); ?></td>
              </tr>
              <?php
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
      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>