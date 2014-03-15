<?php
$class_names = [
		'path'
];
$pageTitle = " Path  - Create & Update all Paths ";
$view_path = "path_view";
?>
<?php include_once("../../includes/functions/loader.inc"); ?>
<?php if (!empty($_POST))
{
 return;
}
 ?>
<script type='text/javascript' src="path.js" ></script>
<?php
$class = $class_first = 'path';
$$class = $$class_first = &$path;
?>