<?php

class inv_transaction {
  protected static $table_name = "inv_transaction";
  
  public static $field_array = ["transaction_id",
                                "transaction_type_id",
                                "item_id",
                                "org_id",
                                "item_number",
                                "lot_number",
                                "serial_number",
                                "logical_transaction",
                                "document_type",
                                "document_number",
                                "document_id",
                                "reason",
                                "reference",
                                "description",
                                "from_org_id",
                                "from_subinventory_id",
                                "from_locator_id",
                                "quantity",
                                "from_account_id",
                                "account",
                                "account_id",
                                "amount",
                                "from_account",
                                "from_amount",
                                "to_org_id",
                                "to_subinventory_id",
                                "to_locator_id",
                                "to_account_id",
                                "to_account",
                                "to_amount",
                                "costed_amount",
                                "transfer_to_gl",
                                "ef_id",
                                "transaction_rev_enabled",
                                "rev_start_number",
                                "created_by",
                                "creation_date",
                                "last_update_by",
                                "last_update_date" ];
  //variables used for showing data
  public static $column_array = ["transaction_id",
                                  "transaction_type_id",
                                  "item_number",
                                  "document_type",
                                  "document_number",
                                  "subinventory",
                                  "reason",
                                  "reference",
                                  "created_by",
                                  "creation_date" ];
  
  public static $account_array = ["from_account",
                                    "to_account" ];
  
 public static $checkbox_array = ["logical_transaction",
                                  "transfer_to_gl",
                                  "transaction_rev_enabled"  ];
 
 public static $required_array = ["item_number",
                                   "org_id",
                                   "item_id",
                                  "transaction_type_id"];
 
  
  
  public $transaction_id;
  public $transaction_type_id;
  public $org_id;
  public $item_id;
  public $item_number;
  public $lot_number;
  public $serial_number;
  public $reason;
  public $reference;
  public $description;
  public $from_org_id;
  public $from_subinventory_id;
  public $from_locator_id;
  public $quantity;
  public $from_account_id;
  public $account;
  public $account_id;
  public $amount;
  
  public $from_amount;
  public $to_org_id;
  public $to_subinventory_id;
  public $to_locator_id;
  public $to_account_id;
  public $to_amount;
  public $costed_amount;
  public $transfer_to_gl;
  public $ef_id;
  public $transaction_rev_enabled;
  public $rev_start_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;

  Public static function inv_transaction_class() {
    $option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
    $inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
    return $inv_transaction_class;
  }

  Public static function transaction_action() {
    $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
    $transaction_action = option_line::find_by_option_id($option_header->option_id);
    return $transaction_action;
  }

  Public static function transaction_action_description($line_code) {
    $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
    $transaction_action = option_line::find_by_optionId_lineCode($option_header->option_id, $line_code);
    return $transaction_action;
  }

  Public static function transaction_action_by_code($code) {
    $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
    $transaction_action = option_line::find_by_option_id($option_header->option_id);
    return $transaction_action;
  }

  public static function find_by_sql($sql = "") {
    global $db;
    $result_set = $db->query($sql);
    $object_array = array();
    while ($row = $db->fetch_array($result_set)) {
      $object_array[] = self::instantiate($row);
    }//end of while Loop
    return $object_array;
  }

  public static function find_all() {
    $sql = " SELECT * FROM " . self::$table_name;
    $result = self::find_by_sql($sql);
    return $result;
  }

  public static function count_all() {
    global $db;
    $sql = "SELECT COUNT(*) FROM " . self::$table_name;
    $result_set = $db->query($sql);
    $row = $db->fetch_array($result_set);
    return array_shift($row);
  }

  public static function count_all_by_sql($sql) {
    global $db;
    $result_set = $db->query($sql);
    $row = $db->fetch_array($result_set);
    return array_shift($row);
  }

  public static function find_by_id($inv_transaction_id) {
    $sql = "SELECT * FROM " . self::$table_name . " where inv_transaction_id={$inv_transaction_id} LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }

  private static function instantiate($record) {
    $object = new self;
    foreach ($record as $attribute => $value) {
      if ($object->has_attribute($attribute)) {
        $object->$attribute = $value;
      }
    }
    return $object;
  }

  Private function has_attribute($attribute) {
    $object_vars = get_object_vars($this);
    return array_key_exists($attribute, $object_vars);
  }

  public static function install() {
    global $db;
    $sql = "
		 ";
    $result = $db->query($sql);
    return !empty($result) ? $result : false;
  }

  public function save() {
    if (empty($this->inv_transaction_id)) {
      $this->create();
    } else {
      $this->update($this->inv_transaction_id);
    }
    return $this->msg;
  }

  public function create() {
    global $db;
    $field_arry_colums = array();
    $field_arry_values = array();
    foreach (self::$field_array as $key => $value) {
      $field_arry_colums[] = sprintf("`%s`", $value);
    }
    $field_colums = implode(',', $field_arry_colums);

    foreach (self::$field_array as $key => $value) {
      if (!empty($this->$value)) {
        $field_arry_values[] = sprintf("'%s'", $this->$value);
      } else {
        $field_arry_values[] = 'NULL';
      }
    }
    $field_values = implode(',', $field_arry_values);

    $sql = " INSERT INTO ";
    $sql.= self::$table_name;
    $sql.= ' ( ';
    $sql.= $field_colums;
    $sql.= ' ) ';
    $sql.= 'VALUES';
    $sql.= ' ( ';
    $sql.= $field_values;
    $sql.= ' ) ';

    if ($db->query($sql)) {
      $this->inv_transaction_id = $db->insert_id();
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

//end of create inv_transaction

  public function update($inv_transaction_id) {
    global $db;
    $field_arry_values = array();

    foreach (self::$field_array as $key => $value) {
      if (!empty($this->$value)) {
        $field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
      }
    }
    $field_values = implode(',', $field_arry_values);

    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE ";
    $sql.= self::$table_name;
    $sql .= " SET ";
    $sql.= $field_values;
//    $sql.= "`last_update_date` = '{$last_update_date}'," ;
//    $sql.= "`last_update_by` = '{$last_update_by }'" ;
    $sql.= " WHERE `inv_transaction_id` = '{$inv_transaction_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

  public static function inv_transaction_page() {
    echo '<table class="normal"><thead><tr>';
    foreach (self::$field_array as $key => $value) {
      echo '<th>' . $value . '</th>';
    }
    echo '</tr></thead><tbody>';

    $inv_transaction = self::find_all();
//    echo '<pre>';
//    print_r($inv_transaction);
//    echo '<pre>';
    foreach ($inv_transaction as $record) {
      echo '<tr>';
      foreach (self::$field_array as $key => $value) {
        echo '<td>' . $record->$value . '</td>';
      }
      echo '</tr>';
    }
    echo ' </tbody> </table>';
  }

}

//end of inv_transaction class
?>



