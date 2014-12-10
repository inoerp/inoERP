<?php
include_once("tparty/barcode/class_ino_barcode.inc");
$bc= new ino_barcode();
$bc->setProperty('_text', 'Hello How Are You');
echo $bc->draw_barcode();

?>
