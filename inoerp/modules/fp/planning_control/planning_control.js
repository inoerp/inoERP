function setValFromSelectPage(address_name) {
 this.address_name = address_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var address_name = this.address_name;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (address_name) {
	$("#content").find(fieldClass).val(address_name);
 }
};


$(document).ready(function() {

 //Get the fp_planning_control_id on find button click
 $('a.show.org_id').click(function() {
	var org_id = $('#org_id').val();
	$(this).attr('href', modepath() + 'org_id=' + org_id);
 });

});

