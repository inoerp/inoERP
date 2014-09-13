<div id="all_contents">
 <div id="content_top"></div>
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content">
    <div id="main">
     <div id="structure">
      <div id="contents">
       
       <?php
        if (empty($_GET['action'])) {
         require_once 'steps/verify.php';
        } else if (!empty($_POST)) {
         require_once 'steps/start_install.php';
        } else if (($_GET['action'] == 'dbsettings')) {
         require_once 'steps/dbsettings.php';
        } else if (($_GET['action'][0] == 'complete_install')) {
         require_once 'steps/complete_install.php';
        }
       ?>
      </div>

     </div>
    </div>
   </div>
  </div>
 </div>
 <div id="content_right_right"></div>
</div>

<div id="content_bottom"></div>
<script type="text/javascript">
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
   success: function(result) {
    if (result) {
     $.each(result, function(key, value) {
      var importStatus = '<br><span id="progress_message" class="message"> Completion % : ' + value + '</span>';
      $('#contents').find('#progress_message').append(importStatus);
     });
    }
    else {

    }
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
 $('#complete_install').on('click', function(e) {
  var smallLoadingImg = 'files/images/small_loading.gif';
  $('#content').append('<img src="' + smallLoadingImg + '"\> loading...');
//  setInterval("getImportStatus()", 10000);
 });

</script>

<?php include_template('footer.inc') ?>
