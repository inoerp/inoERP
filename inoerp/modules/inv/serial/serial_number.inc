<?php
if (empty($$class->inv_serial_number_id)) {
 $$class->status = 'DEFINED';
 $$class->generation = 'PRE_DEFINED';
 $$class->origination_type = 'MANUAL';
 $$class->origination_date = current_time(1);
 $$class->current_org_id = $$class->org_id;
}else{
 $result_stmt = '<a class="button" href="#" >No Result</a>';
}

if(!empty($$class->item_id_m)){
 $item_d = item::find_by_orgId_item_id_m($$class->item_id_m, $$class->org_id);
 $$class->item_number = $item_d->item_number;
 $$class->item_description = $item_d->item_description;
}
?>