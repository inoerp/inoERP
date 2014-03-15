function setValFromSelectPage(bom_cost_type_id) {
 this.bom_cost_type_id = bom_cost_type_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_cost_type_id = this.bom_cost_type_id;
 $("#bom_cost_type_id").val(bom_cost_type_id);
};

$(document).ready(function() {

 //selecting data
 $(".bom_cost_type_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('../../../select.php?class_name=bom_cost_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//  function setParnetWindowValues(bom_cost_type_id, bom_cost_type, orgId)
// {
//	if ((typeof localStorage.idValue !== 'undefined') && (localStorage.idValue.length > 0)) {
//	 var RowDivId = 'tr#' + localStorage.idValue;
//	 window.opener.$(RowDivId).find(".bom_cost_type_id").val(bom_cost_type_id);
//	 window.opener.$(RowDivId).find(".bom_cost_type").val(bom_cost_type);
//	 window.opener.$(RowDivId).find(".org_id").val(orgId);
//	} else {
//	 window.opener.$(".bom_cost_type_id").val(bom_cost_type_id);
//	 window.opener.$(".bom_cost_type").val(bom_cost_type);
//	 window.opener.$(".org_id").val(orgId);
//	}
// }
//
// $(".quick_select").on("click", function() {
//	var bom_cost_type_id = $(this).val();
//	var bom_cost_type = $(this).closest("td").siblings("td.bom_cost_type").html();
//	var orgId = $(this).closest("td").siblings("td.org_id").html();
//	setParnetWindowValues(bom_cost_type_id, bom_cost_type, orgId);
//	window.close();
// });
// 
 //Get the bom_cost_type_id on refresh button click
 $('a.show.bom_cost_type_id_show').click(function() {
	var bom_cost_type_id = $('#bom_cost_type_id').val();
	$(this).attr('href', modepath() + 'bom_cost_type_id=' + bom_cost_type_id);
 });
 var classSave = new saveMainClass();
 classSave.json_url = 'bom_cost_type.php';
 classSave.form_header_id = 'bom_cost_type';
 classSave.primary_column_id = 'bom_cost_type_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'bom_cost_type';
 classSave.saveMain();
});


