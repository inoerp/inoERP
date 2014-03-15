$(document).ready(function() {
 //selecting data
 $(".bom_resource_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_bom_resource.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  function setParnetWindowValues(bom_resource_id, bom_resource, orgId)
 {
	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
	 var RowDivId = 'tr#' + localStorage.idValue;
	 window.opener.$(RowDivId).find(".bom_resource_id").val(bom_resource_id);
	 window.opener.$(RowDivId).find(".bom_resource").val(bom_resource);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".bom_resource_id").val(bom_resource_id);
	 window.opener.$(".bom_resource").val(bom_resource);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var bom_resource_id = $(this).val();
	var bom_resource = $(this).closest("td").siblings("td.bom_resource").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	setParnetWindowValues(bom_resource_id, bom_resource, orgId);
	window.close();
 });
 
 //Get the bom_resource_id on refresh button click
 $('a.show.bom_resource_id_show').click(function() {
	var bom_resource_id = $('#bom_resource_id').val();
	$(this).attr('href', '?bom_resource_id=' + bom_resource_id);
 });
 
//Save record
 save('json.bom_resource.php', '#bom_resource', '', 'bom_resource', '#bom_resource_id', '');

//delete line
 deleteData('json.bom_resource.php');

});


