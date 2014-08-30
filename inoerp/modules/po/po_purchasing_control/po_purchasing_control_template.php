<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="po_purchasing_control_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Purchasing Control </span>
			 <form action=""  method="post" id="po_purchasing_control"  name="po_purchasing_control">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<?php echo form::hidden_field('po_purchasing_control_id', $$class->po_purchasing_control_id); ?>
					<li><label>Business Org :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1); ?>
					 <a name="show" href="form.php?class_name=po_purchasing_control" class="show org_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($$class->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $$class->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Purchasing Info</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column five_column"> 
							<li><label>Payment Term : </label>
							 <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', '', 1, $readonly); ?>
							</li>
							<li><label>Ship to Address : </label><?php $f->address_field_d('ship_to_location') ?> 							</li>
							<li><label>Bill to Address : </label><?php $f->address_field_d('bill_to_location') ?> 						</li>
              <li><label>PO Approval : </label>
               <?php echo $f->select_field_from_array('po_approval_hierarchy', po_purchasing_control::$approval_hierarchy_a, $$class->po_approval_hierarchy) ?> 						</li>
              <li><label>Req Approval : </label>
               <?php echo $f->select_field_from_array('req_approval_hierarchy', po_purchasing_control::$approval_hierarchy_a, $$class->req_approval_hierarchy) ?> 						</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--              end of tab1-->

					 <div id="tabsLine-2"  class="tabContent">

					 </div>
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
