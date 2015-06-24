<?php

 if (!empty($_GET['obj_class_name'])) {
  $obj_class_name_h = $_GET['obj_class_name'];
  $secondary_field_object = sys_secondary_field_instance::find_by_referenceKey($obj_class_name_h);
 } else {
  $obj_class_name_h = '';
 }

 if (empty($secondary_field_object)) {
  $secondary_field_object = array(new sys_secondary_field_instance());
 }

 ?>