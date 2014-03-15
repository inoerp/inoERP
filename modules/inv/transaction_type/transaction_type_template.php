<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="transaction_type_divId">
			<?php
			$current_page_path = "transaction_type.php";
			if (empty($readonly)) {
			 form::form_button($current_page_path);
			 $readonly = "";
			} else {
			 $readonly = 1;
			}
			?>
			<div id="transaction_type_searchId">
			 <?php
			 if (empty($readonly)) {
				$search_form = search::search_form('transaction_type', 'transaction_type', 'transaction_type_search');
				if (!empty($pagination)) {
				 $pagination_statement = $pagination->show_pagination($pagination, 'transaction_type', $pageno, $query_string);
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
			 <form action=""  method="post" id="transaction_type"  name="transaction_type">
				<div id ="form_line" class="form_line"><span class="heading">Transaction Type Details </span>
				 <div id="tabs">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Mandatory</a></li>
					 <li><a href="#tabsLine-2">Other Info</a></li>
					</ul>
					<div class="tabContainer"> 
					<div id="tabsLine-1"  class="tabContent">
					 <table class="form_table">
						<?php echo transaction_type::$tabs_header1_tr ?>
						<tbody class="transaction_type_values">
						 <?php
						 $count = 0;
						 foreach ($search_result as $transaction_type) {
							?>         
 						 <tr class="transaction_type<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($transaction_type->transaction_type_id); ?>"></li>           
 							 </ul>
 							</td>
 							<td><?php form::text_field_widsr('transaction_type_id'); ?></td>
							<td><?php form::text_field_widsm('transaction_type_number'); ?></td>
							<td><?php form::text_field_widm('transaction_type'); ?></td>
 							<td><?php echo form::select_field_from_object('type_class', transaction_type::transaction_type_class(), 'option_line_code', 'description', $$class->type_class, '', $readonly,'max_width_150'); ?></td>
 							<td><?php echo form::select_field_from_object('transaction_action', transaction_type::transaction_action(), 'option_line_code', 'description', $$class->transaction_action, '', $readonly,'max_width_150'); ?></td>
 							<td><?php form::text_field_wid('description'); ?></td>
 							<td><?php echo form::checkBox_field('allow_negative_balance_cb' . $count, $$class->allow_negative_balance_cb, 'allow_negative_balance_cb', $readonly); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="tabContent scrollElement" >
					 <table class="form_table">
						<?php echo transaction_type::$tabs_header2_tr ?>
						<tbody class="transaction_type_values">
						 <?php
						 $count = 0;
						 foreach ($search_result as $transaction_type) {
							?>         
 						 <tr class="transaction_type<?php echo $count ?>">
 							<td>
								<?php form::account_field('account_id'); ?>
 							</td>
 							<td>
								<?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
 							</td>
 							<td>                      
								<?php echo form::status_field($$class->status, $readonly); ?>
 							</td>
 							<td>
								<?php echo form::checkBox_field('rev_enabled_cb' . $count, $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
 							</td> 
 							<td>
								<?php form::text_field_wid('rev_number'); ?>

 							</td> 
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->

					 </table>
					</div>
					</div>
					</div>
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
