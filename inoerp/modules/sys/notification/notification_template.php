<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="sys_notification_divId">
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
       <form action=""  method="post" id="sys_notification"  name="sys_notification"><span class="heading">Notification </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Requirements</a></li>
           <li><a href="#tabsHeader-3">Attachments</a></li>
           <li><a href="#tabsHeader-4">Notes</a></li>

          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_notification_id select_popup clickable">
                Notification Id : </label><?php $f->text_field_dsr('sys_notification_id') ?>
               <a name="show" href="form.php?class_name=sys_notification" class="show sys_notification_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Notification Type :</label><?php $f->text_field_dr('notification_type'); ?> 					</li>
              <li><label>From :</label><?php $f->text_field_dr('from_user'); ?> 					</li>
              <li><label>To :</label><?php $f->text_field_dr('to_user'); ?> 					</li>

              <li><label>Start Date :</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
              <li><label>Status : </label>
               <?php echo $f->select_field_from_array('status', sys_notification::$status_a, $$class->status, '', '', '', '', 1); ?></li>
              <li><label>Message :</label><?php $f->text_field_dlr('notification_subject'); ?> 					</li>
              <li><label>Action : </label>
               <?php echo $f->select_field_from_array('notification_action', $$class->notification_action_a, ''); ?></li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column three_column"> 
              <li><label>To eMail:</label><?php $f->text_field_dr('to_email'); ?> 					</li>
              <li><label>Mail Status :</label><?php $f->text_field_dlr('mail_status'); ?> 					</li>
              <li><label>Responder :</label><?php $f->text_field_dlr('responder'); ?> 					</li>
              <li><label>Due Date :</label><?php echo $f->date_fieldAnyDay('due_date', $$class->due_date); ?> 	</li>
              <li><label>End Date :</label><?php echo $f->date_fieldAnyDay('end_date', $$class->end_date); ?> 	</li>
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
                $reference_table = 'sys_notification';
                $reference_id = $$class->sys_notification_id;
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
        <div id ="form_line" class="form_line"><span class="heading">Details & References </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Notification Details</a></li>
           <li><a href="#tabsLine-2">Responder Comment</a></li>
           <li><a href="#tabsLine-3">References</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div> <?php echo $$class->text_field1; echo $f->hidden_field('text_field1', $$class->text_field1); ?> 	  </div> 
           </div> 
           <div id="tabsLine-2" class="tabContent">
            <div><?php echo $f->text_area_ap(array('name' => 'responder_comment', 'value' => $$class->responder_comment, 'row_size' => '10', 'column_size' => '90')); ?>	
            </div> 
           </div> 
           <div id="tabsLine-3"  class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column three_column"> 
              <li><label>Reference Key :</label><?php $f->text_field_dlr('reference_key_name'); ?> 					</li>
              <li><label>Reference Value :</label><?php $f->text_field_dlr('reference_key_value'); ?> 					</li>
              <li><label>User Key Name :</label><?php $f->text_field_dlr('user_key_name'); ?> 					</li>
              <li><label>User Key Value :</label><?php $f->text_field_dlr('user_key_value'); ?> 					</li>
              <li><label>Reference Doc :</label><?php echo $$class->ref_doc_stmt; ?> 					</li>
              <li><label>From User Id :</label><?php $f->text_field_dsr('from_user_id'); ?> 					</li>
              <li><label>To User Id :</label><?php $f->text_field_dsr('to_user_id'); ?> 					</li>
              <li><label>Name :</label><?php $f->text_field_dr('notification_name'); ?> 					</li>
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
  <li class="headerClassName" data-headerClassName="sys_notification" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_notification_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_notification" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_notification_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_notification_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>