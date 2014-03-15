$(document).ready(function() {

 //controlling org type values - what can be entered

 $("#org_type").change(function() {
	var selectedVal = $(this).val();
	if (selectedVal == "ENTERPRISE") {
	 $("#enterprise_org_id").val("ENTERPRISE");
	 $("#enterprise_org_id").attr("disabled", true);
	 $("#legal_org_id").val("ENTERPRISE");
	 $("#legal_org_id").attr("disabled", true);
	 $("#business_org_id").val("ENTERPRISE");
	 $("#business_org_id").attr("disabled", true);
	 $("input:disabled").css("background-color", "yellow");
	}

	if (selectedVal == "LEGAL_ORG") {
	 $('#loading').show();
	 $.ajax({
		url: 'json.org.php?',
		type: 'get'
	 }).done(function(result) {
		var enterpriseDiv = $(result).filter('div#enterprise_json').html()
		$("#enterprise_org_id").html(enterpriseDiv);
		$('#loading').hide();
	 }).fail(function() {
		alert("failed");
		$('#loading').hide();
	 });
	 $("#enterprise_org_id").attr("disabled", false);
	 $("#legal_org_id").val("LEGAL_ORG");
	 $("#legal_org_id").attr("disabled", true);
	 $("#business_org_id").val("LEGAL_ORG");
	 $("#business_org_id").attr("disabled", true);
	 $("input:disabled").css("background-color", "yellow");
	}

	if (selectedVal == "BUSINESS_ORG") {
	 $('#loading').show();
	 $.ajax({
		url: 'json.org.php?',
		type: 'get'
	 }).done(function(result) {
		var enterpriseDiv = $(result).filter('div#enterprise_json').html();
		var legalDiv = $(result).filter('div#legal_json').html();
		$("#enterprise_org_id").html(enterpriseDiv);
		$("#legal_org_id").html(legalDiv);
		$('#loading').hide();
	 }).fail(function() {
		alert("failed");
		$('#loading').hide();
	 });
	 $("#enterprise_org_id").attr("disabled", false);
	 $("#legal_org_id").attr("disabled", false);
	 $("#business_org_id").val("BUSINESS_ORG");
	 $("#business_org_id").attr("disabled", true);
	 $("input:disabled").css("background-color", "yellow");
	}

	if (selectedVal == "INVENTORY_ORG") {
	 $('#loading').show();
	 $.ajax({
		url: 'json.org.php?',
		type: 'get'
	 }).done(function(result) {
		var enterpriseDiv = $(result).filter('div#enterprise_json').html();
		var legalDiv = $(result).filter('div#legal_json').html();
		$("#enterprise_org_id").html(enterpriseDiv);
		$("#legal_org_id").html(legalDiv);
		$('#loading').hide();
	 }).fail(function() {
		alert("failed");
		$('#loading').hide();
	 });
	 $("#enterprise_org_id").attr("disabled", false);
	 $("#legal_org_id").attr("disabled", false);
	 $("#business_org_id").val("BUSINESS_ORG");
	 $("#business_org_id").attr("disabled", true);
	 $("input:disabled").css("background-color", "yellow");
	}
 });


//Select the legal org while changing the enterprise
 $("#enterprise_org_id").on('blur',function() {
	var enterprise_org_id = $(this).val();
	if (enterprise_org_id != "" && enterprise_org_id != 'undefined')
	{
	 $('#loading').show();
	 $.ajax({
		url: 'json.org.php?',
		data: {enterprise_org_id: enterprise_org_id},
		type: 'get'
	 }).done(function(result) {
				var enterpriseLegalDiv = $(result).filter('div#enterprise_legal_json').html();
		$("#legal_org_id").html(enterpriseLegalDiv);
		$('#loading').hide();
	 }).fail(function() {
		alert("failed");
		$('#loading').hide();
	 });
	}

 });

//Select the business org while changing the legal org
 $("#legal_org_id").on('blur',function() {
	var legal_org_id = $(this).val();
	if (legal_org_id != "" && legal_org_id != 'undefined')
	{
	 $('#loading').show();
	 $.ajax({
		url: 'json.org.php?',
		data: {legal_org_id: legal_org_id},
		type: 'get'
	 }).done(function(result) {
		var businessDiv = $(result).filter('div#business_json').html();
		$("#business_org_id").html(businessDiv);
		$("#business_org_id").attr("disabled", false);
		$('#loading').hide();
	 }).fail(function() {
		alert("failed");
		$('#loading').hide();
	 });
	}

 });

//Popup for selecting org type
 $(".popup").click(function() {
	void window.open('find_org.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 function parentWindow(findElement)
 {
	$(window.opener.document).find("#org_id").val(findElement);
	$('#form_box a.show').prop('href', 'org.php?org_id=' + findElement);
 }

 $("#selected").click(function() {
	var findElement = $(".select_org_id:checked").val();
	parentWindow(findElement);
	window.close();
 });

 $(".quick_select").click(function() {
	var findElement = $(this).val();
	parentWindow(findElement);
	window.close();
 });

//Popup for selecting address 
 $(".address_popup").click(function() {
	void window.open('address/find_address.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 function getAddress(findAddress)
 {
	document.getElementById("address_id").value = findAddress;
	$('#form_header a.show').prop('href', 'address.php?address_id=' + findAddress);
 }

 //Get the org_id on find button click
 $('#form_header a.show').click(function() {
	var orgId = $('#org_id').val();
	$(this).attr('href', '?org_id=' + orgId);
 });

//Get the org id on fly after clicking the submit header
 $('#submit_header').click(function() {
	var orgId = $('#org_id').val();
	$('#org_header').attr('action', 'org.php?org_id=' + orgId);
 });

//Get the org id on fly after clicking the submit line
 $('#submit_line').click(function() {
	var orgId = $('#org_id').val();
	$('#org_line').attr('action', 'org.php?org_id=' + orgId);
 });


save('json.org.php', '#org', '', 'org', '#org_id');
});

