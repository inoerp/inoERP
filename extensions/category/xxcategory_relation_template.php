<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="category">
      <!--    START OF FORM HEADER-->
      <div id ="form_header">
       <ul id="form_box"> 
        <li>

         <div id="loading"><img alt="Loading..." 
                                src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
        </li>
        <li>   <!--    Place for showing error messages-->

         <div class="error"></div>
         <?php echo (!empty($show_message)) ? $show_message : ""; ?> 


         <!--    End of place for showing error messages-->
        </li>
        <!--Search form creation    -->
       </ul>
      </div>  
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
         foreach ($all_categories as $major_category) {
          echo '<li class="first expandable">';
          echo '<tr class="first"><td class="first">' . $major_category['category'] . '</td><td>' . $major_category['description'] . '</td><td></td></tr>';
          if (!empty($major_category['child'])) {
           echo '<ul class="second">';
           foreach ($major_category['child'] as $child1) {
            echo '<li class="second expandable">';
            echo '<tr class="second"><td class="second"> ' . $child1['category'] . '</td><td>' . $child1['description'] . '</td><td></td></tr>';
            if (!empty($child1['child'])) {
             echo '<ul class="third expandable">';
             foreach ($child1['child'] as $child2) {
              echo '<li class="third" >';
              echo '<tr class="third"><td class="third">' . $child2['category'] . '</td><td>' . $child2['description'] . '</td><td></td></tr>';
              echo '</li>';
             }

             echo '</ul>';
            }

            echo '</li>';
           }
           echo '</ul>';
          }

          echo '</li>';
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
