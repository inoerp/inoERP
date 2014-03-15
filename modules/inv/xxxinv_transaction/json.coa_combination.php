<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa_combination.js"></script>

<div id="json_account_type">
<?php
$coa_account_types = coa_segment_values::coa_account_types();
  echo '<select name="account_type[]" id="account_type"  class="account_type"> ';
  foreach ($coa_account_types as $records) {
     echo '<option value="';
     echo $records->option_line_code . '">' . $records->description_l;
     echo '</option>';
  }
  echo '</select>' ;
?> 
</div>

<div id="json_combination">
 <?php
 // if the 'term' variable is not sent with the request, exit
if ( !isset($_REQUEST['term']) )
	exit;
$coa_combination = $_REQUEST['term'];
$data = coa_combination::find_coa_combination_by_coa_combination($coa_combination);

echo json_encode($data);
?>
</div>

<?php include_template('footer.inc') ?>