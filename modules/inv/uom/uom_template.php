<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="uom_divId">

			<div id="uom_search">
			 <?php
			 if (empty($readonly)) {
				$search_form = search::search_form('uom', 'uom', 'loactor_search');
				if (!empty($pagination)) {
				 $pagination_statement = $pagination->show_pagination($pagination, 'uom', $pageno, $query_string);
				}
				echo!(empty($search_form)) ? $search_form : "";
			 }
			 ?>
			</div>
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="uom"  name="uom">
				<div id ="form_line" class="form_line"><span class="heading">UOM Details </span>
				 <table class="form_table">
					<?php echo uom::$table_line_tr ?>
					<tbody class="uom_values">
					 <?php
					 $count = 0;
					 foreach ($search_result as $uom) {
						?>         
 					 <tr class="uom<?php echo $count ?>">
 						<td>    
 						 <ul class="inline_action">
 							<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 							<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 							<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($uom->uom_id); ?>"></li>           
 						 </ul>
 						</td>
 						<td>
							<?php form::text_field_wids('uom_id'); ?>
 						</td>
 						<td>    
							<?php form::text_field_wid('uom'); ?>
 						</td>
 						<td>
							<?php echo form::select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', $readonly); ?>
 						</td>
 						<td>
							<?php form::text_field_wid('description'); ?>
 						</td>
 						<td>
							<?php echo form::checkBox_field('primary', $$class->primary, '', $readonly); ?>
 						</td>
 						<td>
							<?php form::text_field_wid('primary_uom'); ?>
 						</td>
 						<td>  
 						 <input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
 						</td>
 						<td>
							<?php form::text_field_wid('primary_relation'); ?>
 						</td>
 						<td>
							<?php echo form::text_field_wids('ef_id', '10', $readonly); ?>
 						</td>
 						<td>                      
							<?php echo form::status_field($$class->status, $readonly); ?>
 						</td>
 						<td>
							<?php echo form::checkBox_field('rev_enabled_cb' . $count, $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
 						</td> 
 						<td>
							<?php form::text_field_wids('rev_number'); ?>

 						</td> 

 					 </tr>
						<?php
						$count = $count + 1;
					 }
					 ?>
					</tbody>
				 </table>
				</div> 
			 </form>
			</div>
			<!--END OF FORM HEADER-->
			<div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
			</div>
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
