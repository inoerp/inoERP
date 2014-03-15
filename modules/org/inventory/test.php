<?php
include_once('inventory_org.inc');

$org = new org_header;
$org->org_id = "";
$org->org_type = "";
$org->name = "";
$org->description = "";
$org->enterprise_id = "";
$org->inventory_id = "";
$org->inventory_id = "";
$org->organization_id = "";
$org->ef_id = "";
$org->inventory_id = "";
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
//$query = "SHOW COLUMNS FROM inventory_org ";
//
////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
//}

//$query1= "ALTER TABLE inventory_org 
//  ADD `serial_uniqueness` varchar(50) NOT NULL AFTER lot_starting_number,
//  ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
//  ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
//  ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";

//$query1= "ALTER TABLE inventory_org 
////  CHANGE `deffered_cogs_ac` deferred_cogs_ac  varchar(256)";
//
//
//$result1 = $db->query($query1);

$query = "SELECT * FROM inventory_org ";

echo '<h2>New values </h2>' ;
//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<pre>';
  print_r($rows);
  echo '<pre>';
}
execution_time(); 
?>

<!--   end of structure-->

<?php include_template('footer.inc') ?>