<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * PO_HEADER_CLASS
 * Contains all the po header level information, such as - Supplier, Document Type, Currency, Addresses
 * Same for standard, blanket & planned POs
 */
class po_header extends dbObject {

 public static $table_name = "po_header";
 public static $dependent_classes = ['po_line', 'po_detail'];
 public static $primary_column = "po_header_id";
 public static $primary_column2 = "po_number";
 public static $primary_column3 = "release_number";
 public static $key_column = 'supplier_id';
 public static $module = "pur";
 public static $js_fileName = 'modules/po/js/multi_select.js';
 public static $system_info = [
		 'name' => 'Purchasing',
		 'number' => '2212',
		 'description' => 'Create & Mainten Purchase Order & Related documents/transactions',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('po_line', 'po_detail'),
		 'primary_entity_cb' => '',
		 'module_name' => 'po',
		 'weight' => 1
 ];
 private $_po_type_document_mapping = [
		 'STANDARD' => 'PUR_STANDRAD_PO',
		 'BLANKET' => 'PUR_BLANKET_AGGREMENT',
		 'EXTERNAL_REQUISITION' => 'PUR_REQUISITION_EXTERN',
		 'BLANKET_RELEASE' => 'PUR_BLANKET_RELEASE',
		 'CONTRACT' => 'PUR_CONTRACT_PO',
 ];
 public static $po_type_a = [
		 'STANDARD' => 'Standard Order',
		 'BLANKET' => 'Blanket Agreement',
		 'CONTRACT' => 'Contract Order',
 ];
 public $checkbox = [
		 "multi_bu_cb"
 ];
 public $action_a = [
		 'PRINT' => 'Print',
		 'APPROVE' => 'Approve',
		 'VIEW_HISTORY' => 'View History',
		 'CANCEL' => 'Cancel',
		 'RECEIVE' => 'Receive',
 ];
 public $field_a = [
		 'po_header_id',
		 'bu_org_id',
		 'ref_po_header_id',
		 'release_number',
		 'po_type',
		 'po_number',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'hr_employee_id',
		 "description",
		 'ship_to_id',
		 'bill_to_id',
		 'header_amount',
		 'tax_amount',
		 'price_list_header_id',
		 'currency',
		 'doc_currency',
		 'payment_term_id',
		 'agreement_start_date',
		 'agreement_end_date',
		 'exchange_rate_type',
		 'exchange_rate',
//   'released_amount',
		 "ef_id",
		 "po_status",
		 "multi_bu_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $profile_default = [
		 'exchange_rate_type' => 'gl_currency_conversion_type',
		 'bu_org_id' => 'org_bu_name_default',
		 'ship_to_id' => 'ship_to_address_default',
		 'bill_to_id' => 'bill_to_address_default'
 ];
 public $initial_search = [
		 'po_type',
		 "po_header_id",
		 "po_number",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "buyer"
 ];
 public $requiredField = [
		 'supplier_id',
		 'supplier_site_id',
		 'ship_to_id',
		 'bill_to_id',
		 'payment_term_id'
 ];
 public $addressField = [
		 'ship_to_id',
		 'bill_to_id'
 ];
 public $numberField = [
		 'header_amount',
		 'exchange_rate',
		 'tax_amount',
		 'po_header_id',
		 'bu_org_id',
		 'ref_po_header_id',
		 'supplier_id',
		 'supplier_site_id',
		 'ship_to_id',
		 'bill_to_id',
		 'price_list_header_id',
		 'payment_term_id',
 ];
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "ship_to_address",
		 "bill_to_address",
		 'multi_action_class_pc',
		 'multi_action_class_pc_value',
		 'action',
		 'ship_to_phone',
		 'ship_to_email',
		 'ship_to_address',
		 'ship_to_country',
		 'ship_to_postal_code',
		 'bill_to_phone',
		 'bill_to_email',
		 'bill_to_address',
		 'bill_to_country',
		 'bill_to_postal_code',
 ];
 public $fields_inDataBase_notInForm = [
		 'currency'
 ];
 public $search_functions = [
		 'Business Org' => 'search_business_org',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update PO',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
		 '_extra_path' => array('form.php?class_name=ap_transaction_header&mode=9' => 'Invoice',
				 'form.php?class_name=receipt_header&mode=9' => 'Receive')
 ];
 public static $json_label_fields = [
		 'po_number',
		 'release_number',
		 'bu_org_id',
		 'po_type',
		 'buyer',
		 "description",
		 'doc_currency',
		 "po_status",
 ];
 public $pageTitle = "Purchase Order"; //page Title
 public $option_lists = [
		 'po_type' => 'PO_TYPE',
		 'po_status' => 'PO_STATUS',
 ];
 public $po_header_id;
 public $bu_org_id;
 public $po_type;
 public $po_number;
 public $ref_po_header_id;
 public $release_number;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $hr_employee_id;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $header_amount;
 public $tax_amount;
 public $price_list_header_id;
 public $currency;
 public $doc_currency;
 public $payment_term_id;
 public $agreement_start_date;
 public $agreement_end_date;
 public $exchange_rate_type;
 public $exchange_rate;
//  public $released_amount;
 public $ef_id;
 public $po_status;
 public $multi_bu_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $ship_to_address;
 public $bill_to_address;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $bill_to_address_name;
 public $ship_to_phone;
 public $ship_to_address_name;
 public $ship_to_country;
 public $ship_to_postal_code;
 public $bill_to_phone;
 public $bill_to_country;
 public $bill_to_postal_code;
				 private$_po_status;
 private $_comment_msg;
 public $status;

 public function _before_delete() {
	$line_exists = po_line::find_by_parent_id($this->po_header_id);
	if ($line_exists) {
	 echo "<br>Delete is not allowed as PO Lines exists!. First delete lines and then try aagain ";
	 return -99;
	} else {
	 return 1;
	}
 }

 public function _before_save() {
	if (empty($this->po_header_id)) {
	 $this->po_status = 'ENTERED';
	} else if (empty($this->po_status)) {
	 $this->po_status = po_header::find_by_id($this->po_header_id)->po_status;
	}

	if ((!empty($this->po_header_id)) && !empty($this->po_status) && (in_array('$this->po_status', array('INPROCESS', 'FIN_CLOSED', 'CANCELLED')))) {
	 echo "You cant make changes to PO in process/re approval status. First get the PO approved";
	 return -99;
	}

	if (($this->action == 'CANCEL')) {
	 echo "<br> Cancelling Purchase Order ";
	 $this->_cancel_po();
	 return 10;
	}

	
	if($this->po_type =='BLANKET' && array_key_exists(1, $_POST['po_type'])){
	 $this->po_type = 'BLANKET_RELEASE';
	}

	if (($this->action == 'convert_requisition')) {
	 echo "<br> saving before PO SAVE";
	 $this->_convert_requisition_toDoc();
	 return 10;
	}

	if (empty($this->po_header_id) && !empty($this->bu_org_id)) {
	 $this->_do_initial_defaults();
	}
 }

 private function _cancel_po() {
	$this->po_status = 'CANCELLED';
	$this->update($this->po_header_id);
 }

 public function _after_save() {

	if ((!empty($this->po_header_id)) && empty($this->po_number)) {
	 $po_header_id = $this->po_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $this->po_number = $bu_org_id . '-' . $po_header_id;
	 echo ' System generated PO number is ' . $this->po_number;
	 $this->save();
	}

	if ((!empty($this->ref_po_header_id)) && empty($this->release_number) && !empty($this->po_header_id) && ($this->po_type == 'BLANKET_RELEASE')) {
	 $this->release_number = $this->_find_relNumber();
	 $this->save();
	}

	if (($this->action == 'APPROVE')) {
	 if (($this->po_type == 'BLANKET_RELEASE') && empty($this->release_number)) {
		echo "<br>You cant approve a relase with a release number";
		return -99;
	 } else {
		
	 }
	 $pur_control = po_purchasing_control::find_by_org_id($this->bu_org_id);
	 if (empty($pur_control->po_approval_hierarchy)) {
		$this->po_status = 'APPROVED';
		$this->audit_trial();
	 } else {
		$this->_approve_po($_SESSION['user_id'], $pur_control->po_approval_hierarchy);
	 }
	}
 }

 public function _before_showing() {
	$address = new address();
	if (!empty($this->ship_to_id)) {
	 $address_ship_to = $address->findBy_id($this->ship_to_id);
	 if (!empty($address_ship_to)) {
		$this->ship_to_address_name = isset($address_ship_to->address_name) ? $address_ship_to->address_name : '';
		$this->ship_to_address = isset($address_ship_to->address) ? $address_ship_to->address : '';
		$this->ship_to_country = isset($address_ship_to->country) ? $address_ship_to->country : '';
		$this->ship_to_postal_code = isset($address_ship_to->postal_code) ? $address_ship_to->postal_code : '';
		$this->ship_to_phone = isset($address_ship_to->phone) ? $address_ship_to->phone : '';
	 }
	}
	if (!empty($this->bill_to_id)) {
	 $address_bill_to = $address->findBy_id($this->bill_to_id);
	 if (!empty($address_bill_to)) {
		$this->bill_to_address_name = isset($address_bill_to->address_name) ? $address_bill_to->address_name : '';
		$this->bill_to_address = isset($address_bill_to->address) ? $address_bill_to->address : '';
		$this->bill_to_country = isset($address_bill_to->country) ? $address_bill_to->country : '';
		$this->bill_to_postal_code = isset($address_bill_to->postal_code) ? $address_bill_to->postal_code : '';
		$this->bill_to_phone = isset($address_bill_to->phone) ? $address_bill_to->phone : '';
	 }
	}
 }

 private function _approve_po($approving_user_id, $approval_hierarchy = '') {
	/* 1. Check the approval option for the BU - Employee Supervisor or Position Base
	  2. Find the employee details of the current user
	  3. Find the position(if not available then job) of the current employee
	  4. Get the approval limits of the position/job
	  5. If approval limit is good then approve the po
	  6. ELse create an approal notification for the superviosr/role and put the PO in inProcess
	 */
	$po_header_after_rev = new po_header();
	$po_header_after_rev->po_header_id = $this->po_header_id;
	$position_approval_details = hr_employee_position_v::find_by_userId_docType($approving_user_id, $this->_po_type_document_mapping[$this->po_type]);
	if (empty($position_approval_details)) {
	 echo "<br>No approval limit found";
	 return -99;
	}
	foreach ($position_approval_details as $obj) {
	 if ($obj->limit_object == 'TOTAL_AMOUNT') {
		$amount_limit = $obj->amount_limit;
		if ($amount_limit >= $this->header_amount) {
		 $po_header_after_rev->po_status = 'APPROVED';
		 $comment_msg = " PO Approved By $approving_user_id ";
		} else {
		 //create notification
		 $po_header_after_rev->po_status = 'INPROCESS';
		 $comment_msg = " Approval request is submitted by user id $approving_user_id ";
		}
	 }
	}
	if ($po_header_after_rev->po_status == 'INPROCESS') {
	 //create notification
	 $notif = new sys_notification();
	 $notif->notification_type = 'APPROVAL';
	 $notif->notification_name = 'PO_APPROVAL';
	 $notif->from_user_id = $approving_user_id;
//    $employee_details = hr_employee_p::find_by_id($this->employee_id);
	 $notif->from_user = $position_approval_details[0]->first_name . ' ' . $position_approval_details[0]->last_name;
	 if (empty($position_approval_details[0]->supervisor_employee_id)) {
		$comment_msg = " No Supervisor found for $notif->from_user ";
		$this->_write_comment($approving_user_id, $comment_msg);
		$po_header_after_rev->po_status = 'INCOMPLETE';
		$po_header_after_rev->audit_trial();
		$po_header_after_rev->save();
		return;
	 }
	 $supr_employee_details = hr_employee::find_by_id($position_approval_details[0]->supervisor_employee_id);
	 $supr_user_details = ino_user::find_by_employeeId($position_approval_details[0]->supervisor_employee_id);
	 $notif->to_user_id = $supr_user_details->user_id;
	 $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
	 $notif->to_email = $supr_employee_details->email;
	 $notif->reference_key_name = 'po_header';
	 $notif->reference_key_value = $this->po_header_id;
	 $notif->status = 'OPEN';
	 $notif->start_date = current_time(true);
	 $notif->notification_subject = "PO Approval From " . $notif->from_user . ' ' . gettext('PO') . '#' . $this->po_number;
	 $notif->notification_subject .=!empty($this->release_number) ? ' ' . gettext('Release') . ' #' . $this->release_number : '';
	 $notif->text_field1 = "<br>" . gettext('PO Type') . " : $this->po_type ";
	 $notif->text_field1 .= "<br>" . gettext('PO Number') . " : $this->po_number &nbsp;&nbsp; " . gettext('Amount') . " : $this->header_amount";
	 $notif->text_field1 .= "<br>" . gettext('Supplier') . " : $this->supplier_name (" . gettext('Supplier Id') . " : $this->supplier_id) ";
	 $notif->text_field1 .= "<br>" . gettext('Description') . " : $this->description ";
	 $notif->save();
	 $notif->_after_save();
	}
	$po_header_after_rev->approved_by = $position_approval_details[0]->first_name . ' ' . $position_approval_details[0]->last_name;
	$po_header_after_rev->approved_date = current_time();
	$po_header_after_rev->audit_trial();
	$po_header_after_rev->update_changesOnly($po_header_after_rev->po_header_id);
	$po_header_after_rev->write_comment($approving_user_id, $comment_msg);
 }

 private function _convert_requisition_toPO_header($i, &$PO_cretaed) {
	global $dbc;
	$header_amt = 0;
//   foreach($_POST['line_price'] as $amt_k => $amt_v ){
//    $header_amt += $amt_v;
//   }
	$poh = new po_header();
	$poh->bu_org_id = $_POST['bu_org_id'][$i];
	$poh->po_type = 'STANDARD';
//   pa($_POST);
	$poh->supplier_id = $_POST['supplier_id'][$i];
	$poh->supplier_site_id = $_POST['supplier_site_id'][$i];
	$poh->bill_to_id = org::find_by_id($_POST['bu_org_id'][$i])->address_id;
	$poh->ship_to_id = org::find_by_id($_POST['receving_org_id'][$i])->address_id;
	$poh->supplier_id = $_POST['supplier_id'][$i];
	$poh->currency = $_POST['currency'][$i];
	$supplier_site_details = supplier_site::find_by_id($poh->supplier_site_id);
	$poh->currency = $_POST['currency'][$i];
	$poh->doc_currency = $supplier_site_details->currency;
	if ($poh->currency != $poh->doc_currency) {
	 $poh->exchange_rate_type = 'CORP';
	}
	$poh->header_amount = .01;
	$poh->po_status = 'ENTERED';
	$poh->payment_term_id = $_POST['payment_term_id'][$i];
	if (empty($poh->payment_term_id)) {
	 $poh->payment_term_id = supplier_site::find_by_id($poh->supplier_site_id)->payment_term_id;
	}
	if (empty($poh->payment_term_id)) {
	 $poh->payment_term_id = po_purchasing_control::find_by_org_id($poh->bu_org_id)->payment_term_id;
	}
	$poh->audit_trial();
	$poh->save();
	echo "<br> PO header is succefully created. Header Id - " . $poh->po_header_id;
	$dbc->confirm();
	$record_saved = ['supplier_id' => $poh->supplier_id,
			'supplier_site_id' => $poh->supplier_site_id,
			'po_header_id' => $poh->po_header_id];
	array_push($PO_cretaed, $record_saved);
	return $poh->po_header_id;
 }

 private function _convert_requisition_toBPArelease($i, &$PO_cretaed) {
	global $dbc;
	$po_rd = new po_requisition_detail();
	$po_rd->findBy_id($_POST['po_requisition_detail_id'][$i]);
	if (!empty($po_rd->order_number)) {
	 return;
	}
	$po_rls = new po_header();
	$bpa_line = new po_line();
	$bpa_line->findBy_id($_POST['bpa_po_line_id'][$i]);
	$po_rls->findBy_id($bpa_line->po_header_id);
	$po_rls->ref_po_header_id = $po_rls->po_header_id;
	$po_rls->po_header_id = null;
	$po_rls->release_number = $po_rls->_find_relNumber($po_rls->po_header_id);
	$po_rls->po_type = 'BLANKET_RELEASE';
	$po_rls->po_status = 'ENTERED';
	$po_rls->save();
	echo "<br> PO Header is succefully created. Header Id - " . $po_rls->po_header_id;
	$line_number = 1;
	$pol = new po_line();
	foreach ($bpa_line as $k => $v) {
	 $pol->$k = $v;
	}
	$pol->po_line_id = null;
	$pol->line_number = $line_number;
	$pol->bpa_line_id = $bpa_line->po_line_id;
	$pol->line_type = 'GOODS';
	$pol->po_header_id = $po_rls->po_header_id;
	$pol->receving_org_id = $_POST['receving_org_id'][$i];
	$item = new item();
	$item->findBy_id($pol->item_id_m);
	$pol->item_description = $item->item_description;
	$pol->uom_id = $item->uom_id;
	$pol->line_quantity = $_POST['line_quantity'][$i];
	$pol->line_price = $pol->line_quantity * $pol->unit_price;
	$pol->reference_doc_type = 'po_requisition_details';
	$pol->reference_doc_number = $_POST['po_requisition_detail_id'][$i];
	$pol->save();
	echo "<br> PO Line is succefully created. Line Id - " . $pol->po_line_id;

	$pod = new po_detail();
	$pod->po_header_id = $po_rls->po_header_id;
	$pod->po_line_id = $pol->po_line_id;
	$pod->shipment_number = 1;
	$pod->need_by_date = $_POST['need_by_date'][$i];
	$inv = new inventory();
	$inv_i = $inv->findBy_org_id($pol->receving_org_id);
	//ac id needs to be modified to req accounts
	$pod->charge_ac_id = $inv_i->material_ac_id;
	$pod->accrual_ac_id = $inv_i->inv_ap_accrual_ac_id;
	$pod->ppv_ac_id = $inv_i->inv_ppv_ac_id;
	$pod->save();
	echo "<br> PO Detail is succefully created. Detail Id - " . $pod->po_detail_id;

	$po_rd->order_number = $po_rls->po_header_id;
	$po_rd->audit_trial();
	$po_rd->save();
 }

 private function _convert_requisition_toSO_header($i, &$SO_cretaed) {
	global $dbc;
	$header_amt = 0;
//   foreach($_POST['line_price'] as $amt_k => $amt_v ){
//    $header_amt += $amt_v;
//   }
	$sd_so = new sd_so_header();
	$supp_inv_org = $_POST['supply_org_id'][$i];
	$fin_details = org::find_financial_details_from_orgId($supp_inv_org);
	if (empty($fin_details->business_org_id)) {
	 throw new Exception('No business org id found for the source inventory org');
	} else {
	 $sd_so->bu_org_id = $fin_details->business_org_id;
	 $sales_control_d = sd_sales_control::find_by_org_id($sd_so->bu_org_id);
	 $sd_so->order_source_type = 'IR';
	 $sd_so->document_type = $sales_control_d->iso_h_default_document_type_id;
	 $this->_iso_l_default_document_type_id = $sales_control_d->iso_l_default_document_type_id;
	 $ar_customer_site_i = ar_customer_site::find_by_ColumnNameVal('internal_org_id', $_POST['receving_org_id'][$i]);
	 if (empty($ar_customer_site_i[0]->ar_customer_id)) {
		throw new Exception('No Internal customer found for the receving organization');
	 } else {
		$sd_so->ar_customer_id = $ar_customer_site_i[0]->ar_customer_id;
		$sd_so->ar_customer_site_id = $ar_customer_site_i[0]->ar_customer_site_id;
		$sd_so->doc_currency = $fin_details->currency_code;
		$sd_so->bill_to_id = $ar_customer_site_i[0]->bill_to_id;
		$sd_so->ship_to_id = $ar_customer_site_i[0]->ship_to_id;
		$sd_so->header_amount = '.01';
		$sd_so->tax_amount = null;
		$sd_so->so_status = 'ENTERED';
		if (!empty($fin_details->currency_code)) {
		 $sd_so->currency = $fin_details->currency_code;
		} else {
		 throw new Exception('No default currency found for the org ');
		}
		$sd_so->payment_term_id = $ar_customer_site_i[0]->payment_term_id;
		$sd_so->payment_term_date = current_time(true);
		$sd_so->reference_doc_type = 'po_requisition_details';
		$sd_so->reference_doc_number = $_POST['po_requisition_detail_id'][$i];
		try {
		 $sd_so->save();
		 $sd_so->_after_save();
		} catch (Exception $e) {
		 $this->message .= '<br> Failed to create sales order. line Error @ po_header @@ line ' . __LINE__ . ' ' . $e->getMessage();
		 $dbc->rollback = true;
		 return false;
		}
		echo "<br> SO header is succefully created. Header Id - " . $sd_so->sd_so_header_id;
		$dbc->confirm();
		$record_saved = ['ar_customer_id' => $sd_so->ar_customer_id,
				'ar_customer_site_id' => $sd_so->ar_customer_site_id,
				'sd_so_header_id' => $sd_so->sd_so_header_id];
		array_push($SO_cretaed, $record_saved);
		return $sd_so->sd_so_header_id;
	 }
	}
 }

 private $_iso_l_default_document_type_id;

 private function _create_iso() {
	global $dbc;

	$SO_cretaed = [];
	$line_number = 0;
	for ($i = 0; $i < count($_POST['po_requisition_detail_id']); $i++) {
	 $line_number ++;
	 $sd_so_header_id = null;

	 foreach ($SO_cretaed as $so_recods) {
		if (array_search($_POST['supply_org_id'][$i], $so_recods)) {
		 $sd_so_header_id = $so_recods['sd_so_header_id'];
		 $line_number++;
		 break;
		}
	 }
	 if (empty($sd_so_header_id)) {
		$sd_so_header_id = $this->_convert_requisition_toSO_header($i, $SO_cretaed);
	 }
	 if (!empty($sd_so_header_id)) {
		$po_rd = new po_requisition_detail();
		$po_rd->findBy_id($_POST['po_requisition_detail_id'][$i]);
		if (!empty($po_rd->order_number)) {
		 continue;
		}
		$sd_so_line = new sd_so_line();


		$item_details = item::find_by_id($_POST['item_id_m'][$i]);
		$sd_so_line->item_id_m = $item_details->item_id_m;
		$sd_so_line->shipping_org_id = $_POST['supply_org_id'][$i];
		$sd_so_line->sd_so_header_id = $sd_so_header_id;
		$sd_so_line->item_description = $item_details->item_description;
		$sd_so_line->uom_id = $item_details->uom_id;
		$sd_so_line->line_number = $line_number;
		$sd_so_line->line_type = $this->_iso_l_default_document_type_id;
		$sd_so_line->line_status = 'ENTERED';
		$sd_so_line->line_quantity = $_POST['line_quantity'][$i];

		$sd_so_line->unit_price = $_POST['unit_price'][$i];
		$sd_so_line->line_price = $sd_so_line->unit_price * $sd_so_line->line_quantity;
//    $sd_so_line->tax_code_id = $confirm_order_details->tax_code[$k];
		$sd_so_line->supply_source = 'INV';
		$sd_so_line->reference_doc_type = 'po_requisition_detail';
		$sd_so_line->reference_doc_number = $_POST['po_requisition_detail_id'][$i];
		$sd_so_line->line_description = 'po_requisition_details : ' . $sd_so_line->reference_doc_number;
		$sd_so_line->requested_date = $_POST['need_by_date'][$i];
		try {
		 $sd_so_line->save();
		} catch (Exception $e) {
		 $this->message .= '<br> Failed to create sales order line. line Error @ po_header @@ line ' . __LINE__ . ' ' . $e->getMessage();
		 $dbc->rollback = true;
		 return false;
		}

		$po_rd->order_type = 'sd_so_header';
		$po_rd->order_number = $sd_so_header_id;
		$po_rd->save();
	 }
	}
 }

 private function _convert_requisition_toDoc() {
	global $dbc;
	if (empty($_POST)) {
	 return;
	}
	$PO_cretaed = [];
	$line_number = 0;
	for ($i = 0; $i < count($_POST['po_requisition_detail_id']); $i++) {
	 $line_number ++;
	 $po_header_id = null;
	 if (($_POST['po_requisition_type'][$i]) == 'INTERNAL') {
		//create ISO
		$this->_create_iso();
		break;
	 }

	 foreach ($PO_cretaed as $po_recods) {
		if (array_search($_POST['supplier_site_id'][$i], $po_recods)) {
		 $po_header_id = $po_recods['po_header_id'];
		 $line_number++;
		 break;
		}
	 }
	 if (empty($po_header_id)) {
		if (!empty($_POST['bpa_po_line_id'][$i])) {
		 $this->_convert_requisition_toBPArelease($i, $PO_cretaed);
		} else {
		 $po_header_id = $this->_convert_requisition_toPO_header($i, $PO_cretaed);
		}
	 }
	 if (!empty($po_header_id)) {
		$po_rd = new po_requisition_detail();
		$po_rd->findBy_id($_POST['po_requisition_detail_id'][$i]);
		if (!empty($po_rd->order_number)) {
		 continue;
		}
		$pol = new po_line();
		$pol->line_number = $line_number;
		$pol->line_type = 'GOODS';
		$pol->po_header_id = $po_header_id;
		$pol->receving_org_id = $_POST['receving_org_id'][$i];
		$pol->item_id_m = $_POST['item_id_m'][$i];
		$item = new item();
		$item->findBy_id($pol->item_id_m);
		$pol->item_description = $item->item_description;
		$pol->uom_id = $item->uom_id;
		$pol->line_quantity = $_POST['line_quantity'][$i];
		$pol->unit_price = $_POST['unit_price'][$i];
		$pol->line_price = $pol->line_quantity * $pol->unit_price;
		$pol->reference_doc_type = 'po_requisition_details';
		$pol->reference_doc_number = $_POST['po_requisition_detail_id'][$i];
		$pol->audit_trial();
		$pol->save();
		echo "<br> PO Line is succefully created. Line Id - " . $pol->po_line_id;

		$pod = new po_detail();
		$pod->po_header_id = $po_header_id;
		$pod->po_line_id = $pol->po_line_id;
		$pod->shipment_number = 1;
		$pod->need_by_date = $_POST['need_by_date'][$i];
		$inv = new inventory();
		$inv_i = $inv->findBy_org_id($pol->receving_org_id);
		//ac id needs to be modified to req accounts
		$pod->charge_ac_id = $inv_i->material_ac_id;
		$pod->accrual_ac_id = $inv_i->inv_ap_accrual_ac_id;
		$pod->ppv_ac_id = $inv_i->inv_ppv_ac_id;
		$pod->audit_trial();
		$pod->save();
		echo "<br> PO Detail is succefully created. Detail Id - " . $pod->po_detail_id;

		$po_rd->order_number = $po_header_id;
		$po_rd->order_type = 'po_header';
		$po_rd->save();
	 }
	}
 }

 public function notification_action($obj) {
	$this->findBy_id($obj->reference_key_value);
	if ($obj->notification_action == 'APPROVE') {
	 try {
		$this->_approve_po($obj->to_user_id);
	 } catch (Exception $e) {
		$this->rollback = true;
		echo "<br> Unable to complete the approval process " . $e->getMessage();
	 }
	} else if ($obj->notification_action == 'REJECT') {
	 $this->po_status = 'REJECTED';
	 $this->approved_by = $obj->to_user;
	 $this->approved_date = current_time();

	 $this->update($this->po_header_id);
	}
 }

 public function findAll_releases($ref_po_header_id = '') {
	$ref_po_header_id = empty($ref_po_header_id) ? $this->ref_po_header_id : $ref_po_header_id;
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE ref_po_header_id = :ref_po_header_id ";
	$value_a = ['ref_po_header_id' => $ref_po_header_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }

 public static function find_by_refPOHeaderId_releseNumber($ref_po_header_id, $release_number) {
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE ref_po_header_id = '{$ref_po_header_id}' AND release_number = '{$release_number}' LIMIT 1 ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 public function _find_relNumber($ref_po_header_id = '') {
	$po_header1 = $this->findBy_id($this->po_header_id);
	if (!empty($po_header1->release_number)) {
	 return $po_header1->release_number;
	}
	$ref_po_header_id = empty($ref_po_header_id) ? $this->ref_po_header_id : $ref_po_header_id;
	$sql = " SELECT MAX(release_number) as release_number FROM " . self::$table_name;
	$sql .= " WHERE ref_po_header_id = :ref_po_header_id ";
	$value_a = ['ref_po_header_id' => $ref_po_header_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result)->release_number + 1 : 1;
 }

 Public static function po_types() {
	$option_header = option_header::find_by_name('PO_TYPE');
	$po_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_types;
 }

 Public static function po_status() {
	$option_header = option_header::find_by_name('PO_STATUS');
	$po_status = option_line::find_by_option_id($option_header->option_header_id);
	return $po_status;
 }

 public function copy($po_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM po_header WHERE `po_header_id` = '{$po_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `po_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `po_header_id` = '{$po_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `po_header` SELECT * FROM tmptable WHERE `po_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->po_header_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

 public static function find_all_active_bpa($bu_org_id = '') {
	$sql = " SELECT poh.po_header_id, poh.po_number, sup.supplier_id, sup.supplier_name
            FROM po_header poh
            LEFT JOIN supplier sup ON poh.supplier_id = sup.supplier_id";
	$sql .= " WHERE poh.po_type = 'BLANKET' ";
	$sql .= " AND poh.po_status = 'APPROVED' ";
//   $sql .= " AND poh.released_amount IS NULL ||  poh.released_amount < header_amount ";
	$sql .= " AND poh.aggrement_end_date IS NULL ||  poh.aggrement_end_date < CURDATE() ";
	if (!empty($bu_org_id)) {
	 $sql .= " AND poh.bu_org_id = '{$bu_org_id}' ";
	}
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

//  public function save() {
//   $primary_column = static::$primary_column;
//   if (empty($this->$primary_column)) {
//    $this->po_status = 'Entered';
//    $this->create();
//   } else {
//    $this->update($this->$primary_column);
//   }
//   return $this->msg;
//  }
 //multi select used for req to PO conversion

 public function multi_select_input_fields() {
	$multi_select_input = [
			'select_supplier_name',
			'supplier_site_name'
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'mode',
			'action',
			'show_block',
	];

	return $multi_select_hidden;
 }

}

//end of po_header class
?>
