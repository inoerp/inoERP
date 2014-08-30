<?php
$module_info = [
		array(
				"module" => "ar",
				"class" => "ar_customer_bu",
				"key_field" => "customer_id",
				"primary_column" => "ar_customer_bu_id"
		)
];
$pageTitle = " Customer - Create & Update all Customers ";
$view_path = "customer_view";
$show_submit_button = 1;
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript'>
 $(document).ready(function() {
	//creating tabs
	$("#tabsLine").tabs();
	//Popup for selecting address 
	$(".address_popup").click(function() {
	 void window.open('../../org/address/find_address.php', '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");
	 ;
	 return false;
	});
	get_attachment_form('../../../extensions/file/json.file.php');
	save('customer_bu.php', '#customer_bu', '', 'ar_customer_id', "ar_customer_bu_id");
 });
</script>
<div id="json_save_header"> <?php json_save('ar', 'ar_customer_bu', 'ar_customer_id', 'ar_customer_bu_id'); ?></div>

<?php
$class = $class_first = 'ar_customer_bu';
$$class = $$class_first = &$ar_customer_bu;

if ((!empty($_GET['org_id'])) && (!empty($_GET['ar_customer_id']))) {
  $org_id = $_GET['org_id'];
 $customer_id = $_GET['ar_customer_id'];
 
  if(ar_customer_bu::find_by_orgId_customerId($customer_id, $org_id)){
//	 echo "<dic class='message'>org_id is $org_id & customer_id is $customer_id </div>";
 $ar_customer_bu = ar_customer_bu::find_by_orgId_customerId($customer_id, $org_id);
 }
 
 $$class->org_id = $_GET['org_id'];
 $$class->ar_customer_id = $_GET['ar_customer_id'];
 
 $customer = ar_customer::find_by_id($customer_id);
 $org = org::find_by_id($org_id);
 $$class->customer_name = $customer->customer_name;
 $$class->customer_number = $customer->customer_number;
 $$class->org = $org->org;
 

 
//// print_r($customer_bu_array);
// $customer_bu->org = $customer_bu_org->org;
// $customer_bu->customer_name = $customer->customer_name;
// $customer_bu->customer_number = $customer->customer_number;
}

if ((!empty($$class->$primary_column)) && (!empty($class::$addressField_array))) {
 foreach ($class::$addressField_array as $key => $value) {
	if (!empty($$class->$value)) {
	 $address = address::find_by_id($$class->$value);
	} else {
	 $address = new address();
	}
	$$value = address::show_adrees_details($address);
 }
}

if (!empty($$class->$primary_column)) {
 $customer_bu_file = file::find_by_reference_table_and_id('ar_customer_bu', $$class->ar_customer_bu_id);
}
?>
<?php require_once('customer_bu_template.php') ?>