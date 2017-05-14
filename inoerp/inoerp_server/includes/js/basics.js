function animateCycle()
{
 var interval = null;
 $("#animated_content > div:gt(0)").hide();

 function animateContent() {
  $('#animated_content > div:first')
          .slideUp(1000)
          .next()
          .delay(1000)
          .slideDown(1000)
          .end()
          .appendTo('#animated_content');
 }

 interval = setInterval(animateContent, 5000);
 $('#all_contents').on('click', '#animated_block', function () {
  clearInterval(interval);
 });

 $('#all_contents').on('click', '.stop_play', function () {
  clearInterval(interval);
 });

}

function daysBetweenDates(date1, date2) {
 return (Date.parse(date1) - Date.parse(date2)) / (1000 * 60 * 60 * 24);
}

function hideOverLay() {
 $('#overlay').css('display', 'none');
}

function getFormDetails(url) {
 if ($('#unsaved_fields').data('no_of_fields') >= 1) {
  if (confirm("Unsaved chages exists. Do you want to proceed with the action ?") !== true) {
   return false;
  } else {
   remove_unsaved_msg();
  }
 }
 return $.ajax({
  url: url,
  type: 'get',
  data: {
  },
  beforeSend: function () {
   $('#overlay').css('display', 'block');
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
//  if($('#path_by_module').html()){
//   var path_by_module_content = '<div id="path_by_module" class="hidden">' + $('#path_by_module').html() + '</div>';
//  }
  var newContent = $(result).find('div#structure').html();
  var allButton = $(result).find('div#header_top_container #form_top_image').html();
  if (typeof allButton === 'undefined') {
   allButton = '';
  }
  var breadCrumb = $(result).filter('div#top-bc').html();
  var commentForm = $(result).find('div#comment_form').html();
  if (newContent) {
   if ($('#path_by_module').length > 0) {
    $('#hidden-div-content').replaceWith($('#structure').html());
   }
   $('#structure').replaceWith('<div id="structure">' + newContent + '</div>');
//   $('#structure').append(path_by_module_content);
   $('#header_top_container').replaceWith('<div id="header_top_container"> <ul id="form_top_image" class="draggable">' + allButton + '</ul></div>');
   if (typeof breadCrumb !== 'undefined') {
    $('#top-bc').replaceWith('<div id="top-bc" class="container ajax_content">' + breadCrumb + '</div>');
   }

   $('#display_comment_form').append(commentForm);
   if ($(result).find('div#document_history').html()) {
    $('#document_history').replaceWith('<div id="document_history">' + $(result).find('div#document_history').html() + '</div>');
   }
   var homeUrl = $('#home_url').val();
   if ($(result).find('div#page_title').html()) {
    $(document).prop('title', $(result).find('div#page_title').html() + ' - inoERP');
   }

   $(result).find('#js_files').find('li').each(function () {
    $.getScript($(this).html());
   });
   $(result).find('ul#css_files').find('li').each(function () {
    var filePath = $(this).html();
    if (!$("link[href='" + filePath + "']").length) {
     $('<link href="' + filePath + '" rel="stylesheet">').appendTo("head");
    }
   });
   $.getScript(homeUrl + "includes/js/reload.js").done(function () {
    hideOverLay();
   });
  } else {
   hideOverLay();
  }

 }).fail(function () {
  alert("Form loading failed!");
  hideOverLay();
 });
}



function carTupdateAnimation() {
 $("#no-of-cart-items").animate({
  fontSize: "25px",
  backgroundColor: "green",
  marginTop: "50px"
 }, {
  duration: 1000,
  specialEasing: {
   width: "linear",
   height: "easeOutBounce"
  },
  complete: function () {
   $(this).css({
    fontSize: "12px",
    marginTop: "2px",
   });
  }
 });

}

function get_formTopImage() {
 var stmt = '<ul id="form_top_image" class="draggable">';
 stmt += '<li id="refresh_button" class="fa fa-refresh clickable" title="Refresh"></li>';
 stmt += '<li><a id="new_page_button" class="fa fa-file-text-o clickable" href="form.php?mode=9&class_name=hr_timesheet_header" title="New Document"></a></li>';
 stmt += '<li id="save" class="fa fa-save clickable" title="Save"></li>';
 stmt += '<li><a id="new_object_button" class="fa fa-eraser clickable" href="form.php?mode=9&class_name=hr_timesheet_header" title="Clear All, Quick Entry"></a></li>';
 stmt += '<li id="delete_button" class="fa fa-trash-o clickable" title="Delete"></li>';
 stmt += '<li id="remove_row_button" class="fa fa-remove clickable" title="Remove"></li>';
 stmt += '<li id="print_searchResult" class="fa fa-print clickable print" title="Print"></li>';
 stmt += '</ul>';
 return stmt;
}

function arrow_menu() {
 //menu arrow
 $("#header_top .menu li > ul").each(function () {
  var parent = $(this).parent("li");
  parent.addClass("parent").find("> a").append("<span class='arrow-down'></span>");
 });

 //Add the parent class and arrow to third tier sub-menu
 $("#header_top .menu li > ul li > ul").each(function () {
  var parent = $(this).parent("li");
  parent.addClass("parent").find("> a span").removeClass("arrow-down").addClass("arrow-right");
 });
}

function getCommentForm() {
 $('#loading').show();
 var content_id = $("#content_id").val();
 $.ajax({
  url: 'comment.php',
  data: {reference_table: 'content',
   reference_id: content_id},
  type: 'get'
 }).done(function (data) {
  var div = $('#comment', $(data)).html();
  $("#new_comment").append(div);
  $('#loading').hide();
 }).fail(function () {
  alert("Comment content loading failed");
  $('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}
$('body').on('click', '#comment_button', function () {
 getCommentForm();
});

function deleteComment() {
 var homeUrl = $('#home_url').val();
 var daletePath = homeUrl + 'form.php?class_name=extn_comment';
 $("body").on('click', '.delete_button', function (e) {
  var headerId = $(this).val();
  var this_dce = $(this);
  $(".delete_button").addClass("show_loading_small");
  $(".delete_button").prop('disabled', true);
  e.preventDefault();
  if (confirm("Do you really want to delete ?\n" + headerId)) {
   $.ajax({
    url: daletePath,
    data: {
     delete_id: headerId,
     deleteType: 'header',
     delete: '1'},
    type: 'get',
    beforeSend: function () {
     $('.show_loading_small').show();
    },
    complete: function () {
     $('.show_loading_small').hide();
    }
   }).done(function (result) {
    $(".error").prepend(result);
    $("#accordion").accordion({active: 0});
    $(".delete_button").removeClass("show_loading_small");
    $(".delete_button").prop('disabled', false);
    $(this_dce).closest('.commentRecord').remove();
   }).fail(function (error, textStatus, xhr) {
    alert("delete failed \n" + error + textStatus + xhr);
    $(".delete_button").removeClass("show_loading_small");
    $(".delete_button").prop('disabled', false);
   });
  }
 });
}

function calendar_update() {
 var data_arr = [];
 $('tbody.cal-year-tbdy').find('td.col3').each(function () {
  var this_arr = [];
  this_arr['start_date'] = $(this).attr('start_date');
  this_arr['end_date'] = $(this).attr('end_date');
  this_arr['start_time'] = $(this).attr('start_time');
  this_arr['end_time'] = $(this).attr('end_time');
  this_arr['title'] = $(this).closest('tr').find('td.col2').text();
  this_arr['event_id'] = $(this).attr('event_id');
  data_arr.push(this_arr);

 });


 $('tbody.cal-week-tbdy').find('td').not('.col_0').empty();
 $('tbody.cal-day-tbdy').find('td').not('.col_0').empty();
// $('tbody.cal-day-tbdy').find('td').not('.col_0').empty();

 for (var key in data_arr) {
  var this_arr = data_arr[key];
  var start_date = this_arr['start_date'];
  var start_time = this_arr['start_time'];
  var end_time = this_arr['end_time'];
  var title = this_arr['title'];
  var event_id = this_arr['event_id'];

  var start_time_spla = start_time.split(':');
  var end_time_spla = end_time.split(':');
  var total_time = (end_time_spla[0] - start_time_spla[0]) * 60 + (end_time_spla[1] - start_time_spla[1]);
  var tilte_height = total_time / 30;
  var height_class = 'cal-hgt' + tilte_height;
  var msg1 = '<div class="event-msg ' + height_class + ' " height="' + tilte_height + '"  event_id="' + event_id + '"   >' + title + '</div>';
  $('tbody.cal-week-tbdy').find("td[date='" + start_date + "'][time='" + start_time + "']").empty().append(msg1);
  $('tbody.cal-day-tbdy').find("td[date='" + start_date + "'][time='" + start_time + "']").empty().append(msg1);
  $('tbody.cal-month-tbdy').find("td[date='" + start_date + "']").empty().append(msg1);
 }

}

function calendar_size_update() {
 $('.event-msg').each(function () {
  var height = $(this).attr('height') * $(this).parent().height();
  var width = $(this).parent().width();
  $(this).css({
   'height': height + 'px',
   'width': width + 'px'
  });
 });

}
function deleteImage() {
 var homeUrl = $('#home_url').val();
 var daletePath = homeUrl + 'form.php?class_name=extn_image_reference';
 $("body").on('click', '.delete_image', function (e) {
  var this_e = $(this);
  var headerId = $(this).data('extn_image_reference_id');
  $(".delete_button").addClass("show_loading_small");
  $(".delete_button").prop('disabled', true);
  e.preventDefault();
  if (confirm("Do you really want to delete ?\n" + headerId)) {
   $.ajax({
    url: daletePath,
    data: {
     delete_id: headerId,
     deleteType: 'header',
     delete: '1'},
    type: 'get',
    beforeSend: function () {
     $('.show_loading_small').show();
    },
    complete: function () {
     $('.show_loading_small').hide();
    }
   }).done(function (result) {
    $(".error").prepend(result);
    $("#accordion").accordion({active: 0});
    $(".delete_button").removeClass("show_loading_small");
    $(".delete_button").prop('disabled', false);
    this_e.parent().remove();
   }).fail(function (error, textStatus, xhr) {
    alert("delete failed \n" + error + textStatus + xhr);
    $(".delete_button").removeClass("show_loading_small");
    $(".delete_button").prop('disabled', false);
   });
  }
 });
}

function updateComment(comment_id, ulId) {
 var homeUrl = $('#home_url').val();
 var savePath = homeUrl + 'comment.php';
 $('#loading').show();
 return $.ajax({
  url: savePath,
  data: {update: '1',
   extn_comment_id: comment_id},
  type: 'get'
 }).done(function (result) {
  var div = '<div class="temp-update-form">' + $(result).filter('div#commentForm').html() + '</div>';
  var ulId_h = '#' + ulId;
  $('#content').find(ulId_h).find('.update-comment').empty().append(div);
  $('#loading').hide();
 }).fail(function (e) {
  alert("Comment update failed ");
  $('#loading').hide();
 });
}

function include_once(src) {
 var all_scripts = $(document).find('script');
 if (all_scripts) {
  for (var k = 0; k < all_scripts.length; k++) {
   if (all_scripts[k].src == src) {
    return;
   }
  }
 }
 var script = document.createElement('script');
 script.src = src;
 script.type = 'text/javascript';
 ($(document).find('HEAD')[0] || document.body).appendChild(script);
}

function getFieldNames(options) {
 var defaults = {
  fieldClass: 'table_fields',
  josnurl: 'extensions/view/json_view.php'
 };
 var settings = $.extend({}, defaults, options);
 $('#loading').show();
 $.ajax({
  url: settings.josnurl,
  data: {
   tableName: settings.tableName,
   get_fieldName: 1},
  type: 'get'
 }).done(function (result) {
  var parentClass = '.' + settings.parentClass.replace(/\s+/g, '.');
  var fieldClass = '.' + settings.fieldClass.replace(/\s+/g, '.');
  var div = $(result).filter('div#json_filed_names').html();
  if (div.length > 5) {
   $('#content').find(parentClass).find(fieldClass).empty().append(div);
  }
  $('#loading').hide();
 }).fail(function () {
  alert("table field loading failed");
  $('#loading').hide();
 });
 $(".table_fields").attr("disabled", false);
}

//tree view
function folder_treeView() {
 var plusClass = 'fa-folder-o';
 var minusClass = 'fa-folder-open-o';
 $('ul.tree_view2  ul').hide();
 $('ul.tree_view2 > li').show();
 $('ul.tree_view2 > li').has('ul').addClass('contentContainer fa ' + plusClass);
 $('.tree_view2').on('click', '.contentContainer, .contentViewing',
         function (e) {
          if (e.target === this && $(this).hasClass('contentContainer')) {
           $(this).find('>ul').show();
           $(this).find('>ul').find('>li').show();
           $(this).find('>ul').find('>li').has('ul').addClass('contentContainer ' + plusClass);
           $(this).removeClass('contentContainer ' + plusClass).addClass('contentViewing fa ' + minusClass);
           e.stopPropagation();
          } else if (e.target === this) {
           $(this).find('>ul').hide();
           $(this).find('>ul').find('>li').hide().removeClass('contentContainer ' + plusClass);
           $(this).removeClass('contentViewing ' + minusClass).addClass('contentContainer ' + plusClass);
           e.stopPropagation();
          }
          if (e.target === this) {
           $(this).parent().find('.contentContainer, .contentViewing').not(this).each(function (e) {
            $(this).find('ul').hide();
            $(this).find('ul').find('li').hide().removeClass('contentContainer ' + minusClass);
            $(this).removeClass('contentViewing ' + minusClass).addClass('contentContainer ' + plusClass);
           });
          }

         });

}



//function treeview
function treeView() {
 var plusClass = 'fa-plus-square';
 var minusClass = 'fa-minus-square';
 if ($(this).attr('data-plusclass')) {
  plusClass = $('ul.tree_view').Data('plusclass');
 }
 if ($(this).attr('data-minusclass')) {
  minusClass = $('ul.tree_view').Data('minusclass');
 }
 $('ul.tree_view  ul').hide();
 $('ul.tree_view > li').show();
 $('ul.tree_view > li').has('ul').addClass('contentContainer fa ' + plusClass);
 $('.tree_view').on('click', '.contentContainer, .contentViewing',
         function (e) {
          if (e.target === this && $(this).hasClass('contentContainer')) {
           $(this).find('>ul').show();
           $(this).find('>ul').find('>li').show();
           $(this).find('>ul').find('>li').has('ul').addClass('contentContainer ' + plusClass);
           $(this).removeClass('contentContainer ' + plusClass).addClass('contentViewing fa ' + minusClass);
           e.stopPropagation();
          } else if (e.target === this) {
           $(this).find('>ul').hide();
           $(this).find('>ul').find('>li').hide().removeClass('contentContainer ' + plusClass);
           $(this).removeClass('contentViewing ' + minusClass).addClass('contentContainer ' + plusClass);
           e.stopPropagation();
          }
          if (e.target === this) {
           $(this).parent().find('.contentContainer, .contentViewing').not(this).each(function (e) {
            $(this).find('ul').hide();
            $(this).find('ul').find('li').hide().removeClass('contentContainer ' + minusClass);
            $(this).removeClass('contentViewing ' + minusClass).addClass('contentContainer ' + plusClass);
           });
          }

         });

 $('body').on('click', '#expand_all_nav', function () {
  $('#sys_menu_left_vertical').find('.tree_view').find('.contentContainer, .contentViewing').each(function (e) {
   $(this).find('ul').show();
   $(this).find('ul').find('li').show();
   $(this).find('ul').find('li').has('ul').addClass('contentContainer fa-plus-square');
   $(this).removeClass('contentContainer fa-plus-square').addClass('contentViewing fa-minus-square');
  });
 });

 $('body').on('click', '#collapse_all_nav', function () {
  $('#sys_menu_left_vertical').find('.tree_view').find('.contentContainer, .contentViewing').each(function (e) {
   $(this).find('ul').hide();
   $(this).find('ul').find('li').hide().removeClass('contentContainer fa-minus-square');
   $(this).removeClass('contentViewing fa-minus-square').addClass('contentContainer fa-plus-square');
  });
 });

}


function treeView_simple() {
 $('ul.tree_view  ul').hide();
 $('ul.tree_view > li').show();
 $('ul.tree_view > li').has('ul').addClass('contentContainer');
 $('.tree_view').on('click', '.contentContainer, .contentViewing',
         function (e) {
          if ($(this).hasClass('contentContainer')) {
           $(this).find('>ul').show();
           $(this).find('>ul').find('>li').show();
           $(this).find('>ul').find('>li').has('ul').addClass('contentContainer');
           $(this).removeClass('contentContainer').addClass('contentViewing');
           e.stopPropagation();
          } else {
           $(this).find('>ul').hide();
           $(this).find('>ul').find('>li').hide().removeClass('contentContainer');
           $(this).removeClass('contentViewing').addClass('contentContainer');
           e.stopPropagation();
          }
         });

 $('.expand_collapse_all').on('click', function () {
  $(this).parent().find('.tree_view').find('.contentContainer, .contentViewing').each(
          function (e) {
           if ($(this).hasClass('contentContainer')) {
            $(this).find('ul').show();
            $(this).find('ul').find('li').show();
            $(this).find('ul').find('li').has('ul').addClass('contentContainer');
            $(this).removeClass('contentContainer').addClass('contentViewing');
           } else {
            $(this).find('ul').hide();
            $(this).find('ul').find('li').hide().removeClass('contentContainer');
            $(this).removeClass('contentViewing').addClass('contentContainer');
           }
          });
 });

}


function toUpperCase(str)
{
 return str.toLowerCase().replace(/([^a-z])([a-z])(?=[a-z]{2})|^([a-z])/g, function (_, g1, g2, g3) {
  return (typeof g1 === 'undefined') ? g3.toUpperCase() : g1 + g2.toUpperCase();
 });
}

function recentVisitInAjax() {
 $('body #recent-visits').on('click', 'a', function (e) {
  e.preventDefault();
  getFormDetails($(this).attr('href'));

 });
}

function magnifier() {
 //image maginifier
 var native_width = 0;
 var native_height = 0;
 $('body').on('mousemove', '.magnify', function (e) {
  if ((!native_width && !native_height))
  {
   var image_src = $(this).find('.item.active').find('.img').prop('src');
   var image_object = new Image();
   image_object.src = image_src;
   native_width = image_object.width;
   native_height = image_object.height;
  } else
  {
   var magnify_offset = $(this).offset();
   var mx = e.pageX - magnify_offset.left;
   var my = e.pageY - magnify_offset.top;

   //Finally the code to fade out the glass if the mouse is outside the container
   if (mx < $(this).width() && my < $(this).height() && mx > 0 && my > 0)
   {
    $(".large").fadeIn(100);
   } else
   {
    $(".large").fadeOut(100);
    $.magnifier().one();

   }

   if ($(".large").is(":visible"))
   {
    var rx = Math.round(mx / $(".small").width() * native_width - $(".large").width() / 2) * -1;
    var ry = Math.round(my / $(".small").height() * native_height - $(".large").height() / 2) * -1;
    var bgp = rx + "px " + ry + "px";

    var px = mx - $(".large").width() / 2;
    var py = my - $(".large").height() / 2;
    var image_src = $(this).find('.item.active').find('.img').prop('src');
    $(".large").css('background-image', 'url(' + image_src + ')');
    $(".large").css({left: px, top: py, backgroundPosition: bgp});
   }
  }
 }).on('mouseout', '.magnify', function () {
  $(".large").hide();
 });
}


//get blocks
function setConetntRightLeft() {
 var content_right_right = $("#content_right_right").html();
 if ((content_right_right === undefined) ||
         (content_right_right === "")) {
  $("#content_right_left").width("100%");
  $("#content_right_right").width("0%");
 } else {
  $("#content_right_left").width("84%");
  $("#content").css("float:left");
  $("#content_right_right").width("12%");
 }

}

function getBlocks() {
 var pathname = window.location.href;
 var homeUrl = $('#home_url').val();
 if (!homeUrl) {
  return false;
 }
 var blockPath = homeUrl + 'includes/basics/json.basics.php';
 var smallLoadingImg = homeUrl + 'files/images/small_loading.gif';
 $.ajax({
  url: blockPath,
  data: {all_blocks: '1',
   pathname: pathname,
  },
  type: 'POST',
  timeout: 50000,
  beforeSend: function () {
   $('#content_left').html('<img src="' + smallLoadingImg + '"\> loading...');
  }
 }).done(function (data) {
  var header_top = $('#header_top', $(data)).html();
  var header_bottom = $('#header_bottom', $(data)).html();
  var navinagtion_top = $('#navinagtion_top', $(data)).html();
  var navinagtion_bottom = $('#navinagtion_bottom', $(data)).html();
  var content_top = $('#content_top', $(data)).html();
  var content_left_top = $('#content_left_top', $(data)).html();
  var content_right_top = $('#content_right_top', $(data)).html();
  var content_left_bottom = $('#content_left_bottom', $(data)).html();
  var content_right_bottom = $('#content_right_bottom', $(data)).html();
  var content_bottom = $('#content_bottom', $(data)).html();
  var content_left = $('#content_left', $(data)).html();
  var content_right_right = $('#content_right_right', $(data)).html();
  var footer_top = $('#footer_top', $(data)).html();
  var footer_bottom = $('#footer_bottom', $(data)).html();
  $("#header_top").append(header_top);
  $("#header_bottom").append(header_bottom);
  $("#navinagtion_top").append(navinagtion_top);
  $("#navinagtion_bottom").append(navinagtion_bottom);
  $("#content_top").append(content_top);
  $("#content_left_top").append(content_left_top);
  $("#content_right_top").append(content_right_top);
  $("#content_left_bottom").append(content_left_bottom);
  $("#content_right_bottom").append(content_right_bottom);
  $("#content_bottom").append(content_bottom);
  $("#content_left").html(content_left);
  $("#content_right_right").append(content_right_right);
  $("#footer_top").append(footer_top);
  $("#footer_bottom").append(footer_bottom);
//	setConetntRightLeft();
  if ((typeof (header_top) !== 'undefined') && (header_top.length > 1)) {
   $('#header_top_container').css('display', 'block');
  }
//  treeView_simple();
//  arrow_menu();
 }).fail(function () {
  $('#content_left').html('');
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}
//remoe & replace content from summary
function update_summary_list(maxListCount, shownListCount) {
 $('ul.summary_list').find('li').each(function () {
  var className = $(this).prop('class');
  var startPoint = className.lastIndexOf('_') + 1;
  var listCount = +className.substring(startPoint);
  if (listCount > maxListCount || listCount <= shownListCount) {
   $(this).hide();
  } else {
   $(this).show();
  }
 });
}

//get parameter value from window.location - equivalent og $_GET
function getUrlValues(name, user_link) {
 var link = typeof user_link === 'undefined' ? location.search : user_link;
 name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
 var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
         results = regex.exec(link);
 return results == null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
}

function modepath() {
 var url = '';
 url += getUrlValues('class_name') == null ? '' : 'class_name=' + getUrlValues('class_name') + '&';
 url += getUrlValues('mode') == null ? '' : 'mode=' + getUrlValues('mode') + '&';
 if (url != null) {
  url = '?' + url;
 }
 return url;
}

function formModePath(user_link) {
 var url = '';
 url += getUrlValues('class_name', user_link) == null ? '' : 'class_name=' + getUrlValues('class_name', user_link) + '&';
 url += getUrlValues('mode', user_link) == null ? '' : 'mode=' + getUrlValues('mode', user_link) + '&';
 if (url != null) {
  url = '?' + url;
 }
 return url;
}

//select mandatory fields
var Mandatory_Fields = "";
function select_mandatory_fields_all(form_area, Mandatory_Fields) {
 var i = 0;
 if (Mandatory_Fields.length / 2 >= 1) {
  var fieldId = Mandatory_Fields[i];
  var msg = Mandatory_Fields[i + 1];
  $(form_area + " :input").not(fieldId).on("focusin", function () {
   if ($(fieldId).val().length === 0) {
    alert(msg);
    $(fieldId).focus();
   }
  });
  $(fieldId).on("change", function () {
   if ($(fieldId).val().length === 0) {
    alert(msg);
    $(fieldId).focus();
   } else if (Mandatory_Fields.length >= 2) {
    Mandatory_Fields.splice(0, 2);
    if (Mandatory_Fields.length >= 2) {
     select_mandatory_fields(Mandatory_Fields);
    }
   }
  });
 }

}


function select_mandatory_fields(Mandatory_Fields) {
 select_mandatory_fields_all('#content', Mandatory_Fields);
}

function select_mandatory_fields_line(Mandatory_Fields) {
 select_mandatory_fields_all('#form_line', Mandatory_Fields);
}

function remove_row() {
 $("body").on("click", ".remove_row_img", function () {
  var trclass = $(this).closest('tr').attr("class");
  var newTrclass = trclass.replace(/\s+/g, '.');
  if (($("tr." + newTrclass).closest('form').find('tbody').first().children().filter('tr').length) > 1) {
   $("tr." + newTrclass).remove();
  } else if (($("tr." + newTrclass).closest('form').find('tbody.form_data_line_tbody').first().children().filter('tr').length) > 1) {
   $("tr." + newTrclass).remove();
  } else if (($("tr." + newTrclass).closest('form').find('tbody.form_data_detail_tbody').first().children().filter('tr').length) > 1) {
   $("tr." + newTrclass).remove();
  } else if (($("tr." + newTrclass).closest('form').find('tbody.form_data_detail_tbody_sn').first().children().filter('tr').length) > 1) {
   $("tr." + newTrclass).remove();
  } else if (($("tr." + newTrclass).closest('form').find('tbody.form_data_detail_tbody_ln').first().children().filter('tr').length) > 1) {
   $("tr." + newTrclass).remove();
  }

 });
}

function po_calculate_amounts_withLinePrice(elem) {
 var trClass = '.' + elem.closest('tr').attr('class');
 var unitPrice = +(elem.closest('#form_line').find(trClass).find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
 var lineQuantity = +(elem.closest('#form_line').find(trClass).find('.line_quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
 var linePrice = unitPrice * lineQuantity;
 $(elem).closest('#form_line').find(trClass).find('.line_price').val(linePrice);
 $('body').trigger('calculateTax', [trClass]);
 $('body').trigger('getGlPrice', [trClass]);
 $('body').trigger('calculateHeaderAmount');
}

function po_calculate_amounts(elem) {
 var trClass = '.' + elem.closest('tr').prop('class');
 $('body').trigger('calculateTax', [trClass]);
 $('body').trigger('getGlPrice', [trClass]);
 $('body').trigger('calculateHeaderAmount');
}

//function lineDetail_QuantityValidation
function lineDetail_QuantityValidation(call_back_f) {
 $('#content').on('change, keyup', '.line_quantity', function () {
  var lineQuantity = $(this).val();
  var detailQuantity = 0;
  $(this).closest('tr').find('.add_detail_values').find('.quantity').each(function () {
   detailQuantity += +$(this).val();
  });

  if ((detailQuantity > 0) && (lineQuantity != detailQuantity)) {
   $(this).val(detailQuantity);
   alert('Sum of detail quantity should be same as sum of line quantity\nChange detail quanityt if required');
  }
 });

 $('#content').on('change, keyup', '.quantity', function () {
  var detailQuantity = 0;
  $(this).closest('tbody').find('.quantity').each(function () {
   detailQuantity += +$(this).val();
  });
  $(this).closest('.add_detail_values').closest('tr').find('.line_quantity').val(detailQuantity);
  $('.line_quantity').trigger('lineChange_t');
  if (call_back_f !== 'undefined' && call_back_f !== "") {
   po_calculate_amounts_withLinePrice($(this).closest('.add_detail_values').closest('tr').find('.line_quantity').first());
  }
 });
}

//add new search criteria
function new_searchCriteria_onClick(json_url) {
 $("#new_search_criteria_add").on("click", function () {
  $('#loading').show();
  var new_search_criteria = $(".new_search_criteria").val();
  $.ajax({
   url: json_url,
   data: {new_search_criteria: new_search_criteria},
   type: 'get'
  }).done(function (result) {
   var div = $(result).filter('div#new_search_criteria').html();
   $("ul.search_form").append(div);
   $('#loading').hide();
  }).fail(function () {
   $('#loading').hide();
  });
 });
}

//add a new line on clickint add a new detail line
var detailObjectCount = 2001;
var dateCount = 30000;
function onClick_addDetailLine(noOfTabs, add_row_detail_img, tabsDetailName) {
 add_row_detail_img = (typeof add_row_detail_img !== 'undefined') ? add_row_detail_img : '.add_row_detail_img';
 tabsDetailName = (typeof tabsDetailName !== 'undefined') ? tabsDetailName : 'tabsDetail';
 var highest_seq_num = 1;
 var lastDetailNumber = 1;
 $("#content").off('click', add_row_detail_img).on("click", add_row_detail_img, function () {
  noOfTabs = $(this).closest('.tabContainer').find('.tabContent').length;
  var trClass = '.' + $(this).closest("tr").attr('class').replace(/\s+/g, '.');
  var trClass_wod = trClass.replace(/tr\./g, '');
  trClass_wod = trClass_wod.replace(/\./g, '');
  var tbodyClass = 'tbody.' + $(this).closest("tbody").attr('class').replace(/\s+/g, '.');
  if ($(this).closest('tbody').find('.detail_seq_number').last().val()) {
   highest_seq_num = +$(this).closest('tbody').find('.detail_seq_number').last().val();
  } else {
   highest_seq_num++;
  }
  var nextDetailSeqNumber_seq = (highest_seq_num) + 1;

  if ($(this).closest('tbody').find('.detail_number').last().val()) {
   lastDetailNumber = +$(this).closest('tbody').find('.detail_number').last().val();
  } else {
   lastDetailNumber++;
  }
  var nextDetailNumber = (lastDetailNumber + 1);
//	var nextDetailSeqNumber = (+lastDetailSeqNumber + 0.1).toFixed(1);
  var closetLineRowClass = $(this).closest(".class_detail_form").closest('tr').attr('class');
  var closetLineRowClass = '.' + closetLineRowClass;
  if (noOfTabs > 1) {
   var startingTab = $("tr[class*='" + trClass_wod + "']").first().closest('.tabContent').attr('id');
   var startingTabArray = startingTab.split('-');
   var startingTabLastNumber = startingTabArray[2];
   var startingTabFirstNumber = startingTabArray[1];
   var tabCount = 1;
   do {
    $("#" + tabsDetailName + "-" + startingTabFirstNumber + "-" + startingTabLastNumber).find(trClass).clone().attr("class", "new_object" + detailObjectCount).appendTo($(closetLineRowClass + " #" + tabsDetailName + "-" + startingTabFirstNumber + "-" + startingTabLastNumber + " " + tbodyClass));
    startingTabFirstNumber++;
    tabCount++;
   } while (tabCount <= noOfTabs);
  } else {
   $(trClass + ':first').clone().attr("class", "new_object" + detailObjectCount).appendTo($(closetLineRowClass + ' ' + tbodyClass));
  }

  $("tr.new_object" + detailObjectCount).find("td input[type=text]").not('.copyValue').each(function () {
   $(this).val("");
  });
  $("tr.new_object" + detailObjectCount).find("td input[type=number]").not('.copyValue').each(function () {
   $(this).val("");
  });
  $("tr.new_object" + detailObjectCount).find("td select").not('.copyValue').each(function () {
   $(this).val("");
  });

  $(".new_object" + detailObjectCount).find(".detail_seq_number").val(nextDetailSeqNumber_seq);
  $(".new_object" + detailObjectCount).find(".detail_number").val(nextDetailNumber);
  $(".new_object" + detailObjectCount).find(".date").each(function () {
   $(this).attr("id", "date" + dateCount);
   dateCount++;
  });
  detailObjectCount++;
 });
}


function onClick_add_new_row(trClass, tbodyClass, noOfTabs, divClassToBeCopied) {
 $("body table").on("click", ".add_row_img", function () {
//	add_new_row(trClass, tbodyClass, noOfTabs);

  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = trClass;
  addNewRow.tbodyClass = tbodyClass;
  addNewRow.noOfTabs = noOfTabs;
  addNewRow.removeDefault = true;
  addNewRow.enableUpdate = 'enable_update';
  addNewRow.divClassToBeCopied = divClassToBeCopied;
  addNewRow.add_new_row();
 }).one();
 return 1;
}
//onClick_add_new_row();
//toggle detail lines if exists else create a new detail line
var objectDetailTabCount = 2;
var detailObjectRowCount = 600;
function addOrShow_lineDetails(afterAddNewDetail) {
 var highest_seq_num = 0;
 if ($('.form_data_detail_tbody').find('.detail_seq_number').last().val()) {
  highest_seq_num = $('.form_data_detail_tbody').find('.detail_seq_number').last().val();
 }
 var nextDetailSeqNumber_seq = (+highest_seq_num) + 1;
 $('body').on("click", "table.form_line_data_table .add_detail_values_img", function () {
  var class_detail_form_w = ($(this).closest('tr').width() - $(this).closest('tr').find('td:first').width() - $(this).closest('td').width()) + 'px';
  $(this).closest('td').find('.class_detail_form').width(class_detail_form_w).css({
   'margin-left': '-' + class_detail_form_w,
   'margin-top': '24px'
  });
  var tabID = '#' + $(this).closest('.tabContent').attr('id');
  var tdClass = '.' + $(this).closest('td').attr('class').replace(/tr\./g, '');
  var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
  if (detailExists > 0) {
   $(this).closest("td").find(".form_detail_data_fs").toggle();
  } else {
   var detailNumber = 1;
   var elementToBeCloned = $('#content').find(tabID).find(tdClass).find('.class_detail_form').first();
   var clonedElement = elementToBeCloned.clone();

   var firstTrClass = '.' + $(clonedElement).find('tbody').find("tr").first().attr('class').replace(/tr\./g, '');
   clonedElement.find("tr").not(':first-child').not(firstTrClass).remove();
   $(clonedElement).find('tbody tr').attr("class", "new_object" + detailObjectRowCount);
   clonedElement.find("input").not('.hidden').each(function () {
    $(this).val("");
   });
   clonedElement.appendTo($(this).closest("td"));
   $(this).closest("td").find("li.tabLink").each(function () {
    var tabLink = $(this).find("a[href]").attr('href');
    var n = tabLink.lastIndexOf("-");
    var newStr = tabLink.substring(0, n);
    var newTabLink = newStr + '-' + objectDetailTabCount;
    $(this).find("a[href]").attr('href', newTabLink);
   });
   $(this).closest("td").find(".tabContent").each(function () {
    var tabLink = $(this).attr('id');
    var n = tabLink.lastIndexOf("-");
    var newStr = tabLink.substring(0, n);
    var newTabLink = newStr + '-' + objectDetailTabCount;
    $(this).attr('id', newTabLink);
   });
   $(".tabsDetail").tabs();
   $(this).closest("td").find(".form_detail_data_fs").toggle();
   $(this).closest("td").find(".detail_number:first").val(detailNumber);
   $(this).closest("td").find(".detail_seq_number").val(nextDetailSeqNumber_seq);
  }
  objectDetailTabCount++;
  detailObjectRowCount++;
  if (typeof afterAddNewDetail === 'function') {
   afterAddNewDetail();
  }
 });


}

function deleteLine(json_url, delete_id, delete_type) {
 switch (delete_type) {
  case 'detail':
   var deleteType = 'detail';
   break;

  case 'line':
   var deleteType = 'line';
   break;

  case 'line2':
   var deleteType = 'line2';
   break;

  case 'header':
   var deleteType = 'header';
   break;

  case 'default':
   var deleteType = 'header';
   break;
 }
 $.ajax({
  url: json_url,
  data: {
   delete: '1',
   delete_id: delete_id,
   deleteType: deleteType},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
//	if (isDetail == 1) {
//	 var div = $(result).filter('div#json_delete_detail').html();
//	} else {
//	 var div = $(result).filter('div#json_delete_line').html();
//	}
  $(".error").append(result);
  $("#delete_button").removeClass("show_loading_small");
  $("#delete_button").prop('disabled', false);
 }).fail(function (error, textStatus, xhr) {
  alert("delete failed \n" + error + textStatus + xhr);
  $("#delete_button").removeClass("show_loading_small");
  $("#delete_button").prop('disabled', false);
 });
}
//used for deleting header forms like content/page/comment
function deleteHeader(json_url, headerId) {
 $("#delete_button").click(function (e) {
  $("#delete_button").addClass("show_loading_small");
  $("#delete_button").prop('disabled', true);
  e.preventDefault();
  if (confirm("Do you really want to delete ?\n" + headerId)) {
   deleteHeaderAjax(json_url, headerId);
  }
 });
}

function deleteHeaderAjax(json_url, headerId) {
 $.ajax({
  url: json_url,
  data: {
   delete_id: headerId,
   deleteType: 'header',
   delete: '1'
  },
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
//		var div = $(result).filter('div#json_delete_header').html();
  $(".error").append(result);
  $("#delete_button").removeClass("show_loading_small");
  $("#delete_button").prop('disabled', false);
 }).fail(function (error, textStatus, xhr) {
  alert("delete failed \n" + error + textStatus + xhr);
  $("#delete_button").removeClass("show_loading_small");
  $("#delete_button").prop('disabled', false);
 });
}

function deleteReferences(options) {
 var defaults = {
  deleteType: 'header',
  json_url: 'form.php?class_name=extn_contact_reference'
 };
 var settings = $.extend({}, defaults, options);

 $('#content').on('click', '.delete_ref', function () {
  var headerId = $(this).data('delete_id');
  if (confirm("Do you really want to delete ?\n" + headerId)) {
   $.ajax({
    url: settings.json_url,
    data: {
     delete_id: headerId,
     deleteType: settings.deleteType,
     delete: '1'
    },
    type: 'get',
    beforeSend: function () {
     $('.show_loading_small').show();
    },
    complete: function () {
     $('.show_loading_small').hide();
    }
   }).done(function (result) {
//		var div = $(result).filter('div#json_delete_header').html();
    $(".error").append(result);
    $("#delete_button").removeClass("show_loading_small");
    $("#delete_button").prop('disabled', false);
   }).fail(function (error, textStatus, xhr) {
    alert("delete failed \n" + error + textStatus + xhr);
    $("#delete_button").removeClass("show_loading_small");
    $("#delete_button").prop('disabled', false);
   });
  }

 });
}

function deleteData(json_url) {
 $('body').off('click', '#delete_button').on('click', '#delete_button', function (e) {
  remove_unsaved_msg();
  $("#delete_button").addClass("show_loading_small");
  $("#delete_button").prop('disabled', true);
  e.preventDefault();
  $('input[name="detail_id_cb"]:checked').each(function () {
   var detail_id = $(this).val();
   if (confirm("Are you sure?\nDetail Id #" + detail_id)) {
    deleteLine(json_url, detail_id, 'detail');
   }
  });

  $('input[name="line_id_cb"]:checked').each(function () {
   var line_id = $(this).val();
   if (confirm("Are you sure?\nLine Id #" + line_id)) {
    if ($(this).closest('tbody').hasClass('form_data_line_tbody2')) {
     var lineType = 'line2';
    } else {
     var lineType = 'line';
    }
    deleteLine(json_url, line_id, lineType);
   }
  });

  if (!$('input[name="line_id_cb"]').val()) {
   var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
   var header_id_h = '#' + primary_column_id;
   var headerId = $(header_id_h).val();
   if (confirm("Are you sure?\nHeader Id #" + headerId)) {
    deleteLine(json_url, headerId, 'header');
   }
  }
  $("#accordion").accordion({active: 0});
  $('#content a.show').trigger('click');
 });
}

function deleteFile(json_url, file_reference_id) {
 $('.show_loading_small').show();
 $.ajax({
  url: json_url,
  data: {delete: '1',
   file_reference_id: file_reference_id
  },
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_delete_file').html();
  $(".error").append(div);
  $('.show_loading_small').hide();
 }).fail(function () {
  alert("File delete failed");
  $('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}

function getAttachmentForm(divId, jsonFileLink) {
 $('#loading').show();
//var org_id = $(".form_table #org_id").val();
 $.ajax({
  url: jsonFileLink,
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (data) {
  var div = $('#add_attachments', $(data)).html();
  $(divId).append(div);
  $('#loading').hide();
  $('li#loading').hide();
 }).fail(function () {
  alert("Attachment loading failed");
  $('#loading').hide();
 });
}

//get the attachement form
function get_attachment_form(jsonFileLink) {
 $("body").on("click", ".attachment_button", function () {
  var closestDiv = $(this).closest("div").attr("id");
  divId = "#" + closestDiv;
  getAttachmentForm(divId, jsonFileLink);
 });
}

//get default values
//get  gl exchange conversion rate
function getExchangeRate(options) {
 var defaults = {
  json_url: 'modules/gl/currency_conversion/json_currency_conversion.php',
  rate_type: $('#exchange_rate_type').val(),
  to_currency: $('#currency').val(),
  from_currency: $('#document_currency').val() ? $('#document_currency').val() : $('#doc_currency').val()
 };
 var settings = $.extend({}, defaults, options);

 if (settings.from_currency == settings.to_currency) {
  $('#exchange_rate').val('1');
  return true;
 }

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   rate_type: settings.rate_type,
   from_currency: settings.from_currency,
   to_currency: settings.to_currency,
   find_exchange_rate: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'rate':
       if (value && value != 'false') {
        var valFixed = (+value).toFixed(7);
        $('#exchange_rate').val(valFixed);
       } else {
        $('#exchange_rate').val('');
       }
       break;
     }
    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//get Supplier details - supplier Sites, addresses etc - supplier_id, afterFunction not mandatory
function getSupplierDetails(jsonurl, org_id, supplier_id, trClass) {
 supplier_id = typeof (supplier_id) !== 'undefined' ? supplier_id : $("#supplier_id").val();
 $('.show_loading_small').show();
 return $.ajax({
  url: jsonurl,
  data: {supplier_id: supplier_id,
   org_id: org_id,
   find_supplier_details: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  $.each(result, function (key, value) {
   switch (key) {
    case 'supplier_site_id':
     if (typeof (trClass) !== 'undefined') {
      $('#content').find(trClass).find('.supplier_site_id').replaceWith(value);
     } else {
      $("#supplier_site_id").replaceWith(value);
     }
     break;

    case 'payment_term_id':
    case 'site_address_id':
     var className = '.' + key;
     $('#content').find(className).val(value);
     break;
   }

  });
  $('.show_loading_small').hide();
 }).fail(function () {
  alert("Supplier Site Loading failed");
  $('.show_loading_small').hide();
 }).always(function () {
  $('.show_loading_small').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

function get_supplier_detail_for_bu(search_all_bu) {
 var all_bu = typeof search_all_bu === 'undefined' ? false : true;
 if ($('#bu_org_id').val()) {
  var bu_org_id = $('#bu_org_id').val();
 } else {
  var bu_org_id = null;
 }
 $("#supplier_id, #supplier_name, #supplier_number").data('last', '').on("blur", function () {
  if ((!all_bu) && !$('#bu_org_id').val()) {
   alert(select_bu_first);
   return;
  }
  var last = $(this).data('last');
  var current = $(this).val();
  if (current !== '' && current !== last) {
   getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id);
  }
  $("#supplier_id, #supplier_name, #supplier_number").each(function () {
   var current = $(this).val();
   $(this).data('last', current);
  });
 });
}

//get Supplier site details - currency, payment terms, attachements
function getSupplierSiteDetails(jsonUrl, supplier_site_id) {
 $('.show_loading_small').show();
 $.ajax({
  url: jsonUrl,
  data: {supplier_site_id: supplier_site_id,
   find_site_details: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  $.each(result, function (key, value) {
   switch (key) {
    case 'currency':
     $("#doc_currency").val(value);
     break;

    case 'payment_term_id':
     var divId = '#' + key;
     $('#content').find(divId).val(value);
     break;
   }
  });
  $('.show_loading_small').hide();
 }).fail(function () {
  alert("Supplier Site Loading failed");
  $('.show_loading_small').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get Customer details - customer Sites, addresses etc
function getCustomerDetails(jsonurl, org_id) {
 $('.show_loading_small').show();
 var ar_customer_id = $("#ar_customer_id").val();
 return $.ajax({
  url: jsonurl,
  data: {ar_customer_id: ar_customer_id,
   org_id: org_id,
   find_all_sites: 1,
   get_customer_details: 1
  },
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  success: function (result) {
   if ($(result).find('div#json_customerSites_find_all').length < 1) {
    $('.show_loading_small').hide();
    return false;
   }
   var customer_sites = $(result).find('div#json_customerSites_find_all').html();
   var receivable_ac_id = $(result).find('div#receivable_ac_id').html();
   var customer_attachment = $(result).find('#customer_header_level_attachement').html();

   var errorMsg = $(result).filter('.errorMsg').html();
   if (customer_sites.length > 5) {
    $("#ar_customer_site_id").replaceWith(customer_sites);
   }
   if (customer_attachment) {
    $("#customer_header_level_attachement").replaceWith(customer_attachment);
   }
   if (receivable_ac_id) {
    $("#receivable_ac_id").val(receivable_ac_id);
   }
   if (errorMsg !== undefined) {
    $(".error").append(errorMsg);
   }
   $('.show_loading_small').hide();
   $('.ship_to_id').getAddressDetails({'address_id': $('#ship_to_id').val()});
   $('.bill_to_id').getAddressDetails({'address_id': $('#bill_to_id').val()});
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function get_customer_detail_for_bu(search_all_bu) {
 var all_bu = typeof search_all_bu === 'undefined' ? false : true;
 if ($('#bu_org_id').val()) {
  var bu_org_id = $('#bu_org_id').val();
 } else {
  var bu_org_id = null;
 }
 $("#ar_customer_id, #customer_name, #customer_number").data('last', '').on("blur", function () {
  if ((!all_bu) && !$('#bu_org_id').val()) {
   alert(select_bu_first);
   return;
  }
  var last = $(this).data('last');
  var current = $(this).val();
  if (current !== '' && current !== last) {
   getCustomerDetails('modules/ar/customer/json_customer.php', bu_org_id);
  }
  $("#ar_customer_id, #customer_name, #customer_number").each(function () {
   var current = $(this).val();
   $(this).data('last', current);
  });
 });
}

//get Customer site details - currency, payment terms, attachements
function getCustomerSiteDetails(jsonUrl, customer_site_id) {
 $('.show_loading_small').show();
 return $.ajax({
  url: jsonUrl,
  data: {ar_customer_site_id: customer_site_id,
   find_site_details: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'payment_term_id':
     case 'ship_to_id':
     case 'bill_to_id':
      var className = '.' + key;
      $('#content').find(className).val(value);
      break;

     case 'currency':
      $('#content').find('.doc_currency').val(value);
      break;
    }

   });
   $('.show_loading_small').hide();
   $('.ship_to_id').getAddressDetails({'address_id': $('#ship_to_id').val()});
   $('.bill_to_id').getAddressDetails({'address_id': $('#bill_to_id').val()});
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//get Subinventories
function getSubInventory(options) {
 var defaults = {
  json_url: 'modules/inv/subinventory/json_subinventory.php',
  org_id: $('#org_id').val(),
  subinventory_class: ('.subinventory_id')
 };
 var settings = $.extend({}, defaults, options);

 $('#loading').show();
 return $.ajax({
  url: settings.json_url,
  data: {
   org_id: settings.org_id,
   find_all_subinventory: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_subinventory_find_all').html();
  if (settings.rowClass_d) {
   $('#content').find(settings.rowClass_d).find(settings.subinventory_class).empty().append(div);
  } else {
   $('#content').find(settings.subinventory_class).empty().append(div);
  }
 }).fail(function () {
  alert(settings.json_url);
//  alert("org name loading failed");
 }).always(function () {
  $('#loading').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get locator name
function getLocator(json_url, subinventory_id, subinventory_type, divClass) {
 $('#loading').show();
 $.ajax({
  url: json_url,
  data: {subinventory_id: subinventory_id,
   find_all_locator: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
//   var div = $('#json_locator', $(data)).html();
  var div = $(result).filter('div#json_locator_find_all').html();
  if (subinventory_type == "from_subinventory_id") {
   $(divClass + " .from_locator_id").find('option').remove();
   $(divClass + " .from_locator_id").empty().append(div);
  }
  if (subinventory_type == "to_subinventory_id") {
   $(divClass + " .to_locator_id").find('option').remove();
   $(divClass + " .to_locator_id").empty().append(div);
  }
  if (subinventory_type == "subinventory") {
   $(divClass).find(".locator_id").find('option').remove();
   $(divClass).find(".locator_id").empty().append(div);
  }

  if (subinventory_type == "oneSubinventory") {
   $('#content').find(".locator_id").find('option').remove();
   $('#content').find(".locator_id").empty().append(div);
  }

  if (subinventory_type == "oneToOneSubinventory") {
   $('#content').find(divClass).find('option').remove();
   $('#content').find(divClass).empty().append(div);
  }

  $('#loading').hide();
 }).fail(function () {
  alert("Locator name loading failed");
  $('#loading').hide();
 });
 $(".form_table .from_locator_id").attr("disabled", false);
}

//fetch all the accounts from inventory details
function getAllInventoryAccounts(jsonUrl, ship_to_inventory, classValue) {
 $('.show_loading_small').show();
 $.ajax({
  url: jsonUrl,
  data: {ship_to_inventory: ship_to_inventory,
   find_account_details: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_inventory_ac_all').html();
  var inv_ap_accrual_ac = $(result).find('div#json_ap_accrual_ac_id').html();
  var inv_ap_accrual_ac_id = $(result).find('div#json_ap_accrual_ac_id').data('ac_id');
  var material_ac = $(result).find('div#json_material_ac_id').html();
  var material_ac_id = $(result).find('div#json_material_ac_id').data('ac_id');
  var inv_ppv_ac = $(result).find('div#json_inv_ppv_ac_id').html();
  var inv_ppv_ac_id = $(result).find('div#json_inv_ppv_ac_id').data('ac_id');
  $(classValue).closest('.tabContainer').find(classValue).find('.combination.charge_ac_id').val(material_ac);
  $(classValue).closest('.tabContainer').find(classValue).find('.combination.accrual_ac_id').val(inv_ap_accrual_ac);
  $(classValue).closest('.tabContainer').find(classValue).find('.combination.ppv_ac_id').val(inv_ppv_ac);
  $(classValue).closest('.tabContainer').find(classValue).find('.coa_combination_id.charge_ac_id').val(material_ac_id);
  $(classValue).closest('.tabContainer').find(classValue).find('.coa_combination_id.accrual_ac_id').val(inv_ap_accrual_ac_id);
  $(classValue).closest('.tabContainer').find(classValue).find('.coa_combination_id.ppv_ac_id').val(inv_ppv_ac_id);
 }).fail(function () {
  alert("Supplier Site Loading failed");
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get WIP Accounting Group
function getWipAccountingGroup(json_url, org_id) {
 $('#loading').show();
 $.ajax({
  url: json_url,
  data: {org_id: org_id,
   find_all_accounting_group: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_accounting_group_find_all').html();
  $(".wip_accounting_group_id").empty().append(div);
  return div;
 }).fail(function () {
  alert("Accounting Group Loading Failed!!!");
 }).always(function () {
  $('#loading').hide();
 });
 $(".form_table .from_subinventory_id").attr("disabled", false);
}

//get Tax Codes
function getTaxCodes(json_url, org_id, in_out_tax, trClass) {
 $('#loading').show();
 $.ajax({
  url: json_url,
  data: {
   org_id: org_id,
   in_out_tax: in_out_tax,
   find_all_tax: 1},
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_tax_code_find_all').html();
  if (in_out_tax === 'IN') {
   if (trClass) {
    $('#content').find(trClass).find(".input_tax").empty().append(div);
   } else {
    $(".input_tax").empty().append(div);
   }
  } else if (in_out_tax === 'OUT') {
   if (trClass) {
    $('#content').find(trClass).find(".output_tax").empty().append(div);
   } else {
    $(".output_tax").empty().append(div);
   }
  }
  return div;
 }).fail(function () {
//  alert("org name loading failed");
 }).always(function () {
  $('#loading').hide();
 });
}

//get Document Type Details
function getDocumentTypeDetails(sd_document_type_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/sd/document_type/json_document_type.php';
 sd_document_type_id = (typeof sd_document_type_id !== 'undefined') ? sd_document_type_id : '1';
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   sd_document_type_id: sd_document_type_id,
   find_document_detail: 1
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'price_list_header_id':
     case 'destination_type':
     case 'supply_source':
      var className = '.' + key;
      $('#content').find(className).val(value);
      break;
    }

   });
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//get Price Details -- rowClass, item_id_m
function getPriceDetails(options) {
 var d = new Date();
 var month = d.getMonth() + 1;
 var day = d.getDate();
 var curernt_date = d.getFullYear() + '-' + (month < 10 ? '0' : '') + month + '-' + (day < 10 ? '0' : '') + day;
 var defaults = {
  json_url: 'modules/mdm/price_list/json_price_list.php',
  price_list_header_id: $('#price_list_header_id').val(),
  price_date: curernt_date
 };
 var settings = $.extend({}, defaults, options);
 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   price_list_header_id: settings.price_list_header_id,
   find_price: 1,
   price_date: settings.price_date,
   item_id_m: settings.item_id_m,
   uom_id: settings.uom_id,
   quantity: settings.quantity
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'unit_price':
       var className = '.' + key;
       $('#content').find(settings.rowClass).find(className).val(value);
       break;
     }
    });
   } else {
    $('#content').find(settings.rowClass).find('.unit_price').val('');
   }

  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getBUDetails(bu_org_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/org/business/json_bu.php';
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   bu_org_id: bu_org_id,
   find_bu_details: 1
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'ledger_id':
      var className = '.' + key;
      $('#content').find(className).val(value);
      break;

     case 'currency':
      var className = '.' + key;
      $('#content').find(className).val(value);
      $('#content').find('.document_currency').val(value);
      $('#content').find('.doc_currency').val(value);
      break;

     case 'period_name_stmt':
      $('#period_id').replaceWith(value);
      break;

     case 'transaction_type' :
      $('#transaction_type').replaceWith(value);
      break;

     case 'output_tax' :
      $('#content').find('.output_tax').replaceWith(value);
      break;
    }

   });
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getLedgerDetails(gl_ledger_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/gl/ledger/json_ledger.php';
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   gl_ledger_id: gl_ledger_id,
   find_ledger_details: 1
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'currency':
      var className = '.' + key;
      $('#content').find(className).val(value);
      $('#content').find('.document_currency').val(value);
      $('#content').find('.doc_currency').val(value);
      break;

     case 'period_name_stmt':
      $('#period_id').replaceWith(value);
      break;

     case 'coa_id' :
      $('#coa_id').val(value);
      break;

     default :
      break;
    }

   });
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getARTransactionTypeDetails(ar_transaction_type_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/ar/transaction_type/json_transaction_type.php';
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   ar_transaction_type_id: ar_transaction_type_id,
   find_ar_transaction_type_detail: 1
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'payment_term_id':
     case 'transaction_class':
      var diId = '#' + key;
      $('#content').find(diId).val(value);
      break;
     case 'period_name_stmt':
      $('#period_id').replaceWith(value);
      break;

     case 'transaction_type' :
      $('#transaction_type').replaceWith(value);
      break;

     case 'receivable_ac' :
      $('#receivable_ac_id').val(value);
      break;
    }

   });
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getOnhandDetails(options) {
 var defaults = {
  json_url: 'modules/inv/onhand/json_onhand.php'
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   item_id_m: settings.item_id_m,
   org_id: settings.org_id,
   subinventory_id: settings.subinventory_id,
   locator_id: settings.locator_id,
   find_onhand_details: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'onhand':
      case 'onhand_id':
      case 'reservable_onhand':
       var className = '.' + key;
       if (settings.trClass) {
        var trClass = settings.trClass;
        if (settings.fieldClass) {
         className += '.' + settings.fieldClass;
        }
        $('#content').find(trClass).find(className).val(value);
       } else {
        $('#content').find(className).val(value);
       }

       break;
     }
    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   $(".error").prepend('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function get_ar_receipt_source_details(bu_org_id, json_url) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/ar/receipt_source/json_receipt_source.php';
 $.ajax({
  url: json_url,
  type: 'get',
  dataType: 'json',
  data: {
   bu_org_id: bu_org_id,
   find_receipt_source_details: 1
  },
  success: function (result) {
   $.each(result, function (key, value) {
    switch (key) {
     case 'receipt_source_stmt':
      $('#ar_receipt_source_id').replaceWith(value);
      break;
    }

   });
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getBPAList(options) {
 var defaults = {
  json_url: 'modules/po/json_po.php',
  bu_org_id: $('#bu_org_id').val(),
  field_name: 'po_number',
  replacing_field: 'po_number',
  trclass: false
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   bu_org_id: settings.bu_org_id,
   supplier_site_id: settings.supplier_site_id,
   item_id_m: settings.item_id_m,
   find_bpa_list: 1
  },
  success: function (result) {
   if (result) {
    if (settings.trclass) {
     var select_stmt = '<select class="select ' + settings.field_name + '" name="' + settings.field_name + '[]" style="max-width:95%;">';
    } else {
     var select_stmt = '<select id="' + settings.field_name + '" class="select ' + settings.field_name + '" name="' + settings.field_name + '[]" style="max-width:95%;">';
    }
    $.each(result, function (f_key, f_name) {
     select_stmt += '<option data-ref_po_line_id="' + f_name.po_line_id + '" value="' + f_name.po_header_id + '">' + f_name.po_number + ' Line ' + f_name.po_line_number + '</option>';
    });
    select_stmt += '</select>';
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     var replacing_field_d = '.' + settings.replacing_field;
     $(trclass_d).find(replacing_field_d).replaceWith(select_stmt);
    } else {
     var replacing_field_id_h = '#' + settings.replacing_field;
     $(replacing_field_id_h).replaceWith(select_stmt);
    }
   } else {
    if (settings.trclass) {
     var select_stmt = '<select class="select ' + settings.field_name + '" name="' + settings.field_name + '[]" style="max-width:95%;">';
    } else {
     var select_stmt = '<select id="' + settings.field_name + '" class="select ' + settings.field_name + '"  name="' + settings.field_name + '[]" style=max-width:95%;">';
    }
    select_stmt += '<option></option>';
    select_stmt += '</select>';
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     var replacing_field_d = '.' + settings.replacing_field;
     $(trclass_d).find(replacing_field_d).replaceWith(select_stmt);
    } else {
     var replacing_field_id_h = '#' + settings.replacing_field;
     $(replacing_field_id_h).replaceWith(select_stmt);
    }
   }
  },
  complete: function () {
   $('.document_header_id').trigger('changeHeader');
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getBPADetails(options) {
 var defaults = {
  json_url: 'modules/po/json_po.php'
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   po_header_id: settings.po_header_id,
   find_bpa_details: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'po_header_id':
      case 'po_type':
      case 'po_status':
       break;

      default :
       var key_h = '#' + key;
       $(key_h).val(value);
       break;
     }
    });
   } else {

   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getBPALineDetails(options) {
 var defaults = {
  json_url: 'modules/po/json_po.php'
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   po_line_id: settings.po_line_id,
   find_bpa_line_details: 1
  },
  success: function (result) {
   if (result) {
    var trClass_d = '.' + settings.trClass;
    $.each(result, function (key, value) {
     switch (key) {
      case 'po_header_id':
      case 'po_line_id':
      case 'po_detail_id':
       break;

      case 'ship_to_id':
       $('#form_line').find(trClass_d).find('.receving_org_id').val(value);
       break;

      default :
       var key_c = '.' + key;
       $('#form_line').find(trClass_d).find(key_c).val(value);
       break;
     }
    });
   } else {

   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getSerialNumber(options) {
 var defaults = {
  json_url: 'modules/inv/serial_number/json_serial_number.php',
  org_id: $('#org_id').val(),
  status: $('#serial_status').val(),
  trclass: false
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   current_org_id: settings.org_id,
   current_subinventory_id: settings.subinventory_id,
   current_locator_id: settings.locator_id,
   status: settings.status,
   item_id_m: settings.item_id_m,
   find_serial_list: 1
  },
  success: function (result) {
   if (result) {
    if (settings.trclass) {
     var select_stmt = '<select class="select inv_serial_number_id" name="inv_serial_number_id[]" style="max-width:95%;">';
    } else {
     var select_stmt = '<select id="inv_serial_number_id" class="select inv_serial_number_id" name="inv_serial_number_id[]" style="max-width:95%;">';
    }
    $.each(result, function (f_key, f_name) {
     select_stmt += '<option data-status="' + f_name.status + '" value="' + f_name.inv_serial_number_id + '">' + f_name.serial_number + '</option>';
    });
    select_stmt += '</select>';
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     $(trclass_d).find('.serial_number').replaceWith(select_stmt);
    } else {
     $('#inv_serial_number_id').replaceWith(select_stmt);
    }
   } else {
//    console.log(result);
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   console.log('No valid serail number found \n' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}


function getCoaStructure(options) {
 var defaults = {
  json_url: 'modules/gl/coa/json_coa.php',
  coa_structure_id: $('#coa_structure_id').val(),
  trclass: false
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   coa_structure_id: settings.coa_structure_id,
   find_coa_structure: 1
  },
  success: function (result) {
   if (result) {
    var count = 1;
    var option_stmt;
    $.each(result, function (f_key, f_name) {
     option_stmt += '<option data-description="' + f_name.description + '" value="' + f_name.option_line_code + '">' + f_name.option_line_value + '</option>';
    });

    $('body').find('.coa_qualifier').each(function () {
     $(this).empty().append(option_stmt);
    });
    $('#no_coa_structure_id').html('');
    $('ul#segment_structure').empty();
    $.each(result, function (f_key, f_name) {
     var field_name = 'field' + count + '[]';
     var field_stmt = '<li><label>Field #: ' + count + '</label>';
     field_stmt += '<select class="select coa_segment fields" name="' + field_name + '" style="max-width:95%;">';
     field_stmt += option_stmt;
     field_stmt += '</select>';
     field_stmt += '</li>';
     $('ul#segment_structure').append(field_stmt);
     count++;
    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getlotNumber(options) {
 var defaults = {
  json_url: 'modules/inv/lot_number/json_lot_number.php',
  org_id: $('#org_id').val(),
  trclass: false
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   org_id: settings.org_id,
   subinventory_id: settings.subinventory_id,
   locator_id: settings.locator_id,
   status: settings.status,
   item_id_m: settings.item_id_m,
   find_lot_list: 1
  },
  success: function (result) {
   if (result) {
    if (settings.trclass) {
     var select_stmt = '<select class="select inv_lot_number_id" name="inv_lot_number_id[]" style="max-width:95%;">';
    } else {
     var select_stmt = '<select id="inv_lot_number_id" class="select inv_lot_number_id" name="inv_lot_number_id[]" style="max-width:95%;">';
    }
    $.each(result, function (f_key, f_name) {
     select_stmt += '<option data-status="' + f_name.status + '" value="' + f_name.inv_lot_number_id + '">' + f_name.lot_number + '</option>';
    });
    select_stmt += '</select>';
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     $(trclass_d).find('.lot_number').replaceWith(select_stmt);
    } else {
     $('#lot_number').replaceWith(select_stmt);
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   $(".error").prepend('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
   $("#accordion").accordion({active: 0});
  }
 });
}
//end of get default values


function beforeSave_serial() {
 var retValue = 1;
 $('.add_detail_values').each(function () {
  if ($(this).children('.serial_generation').val()) {
   var trClass = '.' + $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   var qty = +$('#content').find(trClass).find('.quantity').val();
   var noOfSerialIds = 0;
   $(this).closest('td').find('.inv_serial_number_id').each(function () {
    if ($(this).val()) {
     noOfSerialIds++;
    }
   })

   if (noOfSerialIds != qty) {
    var noOfSerials = 0;
    $(this).closest('td').find('.serial_number').each(function () {
     if ($(this).val()) {
      noOfSerials++;
     }
    })
    if (noOfSerials != qty) {
     alert('Can\'t save data as no of serial numbers doesnt match quantity');
     retValue = -10;
     return false;
    }
   }
  }
 });
 return retValue;
}

function getSerialInStore(orgId) {
 orgId = (typeof orgId !== 'undefined') ? orgId : $('#org_id').val();
 $('#content').on('blur', '.item_number', function () {
  var trClass = $(this).closest("tr").attr('class').replace(/\s+/g, '.');
  var trClass_d = '.' + trClass;
  var generation_type = $('#content').find(trClass_d).find('.serial_generation').val();

  if (!generation_type) {
   var field_stmt = '<input class="textfield serial_number" type="text" size="25" readonly name="serial_number[]" >';
   $('#content').find(trClass_d).find('.inv_serial_number_id').replaceWith(field_stmt);
   $('#content').find(trClass_d).find('.serial_number').replaceWith(field_stmt);
   alert('Item is not serial controlled.\nNo serial informatio \'ll be saved in database');
   return;
  }
  var itemIdM = $('#content').find(trClass_d).find('.item_id_m').val();
  if (!itemIdM) {
   return;
  }

  getSerialNumber({
   'org_id': orgId,
   'status': 'IN_STORE',
   'item_id_m': itemIdM,
   'trclass': trClass,
   'current_subinventory_id': $('#content').find(trClass_d).find('.from_subinventory_id').val(),
   'current_locator_id': $('#content').find(trClass_d).find('.from_locator_id').val()
  });
 });
}


function getViewResult(options) {
 var defaults = {
  json_url: 'extensions/view/json_view.php',
  display_field_id: 'live_display_data',
  query_v: $('#query_v').val(),
  show_from_query: true,
  display_type: $('#display_type').val(),
  no_of_grid_columns: $('#no_of_grid_columns').val(),
  update_result: true
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   query_v: settings.query_v,
   find_result: 1,
   class_name: settings.class_name,
   view_id: settings.view_id,
   pageno: settings.pageno,
   per_page: settings.per_page,
   show_from_query: settings.show_from_query,
   display_type: settings.display_type,
   no_of_grid_columns: settings.no_of_grid_columns,
   filter_data: settings.filterData,
   sort_data: settings.sortData
  },
  success: function (result) {
   if (result) {
    if (settings.update_result) {
     var divHtml = $(result).filter('div#return_divId').html();
     $('.live_display_data').empty().append(divHtml);
     $.getScript("includes/js/reload.js");
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getReportResult(options) {
 var defaults = {
  json_url: $('#home_url').val() + 'extensions/report/json_report.php',
  display_field_id: 'live_display_data',
  query_v: $('#query_v').val(),
  show_from_query: true,
  display_type: $('#display_type').val(),
  no_of_grid_columns: $('#no_of_grid_columns').val(),
  update_result: true
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   query_v: settings.query_v,
   find_result: 1,
   class_name: settings.class_name,
   extn_report_id: settings.extn_report_id,
   pageno: settings.pageno,
   per_page: settings.per_page,
   show_from_query: settings.show_from_query,
   display_type: settings.display_type,
   no_of_grid_columns: settings.no_of_grid_columns,
   filter_data: settings.filterData,
   sort_data: settings.sortData
  },
  success: function (result) {
   if (result) {
    if (settings.update_result) {
     var divHtml = $(result).filter('div#return_divId').html();
     $('.live_display_data').empty().append(divHtml);
     $.getScript("includes/js/reload.js");
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getViewResultByViewId(options) {
 var defaults = {
  json_url: 'extensions/view/json_view.php'
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   viewResultById: true,
   view_id: settings.view_id,
  },
  success: function (result) {
   if (result) {
    if (settings.update_divId_h) {
     var divHtml = $(result).filter('div#return_divId').html();
     $(settings.update_divId_h).empty().append(divHtml);
     $.getScript("includes/js/reload.js");
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getFormPersonalization(options) {
 var defaults = {
  json_url: 'modules/sys/form_personalization/json_fp.php',
  template_code: $('#template_code').val(),
  obj_class_name: $('#obj_class_name').val()
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'post',
  data: {
   get_fp_from_form: true,
   template_code: settings.template_code,
   obj_class_name: settings.obj_class_name
  },
  success: function (result) {
   if (result) {
    var divHtml = '<div id="form_data">' + $(result).filter('div#return_divId').html() + '</div>';
    $('#form_data').empty().append(divHtml);
    $.getScript("includes/js/reload.js");
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getReportResultByReportId(options) {
 var defaults = {
  json_url: 'extensions/report/json_report.php'
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   viewReportById: true,
   extn_report_id: settings.report_id
  },
  success: function (result) {
   if (result) {
    if (settings.update_divId_h) {
     var divHtml = $(result).filter('div#return_divId').html();
     $(settings.update_divId_h).empty().append(divHtml);
     $.getScript("includes/js/reload.js");
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function viewResultWith_pagination() {
 $('body').on('click', '.ajax_view.pagination .page_nos a', function (e) {
  e.preventDefault();
  var link = $(this).attr('href');
  var class_name = getUrlValues('class_name', link);
  var view_id = getUrlValues('view_id', link);
  var pageno = getUrlValues('pageno', link);
  var per_page = getUrlValues('per_page', link);
  var filterData = $(this).closest('div.view_content').find('.view_filters').find('.filtered_field:input').serializeArray();
  var sortData = $(this).closest('div.view_content').find('.view_filters').find('.sorted_field:input').serializeArray();
  //calling the ajax function
  getViewResult({
   class_name: class_name,
   view_id: view_id,
   pageno: pageno,
   per_page: per_page,
   show_from_query: false,
   filterData: filterData,
   sortData: sortData
  });
 });

 $('body').on('click', '.ajax_view.pagination .content_per_page', function (e) {
  e.preventDefault();
  var link = $(this).closest('.pagination').find('a').first().attr('href');
  var class_name = getUrlValues('class_name', link);
  var view_id = getUrlValues('view_id', link);
  var pageno = getUrlValues('pageno', link);
  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
  var filterData = $(this).closest('div.view_content').find('.view_filters').find('.filtered_field:input').serializeArray();
  var sortData = $(this).closest('div.view_content').find('.view_filters').find('.sorted_field:input').serializeArray();
  //calling the ajax function
  getViewResult({
   class_name: class_name,
   view_id: view_id,
   pageno: pageno,
   per_page: per_page,
   show_from_query: false,
   filterData: filterData,
   sortData: sortData
  });
 });
}

function getSearchResult(options) {
 var defaults = {
  json_url: 'includes/json/json_search.php',
  className: $('.search.class_name').val(),
  searchParameters: $('#generic_search_form').find(":input").filter(function () {
   return !!this.value;
  }).serializeArray(),
  pageno: 1,
  per_page: 0
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   class_name: settings.className,
   search_parameters: settings.searchParameters,
   pageno: settings.pageno,
   per_page: settings.per_page
  },
  beforeSend: function () {
   $('#overlay').css('display', 'block');
  },
  complete: function () {

  }
 }).done(function (result) {
  var newContent = $(result).find('div#searchResult').html();
  $('#searchResult').empty().append(newContent);

  $.getScript("includes/js/reload.js").done(function () {
   $('#overlay').css('display', 'none');
   $('.show_loading_small').hide();
  });
 }).fail(function () {
  alert("Search Failed");
  $('#overlay').css('display', 'none');
 });
}


function getSelectResult(options) {
 var defaults = {
  json_url: 'includes/json/json_select.php',
  className: $('.search.class_name').val(),
  searchParameters: $('#select_page').find(":input").filter(function () {
   return !!this.value;
  }).serializeArray(),
  pageno: 1,
  per_page: 0
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   class_name: settings.className,
   search_parameters: settings.searchParameters,
   pageno: settings.pageno,
   per_page: settings.per_page
  },
  beforeSend: function () {
   $('#overlay').css('display', 'block');
  },
  complete: function () {

  }
 }).done(function (result) {
  var newContent = $(result).find('div#selectResult').html();
  $('#selectResult').empty().append(newContent);
  $.getScript("includes/js/reload.js").done(function () {
   $('#overlay').css('display', 'none');
   $('.show_loading_small').hide();
  });
 }).fail(function () {
  alert("Search Failed");
  $('#overlay').css('display', 'none');
 });
}

function getSiteSearchResult(options) {
 var defaults = {
  json_url: 'includes/json/json_site_search.php',
//  className: $('.search.class_name').val(),
  searchParameters: $('#site_search').find(":input").serializeArray(),
  pageno: 1,
  per_page: 0
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
//   class_name: settings.className,
   search_parameters: settings.searchParameters,
   pageno: settings.pageno,
   per_page: settings.per_page
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var newContent = $(result).filter('#json_search_result').html();
  $('#structure').replaceWith('<div id="structure">' + newContent + '</div>');
//  $.getScript("includes/js/reload.js");
 }).fail(function () {
  alert("Search Failed");
 });
}


function getMultiSelectResult(options) {
 var defaults = {
  json_url: 'includes/json/json_multi_select.php',
  className: $('.search.class_name').val(),
  actionclassName: $('.action_class_name').val(),
  action: $('.action').val(),
  searchParameters: $('#generic_search_form').find(":input").serializeArray(),
  pageno: 1,
  per_page: 0
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   search_class_name: settings.className,
   action_class_name: settings.actionclassName,
   action: settings.action,
   search_parameters: settings.searchParameters,
   pageno: settings.pageno,
   per_page: settings.per_page
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var allButton = $(result).filter('div#header_top_container').html();
  var newContent = $(result).find('div#searchResult').html();

  if (newContent) {
   $('#header_top_container').replaceWith('<div id="header_top_container">' + allButton + '</div>');
  }
  $('#searchResult').empty().append(newContent);
  var pagination = $(result).find('div#pagination').html();
  if (pagination) {
   $('#pagination').empty().append(pagination);
  }
  $.getScript("includes/js/reload.js");
  $.getScript("includes/js/multi_select.js");
  $(result).find('#js_files').find('li').each(function () {
   $.getScript($(this).html());
  });
  $(result).find('ul#css_files').find('li').each(function () {
   var filePath = $(this).html();
   if (!$("link[href='" + filePath + "']").length) {
    $('<link href="' + filePath + '" rel="stylesheet">').appendTo("head");
   }
  });
  $('.hideDiv_input').trigger('click');
 }).fail(function () {
  alert("Search Failed");
 });
}

function getSvgImage(options) {
 var defaults = {
  json_url: 'includes/json/json_svgimage.php',
  display_field_class: 'svg_image',
  query_v: $('#query_v').val(),
  chart_type: $('#chart_type').val(),
  chart_label: $('#chart_label').val(),
  chart_value: $('#chart_value').val(),
  chart_name: $('#view_name').val(),
  chart_width: $('#chart_width').val(),
  chart_height: $('#chart_height').val(),
  chart_legend: $('#chart_legend').val(),
  chart_legend2: $('#chart_legend2').val(),
  update_image: true
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  datatype: 'image/svg+xml',
  data: {
   query_v: settings.query_v,
   find_result: 1,
   class_name: settings.class_name,
   view_id: settings.view_id,
   chart_type: settings.chart_type,
   chart_label: settings.chart_label,
   chart_value: settings.chart_value,
   chart_name: settings.chart_name,
   chart_width: settings.chart_width,
   chart_height: settings.chart_height,
   chart_legend: settings.chart_legend,
   chart_legend2: settings.chart_legend2,
   filter_data: settings.filterData,
   sort_data: settings.sortData,
   extn_report_id: settings.extn_report_id
  },
  success: function (result) {
   if (result) {
    if (settings.update_image) {
     $('.svg_image').empty().append(result);
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getItemRevision(options) {
 var defaults = {
  json_url: 'modules/inv/item/revision/json_item_revision.php',
  org_id: $('#org_id').val(),
  trclass: false,
  show_date: false
 };
 var settings = $.extend({}, defaults, options);
 if (!settings.item_id_m) {
  return;
 }
 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   org_id: settings.org_id,
   item_id_m: settings.item_id_m,
   find_revision: 1
  },
  success: function (result) {
   if (result) {
    if (settings.trclass) {
     var select_stmt = '<select name="revision_name[]" class="from_array select revision_name">';
    } else {
     var select_stmt = '<select id="revision_name" class="select revision_name medium" name="revision_name[]" style="max-width:95%;">';
    }
    $.each(result, function (f_key, f_name) {
     if (settings.show_date) {
      select_stmt += '<option data-effective_start_date="' + f_name.effective_start_date + '" value="' + f_name.revision_name + '">' + f_name.revision_name + ' - ' + f_name.effective_start_date + '</option>';
     } else {
      select_stmt += '<option data-effective_start_date="' + f_name.effective_start_date + '" value="' + f_name.revision_name + '">' + f_name.revision_name + '</option>';
     }
    });
    select_stmt += '</select>';
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     $(trclass_d).find('.revision_name').replaceWith(select_stmt);
    } else {
     $('#revision_name').replaceWith(select_stmt);
    }
   } else {
    if (settings.trclass) {
     var trclass_d = '.' + settings.trclass;
     $(trclass_d).find('.revision_name').children().remove();
    } else {
     $('#revision_name').children().remove();
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getDBReportList(options) {
 var defaults = {
  json_url: 'extensions/ino_user/dashboard/config/json_dbconfig.php',
  report_type: 'block',
  update_data: true
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   report_type: settings.report_type,
   find_report_list: 1
  },
  success: function (result) {
   if (result) {
    var trClass = settings.trClass;
    var trClass_d = '.' + trClass.replace(/\s+/g, '.');
    var newContent = $(result).filter('div#return_divId').html();
    if (settings.update_data) {
     $(trClass_d).find('.report_id').empty().append(newContent);
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function printLabel(options) {
 var defaults = {
  json_url: 'modules/bc/static_label/json_static_label.php',
  org_id: $('#org_id').val(),
  subinventory_id: $('#subinventory_id').val(),
  item_id: $('#item_id').val(),
  bc_static_label_id: $('#bc_static_label_id').val()
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   org_id: settings.org_id,
   subinventory_id: settings.subinventory_id,
   locator_id: settings.locator_id,
   status: settings.status,
   item_id_m: settings.item_id_m,
   print_label: 1,
   bc_static_label_id: settings.bc_static_label_id,
   print_parameters: settings.print_parameters
  },
  success: function (result) {
   if (result) {
    var divContent = $(result).filter('div#ret_message').html();
    $('.error').append(divContent);
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//show Default Dialog Box 
function show_dialog_box() {
 $("#dialog_box").dialog({
  dialogClass: "no-close",
  modal: true,
  minWidth: 600,
  title: "Action Message",
  buttons: [
   {
    text: "OK",
    class: 'button btn btn-info btn-done',
    click: function () {
     $(this).dialog("close");
    }
   }
  ],
  closeOnEscape: true,
  position: {my: "center center", at: "center bottom", of: "#structure "}
 });
}

function getPayrollSchedules(options) {
 var defaults = {
  min_length: 3,
  hr_payroll_schedule_id: 'hr_payroll_schedule_id',
  json_url: 'modules/hr/payroll/json_payroll.php',
  hr_payrollId: $('#hr_payroll_id').val()
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   find_payroll_schedules: 1,
   hr_payroll_id: settings.hr_payrollId
  },
  success: function (result) {
   if (result) {
    if (settings.trDivId) {
     var select_stmt = '<select class="select hr_payroll_schedule_id" name="hr_payroll_schedule_id[]" style="max-width:95%;">';
    } else {
     var select_stmt = '<select id="hr_payroll_schedule_id" class="select hr_payroll_schedule_id" name="hr_payroll_schedule_id[]" style="max-width:95%;">';
    }
    $.each(result, function (f_key, f_name) {
     select_stmt += '<option value="' + f_name.hr_payroll_schedule_id + '">' + f_name.scheduled_date + ' : ' + f_name.period_name + '</option>';
    });
    select_stmt += '</select>';
    if (settings.trDivId) {
     var select_class_d = '.' + settings.trDivId;
     $(select_class_d).replaceWith(select_stmt);
    } else {
     $('#hr_payroll_schedule_id').replaceWith(select_stmt);
    }
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function enableLineForSaveAfterFieldChange() {
 //enable lines with change data for save
 $('#content').data('last', '').on("blur", ':input', function () {
  var last = $(this).data('last');
  var current = $(this).val();
  if ($(this).parent().prop('tagName') === 'TD') {
   if (current && current !== '' && current !== last) {
    var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
    var detail_line_cb = $('#content').find(trClass).find('input[name="line_id_cb"],input[name="detail_id_cb"]');
    if (detail_line_cb) {
     $('#content').find(trClass).find('input[name="line_id_cb"],input[name="detail_id_cb"]').prop('checked', true);
     $('#content').find('input[name="detail_id_cb"]:checked').each(function () {
      $(this).closest('td.add_detail_values').closest('tr').find('input[name="line_id_cb"]').prop('checked', true);
     });
    }
   }

  }
 });
}

function openNextGLPeriod(options) {
 var defaults = {
  json_url: 'modules/gl/period/json_period.php',
  new_gl_calendar_id: $('#new_gl_calendar_id').val(),
  new_gl_calendar_name: $('#new_gl_calendar_id :selected').text(),
  ledger_id: $('#gl_ledger_id').val()
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   new_gl_calendar_id: settings.new_gl_calendar_id,
   ledger_id: settings.ledger_id,
   open_next_gl_period: 1
  },
  success: function (result) {
   if (result) {
    $(".error").prepend(result);
    $("#accordion").accordion({active: 0});
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getOpenPeriodsFromLedgerId(options) {
 var defaults = {
  json_url: 'modules/gl/period/json_period.php',
  gl_ledger_id: $('#gl_ledger_id').val(),
  trclass: false
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   gl_ledger_id: settings.gl_ledger_id,
   find_open_periods: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'period_name_stmt':
       $('#gl_period_id').replaceWith(value);
       break;

      default :
       break;
     }

    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//report
function getReportResult_i(filterData, sortData) {
 if (typeof filterData === 'undefined') {
  filterData = $('.extn_report_filters').find('.filtered_field:input').serializeArray();
 }
 if (typeof sortData === 'undefined') {
  sortData = $('.extn_report_filters').find('.sorted_field:input').serializeArray();
 }
 getReportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $('#extn_report_id').val(),
  show_from_query: false
 });
}

$.fn.getReportResult_e = function (options) {
 var thisElement = $(this);
 var filterData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.filtered_field:input').serializeArray();
 var sortData = $(this).closest('div.extn_report_content').find('.extn_report_filters').find('.sorted_field:input').serializeArray();
 $.when(getReportResult({
  filterData: filterData,
  sortData: sortData,
  extn_report_id: $(this).closest('div.extn_report_content').find('.extn_report_id').val(),
  show_from_query: false,
  update_result: false
 })).then(function (data, textStatus, jqXHR) {
  var divHtml = $(data).filter('div#return_divId').html();
  $(thisElement).closest('div.extn_report_content').find('.live_display_data').empty().append(divHtml);
  $.getScript("includes/js/reload.js");
 });
 return this;
};

//POS Terminal Number
function save_posTerminalName(options) {
 var defaults = {
  json_url: 'modules/pos/transaction/json_pos_transaction.php',
  terminal_name: $('#terminal_name').val()
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   terminal_name: settings.terminal_name,
   save_terminal_name: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'result':
       alert(value);
       break;

      default :
       break;
     }

    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

//Save ratings
function save_ratings(options) {
 var defaults = {
  json_url: 'extensions/rating/json_rating.php',
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   rating: settings.rating,
   reference_table: settings.reference_table,
   reference_id: settings.reference_id,
   save_ratings: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'result':
       alert(value);
       break;

      default :
       break;
     }

    });
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function save_dataInSession(options) {
 var defaults = {
  json_url: 'includes/json/json_session.php',
  openUrl: false,
  over_write: true
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'post',
  data: {
   data_name: settings.data_name,
   data_value: settings.data_value,
   save_dataInSession: 1,
   over_write: settings.over_write,
   remove_data: settings.remove_data
  },
  success: function () {
   if (settings.openUrl !== false) {
    var openUrl = 'form.php?class_name=sd_pick_list_v&mode=2&window_type=popup';
    void window.open(openUrl, '_blank',
            'width=1200,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}


function getFilesList(options) {
 var defaults = {
  json_url: 'extensions/folder/json_folder.php'
 };
 var settings = $.extend({}, defaults, options);

 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   extn_folder_id: settings.extn_folder_id,
   find_files: 1
  },
  success: function (result) {
   $('tbody#folder-content').empty();
   if (result) {
    var body_stmt = '';
    $.each(result, function (f_key, f_name) {
     var file_lnik = '<a href="'+ f_name.file_path + f_name.file_name +'">' + f_name.file_name + '</a>';
     body_stmt += '<tr>';
     body_stmt += '<td>' + f_name.org + '</td>';
     body_stmt += '<td>' + f_name.reference_table + '</td>';
     body_stmt += '<td>' + f_name.reference_id + '</td>';
     body_stmt += '<td>' + file_lnik + '</td>';
     body_stmt += '<td>' + f_name.creation_date + '</td>';
     body_stmt += '<td>' + f_name.description + '</td>';
     body_stmt += '</tr>';
    });
    
   $('tbody#folder-content').replaceWith('<tbody id="folder-content">' + body_stmt + '</tbody>');
   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   $(".error").prepend('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
   $("#accordion").accordion({active: 0});
  }
 });
}

//get SelectOptionsForExpense
function getSelectOptionsForExpense(options) {
 var defaults = {
  json_url: 'modules/hr/expense/json_expense.php',
  expense_template_id: $('#expense_template_id').val()
 };
 var settings = $.extend({}, defaults, options);
 $('#loading').show();
 return $.ajax({
  url: settings.json_url,
  data: {
   expense_template_id: settings.expense_template_id,
   find_expense_details: 1
  },
  type: 'get',
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  complete: function () {
   $('.show_loading_small').hide();
  }
 }).done(function (result) {
  var div = $(result).filter('div#expense_template_details').html();
  $('#content').find('.expense_type').empty().append(div);
//  console.log(div);
 }).fail(function () {
//  alert("org name loading failed");
 }).always(function () {
  $('#loading').hide();
 });
}

//get expense perdiem rate
function getPerDiemRate(options) {
 var d = new Date();
 var month = d.getMonth() + 1;
 var day = d.getDate();
 var curernt_date = d.getFullYear() + '-' + (month < 10 ? '0' : '') + month + '-' + (day < 10 ? '0' : '') + day;
 var defaults = {
  json_url: 'modules/hr/perdiem_rate/json_perdiem_rate.php',
  hr_employee_id: $('#hr_employee_id').val(),
  price_date: curernt_date
 };
 var settings = $.extend({}, defaults, options);
 return $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   hr_location_id: settings.hr_location_id,
   find_perdiem_rate: 1,
   price_date: settings.price_date,
   hr_employee_id: settings.hr_employee_id
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'rate':
       var className = '.' + key;
       $('#content').find(settings.rowClass).find(className).val(value);
       break;
     }
    });
   } else {
    $('#content').find(settings.rowClass).find('.per_diem_rate').val('');
   }

  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function refreshData(options) {
 var defaults = {
  json_url: 'includes/json/json_refresh.php'
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   data_type: settings.data_type,
   refresh_data: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     switch (key) {
      case 'string_data':
       var dataString = value;
       if (settings.divId) {
        var idName = '#' + settings.divId;
        $('body').find(idName).empty().append(dataString);
       }

       break;
     }
    });
   } else {

   }
  },
  complete: function () {
   $('.show_loading_small').hide();
  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  }
 });
}

function getUserMessages(options) {
 var defaults = {
  json_url: 'extensions/emessage/json_emessage.php',
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  data: {
   extn_emessage_header_id: settings.extn_emessage_header_id,
   current_user_id: settings.current_user_id,
   extn_emessage_line_id: settings.extn_emessage_line_id
  },
  complete: function () {

  }
 }).done(function (result) {
  var oldHeight = $('#chat-content-internal').height();
  $("#chat-content").animate({scrollTop: newHeight}, 'normal');
  var newContent = $(result).filter('div#new_msg_content').html();
  if (!settings.extn_emessage_line_id) {
   $('#chat-content-internal').replaceWith('<div id="chat-content-internal">' + newContent + '</div>');
  } else {
   console.log(settings.extn_emessage_line_id);
   $('#chat-content-internal').prepend(newContent);
  }

  var newHeight = $('#chat-content-internal').height();
  if (newHeight > oldHeight) {
   $("#chat-content").animate({scrollTop: newHeight}, 'normal');
  }

 }).fail(function () {
  alert("Message Loading Failed");
  $('#overlay').css('display', 'none');
 });
}

function sleep(milliseconds) {
 var start = new Date().getTime();
 for (var i = 0; i < 1e7; i++) {
  if ((new Date().getTime() - start) > milliseconds) {
   break;
  }
 }
}

//end of global functions
$(document).ready(function () {
 var homeUrl = $('#home_url').val();
 $('.non_clickable').on('click', function (e) {
  e.preventDefault();
 });


 $('#loading').hide();
 $('.show_loading_small').hide();

 viewResultWith_pagination();
 //show & remove select search icon
 $('.select_popup').hide();
 $('#content').on('focusin', 'input', function () {
  $('#content').find('.select_popup').hide();
  $(this).parent().find('.select_popup').show();
//  if ($(this).parent().find('.select_popup').length > 0) {
//   $(this).parent().find('.select_popup').show();
//   $(this).css('width', '80%');
//   localStorage.setItem("change_field_width", true);
//   var parent =$(this).parent();
//   localStorage.setItem("change_field_width", true);
//  }
 });

// .on('focusout', parent, function () {
//  if (localStorage.getItem("change_field_width") == 'true') {
//   $(this).css('width', '125%');
//   localStorage.setItem("change_field_width", false);
//  }
// });
// 


 if ($('#display_comment_form').length > 0) {
  $('#display_comment_form').html($('#commentForm_witoutjs').html());
  $('#commentForm_witoutjs').html('');
 }

 $('body').on('click', '.content_per_page', function (e) {
  var currentUrl = window.location.toString();
  var newURL = currentUrl.replace(/per_page=/g, '');
  newURL = newURL.replace(/&&/g, '&');
  if (newURL.indexOf('?') > -1) {
   newURL = newURL + '&per_page=' + $(this).closest('div').find('select').val();
  } else {
   newURL = newURL + '?per_page=' + $(this).closest('div').find('select').val();
  }
  $(this).attr('href', newURL);
 });

//enable lines with change data for save
 enableLineForSaveAfterFieldChange();


//hiding the loader
 var $loader = $('#loading'), timer;
 $loader.hide().ajaxStart(function ()
 {
  timer && clearTimeout(timer);
  timer = setTimeout(function ()
  {
   $loader.show();
  },
          10000);
 }).ajaxStop(function ()
 {
  clearTimeout(timer);
  $loader.hide();
 });

//select page data selction in parent window
 $('body').on('click', '#selectResult_page .quick_select', function () {
  var useOpenerFunc = false;
  if (typeof opener.setValFromSelectPage === 'function') {
   var setData = new opener.setValFromSelectPage;
   useOpenerFunc = true;
  }

  var selectedData = [];
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'LI') {
   $(this).closest('ul').find('input').each(function () {
    if (useOpenerFunc) {
     setData[$(this).data('field_name')] = $(this).prop('value');
    }
    var selectedData_obj = {};
    selectedData_obj.field_name = $(this).data('field_name');
    selectedData_obj.field_value = $(this).prop('value');
    selectedData.push(selectedData_obj);
   });
  } else {
   var trCLass = $(this).closest('tr').prop('class');
   var trCLass_d = '.' + trCLass.replace(/\s+/g, '.');
   $(trCLass_d).find('td').each(function () {
    if (useOpenerFunc) {
     setData[$(this).data('field_name')] = $(this).text();
    }
    var selectedData_obj = {};
    selectedData_obj.field_name = $(this).data('field_name');
    selectedData_obj.field_value = $(this).text();
    selectedData.push(selectedData_obj);
   });
  }

  if (localStorage.getItem("close_field_class") !== null) {
   var close_field_class = localStorage.getItem("close_field_class");
   if (localStorage.getItem("close_div_class") !== null) {
    var close_div_class = localStorage.getItem("close_div_class");
   }
   var opener_elemenType = window.opener.$(close_field_class).parent().prop('tagName');
   if (opener_elemenType === 'LI') {
    $(selectedData).each(function (i, currentData) {

     $(currentData).each(function (k, v) {
      if (v.field_name !== 'undefined') {
       var field_d = '.' + v.field_name;
       console.log(' field_d : ' + field_d + ' v.field_value ' + v.field_value);
       if (localStorage.getItem("set_value_for_one_field") !== null) {
        window.opener.$(close_field_class).parent().find(field_d).val(v.field_value);
//        console.log(field_d + ' : ' +  close_field_class + ' :: ' +  v.field_value);
       } else if (localStorage.getItem("set_value_for_one_div") !== null) {
        window.opener.$(close_div_class).find(field_d).val(v.field_value);
//        console.log(field_d + ' : ' +  close_field_class + ' :: ' +  v.field_value);
       } else {
        console.log('3 field_d : ' + field_d + ' v.field_value ' + v.field_value + 'close_field_class is ' + close_field_class);
        window.opener.$(close_field_class).closest('.tabContent').find(field_d).val(v.field_value);
       }
      }
     });
    });
//    window.opener.$(close_field_class).val($(this).data('select_field_value'));
   } else {
    var rowClass = '.' + localStorage.getItem("row_class").replace(/\s+/g, '.');
    $(selectedData).each(function (i, currentData) {
     $(currentData).each(function (k, v) {
      if (v.field_name !== 'undefined') {
       var field_d = '.' + v.field_name;
       if (localStorage.getItem("set_value_for_one_field") !== null) {
        window.opener.$(rowClass).find(close_field_class).parent().find(field_d).val(v.field_value);
       } else {
        window.opener.$(rowClass).find(field_d).val(v.field_value);
       }
      }
     });
    });
   }
   localStorage.removeItem("close_field_class");
  } else {
   if (useOpenerFunc) {
    setData.setVal();
    if (opener.setPopUpValue) {
     opener.setPopUpValue(setData);
    }
   }
  }

  localStorage.removeItem("set_value_for_one_field");
  localStorage.removeItem("set_value_for_one_div");
  localStorage.removeItem("field_class");
  localStorage.removeItem("reset_link");
  window.close();

  if (localStorage.getItem("auto_refresh_class") !== null) {
   window.opener.$(localStorage.getItem("auto_refresh_class")).trigger('click');
  }
  window.opener.$('#content').trigger('setInoVal');
 });

 $('body').on('click', '#selectResult_page .popover_quick_select', function (e) {
  e.preventDefault();
  var select_field = $(this).data('select_field');
  var select_field_d = '.' + select_field;
  var select_field_val = $(this).data('select_field_value');
  $('#erp_form_area').find(select_field_d).val(select_field_val);
  var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  var primary_column_id_t = primary_column_id.trim();
  var select_field_t = select_field.trim();
  if (primary_column_id_t == select_field_t) {
   $('#big_popover').trigger('click');
   $('a.show' + select_field_d).trigger('click');
  } else {
   $('#big_popover').trigger('click');
  }
 });

 $('body').on('click', '.make-draggable', function () {
  $(this).closest('div').draggable();
 });

 //search reset button
 var link = localStorage.getItem("reset_link");
 if (link) {
  $('#multi_select a#search_reset_btn').on('click', function () {
   $(this).attr('href', link);
  });
 }

 var reset_link_ofSelect = localStorage.getItem("reset_link_ofSelect");
 if (reset_link_ofSelect) {
  $('#select_page a#search_reset_btn').on('click', function () {
   $(this).attr('href', reset_link_ofSelect);
  });
 }

 //new object
 $('body').on('click', '#new_object_button', function (e) {
  e.preventDefault();
  $('#content').find(' :input').not('#attach_submit, .button, .search').val('');
  $('#content').find(' :input').not('#attach_submit').prop('disabled', false);
  $('#content').find(' :checkbox').prop('checked', false);
 });

 remove_row();

 $('.select_account').inoAutoCompleteElement({
  json_url: 'modules/gl/coa_combination/coa_search.php',
  primary_column1: 'coa_id',
  set_value_for_one_field: true
 });

 $('body').on('blur', '.select_account.account_combination', function () {
  if (!$(this).val()) {
   $(this).parent().find(':input').each(function () {
    $(this).val('');
   })
  }
 })

 var supplierName = new autoCompleteMain();
 supplierName.json_url = 'modules/ap/supplier/json_supplier.php';
 supplierName.primary_column1 = 'bu_org_id';
 supplierName.select_class = 'select_supplier_name';
 supplierName.extra_elements = ['supplier_id', 'supplier_number'];
 supplierName.min_length = 3;
 supplierName.autoComplete();

 $('.select_customer_name').inoAutoCompleteElement({
  json_url: 'modules/ar/customer/json_customer.php',
  primary_column1: 'bu_org_id'
 });

 //vaidation field auto complete
 $('.val_field').inoAutoCompleteElement({
  json_url: 'includes/json/json_validation_field.php',
  primary_column1: 'bu_org_id',
  min_length: 2
 });


 var itemNumber = new autoCompleteMain();
 itemNumber.json_url = 'modules/inv/item/item_search.php';
 itemNumber.select_class = 'select_item_number';
 itemNumber.primary_column1 = 'org_id';
 itemNumber.extra_elements = ['item_id', 'item_id_m', 'item_description', 'uom_id', 'processing_lt', 'lot_generation', 'serial_generation', 'kit_cb'];
 itemNumber.min_length = 2;
 itemNumber.autoComplete();

 $('.select_item_number_all').inoAutoCompleteElement({
  json_url: 'modules/inv/item/json_item.php',
  primary_column1: 'org_id'
 });




 //auto complete for allowed BOM
 var itemNumber = new autoCompleteMain();
 itemNumber.json_url = 'modules/inv/item/item_search.php';
 itemNumber.select_class = 'select_item_number_allowedBOM';
 itemNumber.primary_column1 = 'org_id';
 itemNumber.extra_elements = ['item_id', 'item_id_m', 'item_description', 'uom_id', 'processing_lt', 'lot_generation', 'serial_generation'];
 itemNumber.min_length = 2;
 itemNumber.options = {bom_enabled_cb: "1"};
 itemNumber.autoComplete();

 $('#form_line').on('blur', '.textfield.select_item_number', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var trClass = '.' + $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   if ($('#form_line').find(trClass).find('.serial_generation').val()) {
    $('#form_line').find(trClass).find('.serial_number').attr('required', true).css('background-color', 'pink');
   }
   if ($('#form_line').find(trClass).find('.lot_generation').val()) {
    $('#form_line').find(trClass).find('.lot_number').attr('required', true).css('background-color', 'pink');
   }
  }
 });

 //popu for selecting employee
 $('#content').on('click', '.select_employee_name.select_popup', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_employee_name').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.removeItem("li_divId", liId);
  } else {
   var liId = $(this).closest('li').find('.employee_name').prop('id');
   localStorage.setItem("li_divId", liId);
   localStorage.removeItem("row_class");
  }

  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=hr_employee_v';
  if ($(this).siblings('.org_id').val()) {
   openUrl += '&org_id=' + $(this).siblings('.org_id').val();
  } else if ($('#org_id').val()) {
   openUrl += '&org_id=%3D' + $('#org_id').val();
  }

  if ($(this).siblings('.employee_name').val()) {
   openUrl += '&employee_name=' + $(this).siblings('.employee_name').val();
  }
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popu for selecting user
 $('#content').on('click', '.select_username.select_popup', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_username').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.removeItem("li_divId", liId);
  } else {
   var liId = $(this).closest('li').find('.username').prop('id');
   localStorage.setItem("li_divId", liId);
   localStorage.removeItem("row_class");
  }

  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=user';

  if ($(this).siblings('.username').val()) {
   openUrl += '&username=' + $(this).siblings('.username').val();
  }
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popu for selecting any generic class
 $('#content').on('click', '.generic.select_popup', function () {
  if ($(this).is('.readonly, .always_readonly ')) {
   return false;
  }
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.removeItem("li_divId", liId);
  } else {
   var liId = $(this).closest('li').find("input[type!='hidden']").prop('id');
   localStorage.setItem("li_divId", liId);
   localStorage.removeItem("row_class");
  }
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  if ($(this).hasClass('set_value_for_one_field')) {
   localStorage.setItem("set_value_for_one_field", true);
  }

  if ($(this).hasClass('getform')) {
   localStorage.setItem("auto_refresh_class", 'a.show');
  } else {
   localStorage.setItem("auto_refresh_class", null);
  }

  var select_class_name = $(this).data('class_name');
  var openUrl = 'select.php?class_name=' + select_class_name;
  $(this).parent().parent().find('.popup_value').each(function () {
   var dataName = $(this).prop('name').replace(/\[]+/g, '');
   openUrl += '&' + dataName + '=' + $(this).val();
  });
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


//popu for selecting accounts
 $('body').on('click', '.select_account.select_popup', function () {
  var ulink = 'select.php?class_name=coa_combination';
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.account_popup').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.setItem("field_class", fieldClass);
   if ($(this).closest('td').find('input').data('ac_type')) {
    ulink += 'ac_type=' + $(this).closest('td').find('input').data('ac_type');
   }
  } else {
   var liId = $(this).closest('li').find('.select_account').prop('id');
   localStorage.setItem("li_divId", liId);
   if ($(this).closest('li').find('select_account').data('ac_type')) {
    ulink += 'ac_type=' + $(this).closest('td').find('input').data('ac_type');
   }
  }
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  localStorage.setItem("set_value_for_one_field", true);

  void window.open(ulink, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(ulink, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');

 });

 //popu for selecting items
 $('body').on('click', '.select_item_number.select_popup', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.setItem("field_class", fieldClass);
  } else {
   var liId = $(this).closest('li').find('.item_number').prop('id');
   localStorage.setItem("li_divId", liId);
  }
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=item';
  if ($(this).siblings('.org_id').val()) {
   openUrl += '&org_id=' + $(this).siblings('.org_id').val();
  } else if ($('#org_id').val()) {
   openUrl += '&org_id=%3D' + $('#org_id').val();
  }
  if ($(this).siblings('.item_number').val()) {
   openUrl += '&item_number=' + $(this).siblings('.item_number').val();
  }
  $(this).parent().parent().find('.popup_value').each(function () {
   var dataName = $(this).prop('name').replace(/\[]+/g, '');
   openUrl += '&' + dataName + '=' + $(this).val();
  });

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#content').on('click', '.select_item_number_only.select_popup', function () {
  var rowClass = $(this).closest('tr').prop('class');
  var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
  localStorage.setItem("row_class", rowClass);
  localStorage.setItem("field_class", fieldClass);
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=item_select';
  if ($(this).siblings('.item_number').val()) {
   openUrl += '&item_number=' + $(this).siblings('.item_number').val();
  }
  localStorage.setItem("set_value_for_one_field", true);

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //popu for selecting serial_number
 $('body').on('click', '.select_serial_number.select_popup', function () {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_serial_number').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.setItem("field_class", fieldClass);
  } else {
   var liId = $(this).closest('li').find('.serial_number').prop('id');
   localStorage.setItem("li_divId", liId);
  }
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=inv_serial_number';
  if ($(this).siblings('.org_id').val()) {
   openUrl += '&org_id=' + $(this).siblings('.org_id').val();
  } else if ($('#org_id').val()) {
   openUrl += '&org_id=%3D' + $('#org_id').val();
  }
  if ($(this).siblings('.item_id_m').val()) {
   openUrl += '&item_id_m=' + $(this).siblings('.item_id_m').val();
  }
  $(this).parent().parent().find('.popup_value').each(function () {
   var dataName = $(this).prop('name').replace(/\[]+/g, '');
   openUrl += '&' + dataName + '=' + $(this).val();
  });

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //select serial number
 $('body').on('click', '.select.inv_serial_number_id', function () {
  if ($(this).find('option').length > 0) {
   return true;
  }
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var item_id_m = $(this).closest('tr').find('.item_id_m').val();
   if (!item_id_m) {
    return true;
   }
   var status = $(this).parent().find('.serial_status').val();
   getSerialNumber({
    status: status,
    item_id_m: item_id_m,
    trclass: rowClass
   });
  } else {
   var rowClass = $(this).closest('tr').prop('class');
   var item_id_m = $(this).closest('ul').find('.item_id_m').val();
   var status = $(this).parent().find('.serial_status').val();
   if (!item_id_m) {
    return true;
   }
   getSerialNumber({
    status: status,
    item_id_m: item_id_m
   });
  }
 });

 //Popup for selecting address address_id for normal popup & address_popup for popup where address can be created
 $('body').on('click', '.address_id.select_popup', function (e) {
  e.preventDefault();
  localStorage.setItem("set_value_for_one_div", true);
  var close_div_class = '.' + $(this).closest('ul').parent().prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_div_class", close_div_class);
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);

  var openUrl = 'select.php?class_name=address&mode=2';
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 //Popup for selecting po_header_id
 $('body').on('click', '.select_popup_default_class', function (e) {
  e.preventDefault();
  localStorage.setItem("set_value_for_one_field", true);
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=' + $(this).data('default_class') + '&mode=2';
  $(this).parent().find('.popup_value').each(function () {
   var dataName = $(this).prop('name').replace(/\[]+/g, '');
   openUrl += '&' + dataName + '=' + $(this).val();
  });

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

//selecting customer
 $('body').on("click", '.ar_customer_id.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);

  var openUrl = 'select.php?class_name=ar_customer';
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');

 });

//selecting supplier
 $('body').on("click", '.supplier_id.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);

  var openUrl = 'select.php?class_name=supplier';
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //selecting user
 $('body').on("click", '.user_id.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open('select.php?class_name=user', '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');

 });

 //selecting change request
 $('body').on("click", '.hd_change_request_id.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);

  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open('select.php?class_name=hd_change_request', '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //selecting support request
 $('body').on("click", '.hd_support_request_id.select_popup', function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  void window.open('select.php?class_name=hd_support_request', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popup for contact
 $('#content').on('click', '.extn_contact_id.select_popup', function () {
  var close_field_class = '.' + $(this).closest('li').find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  localStorage.setItem("set_value_for_one_field", 1);
  void window.open('select.php?class_name=extn_contact', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popup for hd_service_request_id
 $('#content').on('click', '.hd_service_request_id.select_popup', function () {
  var close_field_class = '.' + $(this).closest('li').find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  void window.open('select.php?class_name=hd_service_request', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $("body").on("click", ".select_am_asset_number.select_popup", function () {
  var close_field_class = '.' + $(this).parent().find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  void window.open('select.php?class_name=am_asset', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $("body").on("click", "a.contact_link", function (e) {
  e.preventDefault();
  void window.open($(this).prop('href'), '_blank',
          'width=1000,height=600,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $("body").on("click", ".wo_number.select_popup", function () {
  var close_field_class = '.' + $(this).closest('li').find(':input').not('.hidden').prop('class').replace(/\s+/g, '.');
  localStorage.setItem("close_field_class", close_field_class);
  var openUrl = 'select.php?class_name=wip_wo_header';
  $(this).parent().parent().find('.popup_value').each(function () {
   var dataName = $(this).prop('name').replace(/\[]+/g, '');
   openUrl += '&' + dataName + '=' + $(this).val();
  });
  void window.open(openUrl, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //add new order by
 $('#content').on('change', '.search_order_by', function () {
  if ($(this).val() !== 'remove') {
   $(this).closest('li').clone().insertAfter($(this).closest('li'));
  } else {
   $(this).closest('li').remove();
  }
 });

 $('body').on('change', '#searchForm .new_search_criteria', function () {
  if ($(this).val()) {
   var newSearchCriteria = $(this).val();
   var newSearchCriteriaText = $(this).find('option:selected').prop('innerHTML');
   var newSearchCriteriaText_label = toUpperCase($(this).find('option:selected').prop('innerHTML').replace(/_/g, ' '));
   var newSearchCriteriaName = newSearchCriteria + '[]';
   var elementToBeCloned = $('.text_search').first().closest('li');
   var elementClass = $('.text_search').first().attr('class');
   var elementName = $('.text_search').first().attr('name');
   var elementLabelClass = '.label_' + elementName;
   elementLabelClass = elementLabelClass.replace('[', '');
   elementLabelClass = elementLabelClass.replace(']', '');
   var clonedElement = elementToBeCloned.clone();


   clonedElement.find('label').prop('textContent', newSearchCriteriaText_label);
   clonedElement.find('label').text(newSearchCriteriaText_label);
   clonedElement.children().removeAttr('id');
   clonedElement.children().removeClass(elementClass);
   clonedElement.children().addClass(newSearchCriteria);
   clonedElement.children().prop('name', newSearchCriteriaName);

   clonedElement.find("input").each(function () {
    $(this).val("");
   });
//	 clonedElement.appendTo($(this).closest("ul"));
   clonedElement.insertBefore($(this).closest("li"));
//   $(elementLabelClass + ':last').text(newSearchCriteria);
  }
 });


 //toggle detail lines
 $(".form_detail_data_fs").hide();
 $("#content").on('click', '.error', function () {
  $(this).html("");
 });

 $('body').on('click', '#sys_msg_box button.close', function () {
  $('.alert-dismissible').alert('close');
 });

 //export to excel from search result
 $("#content").on('click', '#export_excel_searchResult', function (e) {
  window.open('data:application/vnd.ms-excel,' + encodeURIComponent($('#search_result').html()));
  e.preventDefault();
 });
//remove row
 remove_row();

 //remove attached files
 $('#content').on('click', '.remove_file', function () {
  $(this).closest('ul').remove();
 });


 $('body').on('focus', ".dateTime", function () {
  var currentDate = new Date();
  var timeStamp = currentDate.getHours() + ':' + currentDate.getMinutes() + ':' + currentDate.getSeconds();
  $(this).datepicker({
   defaultDate: currentDate,
   changeMonth: true,
   changeYear: true,
   dateFormat: "yy-mm-dd " + timeStamp,
   setDate: currentDate
  });
 });


 $('body').on('focus', ".anyDate", function () {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert(readonly_field);
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate
   });
  }

 });

 $('body').on('focus', ".anyDate_gt", function () {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert(readonly_field);
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: ">yy-mm-dd",
    setDate: currentDate
   });
  }

 });

 $('body').on('focus', ".anyDate_lt", function () {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert(readonly_field);
  } else {
   var currentDate = '<' + new Date();
   $(this).datepicker({
    defaultDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: ">yy-mm-dd",
    setDate: currentDate
   });
  }

 });

 $('body').on('focus', ".dateFromToday", function () {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert(readonly_field);
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    minDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate
   });
  }
 });

 $('body').on('focus', ".MondayFromToday", function () {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert(readonly_field);
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    minDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate,
    beforeShowDay: function (date) {
     var day = date.getDay();
     return [day == 1, ""];
    }
   });
  }
 });

 var today_date = new Date();
 var formatted_date = today_date.getFullYear() + '-' + (today_date.getMonth() + 1) + '-' + today_date.getDate();
 $(".default_date").val(formatted_date);

 //dont allow past dates if manually entered
 $('body').on('change', '.dateFromToday', function () {
  var toDay = new Date();
  var enteredDate = $(this).datepicker("getDate");
  var diff = enteredDate - toDay;
  if ((enteredDate) && (diff < -86400000)) {
   $(this).attr('value', '');
   $(this).focus();
   alert("Past date is not allowed");
  }
 });
 //creating tabs
// $("#tabs").tabs();
 //creating tabs
 $(function () {
  var tabs = $("#tabsHeader").tabs();
  var tabs = $("#tabsLine").tabs();
  tabs.find(".ui-tabs-nav").sortable({
   axis: "x",
   stop: function () {
    tabs.tabs("refresh");
   }
  });
 });
 $("#tabsVertical").tabs().addClass("ui-tabs-vertical ui-helper-clearfix");
 $("#tabsVertical li").removeClass("ui-corner-top").addClass("ui-corner-left");
// $("#tabsLine").tabs();
 $("#tabsDetail, #tabsDetailA ,#tabsDetailB, #tabsDetailC, #tabsDetailD, #tabsDetailSN, #tabsDetailLN").tabs();
 $(".tabsDetail, .tabsDetailA , .tabsDetailB, .tabsDetailC, .tabsDetailD, .tabsDetailSL, .tabsDetailLN").tabs();

//Refresh the page
 $("#refresh_button").on("click", function () {
  location.reload(true);
  localStorage.removeItem("disableContextMenu");
 });

//setConetntRightLeft();
 tinymce.init({
  selector: '.mediumtext',
  mode: "exact",
//    theme: "modern",
  plugins: 'textcolor link image lists code table emoticons',
  width: 680,
  height: 150,
  relative_urls: false,
  remove_script_host: false,
  force_br_newlines: true,
  force_p_newlines: false,
  forced_root_block: '',
  toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
  menubar: false,
  statusbar: false,
  valid_elements: '*[*]',
  file_browser_callback: function () {
   $('#comment_attachments').trigger('click');
  }
 });

 tinymce.init({
  selector: '.bigtext',
  mode: "exact",
//    theme: "modern",
  plugins: 'textcolor link image lists code table emoticons',
  width: 740,
  height: 250,
  relative_urls: false,
  remove_script_host: false,
  force_br_newlines: true,
  force_p_newlines: false,
  forced_root_block: '',
  toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
  menubar: false,
  statusbar: false,
  valid_elements: '*[*]',
  file_browser_callback: function () {
   $('#attachment_button').click();
  }
 });



 //diable/enable auto complete
 $('#content').on('click', '.disable_autocomplete', function () {
  $(this).parent().siblings('input').each(function () {
   $(this).autocomplete({
    disabled: true
   });
   var fname = $(this).prop('name').replace(/\[]+/g, ' ').replace(/_+/g, ' ');
   $(this).prop('placeholder', 'Enter new ' + fname);
  });
  $(this).parent().children('input').each(function () {
   $(this).autocomplete({
    disabled: true
   });
   var fname = $(this).prop('name').replace(/\[]+/g, ' ').replace(/_+/g, ' ');
   $(this).prop('placeholder', 'Enter new ' + fname);
  });
 });

 $('#content').on('dblclick', ':input', function () {
  if ($(this).hasClass('ui-autocomplete-input')) {
   $(this).autocomplete({
    disabled: false
   });
  }
 });

 //basic finction --making background colors for form fields
 $("[required]").addClass('required');
 $("[readonly]").addClass('readonly');

 //Popup for print
 $('body').on('click', '.print', function () {
//  window.print();

  var pContent = '<div id="popup_print" class="row">';

  if ($('.extn_report_content').length > 0) {
   pContent += '<table>';
   pContent += '<thead><tr>';
   $('#structure').find('table thead tr').each(function (k, v) {
    pContent += $(v).html();
   });
   pContent += '</tr></thead>';
   pContent += '<tbody class="form_data_line_tbody search_results"><tr>';
   $('#structure').find('table tbody.tbody_row0 tr').each(function (k, v) {
    var rowClass = '.' + $(this).attr('class');
    $('#structure').find('table tbody tr' + rowClass).each(function (k2, v2) {
     pContent += $(v2).html();
    });
    pContent += '</tr>';
   });
   pContent += '</tbody>';
   pContent += '</table>';
  } else if ($('#searchResult').length > 0) {
   $('#searchResult').find('table').each(function (k, v) {
    pContent += '<table>' + $(v).html() + '</table>';
   });
  } else {
   pContent += '<div class="col-md-12"><ul id="print-header">';
   $('#form_header').not('.big_popover').find('label,:input').each(function (k, v) {
    if ($(v).closest('span').hasClass('big_popover')) {
     return true;
    }
    if ($(v).is('label')) {
     pContent += '<li><label>';
     pContent += $(v).html();
    } else {

     if ($(v).is('select')) {
      pContent += $(v).find(':selected').text();

     } else if ($(v).is(':text') || $(v).is('bool')) {
      pContent += $(v).val();
     }
    }
    if (!$(v).is('label')) {
     pContent += '</li>';
    } else {
     pContent += '</label>';
    }
   });
   pContent += '</ul></div>';
  }

  if ($('#form_line').length > 0) {
//   var class_detail_form_w = +($('table.form_line_data_table').find('tr').first().width() - $('table.form_line_data_table').first().find('td:first').width() - $('table.form_line_data_table').find('td.add_detail_values').first().width()) + 'px';
   $('.add_detail_values_img').first().trigger('click');
   var class_detail_form_w = +($('table.form_detail_data_table').first().width()) + 'px';
   $('.add_detail_values_img').first().trigger('click');
   if ($('#form_line').find('table').length > 0) {
    pContent += '<div class="col-md-12 table-responsive" id="print-line">';
    $('#form_line').find('table.form_line_data_table').each(function (k, v) {
     var table_no = 'table_' + k;
     $(this).find('.class_detail_form').css({
      'margin-left': '-' + class_detail_form_w,
      'width': class_detail_form_w
     });
     pContent += '<table class="table ' + table_no + ' ">' + $(this).html() + '</table>';
    });
    pContent += '</div>';
//    $('#form_line').find('table').each(function (k, v) {
//     pContent += '<table>' + $(v).html() + '</table>';
//    });
   } else {
    pContent += '<ul>';
    $('#form_line').find('label,:input').each(function (k, v) {
     if ($(v).closest('span').hasClass('big_popover')) {
      return true;
     }
     if ($(v).is('label')) {
      pContent += '<li><label>';
      pContent += $(v).html();
     } else {

      if ($(v).is('select')) {
       pContent += $(v).find(':selected').text();

      } else if ($(v).is(':text') || $(v).is('bool')) {
       pContent += $(v).val();
      }
     }
     if (!$(v).is('label')) {
      pContent += '</li>';
     } else {
      pContent += '</label>';
     }
    });
    pContent += '</ul>';
   }

  }



  pContent += '</div>';

  var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  var primary_column_id_h = '#' + primary_column_id;
  var print_title = $('span.heading').first().text() + ' with ' + primary_column_id + ' ' + $(primary_column_id_h).val();
  var printContenet = '<!DOCTYPE html><html><head>';
  printContenet += '<title>' + print_title + '</title>';
  printContenet += '<link rel="stylesheet" type="text/css" href="tparty/bootstrap/css/bootstrap.css">';
  printContenet += '<link rel="stylesheet" type="text/css" href="themes/default/kprint.css">';
  printContenet += '</head><body>';
  printContenet += pContent;
  printContenet += '<' + '/body' + '><' + '/html' + '>';
  var w_width = $(window).width();
  var w_height = $(window).height();
  var popupWin = window.open("", "_blank", "width=" + w_width + ",height=" + w_height + ",TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no");

  popupWin.document.writeln('' + printContenet + '');
  popupWin.document.close();
//  popupWin.focus();
  popupWin.print();
//  popupWin.close();
 });
 //all download
 $('#export_excel_allResult').on('click', function () {
  $('#download_all').submit();
 });

 $('body').on('click', '#generate_report', function () {
  $('#program_header').submit();
 });

 show_dialog_box();
 animateCycle();
 $('#all_contents').on('click', '.start_play', function () {
  animateCycle();
 });

 $('#all_contents').on('focusIn', '#animated_block', function () {
  clearInterval(interval);
 });

 $('#all_contents').on('focusOut', '#animated_block', function () {
  animateCycle();
 });

//tree view
 treeView();
 folder_treeView();

 $("#search_message").dialog({
  autoOpen: false,
  dialogClass: "no-close",
  modal: true,
  minWidth: 600,
  title: "Searching Tips",
  show: {
   effect: "blind",
   duration: 1000
  },
  hide: {
   effect: "explode",
   duration: 1000
  },
  buttons: [
   {
    text: "OK",
    class: 'button btn btn-info btn-done',
    click: function () {
     $(this).dialog("close");

    }
   }
  ],
  closeOnEscape: true,
  position: {my: "left top", at: "left top", of: "#structure "}
 });


 $('body').off('click', '#search_tip').on('click', '#search_tip', function () {
  $("#search_message").dialog("open");
 });

 $('body').off('click', '#menu_button8').on('click', '#menu_button8', function () {
  $("#document_history_ul").dialog("open");
 });

//save data
 if ($('ul#js_saving_data').length > 0) {
  var classSave = new saveMainClass();
  var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
  var lineClassName = $('ul#js_saving_data').find('.lineClassName').data('lineclassname');
  var lineClassName2 = $('ul#js_saving_data').find('.lineClassName2').data('lineclassname2');
  var lineClassName3 = $('ul#js_saving_data').find('.lineClassName3').data('lineclassname3');
  var detailClassName = $('ul#js_saving_data').find('.detailClassName').data('detailclassname');
  var form_header_id = $('ul#js_saving_data').find('.form_header_id').data('form_header_id');
  var form_line_id = $('ul#js_saving_data').find('.form_line_id').data('form_line_id');
  var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  var primary_column_id2 = $('ul#js_saving_data').find('.primary_column_id2').data('primary_column_id2');
  var line_key_field = $('ul#js_saving_data').find('.line_key_field').data('line_key_field');
  var savingOnlyHeader = $('ul#js_saving_data').find('.savingOnlyHeader').data('savingonlyheader');
  var onlyHeaderOverLay = $('ul#js_saving_data').find('.onlyHeaderOverLay').data('onlyheaderoverlay');
  var save_vertical_tab = $('ul#js_saving_data').find('.save_vertical_tab').data('save_vertical_tab');
  var onlyOneLineAtATime = $('ul#js_saving_data').find('.onlyOneLineAtATime').data('onlyonelineatatime');
  var allLineTogether = $('ul#js_saving_data').find('.allLineTogether').data('alllinetogether');
  var single_line = $('ul#js_saving_data').find('.single_line').data('single_line');

  var before_save_function = $('ul#js_saving_data').find('.before_save_function').data('before_save_function');
  if (!before_save_function) {
   window.beforeSave = function () {
    return false;
   }
  }

  classSave.enable_select = true;
  classSave.json_url = 'form.php?class_name=' + headerClassName;
  classSave.form_header_id = form_header_id;
  classSave.form_line_id = (typeof form_line_id !== 'undefined') ? form_line_id : 'form_line';
  classSave.line_key_field = (typeof line_key_field !== 'undefined') ? line_key_field : null;
  classSave.primary_column_id = primary_column_id;
  classSave.primary_column_id2 = primary_column_id2;
  classSave.savingOnlyHeader = (savingOnlyHeader == true) ? true : false;
  classSave.onlyHeaderOverLay = (onlyHeaderOverLay == true) ? true : false;
  classSave.saveVerticalTab = (save_vertical_tab == true) ? true : false;
  classSave.allLineTogether = (allLineTogether == true) ? true : false;
  classSave.onlyOneLineAtATime = (onlyOneLineAtATime == true) ? true : false;
  classSave.single_line = (single_line == true) ? true : false;
  if (single_line == true) {
   var primary_column_id_h = '#' + primary_column_id;
   if (!$(primary_column_id_h).val()) {
    classSave.savingOnlyHeader = true;
   } else {
    classSave.savingOnlyHeader = false;
   }
  }
  classSave.headerClassName = headerClassName;
  var deleteLink = 'form.php?class_name=' + headerClassName;

  if (typeof lineClassName !== 'undefined') {
   deleteLink += '&line_class_name=' + lineClassName;
   classSave.lineClassName = lineClassName;
  } else {
   classSave.lineClassName = null;
  }
  if (typeof lineClassName2 !== 'undefined') {
   deleteLink += '&line_class_name2=' + lineClassName2;
   classSave.lineClassName2 = lineClassName2;
  } else {
   classSave.lineClassName2 = null;
  }
  if (typeof lineClassName3 !== 'undefined') {
   deleteLink += '&line_class_name3=' + lineClassName3;
   classSave.lineClassName3 = lineClassName3;
  } else {
   classSave.lineClassName3 = null;
  }
  if (typeof detailClassName !== 'undefined') {
   deleteLink += '&detail_class_name=' + detailClassName;
   classSave.detailClassName = detailClassName;
  } else {
   classSave.detailClassName = null;
  }
  classSave.saveMain(before_save_function);
  deleteData(deleteLink);
 }

//context menu
 if ($('ul#js_contextMenu_data').length > 0) {
  var classContextMenu = new contextMenuMain();
  var docHedaderId = $('ul#js_contextMenu_data').find('.docHedaderId').data('dochedaderid');
  var docLineId = $('ul#js_contextMenu_data').find('.docLineId').data('doclineid');
  var docDetailId = $('ul#js_contextMenu_data').find('.docDetailId').data('docdetailid');
  var btn1DivId = $('ul#js_contextMenu_data').find('.btn1DivId').data('btn1divid');
  var btn2DivId = $('ul#js_contextMenu_data').find('.btn2DivId').data('btn2divid');
  var trClass = $('ul#js_contextMenu_data').find('.trClass').data('trclass');
  var tbodyClass = $('ul#js_contextMenu_data').find('.tbodyClass').data('tbodyclass');
  var noOfTabbs = $('ul#js_contextMenu_data').find('.noOfTabbs').data('nooftabbs');
  var beforeCopy = $('ul#js_contextMenu_data').find('.beforeCopy').data('beforecopy');
  var afterCopy = $('ul#js_contextMenu_data').find('.afterCopy').data('aftercopy');

  classContextMenu.docHedaderId = (typeof docHedaderId !== 'undefined') ? docHedaderId : null;
  classContextMenu.docLineId = (typeof docLineId !== 'undefined') ? docLineId : null;
  classContextMenu.docDetailId = (typeof docDetailId !== 'undefined') ? docDetailId : null;
  classContextMenu.btn1DivId = (typeof btn1DivId !== 'undefined') ? btn1DivId : null;
  classContextMenu.btn2DivId = (typeof btn2DivId !== 'undefined') ? btn2DivId : 'form_line';
  classContextMenu.trClass = (typeof trClass !== 'undefined') ? trClass : null;
  classContextMenu.tbodyClass = (typeof tbodyClass !== 'undefined') ? tbodyClass : null;
  classContextMenu.noOfTabbs = (typeof noOfTabbs !== 'undefined') ? noOfTabbs : null;
  classContextMenu.beforeCopy = (typeof beforeCopy !== 'undefined') ? beforeCopy : null;
  classContextMenu.afterCopy = (typeof afterCopy !== 'undefined') ? afterCopy : null;
  classContextMenu.contextMenu();

 }

 $('body').on("click", "#form_line .add_row_img", function () {
  var addNewRow = new add_new_rowMain();
  var noOfTabbs = $('ul#js_contextMenu_data').find('.noOfTabbs').data('nooftabbs');
  var lineClassName = $('ul#js_saving_data').find('.lineClassName').data('lineclassname');
  addNewRow.trClass = lineClassName;
  addNewRow.tbodyClass = 'form_data_line_tbody';
  addNewRow.noOfTabs = noOfTabbs;
  addNewRow.removeDefault = true;
  addNewRow.divClassToBeCopied = 'copy';
  addNewRow.divClassNotToBeCopied = 'dontCopy';
  addNewRow.enableUpdate = 'enable_update';
  addNewRow.add_new_row();
  $(".tabsDetail").tabs();
 });

 addOrShow_lineDetails();
 onClick_addDetailLine();
 onClick_addDetailLine(2, '.add_row_detail_img3', 'tabsDetailC');

// var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.mandatoryHeader();

 $('#content').on('change', '.sys_extra_field_id', function () {
  var field_type = $(this).find('option:selected').data('field_type');
  $(this).closest('tr').find('.field_type').val(field_type);
 });

 $('#content').on('change', '.sys_secondary_field_id', function () {
  var field_type = $(this).find('option:selected').data('field_type');
  $(this).closest('tr').find('.field_type').val(field_type);
 });

 $('body').off('click', '.hideDiv').on('click', '.hideDiv', function () {
  $('.hideDiv').children().toggle();
  $(this).parent().find('.hideDiv_element').toggle();
  $(this).parent().parent().find('.hideDiv_element').toggle();
  $(this).removeClass('hideDiv').addClass('showDiv');
 });

 $('body').off('click', '.showDiv').on('click', '.showDiv', function () {
  $(this).children().toggle();
  $(this).parent().find('.hideDiv_element').toggle();
  $(this).parent().parent().find('.hideDiv_element').toggle();
  $(this).removeClass('showDiv').addClass('hideDiv');
 });

 $('body').off('click', '.hideDiv_input').on('click', '.hideDiv_input', function () {
  $(this).parent().find('.hideDiv_input_element').toggle();
  $(this).removeClass('hideDiv_input fa-minus-circle').addClass('showDiv_input fa-plus-circle');
 });

 $('body').off('click', '.showDiv_input').on('click', '.showDiv_input', function () {
  $(this).parent().find('.hideDiv_input_element').toggle();
  $(this).removeClass('showDiv_input fa-plus-circle').addClass('hideDiv_input fa-minus-circle');
 });

 $('#content_divId .hideDiv_input, #program_header .hideDiv_input').trigger('click');

// $('#user_info .block_menu').menu();
 $('#big_popover').popover({
  html: true,
  title: function () {
   return $("#popover-head").html();
  },
  content: function () {
   return $("#popover-content").html();
  }
 });


 $('body').on('click', '.close_big_popover', function () {
  $('#big_popover').trigger('click');
 });


 $('body').on('click', '#search_page #search_submit_btn', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  getSearchResult();
 });

 $('body').on('click', '#select_page #search_submit_btn, #select-popover #search_submit_btn', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  getSelectResult();
 });

 $('body').on('click', '#search_page .page_nos a, #left-clipboard-data .page_nos a', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var page_no = getUrlValues('pageno', $(this).prop('href'));
  var per_page = getUrlValues('per_page', $(this).prop('href'));
  getSearchResult({
   pageno: page_no,
   per_page: per_page
  });
 });

 $('body').on('click', '#search_page a.content_per_page', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
  getSearchResult({
   per_page: per_page
  });
 });

 $('body').on('click', '#select_page .page_nos a', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var page_no = getUrlValues('pageno', $(this).prop('href'));
  var per_page = getUrlValues('per_page', $(this).prop('href'));
  getSelectResult({
   pageno: page_no,
   per_page: per_page
  });
 });

 $('body').on('click', '#select_page a.content_per_page', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
  getSelectResult({
   per_page: per_page
  });
 });

 $('body').on('click', '#site_search_submit', function (e) {
  e.preventDefault();
  getSiteSearchResult();
 });
 $('body').on('submit', '#site_search', function (e) {
  e.preventDefault();
  getSiteSearchResult();
 });


 $('body').on('click', '#site_search_content .page_nos a', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var page_no = getUrlValues('pageno', $(this).prop('href'));
  var per_page = getUrlValues('per_page', $(this).prop('href'));
  getSiteSearchResult({
   pageno: page_no,
   per_page: per_page
  });
 });

 $('body').on('click', '#site_search_content a.content_per_page', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
  getSiteSearchResult({
   per_page: per_page
  });
 });

 $('body').on('click', '#multi_select #search_submit_btn', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  getMultiSelectResult();
 });

 $('body').on('click', '#multi_select .page_nos a, .multi_select_page .page_nos a', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var page_no = getUrlValues('pageno', $(this).prop('href'));
  var per_page = getUrlValues('per_page', $(this).prop('href'));
  getMultiSelectResult({
   pageno: page_no,
   per_page: per_page
  });
 });

 $('body').on('click', '#multi_select a.content_per_page', function (e) {
  e.preventDefault();
  $('.hideDiv_input').trigger('click');
  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
  getMultiSelectResult({
   per_page: per_page
  });
 });

 var contactObjectCount = 2;
 $('#content').on('click', 'li#add_new_contact', function () {
  $(this).closest('ul').find('li').first().clone().attr("class", "new_object" + contactObjectCount).prependTo($(this).closest('ul'));
  contactObjectCount++;
 });

 getBlocks();

//#path_by_module a, #pagination .page_nos a, .pagination_page .page_nos a
//#pagination .page_nos a added for price list
// #pagination .page_nos a REMOVED for comment and content multi action
 $('body').on('click', '.getAjaxForm,#top-path-menu-ul a, #path_by_module a, .search_result a, #erp_form_area a.ajax-link ,.pagination_page .page_nos a, #header_top .menu a, #sys_menu_left_vertical .menu a,#search_result .action a,  #new_page_button', function (e) {
  e.preventDefault();
  if (ino_light) {
   if ($(this).closest('li').data('enterprise') == '1') {
    alert("Sorry! for technical reasons this feature is available only in the inoERP cloud version.");
    return false;
   }
  }
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var urlLink_firstPart_a = urlLink_a[0].split('/');
  var pageType = urlLink_firstPart_a.pop();
  if (pageType == 'form.php') {
   var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
  } else if (pageType == 'program.php') {
   var formUrl = 'includes/json/json_program.php?' + urlLink_a[1];
  } else if (pageType == 'search.php') {
   var formUrl = 'includes/json/json_blank_search.php?' + urlLink_a[1];
  } else {
   var formUrl = urlLink;
  }
  getFormDetails(formUrl);
  history.pushState(null, null, urlLink);
 }).one();

 $('body').on('click', 'a.show3', function (e) {
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
  $(this).closest('li').find(':input').each(function (k, v) {
   formUrl += '&' + $(this).attr('name').replace(/\[]+/g, '') + '=';
   formUrl += $(this).val();
  });
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', '.ajax_content a', function (e) {
  if ($(this).hasClass('non_ajax')) {
   location.href($(this).prop('href'));
   return false;
  }
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var urlLink_firstPart_a = urlLink_a[0].split('/');
  var pageType = urlLink_firstPart_a.pop();
  if (pageType == 'form.php') {
   var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
  } else if (pageType == 'content.php') {
   var homeUrl = $('#home_url').val();
   var formUrl = homeUrl + 'includes/json/json_content.php?' + urlLink_a[1];
  } else if (pageType == 'program.php') {
   var formUrl = 'includes/json/json_program.php?' + urlLink_a[1];
  } else {
   var formUrl = urlLink;
  }
  getFormDetails(formUrl);
  history.pushState(null, null, urlLink);
 });


 $('body').on('click', '#pagination a.content_per_page', function (e) {
  e.preventDefault();
  var urlLink = $(this).closest('#pagination').find('a').first().attr('href');
  var urlLink_a = urlLink.split('?');
  var urlLink_firstPart_a = urlLink_a[0].split('/');
  var pageType = urlLink_firstPart_a.pop();
  if (pageType == 'form.php') {
   urlLink_a[1] += '&per_page=' + $(this).parent().find('.per_page').val();
   var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
  } else {
   var formUrl = urlLink;
  }
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', '.event-cal-h', function () {
  var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
  if (headerClassName == 'sys_calendar') {
   return;
  } else {
   var formUrl = 'includes/json/json_form.php?mode=9&class_name=sys_calendar';
   getFormDetails(formUrl);
  }

 }).one();


 $('body').on('click', '#content a.show, #content a.show1', function (e) {
  e.preventDefault();
//  var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
//  var header_id_h = '#' + primary_column_id;
//  var primary_column_id_v = $(header_id_h).val();
  var link = '';
  $(this).parent().find(':input').each(function () {
   var field_name = $(this).prop('name').replace(/\[]+/g, '');
   var field_val = $(this).val();
   link += '&' + field_name + '=' + field_val;
  });
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + link;
  var pageUrlLink = 'form.php?' + urlLink_a[1] + link;
//  console.log(link +  ' : ' + formUrl );
  if ($(this).data('search_field')) {
   var search_field = $(this).data('search_field');
   var search_field_h = '#' + search_field;
   var search_field_val = $(search_field_h).val();
   formUrl += '&' + search_field + '=' + search_field_val;
  }
  history.pushState(null, null, pageUrlLink);
  getFormDetails(formUrl);
 }).one();

 //Delete the comment form
 deleteComment();


//Update the comment form
 $("body").on('click', '.update_button', function (e) {
  e.preventDefault();
  var comment_id = $(this).val();
  var ulId = $(this).closest(".commentRecord").prop('id');
  if (confirm("Are you sure?")) {
   updateComment(comment_id, ulId);
  }
  e.stopPropagation();
 });

 $('body').on('click', '.submit_comment', function () {
  var this_e = $(this);
  $('.show_loading_small').show();
  var comment_text = $('form').find('.ed-mediumtext').val().trim();
  if (!comment_text) {
   alert('Enter comment and then click on post');
   return false;
  }
//  if (!$(this).closest('ul').find('.content_by').val()) {
//   alert('Please enter your name in Post As.\n\Or Login to the site');
//   return false;
//  }
  $(this).prop('disabled', true);
  var headerData = $(this).closest('form').serializeArray();
  var homeUrl = $('#home_url').val();
  var savePath = homeUrl + 'form.php?class_name=extn_comment';
  $.when(saveHeader(savePath, headerData, '#comment_id', '', '', true, 'extn_comment')).then(function () {
   var msg = '<div class="panel panel-info commentRecord"><div class="panel-heading"><ul class="header_li">';
   msg += '</ul></div>';
   msg += '<div class="comment panel-body new-comment update-comment">';
   msg += this_e.closest('form').find('textarea').val();
   msg += '<span class="comment-reply"><a class="btn btn-success" role="button" href="#commentForm">Reply</a></span></div>';
   msg += '</div>';
   if ($('#comment_list .pagination').length > 0) {
    $(msg).insertBefore('#comment_list .pagination');
   } else {
    $(msg).insertBefore('#comment_list');
   }

   $('.show_loading_small').hide();
   this_e.prop('disabled', false);
   this_e.closest('form').find('textarea').val('');
   $('.temp-update-form').closest('.commentRecord').remove();
  });
 });

 $('body').on('click', '#save_program', function () {
  $('.show_loading_small').show();
  var headerData = $('#program_header').serializeArray();
  var class_name = $('.class_name').val();
  var homeUrl = $('#home_url').val();
  if (headerData) {
   var savePath = homeUrl + 'program.php?class_name=' + class_name;
   $.when(saveHeader(savePath, headerData, '#sys_program', '', '', true, 'program_header')).then(function () {
    $('.show_loading_small').hide();
   });
  }
 });

 //FILE attachment
 var fu = new fileUploadMain();
 if ($('#upload_type').val()) {
  var upload_type = $('#upload_type').val();
  fu.upload_type = upload_type;
  fu.class_name = $('.class_name').val();
  fu.directory = 'temp';
 } else {
  var upload_type = '';
 }
 fu.json_url = homeUrl + 'extensions/file/upload.php';
 fu.fileUpload();

 //bank account popup
 $("body").on("click", '.mdm_bank_account_id.select_popup', function () {
  void window.open('select.php?class_name=mdm_bank_account_v', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //coa structure
 $('body').on('change', '#coa_structure_id', function () {
  if (!$('#coa_id').val()) {
   getCoaStructure();
  }
 });

//open new period
 $('body').on('click', '#open_next_period', function () {
  if ($('#new_gl_calendar_id').val()) {
   var period_name = $('#new_gl_calendar_id option:selected').text();
   if (confirm("Open " + period_name + " Period ?\n")) {
    openNextGLPeriod();
   }
  } else {
   alert('No period avaibale to open');
  }
 });


 $('body').on('click', 'a.payslipBy_periodName', function (e) {
  var headerId_v = $(this).parent().find('select').val();
  var headerId = $(this).parent().find('select').attr('id');
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&' + headerId + '=' + headerId_v + '&employee_id=' + $('#employee_id').val();
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', 'a.hr_approval_limit_assign_id', function (e) {
  var position_id_v = $('#position_id').val();
  var job_id_v = $('#job_id').val();
  var bu_org_id_v = $('#bu_org_id').val();
  e.preventDefault();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&position_id=' + position_id_v + '&job_id=' + job_id_v + '&bu_org_id=' + bu_org_id_v;
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', 'a.sys_profile_header_id', function (e) {
  e.preventDefault();
  var sys_profile_header_id = $('#sys_profile_header_id').val();
  var profile_level = $('#profile_level').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&sys_profile_header_id=' + sys_profile_header_id + '&profile_level=' + profile_level;
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', 'a.sys_hold_reference_doc_id', function (e) {
  e.preventDefault();
  var reference_table = $('#reference_table').val();
  var reference_id = $('#reference_id').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&reference_table=' + reference_table + '&reference_id=' + reference_id;
  getFormDetails(formUrl);
 }).one();

 $('body').on('click', 'a.bc_label_auto_trigger_id', function (e) {
  e.preventDefault();
  var transaction_type_id = $('#transaction_type_id').val();
  var association_level = $('#association_level').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&transaction_type_id=' + transaction_type_id + '&association_level=' + association_level;
  getFormDetails(formUrl);
 }).one();



 $("#filter_area").dialog({
  autoOpen: false,
  dialogClass: "no-close",
  modal: true,
  minWidth: 800,
  title: "Filters",
  buttons: [
   {
    text: "Done",
    class: 'button btn btn-info btn-done',
    click: function () {
     $("#filter_area").find('input.field_name').val('');
     $(this).dialog("close");
    }
   }
  ],
  closeOnEscape: true,
  position: {my: "center center", at: "center center"}
 });


 $('body').off('click', '.apply-filter').on('click', '.apply-filter', function () {
  if ($('#searchForm').length < 1) {
   return true;
  }
  var inputFieldName = $(this).closest('.list_filter').find('select.field_name').val();
  var inputFieldCondition = $(this).closest('.list_filter').find('select.condition_name').val();
  var inputFieldValue = $(this).closest('.list_filter').find('input.condition_value').val();

  var filterHtml = ' ' + inputFieldName;
  filterHtml += ' ' + inputFieldCondition;
  filterHtml += ' ' + inputFieldValue;
  var elementClass = 'applied-filter ' + inputFieldName;
  var elementToBeCloned = $('.applied_filters').last().clone().attr('data-field_name', inputFieldName).attr('class', elementClass);
  $(elementToBeCloned).find('button.toggle-filter').append(filterHtml);
  $('#searchForm').append(elementToBeCloned);

  var hiddenFieldValue = inputFieldCondition + inputFieldValue;
  var hiddenInput = '<input class="filter_field ' + inputFieldName + ' " type="hidden" value="' + hiddenFieldValue + '" name="' + inputFieldName + '[]" form="generic_search_form">';
  $('#searchForm').find('ul.search_form').append(hiddenInput);
  if ($('#searchForm').find('.window_type').val() && $('#searchForm').find('.window_type').val() == 'popover') {
   getSelectResult();
  } else {
   getSearchResult();
  }
 });

 $('body').on('click', '#search_result .ino_filter', function () {
  $("#filter_area").dialog("open");
  var select_field = '<select class="field_name form-control" name="field_name">';
  $(this).closest('#search_result').find('th').each(function () {
   if ($(this).data('field_name')) {
    var fname = $(this).data('field_name');
    select_field += '<option value="' + fname + '"> ' + fname + ' </option> ';
   }
  });
  select_field += '</select>';
  $("#filter_area").find('input.field_name').replaceWith(select_field);
  $("#filter_area").find('select.field_name').val($(this).closest('th').data('field_name'));
 });


 $('body').on('click', '#search_result .ino_sort_a_z', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('asc');
  getSearchResult();
 });

 $('body').on('click', '#search_result .ino_sort_z_a', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('desc');
  getSearchResult();
 });

 $('body').on('click', '#select_result .ino_sort_a_z', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('asc');
  getSelectResult();
 });

 $('body').on('click', '#select_result .ino_sort_z_a', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('desc');
  getSelectResult();
 });

 $('body').on('click', '.add-element', function () {
  $(this).closest('.list_filter').clone().appendTo($(this).closest('.well'));
 });

 $('body').on('click', '.remove-element', function () {
  if ($('.list_filter').length > 1) {
   $(this).closest('.list_filter').remove();
  } else {
   alert('You cannot remove the last filter element\nClick on Done to close the filter form');
  }
 });


 $('body').on('click', '#search_result .ino_sort_z_a', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('desc');
  getSearchResult();
 });

 $('body').on('click', '.remove-filter', function () {
  var report_elem = $(this).closest('.extn_report_filters');
  var field_name = $(this).closest('.applied-filter').data('field_name');
  var field_name_d = '.' + field_name;
  $('#searchForm').find('ul.search_form').find(field_name_d).remove();
  $(this).closest('.applied-filter').remove();
  if ($('#searchForm').find('.window_type').val() && $('#searchForm').find('.window_type').val() == 'popover') {
   getSelectResult();
  } else if ($(this).closest('.extn_report_content') != 'undefined') {
   $(report_elem).find('.hidden' + field_name_d).remove();
   $(report_elem).siblings('.live_display_data').find('.ino_filter').first().getReportResult_e();
  } else {
   getSearchResult();
  }
 });


 $('body').on('click', '#select_result .ino_filter', function () {
  $("#filter_area").dialog("open");
  var select_field = '<select class="field_name form-control" name="field_name">';
  $(this).closest('#select_result').find('th').each(function () {
   if ($(this).data('field_name')) {
    var fname = $(this).data('field_name');
    select_field += '<option value="' + fname + '"> ' + fname + ' </option> ';
   }
  });
  select_field += '</select>';
  $("#filter_area").find('input.field_name').replaceWith(select_field);
  $("#filter_area").find('select.field_name').val($(this).closest('th').data('field_name'));
 });




 $('body').on('click', '#select_result .ino_sort_z_a', function () {
  $('#searchForm').find('.search_order_by').val($(this).closest('th').data('field_name'));
  $('#searchForm').find('.search_asc_desc').val('desc');
  getSelectResult();
 });


 $('body').on('click', '#reset_program', function () {
  $(this).closest('form').find(':input').not('.button').val('');
 });

 $('body').on('click', '.right_bar_navigation_menu', function () {
  if ($('.sidebar').is(':visible')) {
   var containerWidth = +$('body').width() - 25;
   $('#divider-bar').css({
    'margin-left': '-1000px'});
   $('.mainbar,  #navigation_bar').css({
    'margin-left': '6px',
    'width': containerWidth + 'px'});
   $('#header_top_quick_nav .right_bar_navigation_menu').removeClass('fa-toggle-left').addClass('fa-toggle-right');
  } else {
   var containerWidth = +$('body').width() - 35;
   var leftPos = $('.sidebar').width();
   var mainBarWidth = containerWidth - leftPos;
   $('#divider-bar').css({
    'margin-left': '0px'});
   $('.mainbar,  #navigation_bar').css({
    'margin-left': leftPos + 20 + 'px',
    'width': mainBarWidth + 'px'});
   $('#header_top_quick_nav .right_bar_navigation_menu').removeClass('fa-toggle-right').addClass('fa-toggle-left');
  }
  $('.sidebar').slideToggle();
 });

 $("#divider-bar").draggable({
  axis: "x",
  delay: 150,
  topValue: null,
  leftValue: null,
  start: function () {
   this.topValue = $(this).position().top;
   this.leftValue = $(this).position().left;
  },
  stop: function (e, ui) {
   var topPos = ui.position.top;
   var leftPos = ui.position.left;
   var leftBarWidth = leftPos;
   var containerWidth = $('body').width();
   var mainBarWidth = containerWidth - leftPos;
   $('.container-fluid .sidebar').css('width', leftBarWidth + 'px');
   $('.mainbar, #navigation_bar').css({
    'margin-left': leftPos + 'px',
    'width': mainBarWidth + 'px'});

  }
 });

 $("#accordion").accordion({
  heightStyle: "content",
  active: 1,
  collapsible: true
 });

 $("#accordion0,#accordion1").accordion({
  heightStyle: "content",
  activate: function (event, ui) {
   if (ui.newHeader.find('i').hasClass('fa-plus-circle')) {
    ui.newHeader.find('i').removeClass('fa-plus-circle').addClass('fa-minus-circle');
   }

   if (ui.oldHeader.find('i').hasClass('fa-minus-circle')) {
    ui.oldHeader.find('i').removeClass('fa-minus-circle').addClass('fa-plus-circle');
   }
  }
 });

 $('body').on('click', '#accordion h3.recent-visits', function () {
  refreshData({
   data_type: 'recent_visit',
   divId: 'recent-visits'
  });

 });

 recentVisitInAjax();

 $('body').on('click', '#header_top_quick_nav .fa-close', function () {
  window.close();
 });

 $('body').on('click', '.fa-arrow-circle-down', function () {
  $(this).removeClass('fa-arrow-circle-down').addClass('fa-arrow-circle-up');
 });

 $('body').on('click', '.fa-arrow-circle-up', function () {
  $(this).removeClass('fa-arrow-circle-up').addClass('fa-arrow-circle-down');
 });

 //tool tip causing error in firefox
// $('[data-toggle="tooltip"]').tooltip({'placement': 'top'});


 $('body').on('click', '#save_content', function () {
  if (!$('#subject').val()) {
   alert('No Subject Entered. Subject is required!');
   return false;
  }

  $(".error").append('<div class="alert alert-warning alert-dismissible" role="alert">Saving Post ...</div>');
  var form_header_id = '#content_data';
  if ($('.mce-tinymce').length >= 1) {
   $(form_header_id).find('textarea').each(function () {
    var name = $(this).attr('name');
    var data = tinyMCE.get(name).getContent();
    $(this).html(data);
   });
  }
  var headerData = $(form_header_id).serializeArray();
  $(this).prop('disabled', true);
  $.when(saveHeader('content.php', headerData, '#content_id', '', '', true, 'content')).then(function () {
   var message = '<div class="alert alert-success alert-dismissible" role="alert">';
   message += 'Document is Successfully Posted, and you will be re-directed to the new post <br> Click on view to view the post';
   message += '</div>';
   $(".error").replaceWith(message);
   $('.show_loading_small').hide();
   var path = 'content.php?mode=2&content_id=' + $('#content_id').val()
           + '&content_type=' + $('#content_type').val();
   window.location.href = path;
  });

 });


 $('body').on('click', '#generic_save', function () {
  var noOfRequiredFileValuesMissing = 0;
  var missingMandatoryValues = [];
  $('body').find('input:required').each(function () {
   if (!$(this).val())
   {
    missingMandatoryValues.push($(this).attr('class'));
    noOfRequiredFileValuesMissing++;
   }
  });

  if (noOfRequiredFileValuesMissing > 0) {
   var showMessage = ' <div id="dialog_box" class="dialog mandatory_message"> ' + noOfRequiredFileValuesMissing + ' mandatory field(s) is/are missing....... <br>';
   $.map(missingMandatoryValues, function (val, i) {
    showMessage += i + ' : ' + val.replace(/_+/, ' ') + ' <br>';
   });
   showMessage += '</div>';
   $("#content").append(showMessage);
   show_dialog_box();
   return;
  }
  $(".error").append('<div class="alert alert-warning alert-dismissible" role="alert">Requet In Progress ...</div>');
  var form_header_id = '#content_data';
  if ($('.mce-tinymce').length >= 1) {
   $(form_header_id).find('textarea').each(function () {
    var name = $(this).attr('name');
    var data = tinyMCE.get(name).getContent();
    $(this).html(data);
   });
  }
  var save_message = $(this).data('save_message');
  var headerData = $(form_header_id).serializeArray();
  $(this).prop('disabled', true);
  $.when(saveHeader('content.php', headerData, '#content_id', '', '', true, 'content')).then(function () {
   var message = '<div class="alert alert-success alert-dismissible" role="alert">' + save_message + '</div>';
   $(".error").replaceWith(message);
   $('.show_loading_small').hide();
  });

 });

 $('body').on('focusin', '.always_readonly, select.readonly', function () {
  $(this).attr('readonly', true).css('background-color', 'none repeat scroll 0% 0% #F3F3D2;');
  alert(readonly_field);
 });

 $('.small_popover').popover({
  html: true,
  trigger: 'hover'
 });


 $('body').on('click', '.enable-editor', function () {
  tinymce.init({
   selector: '.ed-bigtext',
   mode: "exact",
//    theme: "modern",
   plugins: 'textcolor link image lists code table emoticons',
   width: 680,
   height: 150,
   force_br_newlines: true,
   force_p_newlines: false,
   forced_root_block: '',
   relative_urls: false,
   remove_script_host: false,
   toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
   menubar: false,
   statusbar: false,
   valid_elements: '*[*]',
   file_browser_callback: function () {
    $('#comment_attachments').trigger('click');
   }
  });

 });

 $('body').on('click', 'a.erp-links', function (e) {
  e.preventDefault();

  if ($(this).hasClass('search-list-page')) {
   if ($('ul#js_saving_data').find('.headerClassName').data('headerclassname')) {
    var hideSearchPage = $('ul#js_saving_data').find('.hideSearchPage').data('hidesearchpage');
    if (hideSearchPage) {
     return false;
    }
    var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
    var formUrl = 'includes/json/json_blank_search.php?class_name=' + headerClassName;
    getFormDetails(formUrl);
   }
  } else if ($(this).hasClass('form-page')) {
   if ($('input[name="search_class"]')) {
    var headerClassName = $('input[name="search_class"]').val();
    var formUrl = 'form.php?mode=9&class_name=' + headerClassName;
    getFormDetails(formUrl);
   }
  }
 });

 $('body').on('click', '.delete_image', function () {
  $(this).closest('.ino-images').find('.file_id').val('');
  $(this).closest('.ino-images').find('.existing-image').css('display', 'none');
 });


 $('body').on('click', 'a.show2.wip_wo_header_id', function (e) {
  e.preventDefault();
  var wip_wo_header_id = $('#wip_wo_header_id').val();
  var urlLink = $(this).attr('href');
  var formUrl = urlLink + '&wip_wo_header_id=' + wip_wo_header_id;
  getFormDetails(formUrl);
 });


 $("body").on('mouseenter', '.img-vs', function () {
  $(this).next(".hidden-image").show();
 }).on('mouseout', '.img-vs', function () {
  $(this).next(".hidden-image").hide();
 });

 deleteImage();

 $('body').on('blur', '.select.multi-category', function () {
  if ($(this).val()) {
   $(this).clone().appendTo($(this).parent());
  } else {
   var select_count = 0;
   $(this).parent().find('.select.multi-category').each(function () {
    if (!$(this).val()) {
     select_count++;
    }
    if (select_count > 1) {
     $(this).remove();
    }
   });
  }
 });

 $('body').off('click', '.popup-form').on('click', '.popup-form', function (e) {
  e.preventDefault();
  var openUrl = $(this).prop('href');
  var popup_width = $(window).width();
  var popup_height = $(window).height();
  void window.open(openUrl, '_blank',
          'width=' + popup_width + ',height=' + popup_height + ',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// $('body').on('click', '.readonly', function () {
//  alert('Readonly Field!');
// });
 magnifier();

 $('body').on('click', 'a.add-to-cart', function (e) {
  e.preventDefault();
  $.when(save_dataInSession({
   data_name: 'ec_product_id',
   data_value: $('#ec_product_id').val(),
   over_write: 0
  })).then(function () {
//   alert('Cart is updated');
   var no_of_item = +$('#no-of-cart-items').html();
   no_of_item++;
   +$('#no-of-cart-items').html(' ' + no_of_item + ' ');
   carTupdateAnimation();
  });
 });




 $('body').on('click', '.remove_from_cart', function (e) {
  var data_value = $(this).closest('tr').find('.ec_product_id').val();
  $.when(save_dataInSession({
   data_name: 'ec_product_id',
   data_value: data_value,
   remove_data: true,
   over_write: 1
  })).then(function () {
   var no_of_item = +$('#no-of-cart-items').html();
   no_of_item--;
   +$('#no-of-cart-items').html(' ' + no_of_item + ' ');
   carTupdateAnimation();
  });
 });

 $('body').off('click', '#copy_clipboard').on('click', '#copy_clipboard', function () {
  var actionStmt = '<div class="search_result"><table>';
  $('td.search_result.action').each(function () {
   actionStmt += '<tr><td>' + $(this).prev().html() + '</td>';
   actionStmt += '<td>' + $(this).nextAll().slice(1, 2).html() + '</td>';
   actionStmt += '<td>' + $(this).html() + '</td></tr>';
  });
  actionStmt += '</table></div>';
//actionStmt += '<div class="page_nos">' +$('#searchResult').find('.page_nos.pagination').html() + '</div>';

  $('#left-clipboard-data').append(actionStmt);
  $('#accordion h3.clipboard-data').trigger('click');
 });


 $('body').on('click', '.clear-clipboard', function () {
  $('#left-clipboard-data').empty();
 });

 $('body').on('click', '.ino-close-form', function (e) {
  e.preventDefault();
  var pathContent = $('#hidden-div').html();
  $('#hidden-div #path_by_module').replaceWith('<div id="hidden-div-content"></div>');
  $('#structure').replaceWith('<div id="structure">' + pathContent + '</div>');
 });

 var mfc = 0;
 var minmize_forms = [];
 $('body').off('click', '#ino-minimize-form').on('click', '#ino-minimize-form', function () {
  mfc++;
  if ($('ul#js_saving_data').find('.headerClassName').length > 0) {
   var headerClassName = toUpperCase($('ul#js_saving_data').find('.headerClassName').data('headerclassname').replace(/_/g, ' '));
   var primary_column_id_h = '#' + $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  } else if ($('#searchForm').length > 0) {
   var headerClassName = toUpperCase($('#searchForm').find('.search.class_name').val().replace(/_/g, ' '));
   primary_column_id_h = null;
  } else if ($('ul#js_saving_data').find('.lineClassName').length > 0) {
   var headerClassName = toUpperCase($('ul#js_saving_data').find('.lineClassName').data('lineclassname').replace(/_/g, ' '));
   var primary_column_id_h = null;
  }
  var minStmt = '<li type="button" data-mfc="' + mfc + '" class="clickable list-group-item min-form-list min-form-count-' + mfc + '">';
  minStmt += '<button class="close" aria-label="Close" data-dismiss="alert" type="button"><span aria-hidden="true">×</span></button>';
  minStmt += headerClassName;
  if (primary_column_id_h !== null) {
   minStmt += ' : ' + $(primary_column_id_h).val();
  }
  minStmt += '</li>';

  minmize_forms[mfc] = $('#structure').html();
  localStorage.setItem("minmize_forms_str", JSON.stringify(minmize_forms));

  $('ul#minform-list').append(minStmt);
  if ($('ul#minform-list').find('li').length == 1) {
   $('#accordion h3.minform-data').trigger('click');
  }
  $(this).closest('ul').find('.ino-close-form').trigger('click');
 });

 $('body').on('click', '.min-form-list', function (e) {
  $('.show_loading_small').show();
  $(this).parent().find('li').removeClass('active');
  $(this).addClass('active');
  e.preventDefault();
  var mfc_n = $(this).data('mfc');
  var minmize_forms = JSON.parse(localStorage.getItem("minmize_forms_str"));
  var structContent = minmize_forms[mfc_n];
  $('#structure').replaceWith('<div id="structure">' + structContent + '</div>');
  $.getScript(homeUrl + "includes/js/reload.js").done(function () {
   $('.show_loading_small').hide();
  });
 });

 $('body').on('click', 'ul#minform-list .close', function (e) {
  $(this).closest('li').remove();
  e.stopPropagation();
 });


 $('body').on('click', '.get-view-content', function () {
  var view_id = $(this).data('view_id');
  if ($(this).data('update_divId')) {
   var update_divId_h = '#' + $(this).data('update_divId');
  } else {
   var update_divId_h = $(this).prop('hash');
  }

  if (!$(update_divId_h).text().trim()) {
   getViewResultByViewId({
    view_id: view_id,
    update_divId_h: update_divId_h

   });
  }

 });

 $('body').off('click', '.get-report-content').on('click', '.get-report-content', function () {
  var report_id = $(this).data('report_id');
  if ($(this).data('update_divId')) {
   var update_divId_h = '#' + $(this).data('update_divId');
  } else {
   var update_divId_h = $(this).prop('hash');
  }

  if (!$(update_divId_h).text().trim()) {
   getReportResultByReportId({
    report_id: report_id,
    update_divId_h: update_divId_h

   });
  }

 });

//tracking unsaved changes
 $('#erp_form_area').on('change', 'form[method="post"] :input', function (e) {
  if ($(this).hasClass('action')) {
   return true;
  }
  var noof_field_changes = $('#unsaved_fields').data('no_of_fields');
  //if (noof_field_changes < 1) {
  // $('#unsaved_fields').html('<span role="button" class="btn btn-warning btn-sm unsaved-msg">'+ noof_field_changes+' Unsaved Changes</span>');
  //}
  noof_field_changes++;
  if (noof_field_changes == 1) {
   $('#unsaved_fields').html('<span role="button" class="btn btn-warning btn-sm unsaved-msg">' + noof_field_changes + ' ' + unsaved_change + '</span>');
  } else {
   $('#unsaved_fields').html('<span role="button" class="btn btn-warning btn-sm unsaved-msg">' + noof_field_changes + ' ' + unsaved_changes + '</span>');
  }
  $('#unsaved_fields').data('no_of_fields', noof_field_changes);
 });

 $('body').on('click', '.get-report-content', function () {
  var report_id = $(this).data('report_id');
  if ($(this).data('update_divId')) {
   var update_divId_h = '#' + $(this).data('update_divId');
  } else {
   var update_divId_h = $(this).prop('hash');
  }

  if (!$(update_divId_h).text().trim()) {
   getReportResultByReportId({
    report_id: report_id,
    update_divId_h: update_divId_h
   });
  }
 });

 $('body').on('click', '#multi_fp_kanban_suggestion_v .line_id_cb', function () {
  if (!$(this).closest('tr').find('.fp_kanban_header_id').val()) {
   $(this).attr('checked', false);
   alert('No Kaban Found!\nFirst create a kanban card');
   var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   $('#multi_fp_kanban_suggestion_v').find(trClass).find(':input').prop('disabled', true);
  }
 });
 $('body').on('change', '#multi_fp_kanban_suggestion_v .overwrite_kanban_multibin_number, #multi_fp_kanban_suggestion_v .overwrite_kanban_multibin_size', function () {
  if (!$(this).closest('tr').find('.fp_kanban_header_id').val()) {
   $(this).attr('checked', false);
   alert('No Kaban Found!\nFirst create a kanban card');
   var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
   $('#multi_fp_kanban_suggestion_v').find(trClass).find(':input').prop('disabled', true);
  }
 });

 $('body').on('click', '.select_all', function () {
  $('#form_line').find('input[name="line_id_cb"]').prop('checked', true);
 });

 $('body').on('click', '.deselect_all', function () {
  $('#form_line').find('input[name="line_id_cb"]').prop('checked', false);
 });

 $('body').on('click', '#subscribe_cb', function () {
  if (!$('#user_id').val()) {
   alert('Please login to subscribe');
   $(this).prop('checked', false);
  }
 });

//short cut keys ctrl+c to copy value for one field
 $('body').on('keypress', '#form_line :input', function (e) {
  if (!e.ctrlKey) {
   return;
  }

  switch (e.which) {
   case 97 : //copy all data from top row Ctrl + A
    e.preventDefault();
    var prevRow = $(this).closest('tr').prev();
    var this_e = $(this);
    $(prevRow).find(':input').each(function (i, v) {
     if ($(this).hasClass('readonly') || $(this).hasClass('always_readonly') || $(this).hasClass('dontCopy') || $(this).hasClass('dont_copy')) {
      return;
     }
     if (!$(this_e).closest('tr').find(':input:eq(' + i + ')').val()) {
      $(this_e).closest('tr').find(':input:eq(' + i + ')').val($(v).val());
     }
    });
    break;

   case 98 : //copy field value from top row Ctrl + B
    e.preventDefault();
    var parent_td = $(this).closest('td');
    var parent_tr = $(this).closest('tr');
    var ind = $(parent_tr).find('td').index(parent_td);
    $(this).val($(this).closest('tr').prev().find('td:eq(' + ind + ')').find(':input').val());
    break;

   case 120 : //remove line in form line Ctrl + X
    e.preventDefault();
    var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
    $(trClass).find('.remove_row_img').first().trigger('click');
    break;
  }
  $(this).unbind('keypress');
 });

 //short cut keys 
 $('body').on('keydown', '#form_line input', function (e) {
  switch (e.which) {
   case 40 ://add a new row with down arrow
    $('#form_line').find('.add_row_img').first().trigger('click');
    break;
  }
 });

 //save
 $('body').on('keypress', '#content :input', function (e) {
  if (!e.ctrlKey) {
   return;
  }
  switch (e.which) {
   case 100 ://delete data Ctl + D
    e.preventDefault();
    $('#delete_button').trigger('click');
    break;

   case 114 : //referesh data Ctrl + R
    e.preventDefault();
    $('a.show.document_id').trigger('click');
    break;

   case 115 ://save data Ctrl + S
    e.preventDefault();
    $('#save').trigger('click');
    break;

  }
  $(this).unbind('keypress');
 });


 $("#event-datepicker").datepicker({
  changeMonth: true,
  changeYear: true,
  dateFormat: "dd-mm-yy",
  onSelect: function (sd) {
   var date_p = $(this).datepicker('getDate');
   var date_s = ("0" + date_p.getDate()).slice(-2);
   var month_s = ("0" + (date_p.getMonth() + 1)).slice(-2);
   var year_s = date_p.getFullYear();
   var sunday_date_i = date_p.getDate() - date_p.getDay();
   var sunday_date = ("0" + (sunday_date_i)).slice(-2);
   var ino_date = year_s + '-' + month_s + '-' + date_s;
   //day
   $('table.cal-day .col1').find('.cal-date').empty().append(' ' + ino_date + ' ');
   $('tbody.cal-day-tbdy').find('td.col_1').attr('date', ino_date);

   //week
   $('table.cal-week .col1').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_1').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col2').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_2').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col3').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_3').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col4').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_4').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col5').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_5').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col6').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_6').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   sunday_date++;
   sunday_date = ("0" + (sunday_date)).slice(-2);
   $('table.cal-week .col7').find('.cal-date').empty().append(' (' + year_s + '-' + month_s + '-' + sunday_date + ') ');
   $('tbody.cal-week-tbdy').find('td.col_7').attr('date', year_s + '-' + month_s + '-' + sunday_date);
   //month
   $('table.cal-month').find('td').empty();
   $('table.ui-datepicker-calendar td').each(function (i, v) {
    i++;
    var cell_no = 'cell_' + i;
    if ($(this).find('a').length > 0) {
     var date_val = +$(this).find('a').text();
     $('table.cal-month').find('td.' + cell_no).empty().append(date_val);
     $('table.cal-month').find('td.' + cell_no).attr('date', year_s + '-' + month_s + '-' + date_val);
    } else {
     $('table.cal-month').find('td.' + cell_no).empty();
    }
   });
   calendar_update();
   calendar_size_update();
  }

 });

//remove links with no child
 $('ul.block_menu').find('li.parent_menu').each(function () {
  if ($(this).children('ul.child_menu').children().length < 1) {
   $(this).remove();
  }
 });

 $('body').on('click', '.search.reset ', function () {
  $(this).closest('form').find(':input:not(.btn, .readonly, .hidden)').not('readonly').val('');
 });

//serial lot form flip
 $('body').on('click', '.ino-flip.fa-plus-square-o', function () {
  $(this).removeClass('fa-plus-square-o').addClass('fa-minus-square-o');
 }).on('click', '.ino-flip.fa-minus-square-o', function () {
  $(this).removeClass('fa-minus-square-o').addClass('fa-plus-square-o');
 });

 $('body').off('click', '#start_query_mode').on('click', '#start_query_mode', function () {
  $('#form_header .tabContainer').find(':input').val('').addClass('val_field query-mode');
  $('#content').find(':input').val('');
  $('.val_field').inoAutoCompleteElement({
   json_url: 'includes/json/json_validation_field.php',
   primary_column1: 'bu_org_id',
   min_length: 2
  });
 });

//selected files for upload
 $('body').on('change', '#attachments, #comment_attachments', function () {
  var this_e = $(this);
  $(this.files).each(function (k, elem) {
   var thisFile = elem[0];
   var fileSize = elem.size / 1024 / 1024;
   var stmt = '<ul class="inRow asperWidth ready-to-upload">';
   stmt += '<li class="file-details">File Details : </li>';
   stmt += '<li class="file-name">' + elem.name + '</a></li>';
   stmt += '<li class="file-size">' + fileSize.toFixed(2) + " MB" + '</a></li>';
   stmt += '<li class="file-type">' + elem.type + '</a></li>';
   stmt += '</ul>';
   $(this_e).closest('#file_upload_form').find('.uploaded_file_details').append(stmt);
  });
 });

 $('body').on('blur', '#enteredRePassword', function () {
  if ($(this).val() != $('#enteredPassword').val()) {
   alert('You have entered two different passwords');
   $(this).val('');
  }

 });

 if (typeof mandatory_field_color !== 'undefined' && !bg_image_path) {
  $(':input.required').css('background-color', mandatory_field_color);
 }

 if (typeof content_color !== 'undefined' && !bg_image_path) {
  $('.tabContainer, ul.tabMain li.ui-state-active').css('background-color', content_color);
 }

 if (typeof bg_image_path !== 'undefined' && bg_image_path != "") {
//$('.container-fluid').css('background-image', 'url(' + bg_image_path + ')');
  $('#ino-body, body').css('background-image', 'url(' + bg_image_path + ')');
  $('#path_by_module').css('opacity', bg_opacity);
  $('.sidebar').css('background-color', 'transparent');
 }

 var toogleLi = '<li class="ino-toggle-tab pull-right clickable"><i class="fa fa-arrow-circle-up"></i><li>';
 $('#tabsHeader ul.tabMain ').append(toogleLi);


 $('body').off('click', '.ino-toggle-tab').on('click', '.ino-toggle-tab', function () {
  $('#tabsHeader .tabContainer').toggle();
 });

 $('body').on('click', 'a.right_navicon, .ino-close-right-navbar', function () {
  $('#navbar-collapse-right').toggleClass('hidden');
 });

 $('body').on('keypress', '.div-with-preview', function () {
  $(this).parent().find('.ino-text-preview').html($(this).val());

 });

 var last_ww = '601';
 localStorage.setItem("last_ww", last_ww);
 reszieTable();
 $(window).resize(function () {
  clearTimeout(window.resizedFinished);
  window.resizedFinished = setTimeout(function () {
   if ((last_ww > 599) && ($(window).width() < 600) || (last_ww < 599) && ($(window).width() > 600)) {
    $('a.document_id .fa-refresh').trigger('click');
   }
  }, 250);
 });


 $('body').on('click', '.hide-form-row', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(trClass).find('th').not(':first').hide();
  $(trClass).find('td').not(':first').hide();
  $(trClass).find('.ino-control-th.fa-arrow-circle-up').removeClass('fa-arrow-circle-up').addClass('fa-arrow-circle-down');
  $(trClass).find('.hide-form-row').removeClass('hide-form-row').addClass('show-form-row');

 });

 $('body').on('click', '.show-form-row', function () {
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $(trClass).find('th').not(':first').show();
  $(trClass).find('td').not(':first').show();
  $(trClass).find('.ino-control-th.fa-arrow-circle-down').removeClass('fa-arrow-circle-down').addClass('fa-arrow-circle-up');
  $(trClass).find('.show-form-row').removeClass('show-form-row').addClass('hide-form-row');

 });

 $('body').on('change', '#bg_opacity_user', function () {
  opvalue = $(this).val() / 100;
  bg_opacity = opvalue;
  $('.tabContainer').css({
   'opacity': opvalue
  });
 });

 $('body').on('click', '.close-footer-menu', function () {
  $('#half_copyrights').remove();
 });

 $('.enlarge-window').on('click', function () {
  var i = document.getElementById("ino-body");

  if (document.fullscreenElement || document.webkitFullscreenElement || document.mozFullScreenElement || document.msFullscreenElement) {
   if (document.exitFullscreen) {
    document.exitFullscreen();
   } else if (document.webkitExitFullscreen) {
    document.webkitExitFullscreen();
   } else if (document.mozCancelFullScreen) {
    document.mozCancelFullScreen();
   } else if (document.msExitFullscreen) {
    document.msExitFullscreen();
   }
  } else {
   if (i.requestFullscreen) {
    i.requestFullscreen();
   } else if (i.webkitRequestFullscreen) {
    i.webkitRequestFullscreen();
   } else if (i.mozRequestFullScreen) {
    i.mozRequestFullScreen();
   } else if (i.msRequestFullscreen) {
    i.msRequestFullscreen();
   }
  }
 });

//delete category
 $("body").on('click', '.delete-category', function (e) {
  var headerId = $(this).data('category_reference_id');
  if (confirm("Do you really want to delete ?\n" + headerId)) {
   var daletePath = $('#home_url').val() + 'form.php?class_name=category_reference';
   deleteHeaderAjax(daletePath, headerId);
  }
 });

 $('body').on('change', '#ledger_id, #gl_ledger_id', function () {
  $('.ledger_currency').val($(this).find('option:selected').data('currency_code'));
 });


});

function remove_unsaved_msg() {
 $('#unsaved_fields').html('');
 $('#unsaved_fields').data('no_of_fields', '0');
}

var reszieTable = function () {
 if (($(window).width() < 600)) {
  $('table.form_line_data_table > thead').each(function () {
   var thObject = $(this).find('th');
   $(this).closest('table.form_line_data_table').find('tbody.form_data_line_tbody > tr').each(function (trk, trv) {
    $(this).children('td').each(function (k, v) {
     if ($(this).hasClass('add_detail_values')) {
      $(this).find('table.form_detail_data_table > thead').each(function () {
       var thObject1 = $(this).find('th');
       $(this).closest('table.form_detail_data_table').find('tbody.form_data_detail_tbody > tr').each(function () {
        $(this).children('td').each(function (k2, v2) {
         if (k2 > 0) {
          var objWithTd2 = '<td class="ino-th">' + $(thObject1[k2]).html() + '</td>';
          $(this).before(objWithTd2);
         } else {
          var objWithFa2 = '<td class="ino-th">' + $(thObject1[k2]).html() + (' <i class="ino-control-th fa fa-arrow-circle-up clickable hide-form-row"></i>') + '</td>';
          $(this).before(objWithFa2);
         }
        });
       });
      });
     } else {
      if (k > 0) {
       var objWithTd = '<td class="ino-th">' + $(thObject[k]).html() + '</td>';
       $(this).before(objWithTd);
      } else {
       var objWithFa = '<td class="ino-th">' + $(thObject[k]).html() + (' <i class="ino-control-th fa fa-arrow-circle-up clickable hide-form-row"></i>') + '</td>';
       $(this).before(objWithFa);
      }
     }

    });
   });
  });

 }
};


function copyOriginalTable(original)
{
 original.wrap("<div class='table-wrapper' />");
 var copy = original.clone();
 copy.find("td:not(:first-child), th:not(:first-child)").css("display", "none");
 copy.removeClass("responsive");
 original.closest(".table-wrapper").append(copy);
 copy.wrap("<div class='pinned' />");
 original.wrap("<div class='scrollable' />");
}
function unsplitTable(original) {
 original.closest(".table-wrapper").find(".pinned").remove();
 original.unwrap();
 original.unwrap();
}
