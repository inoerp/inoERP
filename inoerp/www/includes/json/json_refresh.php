<?php require_once __DIR__.'/../basics/wloader.inc';
include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc'); ?>
<?php

if ((!empty($_GET['data_type'])) && (!empty($_GET['refresh_data'])) && ($_GET['refresh_data'] = 'recent_visit')) {
 $retun_data_a = [];
 $ret_data = ino_recent_visits();
 $retun_data_a['string_data'] = $ret_data;
 echo header('Content-Type: application/json');
 echo json_encode(($retun_data_a));
}
?>