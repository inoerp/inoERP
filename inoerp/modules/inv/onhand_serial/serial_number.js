function setValFromSelectPage(inv_serial_number_id, item_id, item_number, item_description ) {
 this.inv_serial_number_id = inv_serial_number_id;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
}


setValFromSelectPage.prototype.setVal = function() {
 var inv_serial_number_id = this.inv_serial_number_id;
 if (inv_serial_number_id) {
	$("#inv_serial_number_id").val(inv_serial_number_id);
 }
 if ( this.item_id ) {
	$("#item_id").val( this.item_id );
 }
  if ( this.item_number ) {
	$("#item_number").val( this.item_number );
 }
  if ( this.item_description ) {
	$("#item_description").val( this.item_description );
 }
};

$(document).ready(function() {
 //selecting Id
 $(".inv_serial_number_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=inv_serial_number', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the inv_serial_number_id on find button click
 $('a.show.inv_serial_number_id').click(function() {
	var inv_serial_number_id = $('#inv_serial_number_id').val();
	$(this).attr('href', modepath() + 'inv_serial_number_id=' + inv_serial_number_id);
 });


//
$('#org_id').on('change', function(){
$('#current_org_id').val($(this).val());
})

 //get Subinventory Name
 $("#scope_org_id").on("change", function() {
    getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#scope_org_id").val()
  });
 });

 $('#fp_mrp_header_id, #fp_forecast_header_id').on('change', function() {
	var orgID = $(this).find('option:selected').data('org_id');
	$('#scope_org_id').val(orgID).prop('disabled', true);
	  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#scope_org_id").val()
  });
 });

});
