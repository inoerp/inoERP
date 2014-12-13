<div id="all_contents">
 <div id="content_top"></div>
  <div id="content_right">
	<div id="content_right_left">
	 <div id="content">
    <div id="content_left_top"></div><div id="content_right_top"></div>
		<div id="main">
		 <div id="structure">
			<div id="content_list">
			 <!--    START OF FORM HEADER-->
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <?php
			 $content = new content();
			  if (empty($content_type->content_type_id)) {
							$content_lists = $content->showSummaryList_byConteTypeCategory($pageno, $per_page, $query_string);
				echo $content_lists. '			</div> 		 </div> 		</div> 	 </div> 	</div> 	<div id="content_right_right"></div>
                </div>  <div id="content_bottom"></div>  </div>';
				include_template('footer.inc');
				return;
			 }
			 if (!empty($category_id)) {
				$content_cat = new category();
				$all_child_cat = $content_cat->findAll_childOfParent($category_id);
				if (!empty($all_child_cat)) {
				 $exploded_cat = $content_cat->category_explosion_withPCRelation($category_id);
				 $category_relation_statement = $content_cat->show_exploded_category($category_id, $content_type_name);
//				$category_relation_statement = category::print_category_relations_content($all_child_cat, $content_type_name);
				} else {
				 $category_relation_statement = null;
				}
			 }
//pa($content_type);
			 $content->content_type_id = $content_type->content_type_id;
			 $content->category_id = !empty($category_id) ? $category_id : null;
			 if ($content_type->show_category_onsummary_cb) {
				$content_lists = $content->showSummaryList_byConteTypeCategory($pageno, $per_page, $query_string);
			 } else {
				$content_lists = $content->showForumList_byConteTypeCategory($pageno, $per_page, $query_string);
			 }

			 if (!empty($category_relation_statement)) {
				echo "<div id='category_relationDiv'>$category_relation_statement</div>";
			 }
			 echo "<div id='contents_listDiv'>$content_lists</div>";
			 ?>
			</div>
		 </div>
		</div>
    <div id="content_content_bottom">
	 <div id="content_left_bottom"></div><div id="content_right_bottom"></div>
   </div> 
   </div>
	</div>
   <div id="content_right_right">
    <div id="content_left"></div>
   </div>
  
 </div>
 <div id="content_bottom"></div> 
</div>
<?php include_template('footer.inc') ?>
