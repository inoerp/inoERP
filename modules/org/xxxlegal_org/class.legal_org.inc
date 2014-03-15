<?php

class legal_org {
  protected static $table_name = "legal_org";
  public $legal_id;
  public $name;
  public $description;
  public $address_id;
  public $legal_org_type;
  public $registration_number;
  public $place_of_registration;
  public $country_of_registration;
  public $identification_number;
  public $ein_tin_tan;
  public $ledger_id;
  public $balancing_segments;
  public $ef_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;

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

  public static function find_by_id($legal_id) {
    $sql = "SELECT * FROM " . self::$table_name . " where legal_id={$legal_id} LIMIT 1";
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
    if (empty($this->legal_id)) {
      $this->create();
    } else {
      $this->update($this->legal_id);
    }
    return $this->msg;
  }

  public function create() {
    global $db;
    $sql = "INSERT INTO legal_org (
					  `legal_id`, 
					  `created_by`, 
					  `creation_date`, 
					  `last_update_by`, 
					  `last_update_date`) 
  VALUES( NULL , '{$this->created_by}', '{$this->creation_date}', '{$this->created_by}', 
		 '{$this->creation_date}' )";

    if ($db->query($sql)) {
      $this->legal_id = $db->insert_id();
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

//end of create legal_org

  public function update($legal_id) {
    global $db;
    $legal_id = $db->escape_value($this->legal_id);
    $legal_org_type = $db->escape_value($this->legal_org_type);
    $registration_number = $db->escape_value($this->registration_number);
    $place_of_registration = $db->escape_value($this->place_of_registration);
    $country_of_registration = $db->escape_value($this->country_of_registration);
    $identification_number = $db->escape_value($this->identification_number);
    $ein_tin_tan = $db->escape_value($this->ein_tin_tan);
    $ledger_id = $db->escape_value($this->ledger_id);
    $balancing_segments = $db->escape_value($this->balancing_segments);
    $ef_id = $db->escape_value($this->ef_id);
    
    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE `legal_org` SET 
			`legal_org_type` = '{$legal_org_type}', 
			`registration_number` = '{$registration_number}',
            `place_of_registration` = '{$place_of_registration}',
            `registration_number` = '{$registration_number}',
            `country_of_registration` = '{$country_of_registration}',
            `identification_number` = '{$identification_number}',
            `ein_tin_tan` = '{$ein_tin_tan}',
            `ledger_id` = '{$ledger_id}',
            `balancing_segments` = '{$balancing_segments}',
            `ef_id` = '{$ef_id}',
            `last_update_by`= '{$last_update_by}', 
			`last_update_date`= '{$last_update_date}'
			 WHERE `legal_id` = '{$legal_id}' ";

    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

  public static function legal_org_page() {
    echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>Legal Org Id</th>
                    <th>Name</th>
                    <th>Description</th>
                    <th>Address Id</th>
                    <th>Registration Number</th>
                    <th>Ledger Id</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Update By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

    $legal_org = legal_org::find_all();
    foreach ($legal_org as $record) {
      $org = org_header::find_by_legal_id($record->legal_id);
      echo '<tr><td>' . $record->legal_id . '</td>';
      echo '<td>' . $org->name . '</td> ';
      echo '<td>' . $org->description . '</td>';
      echo '<td>' . $org->address_id . '</td> ';
      echo '<td>' . $record->registration_number . '</td>';
      echo '<td>' . $record->ledger_id . '</td>';
      echo '<td>' . $record->created_by . '</td>';
      echo '<td>' . $record->creation_date . '</td> ';
      echo '<td>' . $record->last_update_by . '</td>';
      echo '<td>' . $record->last_update_date . '</td>';
      echo '<td><a href="legal_org.php?legal_id=' . $record->legal_id . '">Update</a></td></tr>';
    }

    echo ' </tbody> </table>';
  }

}

//end of legal_org class
?>
