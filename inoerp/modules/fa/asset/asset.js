function setValFromSelectPage(fa_asset_id, asset_number, hr_employee_id, first_name, last_name,
        identification_id, combination) {
 this.fa_asset_id = fa_asset_id;
 this.asset_number = asset_number;
 this.hr_empoyee_id = hr_employee_id;
 this.first_name = first_name;
 this.last_name = last_name;
 this.identification_id = identification_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function () {
 var fa_asset_id = this.fa_asset_id;


 if (this.asset_number) {
  $("#asset_number").val(this.asset_number);
 }
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (this.first_name && this.first_name != 'undefined') {
  var name = this.first_name + ' ' + this.last_name;
 }

 if (localStorage.getItem("row_class") && localStorage.getItem("row_class") !== 'null') {
  var rowClass = '.' + localStorage.getItem("row_class");
  rowClass = rowClass.replace(/\s+/g, '.');
 }

 if (this.combination) {
  $('#content').find(rowClass).find(fieldClass).val(this.combination);
 }

 if (this.hr_team_header_id) {
  $("#hr_team_header_id").val(hr_team_header_id);
 }

 if (rowClass) {
  if (this.hr_employee_id && this.hr_employee_id != 'undefined') {
   $('#content').find(rowClass).find('.hr_employe_id').val(this.hr_employee_id);
  }
  if (name && this.hr_employee_id != 'undefined') {
   $('#content').find(rowClass).find('.member_employee_name').val(name);
  }
 }
 localStorage.removeItem("row_class");
 if (fa_asset_id) {
  $("#fa_asset_id").val(fa_asset_id);
  $("a.show.fa_asset_id").trigger('click');
 }
};


function beforeSave() {
 var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
 if (!headerClassName || headerClassName == 'undefined') {
  return 1;
 } else if (headerClassName != 'fa_asset') {
  return 1;
 }
 var sum_total_line_units = 0;
 $('.line_units').each(function () {
  sum_total_line_units += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
 });

 var header_units = $('#units').val();
 if (sum_total_line_units == header_units) {
  return 1;
 } else {
  alert('Cant save data as sum of line units is not same as header unit : ' + header_units + ' & sum of line units is : ' + sum_total_line_units);
  return -99;
 }
}

$(document).ready(function () {
//var mandatoryCheck = new mandatoryFieldMain();
//  mandatoryCheck.mandatoryHeader();

 //selecting Id
 $(".fa_asset_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=fa_asset', '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});