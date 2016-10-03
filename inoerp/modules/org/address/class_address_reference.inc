<?php

class address_reference extends dbObject {

 public static $table_name = "address_reference";
//  data base variables as stored database column name
 public $field_a = [
  "address_reference_id",
  "address_id",
  "reference_table",
  "reference_id",
  'status'
 ];
 public $address_reference_id;
 public $address_id;
 public $reference_table;
 public $reference_id;
 public $status;
 public static $primary_column = "address_reference_id";

 public static function find_by_reference_detailts($ref_table, $ref_id) {
  $sql = " SELECT ad.address_id, ad.type, ad.address_name, ad.phone, ad.email, ad.website, ad.address, ad.country, ad.postal_code,
   ad.default_cb

FROM address ad,
address_reference ar

WHERE ad.address_id = ar.address_id
AND ar.reference_id = '{$ref_id}'
AND ar.reference_table = '{$ref_table}'";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function address_stmt_byReference($ref_table, $ref_id) {
  $all_address = self::find_by_reference_detailts($ref_table, $ref_id);
  if (empty($all_address)) {
   return false;
  }
  $stmt = '<div class="existing-address inline">';
  foreach ($all_address as $address) {
   $stmt .= '<div class="address-stmt">';
   $stmt .= '<div class="panel-heading">' . $address->address_name . ' <i class="fa fa-minus-circle"></i></div>';
   $stmt .= '<div class="panel-body"><ul>';
   $stmt .= '<li>' . $address->address . '</li>';
   $stmt .= '<li>' . $address->country . ' ' . $address->postal_code . '</li>';
   $stmt .= '<li>' . $address->phone . '</li>';
   $stmt .= '<li>' . $address->email . '</li>';
   $stmt .= '<li>' . $address->website . '</li>';
   $stmt .= '</ul></div>';

   $stmt .= '</div>';
  }
  $stmt .= '</div>';
 }

 public static function show_address($all_address, $show_addres_id_name = false, $ref_class_name = null) {
  global $f; 
  if (empty($all_address)) {
   return false;
  }
  $stmt = '<div id="existing-address-details">';
  foreach ($all_address as $address) {
   $stmt .= '<div class="panel panel-warning address-stmt">';
   $stmt .= '<div class="panel-heading">' . $address->address_name . '&nbsp;&nbsp;&nbsp;';
   $stmt .= '<a  class="popup popup-form view-addrees medium" href="form.php?class_name=address&mode=9&window_type=popup&ref_class_name='.$ref_class_name.'&address_id='.$address->address_id.'"><i class="fa fa-trash-o clickable"></i></a>&nbsp;&nbsp;&nbsp;';
   $stmt .= '<a class="popup popup-form view-addrees medium" href="form.php?class_name=address&mode=9&window_type=popup&ref_class_name='.$ref_class_name.'&address_id='.$address->address_id.'"><i class="fa fa-edit clickable"></i></a>';
   $stmt .= '</div>';
   $stmt .= '<div class="panel-body"><ul>';
   $stmt .= '<li>' . $address->address . '</li>';
   $stmt .= '<li>' . $address->country . ' ' . $address->postal_code . '</li>';
   $stmt .= '<li>' . $address->phone . '</li>';
   $stmt .= '<li>' . $address->email . '</li>';
   $stmt .= '<li>' . $address->website . '</li>';
   if ($show_addres_id_name) {
    $stmt .= '<li class="hidden">' . $f->hidden_field($show_addres_id_name, $address->address_id) . '</li>';
   }
   $stmt .= '</ul></div>';

   $stmt .= '</div>';
  }
  $stmt .= '</div>';

  return $stmt;
 }

// 
}

//end of address_reference class
?>