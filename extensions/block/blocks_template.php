<div id="all_contents">
 <div id="content_header"><span class='highlight'>Content header</span></div>
 <div id="content_left"><span class='highlight'>Content Left</span></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"><span class='highlight'>Content Top</span></div>
   <div id="content">
    <div id="main"> 
     <div id="structure">
      <div id="blocks_divId">
       <!--    START OF FORM HEADER-->
			 <div id='observerDiv'></div>
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <!--    End of place for showing error messages-->
			 <div id="form_all">
				<div id ="form_header">
				 <form action=""  method="post" id="block_header"  name="block_header">
					<table class="form_table">
					 <thead> 
						<tr>
						 <th>Action</th>
						 <th>Block Id</th>
						 <th>Name</th>
						 <th>Title</th>
						 <th>Position</th>
						 <th>Weight</th>
						 <th>Enabled</th>
						</tr>
					 </thead>
					 <tbody id="block_statuses">
						<?php
						$count = 0;
						$result = block::find_all();
						foreach ($result as $block) {
						 $is_custom_block = 0;
						 if (block_content::find_by_block_id($block->block_id)) {
							$is_custom_block = 1;
						 }
						 ?>         
 						<tr class="block_number<?php echo $count ?>">
 						 <td>    
 							<ul class="inline_action">
 							 <li class="edit"><a href="block.php?block_id=<?php
								 echo htmlentities($block->block_id);
								 echo ($is_custom_block == 1) ? '&custom_block=1' : "";
								 ?>"><img src="<?php echo HOME_URL; ?>themes/images/edit.png" alt="update this line" /></a></li>
 							 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 							 <li><input type="checkbox" name="block_id_cb" value="<?php echo htmlentities($block->block_id); ?>"></li>
							 <li><?php echo form::hidden_field('reference_table', $$class->reference_table) ?></li>
 							</ul>
 						 </td>
						 <td><?php form::number_field_widsrm('block_id'); ?></td>
 						 <td><?php form::text_field_wid('name'); ?></td>
 						 <td><?php form::text_field_wid('title'); ?></td>
 						 <td><?php echo form::select_field_from_array('position', block::$position_array, $$class->position); ?></td>							
 						 <td><?php echo form::select_field_from_array('weight', dbObject::$position_array, $$class->weight); ?></td>
 						 <td><?php echo form::checkBox_field('enabled_cb', $$class->enabled_cb,'', 1); ?></td> 
							<?php
						 }
						 $count = $count + 1;
						 ?>
						</tr>
					 </tbody>
					 <!--                  Showing a blank form for new entry-->

					</table>
				 </form>
				</div>
			 </div>
			</div>
		 </div>
		 <!--   end of structure-->
		</div>
	 </div>
	 <div id="content_bottom"><span class='highlight'>Content Bottom</span></div>
	</div>
	<div id="content_right_right"><span class='highlight'>Content Right Right</span></div>
 </div>

</div>
<span class='highlight'>Footer Top</span>
<?php include_template('footer.inc') ?>
<span class='highlight'>Footer Bottom</span>
