<?php 
$dont_check_login = true;
include_once("header.inc"); 
?>

<div id="all_blocks">
  <?php
  if (!empty($_POST['all_blocks']) && $_POST['all_blocks'] == 1) {
    $all_blocks_array = block::assign_blocks();

    $blocks_by_position = array();
    
    $block_count = 0;
    $url = $_POST['pathname'];
    echo "url is $url";
    $ulr_vars = explode("/", $url);

//    echo '<pre>';
//    print_r($ulr_vars);
//    echo '<pre>';

    echo 'visibility options are';
    foreach ($all_blocks_array as $records) {
      $show_block_flag = 0;
      $block_count++;
      $position = $records['position'];
      $title = $records['title'];
      $content = $records['content'];
      $visibility_option = $records['visibility_option'];
      $block_visibility = base64_decode($records['block_visibility']);
      $reference_table = $records['reference_table'];
      
echo "<br/> $title $visibility_option : $block_visibility ";
      if(empty($visibility_option)){
        $show_block_flag = 1;
        echo "<br/> show blok flag changed 0 ";
      }
      
      if ($visibility_option == 1) {
        if (array_search($block_visibility, $ulr_vars)) {
          $show_block_flag = 1;
          echo "<br/> show blok flag changed 1 ";
        } elseif (strpos($url,$block_visibility) !== false){
          $show_block_flag = 1;
        }
        else {
          $show_block_flag = 0;
        }
      }

      if ($visibility_option == 2) {
        if (array_search($block_visibility, $ulr_vars)) {
          $show_block_flag = 0;
        } else {
          $show_block_flag = 1;
          echo "<br/> show blok flag changed 2 ";
        }
      }

      if ($visibility_option == 3) {
        if ($block_visibility == 1) {
          $show_block_flag = 1;
        } else {
          $show_block_flag = 1;
          echo "<br/> show blok flag changed 3 ";
        }
      }

      if ($show_block_flag == 1) {
        $block_value = "<div class=\"block $position $reference_table block_$block_count\">";
        $block_value .= "<div class=\"headerBgColor title $reference_table \" > $title </div>";
        $block_value .= "<div class=\"content $reference_table \" > $content </div>";
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
//
////    
////    
//        echo '<pre>';
//    print_r($blocks_by_position);
//    echo '<pre>';


    foreach (block::$position_array as $keys => $values) {
      $var_to_print = "<div id=\"$values\">";
      foreach ($blocks_by_position as $records) {
        if ($records['position'] == $values) {
          $var_to_print .= $records['value'];
        }
      }
//      $var_to_print .= print_r($ulr_vars);
      $var_to_print .= "</div>";
      echo $var_to_print;
      unset($var_to_print);
    }
  }
  ?>
</div>

<div id="new_search_criteria"> <?php   add_new_search_criteria(); ?> </div>

<?php include_template('footer.inc') ?>