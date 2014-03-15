<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">

    <div id="structure">
     <div id="category">
      <div id="form_top">
       <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="category.php">New Object</a> </li>
        <li><input type="submit" form="category_header" name="submit_category" id="submit_category" class="button" Value="Save"></li>
        <li> <a class="button" href="categorys.php?category_id=<?php echo htmlentities($category->category_id); ?>">View</a> </li>
        <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
        <li><input type="reset" class="button" form="category_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
       </ul>
      </div>
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
        <li>
         <div id="scrollElement">
          <form action=""  method="post" id="category_header"  name="category_header">
           <!--create empty form or a single id when search is not clicked and the id is referred from other category -->
           <div class="hidden"><input type="hidden"
                                      name="category_id" value="<?php echo htmlentities($category->category_id); ?>">
           </div>
           <div class="two_column"> 
            <ul> 
             <li><label>Category Id :</label> 
              <input type="text" readonly name="category_id" class="category_id" maxlength="30" size="30"
                     placeholder="System Generated No" value="<?php echo htmlentities($category->category_id); ?>">
             </li>
             <li class="primary_cb"> <label>Primary ? : </label>            
              <input type="checkbox" name="primary_cb"  value="1"
              <?php
              if ($category->primary_cb == 1) {
               echo " checked";
              } else {
               echo "";
              }
              ?> >
             </li>
             <li><label>Parent Name :</label> 

              <select name="parent_id" class="parent_id"> 
               <option value="" ></option> 
               <?php
               if (empty($new_category_parent_id) && (empty($category->parent_id))) {
                $all_child_category_select_options = category::all_child_category_select_options();
                echo $all_child_category_select_options;
               } else {
                $parent = category::find_all();
                foreach ($parent as $record) {
                 echo '<option value="' . $record->category_id . '" ';
                 echo $record->category_id == $category->parent_id ? ' selected ' : ' ';
                 if (!empty($new_category_parent_id)) {
                  echo $record->category_id == $new_category_parent_id ? ' selected ' : ' ';
                 }
                 echo '>' . $record->category . '</option>';
                }
               }
               ?> 
              </select> 
             </li>
             <li><label>Category :</label> 
              <input type="text" required name="category"  maxlength="60" size="60"
                     placeholder="Enter a valid category" value="<?php echo htmlentities($category->category); ?>">
             </li>
             <li><label>Description  : </label> 
              <input type="text" required name="description" maxlength="100" size="60" 
                     placeholder="Enter category descrip. Limit 100 characters" value="<?php echo htmlentities($category->description); ?>">
             </li>

            </ul>
           </div>
          </form>
         </div>  


        </li>

       </ul>


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
