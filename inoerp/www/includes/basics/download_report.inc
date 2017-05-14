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
<div id="erp_form_area">
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
</div>