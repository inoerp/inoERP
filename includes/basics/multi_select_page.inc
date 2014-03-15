<?php
if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
 $show_message .= '</div>';
}
?>
<div id="all_contents">
 <div id="content_right">
	<div id="content">
	 <div id="main">
		<div id="structure">
		 <div id="multi_select">
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<div id="list_contents">
			 <!--			Beginning of line form-->
			 <div id ="form_line" class="multi_select_line">
				<div id="searchForm"><?php echo!(empty($search_form)) ? $search_form : ""; ?></div>
				<?php
				echo '<h2 class="heading">'.$action_message.'</h2>';
				if (empty($search_result)) {
				 return;
				}
				?>
				<div id="tabsLine">
				 <ul class="tabMain">
					<?php
					if (property_exists($class, 'column')) {
					 $column_array = $$class->column;
					} else {
					 $column_array = $class::$column_array;
					}
					$all_columns = !empty($multi_selct_input_fields) ? array_merge($multi_selct_input_fields, $column_array) : $column_array;
					$no_of_columns_per_tab = 9;
					$total_columns = count($multi_selct_input_fields) + count($column_array);
					$no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
					for ($i = 0; $i < $no_of_tabs; $i++) {
					 echo "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
					}
					?>
				 </ul>
				 <div class="tabContainer"> 
					<?php for ($i = 0; $i < $no_of_tabs; $i++) { ?>
 					<div id="tabsLine-<?php echo $i ?>" class="tabContent">
 					 <table class="form_table">
 						<thead> 
 						 <tr>
							 <?php
							 if ($i == 0) {
								echo "<th>Action</th>";
							 }
							 $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
							 $new_end = $new_start + ($no_of_columns_per_tab - 1);
							 for ($j = $new_start; $j <= $new_end; $j++) {
								if ($j > $total_columns - 1) {
								 break;
								}
								echo '<th>' . $all_columns[$j] . '</th>';
							 }
							 ?>
 						 </tr>
 						</thead>
 						<tbody class="form_data_line_tbody multi_select_values" >
							<?php
							$count = 0;
							foreach ($search_result as $records) {
							 ?>         
							 <tr class="multi_select_value_line<?php echo $count ?>">
								<?php
								if ($i == 0) {
								 echo "<td><input type=\"checkbox\" name=\"line_id_cb\" class=\"line_id_cb\"  value=\"\">";
								 echo "<input type=\"hidden\" name=\"multi_action_class\" class=\"hidden multi_action_class\"  value=\"$class\">";
								 echo "<input type=\"hidden\" name=\"$header_id_name\" class=\"hidden $header_id_name\"  value=\"$header_id_value\">";
								 echo "<input type=\"hidden\" name=\"action\" class=\"hidden action\"  value=\"$action_message\"></td>";
								}
								$new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
								$new_end = $new_start + ($no_of_columns_per_tab - 1);
								for ($k = $new_start; $k <= $new_end; $k++) {
								 if ($k > $total_columns - 1) {
									break;
								 }
								 if ((!empty($multi_selct_input_fields)) && (in_array($all_columns[$k], $multi_selct_input_fields))) {
									$readonly = null;
								 } else {
									$readonly = 'readonly';
								 }
								 $bracketName = $all_columns[$k] . '[]';
								 if ((property_exists($records, $all_columns[$k]))) {
									if ((!empty($multi_selct_input_fields)) && (in_array($all_columns[$k], $multi_selct_input_fields))) {
									 $value = null;
									} else {
									 $value = $records->$all_columns[$k];
									}
									echo "<td><input type=\"text\" name=\"$bracketName\" class=\"text $all_columns[$k]\" value=\"$value\" $readonly size=\"12\"> </td>";
								 } else {
									echo "<td><input type=\"text\" name=\"$bracketName\" class=\"text $all_columns[$k]\" value=\" \" $readonly size=\"12\"> </td>";
								 }
								}
								?>
							 </tr>
							 <?php
							 $count = $count + 1;
							}
							?>
 						</tbody>
 					 </table>
 					</div>
					<?php } ?>

				 </div>

				</div>
			 </div> 
			 <!--End of line form-->
			 <div id="pagination" style="clear: both;">
				<?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
				?>
			 </div>
			</div>
		 </div>
		</div>
	 </div>
	</div>
 </div>
</div>
<script type="text/javascript">
 $(document).ready(function() {
	//multi select save
	var line_key_field = $('input[type="checkbox"]').first().prop('name');
	line_key_field = line_key_field.replace(/\[]/g, " ");
	var action_class = $('[name="action_class_name"]').val();
	var calendarSave = new saveMainClass();
	calendarSave.json_url = 'form.php?class_name=' + action_class;
	calendarSave.single_line = false;
	calendarSave.line_key_field = line_key_field;
	calendarSave.lineClassName = action_class;
	calendarSave.saveMain();
	if (localStorage.getItem("jsfile")) {
	 $.getScript(localStorage.getItem("jsfile"));
	}
 });</script>

<?php include_template('footer_simple.inc'); ?>