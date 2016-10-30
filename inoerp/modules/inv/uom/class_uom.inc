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
 * uom
 * Contains all the transaction_type information, such as - uom_id, class, uom_name,  description, etc.
 * 
 */
class uom extends dbObject {

 public static $table_name = "uom";
 public static $primary_column = "uom_id";
 public static $key_column = 'uom_name';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/uom/multi_action/uom_template_ma.php';
  public static $system_info = [
  'name' => 'UOM',
  'number' => '2116',
  'description' => 'Unit Of Measure',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 16
 ];
 public $field_a = [
		 "uom_id",
		 "class",
		 "uom_name",
		 "description",
		 "primary_cb",
		 "primary_uom_id",
		 "primary_relation",
		 "status",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "uom_id",
		 "class",
		 "uom_name",
		 "description",
		 "primary_uom_id"
 ];

 public $checkbox = [
		 "rev_enabled_cb",
		 'primary_cb'
 ];
 public $requiredField = [
		 "class",
		 "uom_name"
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "primary_uom"
 ];
 public $pageTitle = " UOM - Create & Update UOM"; //page Title
 public $option_lists = [
		 'uom_class' => 'UOM_CLASS',
 ];
 public $uom_id;
 public $class;
 public $uom_name;
 public $description;
 public $primary_cb;
 public $primary_uom_id;
 public $primary_relation;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $primary_uom;

 
 public static $table_line_tr = <<<'VAR'
<thead> 
 				 <tr>
 					<th>Action</th>
 					<th>UOM Id</th>
 					<th>UOM</th>
 					<th>Class</th>
 					<th>Description</th>
 					<th>Primary</th>
 					<th>Primary UOM</th>
 					<th>Operator</th>
 					<th>Primary Relation</th>
 					<th>EF Id</th>
 					<th>Status</th>
 					<th>Rev Enabled</th>
 					<th>Rev#</th>
 				 </tr>
 				</thead>
VAR;
 
 Public static function uom_class() {
	$option_header = option_header::find_by_name('UOM_CLASS');
	$uom_class = option_line::find_by_option_id($option_header->option_header_id);
	return $uom_class;
 }

 public function _before_showing() {
	if (!empty($this->primary_uom_id)) {
   $p_uom = new uom();
	 $primar_uom_i = $p_uom->findBy_id($this->primary_uom_id);
	 $this->primary_uom = $primar_uom_i->uom_name;
	}
 }

 public static function find_uom_by_uom($uom) {
	global $db;
	$sql = "SELECT uom_name, description FROM "
					. self::$table_name
					. " where uom_name LIKE '%{$uom}%' ";
          $sql = ino_perPageSql_i($sql, 30);
	$result = $db->find_by_sql($sql);
	$data = array();
	if ($result) {
	 foreach ($result as $row) {
		$data[] = array(
				'label' => $row->uom_name . ' , ' . $row->description,
				'value' => $row->uom_name
		);
	 }
	}

	return $data;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'mode',
			'show_block'
	];

	return $multi_select_hidden;
 }

 public static function staticVar_init($staticvar) {
  $lines = explode("\n", self::${$staticvar});
  self::${$staticvar} = '';
  foreach ($lines as $key => $line) {
   if(strpos($line,'<th>') !== FALSE) {
 	$left = substr($line,0,strpos($line,'>')+1);
 	$text = trim(rtrim(trim(substr($line,strpos($line,'>')+1,strpos($line,'/')-strpos($line,'>')-2)),'#'));
 	$right = substr($line,strpos($line,'/')-1);
 	if(substr(trim(substr($line,strpos($line,'>')+1,strpos($line,'/')-strpos($line,'>')-2)),-1) == '#') {
 	 $line =  $left . gettext($text) . '#' . $right;
 	} else {
 	 $line =  $left . gettext($text) . $right;
 	}
   }
   self::${$staticvar} = self::${$staticvar} . $line;
   if($line != end($lines)) {
    self::${$staticvar} = self::${$staticvar} . "\n";
   }
  }
 }

}

//end of uom class
uom::staticVar_init('table_line_tr');
?>
