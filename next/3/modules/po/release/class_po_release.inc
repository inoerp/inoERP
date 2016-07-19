<?php

 class po_release extends po_header {

  public static $system_info = [
   'name' => 'BPA Relase',
   'number' => '2213',
   'description' => 'Create & Mainten BPA Relase & Related documents/transactions',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
   'dependent_class' => array('po_line', 'po_detail'),
   'primary_entity_cb' => '',
   'module_name' => 'po',
   'weight' => 1
  ];
  public static $po_type_a = [
   'BLANKET_RELEASE' => 'Blanket Release',
   'BLANKET' => 'Blanket Agreeement',
  ];

 }

//end of po_header class
?>