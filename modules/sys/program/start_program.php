<?php
include_once ('includes/basics/basics.inc');
$p = new sys_program();
$p_toStart = $p->findBy_status('Initiated');

if(!empty($p_toStart)){
 foreach ($p_toStart as $key=>$value){
	$p->$value = $p_toStart->$value;
 }
 $class = $p->class ;
 $$class = new $class;
 try{
 $result = call_user_func_array(array($$class, $$class->program_name), $$class->parameters);
 $p->message = 'Program is sucessfully completed <br>'.$result ;
	$p->save();
 }catch(Exception $e){
	$p->message = "<br> Program failed @ start_program " . __LINE__. '<br>' . $e->getMessage();
	$p->save();
 }
}
$p->status = 'Completed';
$p->audit_trial();
try {
 $p->save();
 echo "<div id='json_save_header'><div class='message'>The program is sucessfully saved; Program Id is " . $p->sys_program_id . '</div></div>';
} catch (Exception $e) {
 echo " Saving the program failed! " . $e->getMessage();
 return -99;
}
?>
