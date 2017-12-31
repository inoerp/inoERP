<?php

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['ino_auto_complete']))) {

 global $db;
 $org = new org();

// if the 'term' variable is not sent with the request, exit
 if (!isset($_REQUEST['term'])) {
  echo "exit";
  exit;
 } else {
  $item_number = $_REQUEST['term'];
  if (!empty($_GET['primary_column1'])) {
   $org_id = $_GET['primary_column1'];
  } else {
   $master_org = $org->findAll_item_master();
   $org_id = $master_org[0]->org_id;
  }

  if (!empty($_GET['other_options'])) {
   $options = $_GET['other_options'];
  } else {
   $options = [];
  }
  if (!empty($_GET['hidden_fields'])) {
   $hidden_fields = array_merge($options, $_GET['hidden_fields']);
  } else {
   $hidden_fields = [];
  }

  $all_options = array_merge($hidden_fields, $options);

//  pa($all_options);
//echo $org_id;
  $data = item::find_item_number_by_itemNumber_OrgId_allAttributes($item_number, $org_id, $all_options);
// jQuery wants JSON data
  $json = json_encode($data);
  echo header('Content-Type: application/json');
  echo json_encode(($data));
 }
}
?>