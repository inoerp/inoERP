<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="hr_employee_divId">
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
       <form action=""  method="post" id="hr_employee"  name="hr_employee"><span class="heading">Employee Header </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Personal</a></li>
           <li><a href="#tabsHeader-3">Contact</a></li>
           <li><a href="#tabsHeader-4">Attachments</a></li>
           <li><a href="#tabsHeader-5">Notes</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column five_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
                Employee Id : </label><?php $f->text_field_ds('hr_employee_id') ?>
               <a name="show" href="form.php?class_name=hr_employee" class="show hr_employee_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>First Name :</label><?php $f->text_field_d('first_name'); ?> 					</li>
              <li><label>Last Name :</label><?php $f->text_field_d('last_name'); ?> 					</li>
              <li><label>Title :</label><?php $f->text_field_d('title'); ?> 					</li>
              <li><label>Gender :</label><?php $f->text_field_d('gender'); ?> 					</li>
              <li><label>Person Type :</label><?php $f->text_field_d('person_type'); ?> 					</li>
              <li><label>Identification Type :</label><?php $f->text_field_d('identification_type'); ?> 					</li>
              <li><label>Identification No :</label><?php $f->text_field_d('gender'); ?> 					</li>
              <li><label>Citizen No :</label><?php $f->text_field_d('citizen_number'); ?> 					</li>
              <li><label>ORG Name : </label>
               <?php echo $f->select_field_from_object('org_id', org::find_all_enterprise(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
              </li>
              <li><label>Ledger Name : </label>
               <?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', $readonly, '', '', 1); ?>
              </li>
              <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column five_column"> 
              <li><label>DOB :</label><?php echo $f->date_fieldAnyDay('date_of_birth', $$class->date_of_birth); ?> </li>
              <li><label>Country Of Birth :</label>
               <?php echo $f->select_field_from_object('country_of_birth', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $$class->country_of_birth, '', 'country_code', '', $readonly); ?>              </li>
              <li><label>City Of Birth :</label><?php $f->text_field_d('city_of_birth'); ?> 					</li>
              <li><label>Nationality :</label><?php $f->text_field_d('nationality'); ?> 					</li>
              <li><label>Disability Code :</label><?php $f->text_field_d('disability_code'); ?> 					</li>
              <li><label>Marital Status :</label>
               <?php echo $f->select_field_from_object('marital_status', hr_empoyee::marital_status(), 'option_line_code', 'option_line_value', $$class->marital_status, '', 'marital_status', '', $readonly); ?>              </li>
              <li><label>No Of Children :</label><?php $f->text_field_d('no_of_children'); ?> 					</li>
              <li><label>Passport No :</label><?php $f->text_field_d('passport_number'); ?> 					</li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-3" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column five_column"> 
              <li><label>Home Phone :</label><?php echo $f->text_field_d('home_phone_number'); ?> </li>
              <li><label>Off. Phone :</label><?php echo $f->text_field_d('phone'); ?> </li>
              <li><label>Mobile :</label><?php echo $f->text_field_d('mobile_number'); ?> </li>
              <li><label>Email :</label><?php echo $f->text_field_d('email'); ?> </li>
              <li><label>Personal email :</label><?php $f->text_field_d('other_email'); ?> 			
              <li><label>Home Address :</label><?php $f->text_field_dl('home_address'); ?> 					</li>
              <li><label>Permanent Address :</label><?php $f->text_field_dl('permanent_address'); ?> 					</li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-4" class="tabContent">
            <div> <?php echo ino_attachement($file) ?> </div>
           </div>
           <div id="tabsHeader-5" class="tabContent">
            <div> 
             <div id="comments">
              <div id="comment_list">
               <?php echo!(empty($comments)) ? $comments : ""; ?>
              </div>
              <?php
               $reference_table = 'hr_employee';
               $reference_id = $$class->hr_employee_id;
               include_once HOME_DIR . '/comment.php';
              ?>
              <div id="new_comment">
              </div>
             </div>
            </div>
           </div>
          </div>

         </div>
        </div>
        <div id ="form_line" class="form_line"><span class="heading">Employee Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Assignments</a></li>
           <li><a href="#tabsLine-2">Financial Info</a></li>
           <li><a href="#tabsLine-3">Education</a></li>
           <li><a href="#tabsLine-4">Work Experience</a></li>
           <li><a href="#tabsLine-5">On Boarding</a></li>
           <li><a href="#tabsLine-6">Exit</a></li>
           <li><a href="#tabsLine-7">Job History</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div> 
             <ul class="column four_column"> 
              <li><label>First Name :</label><?php $f->text_field_d('first_name'); ?> 					</li>
              <li><label>First Name :</label><?php $f->text_field_d('last_name'); ?> 					</li>
              <li><label>Title :</label><?php $f->text_field_d('title'); ?> 					</li>
              <li><label>Gender :</label><?php $f->text_field_d('gender'); ?> 					</li>
             </ul> 
            </div> 
           </div> 
           <div id="tabsLine-2"  class="tabContent">
            <div> 

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
  <li class="headerClassName" data-headerClassName="hr_employee" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_employee_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_employee" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_employee_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_employee_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>