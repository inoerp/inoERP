<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php

$err_msg = '';
if ((!empty($_GET['bc_static_label_id'])) && ($_GET['print_label'] == 1)) {
 $sl = new bc_static_label();
 $sl->findBy_id($_GET['bc_static_label_id']);
 switch ($sl->label_type) {
  case 'LOCATOR' :
   $data_obj = locator::find_by_id(18);
   break;

  default:
   break;
 }

 if (!empty($data_obj)) {
  $bc_lr = new bc_label_request();
  $bc_lr->sys_printer_id = $sl->sys_printer_id;
  $bc_lr->bc_label_format_header_id =$sl->bc_label_format_header_id;
  $xml_content = $bc_lr->generate_label($data_obj);
  $bc_lr->print_XMLlabel($xml_content);
  $err_msg .= '<br>Label is sucessfully printed';
 }

 if (!empty($err_msg)) {
  echo  '<div id="ret_message">'.$err_msg.'</div>';
  echo $xml_content;
 }else{
  echo false;
 }
}
?>