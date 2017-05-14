<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * payment_term
 * Payment terms used in AP & AR documents
 * Contains all the conversion information, such as - payment_term, description etc
 * 
 */
class payment_term extends dbObject {

 public static $table_name = "payment_term";
 public static $dependent_classes = ['payment_term_discount', 'payment_term_schedule'];
 public static $primary_column = "payment_term_id";
 public static $key_column = 'payment_term';
 public static $module = "gl";
 public static $system_info = [
  'name' => 'Payment Term',
  'number' => '1108',
  'description' => 'Payment Term',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('payment_term_discount','payment_term_schedule'),
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 8
 ];
 public $checkbox = [
  "rev_enabled_cb",
  "prepayment_cb"
 ];
 public $field_a = [
  'payment_term_id',
  'payment_term',
  'description',
  'prepayment_cb',
  "status",
  "rev_enabled_cb",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  'payment_term_id',
  'payment_term',
  'description',
 ];
 public $column = [
  'payment_term_id',
  'payment_term',
  'description'
 ];
 public $requiredField = [
  'payment_term',
  'description'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Payment Term "; //page Title
 public $payment_term_id;
 public $payment_term;
 public $description;
 public $prepayment_cb;
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

}

//end of payment_term class
?>