<?php
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if (!empty($_POST['get_fp_from_form']) && !empty($_POST['template_code'])) {
 $obj_class_name = $_POST['obj_class_name'];
 $template_code = $_POST['template_code'];
 $class_names = [$obj_class_name];
 include_once(__DIR__ . "/../../../includes/basics/basics.inc");
 include_once(__DIR__ . "/../../../includes/functions/loader.inc");
 echo '<div id="return_divId">';
 $tmpfname = tempnam(HOME_DIR . "/files/temp", "fp_");
 $handle = fopen($tmpfname, "w");
 fwrite($handle, $template_code);
 fclose($handle);
 include_once $tmpfname;
 unlink($tmpfname);
 echo '</div>';
}
?>


