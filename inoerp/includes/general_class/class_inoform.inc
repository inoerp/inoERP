<?php

/*
 * textfields
 * numberfields
 * accounfields
 * textarea
 */

class inoform {

// protected static $table_name = "inoform";
 public static $primary_column = "inoform_id";
 public static $key_column = 'form_name';
 public static $module = "sys";
 //  data base variables as stored database column name
 public static $field_a = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
 ];
 public $column = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
 ];
 public $numberField = [
 ];
 public $requiredField = [
  "form_name",
  "description",
  "class_name",
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=inoform',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public static $docs_notAllowd_inDirectWebForm = [
  'bom_cost_type',
  'bom_material_element',
  'coa',
  'enterprise',
  'gl_calendar',
  'gl_ledger',
  'gl_period',
  'role_access',
  'site_info',
  'transaction_type',
  'uom',
  'bc_label_format_header',
  'bc_static_label',
  'bc_label_format_line',
  'bc_label_auto_trigger',
  'sys_process_flow_line',
  'sys_process_flow_header',
  'cc_co_template_header',
  'cc_co_template_line',
  'sd_document_type',
  'ap_payment_terms',
  'ar_receipt_source',
  'ar_transaction_source',
  'ar_transaction_type',
  'bom_department',
  'bom_dept_res_assignment',
  'bom_overhead',
  'bom_oh_rate_assignment',
  'bom_oh_res_assignment',
  'bom_resource',
  'bom_resource_cost',
  'business',
  'hr_approval_limit_assign',
  'hr_approval_limit_header',
  'hr_approval_limit_line',
  'hr_approval_object',
  'hr_compensation_element',
  'hr_control',
  'hr_element_entry_header',
  'hr_element_entry_line',
  'hr_element_entry_tpl_header',
  'hr_element_entry_tpl_line',
  'hr_job',
  'hr_leave_type',
  'hr_payroll',
  'hr_payroll_payment_method',
  'hr_payroll_schedule',
  'hr_position',
  'hr_pos_hierarchy_header',
  'hr_pos_hierarchy_line',
  'inventory',
  'item_status',
  'legal',
  'mdm_tax_code',
  'mdm_tax_region',
  'mdm_tax_rule',
  'org',
  'payment_term',
  'payment_term_discount',
  'payment_term_schedule',
  'po_purchasing_control',
  'po_header',
  'role_path',
  'sd_shipping_control',
  'sys_document_sequence',
  'sys_extra_field',
  'sys_extra_field_instance',
  'sys_hold_reference',
  'sys_notification_group',
  'wip_control',
  'fp_planning_control',
  'sd_document_type',
  'am_activity_reference',
  'am_asset',
  'ar_customer',
  'ar_customer_bu',
  'ar_customer_site',
  'bom_commonbom_line',
  'bom_config_header',
  'bom_config_line',
  'bom_header',
  'bom_line',
  'bom_routing_detail',
  'bom_routing_header',
  'bom_routing_line',
  'bom_standard_operation',
  'bom_stnd_op_res_assignment',
  'common_bom_line',
  'cst_item_cost_header',
  'cst_item_cost_line',
  'cst_item_cost_line_pre',
  'ext_test_case_header',
  'ext_test_case_line',
  'fa_asset',
  'fa_asset_assignment',
  'fa_asset_book',
  'fa_asset_book_info',
  'fa_asset_category',
  'fa_book_category_assoc',
  'fa_depreciation_method',
  'fa_depreciation_method_rate',
  'fp_forecast_group',
  'fp_forecast_header',
  'fp_mds_header',
  'fp_mrp_header',
  'gl_balance',
  'gl_currency_conversion',
  'hr_employee',
  'hr_employee_education',
  'hr_employee_experience',
  'hr_employee_termination',
  'hr_leave_balance',
  'hr_leave_entitlement_header',
  'hr_leave_entitlement_line',
  'hr_leave_transaction',
  'hr_payslip_header',
  'hr_payslip_line',
  'hr_team_header',
  'hr_team_line',
  'inv_abc_assignment_header',
  'inv_abc_assignment_line',
  'inv_abc_valuation',
  'inv_abc_valuation_result',
  'inv_item_revision',
  'inv_location_default',
  'item',
  'locator',
  'mdm_bank_account',
  'mdm_bank_header',
  'mdm_bank_site',
  'mdm_price_list_header',
  'mdm_price_list_line',
  'po_asl_document',
  'po_requisition_header',
  'po_quote_header',
  'po_asl_header',
  'po_asl_line',
  'po_sourcing_rule_header',
  'po_sourcing_rule_line',
  'pos_barcode_list_header',
  'pos_barcode_list_line',
  'pos_inv_control',
  'sd_document_relation',
  'sd_sales_control',
  'sd_store',
  'sd_store_subinventory',
  'subinventory',
  'supplier',
  'supplier_bu',
  'supplier_site',
  'sys_printer',
  'sys_secondary_field',
  'sys_secondary_field_inst',
  'user_dashboard_config',
  'user_group',
  'user_group_access',
  'wip_accounting_group'
 ];
 public $pageTitle = " inoFrom - All Forms "; //page Title
 public $option_lists = [
//		 'supplier_type' => 'SUPPLIER_TYPE',
 ];
 public $inoform_id;
 public $_form_name;
 public $_description;
 public $_class_name;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $current_page_path = "";
 public $readonly;
 public $readonly1;
 public $readonly2;
 public $readonly3;
 public $readonly4;
 public $ac_field_length = 28;
 public $no_of_columns_per_tab = 9;
 public $data_arrOfObjs;
 public $action_message = 'Comments';
 public $column_array_s;
 public static $time_a = [
  '00:00:00' => '12:00 AM',
  '00:15:00' => '12:15 AM',
  '00:30:00' => '12:30 AM',
  '00:45:00' => '12:45 AM',
  '01:00:00' => '1:00 AM',
  '01:15:00' => '1:15 AM',
  '01:30:00' => '1:30 AM',
  '01:45:00' => '1:45 AM',
  '02:00:00' => '2:00 AM',
  '02:15:00' => '2:15 AM',
  '02:30:00' => '2:30 AM',
  '02:45:00' => '2:45 AM',
  '03:00:00' => '3:00 AM',
  '03:15:00' => '3:15 AM',
  '03:30:00' => '3:30 AM',
  '03:45:00' => '3:45 AM',
  '04:00:00' => '4:00 AM',
  '04:15:00' => '4:15 AM',
  '04:30:00' => '4:30 AM',
  '04:45:00' => '4:45 AM',
  '05:00:00' => '5:00 AM',
  '05:15:00' => '5:15 AM',
  '05:30:00' => '5:30 AM',
  '05:45:00' => '5:45 AM',
  '06:00:00' => '6:00 AM',
  '06:15:00' => '6:15 AM',
  '06:30:00' => '6:30 AM',
  '06:45:00' => '6:45 AM',
  '07:00:00' => '7:00 AM',
  '07:15:00' => '7:15 AM',
  '07:30:00' => '7:30 AM',
  '07:45:00' => '7:45 AM',
  '08:00:00' => '8:00 AM',
  '08:15:00' => '8:15 AM',
  '08:30:00' => '8:30 AM',
  '08:45:00' => '8:45 AM',
  '09:00:00' => '9:00 AM',
  '09:15:00' => '9:15 AM',
  '09:30:00' => '9:30 AM',
  '09:45:00' => '9:45 AM',
  '10:00:00' => '10:00 AM',
  '10:15:00' => '10:15 AM',
  '10:30:00' => '10:30 AM',
  '10:45:00' => '10:45 AM',
  '11:00:00' => '11:00 AM',
  '11:15:00' => '11:15 AM',
  '11:30:00' => '11:30 AM',
  '11:45:00' => '11:45 AM',
  '12:00:00' => '12:00 PM',
  '12:15:00' => '12:15 PM',
  '12:30:00' => '12:30 PM',
  '12:45:00' => '12:45 PM',
  '13:00:00' => '1:00 PM',
  '13:15:00' => '1:15 PM',
  '13:30:00' => '1:30 PM',
  '13:45:00' => '1:45 PM',
  '14:00:00' => '2:00 PM',
  '14:15:00' => '2:15 PM',
  '14:30:00' => '2:30 PM',
  '14:45:00' => '2:45 PM',
  '15:00:00' => '3:00 PM',
  '15:15:00' => '3:15 PM',
  '15:30:00' => '3:30 PM',
  '15:45:00' => '3:45 PM',
  '16:00:00' => '4:00 PM',
  '16:15:00' => '4:15 PM',
  '16:30:00' => '4:30 PM',
  '16:45:00' => '4:45 PM',
  '17:00:00' => '5:00 PM',
  '17:15:00' => '5:15 PM',
  '17:30:00' => '5:30 PM',
  '17:45:00' => '5:45 PM',
  '18:00:00' => '6:00 PM',
  '18:15:00' => '6:15 PM',
  '18:30:00' => '6:30 PM',
  '18:45:00' => '6:45 PM',
  '19:00:00' => '7:00 PM',
  '19:15:00' => '7:15 PM',
  '19:30:00' => '7:30 PM',
  '19:45:00' => '7:45 PM',
  '20:00:00' => '8:00 PM',
  '20:15:00' => '8:15 PM',
  '20:30:00' => '8:30 PM',
  '20:45:00' => '8:45 PM',
  '21:00:00' => '9:00 PM',
  '21:15:00' => '9:15 PM',
  '21:30:00' => '9:30 PM',
  '21:45:00' => '9:45 PM',
  '22:00:00' => '10:00 PM',
  '22:15:00' => '10:15 PM',
  '22:30:00' => '10:30 PM',
  '22:45:00' => '10:45 PM',
  '23:00:00' => '11:00 PM',
  '23:15:00' => '11:15 PM',
  '23:30:00' => '11:30 PM',
  '23:45:00' => '11:45 PM',
 ];

 public static function form_button_withImage_new1($current_page_path = "", $homeUrl = '') {
  $home_url_wos = rtrim(HOME_URL, '/');
  $homeUrl = empty($homeUrl) ? $home_url_wos : $homeUrl;
  if (empty($current_page_path)) {
   $current_page_path = thisPage_url();
  }
  echo '
			 <ul id="form_top_image" class="draggable">
      	<li id="refresh_buttonsave" title="' . gettext('Refresh & Reload The Page') . '"><button type="button" class="img-button"><i class="fa fa-refresh"></i>' . gettext('Refresh') . '</button></li>
        <li><a class="img-button clickable" Title="' . gettext('Create a New Document') . '" id="new_page_button" href="'.$current_page_path.'"><i class="fa fa-file-text-o"></i> ' . gettext('New') . '</a></li>
    		<li id="save" title="' . gettext('Save The Form') . '"><button type="button" class="img-button"><i class="fa fa-save"></i> ' . gettext('Save') . '</button></li>
        <li><a class="fa fa-eraser clickable" Title="' . gettext('Clear All, Quick Entry') . '" id="new_object_button" href="'.$current_page_path.'"></a></li>
        <li class="fa fa-trash-o clickable" id="delete_button" title="' . gettext('Delete') . '"></li>
        <li class="fa fa-remove clickable" id="remove_row_button" title="' . gettext('Remove') . '"></li>
        <li class="fa fa-print clickable print" id="print_searchResult" title="' . gettext('Print') . '"></li>
</ul>
';
 }

 public static function form_button_withImage($current_page_path = "", $homeUrl = '') {
  global $class, $si;
  $current_page_path = 'form.php?mode=9&amp;class_name=' . $class;
  echo '
			 <ul id="form_top_image" class="draggable">
        <li class="fa fa-refresh clickable ino-btn2 " id="refresh_button" title="' . gettext('Refresh') . '" style="background-color: $si->heading_color" ></li>
        <li class="fa fa-file-text-o clickable ino-btn2" Title="' . gettext('New Document') . '" id="new_page_button" href="'.$current_page_path.'" style="background-color: $si->heading_color"></li>
    		<li class="fa fa-save clickable ino-btn2" id="save" title="' . gettext('Save') . '" style="background-color: $si->heading_color" ></li>
        <li class="fa fa-eraser clickable ino-btn2" Title="' . gettext('Clear All, Quick Entry') . '" id="new_object_button" href="'.$current_page_path.'" style="background-color: $si->heading_color"></li>
        <li class="fa fa-trash-o clickable ino-btn2" id="delete_button" title="' . gettext('Delete') . '" style="background-color: $si->heading_color"></li>
        <li class="fa fa-remove clickable ino-btn2" id="remove_row_button" title="' . gettext('Remove') . '" style="background-color: $si->heading_color" ></li>
        <li class="fa fa-search-plus clickable query_mode_icon ino-btn2" id="start_query_mode" title="' . gettext('Query Mode') . '" style="background-color: $si->heading_color"></li>
        <li class="fa fa-print clickable print ino-btn2" id="print_searchResult" title="' . gettext('Print') . '" style="background-color: $si->heading_color"></li>
</ul>
';
 }
 
  public static function xx_btn_form_button_withImage($current_page_path = "", $homeUrl = '') {
  global $class;
  $current_page_path = 'form.php?mode=9&amp;class_name=' . $class;
  echo '
			 <ul id="form_top_image" class="draggable">
        <li class="fa fa-refresh clickable btn btn-default" id="refresh_button" title="' . gettext('Refresh') . '"></li>
        <li class="fa fa-file-text-o clickable btn btn-default" Title="' . gettext('New Document') . '" id="new_page_button" href="'.$current_page_path.'"></li>
    		<li class="fa fa-save clickable btn btn-default" id="save" title="' . gettext('Save') . '"></li>
        <li class="fa fa-eraser clickable btn btn-default" Title="' . gettext('Clear All, Quick Entry') . '" id="new_object_button" href="'.$current_page_path.'"></li>
        <li class="fa fa-trash-o clickable btn btn-default" id="delete_button" title="' . gettext('Delete') . '"></li>
        <li class="fa fa-remove clickable btn btn-default" id="remove_row_button" title="' . gettext('Remove') . '"></li>
        <li class="fa fa-search-plus clickable query_mode_icon btn btn-default" id="start_query_mode" title="' . gettext('Query Mode') . '"></li>
        <li class="fa fa-print clickable print btn btn-default" id="print_searchResult" title="' . gettext('Print') . '"></li>
</ul>
';
 }

 public static function form_button_withImage_less($current_page_path = "", $homeUrl = '') {
  global $class;
  $current_page_path = 'form.php?mode=9&amp;class_name=' . $class;
  echo '
			 <ul id="form_top_image" class="draggable">
        <li class="fa fa-refresh clickable" id="refresh_button" title="' . gettext('Refresh') . '"></li>
        <li><a class="fa fa-file-text-o clickable" Title="' . gettext('New Document') . '" id="new_page_button" href="'.$current_page_path.'"></a></li>
    		<li class="fa fa-save clickable" id="save" title="' . gettext('Save') . '"></li>
        <li><a class="fa fa-eraser clickable" Title="' . gettext('Clear All, Quick Entry') . '" id="new_object_button" href="'.$current_page_path.'"></a></li>
        <li class="fa fa-trash-o clickable" id="delete_button" title="' . gettext('Delete') . '"></li>
</ul>
';
 }

 public static function form_button_withImage_minimum($current_page_path = "", $homeUrl = '') {
  global $class, $si;
  $current_page_path = 'form.php?mode=9&amp;class_name=' . $class;
  echo '
			 <ul id="form_top_image" class="draggable">
        <li class="fa fa-file-text-o clickable ino-btn2" Title="' . gettext('New Document') . '" id="new_page_button" href="'.$current_page_path.'" style="background-color: $si->heading_color"></li>
        <li class="fa fa-trash-o clickable ino-btn2" id="delete_button" title="' . gettext('Delete') . '" style="background-color: $si->heading_color"></li>
</ul>
';
 }

 private function _convert_id($id = "") {
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  return $idvalue;
 }

 public function hidden_field($name, $value) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->hidden_field($field_name, $$class->$field_name);
 }

 public function hidden_field_withId($name, $value) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" id=\"$name\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_withCLass($name, $value, $class) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" name=\"$bracketName\" value=\"$value\" class=\"hidden $class $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_withIdClass($name, $value, $class) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" id=\"$name\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name $class\" >";
  return $element_hidden_field;
 }

 public function image_field($name, $value_file_id, $size = "15", $id = "", $div_class = "", $label = 'Select Image', $display_type = 'image') {
  $stmt = '<div class="ino-images">';
  $stmt .= "<div class='existing-image'>" . $this->show_existing_image($value_file_id, $div_class) . '</div>';
  $stmt .= "<div class='show_attachment'>";
  $stmt .= '<div class="form-group">
							<ul class="inRow asperWidth"><label for="exampleInputFile">' . gettext($label) . '</label>
							 <li><input type="file" id="img_attachments" class="attachments" value="" name="uploaded_file[]" multiple/></li>
              <li><input type="hidden" class="hidden display_type" name="display_type[]" value="' . $display_type . '"/></li>
              <li><input type="hidden" class="hidden file_id ' . $name . '" name="' . $name . '[]" value="' . $value_file_id . '"/></li>
							 <li><button  form="file_upload" name="attach_submit" class="submit button upload_file">' . gettext('Upload') . '</button></li>';
  $stmt .= '<li role="button" class="delete_image btn btn-danger "  name="delete_image" data-extn_image_reference_id="'.$value_file_id.'">' . gettext('Delete Image') . '</li>';
  $stmt.='<li class="show_loading_small"><img alt="Loading..." src="' . HOME_URL . 'themes/images/small_loading.gif"/></li>
							</ul>
							<div class="uploaded_file_details"></div>
						 </div>';
  $stmt .= '</div>';
  $stmt .= '</div>';

  return $stmt;
 }

 public function show_existing_image($value, $div_class, $full_size_on_hover = false) {
  if (empty($value)) {
   return;
  }
  $attachment_statement = '';
  $file = extn_file::find_by_id($value);
  if (empty($file)) {
   return;
  }
  $file_path = HOME_URL . $file->file_path . $file->file_name;
  $file_path_internal = HOME_DIR . DS . $file->file_path . $file->file_name;

  if (file_exists($file_path_internal)) {
   $attachment_statement .= "<div class=\"existing-image \">";
   $attachment_statement .= '<img class="img ' . $div_class . '" src="' . $file_path . '"/>';
   if ($full_size_on_hover) {
    $attachment_statement .= '<img class="img img-medium hidden-image' . '" src="' . $file_path . '"/>';
   }
   $attachment_statement .= "</div>";
  }


  return $attachment_statement;
 }

 public function val_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $val_field_class_n = '', $val_field_v = '', $dependent_field = '', $title = '') {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	  size=\"$size\" class=\"val_field textfield $div_class $name\" "
   . "data-val_value=\"$val_field_v\"  data-val_field=\"$val_field_class_n\" data-dependent_field=\"$dependent_field\"  $required $idvalue $readonly title=\"$title\"  data-toggle=\"tooltip\">";
  return $element_text_field;
 }

 public function text_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256", $disabled = '') {
  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $readonly_v = ($readonly == 1) ? ' readonly ' : '';
  $required_v = ($required == 1) ? ' required ' : '';
  $disabled_v = ($disabled == 1) ? ' disabled ' : '';

  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required_v $idvalue $readonly_v $disabled_v title=\"$title\"  data-toggle=\"tooltip\">";
  return $element_text_field;
 }

 
  public function color_field($name, $value, $id = "", $div_class = "", $required = "", $readonly = "" ) {
  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $readonly_v = ($readonly == 1) ? ' readonly ' : '';
  $required_v = ($required == 1) ? ' required ' : '';

  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"color\" name=\"$bracketName\" value=\"$value\"  class=\"color_field $div_class $name\"  $required_v $idvalue $readonly_v  data-toggle=\"tooltip\">";
  return $element_text_field;
 }
 
  public function l_color_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->color_field($field_name, $$class->$field_name,  $field_name, $div_class, '', $this->readonly);
 }
 
 public function email_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256", $disabled = '') {
  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $readonly_v = ($readonly == 1) ? ' readonly ' : '';
  $required_v = ($required == 1) ? ' required ' : '';
  $disabled_v = ($disabled == 1) ? ' disabled ' : '';

  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"email\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield emailfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required_v $idvalue $readonly_v $disabled_v title=\"$title\"  data-toggle=\"tooltip\">";
  return $element_text_field;
 }

 public function phone_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256", $disabled = '') {
  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $readonly_v = ($readonly == 1) ? ' readonly ' : '';
  $required_v = ($required == 1) ? ' required ' : '';
  $disabled_v = ($disabled == 1) ? ' disabled ' : '';

  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"tel\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield phonefield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required_v $idvalue $readonly_v $disabled_v title=\"$title\"  data-toggle=\"tooltip\">";
  return $element_text_field;
 }

 public function l_text_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256") {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->text_field($name, $value, $size, $id, $div_class, $required, $readonly, $place_holder, $title, $maxlength);
 }

 public function seq_field($value) {
  $this->text_field('seq_number', $value, '6', '', 'seq_number', '', 1);
 }

 public function gl_period_field($name, $ledger_id, $div_id = '', $div_class = 'medium', $req = '', $readonly = '') {
  global $f, $class, $$class;
  if (!empty($ledger_id)) {
   $ledger = new gl_ledger();
   $ledger_i = $ledger->findBy_id($ledger_id);
   if ($ledger_i) {
    $$class->currency = $ledger_i->currency_code;
   }
   $gp = new gl_period();
   $all_open_periods = $gp->find_all_periods($ledger_id, 'OPEN');
   if (empty($$class->$name)) {
    $$class->$name = $gp->current_open_period($ledger_id, 'OPEN')->gl_period_id;
   }
   $period_name_stmt = $f->select_field_from_object($name, $all_open_periods, 'gl_period_id', 'period_name', $$class->$name, $div_id, $div_class, $req, $readonly);
  } else {
   $period_name_stmt = $f->text_field_wid($name);
  }
  return $period_name_stmt;
 }

 public function l_gl_period_field($name, $ledger_id, $div_id = '', $div_class = 'medium', $req = '', $readonly = '') {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->gl_period_field($name, $ledger_id, $div_id, $div_class, $req, $readonly);
 }

 public function l_gl_period_field_d($name, $ledger_id) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->gl_period_field($name, $ledger_id, $name, 'medium');
 }

 public function l_gl_period_field_dm($name, $ledger_id) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->gl_period_field($name, $ledger_id, $name, 'medium', 1);
 }

 public function l_gl_period_field_dr($name, $ledger_id) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->gl_period_field($name, $ledger_id, $name, 'medium always_readonly', '', 1);
 }

 public function seq_field_d($value) {
  echo $this->text_field('seq_number', $value, '6', '', 'seq_number always_readonly', '', 1);
 }

 public function seq_field_detail_d($value) {
  echo $this->text_field('detail_seq_number', $value, '6', '', '', '', 1);
 }

 public function text_field_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $size = array_key_exists('size', $array) ? $array['size'] : "15";
  $maxlength = array_key_exists('maxlength', $array) ? $array['maxlength'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $place_holder = array_key_exists('place_holder', $array) ? $array['place_holder'] : null;
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('class_name', $array) ? $array['class_name'] : null;
  $title = array_key_exists('title', $array) ? $array['title'] : null;

  $bracketName = $name . '[]';
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\" >";
  return $element_text_field;
 }

 public function number_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $min = "", $max = "") {
  $bracketName = $name . '[]';
  $valueAfterDecimal = ino_showDecimal($value);
//	echo "$value : $valueAfterDecimal";
$valueAfterDecimal = htmlentities($valueAfterDecimal, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$valueAfterDecimal\"  size=\"$size\"
	 class=\"number $div_class $name\" placeholder=\"$place_holder\" "
   . "pattern=\"[0-9]+([\.][0-9]+)?\"  $required $idvalue $readonly title=\"$title\" >";
  return $element_text_field;
 }

 public function l_number_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $min = "", $max = "") {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->number_field($name, $value, $size, $id, $div_class, $required, $readonly, $place_holder, $title, $min, $max);
 }

 public function number_field_d($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_number_field_d($field_name, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_number_field_dr($field_name, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function l_number_field_dm($field_name, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1);
 }

 public function l_number_field_dsr($field_name, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  $field_name .=' small';
  echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function address_field($field_name, $div_class = "") {
  global $class, $$class;
  $text_field = $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
  $text_field .= '<img src="' . HOME_URL . 'themes/images/serach.png" class="address_id select_popup">';
  return $text_field;
 }

 public function add_new_address($existing_add_count = 0, $div_class = "") {
  global $class, $$class, $f, $ino_user;
  if (!empty($ino_user->email)) {
   $email = $ino_user->email;
  }
  $default_add_name = 'New Address ' . ($existing_add_count + 1);
  $add_field = '<div class="new-address">
        <ul class="column header_field address">';
  $add_field .= '<li><label>' . gettext('Address Name') . '</label>' . $f->text_field('addr_address_name', $default_add_name, '', '', '', 1) . '</li>';
  $add_field .= '<li><label>' . gettext('Phone') . '</label>' . $f->text_field('addr_phone', '') . '</li>';
  $add_field .= '<li><label>' . gettext('Email') . '</label>' . $f->text_field('addr_email', $email) . '</li>';
  $add_field .= '<li><label>' . gettext('Website') . '</label>' . $f->text_field('addr_website', '') . '</li>';
  $add_field .= '<li><label>' . gettext('Country') . '</label>' . $f->text_field('addr_country', '') . '</li>';
  $add_field .= '<li><label>' . gettext('Postal Code') . '</label>' . $f->text_field('addr_postal_code', '') . '</li>';
  $add_field .= '<li><label>' . gettext('Default') . '</label>' . $f->checkBox_field('addr_default_cb', '') . '</li>';
  $add_field .= '<li><label>' . gettext('Usage Type') . '</label>' . $f->select_field_from_object('addr_usage_type', option_header::find_options_byName('ADDRESS_USAGE_TYPE'), 'option_line_code', 'option_line_value', '', 'usage_type') . '</li>';
  $add_field .= '<li><label>' . gettext('Address') . '</label>' . form::text_area('addr_address', '', '3', '22', '', 'Complete Address', 'address') . '</li>';
  $add_field .= '<li class="hidden">' . $f->hidden_field('address_id', '') . '</li>';
  $add_field .= '</ul>
       </div>';

  return $add_field;
 }

 public function address_field_d($field_name, $show_all_fields = true, $div_class = "") {
  global $class, $$class;
  $ttl = $field_val = null;
  $addr = new address();
  if (!empty($$class->$field_name)) {
   $addr->findBy_id($$class->$field_name);
   if ($addr) {
    $field_val = $addr->address_name;
    $ttl = $addr->address . ' ' . $addr->country . ' ' . $addr->postal_code;
   }
  }
  $text_field = '<ul class="column header_field ' . $div_class . '">';
  $text_field .= '<li><label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  $field_class_name = $field_name . ' ' . $div_class;
  $text_field .= $this->val_field('address_name', $field_val, '15', '', $field_class_name, '', '', 'address', 'address_name');
  $text_field .= '<i class="fa fa-search address_id select_popup clickable"></i></li>';
  if ($show_all_fields) {
   $text_field .= '<li><label>' . gettext('Country') . '</label>' . $this->text_field('xxcountry', $addr->country, '15', '', 'country', '', 1) . '</li>';
   $text_field .= '<li><label>' . gettext('Postal Code') . '</label>' . $this->text_field('xxpostal_code', $addr->postal_code, '15', '', 'postal_code', '', 1) . '</li>';
   $text_field .= '<li><label>' . gettext('Details') . '</label>' . $this->text_area('xxaddress', $addr->address, '3', '', 'address', '', 1) . '</li>';
  }
  $text_field .= '<li>' . $this->hidden_field_withIdClass($field_name, $$class->$field_name, 'address_id') . '</li>';
  $text_field .= '</ul>';

  echo $text_field;
 }

 public function address_field_d2($field_name, $show_all_fields = true, $div_class = "") {
  global $class_second, $$class_second;
  $ttl = $field_val = null;
  $addr = new address();
  if (!empty($$class_second->$field_name)) {
   $text_field = $this->hidden_field_withIdClass($field_name, $$class_second->$field_name, 'address_id');
   $addr->findBy_id($$class_second->$field_name);
   if ($addr) {
    $field_val = $addr->address_name;
    $ttl = $addr->address . ' ' . $addr->country . ' ' . $addr->postal_code;
   }
  }

  $text_field = '<ul class="column header_field ' . $div_class . '">';
  $text_field .= '<li><label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  $text_field .= $this->hidden_field_withId($field_name, $$class_second->$field_name);
  $field_class_name = $field_name . ' ' . $div_class;
  $text_field .= $this->text_field('address_name', $field_val, '', '', $field_class_name, '', 1, '', $ttl);
  $text_field .= '<i class="fa fa-search address_id select_popup clickable"></i></li>';
  if ($show_all_fields) {
   $text_field .= '<li><label>' . gettext('Country') . '</label>' . $this->text_field('xxcountry', $addr->country, '', '', 'country', '', 1) . '</li>';
   $text_field .= '<li><label>' . gettext('Postal Code') . '</label>' . $this->text_field('xxpostal_code', $addr->postal_code, '', '', 'postal_code', '', 1) . '</li>';
   $text_field .= '<li><label>' . gettext('Details') . '</label>' . $this->text_area('xxaddress', $addr->address, '3', '', 'address', '', 1) . '</li>';
  }
  $text_field .= '</ul>';

  echo $text_field;
 }

 public function address_field_wid($field_name, $show_all_fields = true, $div_class = "") {
  global $class, $$class;
  $ttl = $field_val = null;
  if (!empty($$class->$field_name)) {
   $addr = address::find_by_id($$class->$field_name);
   if ($addr) {
    $field_val = $addr->address_name;
    $ttl = $addr->address . ' ' . $addr->country . ' ' . $addr->postal_code;
   }
  }
  $text_field = $this->hidden_field_withCLass($field_name, $$class->$field_name, $field_name);
  $field_class_name = 'address_name ' . $field_name . ' ' . $div_class;
  $text_field .= $this->text_field('address_name', $field_val, '', '', $field_class_name, '', 1, '', $ttl);
  $text_field .= '<img src="' . HOME_URL . 'themes/images/serach.png" class="address_id select_popup">';
  echo $text_field;
 }

 public function l_address_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
//  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->address_field_d($field_name, $div_class);
 }

 public function l_address_field_wid($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->address_field_wid($field_name, $div_class);
 }

 public function contact_field($ref_table, $reference_id = '', $all_contacts = '') {
  global $f;
  if (!empty($all_contacts)) {
   $_SESSION['comment_reference_table'] = $ref_table;
   $_SESSION['comment_reference_id'] = $reference_id;
   include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
  }
  $contact_stmt = '<div>
      <ul id="new_contact_reference">
       <li class="new_object1">
        <label>' . gettext('Associate Contact') .' </label> ';
  $contact_stmt .= $this->hidden_field_withCLass('extn_contact_id_new', '', 'extn_contact_id');
  $contact_stmt .= $this->val_field('contact_name_new', '', '20', '', 'select_contact contact_name', '', '', 'extn_contact', 'contact_name');
  $contact_stmt .='<i class="extn_contact_id select_popup clickable fa fa-search" data-class_name="extn_contact"></i> </li>
<li class="clickable" id="add_new_contact" title="New contact reference field"><i class="fa fa-plus-circle"></i></li>
</ul>
</div>';
  return $contact_stmt;
 }

//d - default , r- readonly, s- small size, m - mandatory
//textfields
 public function text_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function text_field_dd($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', '', '', '', '', 1);
 }

 public function val_field_d($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo $this->val_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_dm($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo $this->val_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_d($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_dm($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_d2($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_second, $$class_second;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_d2m($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_second, $$class_second;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_d3($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_third, $$class_third;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_val_field_d3m($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_third, $$class_third;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->val_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, 1, $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo $this->val_field($field_name, $$class->$field_name, '20', '', $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_widm($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class, $$class;
  echo $this->val_field($field_name, $$class->$field_name, '20', 1, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid2($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->val_field($field_name, $$class_second->$field_name, '20', '', $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid2m($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->val_field($field_name, $$class_second->$field_name, '20', '', $div_class, 1, $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid3($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->val_field($field_name, $$class_third->$field_name, '20', '', $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid3m($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->val_field($field_name, $$class_third->$field_name, '20', 1, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid4($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->val_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function val_field_wid4m($field_name, $val_field_n, $val_field_v, $dependent_field, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->val_field($field_name, $$class_fourth->$field_name, '20', 1, $div_class, '', $this->readonly, $val_field_n, $val_field_v, $dependent_field);
 }

 public function l_text_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_dd($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', '', '', '', '', 1);
 }

 public function l_text_field_ds($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_dr($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function l_text_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function l_text_field_d2($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_d2s($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_d2r($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function l_text_field_d2m($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function l_text_field_d_withSearch($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $search_class = gettext('Search'). ' ' . gettext(ucwords(str_replace('_', ' ', $class)));
  $search_class_gt = gettext($search_class);
  echo '<span class="big_popover"><a href="#" id="big_popover" ><i class="fa fa-search  clickable" 
                                                                  title="Click here to open the search form" data-toggle="tooltip" ></i></a>
 <div id="popover-head" class="hide">' . $search_class_gt .
  '<i title="Click Here To Make This Element Draggable"  class="fa fa-arrows medium small-left-padding make-draggable large-text clickable ">
  </i> <span  class="close_big_popover f-right medium large-text clickable" aria-hidden="true" title="Close This Window">&times;</span></div>
 <div id="popover-content" class="hide"><div id="search-popover">';
  $class_o = $class;
  $$class_o = $$class;
  include __DIR__ . '/../../popover_select.php';
  $class = $class_o;
  $$class = $$class_o;
  echo '</div></div></span>';
  echo '<label class="big_popover">' . gettext(trim(ucwords(str_replace('_', ' ', $field_name)))) . '</label>';
  $div_class .= 'search-text-field';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class);
 }

 public function l_text_field_dr_withSearch($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $search_class = gettext('Search'). ' ' . gettext(ucwords(str_replace('_', ' ', $class)));
  $search_class_gt = gettext($search_class);
  echo '<label class="big_popover">' . gettext(trim(ucwords(str_replace(['_', 'id'], [' ', ''], $field_name)))) . '</label>';
  echo '<span class="big_popover"><a href="#" id="big_popover" ><i class="fa fa-search  clickable" 
                                                                  title="Click here to open the search form" data-toggle="tooltip" ></i></a>
 <div id="popover-head" class="hide">' . $search_class_gt .
  '<i title="Click Here To Make This Element Draggable" class="fa fa-arrows small-left-padding make-draggable medium large-text clickable ">
  </i> <span  class="close_big_popover f-right medium large-text clickable" aria-hidden="true"  title="Close This Window">&times;</span></div>
 <div id="popover-content" class="hide"><div id="search-popover">';
  $class_o = $class;
  $$class_o = $$class;
  include __DIR__ . '/../../popover_select.php';
  $class = $class_o;
  $$class = $$class_o;
  echo '</div></div></span>';
  $div_class .= 'search-text-field';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function xxl_text_field_dr_withSearch($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . '<i class="fa fa-search-plus ' . $field_name . ' select_popup clickable" '
  . ' title="Click here to open the search form" data-toggle="tooltip"></i>';
  echo gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_ds($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, '', $this->readonly);
 }

 public function text_field_dr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function text_field_dl($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, '', $this->readonly);
 }

 public function text_field_dlm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, 1, $this->readonly);
 }

 public function text_field_dlr($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, '', 1);
 }

 public function text_field_dsr($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $field_name . " $div_class small";
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public function text_field_drm($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_dsrm($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_d2($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2s($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2sm($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, 1, $this->readonly2);
 }

 public function text_field_d2r($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_d2m($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, $this->readonly2);
 }

 public function text_field_d2l($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '40', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2sr($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public static function text_field_d2rm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_d2srm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_d3($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3s($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3r($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_d3m($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, 1, $this->readonly3);
 }

 public function text_field_d3l($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '40', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3sr($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public function text_field_d3rm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_d3srm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_wid($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, '', $this->readonly);
 }

 public function text_field_widl($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '40', '', $div_class, '', $this->readonly);
 }

 public function text_field_widlr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '40', '', $div_class, '', 1);
 }

 public function text_field_wids($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, '', $this->readonly);
 }

 public function text_field_widm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, 1, $this->readonly);
 }

 public function text_field_widr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_widrm($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_widsm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, 1, $this->readonly);
 }

 public function text_field_widsr($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_widsrm($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid2($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2s($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2l($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '40', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2m($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, 1, $this->readonly2);
 }

 public function text_field_wid2r($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $field_v = property_exists($$class_second, $field_name) ? $$class_second->$field_name : null;
  echo $this->text_field($field_name, $field_v, '20', '', $div_class, '', 1);
 }

 public function text_field_wid2rm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid2sm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, 1, $this->readonly2);
 }

 public function text_field_wid2sr($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid2srm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid3($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, '', $this->readonly3);
 }

 public function text_field_wid3s($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, '', $this->readonly3);
 }

 public function text_field_wid3m($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, 1, $this->readonly3);
 }

 public function text_field_wid3r($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_wid3rm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid3sm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, 1, $this->readonly3);
 }

 public function text_field_wid3sr($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid3srm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid4($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, '', $this->readonly4);
 }

 public function text_field_wid4s($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, '', $this->readonly4);
 }

 public function text_field_wid4m($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, 1, $this->readonly4);
 }

 public function text_field_wid4r($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_wid4rm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid4sm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, 1, $this->readonly4);
 }

 public function text_field_wid4sr($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid4srm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, 1, 1);
 }

 /* --------------------End of default text fields and begining of default number fields-------------
  * numberfields
  */

 public function l_email_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->email_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_email_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->email_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function l_phone_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->phone_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_phone_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->phone_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 /* --------------------End of default number fields and begining of accoun fields-------------
  * accounfields
  */

 public function account_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $ac_type = '', $place_holder = "", $title = "", $maxlength = "256") {
  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="combination_' . $id . '"';
  } else {
   $idvalue = "";
  }
  if (!empty($ac_type)) {
   $ac_type_i = " data-ac_type='{$ac_type}' ";
  } else {
   $ac_type_i = '';
  }
  $combination = null;
  if (!empty($value)) {
   $ac_d = $this->_get_account($value);
   $combination = $ac_d->combination;
   $title = $ac_d->description;
  }

  $element_text_field = '';
  if (!empty($id)) {
   $element_text_field .= $this->hidden_field_withIdClass($name, $value, 'coa_combination_id');
  } else {
   $element_text_field .= $this->hidden_field_withCLass($name, $value, 'coa_combination_id');
  }

  $element_text_field .= "<input type=\"text\" name=\"ac_combinations[]\" value=\"$combination\" 
                               maxlength=\"$maxlength\" size=\"$size\" class=\"combination $name textfield $div_class account_combination\" "
   . "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\"  data-toggle=\"tooltip\" $ac_type_i >";
  $element_text_field .= $this->accpup_stmt();
  return $element_text_field;
 }

 public function accpup_stmt() {
  //  return "<img src=\"" . HOME_URL . "/themes/images/serach.png\" class=\"account_popup select_popup clickable\" >";
  return '<i class="select_account select_popup clickable fa fa-search"></i>';
 }

 private function _get_account($ac_id = "") {
  $cc = new coa_combination();
  if (!empty($ac_id)) {
   $cc_i = $cc->findBy_id($ac_id);
   if ($cc_i) {
    return !empty($cc_i) ? $cc_i : $cc;
   } else {
    return $cc;
   }
  } else {
   return $cc;
  }
 }

 public function ac_field_d($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly, $ac_type);
 }

 public function l_ac_field_d($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly, $ac_type);
 }

 public function l_ac_field_dm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly, $ac_type);
 }

 public function l_ac_field_dr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type);
 }

 public function l_ac_field_drm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type);
 }

 public function ac_field_dm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly, $ac_type);
 }

 public function ac_field_dr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_drm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type);
 }

 public function ac_field_d2($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly2, $ac_type);
 }

 public function ac_field_d2m($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly2, $ac_type);
 }

 public function ac_field_d2r($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_d2rm($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type);
 }

 public function ac_field_d3($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly3, $ac_type);
 }

 public function ac_field_d3m($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly3, $ac_type);
 }

 public function ac_field_d3r($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_d3rm($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, "$div_class select_account", 'select_account', 1, 1, $ac_type);
 }

 public function ac_field_wid($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly, $ac_type);
 }

 public function ac_field_widm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly, $ac_type);
 }

 public function ac_field_widr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_widrm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  echo $this->account_field($field_name, $$class->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type);
 }

 public function ac_field_wid2($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly2, $ac_type);
 }

 public function ac_field_wid2m($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly2, $ac_type);
 }

 public function ac_field_wid2r($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_wid2rm($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  echo $this->account_field($field_name, $$class_second->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type);
 }

 public function ac_field_wid3($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $div_class = $div_class . ' select_account';
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly3, $ac_type);
 }

 public function ac_field_wid3m($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $div_class = $div_class . ' select_account';
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly3, $ac_type);
 }

 public function ac_field_wid3r($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type);
 }

 public function ac_field_wid3rm($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  echo $this->account_field($field_name, $$class_third->$field_name, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type);
 }

 /* --------------------End of default accoun fields and begining of text area -----------------------------
  * textarea
  */

 public function text_area($name, $value, $rowsize = "1", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $columnsize = "17") {
  $bracketName = $name . '[]';
  
//  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<textarea name=\"$bracketName\" 
                                 cols=\"$columnsize\" rows=\"$rowsize\" class=\"textfield $name $div_class \" title=\"$title\" placeholder=\"$place_holder\" $required $idvalue $readonly>$value</textarea>";
  return $element_text_field;
 }

 public function text_area_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_area($field_name, $$class->$field_name, '10', $field_name, $field_name . ' ' . $div_class, '', $this->readonly, '', '', '40');
 }

 public function l_text_area_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label class="text_area_label">' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_area($field_name, $$class->$field_name, '6', $field_name, $field_name . ' text_area_d ' . $div_class, '', $this->readonly, '', '', '40');
 }

 public function text_area_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  
  $columnsize = array_key_exists('column_size', $array) ? $array['column_size'] : "15";
  $rowsize = array_key_exists('row_size', $array) ? $array['row_size'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $place_holder = array_key_exists('place_holder', $array) ? $array['place_holder'] : null;
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('div_class', $array) ? $array['div_class'] : null;
  $title = array_key_exists('title', $array) ? $array['title'] : null;


  $bracketName = $name . '[]';
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_text_field = "<textarea name=\"$bracketName\" 
                                 cols=\"$columnsize\" rows=\"$rowsize\" class=\"textfield $name $div_class \" title=\"$title\" placeholder=\"$place_holder\" $required $idvalue $readonly>$value</textarea>";
  return $element_text_field;
 }

 public function date_field($name, $value, $size = "20", $id = "", $div_class = "", $required = "", $readonly = "", $with_time = '') {
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }

  if ($with_time == 1) {
   $with_time = 'date_with_time';
  } else {
   $with_time = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  $bracketName = $name . '[]';
  $value = ino_date($value);
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_date_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 	size=\"$size\" "
   . "class=\"date $with_time $div_class $readonly $name copy copyValue\"  $required $readonly $idvalue>";
  return $element_date_field;
 }

 public function dateTime_field($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateTime');
 }

 public function l_dateTime_field($name, $value) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'dateTime');
 }

 public function date_fieldFromToday($name, $value, $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  return $this->date_field($name, $value, '20', '', $divClass);
 }

 public function l_date_fieldFromToday($name, $value, $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', $divClass);
 }

 public function l_date_fieldFromToday_m($name, $value, $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', $divClass, 1);
 }

 public function l_date_fieldFromToday_dm($name, $value, $id = '', $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', $id, $divClass, 1);
 }

 public function l_date_fieldFromToday_d($name, $value, $id = '', $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', $id, $divClass);
 }

 public function date_field_MondayFromToday($name, $value) {
  return $this->date_field($name, $value, '20', '', 'MondayFromToday');
 }

 public function date_fieldFromToday_r($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', '', $readonly);
 }

 public function date_fieldFromToday_m($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', 1);
 }

 public function date_fieldFromToday_mr($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', 1, 1);
 }

 public function date_fieldFromToday_d($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday default_date');
 }

 public function date_fieldAnyDay($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  return $this->date_field($name, $value, '20', '', 'anyDate');
 }
 
  public function date_fieldAnyDay_gt($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate_gt';
  return $this->date_field($name, $value, '20', '', $div_class);
 }
 
   public function date_fieldAnyDay_lt($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate_lt';
  return $this->date_field($name, $value, '20', '', $div_class);
 }

 public function l_date_fieldAnyDay($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate');
 }

 public function l_date_fieldAnyDay_withTime($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate', '', '', 1);
 }

 public function l_date_fieldAnyDay_r($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate', '', 1);
 }

 public function l_date_fieldAnyDay_m($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate', 1);
 }

 public function l_date_fieldAnyDay_withTime_m($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate', 1, '', 1);
 }

 public function date_fieldAnyDay_r($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'anyDate', '', $readonly);
 }

 public function date_fieldAnyDay_m($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'anyDate', 1, $readonly);
 }

 public function select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
//  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }

  if ($disabled == 1) {
   $disabled = ' disabled ';
  } else {
   $disabled = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  $bracketName = $name . '[]';
  $idvalue = $this->_convert_id($id);
  $element_select_field = "<Select name=\"$bracketName\" class=\"from_array select $class_name $name\" $idvalue $required $readonly $disabled >";
  $element_select_field .= "<option value=\"\" >" . gettext('Select') . "</option>";
  foreach ($array as $key => $arraValue) {
   if (trim($key) == trim($value)) {
    $selected = 'selected';
   } else {
    $selected = '';
   }
   $element_select_field .= '<option value="' . $key . '" ';
   $element_select_field .= $selected;
   $element_select_field .= '>' . $arraValue . '</option>';
  }
  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function multi_select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
//  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }

  if ($disabled == 1) {
   $disabled = 'disabled';
  } else {
   $disabled = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  $bracketName = $name . '[]';
  $idvalue = $this->_convert_id($id);
  $element_select_field = "<Select multiple name=\"$bracketName\" class=\"from_array multi_select $class_name $name\" $idvalue $required $readonly $disabled >";
  $element_select_field .= "<option value=\"\" ></option>";
  foreach ($array as $key => $arraValue) {
   if ($key == $value) {
    $selected = 'selected';
   } else {
    $selected = '';
   }
   $element_select_field .= '<option value="' . $key . '" ';
   $element_select_field .= $selected;
   $element_select_field .= '>' . $arraValue . '</option>';
  }
  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function radio_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $divClass = "", $required = "", $readonly = "", $nonArrayName = "", $disabled = "") {
//  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }

  if ($readonly == 1) {
   $readonly = 'disabled';
  } else {
   $readonly = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  if ($disabled == 1) {
   $disabled = 'disbaled';
  } else {
   $disabled = '';
  }

  $element_radio_field = '<div id="radio-group">';
  if ((is_array($object)) && (count($object) > 0 )) {
   foreach ($object as $k => $record) {
    $ele_val = $record->$objectValueKey;
    $ele_label = $record->$objectDescriptionKey;
    if ((!empty($value)) && ($record->$objectValueKey == $value)) {
     $selected = ' checked ';
    } else {
     $selected = '';
    }
    $idvalue = "radio_{$name}_" . $k + 1;
    $element_radio_field .= "<input type='radio'  value=\"$ele_val\" name=\"$bracketName\" class=\"radio $divClass $name\"  ";
    $element_radio_field .= " id=\"$idvalue\" $readonly $required $disabled $selected >";
    $element_radio_field .= " <label for  id=\"$idvalue\"> $ele_label </label>";
   }
  }
  $element_radio_field .= '</div>';
  return $element_radio_field;
 }

 public function l_radio_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $divClass = "", $required = "", $readonly = "", $nonArrayName = "", $disabled = "") {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->radio_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value, $divClass, $required, $readonly, $nonArrayName, $disabled);
 }

 public function select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "", $dataname = '') {
 $value = htmlentities($value, ENT_QUOTES, 'UTF-8');
  $objectValueKey = strtolower($objectValueKey);
  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->_convert_id($id);
  if ($readonly == 1) {
   $readonly = 'disabled';
  } else {
   $readonly = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  if ($disabled == 1) {
   $disabled = 'disbaled';
  } else {
   $disabled = '';
  }
  $element_select_field = "<Select name=\"$bracketName\" class=\"select $divClass $name\" $idvalue $readonly $required $disabled>";
  $element_select_field .= "<option value=\"\" >" . gettext('Select') . "</option>";
  if ((is_array($object)) && (count($object) > 0 )) {
   foreach ($object as $record) {
    if ((!empty($value)) && ($record->$objectValueKey == $value)) {
     $selected = 'selected';
    } else {
     $selected = '';
    }
    
    $element_select_field .= '<option value="' . $record->$objectValueKey . '" ';
    $element_select_field .= $selected;
    if (!empty($dataname)) {
     if (is_array($dataname)) {
      foreach ($dataname as $dataname_k => $dataname_v) {
       $element_select_field .= " data-$dataname_v='" . $record->$dataname_v . "' ";
      }
     } else {
      $element_select_field .= " data-$dataname='" . $record->$dataname . "' ";
     }
    }
    $element_select_field .= '>';
    if (is_array($objectDescriptionKey)) {
     $newValue1 = '';
     foreach ($objectDescriptionKey as $keya => $valuea) {
      $newValue1 .= $record->$valuea . ' | ';
     }
     $newValue = rtrim($newValue1, ' | ');
    } else {
     $objectDescriptionKey = strtolower($objectDescriptionKey);
     $newValue = $record->$objectDescriptionKey;
    }
    $element_select_field .= $newValue;
    $element_select_field .= '</option>';
   }
  }

  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function l_select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "", $dataname = '') {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value, $id, $divClass, $required, $readonly, $convertToText, $nonArrayName, $disabled, $dataname);
 }

 public function l_select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->select_field_from_array($name, $array, $value, $id, $class_name, $required, $readonly, $disabled, $convertToText);
 }

 public function multi_select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "") {
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->_convert_id($id);
  if ($readonly == 1) {
   $readonly = 'disabled';
  } else {
   $readonly = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  if ($disabled == 1) {
   $disabled = 'disbaled';
  } else {
   $disabled = '';
  }
  $element_select_field = "<Select multiple name=\"$bracketName\" class=\"multi_select $divClass $name\" $idvalue $readonly $required $disabled>";
  $element_select_field .= "<option value=\"\" ></option>";
  if ((is_array($object)) && (count($object) > 0 )) {
   foreach ($object as $record) {
    if ((!empty($value)) && ($record->$objectValueKey == $value)) {
     $selected = 'selected';
    } else {
     $selected = '';
    }
    $element_select_field .= '<option value="' . $record->$objectValueKey . '" ';
    $element_select_field .= $selected;
    $element_select_field .= '>';
    if (is_array($objectDescriptionKey)) {
     $newValue1 = '';
     foreach ($objectDescriptionKey as $keya => $valuea) {
      $newValue1 .= $record->$valuea . ' - ';
     }
     $newValue = rtrim($newValue1, ' - ');
    } else {
     $newValue = $record->$objectDescriptionKey;
    }
    $element_select_field .= $newValue;
    $element_select_field .= '</option>';
   }
  }

  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function select_field_from_object_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $ob = array_key_exists('ob', $array) ? $array['ob'] : null;
  $ob_value = array_key_exists('ob_value', $array) ? $array['ob_value'] : null;
  $ob_desc = array_key_exists('ob_desc', $array) ? $array['ob_desc'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('div_class', $array) ? $array['div_class'] : null;
  $convertToText = array_key_exists('convertToText', $array) ? $array['convertToText'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $nonArrayName = array_key_exists('nonArrayName', $array) ? $array['nonArrayName'] : null;
  $disabled = array_key_exists('disabled', $array) ? $array['disabled'] : null;
  $dataname = array_key_exists('dataname', $array) ? $array['dataname'] : null;

  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->co($id);
  if ($readonly == 1) {
   $readonly = 'disabled';
  } else {
   $readonly = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  if ($disabled == 1) {
   $disabled = 'disabled';
  } else {
   $disabled = null;
  }

  $element_select_field = "<Select name=\"$bracketName\" class=\" select $div_class $name  \" $idvalue $readonly $required $disabled>";
  $element_select_field .= "<option value=\"\" ></option>";
  if ((is_array($ob)) && (count($ob) > 0 )) {
   foreach ($ob as $record) {
    if ((!empty($value)) && ($record->$ob_value == $value)) {
     $selected = 'selected';
    } else {
     $selected = '';
    }
    $element_select_field .= '<option value="' . $record->$ob_value . '" ';
    $element_select_field .= $selected;
    if (!empty($dataname)) {
     $element_select_field .= " data-$dataname='" . $record->$dataname . "' ";
    }
    $element_select_field .= '>';
    if (is_array($ob_desc)) {
     $newValue1 = '';
     foreach ($ob_desc as $keya => $valuea) {
      $newValue1 .= $record->$valuea . ' - ';
     }
     $newValue = rtrim($newValue1, ' - ');
    } else {
     $newValue = $record->$ob_desc;
    }
    $element_select_field .= $newValue;
    $element_select_field .= '</option>';
   }
  }

  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public static function extra_field($value, $size = '6', $readonly = "") {
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $element_extra_field = "<input type=\"text\" name=\"efid[]\" value=\"$value\" maxlength=\"200\" 
                               size=\"$size\" class=\"efid\" $readonly \>";
  return $element_extra_field;
 }

 public function checkBox_field($name, $value, $id = "", $class_name = "", $readonly = "") {
  $bracketName = $name . '[]';
  if ($readonly == 1) {
   $readonly = 'onclick="return false"';
  } else {
   $readonly = '';
  }
  if ($value == 1) {
   $checked = "checked";
  } else {
   $checked = "";
  }

  $element_extra_field = "<input type=\"checkbox\" name=\"$bracketName\"  class=\"checkBox $name $class_name \" id=\"$id\" 
                               value=\"1\"  $checked $readonly>";
  return $element_extra_field;
 }
 
  public function slider_checkBox_field($name, $value, $id = "", $class_name = "", $readonly = "") {
   $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $bracketName = $name . '[]';
  if ($readonly == 1) {
   $readonly = 'onclick="return false"';
  } else {
   $readonly = '';
  }
  if ($value == 1) {
   $checked = "checked";
  } else {
   $checked = "";
  }
  $element_extra_field =  '<label class="ino-checkbox switch">';
  $element_extra_field .= "<input type=\"checkbox\" name=\"$bracketName\"  class=\"checkBox $name $class_name \" id=\"$id\" 
                               value=\"1\"  $checked $readonly>";
  $element_extra_field .=  '<div class="slider"><span class="on-color">Yes</span><span class="off-color">No</span></div></label>';
  return $element_extra_field;
 }

 public function l_checkBox_field($name, $value, $id = "", $class_name = "", $readonly = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . ' </label>';
  echo $this->checkBox_field($name, $value, $id, $class_name, $readonly);
  echo '<div class="slider"><span class="on-color">ON</span><span class="off-color">OFF</span></div></label>';
 }

 public function l_checkBox_field_d($field_name) {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo '<label class="ino-checkbox switch">';
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', $this->readonly);
  echo '<div class="slider"><span class="on-color">Yes</span><span class="off-color">No</span></div></label>';
 }

 public function l_checkBox_field_dr($field_name) {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo '<label class="ino-checkbox switch">';
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', 1);
  echo '<div class="slider"><span class="on-color">Yes</span><span class="off-color">No</span></div></label>';
 }

 public function checkBox_field_d($field_name) {
  global $readonly, $class, $$class;
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', $this->readonly);
 }
 
  public function l_checkBox_field_d_ws($field_name) {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', $this->readonly);

 }

 public function checkBox_field_d2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->checkBox_field($field_name, $$class_second->$field_name, $field_name, '', $this->readonly);
 }

 public function checkBox_field_wid($field_name) {
  global $readonly, $class, $$class;
  echo $this->checkBox_field($field_name, $$class->$field_name, '', '', $this->readonly);
 }

 public function checkBox_field_wid2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->checkBox_field($field_name, $$class_second->$field_name, '', '', $this->readonly);
 }

 public function status_field($value, $readonly = "") {
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  $active = "";
  $inactive = "";
  if ($value == 'ACTIVE') {
   $active = 'selected';
  } elseif ($value == 'INACTIVE') {
   $inactive = 'selected';
  }
  if ($readonly == 1) {
   $readonly = 'disabled';
  } else {
   $readonly = '';
  }

  $element_text_field = "<Select name=\"status[]\" class=\"status select\" $readonly >";
  $element_text_field .= "<option value=\"\" ></option>";
  $element_text_field .= "<option value=\"ACTIVE\" $active > " . gettext('Active') . " </option>";
  $element_text_field .= "<option value=\"INACTIVE\" $inactive > " . gettext('Inactive') . " </option>";
  $element_text_field .= "</select>";
  return $element_text_field;
 }

 public function status_field_d($field_name) {
  global $readonly, $class, $$class;
  echo $this->status_field($$class->$field_name, $this->readonly);
 }

 public function l_status_field_d($field_name) {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->status_field($$class->$field_name, $this->readonly);
 }

 public function l_status_field_dr($field_name) {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->status_field($$class->$field_name, 1);
 }

 public function status_field_d2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->status_field($$class_second->$field_name, $this->readonly);
 }

 public function show_arrayData_in_tabularTable() {
  $drop_down_icon = ino_search_dropDownSettings();
  if (empty($this->column_array_s)) {
   foreach ($this->data_arrOfObjs[0] as $k => $v) {
    $this->column_array_s[] = $k;
   }
  }


  $total_columns = count($this->column_array_s) + 1; //1 for action
  $no_of_tabs = ceil($total_columns / $this->no_of_columns_per_tab);

  $stmt_rtn = '';
  $stmt_rtn .= '<div id="tabsLine">
 <ul class="tabMain">';
  for ($i = 0; $i < $no_of_tabs; $i++) {
   $stmt_rtn .= "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
  }
  $stmt_rtn .= ' </ul>
 <div class="tabContainer"> ';

  for ($i = 0; $i < $no_of_tabs; $i++) {
   $stmt_rtn .= "<div id=\"tabsLine-$i\" class='tabContent'>";
   $stmt_rtn .= "<table class=\"normal\"><thead><tr>";
   $stmt_rtn .= "<th>Seq#</th>";
   if ($i == 0) {
    $stmt_rtn .= "<th>" . $this->action_message . "</th>";
   }
   $new_start = ($i * ($this->no_of_columns_per_tab - 1)) + $i;
   $new_end = $new_start + ($this->no_of_columns_per_tab - 1);
   for ($j = $new_start; $j <= $new_end; $j++) {
    if ($j > $total_columns - 2) {
     break;
    }
    $stmt_rtn .= '<th data-field_name="' . $this->column_array_s[$j] . '">' . $drop_down_icon . ucwords(str_replace('_', ' ', $this->column_array_s[$j])) . '</th>';
   }
   $stmt_rtn .='</tr></thead>';
   If (!empty($this->data_arrOfObjs)) {
    $stmt_rtn .= '<tbody class="form_data_line_tbody search_data_arrOfObjss" >';
    $count = 0;
    foreach ($this->data_arrOfObjs as $record) {
     $count++;
     $stmt_rtn .='<tr>';
     $stmt_rtn .= "<td>$count</td>";
     if ($i == 0) {
      $stmt_rtn .= '<td class="search_data_arrOfObjs action">';

      $stmt_rtn .= '</td>';
     }
     $new_start = ($i * ($this->no_of_columns_per_tab - 1)) + $i;
     $new_end = $new_start + ($this->no_of_columns_per_tab - 1);
     for ($k = $new_start; $k <= $new_end; $k++) {
      if ($k > $total_columns - 2) {
       break;
      }
      $col_val = $this->column_array_s[$k];
      if (isset($record->$col_val)) {
       $stmt_rtn .= '<td>' . ucwords(str_replace('_', ' ', $record->$col_val)) . '</td>';
      } else {
       $stmt_rtn .= '<td> </td>';
      }
     }
     $stmt_rtn .= '</tr>';
    }
    $stmt_rtn .= '</tbody>';
   } else {
    $stmt_rtn .= gettext('No Records Found!');
   }
   $stmt_rtn .= '</table> </div>';
  }
  $stmt_rtn .= '</div> </div>';
  return $stmt_rtn;
 }

}

$inoform = new inoform();
$f = & $inoform;
//end of form class
?>
