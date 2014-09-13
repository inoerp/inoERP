<?php

 class gl_ledger extends dbObject {

//protected static variables
  public static $table_name = "gl_ledger";
  public static $dependent_classes = ['gl_ledger_balancing_values'];
//public static varibales - required to be accessed with out intantiating the class
  public static $primary_column = "gl_ledger_id";
  public static $key_column = "ledger";
  public static $module = "gl";
  public $fields_inForm_notInDataBase = [];
  public $fields_inHeader_needsToBeInserted_inPOST = [];
//public attributes used with the class
  public $field_a = [
   'gl_ledger_id',
   'ledger',
   'description',
   'coa_id',
   'coa_structure_id',
   'calendar_option_line_code',
   'currency_code',
   'future_enabled_periods',
   'currency_balancing_ac_id',
   'retained_earnings_ac_id',
   'suspense_ac_id',
   'rev_enabled',
   'rev_number',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $initial_search = [
   'gl_ledger_id',
   'ledger'
  ];
  public $column = [
   'gl_ledger_id',
   'ledger',
   'calendar_option_line_code',
   'currency_code'
  ];
// public $base_encoded = [];
  public $requiredField = [
   'ledger',
   'coa_structure_id',
   'calendar_option_line_code',
   'currency_code'
  ];
// public $dateFields;
//varibles required for search
  public $search = [
   '_update_path' => 'form.php?class_name=gl_ledger',
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update Ledger',
   '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
  ];
  public $pageTitle = " Ledger - Find All Ledgers "; //page Title
  public $option_list = [
   'calendar_option_line_code' => 'GL_CALENDAR_NAME',
   'currency_code' => 'CURRENCY'
  ]; //list of search fields which have options
  public $gl_ledger_id;
  public $ledger;
  public $description;
  public $coa_id;
  public $coa_structure_id;
  public $calendar_option_line_code;
  public $currency_code;
  public $future_enabled_periods;
  public $currency_balancing_ac_id;
  public $retained_earnings_ac_id;
  public $suspense_ac_id;
  public $rev_enabled;
  public $rev_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

    public static function profile_gl_ledger_id_default() {
   $line_data_array = [];
   $line_data_array['line_key'] = 'gl_ledger_id';
   $line_data_array['line_desc'] = 'ledger';
   $line_data_array['line_values'] = gl_ledger::find_all();
   return $line_data_array;
  }

  public function find_coa_byLedgerId() {
   global $db;
   $ledger = $this->findBy_id($this->gl_ledger_id);
   if (empty($ledger)) {
    return;
   }
   $coa = new coa();
   $coa->coa_structure_id = $ledger->coa_structure_id;
   $coa_i = $coa->findBy_structureId();
   return !(empty($coa_i)) ? $coa_i : false;
  }

 }

//end of path class
?>
