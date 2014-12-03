<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="sys_printer_divId">
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
       <form action=""  method="post" id="sys_printer"  name="sys_printer"><span class="heading">Printer </span>
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
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_printer_id select_popup clickable">
                printer Id : </label><?php $f->text_field_dsr('sys_printer_id') ?>
               <a name="show" href="form.php?class_name=sys_printer" class="show sys_printer_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
              </li>
              <li><label>Printer Name :</label><?php $f->text_field_dm('printer_name'); ?> 					</li>
              <li><label>Type :</label>
               <?php echo $f->select_field_from_object('printer_type', sys_printer::printer_type(), 'option_line_code', 'option_line_value', $$class->printer_type, 'printer_type'); ?>              </li>
              <li><label>Manufacturer :</label><?php $f->text_field_d('manufacturer'); ?> 					</li>
              <li><label>IP Address :</label><?php $f->text_field_dm('ip_address'); ?> 					</li>
              <li><label>Port # :</label><?php $f->text_field_dm('port_number'); ?> 					</li>
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
                $reference_table = 'sys_printer';
                $reference_id = $$class->sys_printer_id;
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
  <li class="headerClassName" data-headerClassName="sys_printer" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_printer_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_printer" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_printer_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_printer_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>