function getImportStatus(options) {
 var defaults = {
  json_url: 'engine/install/json_install.php',
 };
 var settings = $.extend({}, defaults, options);

 $.ajax({
  url: settings.json_url,
  type: 'get',
  dataType: 'json',
  data: {
   find_import_status: 1
  },
  success: function (result) {
   if (result) {
    $.each(result, function (key, value) {
     var importStatus = '<br><span id="progress_message" class="message"> Completion % : ' + value + '</span>';
     $('#contents').find('#progress_message').append(importStatus);
    });
   }
   else {

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

$(document).ready(function () {
 $('#complete_install').on('click', function (e) {
  var smallLoadingImg = 'files/images/small_loading.gif';
  $('#content').append('<img src="' + smallLoadingImg + '"\> loading...');
//  setInterval("getImportStatus()", 10000);
 });

});

