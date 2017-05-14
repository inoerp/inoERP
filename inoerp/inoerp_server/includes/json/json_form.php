<?php

$form_page = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {
 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once('../basics/basics.inc');
 $path = new path();
 if (!empty($_GET['path_id'])) {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type, array($_GET['path_id']));
 } else {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type);
 }
 include_once('../functions/loader.inc');
 include_once(__DIR__ . '/../template/json_form_template.inc');
 return;
} else {
 include_once('../functions/functions.inc');
 access_denied('No Class Found!');
}
?>
<?php
$json_loader = 1;
include_once('../functions/loader.inc');
if (empty($_POST)) {
 try {
  if ($continue) {
   header("Content-type: text/html; charset=UTF-8");
   if (!isset($all_contacts)) {
    $all_contacts = null;
   }
   include_once(__DIR__ . '/../template/json_form_template.inc');
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