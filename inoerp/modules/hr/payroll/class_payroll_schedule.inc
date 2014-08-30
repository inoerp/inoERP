<?php

 class hr_payroll_schedule extends dbObject {

  public static $table_name = "hr_payroll_schedule";
  public static $primary_column = "hr_payroll_schedule_id";
  public static $parent_primary_column = "hr_payroll_id";
  public static $key_column = "hr_payroll_id";
  public static $module = "hr";
  public $field_a = [
   'hr_payroll_schedule_id',
   'hr_payroll_id',
   'scheduled_date',
   'start_date',
   'end_date',
   'description',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_payroll_schedule_id',
   'hr_payroll_id',
  ];
  public $requiredField = [
   'hr_payroll_id',
   'scheduled_date',
   'start_date',
   'end_date',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "hr_payroll_id"
  ];

  public $pageTitle = " Payroll Schedule "; //page Title
  public $hr_payroll_schedule_id;
  public $hr_payroll_id;
  public $scheduled_date;
  public $start_date;
  public $end_date;
  public $description;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  


  public static function find_all_lines() {
   $sql = " SELECT * FROM " . self::$table_name;
   $result = self::find_by_sql($sql);
   return $result;
  }

  public static function find_by_header_id($id) {
   $vgl = new hr_payroll_schedule();
   return $vgl->findBy_parentId($id);
  }

  public static function find_by_optionId_lineCode($header_id, $code) {
   $sql = "SELECT * FROM " . self::$table_name .
     " where code={$code} AND hr_payroll_id={$header_id} LIMIT 1 ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_push($result) : $result;
  }

  public function _before_save() {
   if (!(empty($this->item_number)) && empty($this->item_id_m)) {
    $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
    $this->item_id_m = $item_s->item_id_m;
   }
  }

  public static function priceBy_headerId_ItemId($item_id_m, $price_date, $hr_payroll_id = '1') {
   $sql = " 
	 SELECT *
		FROM hr_payroll_schedule 
		WHERE  hr_payroll_id = '{$hr_payroll_id}'
		AND item_id_m = '{$item_id_m}'
		AND effective_start_date < '{$price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$price_date}')
		 LIMIT 1
";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public function priceBy_headerId_orgId_ItemId($price_date) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE hr_payroll_id = '{$this->hr_payroll_id}' ";
   $sql .= " AND item_id_m = '{$this->item_id_m}' ";
   $sql .= " AND org_id = '{$this->org_id}' ";
   $sql .= " AND $this->effective_start_date < '{$price_date}' ";
   $sql .= " AND $this->effective_end_date > '{$price_date}' ";
   $sql .= " OR $this->effective_end_date IS NULL ";

   $result = $this->findBySql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public function getPrice($price_date) {
   if (!empty($this->org_id)) {
    $result = $this->priceBy_headerId_orgId_ItemId($price_date);
   }
  }

 }

//end of path class
?>