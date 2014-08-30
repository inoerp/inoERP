<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="hr_approval_object_divId">
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
       <form action=""  method="post" id="hr_approval_object"  name="hr_approval_object"><span class="heading">Approval Object </span>
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
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_approval_object_id select_popup clickable">
                Header Id : </label><?php $f->text_field_ds('hr_approval_object_id') ?>
               <a name="show" href="form.php?class_name=hr_approval_object" class="show hr_approval_object_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Object Code :</label><?php $f->text_field_d('object_code'); ?> 					</li>
              <li><label>Object Name :</label><?php $f->text_field_d('object_name'); ?> 					</li>
              <li><label>Value Type :</label>
               <?php echo $f->select_field_from_array('value_type', hr_approval_object::$value_type_a, $$class->value_type); ?> 					</li>
              <li><label>Return Type :</label><?php echo $f->select_field_from_array('return_type', hr_approval_object::$return_type_a, $$class->return_type);?> 					</li>
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
               $reference_table = 'hr_approval_object';
               $reference_id = $$class->hr_approval_object_id;
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
        <div id ="form_line" class="form_line"><span class="heading">Details  </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Object Value</a></li>
           <li><a href="#tabsLine-2">Future</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div><label class="text_area_label">Object Value  :</label><?php
              echo $f->text_area_ap(array('name' => 'object_value', 'value' => $$class->object_value,
               'row_size' => '10', 'column_size' => '90'));
             ?> 	
            </div> 
           </div> 
           <div id="tabsLine-2"  class="tabContent">

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
  <li class="headerClassName" data-headerClassName="hr_approval_object" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_approval_object_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_approval_object" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_approval_object_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_approval_object_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>