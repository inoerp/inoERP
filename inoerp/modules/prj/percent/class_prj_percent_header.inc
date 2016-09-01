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
 * prj_percent_header
 * A sigle transaction document(invoice, etc) can be created against multiple purchase orders
 * Transaction header contains all the header level informations such as supplier site, document_type, currency, header amount,  paying entity
 * Transaction line contains invoices details
 *
 */
class prj_percent_header extends dbObject {

 public static $table_name = "prj_percent_header";
 public static $dependent_classes = ['prj_percent_line_v'];
 public static $primary_column = "prj_percent_header_id";
 public static $key_column = 'prj_project_header_id';
 public static $module = "prj"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Project Percent ',
  'number' => '6030',
  'description' => 'Create & Mainten Project Status Percent ',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_percent_line'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 3
 ];
 public $field_a = [
  'prj_percent_header_id',
  'prj_project_header_id',
  'percent',
  'description',
  'as_of_date',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'prj_project_header_id',
 ];
 public $requiredField = [
  'prj_project_header_id',
  'percent',
  'as_of_date',
 ];
 public $fields_inForm_notInDataBase = [
  'project_number',
  'project_description',
  'percent_old',
  'as_of_date_old'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Completion Status  "; //page Title
 public $prj_percent_header_id;
 public $prj_project_header_id;
 public $percent;
 public $description;
 public $as_of_date;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $project_description;
 public $percent_old;
 public $as_of_date_old;

 public function _before_save() {
  if ($this->percent != $this->percent_old) {
   return $this->_percent_action();;
  }
 }

 private function _percent_action() {
  if ($this->percent < $this->percent_old) {
   echo "<br>You can't reduce the percenatage ";
   return -90;
  } else if ($this->percent > $this->percent_old) {
   $new_date = new DateTime($this->as_of_date);
   $old_date = new DateTime($this->as_of_date);
   if ($new_date < $old_date) {
    echo "<br>You can't enter an old as of date ";
    return -90;
   }
   $pph = new prj_percent_headerrev();
   foreach ($pph->field_a as $k => $v) {
    if (property_exists($this, $v)) {
     $pph->$v = $this->$v;
    }
   }
   $pph->prj_percent_headerrev_id = null;
   $pph->save();
   return true;
  }
 }
 
 public function __after_save(){
  pa($this);
 }

}

//end of prj_percent_header class
?>