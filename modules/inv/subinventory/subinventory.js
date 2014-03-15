$(document).ready(function() {
//add new line
onClick_add_new_row('tr.subinventory0', 'tbody.subinventory_values', 3);

//Save record
 save('json.subinventory.php', '#subinventory', '', 'subinventory', '#subinventory_id');

//delete line
 deleteData('json.subinventory.php');

});


