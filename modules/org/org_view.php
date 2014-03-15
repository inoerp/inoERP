<?php
$extension = 'user';
$key_field = 'user_name';
$primary_column = "user_id";
$userTitle = " user - Create & update user ";
$required_field_flag = 1;
$view_path = "user_view";
?>
<?php include_once("../../include/basics/header.inc"); ?>
<script src="user.js"></script>

<?php
if (!empty($$extension)) {
 $content_view_statement = content_view_statement($$extension, $extension);
}

if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
 $show_message .= '</div>';
}
?>
<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="main">

		 <div id="structure user">
			<div id="contents">
			 <div id ="form_header">
				<ul id="form_box"> 
				 <li>
					<div id="loading"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
				 </li>
				 <li> 
					<div class="error"></div>
					<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
				 </li>

				</ul>
			 </div>
			 <div id="specific_content" class="specific_content user">
				<h2>User Details</h2>
				<?php echo!(Empty($content_view_statement)) ? $content_view_statement : ""; ?>
			 </div>
			</div>
		 </div>
		</div>
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>

