function setValFromSelectPage(ext_url_alias_id) {
 this.ext_url_alias_id = ext_url_alias_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var ext_url_alias_id = this.ext_url_alias_id;
  if (ext_url_alias_id) {
	$("#ext_url_alias_id").val(ext_url_alias_id);
 }
};

$(document).ready(function() {
  $(".ext_url_alias_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ext_url_alias', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the ext_url_alias_id on find button click
 $('a.show.ext_url_alias_id').click(function(e) {
	var ext_url_alias_id = $('#ext_url_alias_id').val();
	$(this).attr('href', modepath() + 'ext_url_alias_id=' + ext_url_alias_id);
 });


 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ext_url_alias_id';
 classContextMenu.btn1DivId = 'ext_url_alias_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ext_url_alias';
 classSave.form_header_id = 'ext_url_alias';
 classSave.primary_column_id = 'ext_url_alias_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'ext_url_alias';
 classSave.saveMain();



});


function ext_url_aliasValues(ext_url_aliasType) {
 var ext_url_alias_type = ext_url_aliasType;
 $('#loading').show();
 $.ajax({
	url: 'modules/ext_url_alias/json_ext_url_alias.php',
	type: 'get',
	dataType: 'json',
	context: this,
	data: {
	 ext_url_alias_type: ext_url_alias_type
	},
	success: function(result) {
	 alert('in result');
	 var items = [];
	 $.each(result, function(key, val) {
		alert(key);
	 });
	},
	complete: function() {
	 $('.show_loading_small').hide();
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	error: function(request, errorType, errorMessage) {
	 alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
	}
 });
}

$("#content").on('change', '#type', function() {
 var selectedVal = $(this).val();
 if (selectedVal === "ENTERPRISE") {
	return false;
 } else {
	ext_url_aliasValues('enterprise');
 }
});