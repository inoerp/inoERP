<div id="all_contents">
 <div id="content_header"></div>
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="main">
		 <div id="structure">
			<div id="contents">
			 <!--    START OF FORM HEADER-->
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <div id="scrollElement">
				<?php
				$category = category::find_by_categoryId($category_id);
				$all_child_categories = category::all_child_categories($category->category);

				if (!empty($all_child_categories[0]['child'])) {
				 $category_relation_statement = category::print_category_relations_content($all_child_categories, $content_type_name);
				 echo "<div id='category_relationDiv'>$category_relation_statement</div><br>";
				 $content_lists = content::content_summaryList_byConteTypeCategory($content_type->content_type_id, $category_id, $pageno, $per_page, $query_string);
				 echo "<div id='contents_listDiv'>$content_lists</div>";
				} else {
				 $content_lists = content::content_summaryList_byConteTypeCategory($content_type->content_type_id, $category_id, $pageno, $per_page, $query_string);
				 echo "<div id='contents_listDiv'>$content_lists</div>";
				}
				?>
			</div>
		 </div>
		</div>
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
