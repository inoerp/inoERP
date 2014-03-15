<?php
$module_info = [
		array(
				"module" => "ap",
				"class" => "supplier_bu",
				"key_field" => "supplier_id",
				"primary_column" => "supplier_bu_id"
		)
];
$pageTitle = " Supplier - Create & Update all Suppliers ";
$view_path = "supplier_view";
$show_submit_button = 1 ;
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
	localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");;
	return false;
 });
 get_attachment_form('../../../extensions/file/json.file.php');
	save('supplier_bu.php', '#supplier_bu', '', 'supplier_id', "supplier_bu_id");
 });
</script>
<div id="json_save_header"> <?php json_save('ap', 'supplier_bu', 'supplier_id', 'supplier_bu_id'); ?></div>

<?php
if ((!empty($_GET['org_id'])) && (!empty($_GET['supplier_id']))) {
 $supplier_bu->org_id = $_GET['org_id'];
 $supplier_bu_org = org::find_by_id($supplier_bu->org_id);
 $supplier_bu->supplier_id = $_GET['supplier_id'];
 $supplier = supplier::find_by_id($supplier_bu->supplier_id);
 $supplier_bu_array = supplier_bu::find_by_orgId_supplierId($supplier_bu->supplier_id, $supplier_bu->org_id);
 if (!empty($supplier_bu_array[0])) {
	$supplier_bu = $supplier_bu_array[0];
 }
// print_r($supplier_bu_array);
 $supplier_bu->org = $supplier_bu_org->org;
 $supplier_bu->supplier_name = $supplier->supplier_name;
 $supplier_bu->supplier_number = $supplier->supplier_number;
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
 $supplier_bu_file = file::find_by_reference_table_and_id('supplier_bu', $supplier_bu->supplier_bu_id);
}
?>
<?php require_once('supplier_bu_template.php') ?>