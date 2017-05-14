    <div id="main"> 
     <div id="structure">
      <div id="content_divId">
       <!--    START OF FORM HEADER-->
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <!--    End of place for showing error messages-->
			 <div id="form_all">
				<div id ="form_header">
				 <div class="tabContainer">
					<div id="mass_upload_steps" class="full_content">
					 <ul class="text_list">
						<li><h3>1. Download a copy of the input csv file.</h3>
           <?php echo $dl->show_download_form(); ?>
						 The first column (xxx_id)is ignored for new mass upload and should be correct for existing data modification.<br>
						</li>
						<li><h3>2. Enter the data in the csv file.</h3>
						 First row shows the field /column name. Next few rows shows some sample data.<br>
						 You can remove the sample data but don't delete the field/column names.<br>
						 Save the file only in .csv format.
						</li>
						<li>
						 <h3>3. Upload the file </h3>
						 <div id="file_upload_form">
							<ul class="inRow asperWidth">
							 <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
							 <li><input type="button" value="Import" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
							 <?php echo form::hidden_field('class_name', $class);
                 echo $f->hidden_field_withId('upload_type', 'data_base');
               ?>
							 <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
							</ul>
						 </div>
						</li>
						<li><h3>4. Place holder for output/errors</h3>
						 <div id="uploaded_file_details"></div>
						</li>
					 </ul>
					</div>
				</div> 
				 </div>
			 </div>
      </div>
     </div>
     <!--   end of structure-->
    </div>

<?php
execution_time();
?>
