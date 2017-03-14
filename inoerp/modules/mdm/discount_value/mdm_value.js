$(document).ready(function() {
// var Mandatory_Fields = ["#org_id", "First Select Calendar Name"];
// select_mandatory_fields(Mandatory_Fields);

//Name Value
 $('#form_line').on('focusout', '.year', function() {
	var name = '';
	name += $(this).closest('tr').find('.name_prefix').val();
	name += '-' + $(this).val();
	$(this).closest('tr').find('.name').val(name);
 });

 $('body').off('click', 'a.relation_type').on('click', 'a.relation_type', function (e) {
  e.preventDefault();
  var relation_type = $('#relation_type').val();
  var urlLink = $(this).attr('href');
  var urlLink_a = urlLink.split('?');
  var formUrl = 'includes/json/json_form.php?' + urlLink_a[1] + '&relation_type=' + relation_type ;
  getFormDetails(formUrl);
 }).one();
});  

