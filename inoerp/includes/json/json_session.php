<?php include_once("../basics/basics.inc"); ?>
<?php

if ((!empty($_POST['save_dataInSession'])) && (!empty($_POST['data_name']))) {
 $data_name = $_POST['data_name'];
 $data_val = !empty($_POST['data_value']) ? $_POST['data_value'] : false;

 if (!empty($_GET['over_write']) && ($_GET['over_write'] = true)) {
  if (!empty($_POST['data_value'])) {
   $_SESSION[$data_name] = $data_val;
  } else {
   $_SESSION[$data_name] = false;
  }
 } else {
  if (!empty($_SESSION[$data_name])) {
   if (!in_array($data_val, $_SESSION[$data_name])) {
    array_push($_SESSION[$data_name], $data_val);
   }
  } else {
   $_SESSION[$data_name] = array($data_val);
  }
 }

 return true;
}
?>