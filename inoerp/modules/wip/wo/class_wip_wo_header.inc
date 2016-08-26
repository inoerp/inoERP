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
 * wip_wo_header 
 *
 */
class wip_wo_header extends dbObject {

 public static $table_name = "wip_wo_header";
 public static $dependent_classes = ['wip_wo_routing_line', 'wip_wo_routing_detail', 'wip_wo_bom'];
 public static $primary_column = "wip_wo_header_id";
 public static $primary_column2 = "wo_number";
 public static $key_column = 'item_id_m';
 public static $module = "wip";
 public static $system_info = [
  'name' => 'Accounting Group',
  'number' => '2606',
  'description' => 'Create & Mainten Approved Accounting Group',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('wip_wo_routing_line', 'wip_wo_routing_detail', 'wip_wo_bom'),
  'primary_entity_cb' => '',
  'module_name' => 'wip',
  'weight' => 6
 ];
//  data base variables as stored database column name
 public $field_a = [
  'wip_wo_header_id',
  'item_id_m',
  'revision_name',
  'wo_number',
  'org_id',
  'wip_accounting_group_id',
  'wo_type',
  'wo_status',
  'start_date',
  'completion_date',
  'quantity',
  'nettable_quantity',
  'reference_bom_item_id_m',
  'reference_routing_item_id_m',
  'bom_exploded_cb',
  'routing_exploded_cb',
  'completion_sub_inventory',
  'completion_locator',
  'completed_quantity',
  'scrapped_quantity',
  'released_date',
  'first_unit_completed_date',
  'last_unit_completed_date',
  'schedule_group',
  'build_sequence',
  'line',
  'scheduling_priority',
  'closed_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
  'wip_wo_header_id',
  'item_id_m',
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
  "item_description",
  "uom",
  'processing_lt'
 ];
 public $requiredField = [
  'item_id_m',
  'org_id',
  'wip_accounting_group_id',
  'wo_type',
  'start_date',
  'quantity',
  'nettable_quantity'
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
 public static $json_label_fields = [
  'wo_number',
  'item_id_m',
  'org_id',
  'wo_type',
  'wo_status',
  'start_date',
  'quantity',
 ];
 public $pageTitle = "Work Order "; //page Title
 public $option_lists = [
  'wip_wo_type' => 'WIP_WO_TYPE',
  'wip_wo_status' => 'WIP_WO_STATUS',
 ];
 public $wip_wo_header_id;
 public $item_id_m;
 public $revision_name;
 public $wo_number;
 public $org_id;
 public $wip_accounting_group_id;
 public $wo_type;
 public $wo_status;
 public $start_date;
 public $released_date;
 public $completion_date;
 public $first_unit_completed_date;
 public $last_unit_completed_date;
 public $quantity;
 public $nettable_quantity;
 public $reference_bom_item_id_m;
 public $reference_routing_item_id_m;
 public $bom_exploded_cb;
 public $routing_exploded_cb;
 public $completion_sub_inventory;
 public $completion_locator;
 public $completed_quantity;
 public $scrapped_quantity;
 public $schedule_group;
 public $build_sequence;
 public $line;
 public $scheduling_priority;
 public $closed_date;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $remaining_quantity;
 public $item_number;
 public $item_description;
 public $uom;
 public $processing_lt;

 Public static function wip_wo_type() {
  $option_header = option_header::find_by_name('WIP_WO_TYPE');
  $wo_type = option_line::find_by_option_id($option_header->option_header_id);
  return $wo_type;
 }

 Public static function wip_wo_status() {
  $option_header = option_header::find_by_name('WIP_WO_STATUS');
  $wo_status = option_line::find_by_option_id($option_header->option_header_id);
  return $wo_status;
 }

 Public static function find_by_woNumber($wo_number) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wo_number = '{$wo_number}' ";
  $sql = ino_perPageSql_i($sql, 1);

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
  if ($this->_validate_before_save() < 0) {
   return -90;
  }
  if (empty($this->wo_status)) {
   $this->wo_status = 'UN_RELEASED';
  }

  if ((empty($this->released_date) || ($this->released_date == '0000-00-00') ) && ($this->wo_status == 'RELEASED' )) {
   $this->released_date = current_time(1);
  }
 }

 private function _copy_extra_fields($routing_line_id, $wip_wo_routing_line_id) {
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
   $new_efi->reference_key_name = 'wip_wo_routing_line';
   $new_efi->reference_key_value = $wip_wo_routing_line_id;
   $new_efi->audit_trial();
   try {
    $new_efi->save();
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br> System failed to copy extra field details. Error @ wip_wo_header @@ line " . __LINE__ . $e->getMessage();
   }
  }
 }

 private function _copy_routing() {
  global $dbc;
  $wip_wo_header_id2 = $this->wip_wo_header_id;
  $brl_i = bom_routing_line_v::find_by_itemIdM_OrgId($this->item_id_m, $this->org_id);
  $routingSeqCount = 0;
  if (!empty($brl_i)) {
   foreach ($brl_i as $routing_line) {
    $routing_line_id = $routing_line->bom_routing_line_id;
    $brd = new bom_routing_detail();
    $brd_i = $brd->findBy_parentId($routing_line_id);
    //insert the routing line in WO_Routing_Line
    $wip_wo_routing_line = new wip_wo_routing_line();
    foreach ($wip_wo_routing_line->field_a as $key => $value) {
     if (!empty($routing_line->$value)) {
      $wip_wo_routing_line->$value = $routing_line->$value;
     } else {
      $wip_wo_routing_line->$value = NULL;
     }
    }//end of for line value assignment

    if ($routingSeqCount == 0) {
     $wip_wo_routing_line->queue_quantity = $this->quantity;
    }
    $routingSeqCount++;
    $wip_wo_routing_line->wip_wo_header_id = $wip_wo_header_id2;
    $wip_wo_routing_line->audit_trial();
    try {
     $wip_wo_routing_line->save();
     echo "<br> Routing is Successfullycopied !";
     //copy the extra fields
     $this->_copy_extra_fields($routing_line_id, $wip_wo_routing_line->wip_wo_routing_line_id);
     foreach ($brd_i as $routing_details) {
      $wip_wo_routing_detail = new wip_wo_routing_detail();
      foreach ($brd->field_a as $key => $value) {
       if (!empty($routing_details->$value)) {
        $wip_wo_routing_detail->$value = $routing_details->$value;
       } else {
        $wip_wo_routing_detail->$value = NULL;
       }
      }//end of for detail line value assignment

      $wip_wo_routing_detail->required_quantity = $this->quantity * $routing_details->resource_usage;
      $wip_wo_routing_detail->wip_wo_header_id = $wip_wo_header_id2;
      $wip_wo_routing_detail->wip_wo_routing_line_id = $wip_wo_routing_line->wip_wo_routing_line_id;
      $wip_wo_routing_detail->audit_trial();
      try {
       $wip_wo_routing_detail->save();
       echo "<br> Routing details are Successfullycopied !";
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
  $wip_wo_header_id1 = $this->wip_wo_header_id;
  $bom_header_byItem = bom_header::find_by_itemId_orgId($this->item_id_m, $this->org_id);
  $bom_header_id = $bom_header_byItem->bom_header_id;
  $bol_i = bom_line::find_by_bomHeaderId_revNumber($bom_header_id, $this->revision_name);
//  $bol_i = bom_line_v::find_by_itemIdM_OrgId_revNumber($this->item_id_m, $this->org_id, $this->revision_name);
  if (!empty($bol_i)) {
   foreach ($bol_i as $bom_line) {
    $wip_wo_bom = new wip_wo_bom();
//		$routing_sequence_value = 10;
    foreach ($wip_wo_bom->field_a as $key => $value) {
     if (!empty($bom_line->$value)) {
      $wip_wo_bom->$value = $bom_line->$value;
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
        $wip_wo_bom->$value = $routing_sequence_value;
       }
      }
     } else {
      $wip_wo_bom->$value = NULL;
     }
    }
    $wip_wo_bom->required_quantity = $bom_line->usage_quantity * $this->quantity;
    $wip_wo_bom->wip_wo_header_id = $wip_wo_header_id1;
    $wip_wo_bom->audit_trial();
    try {
     $wip_wo_bom->save();
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
  if ((!empty($this->wip_wo_header_id)) && empty($this->wo_number)) {
   $wip_wo_header_id = $this->wip_wo_header_id;
   $org_id = $this->org_id;
   $this->wo_number = $org_id . '-' . $wip_wo_header_id;
   $this->save();
  }

  //copy the BOM
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
   echo "<br> Error @ wip_wo_header @@ Line " . __LINE__ . $e->getMessage();
  }
 }

 private function update_woNumber($wip_wo_header_id, $wo_number) {
  global $dbc;
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET wo_number = '{$wo_number}'  ";
  $sql .= " WHERE wip_wo_header_id =  '{$wip_wo_header_id }' ";
  try {
   $dbc->ddlexecute($sql);
   $this->wo_number = $wo_number;
   return true;
  } catch (Exception $e) {
   echo "<br> WIP WO Number Update Failed" . $e->getMessage();
   return false;
  }
 }

}

//end of resource class
?>