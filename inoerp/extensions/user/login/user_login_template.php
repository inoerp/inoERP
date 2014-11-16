<link href="user.css" media="all" rel="stylesheet" type="text/css" />
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
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">User Login</a></li>
         <li><a href="#tabsLine-2">New Account</a></li>
         <li><a href="#tabsLine-3">Password Reset</a></li>
         <li><a href="#tabsLine-4">Role Request</a></li>
        </ul>
        <div class="tabContainer"> 

         <div id="tabsLine-1" class="tabContent">
          <form name="user_login" action="user_login.php" method="post" id="user_login">
           <ul class="inRow asperWidth">
            <span id="username_tip" maxlength="50" size="30" id="username_tip" ></span>
            <li><label>User Name</label>
             <input type="text" name="username" maxlength="50" size="30" id="username" placeholder="example : sachin.god"
                    value="<?php echo ($$class->username); ?>"> 
            </li> 
            <li><label>Password</label>
             <input type="password" name="password" maxlength="50" size="30" id="password" placeholder="example : uVrt@%35"
                    value="<?php echo ($$class->password); ?>" >
            </li>
            <li><label>Remember Me</label>
             <input type="checkbox" name="remember_me" value="1" > &nbsp; &nbsp; &nbsp;
            </li>
            <li><input type="submit" name="submitLogin" class="button" value="Log in"></li>
            <li><input type="button" name="cancelLogin" id="cancelLogin" class="button" value="Cancel & Go Back"></li>
           </ul>

          </form>
         </div>


         <div id="tabsLine-2" class="tabContent">
          <div id="create_new_user">
           <form action="" method="post" id="user_header" name="user_header">
            <ul class="two_column">
             <li><label>First Name : </label>
              <?php echo form::text_field_dm('first_name'); ?>
             </li>
             <li><label>Last Name : </label>
              <?php echo form::text_field_dm('last_name'); ?>
             </li>
             <li><label>Username :</label>  
              <?php echo form::text_field_dm('username'); ?>
             </li>
             <li><label>e-Mail ID :</label> 
              <?php echo form::text_field_dm('email'); ?>
             </li>
             <li><label>Password  : </label> 
              <input type="password" name="enteredPassword[]" maxlength="50" id="enteredPassword" size="30" >
              <!--<span class="hint">(Min 8 letter, 1 small, 1 CAP, 1 <i>Special</i>)</span>
              pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" 
              -->
             </li>
             <li><label>Confirm Password  : </label> 
              <input type="password" name="enteredRePassword[]" maxlength="50" id="enteredRePassword" size="30" >
             </li>
             <li><label>Phone :</label> 
              <?php echo form::number_field_d('phone'); ?>
             </li>
            </ul>
            <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->
            <input type="submit" name="newUser" class="button" value="Create Account">
           </form>
          </div>
         </div>

         <div id="tabsLine-3" class="tabContent">
          <form action="" method="post" id="user_reset_password" name="user_reset_password">
           <div class="large_shadow_box">
            <ul class="column four_column">
             <li><label>Username :</label>  
              <?php echo form::text_field('username', $$class_third->username, 35, 200, '', 'Login User Name', 'reset_password_user_name', '', 'reset_password_user_name'); ?>
             </li>
             <li> Or </li>
             <li><label>e-Mail :</label> 
              <?php echo form::text_field('email', $$class_third->email, 35, 200, '', 'Registered email id', 'reset_password_email', '', 'reset_password_email'); ?>
             </li>
             <li><input type="submit" name="resetPassword" class="button" value="Send New Password"></li>
            </ul>
            <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->

           </div>
          </form>
         </div>
         <div id="tabsLine-4" class="tabContent">

         </div>
        </div>
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
