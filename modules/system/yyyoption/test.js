$("document").ready(function(){
  alert ("window is ready");
});

$("p").clone().add("<span>Again</span>").appendTo(document.body);
$("#form_line").clone().appendTo($("#option"));

$("form_line").clone().appendTo(document.getElementById("option"));