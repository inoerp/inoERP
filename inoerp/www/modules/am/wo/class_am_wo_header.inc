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
 * am_wo_header 
 *
 */
class am_wo_header extends dbObject {

 public static $table_name = "am_wo_header";
 public static $dependent_classes = ['am_wo_routing_line', 'am_wo_routing_detail', 'am_wo_bom'];
 public static $primary_column = "am_wo_header_id";
 public static $primary_column2 = "wo_number";
 public static $key_column = 'am_asset_id';
 public static $module = "wip";
 public static $system_info = [
  'name' => 'AM Work Order',
  'number' => '4114',
  'description' => 'Maintenance Work Order',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('am_wo_routing_line', 'am_wo_routing_detail', 'am_wo_bom'),
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 6
 ];
 public static $wo_status_a = [
  'UN_RELEASED' => 'UnReleased',
  'RELEASED' => 'Released',
  'ON_HOLD' => 'On Hold',
  'COMPLETED' => 'Completed',
  'WAITING_FOR_CLOSING' => 'Waiting For Closing',
  'CLOSED' => 'Closed',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'am_wo_header_id',
  'am_asset_id',
  'activity_item_id_m',
  'wo_number',
  'parent_wo_id',
  'org_id',
  'wip_accounting_group_id',
  'wo_type',
  'wo_status',
  'start_date',
  'completion_date',
  'quantity',
  'reference_bom_item_id_m',
  'bom_exploded_cb',
  'routing_exploded_cb',
  'reference_routing_item_id_m',
  'department_id',
  'shutdown_type',
  'failure_type',
  'failure_cause',
  'released_date',
  'failure_resolution',
  'suggested_start_date',
  'schedule_group',
  'build_sequence',
  'line',
  'scheduling_priority',
  'closed_date',
  'suggested_end_date',
  'cycle',
  'cycle_interval',
  'am_maintenance_schedule_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'am_wo_header_id',
  'am_asset_id',
  'wo_number',
  'org_id',
  'wo_type',
  'start_date',
  'wo_status'
 ];
 public $checkbox = [
  'bom_exploded_cb',
  'routing_exploded_cb'
 ];
 public $fields_inForm_notInDataBase = [
  'remaining_quantity',
  "item_number",
  'processing_lt',
  'item_id_m',
  "am_asset_number",
  'item_number',
  'activity_item_number',
  'am_asset_type'
 ];
 public $requiredField = [
  'org_id',
  'wip_accounting_group_id',
  'wo_type',
  'start_date'
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=wip_move_transaction&mode=9' => 'Move',
   'form.php?class_name=wip_material_transaction&mode=9' => 'Material Tnx',
   'form.php?class_name=wip_resource_transaction&mode=9' => 'Resource Tnx',)
 ];
 public $pageTitle = " WO - Maintenance Work Order "; //page Title
 public $am_wo_header_id;
 public $am_asset_id;
 public $activity_item_id_m;
 public $wo_number;
 public $parent_wo_id;
 public $org_id;
 public $wip_accounting_group_id;
 public $wo_type;
 public $wo_status;
 public $start_date;
 public $completion_date;
 public $quantity;
 public $reference_bom_item_id_m;
 public $bom_exploded_cb;
 public $routing_exploded_cb;
 public $reference_routing_item_id_m;
 public $department_id;
 public $shutdown_type;
 public $failure_type;
 public $failure_cause;
 public $released_date;
 public $failure_resolution;
 public $suggested_start_date;
 public $schedule_group;
 public $build_sequence;
 public $line;
 public $scheduling_priority;
 public $closed_date;
 public $suggested_end_date;
 public $cycle;
 public $cycle_interval;
 public $am_maintenance_schedule_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $message;
 public $remaining_quantity;
 public $item_number;
 public $item_description;
 public $processing_lt;
 public $item_id_m;
 public $am_asset_number;
 public $activity_item_number;
 public $am_asset_type;
 public $revision_name; //for activity item_id_m
 public $cut_off_date;
 public $prg_create_wo_parameters = [
  'Organization' => 'search_org_name',
  'Cut Off Date' => 'search_cut_off_date',
  'Asset Number' => 'search_asset_number',
 ];
 public $prg_create_wo_details = [
  'name' => 'Generate Maintenance WOs',
  'description' => 'Generate Maintenance Work Orders',
 ];

 Public static function am_wo_type() {
  $option_header = option_header::find_by_name('AM_WO_TYPE');
  $wo_type = option_line::find_by_option_id($option_header->option_header_id);
  return $wo_type;
 }

 Public static function find_by_woNumber($wo_number) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wo_number = '{$wo_number}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_shift($result) : false;
 }

 private function _validate_before_save() {
  $ret = 1;
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
  if ($item) {
   if (empty($item->build_in_wip_cb)) {
    $ret = -90;
    echo "<br> The item is not enabled for WIP built";
   }
  } else {
   $ret = -90;
   echo "<br> The item is not assigned to the organization";
  }
  return $ret;
 }

 public function _before_save() {
//  if ($this->_validate_before_save() < 0) {
//   return -90;
//  }
 }

 private function _copy_extra_fields($routing_line_id, $am_wo_routing_line_id) {
  global $dbc;
  $all_extra_fields = sys_extra_field_instance::find_by_referenceKeyValue('bom_routing_line', $routing_line_id);
  if (empty($all_extra_fields)) {
   return;
  }
  foreach ($all_extra_fields as $ef) {
   $new_efi = new sys_extra_field_instance();
   foreach ($ef as $key => $value) {
    if ($value) {
     $new_efi->$key = $value;
    }
   }
   $new_efi->sys_extra_field_instance_id = null;
   $new_efi->reference_key_name = 'am_wo_routing_line';
   $new_efi->reference_key_value = $am_wo_routing_line_id;
   $new_efi->audit_trial();
   try {
    $new_efi->save();
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br> System failed to copy extra field details. Error @ am_wo_header @@ line " . __LINE__ . $e->getMessage();
   }
  }
 }

 private function _copy_routing() {
  global $dbc;
  $am_wo_header_id2 = $this->am_wo_header_id;
  $brl_i = bom_routing_line_v::find_by_itemIdM_OrgId($this->item_id_m, $this->org_id);
  $routingSeqCount = 0;
  if (!empty($brl_i)) {
   foreach ($brl_i as $routing_line) {
    $routing_line_id = $routing_line->bom_routing_line_id;
    $brd = new bom_routing_detail();
    $brd_i = $brd->findBy_parentId($routing_line_id);
    //insert the routing line in WO_Routing_Line
    $am_wo_routing_line = new am_wo_routing_line();
    foreach ($am_wo_routing_line->field_a as $key => $value) {
     if (!empty($routing_line->$value)) {
      $am_wo_routing_line->$value = $routing_line->$value;
     } else {
      $am_wo_routing_line->$value = NULL;
     }
    }//end of for line value assignment

    if ($routingSeqCount == 0) {
     $am_wo_routing_line->queue_quantity = $this->quantity;
    }
    $routingSeqCount++;
    $am_wo_routing_line->am_wo_header_id = $am_wo_header_id2;
    $am_wo_routing_line->audit_trial();
    try {
     $am_wo_routing_line->save();
     echo "<br> Routing is Successfully copied !";
     //copy the extra fields
     $this->_copy_extra_fields($routing_line_id, $am_wo_routing_line->am_wo_routing_line_id);
     foreach ($brd_i as $routing_details) {
      $am_wo_routing_detail = new am_wo_routing_detail();
      foreach ($brd->field_a as $key => $value) {
       if (!empty($routing_details->$value)) {
        $am_wo_routing_detail->$value = $routing_details->$value;
       } else {
        $am_wo_routing_detail->$value = NULL;
       }
      }//end of for detail line value assignment

      $am_wo_routing_detail->required_quantity = $this->quantity * $routing_details->resource_usage;
      $am_wo_routing_detail->am_wo_header_id = $am_wo_header_id2;
      $am_wo_routing_detail->am_wo_routing_line_id = $am_wo_routing_line->am_wo_routing_line_id;
      $am_wo_routing_detail->audit_trial();
      try {
       $am_wo_routing_detail->save();
       echo "<br> Routing details are Successfully copied !";
      } catch (Exception $e) {
       $dbc->rollback = true;
       echo "<br> System failed to copy the Routing Details!" . __LINE__ . $e->getMessage();
      }
     }
    } catch (Exception $e) {
     $dbc->rollback = true;
     echo "<br> System failed to copy the Routing!" . __LINE__ . $e->getMessage();
    }
   }//end of each routing line insertion
  }
  $this->routing_exploded_cb = 1;
 }

 private function _copy_bom() {
  global $dbc;
  $am_wo_header_id1 = $this->am_wo_header_id;
  $bom_header_byItem = bom_header::find_by_itemId_orgId($this->item_id_m, $this->org_id);
  $bom_header_id = $bom_header_byItem->bom_header_id;
  $bol_i = bom_line::find_by_bomHeaderId_revNumber($bom_header_id, $this->revision_name);
//  $bol_i = bom_line_v::find_by_itemIdM_OrgId_revNumber($this->item_id_m, $this->org_id, $this->revision_name);
  if (!empty($bol_i)) {
   foreach ($bol_i as $bom_line) {
    $am_wo_bom = new am_wo_bom();
//		$routing_sequence_value = 10;
    foreach ($am_wo_bom->field_a as $key => $value) {
     if (!empty($bom_line->$value)) {
      $am_wo_bom->$value = $bom_line->$value;
      if ($value == 'routing_sequence') {
       $routing_of_bom = bom_routing_line_v::find_by_itemIdM_OrgId($this->item_id_m, $this->org_id);
       if ($routing_of_bom) {
        foreach ($routing_of_bom as $routing_lines) {
         if ($routing_lines->bom_routing_line_id == $bom_line->$value) {
          $routing_sequence_value = $routing_lines->routing_sequence;
         }
        }
       } else {
        echo "<br>No Routing found!. Manually create the routing";
//        $dbc->rollback = true;
//        return;
       }

       if (!empty($routing_sequence_value)) {
        $am_wo_bom->$value = $routing_sequence_value;
       }
      }
     } else {
      $am_wo_bom->$value = NULL;
     }
    }
    $am_wo_bom->required_quantity = $bom_line->usage_quantity * $this->quantity;
    $am_wo_bom->am_wo_header_id = $am_wo_header_id1;
    $am_wo_bom->audit_trial();
    try {
     $am_wo_bom->save();
     $this->bom_exploded_cb = 1;
     echo "<br> BOM is Successfullycopied";
    } catch (Exception $e) {
     echo "<br> System failed to copy the BOM!" . __LINE__ . $e->getMessage();
    }
   }
  }
 }

 public function _after_save() {
  global $dbc;
  if ((!empty($this->am_wo_header_id)) && empty($this->wo_number)) {
   $am_wo_header_id = $this->am_wo_header_id;
   $org_id = $this->org_id;
   $this->wo_number = $org_id . '-' . $am_wo_header_id;
   $this->save();
  }

  if (empty($this->am_wo_header_id)) {
   return;
  }
  //copy the BOM
  if (empty($this->activity_item_id_m)) {
   return;
  } else {
   $this->item_id_m = $this->activity_item_id_m;
  }

  if ((!empty($this->item_id_m)) && (empty($this->bom_exploded_cb))) {
   $this->_copy_bom();
  }

  //copy the Routing
  if ((!empty($this->item_id_m)) && (empty($this->routing_exploded_cb))) {
   $this->_copy_routing();
  }//end of routing copy
  //save again
  try {
   $this->save();
  } catch (Exception $e) {
   $dbc->rollback = true;
   echo "<br> Error @ am_wo_header @@ Line " . __LINE__ . $e->getMessage();
  }
 }

 private function update_woNumber($am_wo_header_id, $wo_number) {
  global $dbc;
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET wo_number = '{$wo_number}'  ";
  $sql .= " WHERE am_wo_header_id =  '{$am_wo_header_id }' ";
  try {
   $dbc->ddlexecute($sql);
   $this->wo_number = $wo_number;
   return true;
  } catch (Exception $e) {
   echo "<br> WIP WO Number Update Failed" . $e->getMessage();
   return false;
  }
 }

 public function prg_create_wo($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Staring Create WO Program. ';
  if (!empty($parameters['org_id'][0])) {
   $this->org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $this->org_id;
  } else {
   $this->message .= '<br> No org id found, Exiting the program<br> . Error message @ am_wo_header @@ line ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['am_asset_id'][0])) {
   $this->am_asset_id = $parameters['am_asset_id'][0];
   $this->message .= '<br> Entered am_asset_id is : ' . $this->am_asset_id;
  }

  if (!empty($parameters['am_asset_id'][0])) {
   $this->cut_off_date = $parameters['cut_off_date'][0];
  } else {
   $date_i = new DateTime();
   $date_i->add(new DateInterval('P365D'));
   $this->cut_off_date = $date_i->format('Y-m-d');
  }

  if (!empty($this->am_asset_id)) {
   $this->message .= '<br> Creating WO for am_asset_id : ' . $this->am_asset_id;
   $this->_create_WO_from_assetId($this->am_asset_id);
  } else if (!empty($this->org_id)) {
   $all_assets = am_asset::find_by_orgId($this->org_id);
   foreach ($all_assets as $asset) {
    $this->message .= '<br> Trying to cerate WO for am_asset_id : ' . $asset->am_asset_id;
    try {
     $this->_create_WO_from_assetId($asset->am_asset_id);
     $this->message .= "<br/>WO is Successfully Created for am_asset_id id " . $asset->am_asset_id;
    } catch (Exception $e) {
     $this->message .= "<br/>WO creation program failed  for for am_asset_id id " . $asset->am_asset_id . $e->getMessage();
    }
   }
  }

  return $this->message;
 }

 private function _create_WO_from_assetId($am_asset_id, $order_typ = 'ACTUAL') {
  global $dbc;
  /*
   * 1. Find all active/blank schedules where effective from date is greater than equal to day and effective end date is blank or
   * greater than today
   * 2. Check if there is a calendar date - if yes use it
   * 3. If no calendar date then use date rule & meter rule
   * 4. Find out WO details as per the date rule & activity; Check if WO exists, If not then create WO
   */
  $am_schedule = new am_maintenance_schedule();
  $am_schedule->org_id = $this->org_id;
  $am_schedule->am_asset_id = $am_asset_id;
  $all_schedules = $am_schedule->findBy_orgId_assetId_otherDetails();
  if (empty($all_schedules)) {
   $this->message .= "<br/>No schedule found for the entered details. Error message @ am_wo_header @@ line " . __LINE__;
   return;
  }
  foreach ($all_schedules as $am_schedule_fl) {
   $all_activities = am_ms_activity_reference::find_by_scheduleId($am_schedule_fl->am_maintenance_schedule_id);
   if (empty($all_activities)) {
    continue;
   } else {
    foreach ($all_activities as $activities) {

     //check calendar rule
     $cal_dates = am_ms_calendar_date::find_by_maintenance_schedule_id($am_schedule_fl->am_maintenance_schedule_id);
     if ($cal_dates) {
      //verify & create WO
      foreach ($cal_dates as $date) {
       $this->_verify_create_WO($am_asset_id, $activities->activity_item_id_m, $date->date, $am_schedule_fl->am_maintenance_schedule_id, $am_schedule_fl->wo_status);
      }
     } else {
      //check date rule
      $date_rule = am_ms_date_rule::find_by_maintenance_schedule_id($am_schedule_fl->am_maintenance_schedule_id);
      if (empty($date_rule)) {
       return;
      }
      $wo_date = $am_schedule_fl->schedule_basis_date;
      $cycle = $am_schedule_fl->current_cycle;
      $cycle_interval = $am_schedule_fl->current_cycle_interval;
      $wo_date_obj = new DateTime($wo_date);
      $cut_off_date_obj = new DateTime($this->cut_off_date);
      do {
       $cycle_interval++;
       if ($cut_off_date_obj > $wo_date_obj) {
        $this->_verify_create_WO($am_asset_id, $activities->activity_item_id_m, $wo_date, $am_schedule_fl->am_maintenance_schedule_id, $am_schedule_fl->wo_status, $cycle, $cycle_interval);
       }
       if (!empty($am_schedule_fl->intervals_per_cycle) && $cycle_interval == $am_schedule_fl->intervals_per_cycle) {
        $cycle++;
       }
       $date_rule_days = $date_rule->base_interval_days * $activities->interval_multiple;
       if (empty($date_rule_days)) {
        $this->message .= "<br/>Either base_interval_days or interval_multiple is zero ";
        $dbc->rollback = true;
        return;
       }
       $wo_date_obj->add(new DateInterval("P$date_rule_days" . "D"));
       $wo_date = $wo_date_obj->format('Y-m-d');
      } while ($cut_off_date_obj >= $wo_date_obj);
     }
    }
   }
  }
 }

 private function _verify_create_WO($am_asset_id, $activity_item_id_m, $date, $am_maintenance_schedule_id, $wo_status = 'UN_RELEASED', $cycle = '', $cycle_interval = '') {
  global $dbc;
  $asset_details = am_asset::find_by_id($am_asset_id);
  $existing_wo = self::find_by_asset_activity_date($am_asset_id, $activity_item_id_m, $date);
  if ($existing_wo) {
   $this->message .= "<br/>WO exists for am_asset_id"
    . " activity_item_id_m, & date [$am_asset_id , $activity_item_id_m , $date ]. WO Id " . $existing_wo[0]->am_wo_header_id;
  } else {
   //create WO
   $new_amwo = new am_wo_header();
   $new_amwo->org_id = $this->org_id;
   $new_amwo->am_asset_id = $am_asset_id;
   $new_amwo->activity_item_id_m = $activity_item_id_m;
   $new_amwo->wip_accounting_group_id = $asset_details->wip_accounting_group_id;
   $new_amwo->wo_type = 'PREVENTIVE';
   $new_amwo->wo_status = $wo_status;
   $new_amwo->department_id = $asset_details->owning_department_id;
   $new_amwo->start_date = $date;
   $new_amwo->am_maintenance_schedule_id = $am_maintenance_schedule_id;
   $new_amwo->cycle = $cycle;
   $new_amwo->cycle_interval = $cycle_interval;
   $new_amwo->quantity = 1;
   try {
    $new_amwo->save();
    $new_amwo->_after_save();
   } catch (Exception $e) {
    $this->message .= "<br/>Unable to save the WO details"
     . " Error @ am_wo_header @@ line  " . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
   }
  }
 }

 public static function find_by_asset_activity_date($am_asset_id, $activity_item_id_m, $date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_asset_id = '{$am_asset_id}'  ";
  $sql .= " AND activity_item_id_m = '{$activity_item_id_m}'  ";
  $sql .= " AND start_date = '{$date}'  ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of resource class
?>