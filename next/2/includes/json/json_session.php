<?php include_once("../basics/basics.inc"); ?>
<?php

if ((!empty($_POST['save_dataInSession'])) && (!empty($_POST['data_name']))) {
 $data_name = $_POST['data_name'];
 $session_data_name_a = $_SESSION[$data_name];
 $data_val = !empty($_POST['data_value']) ? $_POST['data_value'] : false;
 $remove_data = !empty($_POST['remove_data']) ? true : false;
 if (!empty($_POST['over_write']) && ($_POST['over_write'] == 1)) {
  if (!empty($_POST['data_value'])) {
   if ($remove_data && is_array($session_data_name_a)) {
    $ar_k = array_pop(array_keys($session_data_name_a, $data_val));
    unset($_SESSION[$data_name][$ar_k]);
   } else {
    $_SESSION[$data_name] = array($data_val);
   }
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