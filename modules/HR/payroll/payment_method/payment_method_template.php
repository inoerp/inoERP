<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="hr_payroll_payment_method_divId">
      <div id="form_top">
      </div>
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="hr_payroll_payment_method"  name="hr_payroll_payment_method"><span class="heading">Payroll Payment Method </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Attachments</a></li>
           <li><a href="#tabsHeader-3">Notes</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_payroll_payment_method_id select_popup clickable">
                Header Id : </label><?php $f->text_field_ds('hr_payroll_payment_method_id') ?>
               <a name="show" href="form.php?class_name=hr_payroll_payment_method" class="show hr_payroll_payment_method_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Payment Method :</label><?php $f->text_field_d('payment_method'); ?> 					</li>
              <li><label>Currency : </label>
               <?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'currency','', 1,  $readonly1); ?>
              </li>
              <li><label>Payment Type :</label>
                <?php echo $f->select_field_from_object('payment_type', hr_payroll_payment_method::payment_method_type(), 'option_line_code', 'option_line_value', $$class->payment_type, 'payment_type','', 1,  $readonly1); ?>
</li>
              <li><label>Start Date :</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
              <li><label>End Date :</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
              <li><label>Description :</label><?php $f->text_field_dl('description'); ?> 					</li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div> <?php echo ino_attachement($file) ?> </div>
           </div>
           <div id="tabsHeader-3" class="tabContent">
            <div> 
             <div id="comments">
              <div id="comment_list">
               <?php echo!(empty($comments)) ? $comments : ""; ?>
              </div>
              <div id ="display_comment_form">
               <?php
                $reference_table = 'hr_payroll_payment_method';
                $reference_id = $$class->hr_payroll_payment_method_id;
               ?>
              </div>
              <div id="new_comment">
              </div>
             </div>
            </div>
           </div>
          </div>

         </div>
        </div>
        <div id ="form_line" class="form_line"><span class="heading">Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Accounts</a></li>
           <li><a href="#tabsLine-2">Bank Details</a></li>
           <li><a href="#tabsLine-3">Costing</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div>            
             <ul class="column four_column"> 
              <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_bank_account_id select_popup clickable">
                Bank Account Id : </label> <?php $f->text_field_d('bank_account_id') ?>
              </li> 
              <li><label>Cash Ac: </label><?php $f->ac_field_d('cash_ac_id'); ?></li>
              <li><label>Clearing Ac: </label><?php $f->ac_field_d('clearing_ac_id'); ?></li>
              <li><label>Bank Charge Ac: </label><?php $f->ac_field_d('bank_charge_ac_id'); ?></li>
             </ul> 
            </div> 
           </div> 
           <div id="tabsLine-2" class="tabContent">
            <div>            
             <ul class="column four_column"> 
              <li><label>Bank Name :</label> <?php $f->text_field_dr('bank_name') ?>	</li>
              <li><label>Branch Name : </label><?php $f->text_field_dr('branch_name') ?> </li>
              <li><label>Account Number : </label> <?php $f->text_field_dr('account_number') ?>	</li>
              <li><label>Usage : </label> 
               <?php echo $f->select_field_from_array('account_usage', mdm_bank_account::$account_usage_a, $$class->account_usage, 'account_usage', '', '', 1, 1) ?>	</li>
              <li><label>Type : </label> 
               <?php echo $f->select_field_from_object('account_type', mdm_bank_account::bank_account_type(), 'option_line_code', 'option_line_value', $$class->account_type, 'account_type', '', '', 1) ?>	</li>
              <li><label>Description : </label> <?php $f->text_field_dr('account_description') ?>	</li>
              <li><label>Bank Number : </label><?php $f->text_field_dr('bank_number'); ?></li> 
              <li><label>Branch Number : </label><?php $f->text_field_dr('branch_number'); ?></li> 
              <li><label>Short Name: </label><?php $f->text_field_dr('bank_name_short'); ?></li> 
              <li><label>Alt Name : </label><?php $f->text_field_dr('bank_name_alt'); ?></li> 
              <li><label>IFSC : </label><?php $f->text_field_dr('ifsc_code'); ?></li> 
              <li><label>SWIFT : </label><?php $f->text_field_dr('swift_code'); ?></li> 
              <li><label>Routing : </label><?php $f->text_field_dr('routing_number'); ?></li> 
              <li><label>IBAN: </label><?php $f->text_field_dr('iban_code'); ?></li> 
             </ul>
            </div> 
           </div> 
           <div id="tabsLine-3"  class="tabContent">
            <div>
             <ul class="column four_column"> 
              <li><label>Cost Payment : </label><?php $f->checkBox_field_d('costed_cb'); ?></li>
             </ul> 
            </div> 
           </div>
          </div>
         </div> 
        </div> 
       </form>
      </div>
      <!--END OF FORM HEADER-->

     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_payroll_payment_method" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_payroll_payment_method_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_payroll_payment_method" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_payroll_payment_method_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_payroll_payment_method_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>