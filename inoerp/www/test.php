<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
//set_time_limit(0);
include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc');
?>

<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />

<svg class="chart" width="1200" height="400"> 

<?php 


//$img = '';
//$x_cordinate= 100;
//$bar_height= 100;
//$chart_height = 400;
//for ($i=5; $i<=100; $i = $i + 1	){
// $x_cordinate = $x_cordinate + 1;
// $bar_height = $bar_height + 1;
// $y_cordinate = $chart_height - $bar_height;
// $img .= '<g transform="translate('.$x_cordinate.', '.$y_cordinate.')">';
// $img .= '<rect width=".1" height="'.$bar_height.'" label="Inoideas Techonology &nbsp; 1120347.00 " class="chart_value data_class_3 Inoideas Techonology ">
//</rect>';
// $img .= '</g>';
//}
//
//for ($i=200; $i>=5; $i = $i - 1	){
// $x_cordinate = $x_cordinate + 1;
// $bar_height = $bar_height - 1;
// $y_cordinate = $chart_height - $bar_height;
// $img .= '<g transform="translate('.$x_cordinate.', '.$y_cordinate.')">';
// $img .= '<rect width=".1" height="'.$bar_height.'" label="Inoideas Techonology &nbsp; 1120347.00 " class="chart_value data_class_3 Inoideas Techonology ">
//</rect>';
// $img .= '</g>';
//}
//echo $img;
?>

</svg>

<?php

pa(get_dbColumns('ent_sys_webpage_header'));
pa(get_dbColumns('ent_sys_webpage_line'));
//pa(get_dbColumns('mdm_discount_line'));




//pa($_SESSION);
//$_SESSION['csrf_token'] = 'XYZ';
//
//$session->session_update();
//
//pa($_SESSION);

//foreach (PDO::getAvailableDrivers() as $driver)
// echo $driver, '<br>';

//$conn = oci_connect('inoerp', 'Welcome1', 'localhost:1521/orcl.asia.coherentinc.com');
//
//$stid = oci_parse($conn, 'SELECT * from all_tables');
//oci_execute($stid);
//
//pa(oci_fetch_array($stid));
//
//while (($row = oci_fetch_array($stid, OCI_ASSOC + OCI_RETURN_NULLS)) != false) {
// pa($row);
// echo "<tr>\n";
// foreach ($row as $item) {
//  pa($item);
// }
// echo "</tr>\n";
//}


//$sh = $dbc->connection->prepare('SELECT org_seq.NEXTVAL AS org_seq_id FROM DUAL');
//$sh->execute();
//$nextInsertId = $sh->fetchColumn(0);
//
//pa($nextInsertId);

//$inv2 = new inventory();
//pa($inv2->findRelatedDetail_ByOrgId('6'))

//pa($_COOKIE);
//echo ' session id() '. session_id();
//echo ' session_name() '. session_name();
//pa($_SESSION);
//$sql = "SELECT * from locator  ";
//pa(locator::find_by_sql($sql));
//$stmt = $dbh->prepare($sql);
//$stmt->execute();
//pa($stmt->fetchAll(PDO::FETCH_CLASS));

//$S = 'we test coders. Give us a try?';
//$T = 'Forget  CVs..Save time . x x';
//function solution($s){
// $max_w = 0;
// $s_split = preg_split('/[.|?|!]/', $s);
// foreach($s_split as $k => $v ){
//  $v_split = explode(' ', trim($v));
//  $arr_l = count(array_filter($v_split));
//  if($arr_l > $max_w ){
//   $max_w = $arr_l;
//  }
// }
// return $max_w;
//}
//
//

pa(get_dbColumns('ar_receipt_all_v'));
//pa(get_dbColumns('cm_statement_line'));
//pa(get_dbColumns('lms_admission'));

//pa(get_dbColumns('lms_exam_line'));
//pa(get_dbColumns('lms_fee_struct_line'));
//pa(get_dbColumns('lms_fee_struct_line'));
//pa(get_dbColumns('lms_group_line'));

//pa(get_dbColumns('gl_budget_ac_header'));
//pa(get_dbColumns('gl_budget_ac_line'));
//pa(get_dbColumns('gl_budget'));

//pa(get_dbColumns('extn_menu_line'));
//for ($i=0 ; $i<10; $i++){
// echo '<h1>For org id '. $i.' </h1>';
// pa(org::find_financial_details_from_orgId($i));
//}
//phpinfo();
//$sql = "  SELECT *
//FROM 
//(
//SELECT onhand_v.item_number, onhand_v.item_description,onhand_v.product_line,
//onhand_v.org_name, onhand_v.standard_cost, onhand_v.item_id_m, onhand_v.org_id, onhand_v.onhand,
//item.item_id, item.org_id, item.item_type,item.item_id_m
//
//FROM 
//onhand_v,
//item
//
//WHERE onhand_v.item_id_m = item.item_id_m
//AND item.org_id = onhand_v.org_id
//    ) AS temp_tbl
//    
//     ";
//
//pa($db->findBy_sql($sql));
//$all_t = extn_view::find_all_tables_and_views();
//
//$i = 1;
//foreach ($all_t as $tbl) {
// echo '<td>' . $tbl->table_name . '</td><br>';
// $cont_i = new content();
// $cont_i->subject = $tbl->table_name;
// $cont_i->published_cb = 1;
// $cont_i->content_type_id = '50';
// $cont_i->save();
// 
// $all_cols = get_dbColumns($tbl->table_name);
// $all_cols_a = explode('_', $tbl->table_name);
// $all_cols_stmt = '';
// foreach ($all_cols as $col_name) {
//  $all_cols_stmt .= "'" . $col_name . "',\n";
// }
//
// $_POST['content'][0] = 'Contains all information of ' . str_replace('_', ' ', $tbl->table_name);
// $_POST['elements'][0] = $all_cols_stmt ;
// $_POST['module'][0] = $all_cols_a[0];
// 
// $cont_i->_after_save();
//$i++;
//}
//
//echo '<br><br> No of contents created ' . $i;
//
//pa($all_t);
//echo '<table>';
//foreach ($all_t as $tbl) {
// echo '<tr>';
// echo '<td>' . $tbl->table_name . '</td>';
// echo '<td>' . str_replace('_', ' ', $tbl->table_name) . '</td>';
// $all_cols = get_dbColumns($tbl->table_name);
// $all_cols_stmt = '';
// foreach ($all_cols as $col_name) {
//  $all_cols_stmt .= "'" . $col_name . "', <br>";
// }
// echo '<td>' . $all_cols_stmt . '</td>';
// echo '</tr>';
//}
//
//echo '</table>';
//$bc = new ino_barcode();
//$bc->setProperty('_text', '12121');
//$bc->draw_barcode();
//
//$all_tables = extn_view::find_all_tables();
////pa($all_tables);
//foreach($all_tables as $t){
// $cols = get_dbColumns($t->table_name);
// foreach($cols as $k => $c){
//  echo str_replace('_', ' ' , $c).'<br>';
// }
//}
//function get_url_contents($url){
//        $crl = curl_init();
//        $timeout = 5;
//        curl_setopt ($crl, CURLOPT_URL,$url);
//        curl_setopt ($crl, CURLOPT_RETURNTRANSFER, 1);
//        curl_setopt ($crl, CURLOPT_CONNECTTIMEOUT, $timeout);
//        $ret = curl_exec($crl);
//        curl_close($crl);
//        return $ret;
//}
//pa(prj_project_header::find_by_id_gl('5', '>='));
//pa(prj_expenditure_line::find_totalExpenditure_by_projectHeaderId(5));
//pa(prj_budget_line::find_budget_by_ProjectHeaderIdBudgetType(5 ,'APPR_COST'));
//echo "<br>The content is";
//echo get_url_contents('http://inoideas.org');
//pa(prj_expenditure_line::find_distinctProject_byStatus());
//pa($_SESSION);
//unset($_SESSION);
//pa($_SESSION);
// $day = new DateTime("monday this week");
// 
// for($i=1; $i <= 7; $i++){
//  $day_i =  'day'. $i;
//  $$day_i = $day->format('M - d');
//  $day->add(new DateInterval('P1D'));
//  echo "<br>day " . $$day_i;
// }
// 
// echo '<br>' . $day1;
// echo '<br>' . $day3;
// echo '<br>' . $day5;
//   // create curl resource 
//        $ch = curl_init(); 
//
//        // set url 
//        curl_setopt($ch, CURLOPT_URL, "inoideas.org"); 
//
//        //return the transfer as a string 
//        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
//
//        // $output contains the output string 
//        $output = curl_exec($ch); 
//        
//        echo htmlspecialchars($output);
//
//        // close curl resource to free up system resources 
//        curl_close($ch);  
//echo gettext("HELLO_WORLD");
//echo '<br>' .gettext('Type');
//pa($_SESSION);
//
//exec("C:\Users\dasn\Documents\Visual Studio 2013\Projects\keyBoard\Debug\keyBoard.exe ", $output);
//pa($output);
//pa($_SESSION);
//$first_monday = strtoupper(date("d-M-Y",strtotime('monday this week')));
//$date = new DateTime($first_monday);
//for($day=0 ; $day <= 11 ; $day++){
// echo '<br>'. strtoupper($date->format("d-M-y"));
// $date->add(new DateInterval('P1D'));
// 
//}
//
//pa($_SESSION);
//$dir_path = 'modules';
// $dir = new RecursiveDirectoryIterator(HOME_DIR . DS . $dir_path);
// $ite = new RecursiveIteratorIterator($dir);
// $files = new RegexIterator($ite, '([^\s]+(\.(?i)(inc))$)', RegexIterator::GET_MATCH);
// $class_file_name = 'class_' . 'bom_cost_type' . '.inc';
// foreach ($files as $file) {
//  if (substr($file[0], -1) != '.') {
//   if (strpos($file[0], $class_file_name)) {
//    echo $file[0];
//    require $file[0];
//   }
//  }
// }
//pa($dbc);
//$all_tables = extn_view::find_all_tables_and_views();
//foreach($all_tables as $K => $v ){
// echo '<br>' . $v->table_name;
//}
//$new_comb = hr_employee::find_by_fieldVal(['job_id' => '1', 'position_id' => '1']);
//pa($new_comb);
//$str = "'''AB12128      \\\////d'''dsfs12~~~";
//echo " <br> The number in $str is " . filter_var($str, FILTER_SANITIZE_NUMBER_INT);
//pa(get_dbColumns('extn_emessage_line'));
//pa(get_dbColumns('pm_batch_operation_detail'));
//pa(get_dbColumns('pm_batch_line'));
//pa(get_dbColumns('pm_batch_ingredient'));
//pa(get_dbColumns('pm_batch_byproduct'));
//pa(get_dbColumns('prj_category_value'));
//$day=new DateTime('last day of January'); 
//echo $day->format('M jS');
//pa(get_dbColumns('hd_svo_line'));
//$i = 10; $j = 12;
//echo $i ;
//$dbc = new dbc();
//$db = new dbObject();
//echo "<h1>category::contentCount_by_categoryId_contentType</h1>";
//for($i=31; $i<38; $i++){
// echo "<br>catergory id : $i : "; echo(category::contentCount_by_categoryId_contentType($i, 'documentation'));
//}
//echo "<h1>category::contentCount_by_categoryId_contentType</h1>";
//for($i=31; $i<38; $i++){
// echo "<br>catergory id : $i : "; echo(content::content_count_by_categoryId_contentType($i));
//}
//if (!empty($_GET['dir_path'])) {
// $dir_path = $_GET['dir_path'];
//} else {
// $dir_path = 'modules';
//}
//$engine_object = [];
//if (!(empty($search_result))) {
// foreach ($search_result as $object) {
//  array_push($engine_object, $object);
// }
// if (!empty($pagination)) {
//  $pagination->setProperty('_path', 'form');
//  $pagination_statement = $pagination->show_pagination();
// }
//} else if (!(empty($$class))) {
// array_push($engine_object, $$class);
//} else {
// $engine = new engine();
// array_push($engine_object, $engine);
//}
//$all_data = [];
//$file_paths = [];
//$no_of_files = 0;
//$dir = new RecursiveDirectoryIterator(HOME_DIR.DS.$dir_path);
//$ite = new RecursiveIteratorIterator($dir);
//$files = new RegexIterator($ite, '([^\s]+(\.(?i)(inc))$)', RegexIterator::GET_MATCH);
//$fileList = array();
////$module_name_a = [];
//foreach ($files as $file) {
// $file_paths[] = $file[0];
// $cm = get_class_name_from_path($file[0]);
// $class = $cm['class_name'];
// $module_name = $cm['module_name'];
//
// if (property_exists($class, 'system_info') && (!empty($class::$system_info))) {
//  $sys_info_a = $class::$system_info;
//  $sys_info_a['obj_class_name'] = $class;
//  $sys_info_a['module_name'] = $module_name;
//  $sys_info_a['path'] = $file[0];
//    array_push($all_data, $sys_info_a);
// }
//
//}
//
//
//foreach($all_data as $k => $data){
// echo '<br>';
// echo $k;
// foreach($data as $x => $v){
//  if(in_array($x, ['name','number','description','weight','obj_class_name', 'path'])){
//   echo "|$v";
//  }
// }
//}
//pa($_SERVER);
//$all_tables = $db->find_all_tables_and_views();
//
//$con = new content();
//pa($con->findAll_contents());
//   $date_i = new DateTime();
//   $date_i->add(new DateInterval('P365D'));
//   $cut_off_date = $date_i->format('Y-m-d');
//   echo $cut_off_date . '<br>';
//   
//          $wo_date_obj = new DateTime('2019-03-23');
//       $cut_off_date_obj = new DateTime('2018-08-23');
//       if($wo_date_obj > $cut_off_date_obj){
//        echo $wo_date_obj->format('Y-m-d') .' > ' . $cut_off_date_obj->format('Y-m-d');
//       }else{
//        echo $wo_date_obj->format('Y-m-d') .' < ' . $cut_off_date_obj->format('Y-m-d');
//       }
//pa(extn_rating_values::find_by_reference('ec_product', 1));
//pa($_SESSION);
//echo get_user_ip();
//$paid_orders = ec_paid_order::find_all();
//
//foreach ($paid_orders as $order) {
// foreach ($order as $k => $v) {
//
//  if (in_array($k, ['sp_return_data', 'confirm_order_details'])) {
//   echo "<br>$k : ";pa(json_decode($v));
//  } else {
//   echo "<br>$k : $v";
//  }
// }
//}
//
//$pat = new path();
//        echo ($pat->path_allpaths_block(array('divClass' => 'tree_view')));
//pa($_SESSION);
//$email_a = explode(',', $email);
//pa($email_a);
//
//   $im = new inomail();
//   $im->From = $si->email;
//   $im->FromName =  $si->site_name;
//   $im->addAddress('ndas.oracle@gmail.com', 'Nishit Das');
//   $im->addReplyTo($si->email, 'User Registration');
//   $im->isHTML(true);
//   
//   $im->Subject =  'Hello';
//   $im->Body = 'TEST MAIL';
//   $im->ino_sendMail();
// 
//pa(engine::find_by_className('adm_task_type'));
//pa(get_dbColumns('hd_service_activity_line'));
//$column_array = [];
//
//foreach($all_tables as $tbl){
// $columns = $db->get_dbColumns($tbl->table_name);
// $column_array = array_merge($column_array, $columns);
//}
//
//$column_array_uniq = array_unique($column_array);
//foreach($column_array_uniq as $key => $val ){
// echo '<br>'. ucwords(str_replace('_', ' ', $val)) ;
//}
//   $existing_user = new user();
//   $existing_user->findBy_id('34');
//pa($existing_user);
//$ctp = new convertToProd();
//$exclude_tables_limited_mode = $ctp->exclude_tables_limited_mode;
//
//$all_tables = $db->find_all_tables();
//$all_tables_ar = ino_arrayObj_to_array($all_tables, 'TABLE_NAME');
//
//$diff = array_diff($all_tables_ar, $exclude_tables_limited_mode);
//echo "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";echo count($diff);
//pa($diff);
//echo "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";echo count($exclude_tables_limited_mode);
//pa($exclude_tables_limited_mode);
//echo "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";echo count($all_tables_ar);
//pa($all_tables_ar);
//pa($views_in_db2);
//echo "<br> Table in DB 1 ";
//pa($tables_in_db1_ar);
//echo "<br> Table in DB 2 ";
//pa($tables_in_db2_ar);
//
//echo "<br> New Table";
//$new_tables = array_diff($tables_in_db1_ar, $tables_in_db2_ar);
////pa($new_tables);
//
//echo "<br> Tables to be Dropped";
//$delete_tables = array_diff($tables_in_db2_ar, $tables_in_db1_ar);
//pa($delete_tables);
//
////create table if doesnt exists . Sync table structure if exists
//foreach ($tables_in_db1_ar as $k => $table_name) {
// if (in_array($table_name, $tables_in_db2_ar)) {
//  $comp_result = ino_isSame_tablesInTwoDataBases($table_name);
//  echo "<br>table  $table_name  : ".$comp_result;
//  if ($comp_result == 'DIFFERENT') {
//   echo "<br>Updating table  $table_name  : ";
//   ino_update_table_in_oldDB($table_name);
//  }
// } else {
//  echo "<br>$table_name does not exist in old DB. Creating table Table";
//  ino_create_table_in_oldDB($table_name);
// }
//}
//
//if (!empty($delete_tables)) {
// foreach ($delete_tables as $k => $tbl_name_drop) {
//  echo "<br>$tbl_name_drop required. Tryig to drp the table";
//  ino_drop_table_in_oldDB($tbl_name_drop);
// }
//}
//
////$columns  = $db->get_dbColumns('ap_payment_header');
////pa($columns);
////
////$columns2  = $db2->get_dbColumns('ap_payment_header',$dbc2);
////pa($columns2);
////
////$inst_str = implode(',', $columns );
////echo $inst_str;
////pa(ino_comparetables_inTwoDataBases('ap_payment_header'));
//
//
//function ino_update_table_in_oldDB($tbl_name) {
// global $db;
// $dbc2 = new dbc2();
// $table_name = ".$tbl_name";
// $new_db_table = DB_NAME . $table_name;
// $old_db_table_temp = DB_NAME2 . $table_name . '_temp';
// $old_db_table = DB_NAME2 . $table_name;
// $sql = " CREATE TABLE $old_db_table_temp LIKE $new_db_table ";
// $dbc2->ddlexecute($sql);
// $dbc2->confirm();
//
// $columns  = $db->get_dbColumns($tbl_name);
// $inst_str = implode(',', $columns );
// $sql_inst = " INSERT INTO $old_db_table_temp ($inst_str) "
//  . " SELECT $inst_str FROM $old_db_table ";
// $dbc2->ddlexecute($sql_inst);
// $dbc2->confirm();
//
// $sql3 = " DROP TABLE $old_db_table ";
// $dbc2->ddlexecute($sql3);
// $dbc2->confirm();
//
// $sql4 = " RENAME TABLE $old_db_table_temp TO $old_db_table ";
// $dbc2->ddlexecute($sql4);
// $dbc2->confirm();
//
// echo "<div class='alert alert-sucess'>$old_db_table is sucessfully updated</div>";
//}
//
//function ino_isSame_tablesInTwoDataBases($tbl1) {
// $db = new dbObject();
// $sql = " SELECT IF(COUNT(1)>0,'DIFFERENT','SAME') comp_result FROM
//(
//    SELECT
//        column_name,ordinal_position,
//        data_type,column_type,COUNT(1) rowcount
//    FROM information_schema.columns
//    WHERE
//    (
//        (table_schema='" . DB_NAME . "' AND table_name='{$tbl1}') OR
//        (table_schema='" . DB_NAME2 . "' AND table_name='{$tbl1}')
//    )
//    AND table_name = '{$tbl1}'
//    GROUP BY
//        column_name,ordinal_position,
//        data_type,column_type
//    HAVING COUNT(1)=1
//) A;
//";
// $result = $db->find_by_sql($sql);
// return !empty($result) ? $result[0]->comp_result : false;
//}
//
//function ino_comparetables_inTwoDataBases($tbl1) {
// $db = new dbObject();
// $sql = " SELECT column_name,ordinal_position,data_type,column_type FROM
//(
//    SELECT
//        column_name,ordinal_position,
//        data_type,column_type,COUNT(1) rowcount
//    FROM information_schema.columns
//    WHERE
//    (
//        (table_schema='" . DB_NAME . "' AND table_name='{$tbl1}') OR
//        (table_schema='" . DB_NAME2 . "' AND table_name='{$tbl1}')
//    )
//    AND table_name = '{$tbl1}'
//    GROUP BY
//        column_name,ordinal_position,
//        data_type,column_type
//    HAVING COUNT(1)=1
//) A;
//";
// $result = $db->find_by_sql($sql);
// return !empty($result) ? $result : false;
//}
//
//function ino_create_table_in_oldDB($tbl_name) {
// $dbc2 = new dbc2();
// $table_name = ".$tbl_name";
// $new_db_table = DB_NAME . $table_name;
// $old_db_table = DB_NAME2 . $table_name;
// $sql = " CREATE TABLE $old_db_table LIKE $new_db_table ";
// $dbc2->ddlexecute($sql);
// $dbc2->confirm();
// echo "<div class='alert alert-sucess'>$old_db_table is sucessfully created</div>";
//}
//
//function ino_drop_table_in_oldDB($tbl_name) {
// $dbc2 = new dbc2();
// $table_name = ".$tbl_name";
// $drop_db_table = DB_NAME2 . $table_name;
// $sql = " DROP TABLE $drop_db_table ";
// echo $sql;
// $dbc2->ddlexecute($sql);
// $dbc2->confirm();
// echo "<div class='alert alert-sucess'>$drop_db_table is sucessfully dropped</div>";
//}
//Drop table if doesnt exists
//
//$config_file_path = HOME_DIR.'/tparty/extensions/social_login/hybridauth/config.php';
// 
//require_once( "/tparty/extensions/social_login/hybridauth/Hybrid/Auth.php" );
// 
//
//
//try{
//  	// create an instance for Hybridauth with the configuration file path as parameter
//  	$hybridauth = new Hybrid_Auth( $config_file_path );
//  
//  	// try to authenticate the user with twitter, 
//  	// user will be redirected to Twitter for authentication, 
//  	// if he already did, then Hybridauth will ignore this step and return an instance of the adapter
//  	$google_login = $hybridauth->authenticate( "Google" );  
// 
//  	// get the user profile 
//  	$user_profile = $google_login->getUserProfile();
//      $_SESSION['user_profile'] = ['authorization' => 'Googlr', 'profile_data' => $user_profile];
//  	echo "Ohai there! U are connected with: <b>{$user_profile->id}</b><br />"; 
//  	echo "As: <b>{$user_profile->displayName}</b><br />"; 
//  	echo "And your provider user identifier is: <b>{$user_profile->identifier}</b><br />"; 
// 
//  	// debug the user profile
//  	print_r( $user_profile );
// 
//  	// exp of using the twitter social api: Returns settings for the authenticating user.
//  	$account_settings = $user_profile->api()->get( 'account/settings.json' );
// 
//  	// print recived settings 
//  	echo "Your account settings on Twitter: " . print_r( $account_settings, true );
// 
//  	// disconnect the user ONLY form twitter
//  	// this will not disconnect the user from others providers if any used nor from your application
////  	echo "Logging out.."; 
////  	$twitter->logout(); 
//  }
//  catch( Exception $e ){  
//  	// Display the recived error, 
//  	// to know more please refer to Exceptions handling section on the userguide
//  	switch( $e->getCode() ){ 
//  	  case 0 : echo "Unspecified error."; break;
//  	  case 1 : echo "Hybriauth configuration error."; break;
//  	  case 2 : echo "Provider not properly configured."; break;
//  	  case 3 : echo "Unknown or disabled provider."; break;
//  	  case 4 : echo "Missing provider application credentials."; break;
//  	  case 5 : echo "Authentification failed. " 
//  	              . "The user has canceled the authentication or the provider refused the connection."; 
//  	           break;
//  	  case 6 : echo "User profile request failed. Most likely the user is not connected "
//  	              . "to the provider and he should authenticate again."; 
//  	           $twitter->logout(); 
//  	           break;
//  	  case 7 : echo "User not connected to the provider."; 
//  	           $twitter->logout(); 
//  	           break;
//  	  case 8 : echo "Provider does not support this feature."; break;
//  	} 
//  }
//$data = 'MI_PUR99/3.78/OFF30/1.134';
//
//            $bc = new ino_barcode();
//            $bc->setProperty('_text', $data);
//            $bc->draw_barcode();
//            unset($bc);
//            echo '<br><br><br><br>';
//            $data = 'MI_SA/3.78/off10';
//                        $bc = new ino_barcode();
//            $bc->setProperty('_text', $data);
//            $bc->draw_barcode();
//            unset($bc);
//            
//            $all_stores = sd_store::find_by_orgId('6');
//            pa($all_stores);
////pa(get_dbColumns('locator'));
//pa(get_dbColumns('bom_config_header'));
//$sql = " SELECT * from path where parent_id = '59' ";
//$result1 = dbObject::find_by_sql($sql);
//$all_path = [];
//$all_path = $result1;
//foreach ($result1 as $obj) {
// $sql2 = " SELECT * from path where parent_id = '{$obj->path_id}' ";
// $result2 = dbObject::find_by_sql($sql2);
// $all_path = array_merge($all_path, $result2);
// if (!empty($result2)) {
//  foreach ($result2 as $obj2) {
//   $sql3 = " SELECT * from path where parent_id = '{$obj2->path_id}' ";
//   $result3 = dbObject::find_by_sql($sql3);
//   $all_path = array_merge($all_path, $result3);
//   if (!empty($result3)) {
//    foreach ($result3 as $obj3) {
//     $sql4 = " SELECT * from path where parent_id = '{$obj3->path_id}' ";
//     $result4 = dbObject::find_by_sql($sql4);
//     $all_path = array_merge($all_path, $result4);
//    }
//   }
//  }
// }
//}
//
////pa($all_path);
//
//foreach($all_path as $path){
// $sql = " UPDATE PATH
//SET  module_code  = 'adm'
//WHERE module_code  = 'sys' AND path_id = '{$path->path_id}' " ;
//$dbc->ddlexecute($sql);         
//}
////
//$dbc->confirm();
//define('PROJECT_DIR', realpath('./'));
//define('LOCALE_DIR', 'C:\smartview\www\inoerp\locale');
//define('DEFAULT_LOCALE', 'hi_IN');
//
//require_once('locale/gettext.inc');
//
//$supported_locales = array('en_US', 'hi_IN', 'de_CH', 'es_ES');
//$encoding = 'UTF-8';
//
//$locale = (isset($_GET['lang'])) ? $_GET['lang'] : DEFAULT_LOCALE;
//
////var_dump($locale);die();
//// gettext setup
//T_setlocale(LC_MESSAGES, $locale);
//// Set the text domain as 'messages'
//$domain = 'messages';
//bindtextdomain($domain, LOCALE_DIR);
//// bind_textdomain_codeset is supported only in PHP 4.2.0+
//if (function_exists('bind_textdomain_codeset'))
// bind_textdomain_codeset($domain, $encoding);
//textdomain($domain);
//echo gettext("HELLO_WORLD");
//pa(hr_element_entry_header::find_all_regular_lines(1));
//pa(hr_element_entry_header::find_all_basic_regular_lines(1));
////$db = new dbObject();
////$prl = new sys_profile_line();
////$ar_ti = new ar_transaction_interface();
////$param =  ['bu_org_id' => array('5') ];
////
////$ar_ti->prg_import_ar_transaction(serialize($param));
//  pa($session);
//  pa($user);
//$glb = new gl_balance_v();
//
//$params =[ 
// 'period_id' => array(12)
//];
//
//$ret_a = $glb->prg_balance_sheet($params);
//
//pa($ret_a);
// pa(sys_process_flow_action::find_by_parent_id('11'));'
// pa(cc_co_header::find_by_status('REVIew'))
//echo inv_lot_number::show_serialLot_entryForm();
//pa(hr_payroll_schedule::find_latest_open_schedule_by_headerId(3));
//pa(hr_payroll_process::find_payroll_available_for_cancelAndConfirmation());
//$schdule_date = new DateTime('2014-01-01');
//echo '<br>First Date '. $schdule_date->format('Y-m-01');
//echo '<br>Last Date' . $schdule_date->format('Y-m-t');
//echo '<br>Month Year' . $schdule_date->format('M-y');
//$schdule_date->add(new DateInterval('P1M'));
//echo '<br>First Date '. $schdule_date->format('Y-m-01');
//echo '<br>Last Date' . $schdule_date->format('Y-m-t');
//echo '<br>Month Year' . $schdule_date->format('M-y');
//
//pa($schdule_date);
//$date_end = new DateTime('28-DEC-2016');
//$no_days_in_period = 30;
//
//pa($date_start);
//pa($date_end);
//$total_no_days = $date_end->diff($date_start, 1)->days;
//$no_of_periods = $total_no_days / $no_days_in_period;
////pa($date_end->diff($date_start, 1));
//$start_date = new DateTime('01-JAN-2012');
//pa($start_date);
//    $current_date = new DateTime();
//  pa($current_date->diff($start_date, 1));
//
//
//    $start_date = new DateTime('01-JAN-2013');
//     $current_date = new DateTime();
//  pa($start_date);
//  $current_date = new DateTime();
//    pa($current_date->diff($start_date, 1));
//  
//      $start_date = new DateTime('01-AUG-2013');
//     $current_date = new DateTime();
//  pa($start_date);
//  $current_date = new DateTime();
//  pa($current_date->diff($start_date, 1));
//
//
//while ($no_of_periods > 0) {
// $date_intvl = 'P'.$no_days_in_period.'D';
// echo "<br> date_intvl is $date_intvl  & satrt date " . $date_start->format('Y-m-d');
// 
// $date_start->add(new DateInterval($date_intvl));
// $no_of_periods--;
//}
//pa(get_dbColumns('pos_terminal'));
//pa(coa_combination::find_description_from_ccId('1'));
//pa(coa::find_all_accounts_from_coaId(1,'', 'A'));
//$coa = new coa();
//$coa->coa_id = 1;
//$coa->only_parent = true;
//$coa->account_qualifier = 'A';
//pa($coa->findAll_accounts_from_coaId());
//
//$coa = new coa();
//$coa->coa_id = 1;
//$coa->account_qualifier = 'A';
//pa($coa->findAll_accounts_from_coaId());
//$db2 = new dbc();
//$text = 'A, L';
//$text_a =  explode(',', $text);
//foreach($text_a as $k => $v ){
// $text_a[$k] = $db2->connection->quote($v);
//}
//$text1 = join(',',$text_a);
//
//echo '&nbsp;&nbsp;&nbsp;&nbsp;'. $text1;
//$irh = new inv_receipt_header();
//echo $irh->multi_select_tabs();
//// echo fp_urgent_card::find_current_cardList();
// pa(get_dbColumns('pos_transaction_line'));
// pa(get_dbColumns('pos_transaction_header'));
// pa(get_dbColumns('fa_depreciation_line'));
// pa(get_dbColumns('extn_contact_reference'));
// pa(get_dbColumns('hr_payslip_line'));
// pa(get_dbColumns('sys_process_flow_action'));
// pa(get_dbColumns('sys_pflow_action_val'));
// $row_data_component = new SplFixedArray(2001);
// $row_data_component = [];
// for($i=0; $i<=2000; $i++){
//  $row_data_component[$i] = $i.'sdjsdjsdj_sdjidsj23';
// }
// pa($row_data_component);
// 
// echo '<br>Memory usage is '. memory_get_peak_usage();
// $art = new ArrayObject($arr);
// $it = $art->getIterator();
//
// while($it->valid()){
//  
// }
// $bom_lines = new ArrayIterator($arr);
// echo "<br> counts " . $bom_lines->count();
// $position = 10;
// while($bom_lines->valid()){
//  echo '<br>'.$bom_lines->key() . ' is : ' .$bom_lines->current();
//  $bom_lines->next();
//  
// }
// 
// $bom_lines->seek($position);
// echo '<br>'.$bom_lines->key() . ' is : ' .$bom_lines->current();
// $position++;
// 
//  $bom_lines->rewind();
// echo '<br>'.$bom_lines->key() . ' is : ' .$bom_lines->current();
// 
//  $bom_lines->seek($position);
// echo '<br>'.$bom_lines->key() . ' is : ' .$bom_lines->current();
// 
// $dirs = new DirectoryIterator('../files');
//while($dirs->valid()){
// echo "<br> key ". $dirs->key(). ' and file name is '. $dirs->getFilename(). '<br> File Info '. $dirs->getFileInfo() ;
// $dirs->isDir();
// echo "<br> is it directory : ";
// if($dirs->isDir()){
//  echo " yes";
// }else{
//  echo 'no';
// }
// $dirs->next();
// echo "<br><br><br>";
//}
// execution_time();
// echo "<br> counts old methd " . count($arr);
// pa(inv_item_revision::find_currentRev_by_itemIdM_orgId('10092', '6'));
// $offset = 10;
// $date = new DateTime('2014-7-01');
// $view_i = new extn_view();
// $view_i->view_id = 11;
// $view_i->viewResultById();
// pa($_SESSION);
// $block = new block();
// $block->findBy_id('57');
// $class_containg_block = new $block->reference_table;
// $method_name = $block->name . '_block';
// $parameters['block_id'] = $block->block_id;
// $block_content = call_user_func(array($class_containg_block, $method_name), $parameters);
// echo $block_content;
// echo block::show_block_content_by_BlockId('57');
// echo $fav->show_currentUser_fav();
//
// pa( extn_view::find_all_tables_and_views());
// pa(extn_view::find_columns_of_table_obj('subinventory'));
// 
// $poa = new po_all_v();
// $data = $poa->ra_open_po_by_supplier();
// $legend_p = [];
// $chart_settings_p = [
//  '_chart_name' => 'Purchasing Analysis',
//  '_chart_width' => '550',
//  '_chart_height' => '350',
//  '_x_axis_text' => 'Supplier',
//  '_chart_type' => 'clustered_bar',
//  '_legend' => array('Quantity Onhand', 'Open Quantity'),
// ];
//// pa($data);
// $key_name_setting = $key . '_settings';
// $svgimage = new getsvgimage();
// $svgimage->setProperty('_settings', $chart_settings_p);
// $svgimage->setProperty('_data', $data);
// $chart = $svgimage->draw_chart();
// echo $chart;
//
//
// $svgimg = new getsvgimage();
// $result = $result1 = dbObject::find_by_sql('	SELECT onhand_v.item_number AS onhand_v__item_number,onhand_v.item_description AS onhand_v__item_description,onhand_v.product_line AS onhand_v__product_line,onhand_v.org_name AS onhand_v__org_name,onhand_v.standard_cost AS onhand_v__standard_cost,onhand_v.item_id_m AS onhand_v__item_id_m,onhand_v.org_id AS onhand_v__org_id,onhand_v.onhand AS onhand_v__onhand,onhand_v.onhand_value AS onhand_v__onhand_value,item.item_id AS item__item_id,item.org_id AS item__org_id,item.item_type AS item__item_type,item.item_id_m AS item__item_id_m FROM onhand_v, item WHERE onhand_v.item_id_m = item.item_id_m AND item.org_id = onhand_v.org_id GROUP BY onhand_v.item_id_m,item.org_id ORDER BY onhand_v.onhand_value DESC');
//
// $chart_label = str_replace('.', '__', 'onhand_v__item_number');
// $chart_value = str_replace('.', '__', 'onhand_v__onhand');
// $chart_name = 'Custom View Chart';
// $chart_width = '450';
// $chart_height = '500';
// $chart_type = 'clustered_bar';
// $legend_name = 'onhand_v__org_name';
// $legend_name = str_replace('.', '__', $legend_name);
//
// $data = [];
// $labels = [];
// $legend = [];
//
//// echo "<br>legend $legend_name";
//// echo "<br>chart_label $chart_label";
//// echo "<br>chart_value $chart_value";
// pa($result);
//
// foreach ($result as $obj) {
//  if (!empty($legend_name)) {
//   if (!in_array($obj->$legend_name, $legend)) {
//    array_push($legend, $obj->$legend_name);
//   }
//  }
// }
//
// foreach ($result as $obj) {
//  if (!in_array($obj->$chart_label, $labels)) {
//   array_push($labels, $obj->$chart_label);
//   $row = [];
//   $label = $row['label'] = $obj->$chart_label;
//   $row['value'] = [];
//
//   foreach ($legend as $l_k => $l_v) {
//    $isnull = true;
//    foreach ($result1 as $data_obj) {
//     if (($data_obj->$chart_label) == $label && ($data_obj->$legend_name == $l_v)) {
//      $row['value'][] = $obj->$chart_value;
//      $isnull = false;
//      break;
//     }
//    }
//    if ($isnull) {
//     $row['value'][] = null;
//    }
//   }
//
//
//   array_push($data, $row);
//  }
// }
////
// pa($legend);
// pa($data);
//
// $svgimg->setProperty('_chart_name', $chart_name);
// $svgimg->setProperty('_chart_width', $chart_width);
// $svgimg->setProperty('_chart_height', $chart_height);
// $svgimg->setProperty('_chart_type', $chart_type);
// $svgimg->setProperty('_legend', $legend);
// $svgimg->setProperty('_data', $data);
//
// $svg_chart = $svgimg->draw_chart();
// echo '<div id="return_divId">' . $svg_chart . '</div>';
//// 
//$sql = "SELECT subinventory.subinventory AS subinventory__subinventory,subinventory.subinventory AS subinventory__subinventory,subinventory.subinventory_id AS subinventory__subinventory_id,subinventory.description AS subinventory__description,subinventory.locator_control AS subinventory__locator_control,subinventory.subinventory_id AS subinventory__subinventory_id,locator.locator_id AS locator__locator_id,locator.subinventory_id AS locator__subinventory_id,locator.locator AS locator__locator,locator.locator_structure AS locator__locator_structure,locator.locator_id AS locator__locator_id
//FROM 
//subinventory,locator";
//$result = dbObject::find_by_sql($sql);
//
//$pagination = new pagination();
//$pagination->data_result = $result;
//$pagination->setProperty('_path', 'test');
// echo $pagination->show_result_withPagination();
// 
// 
// $ud = new user_activity_v();
//  
//  $subject_noof_char = 50;
// $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
// $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
// $query_string = !empty($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';
// $comment_result = $ud->user_comments();
// $total_count_c = count($comment_result);
// $pagination_c = new pagination($pageno, $per_page, $total_count_c);
// $pagination_c->setProperty('_path', 'form');
// $pagination_c->setProperty('_query_string', $query_string);
// $comment_string = '<div class="table_container">';
//  if ($comment_result) {
//  $con_count = 0;
//  if (count($comment_result) > 0) {
//   $comment_string .='<table id="comment_list" class="top_margin10 form_line_data_table"><thead> 
//						 <tr class="headerBgColor">
//							<th class="topics">Subject</th>
//							<th class="created_by">Created By</th>
//							<th class="post_date">Post Date</th>
//						 </tr>
//						</thead>';
//   foreach ($comment_result as $recod_c_k => $recod_c) {
//   $continue = false;
////    if (($recod_c_k > ($pageno - 1) * $per_page) && ($recod_c_k <= (($pageno - 1) * $per_page) + $per_page)) {
////     $continue = false;
////    }
//    if ($continue) {
//     continue;
//    }
//    $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
//    $comment_string .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> "
//      . " <td class='subject_summary'>";
//    $comment_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
//      . 'content_id=' . $recod_c->reference_id . '&content_type_id=' . $recod_c->content_type_id . '">';
//    $comment_string .= substr($recod_c->comment, 0, $subject_noof_char);
//    $comment_string .= ' </a>';
//    $comment_string .= '</td>';
//    $comment_string .= '<td class="created_by">';
//    $comment_string .= $recod_c->username;
//    $comment_string .= '</td><td class="post_date">';
//    $comment_string .= $recod_c->creation_date;
//    $comment_string .= '</td>';
//    $comment_string .= '</tr>';
//    $con_count++;
//   }
//
//  }
//
//  $comment_string .='</table>';
// }
// $comment_string .='</div>';
// $comment_string .= '<div id="pagination">';
//
//
// $comment_string .= $pagination_c->show_pagination();
// $comment_string .= '</div>';
//
//
// echo $comment_string;
// function next_monday($date_p) {
//  $date = new DateTime($date_p);
//  if ($date->format('D') == 'Mon') {
//   return $date->format('Y-m-d');
//  } else {
//   $date = new DateTime("next monday $date_p");
//   return $date->format('Y-m-d');
//  }
// }
// echo "<br>Next Monday 2014-7-01 "; echo next_monday('2014-7-01');
// echo "<br>Next Monday 2014-7-02 ";echo next_monday('2014-7-02');
//  echo "<br>Next Monday 2014-7-03 "; echo next_monday('2014-7-03');
// echo "<br>Next Monday 2014-7-04 ";echo next_monday('2014-7-04');
//  echo "<br>Next Monday 2014-7-05 ";echo next_monday('2014-7-05');
//  echo "<br>Next Monday 2014-7-06 "; echo next_monday('2014-7-06');
// echo "<br>Next Monday 2014-7-07 ";echo next_monday('2014-7-07');
// echo "<br>Next Monday 2014-7-08 "; echo next_monday('2014-7-08');
// echo "<br>Next Monday 2014-7-09 ";echo next_monday('2014-7-09');
// echo "<h1> All tables </h1>";
// $table_sql = "   select table_name
//from information_schema.tables
//WHERE TABLE_SCHEMA= '".DB_NAME."'
//AND table_type = 'BASE TABLE'
// ";
//
// $prepare = $dbc->connection->prepare($table_sql);
// try {
//  $prepare->execute();
//  $result_fetchAll = $prepare->fetchAll(PDO::FETCH_COLUMN);
// } catch (Exception $e) {
////    echo "<br>Error @dbObject @@ Line " . __LINE__ . $sql;
//  return false;
// }
//
// echo '<h2>Total no base tables in selected DB '.DB_NAME.' : </h2>' . count($result_fetchAll);
// $include_tables = array_diff($result_fetchAll, convertToProd::$exclude_tables);
// $include_tables = array_values($include_tables);
// echo '<h2>Total no tables updated : </h2>' . count($include_tables);
////pa($include_tables);
//
////
// foreach ($include_tables as $key => $table_name) {
//  $sql2 = " DELETE FROM  {$table_name}  ";
//  $dbc->ddlexecute($sql2);
//  $sql3 = "   ALTER TABLE {$table_name} auto_increment = 1 ";
//  $dbc->ddlexecute($sql3);
//  echo "<br> $table_name is updated";
// }
// $dbc->confirm();
//  $table_sql = "   select table_name
//   from information_schema.columns 
//   WHERE TABLE_SCHEMA = 'inoerp' AND column_name = 'last_update_by' 
// ";
////
// $result1 = dbObject::find_by_sql($table_sql);
//
////
// foreach ($result1 as $obj) {
//  $sql3 = "   ALTER TABLE {$obj->table_name} CHANGE last_update_by last_update_by INT(12) NOT NULL;";
//  $dbc->ddlexecute($sql3);
// }
// $dbc->confirm();
// pa($date);
// echo $date->format('Y-m-d');
// $date->add(new DateInterval('P'.$offset.'D'));
// pa($date);
// echo $date->format('Y-m-d');
// echo "<br>Next monday" . date('Y-m-d', strtotime("next monday", strtotime('2014-7-07')));
// pa(sd_so_line::find_by_orgId_ssd(6, '2014-7-01'));
// pa(extn_view::find_all_tables());
//$sys_notification = new sys_notification();
//  pa($sys_notification->find_openNotification_toUserId('34'));
// pa(get_dbColumns('fp_forecast_over_consumption_v'));
//pa(get_dbColumns('site_info'));
//pa(get_dbColumns('po_quote_detail'));
//  pa(get_dbColumns('po_rfq_line'));
//  pa(get_dbColumns('po_rfq_requirement'));
//  pa(get_dbColumns('hr_leave_entitlement_line'));
//  pa(get_dbColumns('hr_approval_limit_assign'));
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
//pa(get_dbColumns('inv_intorg_transfer_line'));
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
////pa(extn_comment::find_all());
////pa($_SERVER);
//
//
?>
<link href="//<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />

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

<div class="panel panel-default">
 <div class="panel-heading">Panel heading without title</div>
 <div class="panel-body">
  Panel content
 </div>
</div>

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
