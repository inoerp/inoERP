<div  id="multi_select">
 <div id="content_divId">
	<div class="row small-top-margin">
	 <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
		<div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>

	 <div id="searchResult">
		<form  method="post" id="content"  name="content">
		 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Contents') ?></span>
			<div id="tabsLine">
			 <ul class="tabMain">
				<li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
				<li><a href="#tabsLine-2"><?php echo gettext('Details') ?></a></li>
			 </ul>
			 <div class="tabContainer">
				<div id="tabsLine-1" class="tabContent">
				 <table class="form_table">
					<thead> 
					 <tr>
						<th><?php echo gettext('Action') ?></th>
						<th><?php echo gettext('Content Id') ?></th>
						<th><?php echo gettext('Content Type') ?></th>
						<th><?php echo gettext('Parent Id') ?></th>
						<th><?php echo gettext('Subject') ?></th>
						<th><?php echo gettext('Terms') ?></th>
						<th><?php echo gettext('Published') ?></th>
						<th><?php echo gettext('Show in FP') ?></th>
						<th><?php echo gettext('Weightage') ?></th>
						<th><?php echo gettext('Comment Status') ?></th>
					 </tr>
					</thead>
					<tbody class="form_data_line_tbody">
							<?php
							$f = new inoform();
							$count = 0;
							if (!empty($search_result)) {
							 foreach ($search_result as $content) {
								$cty = content_type::find_by_id('content_type_id');
								?>         
						 <tr class="content_line<?php echo $count ?>">
							<td>    
							 <ul class="inline_action">
								<li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
								<li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($content->content_id); ?>"></li>           
							 </ul>
							</td>
							<td><?php form::text_field_widsr('content_id'); ?></td>
							<td><?php echo!empty($cty) ? $cty->content_type : $content->content_type_id; ?></td>
							<td><?php echo $f->text_field_wid('parent_id'); ?></td>
							<td><?php echo $f->text_field_wid('subject'); ?></td>
							<td><?php echo $f->text_field_wid('terms'); ?></td>
							<td><?php echo $f->checkBox_field_wid('published_cb'); ?></td>
							<td><?php echo $f->checkBox_field_wid('show_in_fp_cb'); ?></td>
							<td><?php echo $f->text_field_wid('weightage'); ?></td>
							<td><?php echo $f->text_field_wid('comment_status'); ?></td>
							<!--<td><?php // echo $f->select_field_from_array('comment_action', ['unpublish' => 'Unpublish', 'delete' => 'Delete'], '' ,'' ,'medium');  ?></td>-->

						 </tr>
						 <?php
						 $count = $count + 1;
						}
					 }
					 ?>
					</tbody>
				 </table>
				</div>
				<div id="tabsLine-2" class="scrollElement" class="tabContent">
				 <table class="form_table">
					<thead> 
					 <tr>
						<th><?php echo gettext('Content Id') ?></th>
						<th><?php echo gettext('Content Type Id') ?></th>
						<th><?php echo gettext('Content By') ?></th>
						<th><?php echo gettext('Creation Time') ?></th>
						<th><?php echo gettext('Created By') ?></th>
						<th><?php echo gettext('Last Update Time') ?></th>
						<th><?php echo gettext('Last Update By') ?></th>
					 </tr>
					</thead>
					<tbody class="form_data_line_tbody">
							<?php
							$count = 0;
							if (!empty($search_result)) {
							 foreach ($search_result as $content) {
								?>         
						 <tr class="content_line<?php echo $count ?>">
							<td><?php echo $$class->content_id; ?></td>
							<td><?php echo $f->text_field_widr('content_type_id'); ?></td>
							<td><?php echo $f->text_field_widr('content_by'); ?></td>
							<td><?php echo $f->text_field_widr('creation_date'); ?></td>
							<td><?php echo $f->text_field_widr('created_by'); ?></td>
							<td><?php echo $f->text_field_widr('last_update_date'); ?></td>
							<td><?php echo $f->text_field_widr('last_update_by'); ?></td>

						 </tr>
						 <?php
						 $count = $count + 1;
						}
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
	</div>
	<!--END OF FORM HEADER-->
	<div class="row small-top-margin">
	 <div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
	 </div>
	</div>

 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="content" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="content" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="content"></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>

