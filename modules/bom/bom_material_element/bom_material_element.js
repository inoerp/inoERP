$(document).ready(function() {
 
 //selecting data
 $(".bom_material_element_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_bom_material_element.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  function setParnetWindowValues(bom_material_element_id, bom_material_element, orgId)
 {
	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
	 var RowDivId = 'tr#' + localStorage.idValue;
	 window.opener.$(RowDivId).find(".bom_material_element_id").val(bom_material_element_id);
	 window.opener.$(RowDivId).find(".bom_material_element").val(bom_material_element);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".bom_material_element_id").val(bom_material_element_id);
	 window.opener.$(".bom_material_element").val(bom_material_element);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var bom_material_element_id = $(this).val();
	var bom_material_element = $(this).closest("td").siblings("td.bom_material_element").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	setParnetWindowValues(bom_material_element_id, bom_material_element, orgId);
	window.close();
 });
 
 //Get the bom_material_element_id on refresh button click
 $('a.show.bom_material_element_id_show').click(function() {
	var bom_material_element_id = $('#bom_material_element_id').val();
	$(this).attr('href', '?bom_material_element_id=' + bom_material_element_id);
 });
 
//Save record
 save('json.bom_material_element.php', '#bom_material_element', '', 'bom_material_element', '#bom_material_element_id', '');

//delete line
 deleteData('json.bom_material_element.php');

});


