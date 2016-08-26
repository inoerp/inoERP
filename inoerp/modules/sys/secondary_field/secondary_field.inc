<?php

 if (!empty($$class->sys_secondary_field_id)) {
  $instances = sys_secondary_field_inst::find_by_secondaryFieldId($$class->sys_secondary_field_id);
//  $readonly = 1;
//  $mode = 2;
 }

 $extra_element_label = 'Secondary Field';
// $class_name_object = $bom_routing_line_object;
 $ef_refer_key = 'bom_routing_line';
 $ef_refer_value = 'bom_routing_line_id';
 $tr_class = 'bom_routing_line';
?>