<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="userDiv">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <div id="tabsHeader">
        <form action="" method="post" id="user_header" name="user_header"><span class="heading">User Activities </span>
         <div id ="form_header">
          <div id="tabsHeader">
           <ul class="tabMain">
            <li><a href="#tabsHeader-1">Basic Info</a></li>
            <li><a href="#tabsHeader-2">Posts</a></li>
            <li><a href="#tabsHeader-3">Comments</a></li>
            <li><a href="#tabsHeader-4">Files</a></li>
           </ul>
           <div class="tabContainer"> 
            <div id="tabsHeader-1" class="tabContent">
             <div class="large_shadow_box"> 
              <ul class="column two_column inRowLi">
               <li><label>User Name :</label>	<?php echo  $$class->username ; ?></li>
               <li><label>First Name : </label>	<?php echo  $$class->first_name ; ?> </li>
               <li><label>Last Name : </label><?php echo  $$class->last_name ; ?>	 </li>
               <li><label>e-Mail ID :</label> <?php  echo  "xxx"  ; ?> </li>
               <li><label>Phone :</label> <?php echo  $$class->phone ; ?> </li>
               <li><label>Joined On :</label> <?php echo  $$class->creation_date ; ?> </li>
              </ul>
             </div>
            </div>
            <div id="tabsHeader-2" class="tabContent">
             <?php echo!empty($content_string) ? $content_string : false; ?>
            </div>
            <div id="tabsHeader-3" class="tabContent">
             <?php echo!empty($comment_string) ? $comment_string : false; ?>
            </div>
            <div id="tabsHeader-4" class="tabContent">
             <div> <?php echo ino_attachement($file) ?> </div>
            </div>
           </div>

          </div>
         </div>
        </form>
       </div>
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
