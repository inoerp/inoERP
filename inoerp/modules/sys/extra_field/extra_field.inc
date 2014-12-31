<?php

if (!empty($$class->sys_extra_field_id)) {
 $instances = sys_extra_field_instance::find_by_extraFieldId($$class->sys_extra_field_id);
 if ($instances) {
  $readonly = 1;
  $mode = 2;
 }
}
?>