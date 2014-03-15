<?php include_once("../../include/basics/header.inc"); ?>
<script src="org.js"></script>

<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_org'] = '1';
	$_POST = $postArray;

	$org = Pre_Loading_Function('org', 'org', 'org', 'org_id');
	if (!empty($org->org_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $org->org_id . '</div>';
	} else {
	 echo " Error code:  ! ";
	}
 }
 ?>
</div>


<div id="enterprise_json">
  <?php
  $enterprises = org::find_all_enterprise();

  if (count($enterprises) == 0) {
    return false;
  } else {
    foreach ($enterprises as $key => $value) {
      echo '<option value="' . $value->org_id . '"';
      echo '>' . $value->org . '</option>';
    }
  }
  ?>
</div>

<div id="legal_json">
<?php
$legal_org = org::find_all_legal();

if (count($legal_org) == 0) {
  return false;
} else {
  foreach ($legal_org as $key => $value) {
    echo '<option value="' . $value->org_id . '"';
    echo '>' . $value->org . '</option>';
  }
}
?>
</div>

<div id="enterprise_legal_json">
  <?php
  if (!empty($_GET['enterprise_org_id'])) {
    $enterprise_id = $_GET['enterprise_org_id'];
    $legal_org_of_enterprise = org::find_legal_orgs_of_enterprise($enterprise_id);

    if (count($legal_org) == 0) {
      return false;
    } else {
      foreach ($legal_org_of_enterprise as $key => $value) {
        echo '<option value="' . $value->org_id . '"';
        echo '>' . $value->org . '</option>';
      }
    }
  }
  ?>
</div>

<div id="business_json">
  <?php
  if(!empty($_GET['legal_org_id'])){
      $legal_id = $_GET['legal_org_id'];
  $business_org_of_legal = org::find_business_orgs_of_legal($legal_id);

  if (count($business_org_of_legal) == 0) {
    return false;
  } else {
    foreach ($business_org_of_legal as $key => $value) {
      echo '<option value="' . $value->org_id . '"';
      echo '>' . $value->org . '</option>';
    }
  }
  }

  ?>
</div>

<!--get all inventory org orgs -->
<div id="inventory_all_json">
   <?php
  $inventory_orgs = org::find_all_inventory_org();
//	echo '<pre>';
//	print_r($inventory_orgs);
//	echo '<pre>';
	if(!empty($inventory_orgs)){
	     foreach ($inventory_orgs as $key => $value) {
      echo '<option value="' . $value->org_id . '"';
      echo '>' . $value->org . '</option>';
    }
	}
  ?>
</div>


<!--get the org org from Inventory Id-->
<div id="inventoryId">
      <?php
  if(!empty($_GET['inventoryId'])){
      $inventory_id = $_GET['inventoryId'];
  $inventory_org = org::find_by_inventory_id($inventory_id);

  if (count($inventory_org) == 0) {
    return false;
  } else {
 echo '<input type="text" readonly id="org_org" org="org_org" value="'.
         $inventory_org->org. 
          '" maxlength="50" >';
    }
  }
  
  ?>
</div>

  <?php include_template('footer.inc') ?>