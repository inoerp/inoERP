<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="gl_ledger_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all"><span class="heading">Ledger Header </span>
       <form action=""  method="post" id="gl_ledger"  name="gl_ledger">
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Accounts</a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column">
              <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="gl_ledger_id select_popup clickable">
                Ledger Id : </label>
               <?php echo form::number_field_drs('gl_ledger_id'); ?>
               <a name="show" class="show gl_ledger_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li>
              <li><label>Ledger(1) : </label>
               <?php echo form::text_field_dm('ledger'); ?>
              </li>
              <li><label>Description : </label>
               <?php echo form::text_field_dm('description'); ?>
              </li>
              <li><label>Char of Account : </label>
               <?php echo $f->select_field_from_object('coa_id', coa::find_all(), 'coa_id', 'description', $$class->coa_id, 'coa_id', '', 1, $readonly1,'','','','coa_structure_id'); ?>
              </li>
              <li><label>Account Structure : </label>
               <?php echo $f->select_field_from_object('coa_structure_id', coa::coa_structures(), 'option_header_id', 'option_type', $$class->coa_structure_id, 'coa_structure_id', '', 1, 1); ?>
              </li>
              <li><label>Currency : </label>
               <?php echo $f->select_field_from_object('currency_code', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency_code, 'currency_code', '', 1, $readonly1); ?>
              </li>
              <li><label>Calendar : </label>
               <?php echo $f->select_field_from_object('calendar_option_line_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $$class->calendar_option_line_code, 'option_line_code', '',1, $readonly1); ?>
              </li>
              <li><label>Future Periods: </label>
               <?php form::number_field_d('future_enabled_periods'); ?>
              </li>
              <li><label>Revision : </label>
               <?php form::revision_enabled_field_d('rev_enabled'); ?>
              </li>
              <li><label>Revision No: </label>
               <?php form::text_field_ds('rev_number'); ?>
              </li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div> 
             <ul class="column five_column">
              <li><label>Retained Earnings : </label><?php $f->ac_field_d('retained_earnings_ac_id'); ?></li>
              <li><label>Suspense Account : </label><?php $f->ac_field_d('suspense_ac_id'); ?></li>
              <li><label>Currency Balancing : </label><?php $f->ac_field_d('currency_balancing_ac_id'); ?></li>
             </ul>
            </div>
           </div>
          </div>
         </div>
        </div>
       </form>
       <div id ="form_line" class="gl_ledger_balancing_values"><span class="heading">Ledger Options </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Balancing Segment Values</a></li>
          <li><a href="#tabsLine-2">Future</a></li>
         </ul>
         <div class="tabContainer"> 
          <form action=""  method="post" id="gl_ledger_balancing_values_line"  name="gl_ledger_balancing_values_line">
           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Line Id</th>
               <th>Balance Segment Value</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody gl_ledger_balancing_values_values" >
              <?php
               $count = 0;
               foreach ($gl_ledger_balancing_values_object as $gl_ledger_balancing_values) {
//							 $class_second = 'gl_ledger_balancing_values';
//							 $$class_second = &$gl_ledger_balancing_values;
                ?>         
                <tr class="gl_ledger_balancing_values<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($gl_ledger_balancing_values->gl_ledger_balancing_values_id); ?>"></li>           
                   <li><?php echo form::hidden_field('gl_ledger_id', $$class->gl_ledger_id); ?></li>
                  </ul>
                 </td>
                 <td><?php form::number_field_wid2sr('gl_ledger_balancing_values_id'); ?></td>
                 <td><?php
                  $svgl = new sys_value_group_line();
                  $descp = ['code_value', 'description'];
                  echo form::select_field_from_object('balancing_values', $svgl->findBy_parentId($value_group_headerid), 'code', $descp, $$class_second->balancing_values, '', $readonly);
                  ?></td>

                </tr>
                <?php
                $count = $count + 1;
               }
              ?>
             </tbody>
            </table>
           </div>
           <div id="tabsLine-2" class="tabContent">
           </div>
          </form>
         </div>

        </div>
       </div> 
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