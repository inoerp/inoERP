$.fn.recordData = function(options) {
 var inputValue;
 $('input').on('keydown',
				 function(e) {
					inputValue += String.fromCharCode(e.keyCode);
					console.log(inputValue);
				 }

 );

 this.recordInput = function() {
	this.inputValue = null;
	$('input').on('keydown',
					function(e) {
					 this.inputValue += String.fromCharCode(e.keyCode);
					 console.log(this.inputValue);
					}
	);
	return this.inputValue;
 };
 this.recordInput();
 return this;
};

$('#content').recordData();


var keys = [];

$(document).on('keydown',	function(e) {
  keys[e.which] = true;
		keys.eachArray(function(i,v){
		 alert('pressed key is ' + i + v );
		});
	});

$(document).on('keyup',	function(e) {
  delete keys[e.which];
	});
	
	var keys = {};

$(document).keydown(function (e) {
    keys[e.which] = true;
    
    printKeys();
});

$(document).keyup(function (e) {
    delete keys[e.which];
    
    printKeys();
});

function printKeys() {
    var html = '';
    for (var i in keys) {
        if (!keys.hasOwnProperty(i)) continue;
        html += '<p>' + i + '</p>';
    }
    $('#out').html(html);
}
	

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


function getCostElement(json_url, cost_element_type, row_class) {
 switch (cost_element_type) {
	case 'MAT' :
	 var className = 'bom_material_element';
	 break;

	case 'MOH' :
	case 'OH' :
	 var className = 'bom_overhead';
	 break;

	case 'RES' :
	 var className = 'bom_resource';
	 break;

	case 'default':
	 var className = false;
	 break;
 }

 if (className === false) {
	return;
 }

 $.ajax({
	url: json_url,
	type: 'get',
	data: {
	 class_name: className,
	 element_type: cost_element_type,
	 find_cost_elements: '1'
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	complete: function() {
	 $('.show_loading_small').hide();
	}
 }).done(function(result) {
	var div = $(result).filter('div#cost_elements_find_all').html();
	var asisClass = '.' + row_class;
	var asisClass_d = asisClass.replace(/\s+/g, '.');
	$("#content").find(asisClass_d).find('.cost_element_id').empty().append(div);
 }).fail(function() {
	alert(" Cost Element Not Found!");
 });
}

$('#content').on('change', '.cost_element_type', function() {
 var json_url = 'modules/cst/item_cost/json_item_cost.php';
 var cost_element_type = $(this).val();
 var row_class = $(this).closest('tbody').prop('class');
 getCostElement(json_url, cost_element_type, row_class);
});


function getSearchResult() {
 var className = $('.search.class_name').val();
 var searchParameters = $('ul.search_form').find(":input").serializeArray();
 $.ajax({
	url: 'includes/json/json_search.php',
	type: 'get',
	data: {
	 class_name: className,
	 search_parameters: searchParameters
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	complete: function() {
	 $('.show_loading_small').hide();
	}
 }).done(function(result) {
	var newContent = $(result).find('div#searchResult').html();
	if (newContent) {
	 $('#list_contents').append(newContent);
	 $.getScript("http://www.inoideas.com/inoerp/includes/js/reload.js");
	}
 }).fail(function() {
	alert("Template update failed");
 });
}

function getFormDetails(url) {
 $.ajax({
	url: url,
	type: 'get',
	data: {
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	complete: function() {
	 $('.show_loading_small').hide();
	}
 }).done(function(result) {
	var newContent = $(result).find('div#content').html();
	var allButton = $(result).find('#form_top_image').html();
	if (newContent) {
	 $('#content').replaceWith('<div id="content">' + newContent + '</div>');
	 if (allButton) {
		if ($('#form_top_image')) {
//		$('#form_top_image').replaceWith('<div id="form_top_image">' + allButton + '</div>');
		} else {
		 $('#header_top_container').prepend('<div id="form_top_image">' + allButton + '</div>');
		}
	 }
	 $.getScript("http://www.inoideas.com/inoerp/includes/js/reload.js");
	}
 }).fail(function() {
	alert("Form loading failed!");
 });
}

$('#header_top .menu').on('click', 'a', function(e) {
 e.preventDefault();
 getFormDetails($(this).attr('href'));
});



$('#process_folw').on('mousemove', function(e){
 var pageCoords = "( " + e.pageX + ", " + e.pageY + " )";
  var clientCoords = "( " + e.clientX + ", " + e.clientY + " )";
	if(  e.clientX > 100 && e.clientX  < 250 && e.clientY > 205 && e.clientY < 275 ){
	 var content = $('#process_content').find('.customer').html();
	 $( "#module_message").html(content);
	}	else 	if(  e.clientX  > 15 && e.clientX  < 225 && e.clientY > 418 && e.clientY < 572 ){
	 var content = $('#process_content').find('.planning').html();
	 $( "#module_message").html(content);
	}
	$( ".longHeading").text( "( e.clientX, e.clientY ) : " + clientCoords ); 
});