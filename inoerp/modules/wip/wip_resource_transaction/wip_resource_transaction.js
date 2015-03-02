function setValFromSelectPage(wip_wo_header_id, wo_number, org_id) {
 this.wip_wo_header_id = wip_wo_header_id;
 this.wo_number = wo_number;
 this.org_id = org_id;
}

setValFromSelectPage.prototype.setVal = function () {
 var wo_obj = [{id: 'wip_wo_header_id', data: this.wip_wo_header_id},
  {id: 'wo_number', data: this.wo_number},
  {id: 'org_id', data: this.org_id}
 ];

 $(wo_obj).each(function (i, value) {
  if (value.data) {
   var fieldId = '#' + value.id;
   $('#content').find(fieldId).val(value.data);
  }
 });
 
  if (this.wip_wo_header_id) {
    $('a.show.wip_resource_transaction_id').trigger('click');
 }
};

$(document).ready(function () {
 //mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
// mandatoryCheck.mandatoryHeader();

 //selecting wo header id data
 $('body').off("click", '.wip_wo_header_id.select_popup').on("click", '.wip_wo_header_id.select_popup', function () {
  localStorage.idValue = "";
  var link = 'select.php?class_name=wip_wo_header&wo_status=%3DRELEASED';
  void window.open(link, '_blank',
          'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

