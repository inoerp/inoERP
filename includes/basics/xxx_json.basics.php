<?php
$dont_check_login = true;
include_once("basics.inc");
?>

<div id="all_blocks">
 <?php
 /*
	* Firt find all blocks as per the role & visibility settings
	* Check if any block is cache enabled - If yes, get the content from block_cache using block_id & session_id
	* If not cache enabled then get the content
	* Open another Json link with show_block_content as soon as content is available
	*/

 function get_showFlag_from_visibilityOption($block_visibility, $visibility_option, $url) {
	$ulr_vars = explode("/", $url);
	$show_block_flag = 0;
	if (empty($visibility_option)) {
	 $show_block_flag = 1;
	}

	if ($visibility_option == 1) {
	 if (array_search($block_visibility, $ulr_vars)) {
		$show_block_flag = 1;
	 } elseif (strpos($url, $block_visibility) !== false) {
		$show_block_flag = 1;
	 } else {
		$show_block_flag = 0;
	 }
	}

	if ($visibility_option == 2) {
	 if (array_search($block_visibility, $ulr_vars)) {
		$show_block_flag = 0;
	 } else {
		$show_block_flag = 1;
	 }
	}

	if ($visibility_option == 3) {
	 if ($block_visibility == 1) {
		$show_block_flag = 1;
	 } else {
		$show_block_flag = 1;
	 }
	}
	return $show_block_flag;
 }

 if (!empty($_POST['all_blocks']) && $_POST['all_blocks'] == 1) {
	$block = new block();
	$all_blocks_array = $block->findAll_AvailableBlocks();
	$parameters = !empty($_POST['parameters']) ? $_POST['parameters'] : null;

	$blocks_by_position = array();
	$block_count = 0;
	$url = $_POST['pathname'];

	foreach ($all_blocks_array as $records) {
	 pa($records);
	 $block_count++;
	 $position = $records->position;
	 $title = $records->title;
	 $visibility_option = $records->visibility_option;
	 $block_visibility = base64_decode($records->visibility);
	 $reference_table = $records->reference_table;
	 $show_block_flag = get_showFlag_from_visibilityOption($block_visibility, $visibility_option, $url);
	 
	 //get content from block content or from the block function 
	 if ($reference_table == 'block_content') {
		$custom_block = block_content::find_by_block_id($records->block_id);
		if (!empty($custom_block)) {
		 if (($custom_block->content_php_cb) == 1) {
			$block_content_deocded = base64_decode($custom_block->content);
			$block_content = ino_eval($block_content_deocded);
		 } else {
			$block_content = $custom_block->content;
		 }
		} else {
		 $block_content = '';
		}
	 }else{
		$class_containg_block = new $records->reference_table;
		$method_name = $records->reference_table.'_'.$records->name.'_block';
		$block_content = call_user_func(array($class_containg_block, $method_name), $parameters);
	 }

	 if ($show_block_flag == 1) {
		$block_value = "<div class=\"block $position $reference_table block_$block_count\">";
		$block_value .= "<div class=\"headerBgColor title $reference_table \" > $title </div>";
		$block_value .= "<div class=\"content $reference_table \" > $block_content </div>";
		$block_value .="</div>";
	 }

	 if (!empty($block_value)) {
		foreach (block::$position_array as $key => $value) {
		 if ($position == $value) {
			$blocks_by_position[] = [
					'position' => $position,
					'value' => $block_value
			];
		 }
		}
	 }

	 unset($block_value);
	}

	foreach (block::$position_array as $keys => $values) {
	 $var_to_print = "<div id=\"$values\">";
	 foreach ($blocks_by_position as $records) {
		if ($records['position'] == $values) {
		 $var_to_print .= $records['value'];
		}
	 }
	 $var_to_print .= "</div>";
	 echo $var_to_print;
	 unset($var_to_print);
	}
 }
 ?>
</div>
