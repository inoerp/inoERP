<?php
include_once('business_org.inc');

var_dump(headers_list());
$start_time = $_SERVER["REQUEST_TIME_FLOAT"];
    echo "<br />micro time :" . microtime(true). "</br>";
    echo "<br />start time :" . $start_time . "</br>";
    echo "<br />Execution time :" . (microtime(true) - $start_time) . "</br>";
    
$org = new org_header;
$org->org_id = "";
$org->org_type = "";
$org->name = "";
$org->description = "";
$org->enterprise_id = "";
$org->business_id = "";
$org->business_id = "";
$org->organization_id = "";
$org->ef_id = "";
$org->business_id = "";
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
$query = "SHOW COLUMNS FROM business_org ";

//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<pre>';
  print_r($rows);
  echo '<pre>';
}

//$query1= "ALTER TABLE business_org DROP COLUMN name";
//$result1 = $db->query($query1);

$query = "SHOW COLUMNS FROM business_org ";

echo '<h2>New values </h2>' ;
//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<pre>';
  print_r($rows);
  echo '<pre>';
}
echo "<br />micro time :" . microtime(true). "</br>";
    echo "<br />start time :" . $start_time . "</br>";
    echo "<br />Execution time :" . (microtime(true) - $start_time) . "</br>";
    execution_time();
?>

<!--   end of structure-->

<?php include_template('footer.inc') ?>