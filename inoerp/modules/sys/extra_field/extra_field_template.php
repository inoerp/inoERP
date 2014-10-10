<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="sys_extra_field_divId">
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
       <form action=""  method="post" id="sys_extra_field_form"  name="sys_extra_field_form"><span class="heading">Extra Fields</span>
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
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_extra_field_id select_popup clickable">
                Field Id : </label> 
               <?php $f->text_field_dr('sys_extra_field_id') ?>
               <a name="show" href="form.php?class_name=sys_extra_field" class="show sys_extra_field_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li> 
              <li><label>Field Name :</label> <?php $f->text_field_dm('field_name'); ?>          </li>
              <li><label>SYS Field Name :</label> <?php $f->text_field_dr('sys_field_name'); ?>          </li>
              <li><label>Field Type :</label>
               <?php echo $f->select_field_from_object('field_type', sys_extra_field::sys_extra_field_type(), 'option_line_code', 'option_line_value', $$class->field_type, 'field_type', '', 1, $readonly1); ?>
              </li>
              <li><label>Field Length :</label> <?php echo $f->number_field('field_length', $$class->field_length,'','field_length'); ?>          </li>
              <li><label>Display Type :</label>
               <?php echo $f->select_field_from_array('display_type', sys_extra_field::$display_type_a, $$class->display_type); ?>
              </li>
              <li><label>Active ? :</label>
               <?php echo $f->checkBox_field('active_cb', $$class->active_cb); ?>
              </li>
              <li><label>Description :</label>  <?php $f->text_field_dl('description'); ?>          </li>
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
               $reference_table = 'sys_extra_field';
               $reference_id = $$class->sys_extra_field_id;
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
            <?php
             if (empty($instances)) {
              echo "<h2> No Instances Found</h2>";
             }
            ?>
           </div> 
           <!--end of tab1-->
           <div id="tabsLine-2" class="tabContent">
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
  <li class="headerClassName" data-headerClassName="sys_extra_field" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_extra_field_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_extra_field_form" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_extra_field_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_extra_field_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>