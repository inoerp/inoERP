<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
      echo (!empty($show_message)) ? $show_message : "";
      $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="bc_label_format_header"  name="bc_label_format_header"><span class="heading">Barcode Label Format </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bc_label_format_header_id select_popup clickable">
               Header Id : </label><?php $f->text_field_dsr('bc_label_format_header_id') ?>
              <a name="show" href="form.php?class_name=bc_label_format_header_id" class="show bc_label_format_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Label Format Name : </label><?php $f->text_field_d('format_name'); ?></li>
             <li><label>Label Type : </label><?php 
             echo $f->select_field_from_object('label_type', bc_label_format_header::label_type(),'option_line_code','option_line_value', $$class->label_type); ?></li>
             <li><label>Disable Date : </label><?php echo $f->date_fieldFromToday('disable_date',$$class->disable_date); ?></li>
             <li><label>Description: </label><?php $f->text_field_dl('description'); ?></li>
             <li><label>Default: </label><?php $f->checkBox_field_d('default_cb'); ?></li>
            </ul>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Template Fields </span>
       <form action=""  method="post" id="bc_label_format_line"  name="bc_label_format_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Basic Info </a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Seq#</th>
              <th>Line Id</th>
              <th>Object/Table Name</th>
              <th>Sys Field Name</th>
              <th>Field Name</th>
              <th>Field Description</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
             $count = 0;
             foreach ($bc_label_format_line_object as $bc_label_format_line) {
              if (!empty($$class_second->object_name)) {
               $sys_field_name_a = get_dbColumns_valIndex($$class_second->object_name);
              }else{
               $sys_field_name_a = [];
              }
              ?>         
              <tr class="bc_label_format_line<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img clickable"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->bc_label_format_line_id); ?>"></li>           
                 <li><?php echo form::hidden_field('bc_label_format_header_id', $bc_label_format_header->bc_label_format_header_id); ?></li>
                </ul>
               </td>
               <td><?php $f->seq_field_d($count) ?></td>
               <td><?php echo $f->text_field('bc_label_format_line_id', $$class_second->bc_label_format_line_id, '8'); ?></td>
               <td><?php echo $f->select_field_from_object('object_name', view::find_all_tables_and_views(), 'TABLE_NAME', 'TABLE_NAME', $$class_second->object_name,'','medium',1); ?> </td>
               <td><?php echo $f->select_field_from_array('sys_field_name', $sys_field_name_a, $$class_second->sys_field_name, '', 'medium', 1);  ?> </td>
               <td><?php echo $f->text_field_wid2l('field_name'); ?></td>
               <td><?php echo $f->text_field_wid2l('description'); ?></td>
               </tr>
              <?php
              $count = $count + 1;
             }
             ?>
            </tbody>
           </table>
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
  <li class="headerClassName" data-headerClassName="bc_label_format_header" ></li>
  <li class="lineClassName" data-lineClassName="bc_label_format_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bc_label_format_header_id" ></li>
  <li class="form_header_id" data-form_header_id="bc_label_format_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="bc_label_format_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bc_label_format_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bc_label_format_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>