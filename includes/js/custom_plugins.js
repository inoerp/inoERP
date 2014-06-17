(function($) {
 
 //form amount validations
 $.fn.validateAmount = function(options) {
	var defaults = {
	 header_amount_id: '#header_amount',
	 line_amount_class: '.amount'
	};
	var methods = {
	 checkAmount: function() {
		var totalAmount = 0;
		var header_amount = +$(defaults.header_amount_id).val();
		$(defaults.line_amount_class).each(function() {
		 totalAmount += (+$(this).val());
		});
		if (totalAmount > header_amount) {
		 $(defaults.header_amount_id).val('');
		 alert('Sum of line amounts' + totalAmount + ' is more than header amount ' + header_amount + '\n Re-enter Header Amount!');
		}
	 },
	 hide: function( ) {
	 },
	};

	return this.each(function() {
	 var settings = $.extend({}, $.fn.validateAmount.defaults, options);
	 $(this).on('blur', defaults.header_amount_id, methods.checkAmount);
	 $(this).on('change', defaults.line_amount_class, methods.checkAmount);
	});
 };
}(jQuery));