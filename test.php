<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
set_time_limit(0);


//$conn = oci_connect('appsread', 'fr33be', 'COHREP');
//if (!$conn) {
//    $e = oci_error();
//    trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
//}else{
// echo "<br>COnnected";
//}

include_once("includes/basics/header_public.inc");
//
//$count = 0;
//$dbc = new dbc();
//$db = new dbObject();
//
////pa(comment::find_all());
////pa($_SERVER);
//
//$content = new content();
//$content->content_type_id = 47;
//$content->category_id = 31;
//echo pa($content->findAll_parantContent_of_categoryId(31));
//
//$category = new category();
//pa($category->category_explosion_withPCRelation(1));

//$cont = new comment();
//pa($cont->comment_recent_comments_block());
//
//echo HOME_URL;
//echo "<br>HOME URL WODS".  rtrim(HOME_URL, '/');
//$sql = " ALTER TABLE content 
//				ADD show_in_fp_cb boolean after rev_number	";
//$dbc->ddlexecute($sql);
pa(get_dbColumns('po_header'));
//$bc = new block_cache();
//$bc_i = $bc->findAll();
//pa($bc_i);
//
//foreach ($bc_i as $bci ){
// $bc->session_id = $bci->session_id;
// $bc->delete_allBy_sessionId();
//}
//echo "--------------------------------------after-----------------------------------";
//pa($bc_i);
//
//$block = new block();
//pa($block->findAll_AvailableBlocks());
//
//pa(block::find_all());
////$sql = " ALTER TABLE user_role 
////				CHANGE role_id role_code varchar(25) NOT NULL ";
////$dbc->ddlexecute($sql);
//pa(get_dbColumns('block'));
//
//
//$pathx = new path();
//echo $pathx->path_allpaths_block();
//$path_i = $pathx->findAll_pathId();
//$path_parent_ids = $pathx->findAll_parentPathId();
//
//$allowed_path_ids_all = array_intersect($path_i, $_SESSION['allowed_path_ids']);
//$allowed_parent_path_ids = array_intersect($path_parent_ids, $_SESSION['allowed_path_ids']);
//$allowed_path_ids = array_diff($allowed_path_ids_all, $allowed_parent_path_ids);
//
//function indented_pathMenu($allowed_parent_path_ids, &$allowed_path_ids) {
// $path = new path();
// $level = 0;
// $allPaths = '<div class="menu"><ul class="block_menu">';
// foreach ($allowed_parent_path_ids as $path_id) {
//	$path->findBy_id($path_id);
//	$url = $path->fullPath($path->path_link);
//	$allPaths .= '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
//	$childs = $path->findAll_childOfPartent($path_id);
//	foreach ($childs as $child_paths) {
//	 $allPaths .= '<ul class="child_menu">';
//	 $key = array_search($child_paths->path_id, $allowed_path_ids);
//	 if ($key) {
//		$url_1 = $path->fullPath($child_paths->path_link);
//		$allPaths .= '<li class="expandable">' . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
//		$allPaths .= indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids);
//		$allPaths .= '</li>';
//		unset($allowed_path_ids[$key]);
//	 }
//	 $allPaths .= '</ul>';
//	}
//	$allPaths .= '</li>';
// }
// $allPaths .= '</ul></div>';
// if (!empty($allowed_path_ids)) {
//	$allPaths .= '<li class="parent_menu expandable">' . '<a href="' . HOME_URL . '">Others</a>';
//	foreach ($allowed_path_ids as $path_key => $path_id) {
//	 $child_paths= $path->findBy_id($path_id);
//	 $allPaths .= '<ul class="child_menu">';
//		$url_1 = $path->fullPath($child_paths->path_link);
//		$allPaths .= '<li class="expandable">' . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
//		$allPaths .= indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids);
//		$allPaths .= '</li>';
//	 $allPaths .= '</ul>';
//	}
//	$allPaths .= '</li>';
// }
// return $allPaths;
//}
//
//function indented_pathMenu_Child($path_id, &$allowed_path_ids) {
// $path = new path();
// $all_child = $path->findAll_childOfPartent($path_id);
// if (empty($all_child)) {
//	return;
// }
// foreach ($all_child as $child_paths) {
//	$allPaths = '<ul>';
//	$key = array_search($child_paths->path_id, $allowed_path_ids);
//	if ($key) {
//	 $url = $path->fullPath($child_paths->path_link);
//	 $allPaths .= '<li class="expandable">' . '<a href="' . $url . '">' . $child_paths->name . '</a>';
//	 $allPaths .= indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids);
//	 $allPaths .= '</li>';
//	 unset($allowed_path_ids[$key]);
//	}
//	$allPaths .= '</ul>';
// }
// return $allPaths;
//}
//
//echo "<h2>Path os</h2>";
//echo indented_pathMenu($allowed_parent_path_ids, $allowed_path_ids);

/*
 * 1. Find all the path_id
 */


//pa(scandir('modules/'));
//pa(scandir('modules'));
//pa($_SESSION);
//
//echo '-------------------------------------------------------------------------------------------------------';
//pa($session);
//echo "<br>Session id" . session_id();
//
//
//


//
//$Directory = new RecursiveDirectoryIterator('modules');
//$Iterator = new RecursiveIteratorIterator($Directory);
//$Regex = new RegexIterator($Iterator, '/^.+\.php$/i', RecursiveRegexIterator::GET_MATCH);
//pa($Regex);
//pa(get_declared_classes());
//$exploded_cat_i = exp_cat(1);
//$exploded_cat[1] = $exploded_cat_i;
//pa($exploded_cat);
//pa(category::find_all());
//	$cat = new category();
//	  pa($cat->findBy_id(21));
//	if(count($cat) == 0){
//	 echo "<br>1 count 0 ";
//	}else{
//	 echo "<br>1 count is ". count($cat);
//	}
//	
//  pa($cat->findBy_id(565));
//	if(count($cat) == 0){
//	 echo "<br>2 count 0 ";
//	}else{
//	 echo "<br>2 count is ". count($cat);
//	}
//
//$sql = " ALTER TABLE item
//				CHANGE ap_tax ip_tax_class varchar(25),
//				CHANGE sales_tax op_tax_class varchar(25)";
//////
//$dbc->ddlexecute($sql);
////$sql = " ALTER TABLE sd_so_line
////				add tax_amount decimal(20,5) after line_price,
////				add tax_code_id int(12) after tax_amount ";
////////
////$dbc->ddlexecute($sql);
//
//pa(get_dbColumns('item'));
//pa(get_dbColumns('sd_so_line'));
//pa(mdm_tax_code::find_all_inTax_by_inv_org_id(6));
//pa(mdm_tax_code::find_all_outTax_by_inv_org_id(6));
//pa(org::find_all_inventory());
//pa(mdm_tax_code::find_all());
//
//$conn = oci_connect('appsread', 'fr33be',
//'(DESCRIPTION=
//    (ADDRESS = (PROTOCOL = tcp)(HOST = cohrep.na.coherentinc.com)(PORT=9902))
//    (CONNECT_DATA=(SID=cohrep))
//  )');
//
//if (!$conn) {
//    $e = oci_error();
//    trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
//		echo "<br>Oracle connection failed!";
//}else{
// echo "<br>Oracle Connection SucessFull";
//}
//pa(get_dbColumns('sd_delivery_header'));
//pa(get_dbColumns('sd_delivery_line'));
//ra_conevrt_data_bar_column($db->findBySql($sql));
//function ra_conevrt_data_bar_column($data_a, $first_value_legend = true) {
// $legend_a = [];
// $label_a = [];
// $final_data_a = [];
// $count = 0;
// foreach ($data_a[0] as $key1 => $val1) {
//	if ($count == 0) {
//	 $legend_key_name = $key1;
//	}
//	if ($count == 1) {
//	 $label_key_name = $key1;
//	}
//	if ($count == 2) {
//	 $value_key_name = $key1;
//	}
//	$count++;
// }
// 
// echo "<br > legend_key_name: $legend_key_name , label_key_name : $label_key_name ,value_key_name : $value_key_name ";
// if ($first_value_legend) {
//	$checking_for_legend = 0;
//	$checking_for_label = 1;
// } else {
//	$checking_for_legend = 1;
//	$checking_for_label = 0;
// }
// foreach ($data_a as $data) {
//	$count = 0;
//	foreach ($data as $key => $val) {
//	 if ($count == $checking_for_legend) {
//		!in_array($val, $legend_a) ? array_push($legend_a, $val) : '';
//		break;
//	 }
//	 $count++;
//	}
// }
//
// foreach ($data_a as $data1) {
//	$count = 0;
//	foreach ($data1 as $key1 => $val1) {
//	 if ($count == $checking_for_label) {
//		!in_array($val1, $label_a) ? array_push($label_a, $val1) : '';
//		break;
//	 }
//	 $count++;
//	}
// }
// echo "<br>Legends are ";
// pa($legend_a);
// echo "<br>Labels are ";
// pa($label_a);
//
// foreach ($label_a as $label_key => $label_val) {
//	$data = [];
//	$data['label'] = $label_val;
//	$data['value'] = [];
//	foreach ($legend_a as $legend_key => $legend_val) {
//	 $not_found_value = true;
//	 foreach ($data_a as $this_data_a_key => $this_data_a) {
//		if (($this_data_a->$legend_key_name == $legend_val) && ($this_data_a->$label_key_name == $label_val)) {
//		 array_push($data['value'], $this_data_a->$value_key_name);
//		 $not_found_value = false;
//		 unset($data_a[$this_data_a_key]);
//		 break;
//		}
//	 }
//	 if($not_found_value){
//		array_push($data['value'], null);
//	 }
//	}
//	array_push($final_data_a, $data);
// }
// pa($final_data_a);
//}
//$oh = new onhand_v();
//pa($oh->ra_onhand_by_productLine());
//pa($oh->ra_onhand_by_subinventoryType());
//pa($oh->ra_onhand_by_productLine_subinventoryType());
//
//
//$pov = new po_all_v();
//$result = ($pov->ra_open_po_by_supplier());
//function ra_conevrt_data($data_a, $label, &$legend_a) {
// $ra_data_a = [];
// $legend_count = 0;
// foreach ($data_a as $data) {
//	$data_a = (array) $data;
//	$ra_data_element = [];
//	$ra_data_element['label'] = $data->$label;
//	$ra_data_element['value'] = [];
//	unset($data_a[$label]);
//	foreach ($data_a as $key => $val) {
//	 array_push($ra_data_element['value'], $val);
//	 if($legend_count == 0){
//		array_push($legend_a, $key);
//	 }
//	}
//	array_push($ra_data_a, $ra_data_element);
//	$legend_count++;
// }
// return $ra_data_a;
//}
//$legend = [];
//$data = ra_conevrt_data($result, 'supplier_name', $legend);
//
////$svgimage1 = new getsvgimage();
////$svgimage1->setProperty('_chart_type', 'clustered_bar');
////$svgimage1->setProperty('_legend', $legend);
////$svgimage1->setProperty('_data', $data);
////$chart_image1 = $svgimage1->draw_chart();
//
?>
<link href="//<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />

//<?php
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

