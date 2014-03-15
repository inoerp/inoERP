<?php include_once("option_simple.inc"); ?>

<div id="coa_json">
<?php 
if(!empty($_GET["option_id_l"])) {
 $option_id_l = $_GET["option_id_l"];
  $option_line_object = option_line::find_by_option_id($option_id_l);
  if (count($option_line_object) == 0) {
    return false;
  }else
  {
       foreach ($option_line_object as $key => $value){
         echo '<option value="' . $value->option_line_code .'"';
         echo '>' . $value->option_line_code . '</option>';
      } 
  }
  
}
?>
</div>

<?php include_template('footer.inc') ?>