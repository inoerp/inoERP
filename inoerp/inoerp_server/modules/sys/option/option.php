<?php
if (!empty($_GET['mode'])) {
 $mode = $_GET['mode'];
} else {
 $path_access = -99;
 $mode = 1;
}
?>
<?php include_once("option.inc"); ?>
<?php

//set the option id of option line as 0
//@required : To create line form for new entry
//@required : To create line form where only header is entered
$option_id_l = 0;
?>
<?php empty($_POST) ? require_once('option_template.php') : false; ?>
