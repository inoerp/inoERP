<?php

 if (empty($$class->inv_serial_number_id)) {
  $$class->status = 'DEFINED';
  $$class->generation = 'PRE_DEFINED';
  $$class->origination_type = 'MANUAL';
  $$class->origination_date = current_time(1);
  $$class->current_org_id = $$class->org_id;
 } else {
  $result_stmt = '<a class="button" href="#" >No Result</a>';
 }

 if (!empty($$class->item_id_m)) {
  $item_d = item::find_by_orgId_item_id_m($$class->item_id_m, $$class->org_id);
  $$class->item_number = $item_d->item_number;
  $$class->item_description = $item_d->item_description;
 }

 $inv_serial_transaction_object = array(new inv_serial_transaction_v());
 if (!empty($$class->inv_serial_number_id)) {
  $inv_serial_transaction_object = inv_serial_transaction_v::find_by_invSerialNumberId($$class->inv_serial_number_id);
  $child_serial = inv_serial_number::find_allChild_bySerialId($$class->inv_serial_number_id);
 }

 if (!empty($$class->parent_serial_number_id)) {
  $parent_serial = inv_serial_number::find_by_id($$class->parent_serial_number_id);
 }
 
?>