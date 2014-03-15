$(document).ready(function() {

  //basic finction --making background colors for form fields
  $("input").focus(function() {
    $(this).css("background-color", "#cccccc");
  });
  $("input").blur(function() {
    $(this).css("background-color", "#ffffff");
  });
  $("input:required").css("background-color", "pink");
  $("input:required").focus(function() {
    $(this).css("background-color", "pink");
  });
  $("input:required").blur(function() {
    $(this).css("background-color", "pink");
  });

  //end of basic functions

//Popup for selecting option type
  $(".popup").click(function() {
    void window.open('find_option.php', '_blank',
            'width=700,height=500,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  })

  $("#selected").click(function() {
    var findElement = $(".select_option_id:checked").val();
    window.opener.parentWindow(findElement);
    window.close();
  });

  //Check the option_id while entering the option line code
  document.getElementById("option_line_code").onchange = function() {
    if ($("#option_id").val() == "") {
      document.getElementById("formerror").innerHTML = "First save or select an Option Type";
      $("#option_line_code").val("");
    } else {
      $("#option_id_l").val($("#option_id").val());
    }
  };

  //Get the option_id on find button click
  $('#form_box a.show').click(function() {
    var optionId = $('#option_id').val();
//$(this).prop('href','option.php?option_id_l=' + optionId);
    $(this).attr('href', 'option.php?option_id_l=' + optionId);
  });

//Get the option id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var optionId = $('#option_id').val();
    $('#option_header').attr('action', 'option.php?option_id_l=' + optionId);
  });


//Get the option id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var optionId = $('#option_id').val();
    $('#option_line').attr('action', 'option.php?option_id_l=' + optionId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#option_line"));
    $("#new_object" + objectCount + " .option_line_id").val("");
    $("#new_object" + objectCount + " .option_line_id").focus();
    objectCount++;
  }
  );
    
    //shortcut keys
$(document).bind('keydown', 'alt+n', function(e) {
    $("#add_object").trigger('click');
    });

});

