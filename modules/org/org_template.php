<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="org_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="org"  name="org">
				<div class="large_shadow_box"><span class="heading">Organization Details </span>
				 <ul class="column five_column"> 
					<li> 
					 <label><a href="find_org.php" class="popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
						Org Id : </label> 
					 <input type="text" readonly name="org_id" value="<?php echo htmlentities($org->org_id); ?>"                          
									maxlength="50" id="org_id" class="header_id" placeholder="System generated number"> 
					 <a name="show" href="org.php?org_id=" class="show">
						<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li> 
					<li><label>Org Type : </label> 
					 <select name="type" id="org_type" > 
						<option value="" ></option> 
						<?php
						for ($i = 0; $i <= 3; $i++) {
						 echo '<option value="' . $types[$i]->option_line_code . '"';
						 echo $types[$i]->option_line_code == $org->type ? ' selected' : ' ';
						 echo '>' . $types[$i]->option_line_code . '</option>';
						}
						?> 
					 </select> 
					</li> 
					<li><label>Org : </label> 
					 <input type="text" name="org[]" value="<?php echo htmlentities($org->org);
						?>" maxlength="50" required > 
					</li> 
					<li><label>Code : </label> 
					 <input type="text" name="code[]" value="<?php echo htmlentities($org->code);
						?>" maxlength="5"  id="code" required> 
					</li> 
					<li><label>Enterprise : </label> 
					 <?php echo!(empty($enterprise_statement)) ? $enterprise_statement : ""; ?>
					</li>
					<li><label>Legal Org  : </label> 
					 <?php echo!(empty($legal_org_statement)) ? $legal_org_statement : ""; ?>
					</li>
					<li><label>Business Org  : </label> 
					 <?php echo!(empty($business_org_statement)) ? $business_org_statement : ""; ?>
					</li> 
					<li><label>Description : </label> 
					 <input type="text" name="description[]" value="<?php echo htmlentities($org->description);
					 ?>" maxlength="50" id="description"> 
					</li> 
					<li><label>Extra Field : </label> 
					 <input type="text" name="efid[]" value="<?php echo htmlentities($org->efid);
					 ?>" maxlength="50"  id="ef_id"> 
					</li> 
					<li><label>Status : </label>
					 <Select name="status[]" id="status" >
						<option value="" ></option>
						<option value="enabled" 
										<?php echo $org->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
						<option value="disabled" 
										<?php echo $org->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
					 </select>
					</li>
					<li><label>Revision : </label>
					 <Select name="rev_enabled[]" id="rev_enabled"> 
						<option value="" ></option>   
						<option value="enabled" 
										<?php echo $org->rev_enabled == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
						<option value="disabled" 
										<?php echo $org->rev_enabled == 'disabled' ? 'selected' : ''; ?>>Disabled</option>                                   
					 </select>
					</li>
					<li><label>Revision No: </label> 
					 <input type="text"  name="rev_number[]" value="<?php echo htmlentities($org->rev_number);
										?>" maxlength="50" id="rev_number"> 
					</li>
					<li>
					 <label>Address Id: <a href="address/find_address.php" class="address_popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> </label> 
					 <input type="text"  name="address_id[]" value="<?php echo htmlentities($org->address_id);
										?>" maxlength="50" id="address_id"> 
					</li> 
				 </ul> 
				</div>
			 </form>
			</div>


			<!--END OF FORM HEADER-->
			<div id ="form_line" class="form_line"><span class="heading">Address Details </span>
			 <ul class="address inline_list">
				<li><label>Phone  : </label> 
				 <input type="text" readonly name="phone" maxlength="25" id="phone" size="25" 
								placeholder="Phone number" value="<?php echo htmlentities($address->phone); ?>">
				</li>
				<li><label>Email  : </label> 
				 <input type="text" readonly name="email" maxlength="50" id="postal_code" size="25" 
								placeholder="Email address" value="<?php echo htmlentities($address->email); ?>">
				</li>
				<li><label>Web-site  : </label> 
				 <input type="text"  readonly name="website" maxlength="50" id="country" size="25" 
								placeholder="Official Website" value="<?php echo htmlentities($address->website); ?>">
				</li>
				<li><label>Country  : </label> 
				 <input type="text" readonly name="country" maxlength="50" id="country" size="25" 
								placeholder="Country name" value="<?php echo htmlentities($address->country); ?>">
				</li>
				<li><label>Postal Code  : </label> 
				 <input type="text"  readonly name="postal_code" maxlength="25" id="postal_code" size="25" 
								placeholder="Postal/Zip code" value="<?php echo htmlentities($address->postal_code); ?>">
				</li>
				<li><label>Address :</label>  
				 <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="Select address Id"><?php echo trim(htmlentities($address->address)); ?></textarea>
				</li>
			 </ul>
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
