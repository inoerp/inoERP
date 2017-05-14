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
 * po_requisition_header
 * Contains all the po_requisition_header information 
 *
 */
 class po_requisition_header extends dbObject {

  public static $table_name = "po_requisition_header";
  public static $dependent_classes = ['po_requisition_line', 'po_requisition_detail'];
  public static $primary_column = "po_requisition_header_id";
  public static $primary_column2 = "po_requisition_number";
  public static $key_column = 'bu_org_id';
  public static $module = "pur";
  public static $po_requisition_type_a = [
   'EXTERNAL' => 'External',
   'INTERNAL' => 'Internal'
  ];
  private $_req_type_document_mapping = [
   'EXTERNAL' => 'PUR_REQUISITION_EXTERN',
   'INTERNAL' => 'PUR_REQUISITION_INTERNAL',
  ];
  public static $system_info = [
   'name' => 'Purchaing Requisition',
   'number' => '2211',
   'description' => 'Create & Mainten Purchaing Requisition',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
   'dependent_class' => array('po_requisition_line', 'po_requisition_detail'),
   'primary_entity_cb' => '',
   'module_name' => 'po',
   'weight' => 3
  ];
  public $checkbox = [
   "rev_enabled_cb"
  ];
  public $action_a = [
   'PRINT' => 'Print',
   'APPROVE' => 'Approve',
   'VIEW_HISTORY' => 'View History',
   'CANCEL' => 'Cancel',
   'RECEIVE' => 'Receive',
  ];
  public $field_a = [
   'po_requisition_header_id',
   'bu_org_id',
   'po_requisition_type',
   'po_requisition_number',
   'supplier_id',
   'supplier_site_id',
   'buyer',
   "description",
   'ship_to_id',
   'bill_to_id',
   'header_amount',
   'currency',
   'payment_term_id',
   'exchange_rate_type',
   'exchange_rate',
   "supply_org_id",
   "requisition_status",
   "rev_enabled_cb",
   "rev_number",
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
  public $initial_search = [
   "po_requisition_header_id",
   "po_requisition_number",
   "supplier_id",
   "buyer"
  ];
  public $column = [
   "po_requisition_header_id",
   "po_requisition_number",
   "requisition_status",
   "supplier_id",
   "creation_date",
   "buyer",
  ];
  public $requiredField = [
   'bu_org_id',
   'po_requisition_type',
  ];
  public $addressField = [
   'ship_to_id',
   'bill_to_id'
  ];
  public $numberField = [
   'header_amount',
   'exchange_rate'
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
 
   
  public $profile_default = [
   'exchange_rate_type' => 'gl_currency_conversion_type',
   'bu_org_id' => 'org_bu_name_default',
   'po_requisition_type' => 'po_requisition_type_default',
   'ship_to_id' => 'ship_to_address_default',
   'bill_to_id' => 'bill_to_address_default'
  ];
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
   '_extra_path' => array('form.php?class_name=po_header&mode=9' => 'Create PO')
  ];
  public $pageTitle = " Requisition - Purchasing "; //page Title
  public $option_lists = [
   'po_requisition_type' => 'PO_REQUISITION_TYPE',
   'requisition_status' => 'PO_STATUS',
  ];
  public $po_requisition_header_id;
  public $bu_org_id;
  public $po_requisition_type;
  public $po_requisition_number;
  public $supplier_id;
  public $supplier_site_id;
  public $buyer;
  public $description;
  public $ship_to_id;
  public $bill_to_id;
  public $header_amount;
  public $currency;
  public $payment_term_id;
  public $agreement_start_date;
  public $aggrement_end_date;
  public $exchange_rate_type;
  public $exchange_rate;
  public $released_amount;
  public $supply_org_id;
  public $requisition_status;
  public $rev_enabled_cb;
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

  public static function profile_po_requisition_type_default() {
   $line_data_array = [];
   $line_data_array['line_key'] = 'option_line_code';
   $line_data_array['line_desc'] = 'option_line_value';
   $line_data_array['line_values'] = self::po_requisition_type();
   return $line_data_array;
  }

  public function _before_save() {
   if (empty($this->po_requisition_header_id)) {
    $this->requisition_status = 'ENTERED';
   } else if (empty($this->requisition_status)) {
    $this->requisition_status = po_requisition_header::find_by_id($this->po_requisition_header_id)->requisition_status;
   }
   
   if(!empty($this->supply_org_id)){
    $this->supplier_id = $this->supplier_site_id = null;
   }

   if ((!empty($this->po_requisition_header_id)) && !empty($this->requisition_status) && (in_array('$this->requisition_status', array('INPROCESS', 'FIN_CLOSED', 'CANCELLED')))) {
    echo "You cant make changes to PO in process/re approval status. First get the PO approved";
    return -99;
   }
  }

  public function _after_save() {
   if ((!empty($this->po_requisition_header_id)) && empty($this->po_requisition_number)) {
    $po_requisition_header_id = $this->po_requisition_header_id;
    $bu_org_id = $this->bu_org_id;
    $this->po_requisition_number = $bu_org_id . '-' . $po_requisition_header_id;
    echo ' System generated Requisition number is ' . $this->po_requisition_number;
    $this->audit_trial();
    $this->save();
   }

   if (($this->action == 'APPROVE')) {
    $pur_control = po_purchasing_control::find_by_org_id($this->bu_org_id);
    if (empty($pur_control->req_approval_hierarchy)) {
     $this->po_status = 'APPROVED';
     $this->save();
    } else {
     $this->_approve_doc($pur_control->req_approval_hierarchy);
    }
   }
  }

  private function _approve_doc($approval_hierarchy) {
   $approving_user_id = $_SESSION['user_id'];
   $notification_subject = gettext('Requisition Approval From') . " " . $approving_user_id . ' ' . gettext('Req') . '#' . $this->po_requisition_number;
   $notif_text_field1 = "<br>" . gettext('Requisition Type') ." : $this->po_requisition_type ";
   $notif_text_field1 .= "<br>" . gettext('Requisition Number') . " : $this->po_requisition_number &nbsp;&nbsp; " . gettext('Amount') . " : $this->header_amount";
   $notif_text_field1 .= "<br>" . gettext('Supplier') . " : $this->supplier_name (" . gettext('Supplier Id') . " : $this->supplier_id) ";
   $notif_text_field1 .= "<br>" . gettext('Description') . " : $this->description ";
   $hr_appr_val = new hr_approval_validation();
   $hr_appr_val->approval_hierarchy = $approval_hierarchy;
   $hr_appr_val->approving_doc_name = $this->_req_type_document_mapping[$this->po_requisition_type];
   $hr_appr_val->approving_user_id = $_SESSION['user_id'];
   $hr_appr_val->reference_key_name = 'po_requisition_header';
   $hr_appr_val->reference_key_value = $this->po_requisition_header_id;
   $hr_appr_val->doc_amount = $this->header_amount;
   $hr_appr_val->notification_subject = $notification_subject;
   $hr_appr_val->notification_text = $notif_text_field1;
   $check_approval = $hr_appr_val->check_approval();

   $req_header_after_rev = new po_requisition_header();
   $req_header_after_rev->po_requisition_header_id = $this->po_requisition_header_id;
   if ($check_approval['status'] == 'APPROVED') {
    $req_header_after_rev->requisition_status = 'APPROVED';
    $req_header_after_rev->approved_by = $approving_user_id;
    $req_header_after_rev->approved_date = current_time();
   } else {
    $req_header_after_rev->requisition_status = $check_approval['status'];
   }
   $comment_msg = $check_approval['message'];
   $this->write_comment($approving_user_id, $comment_msg);
   $req_header_after_rev->save();
  }

  public function notification_action($obj) {
   $this->findBy_id($obj->reference_key_value);
   if ($obj->notification_action == 'APPROVE') {
    try {
     $this->_approve_doc($obj->to_user_id);
    } catch (Exception $e) {
     $this->rollback = true;
     echo "<br> Unable to complete the approval process " . $e->getMessage();
    }
   } else if ($obj->notification_action == 'REJECT') {
    $this->requisition_status = 'REJECTED';
    $this->approved_by = $obj->to_user;
    $this->approved_date = current_time();
    $this->audit_trial();
    $this->update($this->po_header_id);
   }
  }

  public function _before_showing() {
   $address = new address();
   if (!empty($this->ship_to_id)) {
    $address_ship_to = $address->findBy_id($this->ship_to_id);
    $this->ship_to_address_name = $address_ship_to->address_name;
    $this->ship_to_address = $address_ship_to->address;
    $this->ship_to_country = $address_ship_to->country;
    $this->ship_to_postal_code = $address_ship_to->postal_code;
    $this->ship_to_phone = $address_ship_to->phone;
   }
   if (!empty($this->bill_to_id)) {
    $address_bill_to = $address->findBy_id($this->bill_to_id);
    $this->bill_to_address_name = $address_bill_to->address_name;
    $this->bill_to_address = $address_bill_to->address;
    $this->bill_to_country = $address_bill_to->country;
    $this->bill_to_postal_code = $address_bill_to->postal_code;
    $this->bill_to_phone = $address_bill_to->phone;
   }
  }

  Public static function po_requisition_type() {
   $option_header = option_header::find_by_name('PO_REQUISITION_TYPE');
   $po_requisition_types = option_line::find_by_option_id($option_header->option_header_id);
   return $po_requisition_types;
  }

  Public static function requisition_status() {
   $option_header = option_header::find_by_name('PO_STATUS');
   $po_requisition_status = option_line::find_by_option_id($option_header->option_header_id);
   return $po_requisition_status;
  }

  public function copy($po_requisition_header_id) {
   global $db;
   $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM po_requisition_header WHERE `po_requisition_header_id` = '{$po_requisition_header_id}' ";
   if ($db->query($sql1)) {
    $sql2 = "  UPDATE tmptable SET `po_requisition_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `po_requisition_header_id` = '{$po_requisition_header_id}' ";
    if ($db->query($sql2)) {
     $sql3 = " INSERT INTO `po_requisition_header` SELECT * FROM tmptable WHERE `po_requisition_header_id` = '' ";
     if ($db->query($sql3)) {
      $this->po_requisition_header_id = $db->insert_id();
      $this->msg = 1;
     } else {
      $this->msg = 0;
     }
    }
   }
   return $this->msg;
  }

// public function save() {
//	$primary_column = static::$primary_column;
//	if (empty($this->$primary_column)) {
//	 $this->requisition_status = 'Entered';
//	 $this->create();
//	} else {
//	 $this->update($this->$primary_column);
//	}
//	return $this->msg;
// }
 }

//end of po_requisition_header class
?>
