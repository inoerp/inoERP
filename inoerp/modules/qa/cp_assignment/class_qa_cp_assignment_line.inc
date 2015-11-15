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
 * qa_cp_assignment_line
 *
 */
class qa_cp_assignment_line extends dbObject {

 public static $table_name = "qa_cp_assignment_line";
 public static $primary_column = "qa_cp_assignment_line_id";
 public static $parent_primary_column = "qa_cp_assignment_header_id";
 public static $key_column = "trigger_name";
 public static $module = "qa";
 public $field_a = [
  'qa_cp_assignment_line_id',
  'qa_cp_assignment_header_id',
  'qa_cp_header_id',
  'trigger_name',
  'description',
  'value_from',
  'value_to',
  'trigger_condition',
  'enabled_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'trigger_name',
  'value_from',
  'description',
 ];
 public $requiredField = [
  'qa_cp_assignment_header_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Collection Plan Line"; //page Title
 public $qa_cp_assignment_line_id;
 public $qa_cp_assignment_header_id;
 public $qa_cp_header_id;
 public $trigger_name;
 public $description;
 public $value_from;
 public $value_to;
 public $trigger_condition;
 public $enabled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $element_value;
 public $element_trigger_name;
 public $category = '';
 public $supplier_name = '';
 public $org_code = '';
 public $org_id = '';
 public $item_number = '';

 public function findAssignments() {

  $sql = " SELECT * from qa_cp_assignment_line ";
  $sql .= " WHERE trigger_name = '{$this->element_trigger_name}' ";

  switch ($this->trigger_condition) {
   case 'EQUAL':
    $sql .= ' AND value_from = ' . $this->element_value;
    break;

   case 'NE':
    $sql .= ' AND value_from != ' . $this->element_value;
    break;

   case 'GT':
    $sql .= ' AND value_from > ' . $this->element_value;
    break;

   case 'GTE':
    $sql .= ' AND value_from >= ' . $this->element_value;
    break;

   case 'LT':
    $sql .= ' AND value_from < ' . $this->element_value;
    break;

   case 'LTE':
    $sql .= ' AND value_from <= ' . $this->element_value;
    break;
  }

  $result = $this->findBySql($sql);

  return $result;
 }

 public $item_id_m;

 public function findAssignments_byTrigger() {
  $sql = " SELECT * from qa_cp_assignment_line ";
  if (!empty($this->org_id)) {
   $sql .= " WHERE trigger_name = 'org.org_id' ";
   $selecting_date = 'org_id';
  } else if (!empty($this->org_code)) {
   $sql .= " WHERE trigger_name = 'org.org_code' ";
   $selecting_date = 'org_code';
  } else if (!empty($this->category)) {
   $sql .= " WHERE trigger_name = 'category.category' ";
   $selecting_date = 'category';
  } else if (!empty($this->supplier_name)) {
   $sql .= " WHERE trigger_name = 'supplier.supplier_name' ";
   $selecting_date = 'supplier_name';
  } else if (!empty($this->supplier_id)) {
   $sql .= " WHERE trigger_name = 'supplier.supplier_id' ";
   $selecting_date = 'supplier_id';
  } else if (!empty($this->item_number)) {
   $sql .= " WHERE trigger_name = 'item.item_number' ";
   $selecting_date = 'item_number';
  } else if (!empty($this->item_id_m)) {
   $sql .= " WHERE trigger_name = 'item.item_id_m' ";
   $selecting_date = 'item_id_m';
  }

  $result = $this->findBySql($sql);
//  pa($result);

  if (empty($result)) {
   return false;
  }

  $qa_cp_header_ids = [];
  foreach ($result as $data) {
   switch ($data->trigger_condition) {
    case 'EQUAL' :
     if (($selecting_date == 'item_number') && ($data->value_from == $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from == $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from == $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from == $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ( trim($data->value_from) == trim($this->category))) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from == $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from == $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;

    case 'NE' :
     if (($selecting_date == 'item_number') && ($data->value_from != $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from != $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from != $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from != $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ($data->value_from != $this->category)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from != $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from != $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;


    case 'GT' :
     if (($selecting_date == 'item_number') && ($data->value_from > $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from > $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from > $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from > $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ($data->value_from > $this->category)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from > $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from > $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;


    case 'GTE' :
     if (($selecting_date == 'item_number') && ($data->value_from >= $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from >= $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from >= $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from >= $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ($data->value_from >= $this->category)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from >= $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from >= $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;

    case 'LTE' :
     if (($selecting_date == 'item_number') && ($data->value_from <= $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from <= $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from <= $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from <= $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ($data->value_from <= $this->category)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from <= $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from <= $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;

    case 'LT' :
     if (($selecting_date == 'item_number') && ($data->value_from < $this->item_number)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'item_id_m') && ($data->value_from < $this->item_id_m)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_id') && ($data->value_from < $this->supplier_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'supplier_name') && ($data->value_from < $this->supplier_name)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'category') && ($data->value_from < $this->category)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_code') && ($data->value_from < $this->org_code)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     } else if (($selecting_date == 'org_id') && ($data->value_from < $this->org_id)) {
      array_push($qa_cp_header_ids, $data->qa_cp_header_id);
     }
     break;
   }
  }
    return $qa_cp_header_ids;
 }

}

//end of path class
?>
