function setValFromSelectPage(supplier_id, supplier_number, supplier_name,
 supplier_site_id, supplier_site_name) {
 this.supplier_id = supplier_id;
 this.supplier_number = supplier_number;
 this.supplier_name = supplier_name;
 this.supplier_site_id = supplier_site_id;
 this.supplier_site_name = supplier_site_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var supplier_site_id = this.supplier_site_id;
 var supplier_id = this.supplier_id;
 var supplier_number = this.supplier_number;
 var supplier_name = this.supplier_name;
 var supplier_site_name = this.supplier_site_name;
 var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');

 if (supplier_id) {
  $('#content').find(rowClass).find(".supplier_id").val(supplier_id);
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    $(this).closest('tr').find('.supplier_id').val(supplier_id);
   }
  });
 }

 if (supplier_site_id) {
  $('#content').find(rowClass).find(".supplier_site_id").val(supplier_site_id);
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    $(this).closest('tr').find('.supplier_site_id').val(supplier_site_id);
   }
  });
 }
 if (supplier_number) {
  $('#content').find(rowClass).find(".supplier_number").val(supplier_number);
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    $(this).closest('tr').find('.supplier_number').val(supplier_number);
   }
  });
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    var trClass = '.' + $(this).closest('tr').prop('class');
    trClass = trClass.replace(/\s+/g, '.');
    $('#content').find(trClass).find('.supplier_number').val(supplier_number);
   }
  });
 }

 if (supplier_site_name) {
  $('#content').find(rowClass).find(".supplier_site_name").val(supplier_site_name);
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    $(this).closest('tr').find('.supplier_site_name').val(supplier_site_name);
   }
  });
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    var trClass = '.' + $(this).closest('tr').prop('class');
    trClass = trClass.replace(/\s+/g, '.');
    $('#content').find(trClass).find('.supplier_site_name').val(supplier_site_name);
   }
  });
 }

 if (supplier_name) {
  $('#content').find(rowClass).find(".supplier_name").val(supplier_name);
  $('#content').find(rowClass).find(".select_supplier_name").val(supplier_name);
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    $(this).closest('tr').find('.select_supplier_name').val(supplier_name);
   }
  });
  $('#content').find('.line_id_cb').each(function() {
   if ($(this).prop('checked')) {
    var trClass = '.' + $(this).closest('tr').prop('class');
    trClass = trClass.replace(/\s+/g, '.');
    $('#content').find(trClass).find('.supplier_name').val(supplier_name);
   }
  });

 }

 localStorage.removeItem("row_class");

};

$(document).ready(function() {

 $('.line_id_cb').each(function() {
  var trClass = '.' + $(this).closest('tr').attr('class');
  var requisition_status = $('#content').find(trClass).find('.requisition_status').val();
  if (requisition_status == 'APPROVED') {
   $('#content').find(trClass).find('input').each(function() {
    $(this).css('background', 'rgba(204,255,153,0.8)');

   });
  } else {
   $('#content').find(trClass).find('input').each(function() {
    $(this).css('background', 'rgba(255,40,0,0.5)');
   });
  }
 });

 $('body').off("blur", '.select_supplier_name').on("blur", '.select_supplier_name', function() {
  var trClass = '.' + $(this).closest('tr').prop('class');
  function afterFunction(result) {
   var new_name = 'select_supplier_site_id[]';
   var supplier_sites = $(result).find('div#json_supplierSites_find_all').html();
   $(trClass).find('.supplier_site_name').first().replaceWith(supplier_sites).removeAttr('id');
   $(trClass).find('.supplier_site_id').removeAttr('id');
   $(trClass).find('.supplier_site_id').first().prop('name', new_name);
   $(trClass).find('.supplier_site_id').first().addClass('supplier_site_name');
  }
//  if (($(this).closest('tr').find('.supplier_id').val()) && ($(this).closest('tr').find('.bu_org_id').val())) {
//   var bu_org_id = $(this).closest('tr').find('.bu_org_id').val();
//   var supplier_id = $(this).closest('tr').find('.supplier_id').val();
//   getSupplierDetails('modules/ap/supplier/json_supplier.php', bu_org_id, supplier_id, afterFunction);
//
//  }
 });

 $('#content').on('mouseenter', '.select_supplier_name', function() {
  $(this).addClass('search_data');
 }).on('mouseleave', '.select_supplier_name', function() {
  $(this).removeClass('search_data');
 });

 $('#content').off('change', '.supplier_site_id').on('change', '.supplier_site_id', function() {
  $(this).closest('tr').find('.supplier_site_id').val($(this).val());
 });

//selecting supplier
 $('body').off("click", '.select_supplier_name').on("click", '.select_supplier_name',function() {
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class", rowClass);
  void window.open('select.php?class_name=supplier_all_v', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


$('#multi_po_convert_requisition_v').find('.supply_org_id ').each(function(){
  if($(this).val()){
  $(this).closest('tr').find('.multi_select_input').attr('disabled', true).addClass('readonly');
  }else{
  }
});

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'po_header_id';
 classContextMenu.docLineId = 'po_line_id';
 classContextMenu.btn1DivId = 'po_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'po_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 6;
 //classContextMenu.contextMenu();

 deleteData('form.php?class_name=po_requisition_interface&line_class_name=po_requisition_interface');



});
