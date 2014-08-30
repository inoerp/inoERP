<script type="text/javascript">
 $(document).ready(function() {
	$("table#category_list tr").not('.first').hide();

	$("table#category_list tr.first").click(function() {
	 $(this).nextUntil("tr.first").toggle();
	});

 });</script>
<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="category">
      <div id="category_relations">
       <ul class="category data">
        <table id="category_list" class="normal">
         <thead>
          <tr>
           <th>Category</th>
           <th>Description</th>
           <th>Operation</th>
          </tr>
         </thead>
         <tbody>
					<?php
					$all_categories = category::all_child_categories();
					foreach ($all_categories as $major_category) {
					 echo '<tr class="first"><td class="first">' . $major_category['category'] . '</td>
            <td>' . $major_category['description'] . '</td>
             <td><a href="form.php?class_name=category&mode=9&category_id=' . $major_category['category_id'] . '">Update</a>&nbsp; &nbsp;' .
					 '<a href="form.php?class_name=category&parent_id=' . $major_category['category_id'] . '">Add Child Category</a> 
                   </td></tr>';
					 if (!empty($major_category['child'])) {

						foreach ($major_category['child'] as $child1) {
						 echo '<tr class="second"><td class="second"> ' . $child1['category'] . '</td>
              <td>' . $child1['description'] . '</td>
               <td><a href="form.php?class_name=category&mode=9&category_id=' . $child1['category_id'] . '">Update</a>&nbsp; &nbsp;' .
						 '<a href="form.php?class_name=category&parent_id=' . $child1['category_id'] . '">Add Child Category</a> 
                     </td></tr>';
						 if (!empty($child1['child'])) {
							foreach ($child1['child'] as $child2) {
							 echo '<tr class="third"><td class="third">' . $child2['category'] . '</td>
                <td>' . $child2['description'] . '</td>
                <td><a href="form.php?class_name=category&mode=9&category_id=' . $child2['category_id'] . '">Update</a> &nbsp; &nbsp;' .
							 '<a href="form.php?class_name=category&parent_id=' . $child2['category_id'] . '">Add Child Category</a> 
                       </td></tr>';
							 if (!empty($child2['child'])) {
								foreach ($child2['child'] as $child3) {
								 echo '<tr class="four"><td class="four">' . $child3['category'] . '</td>
                <td>' . $child3['description'] . '</td>
                <td><a href="form.php?class_name=category&mode=9&category_id=' . $child3['category_id'] . '">Update</a> &nbsp; &nbsp;' .
								 '<a href="form.php?class_name=category&parent_id=' . $child3['category_id'] . '">Add Child Category</a> 
                         </td></tr>';
								}
							 }
							}
						 }
						}
					 }
					}
					?>
         </tbody>
        </table>
       </ul>
      </div>

     </div>
     <!--END OF FORM HEADER-->  
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
