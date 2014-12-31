function setValFromSelectPage(inv_abc_valuation_id, valuation_name) {
 this.inv_abc_valuation_id = inv_abc_valuation_id;
 this.valuation_name = valuation_name;
}


setValFromSelectPage.prototype.setVal = function () {
 var inv_abc_valuation_id = this.inv_abc_valuation_id;
 var valuation_name = this.valuation_name;
 if (inv_abc_valuation_id) {
  $("#inv_abc_valuation_id").val(inv_abc_valuation_id);
 }
 if (valuation_name) {
  $("#valuation_name").val(valuation_name);
 }
};

$(document).ready(function () {
 //selecting Id
 $(".inv_abc_valuation_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=inv_abc_valuation', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $(".mdm_bank_account_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=mdm_bank_account_v', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//get Subinventory Name
 $('body').off("change", '#scope_org_id').on("change", '#scope_org_id', function () {
  getSubInventory({
   json_url: 'modules/inv/subinventory/json_subinventory.php',
   org_id: $("#scope_org_id").val()
  });
 });

 $('body').off('change', '#fp_mrp_header_id, #fp_forecast_header_id')
         .on('change', '#fp_mrp_header_id, #fp_forecast_header_id', function () {
          var orgID = $(this).find('option:selected').data('org_id');
          $('#scope_org_id').val(orgID).prop('disabled', true);
          getSubInventory({
           json_url: 'modules/inv/subinventory/json_subinventory.php',
           org_id: $("#scope_org_id").val()
          });
         });

 $('body').off('change', '#criteria')
         .on('change', '#criteria', function () {
          var slected_criteria = $(this).val();
          $('#form_header').find('select').prop('disabled', false);
          switch (slected_criteria) {
           case 'ONHAND_QTY':
           case 'ONHAND_VALUE':
            $('#fp_mrp_header_id').prop('disabled', true);
            $('#fp_forecast_header_id').prop('disabled', true);
            break;

           case 'MRP_DEMAND_QTY':
           case 'MRP_DEMAND_QTY':
            $('#fp_mrp_header_id').prop('required', true);
            $('#fp_forecast_header_id').prop('disabled', true);
            break;

           case 'FORECAST_DEMAND_QTY':
           case 'FORECAST_DEMAND_USAGE':
            $('#fp_mrp_header_id').prop('disabled', true);
            $('#fp_forecast_header_id').prop('required', true);
            break;
          }
         });

});
