$(document).ready(function() {

//get the block form
 $("#block_button").click(function() {
	getBlockForm();
 });

 function getBlockForm() {
	$('#loading').show();
	var block_id = $("#block_id").val();
	$.ajax({
	 url: '../block/block.php',
	 data: {reference_table: 'block',
		reference_id: block_id},
	 type: 'get'
	}).done(function(data) {
	 var div = $('#block', $(data)).html();
	 $("#new_block").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Block block loading failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }


//Delete from block list
 $("#delete_row").click(function() {
	$('input[name="block_id_cb"]:checked').each(function() {
	 var block_id = $(this).val();
	 if (confirm("Are you sure?")) {
		deleteBlock(block_id);
	 }
	});
 });

//Delete the block form
 $(".delete_button").click(function() {
	var block_id = $(this).val();
	if (confirm("Are you sure?")) {
	 deleteBlock(block_id);
	}
 });

 function deleteBlock(block_id) {
	$('#loading').show();
	$.ajax({
	 url: 'json.block.php',
	 data: {delete: '1',
		block_id: block_id},
	 type: 'get'
	}).done(function(data) {
	 var div = $('#json_delete_block', $(data)).html();
	 $(".error").append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Block delete failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

//Update the block form
 $(".update_button").click(function() {
	var block_id = $(this).val();
	var ulclass = $(this).closest("ul").parent().parent().children("li.line_li");
	if (confirm("Are you sure?")) {
	 updateBlock(block_id, ulclass);
	}
 });

 function updateBlock(block_id, ulclass) {
	$('#loading').show();
	$.ajax({
	 url: '../block/json.block.php',
	 data: {update: '1',
		block_id: block_id},
	 type: 'get'
	}).done(function(data) {
	 var div = $('#json_update_block', $(data)).html();
	 $(ulclass).append(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("Block update failed");
	 $('#loading').hide();
	});
// $(".form_table #subinventory_id").attr("disabled",false);
 }

//dont allow enable/disbale on blocks page
 $('#content').on('click', '.enabled_cb', function() {
	alert('You can\'t enable/disbale blocks from this page \nNavigate to the block page to change the status');
 });

 save('json.block.php', '#block_header', 'line_id_cb', 'block_id', '#block_id', '', '');
 
 //updating block ids through observere
 // Define the target. #content or any higher level
 var target = $("#content")[0];

// Set the configuration for the observer:
 var config = {
	attributes: true,
	childList: true,
	characterData: true,
	subtree: true
 };

// Create a new instance for the observer
 var observer = new MutationObserver(function(mutations) {
	mutations.forEach(function(mutation) {
	 var addedNodes = mutation.addedNodes;  // All newly added nodes
	 if (addedNodes) {
		$(addedNodes).each(function() {
     if($(this).hasClass('json_message')){
			$(this).find('#linids').find('li').each(function(){
			var idNumber = +$(this).html();
			var blockName = $(this).attr('class');
			$('#block_header').find('.name').each(function(){
			if($(this).val() == blockName){
			$(this).closest('tr').find('.block_id').val(idNumber);
			}
			});
			});
		 }
		 //all the functions goes here for new nodes
		});
	 }
	});
 });

//start it
 observer.observe(target, config);
});
