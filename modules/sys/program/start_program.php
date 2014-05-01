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

	$class = $p->class;
	$$class = new $class;
	try {
	 $result = call_user_func(array($$class, $p->program_name), $p->parameters);
	 $p->message = "Program $p->program_name is sucessfully completed <br>" . $result . '<br>' . execution_time();
	 $p->status = 'Completed';
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