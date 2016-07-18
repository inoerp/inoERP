function setValFromSelectPage(sys_notification_id, combination) {
 this.sys_notification_id = sys_notification_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var sys_notification_id = this.sys_notification_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (sys_notification_id) {
	$("#sys_notification_id").val(sys_notification_id);
 }
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
 //selecting Id
 $(".sys_notification_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_notification', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});
