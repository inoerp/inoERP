      <div id ="form_header">
       <form action=""  method="post" id="sys_extra_field_instance_form"  name="sys_extra_field_instance_form"><span class="heading">Extra Fields</span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Note</a></li>
           <li><a href="#tabsHeader-3">Attachments</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_extra_field_instance_id select_popup clickable">
                Field Id : </label> 
               <?php $f->text_field_dr('sys_extra_field_instance_id') ?>
               <a name="show" href="form.php?class_name=sys_extra_field_instance&<?php echo "mode=$mode"; ?>" class="show document_id sys_extra_field_instance_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li> 
              <li><label>Field Name :</label> <?php $f->text_field_dm('field_name'); ?>          </li>
              <li><label>Description :</label>                <?php form::text_field_wid('description'); ?>          </li>
              <li><label>Field Type :</label>
               <?php echo $f->select_field_from_object('field_type', sys_extra_field_instance::sys_extra_field_instance_type(), 'option_line_code', 'option_line_value', $$class->field_type, '', '', 1, $readonly1); ?>
              </li>
              <li><label>Display Type :</label>
               <?php echo $f->select_field_from_array('display_type', sys_extra_field_instance::$display_type_a, $$class->display_type); ?>
              </li>
              <li><label>Active ? :</label>
               <?php echo $f->checkBox_field('active_cb', $$class->active_cb); ?>
              </li>

             </ul>
            </div>
           </div>


           <div id="tabsHeader-2" class="tabContent">
            <div id="comments">
             <div id="comment_list">
              <?php echo!(empty($comments)) ? $comments : ""; ?>
             </div>
             <div id ="display_comment_form">
              <?php
               $reference_table = 'sys_extra_field_instance';
               $reference_id = $$class->sys_extra_field_instance_id;
              ?>
             </div>
             <div id="new_comment">
             </div>
            </div>
            <div> 
            </div>
           </div>
           <div id="tabsHeader-3" class="tabContent">
            <div> <?php echo ino_attachement($file) ?> </div>
           </div>
          </div>

         </div>
        </div>
        <div id ="form_line" class="form_line"><span class="heading"> Extra Field Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Instances</a></li>
           <li><a href="#tabsLine-2">Future</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">

           </div> 
           <!--end of tab1-->
           <div id="tabsLine-2" class="tabContent">
           </div>
          </div>


         </div>
        </div> 
       </form>
      </div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_extra_field_instance" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_extra_field_instance_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_extra_field_instance_form" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_extra_field_instance_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_extra_field_instance_id" ></li>
 </ul>
</div>