<?php include_once("../../../includes/basics/basics.inc"); ?>

<?php
if (!empty($_GET['subinventory_id']) && ($_GET['find_all_locator'] = 1)) {
 echo '<div id="json_locator_find_all">';
 $loc = new locator();
 $loc->subinventory_id = $_GET['subinventory_id'];
 $locators = $loc->findAll_ofSubinventory();
 if (empty($locators)) {
	return false;
 } else {
   echo '<option value=" "> </option>';
	foreach ($locators as $key => $value) {
	 echo '<option value="' . $value->locator_id . '"';
	 echo '>' . $value->locator . '</option>';
	}
 }
 echo '</div>';
}
?>
