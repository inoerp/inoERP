<?php
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $mode = 2;
}

if(empty($$class->mdm_bank_header_id) && !empty($_GET['mdm_bank_site_id'])){
 $bank_site_i = mdm_bank_site::find_by_id($_GET['mdm_bank_site_id']);
 foreach($bank_site_i as $k => $v ){
  $$class_second->$k =  $v;
 }
 pa($bank_site_i);
 $$class->mdm_bank_header_id = $$class_second->mdm_bank_header_id;
 $$class->findBy_id($$class->mdm_bank_header_id);
}

?>