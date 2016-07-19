<?php

class fp_kanban_rfid_v extends dbObject {

 public static $form_class_name = "fp_kanban_rfid";
 public static $table_name = "fp_kanban_rfid_v";
 public static $primary_column = "fp_kanban_rfid_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'plan_name',
  'org_id',
  'planning_horizon_days',
  'org',
  'item_number',
  'item_description',
  'top_level_item_number',
  'top_level_item_description',
  'quantity',
  'forecast',
  'forecast_description',
  'fp_kanban_rfid_id',
  'plan_id',
  'item_id_m',
  'rfid_item_id_m',
  'toplevel_rfid_item_id_m',
  'rfid_type',
  'source',
  'rfid_item_number',
  'rfid_item_description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'forecast',
  'item_number',
  'top_level_item_number',
  'rfid_item_number',
 ];
 public $requiredField = [
  'plan_id',
  'item_id_m',
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=fp_kanban_rfid',
//		 '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
////		 '_extra_path' => '',
 ];
 public $pageTitle = " Kanban rfid "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'Kanban Planner' => 'search_kanban_planner',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_m_from',
  'Item Id To' => 'search_item_id_m_to'
 ];
 public $fp_kanban_rfid_v_id;
 public $plan_id;
 public $item_id_m;
 public $quantity;
 public $rfid_item_id_m;
 public $toplevel_rfid_item_id_m;
 public $rfid_type;
 public $source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function deleteBy_planId($plan_id) {
  $dbc = new dbc();
  $sql = " DELETE FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE  plan_id = :plan_id ";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindParam(':plan_id', $plan_id);
//	echo '<div class="message"><br/>$sql is : ' . $sql . ' and primary column is' . $this->$primary_column . '</div>';
  try {
   $stmt->execute();
   $dbc->connection->commit();
   $this->msg = 1;
   echo "<div class='message'>Records are Successfullydeleted.</div>";
  } catch (PDOException $e) {
   $this->msg = 0;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "Record could not be updated !!: " . $e->getMessage();
  }
  return $this->msg;
 }

 private function create_fp_kanban_rfid_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_kanban_rfid_v
(
sys_rfid_interface_id,   epc,   tag_number,   antena_number,   time_stamp,
description_sri,   readcount,   org_id_sri,   item_id_m,    from_subinventory_id,
from_subinventory_sri,   transaction_type_id,   transaction_type,   quantity,
item_description_sri,   status, 
fp_kanban_header_id,   org_id,   description,     item_number,
item_description,   effective_from,   effective_to,   subinventory,
locator,   source_type,   supplier,   supplier_site,   from_org,
from_subinventory,   from_locator,   planning_only_cb,   auto_request_cb,
calculate,   card_size,   noof_card,   moq,   lead_time,   allocation_per,
flm,   ssd,   rfid_reference
)
AS
SELECT
sri.sys_rfid_interface_id,   sri.epc,   sri.tag_number,   sri.antena_number,   sri.time_stamp,
sri.description,   sri.readcount,   sri.org_id,   sri.item_id_m,    sri.from_subinventory_id,
sri.from_subinventory,   sri.transaction_type_id,   sri.transaction_type,   sri.quantity,
sri.item_description,   sri.status, 
kbh.fp_kanban_header_id,   kbh.org_id,   kbh.description,     kbh.item_number,
kbh.item_description,   kbh.effective_from,   kbh.effective_to,   kbh.subinventory,
kbh.locator,   kbh.source_type,   kbh.supplier,   kbh.supplier_site,   kbh.from_org,
kbh.from_subinventory,   kbh.from_locator,   kbh.planning_only_cb,   kbh.auto_request_cb,
kbh.calculate,   kbh.card_size,   kbh.noof_card,   kbh.moq,   kbh.lead_time,   kbh.allocation_per,
kbh.flm,   kbh.ssd,   kbh.rfid_reference

from fp_kanban_header kbh,
sys_rfid_interface sri

WHERE sri.epc = kbh.rfid_reference

";
 }

}

?>
