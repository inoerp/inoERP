<?php

/**
 * inoERP
 *
 * @copyright   2015 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mail_form
 * Contains all the mail_form information, such as - mail_form_id, type, description,  mail_form_name, etc.
 * 
 */
class qa_quality_result extends dbObject {

 public static $key_column = 'reference_key_name';
 public $reference_type;
 public $reference_entity;
 public $reference_key_name;
 public $reference_key_value;
 public $qa_cp_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $primary_clmn;

 public function _before_save() {
  $this->_do_before_save();
 }

 private function _do_before_save(){
  
  pa($_POST);
 }


}

?>
