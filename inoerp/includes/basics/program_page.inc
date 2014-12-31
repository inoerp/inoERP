<?php
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
		 <div id="structure">
			<div id="contents">
			 <div id ="form_header">
				
				<div class="show_loading_small"></div>
				<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 </div>
			 <div id="list_contents">
				<div id="searchForm">
				 <span class="heading"><?php echo!empty($program_name) ? $program_name : ""; ?></span>
				 <?php echo!(empty($search_form)) ? $search_form : ""; ?>
				<?php $f->hidden_field('program_name', $program_name); ?>
				</div>

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
