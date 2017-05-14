function setValFromSelectPage(option_header_id, option_type, description, module_code) {
 this.option_header_id = option_header_id;
 this.option_type = option_type;
 this.description = description;
 this.module_code = module_code;
}

setValFromSelectPage.prototype.setVal = function() {
 var arr = ['option_header_id','option_type','description','module_code'];
  if(this.option_header_id){
 $("#option_header_id").val(this.option_header_id);
}
 if(this.option_type){
 $("#option_type").val(this.option_type);
}
 if(this.description){
 $("#description").val(this.description);
}
 if(this.module_code){
 $("#module_code").val(this.module_code);
}
};

 //Check the option_id while entering the option line code
 function copy_option_header_id() {
  $(".option_line_code").blur(function()
  {
   if ($("#option_header_id").val() == "") {
    alert("First save header or select an Option Type");
    $(".option_line_code").val("");
   } else {
    $(".option_header_id").val($("#option_header_id").val());
   }
  });
 }


$(document).ready(function() {
//  var mandatoryCheck = new mandatoryFieldMain();
// mandatoryCheck.header_id = 'option_header_id';
// mandatoryCheck.mandatoryHeader();
 
 //Popup for selecting option type
  $(".option_header_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=option_header', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

 copy_option_header_id();
 
 
  $('body').off('click', '#menu_button4, #menu_button4_2, #menu_button4_2_1').on('click', '#menu_button4, #menu_button4_2, #menu_button4_2_1', function () {
  $('#option_type, #access_level').removeClass('always_readonly').removeAttr('readonly');
   });

});

