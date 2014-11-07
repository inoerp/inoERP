(function($) {

 //form amount validations
 $.fn.validateAmount = function(options) {
	var defaults = {
	 header_amount_id: '#header_amount',
	 line_amount_class: '.amount',
	 remaining_amount_class: '.remaining_amount',
	};
	var methods = {
	 checkHeaderAmount: function() {
		var totalAmount = 0;
		var header_amount = +$(defaults.header_amount_id).val();
		$(defaults.line_amount_class).each(function() {
		 totalAmount += (+$(this).val());
		});
		if (totalAmount > header_amount) {
		 $(defaults.header_amount_id).val('');
		 alert('Sum of line amounts ' + totalAmount + ' is more than header amount ' + header_amount + '\n Re-enter Header Amount!');
		}
	 },
	 checkRemainingAmount: function() {
		var remainong_amount = +$(defaults.remaining_amount_class).val();
		var trClass = '.' + $(this).closest('tr').prop('class');
		if(remainong_amount < 0 ){
		 alert('Entered amount is more than remaining amount'+ '\n Re-enter the amount!');
		 $(this).val('');
		 $('#form_line').find(trClass).find(defaults.line_amount_class).val('');
		}
		
	 },
	 hide: function( ) {
	 },
	};

	return this.each(function() {
	 var settings = $.extend({}, $.fn.validateAmount.defaults, options);
	 $(this).on('blur', defaults.header_amount_id, methods.checkHeaderAmount);
	 $(this).on('change', defaults.line_amount_class, methods.checkHeaderAmount);
	 $(this).on('blur', defaults.remaining_amount_class, methods.checkRemainingAmount);
	});
 };
}(jQuery));