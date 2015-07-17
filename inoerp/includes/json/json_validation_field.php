<?php include_once("../basics/basics.inc"); ?>
<?php

if ((!empty($_GET['val_value'])) && (!empty($_GET['val_field']))) {

 if (empty($_REQUEST['term'])) {
  exit;
 }

 if (!empty($_GET['dependent_fields'])) {
  $dependent_fields = ($_GET['dependent_fields']);
 } else {
  $dependent_fields = null;
 }

 if (!empty($_GET['hidden_fields'])) {
  $hidden_fields = ($_GET['hidden_fields']);
 } else {
  $hidden_fields = null;
 }

 $f_val = $_REQUEST['term'];

 $class_name = $_GET['val_field'];
 $f_name = $_GET['val_value'];

 $data = $class_name::find_by_ColumnNameVal($f_name, $f_val, $dependent_fields, $hidden_fields);

 if ($data) {
  if (property_exists($class_name, 'json_label_fields')) {
   $json_label_fields_a = $class_name::$json_label_fields;
   foreach ($data as $obj) {
    $labl = '';
    foreach ($json_label_fields_a as $k => $v) {
     $labl .= $obj->$v . ' | ';
    }
    $obj->label = $labl;
    $obj->value = $obj->$f_name;
   }
  } else {
   foreach ($data as $obj) {
    $obj->label = $obj->$f_name;
   }
  }
 }


 if (count($data) > 0) {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>