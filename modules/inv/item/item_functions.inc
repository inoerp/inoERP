<?php
$account_array = item::$account_array;
$checkbox_array = item::$checkbox_array;
$field_array = item::$field_array;

$item = new item;

foreach ($account_array as $key => $value) {
 $item->$value = "";
}

foreach ($field_array as $key => $value) {
 $item->$value = "";
}

foreach ($checkbox_array as $key => $value) {
 $item->$value = "";
}

$msg = "";
?>


<?php
if (!empty($_GET["item_id"])) {
 $item_id = $_GET["item_id"];
 $item = item::find_by_id($item_id);
 $org = org_header::find_by_id($item->org_id);

 foreach ($account_array as $key => $value) {
  if (!empty($item->$value)) {
   $coa = coa_combination::find_by_id($item->$value);
   if (count($item) != 0) {
    $item->$value = $coa->combination;
   } else {
    $item->$value = "";
   }
  }
 }
}
?>

<?php
if ((!empty($_GET["item_number"])) && (!empty($_GET["org_id"]))) {
 $item_number = $_GET["item_number"];
 $org_id = $_GET["org_id"];
 if (item::find_by_itemNumber_OrgId($item_number, $org_id)){
  $item = item::find_by_itemNumber_OrgId($item_number, $org_id);
  $org = org_header::find_by_id($item->org_id);

 foreach ($account_array as $key => $value) {
  if (!empty($item->$value)) {
   $coa = coa_combination::find_by_id($item->$value);
   if (count($item) != 0) {
    $item->$value = $coa->combination;
   } else {
    $item->$value = "";
   }
  }
 }
 }else{
  $msg = "Item or Item-Organization is not defined!!";
 }
 
 
}
?>

<?php
$msg = array();
if (!empty($_POST['submit_item'])) {
 $item = new item;
 if (empty($_POST['item_id'])) {
  $item->item_id = null;
 } else {
  $item->item_id = trim(mysql_prep($_POST['item_id']));
 }
 $coa_id = 7;

 foreach ($account_array as $key => $value) {
  if (!empty($_POST[$value])) {
   if (coa_combination::validate_coa_combination($coa_id, $_POST[$value]) == 1) {
    $value_id = $value . '_id';
    $item->$value_id = coa_combination::find_combination_id_from_combination($coa_id, $_POST[$value]);
   } else {
    $msgNew = "Invalid " . $value;
    array_push($msg, $msgNew);
   }
  } else {
   $msgNew = $value . " is missing";
   array_push($msg, $msgNew);
  }
 }
 
 foreach ($checkbox_array as $key => $value) {
  if (isset($_POST[$value])) {
   $item->$value = 1;
  } else {
   $item->$value = 0;
  }
 }

 foreach ($field_array as $key => $value) {
  if (isset($_POST[$value])) {
      $item->$value = trim(mysql_prep($_POST[$value]));
  } else {
   $item->$value = "";
  }
 }
 
 if($item->transactable==1){
  $item->inventory_item = 1 ;
  $item->stockable = 1 ;
 }
  
 if($item->reservable==1){
  $item->inventory_item = 1 ;
  $item->stockable = 1 ;
 }
 
 $time = time();
 $item->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
 $item->created_by = $_SESSION['user_name'];

//for new item creation the item id should be null & inventory org should be a master org
//for existing item assignment, the item_id should not be null and org should not be item master
 $inventory_org = inventory_org::find_by_org_id($item->org_id);
 $condtion_new_item = (!($item->item_id)) && ($inventory_org->item_master);
 $condtion_existing_item = ($item->item_id) && (!($inventory_org->item_master));

 if ($condtion_new_item || $condtion_existing_item) {
  if (empty($item->org_id) || empty($item->description) || empty($item->item_number)) {
   
   $newMsg = "Item Number, Description or Inventory is Blank";
   array_push($msg, $newMsg);
  } else {
    $new_item_entry = $item->save();
   if ($new_item_entry == 1) {
    $newMsg = 'Item is sucessfully saved';
    array_push($msg, $newMsg);
   }//end of item entry & msg
   else {
    $newMsg = "Record coundt be saved!!" . mysql_error() .
            ' Returned Value is : ' . $new_item_entry;
    array_push($msg, $newMsg);
   }//end of item insertion else
  }//end of item check & new item creation
 } else {
  $item_mater_update = $item->update($item->item_id);
  if ($item_mater_update == 1) {
   $newMsg = 'Item is sucessfully saved in Item Master';
   array_push($msg, $newMsg);
  }//end of item entry & msg
  else {
   $newMsg = "Record coundt be saved!!" . mysql_error() .
           ' Returned Value is : ' . $new_item_entry;
   array_push($msg, $newMsg);
  }
 }



 //reset all accounts to accounts from id
}//end of post submit header
?>
