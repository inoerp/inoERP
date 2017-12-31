<?php

//$f = new inoform();
//$class = $class_first = 'inv_transaction';
//$$class = $$class_first = &$inv_transaction;
$class_second = 'pm_batch_line';
$$class_second = &$pm_batch_line;

$$class->document_type = 'Batch';
$$class->reference_type = 'table';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['pm_batch_header_id'])) {
 $pm_batch_header_id = ($_GET["pm_batch_header_id"]);
 $pm_batch = pm_batch_header::find_by_id($pm_batch_header_id);
} else if (!empty($_GET["batch_name"])) {
 $batch_name = $_GET["batch_name"];
 $pm_batch = pm_batch_header::find_by_batchName($batch_name);
 $pm_batch_header_id = $pm_batch->pm_batch_header_id;
}
if (!empty($pm_batch_header_id)) {
 $$class->org_id = $pm_batch->org_id;
 $$class->pm_batch_header_id = $pm_batch_header_id;
 $$class->batch_name = $pm_batch->batch_name;
 $pm_batch_bom_object = pm_batch_ingredient::find_all_lines_for_trnx_by_headerId($pm_batch_header_id);
 if (count($pm_batch_bom_object) == 0) {
  $pm_batch_bom_object = [new pm_batch_line()];
 }
}
?>

<?php

if ((!empty($pm_batch_header_id)) && !empty($pm_batch_bom_object)) {
 $bom_sequence_stament = '<select class=" select bom_sequence " name="bom_sequence[]">';
 $bom_sequence_stament .= '<option></option>';
 foreach ($pm_batch_bom_object as $array) {
  $bom_sequence_stament .='<option ';
  $bom_sequence_stament .=' data-item_number ="' . $array->item_number . '"';
  $bom_sequence_stament .=' data-item_description ="' . $array->item_description . '"';
  $bom_sequence_stament .=' data-item_id_m ="' . $array->item_id_m . '"';
  $bom_sequence_stament .=' data-step_no ="' . $array->step_no . '"';
  $bom_sequence_stament .=' data-uom_id ="' . $array->uom_id . '"';
  $bom_sequence_stament .=' data-planned_quantity ="' . $array->planned_quantity . '"';
  $bom_sequence_stament .=' data-actual_quantity ="' . $array->actual_quantity . '"';
  $bom_sequence_stament .=' data-org_id ="' . $array->org_id . '"';
  $bom_sequence_stament .=' data-subinventory_id ="' . $array->subinventory_id . '"';
  $bom_sequence_stament .=' data-serial_generation ="' . $array->serial_generation . '"';
  $bom_sequence_stament .=' data-lot_generation ="' . $array->lot_generation . '"';
  $bom_sequence_stament .=' value="' . $array->pm_batch_ingredient_id . '" >';
  $bom_sequence_stament .= $array->step_no . ' | ' . $array->item_number . ' | ' . $array->item_description;
  $bom_sequence_stament .= '</option>';
 }
 $bom_sequence_stament .= '</select>';
}

if (empty($$class->transaction_type_id)) {
 $$class->transaction_type_id = 29;
}
?>