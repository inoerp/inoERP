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

//Popup for selecting module type
  $(".popup").click(function() {
    void window.open('find_module.php', '_blank',
            'width=700,height=500,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  })

  $("#selected").click(function() {
    var findElement = $(".select_module_id:checked").val();
    window.opener.parentWindow(findElement);
    window.close();
  });

  //Check the module_id while entering the module line code
  document.getElementById("module_line_code").onchange = function() {
    if ($("#module_id").val() == "") {
      document.getElementById("formerror").innerHTML = "First save or select an Option Type";
      $("#module_line_code").val("");
    } else {
      $("#module_id_l").val($("#module_id").val());
    }
  };

  //Get the module_id on find button click
  $('#form_box a.show').click(function() {
    var moduleId = $('#module_id').val();
//$(this).prop('href','module.php?module_id_l=' + moduleId);
    $(this).attr('href', 'module.php?module_id_l=' + moduleId);
  });

//Get the module id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var moduleId = $('#module_id').val();
    $('#module_header').attr('action', 'module.php?module_id_l=' + moduleId);
  });


//Get the module id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var moduleId = $('#module_id').val();
    $('#module_line').attr('action', 'module.php?module_id_l=' + moduleId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#module_line"));
    $("#new_object" + objectCount + " .module_line_id").val("");
    objectCount++;
  }
  );

});

