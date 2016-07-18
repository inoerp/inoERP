<?php
ob_start();
header('Content-type: image/png');
imagepng($image);
imagedestroy($image);
ob_flush();
?>