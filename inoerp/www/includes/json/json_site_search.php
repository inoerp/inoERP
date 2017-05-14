<?php 
require_once __DIR__.'/../basics/wloader.inc';
include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc'); ?>
<?php
if (!empty($_GET)) {
 $param = [];
 if(!empty($_GET['search_parameters']) && is_array($_GET['search_parameters'])){
  foreach($_GET['search_parameters'] as $rec){
   $rec_name = str_replace(['[',']'], '', $rec['name']);
   $param[$rec_name] = $rec['value'];
  }
 }
 $ss = new extn_site_search();
 echo '<div id="json_search_result">';
 echo $ss->site_search_result($param);
 echo '</div>';
}
?>

