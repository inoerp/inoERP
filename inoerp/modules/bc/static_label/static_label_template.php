<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bc_static_label_divId">
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
       <form action=""  method="post" id="bc_static_label"  name="bc_static_label"><span class="heading">Static Labels </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Notes</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column one_column"> 
              <li> 
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bc_static_label_id select_popup clickable">
                Label Id  </label><?php $f->text_field_dsr('bc_static_label_id') ?>
               <a name="show" href="form.php?class_name=bc_static_label" class="show bc_static_label_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Printer Name </label><?php echo $f->select_field_from_object('sys_printer_id', sys_printer::find_all(), 'sys_printer_id', 'printer_name', $$class->sys_printer_id, 'sys_printer_id'); ?> 					</li>
              <li><label>Label Type </label><?php echo $f->select_field_from_array('label_type', bc_static_label::$label_type_a,  $$class->label_type); ?>              </li>
              <li><label>Label Format </label><?php echo $f->select_field_from_object('bc_label_format_header_id', bc_label_format_header::find_all(), 'bc_label_format_header_id', 'format_name', $$class->bc_label_format_header_id, 'bc_label_format_header_id'); ?>              </li>
              <li><label>Status </label><?php $f->text_field_d('status'); ?> 					</li>
              <li><label>No Of Copies </label><?php echo $f->text_field_ap(array('name' => 'no_of_copies', 'value'=>'', 'id'=>'no_of_copies')); ?> 					</li>
              <li><button class="button" id="print_label">Print</button></li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div> 
             <div id="comments">
              <div id="comment_list">
               <?php echo!(empty($comments)) ? $comments : ""; ?>
              </div>
              <div id ="display_comment_form">
               <?php
               $reference_table = 'bc_static_label';
               $reference_id = $$class->bc_static_label_id;
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
  <li class="headerClassName" data-headerClassName="bc_static_label" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bc_static_label_id" ></li>
  <li class="form_header_id" data-form_header_id="bc_static_label" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bc_static_label_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bc_static_label_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>