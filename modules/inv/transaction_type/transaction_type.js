$(document).ready(function() {
//add new line
onClick_add_new_row('tr.transaction_type0', 'tbody.transaction_type_values', 2);

//Save record
 save('json.transaction_type.php', '#transaction_type', '', 'transaction_type', '#transaction_type_id');

//delete line
 deleteData('json.transaction_type.php');

});


