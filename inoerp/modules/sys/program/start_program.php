<?php
set_time_limit(120);
include_once ('../../../includes/basics/basics.inc');

function start_next_program() {
 global $dbc;
 $p = new sys_program();
 $p_toStart = $p->findBy_status('Initiated');
 if (!empty($p_toStart)) {
	foreach ($p->field_a as $key => $value) {
	 $p->$value = $p_toStart->$value;
	}
		//update the status to inprogress
	$p->status = 'inprogress';
	$p->save();
	$dbc->confirm();
  
	$class = $p->class;
	$$class = new $class;
	try {
	 $result = call_user_func(array($$class, $p->program_name), $p->parameters);
	 $result_message = is_array($result) ? $result[0] : $result;
	 $result_output = is_array($result) ? $result[1] : null;
	 $p->message = "Program $p->program_name is sucessfully completed <br>" . $result_message . '<br>' . execution_time();
	 $p->status = 'Completed';
	 try {
		if (!empty($result_output)) {
		 $op_file_name = $p->program_name . '_' . time() . '.xls';
		 $module_name = $class::$module;
		 $file_path = HOME_DIR . "/files/outputs/modules/$module_name/$p->program_name/$op_file_name";
		 $file = fopen($file_path, 'w');
		 $headerData = [];
		 foreach ($result_output[0] as $key => $value) {
			array_push($headerData, $key);
		 }
		 fputcsv($file, $headerData);

		 foreach ($result_output as $obj) {
			$rowData = [];
			foreach ($obj as $key => $value) {
			 array_push($rowData, $value);
			}
			fputcsv($file, $rowData);
		 }
		 fclose($file);
		 $p->output_path = "/files/outputs/modules/$module_name/$p->program_name/$op_file_name";
		}
	 } catch (Exception $e) {
		$p->output_path = null;
	 }
	 $p->audit_trial();
	 $p->save();
	} catch (Exception $e) {
	 $p->status = 'Failed';
	 $p->message = "<br> Program failed @ start_program " . __LINE__ . '<br>' . $e->getMessage();
	 $p->audit_trial();
	 $p->save();
	}
	$dbc->confirm();
 } else {
	sleep(5);
 }

 execution_time();
 unset($p_toStart);
 unset($p);
}

do {
 start_next_program();
} while (execution_time(true) < 55);
?>