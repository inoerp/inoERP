<?php include_once("../basics/basics.inc"); ?>
<?php
if ((!empty($_POST['save_dataInSession'])) && (!empty($_POST['data_name']))) {
 $data_name = $_POST['data_name'];
 if (!empty($_POST['data_value'])) {
  $_SESSION[$data_name] = $_POST['data_value'];
 } else {
  $_SESSION[$data_name] = false;
 }
 return true;
}
?>