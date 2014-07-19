function setValFromSelectPage(inv_abc_valuation_id, combination, mdm_bank_account_id, mdm_bank_header_id, mdm_bank_site_id,
				bank_name, branch_name, account_number) {
 this.inv_abc_valuation_id = inv_abc_valuation_id;
 this.combination = combination;
 this.mdm_bank_account_id = mdm_bank_account_id;
 this.mdm_bank_header_id = mdm_bank_header_id;
 this.mdm_bank_site_id = mdm_bank_site_id;
 this.bank_name = bank_name;
 this.branch_name = branch_name;
 this.account_number = account_number;
}


setValFromSelectPage.prototype.setVal = function() {
 var inv_abc_valuation_id = this.inv_abc_valuation_id;
 var mdm_bank_account_id = this.mdm_bank_account_id;
 var account_number = this.account_number;

 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (inv_abc_valuation_id) {
	$("#inv_abc_valuation_id").val(inv_abc_valuation_id);
 }
 if (mdm_bank_account_id) {
	$("#bank_account_id").val(mdm_bank_account_id);
 }
 if (account_number) {
	$("#account_number").val(account_number);
 }

 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
 //selecting Id
 $(".inv_abc_valuation_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=inv_abc_valuation', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".mdm_bank_account_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_bank_account_v', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the inv_abc_valuation_id on find button click
 $('a.show.inv_abc_valuation_id').click(function() {
	var inv_abc_valuation_id = $('#inv_abc_valuation_id').val();
	$(this).attr('href', modepath() + 'inv_abc_valuation_id=' + inv_abc_valuation_id);
 });

 //get Subinventory Name
 $("#scope_org_id").on("change", function() {
	getSubInventory('modules/inv/subinventory/json_subinventory.php', $("#scope_org_id").val());
 });

 $('#fp_mrp_header_id, #fp_forecast_header_id').on('change', function() {
	var orgID = $(this).find('option:selected').data('org_id');
	$('#scope_org_id').val(orgID).prop('disabled', true);
	getSubInventory('modules/inv/subinventory/json_subinventory.php', $("#scope_org_id").val());
 });

 $('#criteria').on('change', function() {
	var slected_criteria = $(this).val();
	$('#form_header').find('select').prop('disabled', false);
	switch (slected_criteria) {
	 case 'ONHAND_QTY':
	 case 'ONHAND_VALUE':
		$('#fp_mrp_header_id').prop('disabled', true);
		$('#fp_forecast_header_id').prop('disabled', true);
		break;

	 case 'MRP_DEMAND_QTY':
	 case 'MRP_DEMAND_QTY':
		$('#fp_mrp_header_id').prop('required', true);
		$('#fp_forecast_header_id').prop('disabled', true);
		break;

	 case 'FORECAST_DEMAND_QTY':
	 case 'FORECAST_DEMAND_USAGE':
		$('#fp_mrp_header_id').prop('disabled', true);
		$('#fp_forecast_header_id').prop('required', true);
		break;
	}
 });

});
