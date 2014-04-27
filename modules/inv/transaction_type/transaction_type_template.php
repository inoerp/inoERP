<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="transaction_type_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Transaction Type </span>
			 <form action=""  method="post" id="transaction_type_form"  name="transaction_type_form">
				<div class="large_shadow_box">
				 <ul class="column four_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="transaction_type_id select_popup clickable">
						Transaction Type Id : </label> 
					 <?php $f->text_field_ds('transaction_type_id') ?>
					 <a name="show" href="form.php?class_name=transaction_type" class="show transaction_type_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Trnx. Number :</label>
					 <?php form::text_field_wid('transaction_type_number'); ?>
					</li>
					<li><label>Transaction Type :</label>
					 <?php form::text_field_wid('transaction_type'); ?>
					</li>
					<li><label>Type Class :</label>
					 <?php echo $f->select_field_from_object('type_class', transaction_type::transaction_type_class(), 'option_line_code', 'description', $$class->type_class, '', '', 1, $readonly1); ?>
					</li>
					<li><label>Action :</label>
					 <?php echo $f->select_field_from_object('transaction_action', transaction_type::transaction_action(), 'option_line_code', 'description', $$class->transaction_action, '', '', 1, $readonly); ?>
					</li>

				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Transaction Type Details </span>
				 <div id="tabs">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column four_column"> 
							<li><label>Description :</label>
							 <?php $f->text_field_wid('description'); ?>
							</li>
							<li><label>Allow Negative Balance : </label>
							 <?php echo form::checkBox_field_d('allow_negative_balance_cb'); ?>
							</li> 
							<li><label>Extra Field : </label>
							 <?php echo form::extra_field($transaction_type->ef_id, '10', $readonly); ?>
							</li>
							<li><label>Status : </label>
							 <?php echo form::status_field($transaction_type->status, $readonly); ?>
							</li>
							<li><label>Revision : </label>
							 <?php echo form::revision_enabled_field($transaction_type->rev_enabled_cb, $readonly); ?>
							</li>
							<li><label>Revision No: </label>
							 <?php echo form::text_field('rev_number', $transaction_type->rev_number, '10', '', '', '', '', $readonly); ?>
							</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <div id="tabsLine-2"  class="tabContent">
						<!--                end of tab2 div three_column-->
					 </div>
					 <!--end of tab5-->
					</div>

				 </div> 
				</div> 
			 </form>
			</div>
			<!--END OF FORM HEADER-->

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
