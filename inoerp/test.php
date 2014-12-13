<?php
include_once("tparty/barcode/class_ino_barcode.inc");
$bc= new ino_barcode();
echo 'item ';
//$bc->setProperty('_text', 'A');
//$bc->draw_barcode();

echo '<br>item &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
$bc= new ino_barcode();
$str = '1122244' ;
$str .= 'FNC 1';
$str .= 'WIP-02 ' ;

echo $str;

$bc->setProperty('_text', $str);
$bc->draw_barcode();

echo '<br>item ';
$bc= new ino_barcode();
$bc->setProperty('_text', '1122244$IWIP-02$IWIP-02.01.01.01.');
$bc->draw_barcode();


              foreach ($all_data as $mod_name => $modules) {
             
              }
?>
