<?php
include_once('legal_org.inc');

$org = new org_header;
$org->org_id = "";
$org->org_type = "";
$org->name = "";
$org->description = "";
$org->enterprise_id = "";
$org->legal_id = "";
$org->business_id = "";
$org->organization_id = "";
$org->ef_id = "";
$org->legal_id = "";
$org->status = "";
$org->rev_enabled = "";
$org->rev_number = "";
$org->created_by = "";
$org->creation_date = "";
$org->last_update_by = "";
$org->last_update_date = "";

?>
<?php 
global $db;
$query = "SHOW COLUMNS FROM legal_org ";

//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<pre>';
  print_r($rows);
  echo '<pre>';
}

//$query1= "ALTER TABLE legal_org DROP COLUMN description";
//$result1 = $db->query($query1);
//
//$query = "SHOW COLUMNS FROM legal_org ";
//
//echo '<h2>New values </h2>' ;
////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
//}
   
?>

<!--   end of structure-->

<?php include_template('footer.inc') ?>