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

 function block_check($block_visibility_a, $ulr_vars_s) {
  $show_block_flag = 0;
  foreach ($block_visibility_a as $k => $v) {
   if (empty(trim($v, chr(10)))) {
    continue;
   }
   if(is_array($ulr_vars_s)){
    return 1;
   }
   if (strpos($ulr_vars_s, trim($v)) !== false) {
    $show_block_flag = 1;
    break;
   }
   if ($show_block_flag) {
    break;
   }
  }
  return $show_block_flag;
 }

 function get_showFlag_from_visibilityOption($block_visibility, $visibility_option, $url) {
  if ($visibility_option != 3) {
   if (strpos($block_visibility, ',') !== false) {
    $block_visibility_a = explode(',', $block_visibility);
   } else {
    $block_visibility_a = explode(chr(10), $block_visibility);
   }
   $ulr_vars = explode("/", $url);
   $show_block_flag = 0;
   $ulr_vars_s1 = null;
   if(strpos($url, '?')){
    $ulr_vars_s1 = end($ulr_vars);
   }else{
    $ulr_vars_s1 = array_slice($ulr_vars, -2, 1, true);
   }
   
   $ulr_vars_s1 = empty($ulr_vars_s1) ? 'index' : $ulr_vars_s1;

   if (empty($visibility_option)) {
    $show_block_flag = 1;
   }


   if ($visibility_option == 1) {
    if (empty($block_visibility)) {
     $show_block_flag = 1;
    } else if (count($block_visibility_a) == 1 && $block_visibility_a[0] == chr(10)) {
     $show_block_flag = 1;
    } else if (block_check($block_visibility_a, $ulr_vars_s1)) {
     $show_block_flag = 1;
    } elseif (!empty($url) && !empty($block_visibility) && (block_check($block_visibility_a, $ulr_vars_s1))) {
     $show_block_flag = 1;
    } else {
     $show_block_flag = 0;
    }
   }

   if ($visibility_option == 2) {
    if (empty(trim($block_visibility, chr(10)))) {
     $show_block_flag = 0;
    } if (block_check($block_visibility_a, $ulr_vars_s1)) {
     $show_block_flag = 0;
    } elseif (!empty($url) && !empty($block_visibility) && (block_check($block_visibility_a, $ulr_vars_s1))) {
     $show_block_flag = 0;
    } else {
     $show_block_flag = 1;
    }
   }
  }

  if ($visibility_option == 3) {
   try {
    $vis_val = ino_eval($block_visibility);
   } catch (Exception $e) {
    echo "<br> Wrong php expression in visibility option" . $e->getMessage();
   }
   $show_block_flag = ($vis_val == 1) ? true : false;
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
  $session_id = session_id();
  $bc = new block_cache();
  foreach ($all_blocks_array as $records) {
   $block_cache = false;
   $block_count++;
   $position = $records->position;
   $title = $records->title;
   $visibility_option = $records->visibility_option;
   $block_visibility = base64_decode($records->visibility);
   $reference_table = $records->reference_table;

   $show_block_flag = get_showFlag_from_visibilityOption($block_visibility, $visibility_option, $url);
   if (!$show_block_flag) {
    continue;
   }
//   echo "<br> block id " . $records->block_id . ' : show bock flag is '. $show_block_flag;
   //get content from block cahche or block content or from the block function
   if ((!empty($session_id)) && ($records->cached_cb == 1)) {
    $bc->block_id = $records->block_id;
    $bc->session_id = $session_id;
    $bc_i = $bc->findBy_blockId_sessionId();
    if (($bc_i) && !empty($bc_i->block_data)) {
     $block_content = unserialize($bc_i->block_data);
    } else {
     $block_content = null;
     $block_cache = true;
    }
   }

   if (empty($block_content) && ($reference_table == 'block_content')) {
    $custom_block = block_content::find_by_block_id($records->block_id);
    if(DB_TYPE == 'ORACLE'){
     $custom_block->content = stream_get_contents($custom_block->content);
    }
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
   } else if (empty($block_content)) {
    $class_containg_block = new $records->reference_table;
    $method_name = $records->name . '_block';
    $parameters['block_id'] = $records->block_id;
    $block_content = call_user_func(array($class_containg_block, $method_name), $parameters);
   }

//   if (($block_cache) && (!empty($block_content))) {
//    $bc->block_data = serialize($block_content);
//    $bc->create();
//   }

   if ((!empty($block_content)) && ($show_block_flag == 1)) {
    foreach (block::$position_array as $key => $value) {
     if ($position == $value) {
      if ($value == 'footer_top') {
       $block_value = '<div class="col-md-3 col-sm-6 col-xs-12 blog-sidebar">';
       $block_value .= "<div class=\"block $position $reference_table block_$block_count \">";
       if (!empty($records->show_title_cb) && $records->show_title_cb == true) {
        $block_value .= "<div class=\"headerBgColor title $reference_table\" > $title </div>";
       }
       $block_value .= "<div class=\"content $reference_table \" > $block_content </div>";
       $block_value .="</div></div>";
      } else if ($value == 'header_top') {
       $block_value = "<div class=\"block $position $reference_table block_$block_count \">";
       if (!empty($records->show_title_cb) && $records->show_title_cb == true) {
        $block_value .= "<div class=\"title $reference_table\" > $title </div>";
       }
       $block_value .= "<div class=\"content $reference_table \" > $block_content </div>";
       $block_value .="</div>";
      } else {
       $block_value = "<div class=\"block $position $reference_table block_$block_count panel panel-success \">";
       if (!empty($records->show_title_cb) && $records->show_title_cb == true) {
        $block_value .= "<div class=\"headerBgColor title $reference_table panel-heading\" >$title</div>";
       }
       $block_value .= "<div class=\"content $reference_table panel-body \" > $block_content </div>";
       $block_value .="</div>";
      }
      $blocks_by_position[] = [
       'position' => $position,
       'value' => $block_value
      ];
     }
    }
   }

   unset($block_value);
   unset($block_content);
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
