<div id="all_contents">
 <div id="content_left"></div>
<div id="content_right">
 <div id="content_right_left">
  <div id="content_top"></div>
<div id="content">

<div id="structure">
 <div id="page">
  <div id="form_top">
   <ul class="form_top">
    <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
    <li> <a class="button" href="page.php">New Object</a> </li>
    <li><input type="submit" form="page_header" name="submit_page" id="submit_page" class="button" Value="Save"></li>
    <li> <a class="button" href="pages.php?page_id=<?php echo htmlentities($page->page_id); ?>">View</a> </li>
    <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
    <li><input type="reset" class="button" form="page_header" name="reset" Value="Reset All"></li>
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
      <form action=""  method="post" id="page_header"  name="page_header">
       <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
       <div class="hidden"><input type="hidden"
                                  name="page_id" value="<?php echo htmlentities($page->page_id); ?>">
       </div>
       <div id="subject"><label>Subject : </label>
        <input type="text"  name="subject" value="<?php echo htmlentities($page->subject); ?>" 
               size="135"  maxlength="250" class="subject" placeholder="Write a brief subject on the content."> 
       </div>
       <div id="contentId"><label>Content : </label>
        <textarea required name="content" class="plaintext" rows="18" cols="80"><?php 
//                echo base64_decode($page->content);
                echo !empty($$class->content_php_cb) ? base64_decode($page->content) : $page->content;
        ?> </textarea>
       </div>
       <div id="show_attachment">
        <input type="button" class="button" value="Attachements" id="attachment_button" name="">
        <div id="attachment_page">
         <?php
         if (isset($file) && count($file) > 0) {
          echo '<ul  class="header"><li>Hide</li><li>Delete</li><li>File</li></ul>';
          foreach ($file as $records) {
           echo '<ul>';
           echo '<li><input type="checkbox" name="show" value="1"></li>';
           echo '<li><input type="checkbox" name="delete" value="1"></li>';
           echo '<a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
           echo '</ul>';
          }
         }
         ?>
        </div>
        <li>
         <!--      upload files-->

        </li>
       </div>

       <div id="page_element">
        <ul>
         <li id="terms"><label>Tags : </label>
          <input type="text"  name="terms" value="<?php echo htmlentities($page->terms); ?>" 
                 size="10"  maxlength="250" class="terms" placeholder="Tags"> 
         </li>
         <li class="published_cb"> <label>Published : </label>            
          <input type="checkbox" name="published_cb"  value="1"
          <?php
          if ($page->published_cb == 1) {
           echo " checked";
          } else {
           echo "";
          }
          ?> >

         </li>
				 <li><label>Front Page : </label> 
				 <?php echo form::checkBox_field('show_in_frontpage_cb', $$class->show_in_frontpage_cb); ?>
				 </li>
         <li>
          <label>Weightage : </label>
          <input type="number"  name="weightage" value="<?php echo htmlentities($page->weightage); ?>" 
                 size="10"  maxlength="250" class="weightage" placeholder="weightage"> 
         </li>
         <li class="rev_enabled_cb"> <label>Rev enabled : </label>            
          <input type="checkbox" name="rev_enabled_cb"  value="1"
          <?php
          if ($page->rev_enabled_cb == 1) {
           echo " checked";
          } else {
           echo "";
          }
          ?> >

         </li>
         <li>
          <label>Rev Number : </label>
          <input type="number"  name="rev_number" value="<?php echo htmlentities($page->rev_number); ?>" 
                 size="10"  maxlength="250" class="rev_number" placeholder="rev_number"> 
         </li>
         <li>
          <label>Parent : </label>
          <input type="number"  name="parent_id" value="<?php echo htmlentities($page->parent_id); ?>" 
                 size="10"  maxlength="20" class="parent_id" placeholder="parent_id"> 
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
