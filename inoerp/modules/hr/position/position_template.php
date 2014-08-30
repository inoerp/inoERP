<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="hr_position_divId">
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
       <form action=""  method="post" id="hr_position"  name="hr_position"><span class="heading">Position Header</span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Terms</a></li>
           <li><a href="#tabsHeader-3">Attachments</a></li>
           <li><a href="#tabsHeader-4">Notes</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_position_id select_popup clickable">
                position Id : </label><?php $f->text_field_ds('hr_position_id') ?>
               <a name="show" href="form.php?class_name=hr_position" class="show hr_position_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Position Name :</label><?php $f->text_field_d('position_name'); ?> 					</li>
              <li><label>Organization :</label>
               <?php echo $f->select_field_from_object('org_id', org::find_all(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?> 					</li>
              <li><label>Start Date :</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
              <li><label>End Date :</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
              <li><label>Job Name :</label>
               <?php echo $f->select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class->job_id, '', 'job_id', '', $readonly); ?>              </li>
              <li><label>Status : </label><?php echo form::status_field($$class->position_status, $readonly); ?></li>
              <li><label>Description :</label><?php $f->text_field_dl('description'); ?> 					</li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column three_column"> 
              <li><label>Head Count :</label><?php $f->text_field_dl('headcount'); ?> 					</li>
              <li><label>Grade :</label><?php $f->text_field_dl('grade_id'); ?> 					</li>
              <li><label>Payroll :</label><?php $f->text_field_dl('payroll_id'); ?> 					</li>
              <li><label>Salary Basis :</label><?php $f->text_field_dl('salary_basis'); ?> 					</li>
              <li><label>Working Hours :</label><?php $f->text_field_dl('working_hours'); ?> 					</li>
              <li><label> Frequency :</label><?php $f->text_field_dl('wh_frequency'); ?> 					</li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-3" class="tabContent">
            <div> <?php echo ino_attachement($file) ?> </div>
           </div>
           <div id="tabsHeader-4" class="tabContent">
            <div> 
             <div id="comments">
              <div id="comment_list">
               <?php echo!(empty($comments)) ? $comments : ""; ?>
              </div>
              <div id ="display_comment_form">
               <?php
                $reference_table = 'hr_position';
                $reference_id = $$class->hr_position_id;
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
        <div id ="form_line" class="form_line"><span class="heading">Position Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Position Details</a></li>
           <li><a href="#tabsLine-2">Future</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div><label class="text_area_label">Position Details  :</label><?php
              echo $f->text_area_ap(array('name' => 'position_details', 'value' => $$class->position_details,
               'row_size' => '10', 'column_size' => '90'));
             ?> 	
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
  <li class="headerClassName" data-headerClassName="hr_position" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_position_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_position" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_position_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_position_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>