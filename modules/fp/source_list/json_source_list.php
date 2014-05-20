<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['source_list_line_type'])) && ($_GET['find_source_list_line_type'] == 1)) {
 $source_list_line_type = $_GET['source_list_line_type'];

 switch ($source_list_line_type) {
	case 'FORECAST_ENTRY' :
	 $class = 'fp_forecast_header';
	 break;

		case 'DEMAND_ENTRY' :
	 $class = 'fp_mds_header';
	 break;
	
	case 'default' :
	 $class = 'fp_forecast_header';
	 break;
 }

 $$class = new $class;
 $all_data = $$class->findAll_2columns();
  if (count($all_data) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($all_data);
 }
}
?>

