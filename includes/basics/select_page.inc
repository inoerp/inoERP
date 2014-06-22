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
<script type="text/javascript">
 $(document).ready(function() {
	$('#select_page').on('click', '#search_reset_btn', function(e) {
	 e.preventDefault();
	 $(this).closest('#searchForm').find('.search_form').find('input:text, select').each(function() {
		$(this).val('');
	 });
	})

 });
</script>
<div id="all_contents">
	<div id="content">
	 <div id="main">
		<div id="structure">
		 <div id="select_page">
			<div id ="form_header">
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <ul id="form_box"> 
			</div>
			<div id="list_contents">
			 <div id="searchForm"><?php echo!(empty($search_form)) ? $search_form : ""; ?></div>
			 <div id="form_line" class="form_line">
				<div id="print">
				 <table class="find_page normal">
					<thead> 
					 <tr>
						<th>Click Select</th>
						<?php
						if (property_exists($class, 'column')) {
						 $column_array = $$class->column;
						} else {
						 $column_array = $class::$column_array;
						}
						foreach ($column_array as $key => $value) {
						 echo '<th>' . $value . '</th>';
						}
						?>
					 </tr>
					</thead>

					<?php
					If (!empty($search_result)) {
					 echo '<tbody>';
					 foreach ($search_result as $record) {
						$primary_column = $class::$primary_column;
						echo '<tr>';
						echo '<td><input type="button" class="quick_select button" name[]="' . $primary_column . '"
          value="' . $record->$primary_column . '"></td>';
						foreach ($column_array as $key => $value) {
						 echo "<td class=\"$value\">" . $record->$value . '</td>';
						}
						echo '</tr>';
					 }
					 echo '</tbody>';
					}
					?>

				 </table>

				</div>
			 </div>

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


</body>
</html>
<?php
global $dbc;
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>

