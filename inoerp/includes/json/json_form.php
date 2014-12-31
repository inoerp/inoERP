<?php
$form_page = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {
 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once('../basics/basics.inc');
 $path = new path();
 $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type);
 include_once('../functions/loader.inc');
 include_once(__DIR__.'/../template/json_form_template.inc');
 return;
} else {
 access_denied('No Class Found!');
}
?>
<?php
include_once('../functions/loader.inc');
if (empty($_POST)) {
 try {
  if ($continue) {
   include_once(__DIR__.'/../template/json_form_template.inc');
  } else {
   $continue = false;
   echo "<h2>Could n't call the header</h2>";
   return;
  }
 } catch (Exception $e) {
  echo $e->getMessage();
 }
}
?>