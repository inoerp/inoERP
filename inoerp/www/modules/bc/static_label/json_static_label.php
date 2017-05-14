<?php

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

$err_msg = '';
if ((!empty($_GET['bc_static_label_id'])) && ($_GET['print_label'] == 1)) {
 $param = get_postArray_From_jqSearializedArray($_GET['print_parameters']);
 $sl = new bc_static_label();
 $sl->findBy_id($_GET['bc_static_label_id']);
 switch ($sl->label_type) {
  case 'LOCATOR' :
   $locator = new locator_v();
   $locator->org_id = !empty($param['org_id'][0]) ? $param['org_id'][0] : '';
   $locator->subinventory_id = !empty($param['subinventory_id'][0]) ? $param['subinventory_id'][0] : '';
   $locator->locator_id = !empty($param['locator_id'][0]) ? $param['locator_id'][0] : '';
   $data_obj_a = $locator->findBy_parameter();
   break;

  case 'SUBINV' :
   $sub = new subinventory();
   $sub->org_id = !empty($param['org_id'][0]) ? $param['org_id'][0] : '';
   $sub->subinventory_id = !empty($param['subinventory_id'][0]) ? $param['subinventory_id'][0] : '';
   $data_obj_a = $sub->findBy_parameter_withOrgDetails();
   break;

  case 'ORG' :
  case 'INV' :
   $org_id = !empty($param['org_id'][0]) ? $param['org_id'][0] : '';
   $data_obj_a = org::find_by_id($org_id);
   break;

  default:
   break;
 }

 if (!empty($data_obj_a) && is_array($data_obj_a)) {
  foreach ($data_obj_a as $data_obj) {
   $bc_lr = new bc_label_request();
   $bc_lr->sys_printer_id = $sl->sys_printer_id;
   $bc_lr->bc_label_format_header_id = $sl->bc_label_format_header_id;
   $xml_content = $bc_lr->generate_label($data_obj);
   $bc_lr->print_XMLlabel($xml_content);
  }
  $err_msg .= '<br>Label is Successfullyprinted';
 } else if (!empty($data_obj_a)) {
  $bc_lr = new bc_label_request();
  $bc_lr->sys_printer_id = $sl->sys_printer_id;
  $bc_lr->bc_label_format_header_id = $sl->bc_label_format_header_id;
  $xml_content = $bc_lr->generate_label($data_obj_a);
  $bc_lr->print_XMLlabel($xml_content);
  $err_msg .= '<br>Label is Successfullyprinted';
 }

 $lbl_frmt_hdr = bc_label_format_header::find_by_id($sl->bc_label_format_header_id);
 if (!empty($lbl_frmt_hdr->generator_class_name) && !empty($lbl_frmt_hdr->generator_function_name)) {
  $class_gl = $lbl_frmt_hdr->generator_class_name;
  $$class_gl = new $class_gl;

  if (method_exists($$class_gl, $lbl_frmt_hdr->generator_function_name)) {
   $xml_content_rtn = call_user_func(array($$class_gl, $lbl_frmt_hdr->generator_function_name), $_GET);
   $bc_lr = new bc_label_request();
   $bc_lr->sys_printer_id = $sl->sys_printer_id;
   $bc_lr->bc_label_format_header_id = $sl->bc_label_format_header_id;
   if (is_array($xml_content_rtn)) {
    foreach ($xml_content_rtn as $xml_content) {
     $bc_lr->print_XMLlabel($xml_content);
    }
   } else {
    $bc_lr->print_XMLlabel($xml_content_rtn);
   }
  }
 }

 if (!empty($err_msg)) {
  echo '<div id="ret_message">' . $err_msg . '</div>';
 } else {
  echo false;
 }
}
?>