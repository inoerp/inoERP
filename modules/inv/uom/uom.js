$(document).ready(function() {
//add new line
onClick_add_new_row('tr.uom0', 'tbody.uom_values', 1);

//add new line by using + sign    
 save('json.uom.php', '#uom', '', 'uom', '#uom_id');

//delete line
 deleteData('json.uom.php');

});
