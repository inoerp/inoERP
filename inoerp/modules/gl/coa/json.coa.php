<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa.js"></script>
<div id="json_save_header"> <div class="json_message"><?php json_save('gl', 'coa', 'coa_structure_id', 'coa_id'); ?></div></div>
<div id="json_account_type">
<?php
if(!empty($_GET['account_type'])){
 $coa_account_types = coa_segment_values::coa_account_types();
  echo '<select name="account_type[]" id="account_type"  class="account_type"> ';
  foreach ($coa_account_types as $records) {
     echo '<option value="';
     echo $records->option_line_code . '">' . $records->description_l;
     echo '</option>';
  }
  echo '</select>' ;
}

?> 
</div>

<?php include_template('footer.inc') ?>