function setValFromSelectPage(item_number, combination) {
 this.item_number = item_number;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var item_number = this.item_number;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (item_number) {
	$("#item_template").val(item_number);
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};


$(document).ready(function() {
 //creating tabs
 $(function() {
	$("#tabsHeader").tabs();
	$("#tabsLine").tabs();
 });

 $('#org_id,.disable_autocomplete.item_number').on('change', function() {
	$('#item_id').val('');
 });

//query mode for item
 $("#item_id").bind('keydown', 'Ctrl+q', function() {
	$(this).attr('readonly', false);
	getAllOrgName();
 });



 $(".item_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=item', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the item_id on find button click
 $('a.show.item_id').click(function(e) {
	var item_id = $('#item_id').val();
	$(this).attr('href', modepath() + 'item_id=' + item_id);
 });


 $('a.show.item_number').click(function(e) {
	var org_id = $('#org_id').val();
	var item_number = $('#item_number').val();
	var itemDefined = false;
	$('#inventory_assignment').find('li :checked').each(function() {
	 if ($(this).closest('li').data('org_id') == org_id) {
		itemDefined = true;
		return;
	 }
	});
	if (itemDefined) {
	 if (org_id) {
		$(this).attr('href', modepath() + 'item_number=' + item_number + '&org_id=' + org_id);
	 } else {
		e.preventDefault();
		alert("Select the Organization or Query by item_id ");
	 }
	} else {
	 e.preventDefault();
	 alert('Item is not defined in the organization.Select a differnt organization');
	}

 });

 //get locatot on Subinventory change
 $('#content').on('change', '.wip_supply_subinventory', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 getLocator('../locator/json.locator.php', subInventoryId, 'oneSubinventory', '');
	}
 });
//popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var fieldClass = $(this).closest('li').find('.select_account').prop('class');
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=coa_combination';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //context menu
 function beforeContextMenu() {
	$('#item_number').val('');
	$('#item_description').val('');
	$('#org_id').val('');
	return true;
 }
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'item_id';
 classContextMenu.btn1DivId = 'item_id';
 classContextMenu.beforeCopy = beforeContextMenu;
 classContextMenu.contextMenu();

 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=item';
 classSave.form_header_id = 'item';
 classSave.primary_column_id = 'item_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'item';
 classSave.saveMain();

//select template
 var itemTemplate = new autoCompleteMain();
 itemTemplate.json_url = 'modules/inv/item/item_search.php';
 itemTemplate.select_class = 'select_item_template';
 itemTemplate.min_length = 2;
 itemTemplate.autoComplete();
 
  $(".select_item_template.select_popup").on("click", function() {
	void window.open('select.php?class_name=item', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

function applyTemplate() {
 var itemNumber = $('#item_template').val();
 var orgId = $('#org_id').val();
 $.ajax({
	url: 'form.php',
	type: 'get',
	data: {
	 class_name: 'item',
	 mode: '9',
	 item_number: itemNumber,
	 org_id: orgId
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	complete: function() {
	 $('.show_loading_small').hide();
	}
 }).done(function(result) {
	var newContent = $(result).find('div#content').html();
	if (newContent) {
	 $(newContent).find('#form_line').find(':input').each(function() {
		if ($(this).val()) {
		var asisClass = '.' + $(this).prop('class');
		if (asisClass.length > 1) {
		 var asisClass_d = asisClass.replace(/\s+/g, '.');
		 if (('#content ' + asisClass_d).length > 0) {
			$('#content').find(asisClass_d).val($(this).val());
		 }
		}
		}
	 });
	}
 }).fail(function() {
	alert("Template update failed");
 });
}

$('#apply_item_template').on('click', function() {
 applyTemplate();
});


});



