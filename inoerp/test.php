<?php
 ini_set('display_errors', 1);
 error_reporting(E_ALL);
 set_time_limit(0);

 include_once("includes/basics/header_public.inc");
//pa(hr_element_entry_header::find_by_employeeId(4));
//pa(hr_element_entry_header::find_all_regular_lines(1));
//pa(hr_element_entry_header::find_all_basic_regular_lines(1));
////$db = new dbObject();
////$prl = new sys_profile_line();
////$ar_ti = new ar_transaction_interface();
////$param =  ['bu_org_id' => array('5') ];
////
////$ar_ti->prg_import_ar_transaction(serialize($param));
//  pa(get_dbColumns('sys_notification'));
//  pa($session);
//  pa($user);
 $db = new dbObject();
 $dbc = new dbc();

// $offset = 10;
 $date = new DateTime('2014-7-01');
 

// function next_monday($date_p) {
//  $date = new DateTime($date_p);
//  if ($date->format('D') == 'Mon') {
//   return $date->format('Y-m-d');
//  } else {
//   $date = new DateTime("next monday $date_p");
//   return $date->format('Y-m-d');
//  }
// }
 echo "<br>Next Monday 2014-7-01 "; echo next_monday('2014-7-01');
 echo "<br>Next Monday 2014-7-02 ";echo next_monday('2014-7-02');
  echo "<br>Next Monday 2014-7-03 "; echo next_monday('2014-7-03');
 echo "<br>Next Monday 2014-7-04 ";echo next_monday('2014-7-04');
  echo "<br>Next Monday 2014-7-05 ";echo next_monday('2014-7-05');
  echo "<br>Next Monday 2014-7-06 "; echo next_monday('2014-7-06');
 echo "<br>Next Monday 2014-7-07 ";echo next_monday('2014-7-07');
 echo "<br>Next Monday 2014-7-08 "; echo next_monday('2014-7-08');
 echo "<br>Next Monday 2014-7-09 ";echo next_monday('2014-7-09');

 

 

// echo "<h1>Next monday is '2014-7-01' </h1>".  next_monday('2014-7-01');
// echo "<h1>Next monday is '2014-7-02' </h1>".  next_monday('2014-7-02');
// echo "<h1>Next monday is '2014-7-03' </h1>".  next_monday('2014-7-03');
// echo "<h1>Next monday is '2014-7-04' </h1>".  next_monday('2014-7-04');
// echo "<h1>Next monday is '2014-7-05' </h1>".  next_monday('2014-7-05');
// echo "<h1>Next monday is '2014-7-06' </h1>".  next_monday('2014-7-06');
// echo "<h1>Next monday is '2014-7-07' </h1>".  next_monday('2014-7-07');
// echo "<h1>Next monday is '2014-7-08' </h1>".  next_monday('2014-7-08');
// echo "<h1>Next monday is '2014-7-09' </h1>".  next_monday('2014-7-09');
 
 
// pa($date);
// echo $date->format('Y-m-d');
// $date->add(new DateInterval('P'.$offset.'D'));
// pa($date);
// echo $date->format('Y-m-d');

// echo "<br>Next monday" . date('Y-m-d', strtotime("next monday", strtotime('2014-7-07')));

// pa(sd_so_line::find_by_orgId_ssd(6, '2014-7-01'));
// pa(view::find_all_tables());
//$sys_notification = new sys_notification();
//  pa($sys_notification->find_openNotification_toUserId('34'));
//pa(get_dbColumns('fp_forecast_line_date'));
//pa(get_dbColumns('po_quote_line'));
//pa(get_dbColumns('po_quote_detail'));
//  pa(get_dbColumns('po_rfq_line'));
//  pa(get_dbColumns('po_rfq_requirement'));
//  pa(get_dbColumns('hr_leave_entitlement_line'));
//  pa(get_dbColumns('hr_approval_limit_assignment'));
//  pa(get_dbColumns('hr_employee_termination'));
//  pa(get_dbColumns('hr_element_entry_line'));
//$inster_items_sql = " SELECT DISTINCT(item_id_m) FROM inv_abc_valuation_result ";
//$inster_items_sql .= " WHERE inv_abc_valuation_id = '1' ";
//$inster_items_result = $db->findBySql($inster_items_sql);
////function get_item_id_m($obj){
//// return $obj->item_id_m;
////}
//////
//$item_id_m = array_map( function($obj){
// return $obj->item_id_m;
//}, $inster_items_result);
//
////$item_id_m = array_map( 'get_item_id_m', $inster_items_result);
//
//pa($item_id_m);
//
//echo ("'".implode("','", $item_id_m)."'");
//pa(ar_customer_site::find_all_sitesOfCustomer(2));
//$item = new item();
//pa($item->findBy_item_id_m('10047'));
//$user_names = [];
//for($i=0 ; $i <=100000 ; $i++){
// array_push($user_names, 'user_no_'.$i);
//}
//
//$f= new inoform();
//echo $f->select_field_from_array('user_name', $user_names, '');
//
//pa($_SESSION);
//$prl = new sys_profile_line();
//echo "---------------------------------------------------------------------------------------------------------------------------";
//pa( $prl->find_default_profile('org_inv_name_default'));
//pa( $prl->find_default_profile('org_bu_name_default'));
//   if (empty($_SESSION['org_inv_name_defalut'])) {
//    pa( $prl->find_default_profile('org_inv_name_defalut'));
//   }
//   if (empty($_SESSION['org_bu_name_defalut'])) {
//    pa( $prl->find_default_profile('org_bu_name_defalut'));
//   }
//  
//foreach(sys_profile_header::find_all() as $obj){
//pa($prl->find_default_profile($obj->profile_name));
//}
//pa($prl->findAll_profile('org_inv_name_defalut'));
//pa($prl->findBy_name_context('gl_currency_conversion_type'));
//
//pa(get_dbColumns('coa'));
//pa(get_dbColumns('coa_combination'));
//pa(get_dbColumns('inv_interorg_transfer_line'));
//$var = 18;
//$arr = [6 , 12, 13];
//if (in_array($var, $arr) ) {
// echo "<br>1.  in 6 , 12, 13";
//}
//
//if ($var == 6 || $var ==  12 ||  $var ==  13) {
// echo "<br>2.  in 6 , 12, 13";
//}
//$onhand = new onhand();
//$onhand->item_id_m = 6;
//pa($onhand->findBy_itemIdm_location());
//
//$onhand->org_id = 6;
//pa($onhand->findBy_itemIdm_location());
//
//$onhand->subinventory_id = 2;
//pa($onhand->findBy_itemIdm_location());
//
//$onhand->locator_id = 5;
//pa($onhand->findBy_itemIdm_location());
//pa(get_dbColumns('mdm_bank_line'));
//pa(get_dbColumns('mdm_bank_account'));
//pa(get_dbColumns('sys_process_flow_line'));
//$path = new path();
//echo $path->findBy_moduleCode('ar');
//pa(coa_combination::find_coa_combination_by_coa_id('905') );
//pa(ar_transaction_line::find_by_parent_id('21'));
//
//pa($_SERVER);
//echo "directory is 1 ". dirname(__FILE__);
//echo "directory is 1 ". __DIR__;
//
//$count = 0;
//$dbc = new dbc();
//$db = new dbObject();
//
////pa(comment::find_all());
////pa($_SERVER);
//
//
?>
<link href="//<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />

<?php
//echo $chart_image1;
//
//$svgimage2 = new getsvgimage();
//$svgimage2->setProperty('_chart_type', 'clustered_column');
//$svgimage2->setProperty('_right_margin', 0);
//$svgimage2->setProperty('_chart_width', 600);
//$svgimage2->setProperty('_legend', $legend);
//$svgimage2->setProperty('_data', $data);
//$chart_image2 = $svgimage2->draw_chart();
//echo $chart_image2;
//
//pa($data);
//pa($result);
//
//$data2 = [
//		array('label' => 'standrad po', 'value' => array('300', '250', '1228', '340', '150', '128', '1300', '20', '1228')),
//		array('label' => 'blanket po', 'value' => array('23', '111', '345', '250', '1228', '340', '250', '1228', '340',)),
//		array('label' => 'planned po', 'value' => array('343', '78', '900', '23', '111', '345', '23', '111', '345')),
//];
//if($datetime1 > $datetime2 ){
// echo "<br> 1 is after 2 ";
//}else{
// echo "<br> 1 is before 2 ";
//}
//
//if($datetime3 > $datetime2 ){
// echo "<br> 3 is after 2 ";
//}else{
// echo "<br> 3 is before 2 ";
//}
//
//pa($datetime1);pa($datetime2);pa($datetime3);
//$list = array(
//		array('aaa', 'bbb', 'ccc', 'dddd'),
//		array('123', '456', '789'),
//		array('"aaa"', '"bbb"')
//);
//$llc = new fp_mrp_lowlevel_code();
////$llc->create_lowlevel_code(6);
//$all_items = $llc->findAll_orderByLevel(6);
//pa($all_items);
////
//$data = ['org_id' => array('6'), 'fp_mrp_header_id' => array('1'),];
//
//$mrpd = new fp_mrp_demand();
//$mrpd->prg_mrp_demand_calculator(serialize($data));
//$sql = "  ALTER TABLE fp_mrp_demand 
//ADD org_id int(12) NOT NULL after fp_mrp_demand_id ";
//////
////////////date
//pa(get_dbColumns('fp_mrp_demand'));
//$boh = new bom_header();
//$all_boms = $boh->findBy_orgId(6);
//$lowLevel_code = [];
//
//function search_item_inLowLevelCode($item_id, &$existing_level, $lowLevelCode_a) {
// foreach ($lowLevelCode_a as $level_key => $level_value_a) {
//	if (array_search($item_id, $level_value_a) !== false) {
//	 $existing_level = $level_key;
//	 return array_search($item_id, $level_value_a);
//	}
// }
// return false;
//}
//
//foreach ($all_boms as $bom) {
// $exploded_bom = $boh->BOM_Explosion($bom->item_id);
// pa($exploded_bom);
// if (empty($lowLevel_code)) {
//	$lowLevel_code = $exploded_bom;
// } else {
//	foreach ($exploded_bom as $new_level => $item_a) {
//	 foreach ($item_a as $key => $item_id) {
//		$existing_level = 0;
//		$verify_item_key = search_item_inLowLevelCode($item_id, $existing_level, $lowLevel_code);
//		if ($verify_item_key !== false) {
//		 if ($new_level > $existing_level) {
//			echo "<br>Item is $item_id - existing level $existing_level & new level $new_level & key : $verify_item_key";
//			unset($lowLevel_code[$existing_level][$verify_item_key]);
//			if (array_key_exists($new_level, $lowLevel_code)) {
//			 array_push($lowLevel_code[$new_level], $item_id);
//			} else {
//			 $lowLevel_code[$new_level] = array($item_id);
//			}
//		 }
//		} else {
//		 echo "<br>Item is $item_id - existing level $existing_level not found in existing array  : $verify_item_key ";
//		 if (array_key_exists($new_level, $lowLevel_code)) {
//			array_push($lowLevel_code[$new_level], $item_id);
//		 } else {
//			$lowLevel_code[$new_level] = array($item_id);
//		 }
//		}
//	 }
//	}
// }
// echo "<br>New low level Code";
// pa($lowLevel_code);
//}
//
//echo "<h2>Final Code</h2>";
//pa($lowLevel_code);

 execution_time();
////$dbc->ddlexecute($query1);
//$query1 = " ALTER TABLE sd_so_line
//add picked_quantity int(12) after line_quantity,
//add shipped_quantity int(12) after picked_quantity ";
//$dbc->ddlexecute($query1);
//
//pa(get_dbColumns('sd_so_line'));
//$query1 = " ALTER TABLE sd_so_line
// add shipping_org_id int(12) NOT NULL after line_number ,
// add line_status varchar(25) NOT NULL after line_price,
//add requested_date date after line_status,
//add promise_date date after requested_date,
//add schedule_ship_date date after promise_date,
//add actual_ship_date date after schedule_ship_date ";
//$dbc->ddlexecute($query1);
//
//pa(get_dbColumns('sd_so_line'));
//pa(get_dbColumns('fp_mds_line'));
//pa(get_dbColumns('item'))
//$query2 = " ALTER TABLE item CHANGE rev_number rounding_option varchar(25)   ";
//$dbc->ddlexecute($query2);
//pa(get_dbColumns('item'));
//
//
//$dbc->ddlexecute($query1);
//$bov = new bom_overhead_v();
//pa($bov->findAll());
////
////
?>

<?php
//$sql = "  CREATE TABLE `fp_minmax_demand`  (
// fp_minmax_demand_id int(12) NOT NULL  AUTO_INCREMENT,
//  plan_id int(12) NOT NULL ,
//item_id int(12) NOT NULL ,
//quantity DECIMAL(20,5),
//demand_item_id int(12),
//demand_type varchar(50),
//source varchar(50),
//created_by varchar(256),
//creation_date datetime,
//last_update_by varchar(256),
//last_update_date datetime,
//primary key (fp_minmax_demand_id)) ";
//$dbc->ddlexecute($sql);
////$prepare->execute();
//
//$sql = "
//CREATE OR REPLACE VIEW sd_so_all_v
//(
//sd_so_header_id,bu_org_id,so_type,so_number,ar_customer_id,ar_customer_site_id,
//sales_person,document_currency,header_amount,so_status, payment_term_id,
//customer_name,customer_number,customer_site_name,customer_site_number,
//payment_term,description,sd_so_line_id,line_type,line_number,item_id,
//item_description,line_description,
//line_quantity,picked_quantity, shipped_quantity,
//unit_price,line_price,line_status,requested_date,
//promise_date ,schedule_ship_date ,actual_ship_date,item_number,
//uom_id,item_status,org,created_by,creation_date,last_update_by,last_update_date
//)
//AS
// SELECT 
//sd_so_header.sd_so_header_id, sd_so_header.bu_org_id, sd_so_header.so_type, sd_so_header.so_number, sd_so_header.ar_customer_id, 
//sd_so_header.ar_customer_site_id, sd_so_header.sales_person, sd_so_header.document_currency, 
//sd_so_header.header_amount, sd_so_header.so_status,
//sd_so_header.payment_term_id,
//ar_customer.customer_name, ar_customer.customer_number,
//ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
//payment_term.payment_term, payment_term.description,
//sd_so_line.sd_so_line_id, sd_so_line.line_type, sd_so_line.line_number,	sd_so_line.item_id, 
//sd_so_line.item_description, sd_so_line.line_description, 
//sd_so_line.line_quantity, sd_so_line.picked_quantity, sd_so_line.shipped_quantity,
//sd_so_line.unit_price, sd_so_line.line_price, sd_so_line.line_status,
//sd_so_line.requested_date, sd_so_line.promise_date , sd_so_line.schedule_ship_date ,sd_so_line.actual_ship_date,
//item.item_number, item.uom_id, item.item_status,
//org.org,
//sd_so_line.created_by, sd_so_line.creation_date, sd_so_line.last_update_by, sd_so_line.last_update_date
//
//FROM sd_so_header 
//LEFT JOIN ar_customer ON sd_so_header.ar_customer_id = ar_customer.ar_customer_id
//LEFT JOIN ar_customer_site ON sd_so_header.ar_customer_site_id = ar_customer_site.ar_customer_site_id
//LEFT JOIN payment_term ON sd_so_header.payment_term_id = payment_term.payment_term_id
//LEFT JOIN sd_so_line ON sd_so_header.sd_so_header_id = sd_so_line.sd_so_header_id
//LEFT JOIN item ON sd_so_line.item_id = item.item_id
//LEFT JOIN org ON sd_so_line.shipping_org_id = org.org_id
//
//";
////pa($db->findBy_sql($sql));
//
////
//$dbc->ddlexecute($sql);
//pa(get_dbColumns('org_v'));
//pa(fp_minmax_suggestion_v::find_all());
//$result = $db->findBy_sql($sql);
//
//pa($result);
//$structure = option_header::find_by_name('COA01');
//echo '<br><br><br><br>strucrte is <pre>';
//
//$segments = option_line::find_by_option_id($structure->option_header_id);
//print_r($segments);
//
//if(!empty($_POST))    {
//echo '<pre>';
//    print_r($_POST);
//    echo '<pre>';
//}
?>

<?php
 global $dbc;
//$block_types = block::block_types();
//  echo '<pre>';
//  print_r($block_types);
//  echo '<pre>';
//$query = "SHOW COLUMNS FROM block ";
////
////$query="Select * from information_schema.tables where table_name='block'";
//
//}
?>

<option value="" ></option> 
</select> -->
<!--   end of structure-->
<label>Background Color</label>
<input type="color" name="bgcolor" id="bgcolor">
<label>Header Color</label>
<input type="color" name="header_color" id="header_color">
<input type="button" class="button" id="set_color" Value="Set Color">

<div id="graph">
 <canvas id="barchart_1" width="400" height="400"></canvas>
 <canvas id="barchart_2" width="400" height="400"></canvas>
 <canvas id="piechart_1" width="400" height="400"></canvas>
 <canvas id="piechart_2" width="400" height="400"></canvas>
 <canvas id="polarchart_1" width="400" height="400"></canvas>
 <canvas id="ploarchart_2" width="400" height="400"></canvas>

 <canvas id="small_can"></canvas>
 Graph Hereford<ul class="graph1">
  <li></li>
  <li></li>
  <li></li>
  <li></li>
 </ul>
</div>

<?php
//execution_time();
 execution_time();
 include_template('footer.inc')
?>
