<div id="view_divId">
 <div id ="form_header"> <span class="heading"><?php echo gettext('Form Personalization') ?></span>
  <form   method="post" id="sys_form_personalization_header"  name="sys_form_personalization_header">
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div id="form_serach_header" class="tabContainer">
      <label><?php echo gettext('Object Name') ?></label></label>
			<?php echo $f->select_field_from_object('obj_class_name', extn_view::find_all_tables(), 'TABLE_NAME', 'TABLE_NAME', $obj_class_name_h, 'obj_class_name', 'action'); ?>
      <a name="show" href="form.php?class_name=sys_form_personalization&<?php echo "mode=$mode"; ?>" class="show document_id sys_form_personalization_id">
       <i class="fa fa-refresh"></i></a> 
     </div>
    </div>
   </div>
   <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Form Personalization Details') ?></span>
    <div id="tabsDetailD">
     <ul class="tabMain">
      <li><a href="#tabsDetailD-1"><?php echo gettext('Template Code') ?></a></li>
      <li><a href="#tabsDetailD-2"><?php echo gettext('Form View') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsDetailD-1" class="tabContent">
       <div class="well">Save the custom template @ <strong>themes\default\template</strong> as file name  <strong><?php echo $custom_template_file_name; ?></strong>
				&nbsp;&nbsp;&nbsp;&nbsp;<span id="update_form_view" role="button" class="btn btn-primary action">Refresh Form View</span>
       </div>
			 <?php
			 if (file_exists($file_name_fp)) {
				$file_content_fp = file_get_contents(($file_name_fp));
			 }
			 echo $f->text_area('template_code', ($file_content_fp), '20', 'template_code', '', ' ', '', '', ' ', 150);
			 ?>
      </div>
      <div id="tabsDetailD-2" class="tabContent">
			 <span id="update_form_view2" role="button" class="btn btn-primary action">Refresh Form View</span>
			 <div id="form_data">
					 <?php
					 if (!empty($file_content_fp)) {
						unset($class_names);
						unset($template_file_names);
						$class_names = $obj_class_name_h;
						include(HOME_DIR . '/includes/functions/loader.inc');
						if (!empty($template_file_names)) {
						 foreach ($template_file_names as $key => $tmpl_file) {
							include_once $tmpl_file;
						 }
						}
					 }
					 $class = 'sys_form_personalization';
					 $$class = new $class;
					 ?>
			 </div>

      </div>
     </div>
    </div>

	 </div>
	</form>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_form_personalization" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="obj_class_name" ></li>
  <li class="form_header_id" data-form_header_id="sys_form_personalization" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_form_personalization_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_form_personalization" ></li>
 </ul>
</div>