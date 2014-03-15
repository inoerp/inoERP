$(document).ready(function() {
//add new line
onClick_add_new_row('tr.locator0', 'tbody.locator_values', 1);

//add new line by using + sign    
 save('json.locator.php', '#locator', '', 'locator', '#locator_id');

//delete line
 deleteData('json.locator.php');
 
////get the new search criteria
//new_searchCriteria_onClick('json.locator.php');

});
