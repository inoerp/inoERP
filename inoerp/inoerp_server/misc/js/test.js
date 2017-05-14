var multi_slect = $('.single_multi_select');
var e_name = $(multi_slect).attr('name');
var new_name = 'xx' + e_name;
var new_element = '<span class="multi-select-container"><ul class="selection-hidden">';
new_element += '<li class="input-element"><input type="text" value="" class="ino-multi-select" name=' + e_name + ' ></li>';
new_element += '<li class="select-element"></li>';
new_element += '</ul></span>';
$('.single_multi_select').replaceWith(new_element);
$(multi_slect).attr('name', new_name).removeAttr('multiple').removeClass('single_multi_select').addClass('');
console.log($(multi_slect).attr('name'));
$('body').on('focusin', '.input-element', function () {
 $(multi_slect).addClass('active-selection');
 $('li.select-element').append(multi_slect);
});
$('body').on('change, focusout', '.active-selection', function () {
 alert('value selected' + $(this).val());
 var existing_text = $(this).closest('ul').find('input.ino-multi-select').prop('value');
 if (existing_text) {
  existing_text += ', ';
 }
 $(this).closest('ul').find('input.ino-multi-select').prop('value', existing_text + $(this).val());
 $('li.select-element').empty();
 $(multi_slect).removeClass('active-selection');
});


$.fn.recordData = function (options) {
 var inputValue;
 $('input').on('keydown',
         function (e) {
          inputValue += String.fromCharCode(e.keyCode);
          console.log(inputValue);
         }

 );

 this.recordInput = function () {
  this.inputValue = null;
  $('input').on('keydown',
          function (e) {
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

$(document).on('keydown', function (e) {
 keys[e.which] = true;
 keys.eachArray(function (i, v) {
  alert('pressed key is ' + i + v);
 });
});

$(document).on('keyup', function (e) {
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
  if (!keys.hasOwnProperty(i))
   continue;
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
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var newContent = $(result).find('div#content').html();
  if (newContent) {
   $(newContent).find('#form_line').find(':input').each(function () {
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
 }).fail(function () {
  alert("Template update failed");
 });
}

$('#apply_item_template').on('click', function () {
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
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#cost_elements_find_all').html();
  var asisClass = '.' + row_class;
  var asisClass_d = asisClass.replace(/\s+/g, '.');
  $("#content").find(asisClass_d).find('.cost_element_id').empty().append(div);
 }).fail(function () {
  alert(" Cost Element Not Found!");
 });
}

$('#content').on('change', '.cost_element_type', function () {
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
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var newContent = $(result).find('div#searchResult').html();
  if (newContent) {
   $('#list_contents').append(newContent);
   $.getScript("http://www.inoideas.com/inoerp/includes/js/reload.js");
  }
 }).fail(function () {
  alert("Search Failed");
 });
}

function getFormDetails(url) {
 $.ajax({
  url: url,
  type: 'get',
  data: {
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
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
   $.getScript("includes/js/reload.js");
  }
 }).fail(function () {
  alert("Form loading failed!");
 });
}


$('#header_top').on('click', '.menu a', function (e) {
 e.preventDefault();
 var urlLink = $(this).attr('href');
 var urlLink_a = urlLink.split('?');
 var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
 alert(formUrl);
 getFormDetails(formUrl);
});



function getFormDetails(url) {
 $.ajax({
  url: url,
  type: 'get',
  data: {
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var newContent = $(result).find('div#structure').html();
  var allButton = $(result).find('#form_top_image').html();
  if (newContent) {
   $('#structure').replaceWith('<div id="structure">' + newContent + '</div>');
   if (allButton) {
    if ($('#form_top_image')) {
//		$('#form_top_image').replaceWith('<div id="form_top_image">' + allButton + '</div>');
    } else {
     $('#header_top_container').prepend('<div id="form_top_image">' + allButton + '</div>');
    }
   }
   $.getScript("includes/js/reload.js");
   $(result).find('#js_files').find('li').each(function () {
    $.getScript($(this).html());
   });
  }
 }).fail(function () {
  alert("Form loading failed!");
 });
}


$('#header_top').on('click', '.menu a, a.show', function (e) {
 e.preventDefault();
 var urlLink = $(this).attr('href');
 var urlLink_a = urlLink.split('?');
 var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
 getFormDetails(formUrl);
});


$('#process_folw').on('mousemove', function (e) {
 var pageCoords = "( " + e.pageX + ", " + e.pageY + " )";
 var clientCoords = "( " + e.clientX + ", " + e.clientY + " )";
 if (e.clientX > 100 && e.clientX < 250 && e.clientY > 205 && e.clientY < 275) {
  var content = $('#process_content').find('.customer').html();
  $("#module_message").html(content);
 } else if (e.clientX > 15 && e.clientX < 225 && e.clientY > 418 && e.clientY < 572) {
  var content = $('#process_content').find('.planning').html();
  $("#module_message").html(content);
 }
 $(".longHeading").text("( e.clientX, e.clientY ) : " + clientCoords);
});


function getViewResult_i() {
 var filterData = $('#view_filters').find('.filtered_field').find(':input').serializeArray();
 getViewResult({
  filterData: filterData,
  view_id: $('#view_id').val(),
  show_from_query: false
 });
}

//$('#content').on('mouseenter', 'table.view th', function() {
// if ($(this).hasClass('show_remove_filter')) {
//
// } else {
//  $(this).addClass('show_add_filter');
// }
//}).on('mouseleave', 'table.view th', function() {
// $(this).removeClass('show_add_filter');
//});

$('#content').on('click', '.show_add_filter', function () {
 $(this).removeClass('show_add_filter');
 var fieldName = $(this).text();
 var filter_value = prompt("Enter value for\n" + fieldName);
 var newDataField = '<span class="filtered_field ' + fieldName + '">' + fieldName + ' : ' + filter_value;
 newDataField += '<input class="hidden filtered_field" type="hidden" value="' + filter_value + '" name="' + $(this).data('fieldname') + '"></span>';
 if (filter_value) {
  $('#view_filters').append(newDataField);
  $(this).addClass('show_remove_filter');
  var filterData = $('#view_filters').find('.filtered_field').find(':input').serializeArray();
  getViewResult({
   filterData: filterData,
   view_id: $('#view_id').val(),
   show_from_query: false
  });
 }
}).on('click', '.show_remove_filter', function () {
 $(this).removeClass('show_remove_filter');
 var fieldName_c = '.filtered_field.' + $(this).text().replace(/\s+/g, '.');
 $('#view_filters').find(fieldName_c).remove();
});

$('#view_filters').on('click', '.filtered_field', function () {
 $(this).remove();
 getViewResult_i();
});

$('#content').on('mouseenter', 'table.view th', function () {
 if ($(this).hasClass('show_remove_filter')) {

 } else {
  $(this).find('.filter_add').addClass('show_add_filter');
  $(this).find('.sort_up').addClass('show_sort_up');
  $(this).find('.sort_up').addClass('show_sort_down');
 }
}).on('mouseleave', 'table.view th', function () {
 $(this).find('.filter_add').removeClass('show_add_filter');
 $(this).find('.sort_up').removeClass('show_sort_up');
 $(this).find('.sort_up').removeClass('show_sort_down');
});



















$('th').find('img').hide();
$('#content').on('mouseenter', 'table.view th', function () {
 $(this).find('ul').addClass('icon_header');
 $(this).find('img').show();
}).on('mouseleave', 'table.view th', function () {
 $(this).find('img').hide();
 $(this).find('ul').removeClass('icon_header');
});

$('#content').on('click', '.filter_add', function () {
 $(this).removeClass('show_add_filter');
 var fieldName = $(this).closest('ul').find('.field_value').text();
 var filter_value = prompt("Enter value for\n" + fieldName);
 var newDataField = '<span class="filtered_field show_remove_filter ' + fieldName + '">' + fieldName + ' : ' + filter_value;
 newDataField += '<input class="hidden filtered_field" type="hidden" value="' + filter_value + '" name="' + $(this).closest('th').data('fieldname') + '"></span>';
 if (filter_value) {
  $('#view_filters').append(newDataField);
  var filterData = $('#view_filters').find('.filtered_field').find(':input').serializeArray();
  getViewResult({
   filterData: filterData,
   view_id: $('#view_id').val(),
   show_from_query: false
  });
 }
}).on('click', '.show_remove_filter', function () {
 $(this).removeClass('show_remove_filter');
 var fieldName_c = '.filtered_field.' + $(this).text().replace(/\s+/g, '.');
 $('#view_filters').find(fieldName_c).remove();
});

$('#view_filters').on('click', '.filtered_field', function () {
 $(this).remove();
 getViewResult_i();
});




$('#view_action_menu_div .view_action_menu').menu();

$('#content').on('mouseenter', 'table.view th', function () {
 if ($(this).hasClass('show_remove_filter')) {

 } else {
  $('#view_action_menu_div .view_action_menu').menu();
  var menuHtml = $('#result_action_menu').html();
  $(this).append(menuHtml);
 }
}).on('mouseleave', 'table.view th', function () {
 $('#content').find('#view_action_menu_div').remove();
});


$('.view_filters').on('click', '.filtered_field, .show_sort_remove', function () {
 $(this).remove();
 var filterData = $(this).closest('div.view_content').find('.view_filters').find('.filtered_field:input').serializeArray();
 var sortData = $(this).closest('div.view_content').find('.view_filters').find('.sorted_field:input').serializeArray();
 var viewId = $('.filtered_field').closest('div.view_content').find('.view_id').val();
 alert(viewId);
 sadas();
 alert(filterData);
 sdfsdf();
 getViewResult({
  filterData: filterData,
  sortData: sortData,
  view_id: viewId,
  show_from_query: false
 });
});


function getFormDetails(url) {
 $.ajax({
  url: url,
  type: 'get',
  data: {
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var newContent = $(result).find('div#structure').html();
  var allButton = $(result).find('div#header_top_container').html();
  if (newContent) {
   $('#structure').replaceWith('<div id="structure">' + newContent + '</div>');
   $('#header_top_container').replaceWith('<div id="header_top_container" style="display: block;">' + allButton + '</div>');
   $.getScript("includes/js/reload.js");
   $(result).find('#js_files').find('li').each(function () {
    $.getScript($(this).html());
   });
  }
 }).fail(function () {
  alert("Form loading failed!");
 });
}


$('body').on('click', '#header_top .menu a,#search_result .action a', function (e) {
 e.preventDefault();
 var urlLink = $(this).attr('href');
 var urlLink_a = urlLink.split('?');
 var urlLink_firstPart_a = urlLink_a[0].split('/');
 var pageType = urlLink_firstPart_a.pop();
 if (pageType == 'form.php') {
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
 } else {
  var formUrl = urlLink;
 }
 getFormDetails(formUrl);
});

//Get the ap_payment_header_id on refresh button click
$('a.show.document_id').click(function (e) {
 var headerId_v = $(this).parent().find(':input').val();
 var headerId = $(this).parent().find(':input').attr('id');
 e.preventDefault();
 var urlLink = $(this).attr('href');
 var urlLink_a = urlLink.split('?');
 var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&' + headerId + '=' + headerId_v;
 getFormDetails(formUrl);
});

var available_indexes = [0, 1];
$("#accordion0").accordion({
 heightStyle: "content",
 activate: function (event, ui) {
  if (ui.newHeader.find('i').hasClass('fa-plus-circle')) {
   ui.newHeader.find('i').removeClass('fa-plus-circle').addClass('fa-minus-circle');
  } 
   
   if (ui.oldHeader.find('i').hasClass('fa-minus-circle')) {
   ui.oldHeader.find('i').removeClass('fa-minus-circle').addClass('fa-plus-circle');
  }
 },
 beforeActivate: function (event, ui) {
  var newIndex = $(ui.newHeader).index('h3');
  console.log( 'new i' + newIndex);
  if (jQuery.inArray(newIndex, available_indexes) === -1) {
   var oldIndex = $(ui.oldHeader).index('h3');
   console.log( 'old i' + oldIndex);
   alert('You cant access this panel. First enter data in previous panel(s)');
    return false;
  }
 }

});




$('#path_by_module a').on('click', function(e) {
  e.preventDefault();
    var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var urlLink_firstPart_a = urlLink_a[0].split('/');
  var pageType = urlLink_firstPart_a.pop();
  if (pageType == 'form.php') {
   var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
  } else if (pageType == 'program.php') {
   var formUrl = 'includes/json/json_program.php?' + urlLink_a[1];
  } else {
   var formUrl = urlLink;
  }
 
  $('#path_by_module a').popover({
  content :  getFormDetails(formUrl)
});
   
});



$(document).ready(function(){
 // When the DOM is ready
		$(function() {
		  
		  // Init ScrollMagic Controller
		  var scrollMagicController = new ScrollMagic();
		  
		  // Create Animation for 0.5s
		  var tween = TweenMax.to('#forest-brush-r', 0.5, {
		    backgroundColor: 'rgb(255, 39, 46)',
		    scale: 5,
		    rotation: 360
		  });
		  
		  // Create the Scene and trigger when visible
		  var scene = new ScrollScene({
		    triggerElement: '#trigger-1',
		    offset: 250 /* offset the trigger 150px below #scene's top */
		  })
		  .setTween(tween)
		  .addTo(scrollMagicController);
		  
		  // Add debug indicators fixed on right side
		   scene.addIndicators();
		  
		});
});