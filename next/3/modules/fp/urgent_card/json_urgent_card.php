<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_POST['save_data']))) {
 $uc = new fp_urgent_card();
 $uc->card_details = $_POST['data_to_save'];
 try{
 $uc->save();
 $dbc->confirm();
 echo  '<br>Data Saved<br>';
 }catch(Exception $e){
  echo "<br>Failed to save data<br>". $e->getMessage();
 }
}
?>