<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

if ((!empty($_GET['save_ratings'])) && (!empty($_GET['rating']))) {
 $extn_rating = new extn_rating_values();
 $extn_rating->rating = !empty($_GET['rating']) ? ($_GET['rating']) : '';
 $extn_rating->reference_id = !empty($_GET['reference_id']) ? ($_GET['reference_id']) : '';
 $extn_rating->reference_table = !empty($_GET['reference_table']) ? ($_GET['reference_table']) : '';
 $extn_rating->ip_address = get_user_ip();
 $extn_rating->vote_time = current_time();

 try {
  $extn_rating->save();
  $dbc->confirm();
  $data = ['result' => 'Thank You'];
 } catch (Exception $e) {
  $data = ['result' => ''];
 }

 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>