<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>

<div id="option_line_values">
 <?php
 if ((!empty($_GET["option_line_page"])) && (!empty($_GET["option_line_id"]))) {
	$option_line_id = $_GET['option_line_id'];
	$option_line_object = option_line::find_by_id($option_line_id);
	$option_header_object = option_header::find_by_id($option_line_object->option_header_id);
//	$option_detail_object = Pre_Loading_Function('option', 'option_detail', 'option_detail_value', 'option_detail_id');
 $option_detail_object = option_detail::find_by_option_line_id($option_line_id);
	if (count($option_detail_object) == 0) {
	 $option_detail = new option_detail();
	 $option_detail_object = array();
	 array_push($option_detail_object, $option_detail);
	}
 ?>
 <div id="option_line_values_form">
	<table class="json_form_data_table">
				 <thead>
					<tr>
					 <th>Action</th>
					 <th>Detail Id</th>
					 <th>Value</th>
					 <th>Description</th>
					 <th>E Field</th>
					 <th>Status</th>
					 <th>Revision</th>
					 <th>Rev #</th>
					 <th>Start Date</th>
					 <th>End Date</th>
					</tr>
				 </thead>
				 <tbody>
					<?php
					$count = 0;
					foreach ($option_detail_object as $option_detail) {
					 ?>
 					<tr class="option_detail_tr<?php echo $count; ?>">
 					 <td>   
 						<ul class="inline_action">
 						 <li class="json_add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 						 <li class="json_remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 						 <li><input type="checkbox" name="option_line_id_cb" value="<?php echo htmlentities($option_detail->option_detail_id); ?>"></li>           
						 <li><?php echo form::hidden_field('option_line_id', $option_line_object->option_line_id); ?></li>
						 <li><?php echo form::hidden_field('option_header_id', $option_header_object->option_header_id); ?></li>
						
						 </ul>
 					 </td>
 					 <td><?php echo form::text_field('option_detail_id', $option_detail->option_detail_id, '8', '12', '', 'System number', 'option_detail_id'); ?></td>
 					 <td><?php echo form::text_field('option_detail_value', $option_detail->option_detail_value, 'required', '20', '50', 'No special characters', ''); ?></td>
 					 <td><?php echo form::text_field('description', $option_detail->description, '20'); ?></td>
 					 <td><?php echo form::extra_field($option_detail->efid, '5'); ?></td>
 					 <td><?php echo form::status_field($option_detail->status); ?></td>
 					 <td><?php echo form::revision_enabled_field($option_detail->rev_enabled); ?></td>
 					 <td><?php echo form::text_field('rev_number', $option_detail->rev_number, '5'); ?></td>
 					 <td><?php echo form::date_field('effective_start_date', $option_detail->effective_start_date, '10', '', '', ''); ?></td>
 					 <td><?php echo form::date_field('effective_end_date', $option_detail->effective_end_date, '10', '', '', ''); ?></td>
 					</tr>
					 <?php
					 $count++;
					}
					?>
				 </tbody>
				</table>
	</div>
	
<?php }
 ?>
</div>

<div id="coa_json">
 <?php
 if (!empty($_GET["option_id"])) {
	$option_id_l = $_GET["option_id_l"];
	$option_line_object = option_line::find_by_option_id($option_id_l);
	if (count($option_line_object) == 0) {
	 return false;
	} else {
	 foreach ($option_line_object as $key => $value) {
		echo '<option value="' . $value->option_line_code . '"';
		echo '>' . $value->option_line_code . '</option>';
	 }
	}
 }
 ?>
</div>

<div id="json_delete_option_line">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	$option_line_id = $_GET['option_line_id'];

	$result = option_line::delete($option_line_id);

	if ($result == 1) {
	 echo 'Option line is deleted!';
	} else {
	 echo " Error code: $result ! ";
	}
 }
 ?>
</div>

<div id="json_save_option_header">
 <?php
 if (!empty($_POST['option_header'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['option_header']);
	$postArray['submit_option_header'] = '1';
	$_POST = $postArray;

	$option_header = Pre_Loading_Function('option', 'option_header', 'option_type', 'option_header_id');
	if (!empty($option_header->option_header_id)) {
	 echo '<div class="message">Option header is sucessfully saved! </div>';
	 echo '<div id="option_headerId">' . $option_header->option_header_id . '</div>';
	} else {
	 echo " Error code:  ! ";
	 echo '<pre>';
	 print_r($option_header);
	 echo '<pre>';
	}
 }
 ?>
</div>

<div id="json_save_option_line">
 <?php
 if (!empty($_POST['option_line'])) {
	$option_header_id = $_POST['option_header_id'];
	$option_header_idArray = [];

	$postArray = get_postArray_From_jqSearializedArray($_POST['option_line']);
	foreach ($postArray['option_line_code'] as $option_line_code) {
	 array_push($option_header_idArray, $option_header_id);
	}
	$postArray['submit_option_line'] = '1';
	$postArray['option_header_id'] = $option_header_idArray;

	$_POST = $postArray;

	$option_line = Pre_Loading_Function('option', 'option_line', 'option_line_code', 'option_line_id');

	if (!empty($option_line->option_line_id)) {
	 echo '<div class="message">Option line is sucessfully saved! </div>';
	 echo '<div class="option_lineId">' . $option_line->option_line_id . '</div>';
	} else {
	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($option_line);
	 echo '<pre>';
	}
 }
 ?>
</div>

 <?php include_template('footer.inc') ?>