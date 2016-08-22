<link href="user.css" media="all" rel="stylesheet" type="text/css" />

<div class="white-wrapper">
 <div class="container">
  <div id="structure">
   <div id="userDiv">
    <!--    START OF FORM HEADER-->
    <div class="error"></div><div id="loading"></div>
    <div role="alert" class="alert alert-warning error alert-dismissible"><?php
     if (!empty($show_message)) {
      echo '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' . $show_message;
     }
     ?></div>
    <!--    End of place for showing error messages-->
    <div id ="form_header" class="login-form">
     <div id="tabsHeader">
      <ul class="tabMain">
       <li><a href="#tabsHeader-1">User Login</a></li>
       <li><a href="#tabsHeader-2">New Account</a></li>
       <li><a href="#tabsHeader-3">Password Reset</a></li>
       <li><a href="#tabsHeader-4">Role Request</a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsHeader-1" class="tabContent">
        <div class="col-md-8">
         <form name="user_login_onPage" action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_login_onPage">
          <ul class="single-column">
           <span id="username_tip" maxlength="50" size="30"  ></span>
           <li><?php $f->l_text_field('username', $user->username, '', 'username', '', 1, '', 'Sachin.God'); ?></li> 
           <li><label>Password</label>
            <input type="password" name="password" maxlength="50" size="30" required id="password" placeholder="example : uVrt@%35"
                   value="<?php echo ($user->password); ?>" >
           </li>
           <li><?php $f->l_select_field_from_object('user_language', ino_user::all_languages(), 'option_line_code', 'description', $user->user_language, 'user_language'); ?>  </li>
           <li><label></label><input type="submit" name="submitLogin" class="button btn btn-success" value="Log in"></li>
          </ul>

         </form>
        </div>
        <div class="col-md-4"> 
<?php echo extn_social_login::sl_stmt(); ?>
        </div>
       </div>


       <div id="tabsHeader-2" class="tabContent">
        <div id="create_new_user" class="col-md-8">
         <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_header_onPage" name="user_header_onPage">
          <ul class="single-column">
           <li><?php $f->l_text_field_dm('first_name'); ?></li>
           <li><?php $f->l_text_field_dm('last_name'); ?></li>
           <li><?php $f->l_text_field_dm('username'); ?></li>
           <li><?php $f->l_email_field_dm('email'); ?></li>
           <li><label>Password</label><input type="password" name="enteredPassword[]" maxlength="50" id="enteredPassword" size="30" >
            <!--<span class="hint">(Min 8 letter, 1 small, 1 CAP, 1 <i>Special</i>)</span>
            pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" 
            -->
           </li>
           <li><label>Confirm Password</label><input type="password" name="enteredRePassword[]" maxlength="50" id="enteredRePassword" size="30" ></li>
           <li><?php $f->l_phone_field_d('phone'); ?></li>
           <li><label></label><input type="submit" name="newUser" class="button btn btn-success" value="Create Account"></li>
          </ul>
          <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->

         </form>
        </div>
        <div class="col-md-4"> 
<?php echo extn_social_login::sl_stmt(); ?>
        </div>
       </div>

       <div id="tabsHeader-3" class="tabContent">
        <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_reset_password_onPage" name="user_reset_password_onPage">
         <ul class="single-column">
          <li><label>Username</label><?php echo form::text_field('username', $user_password_reset->username, 35, 200, '', 'Login User Name', 'reset_password_user_name', '', 'reset_password_user_name'); ?>         </li>
          <li><label></label> Or </li>
          <li><label>e-Mail</label><?php echo form::text_field('email', $user_password_reset->email, 35, 200, '', 'Registered email id', 'reset_password_email', '', 'reset_password_email'); ?>           </li>
          <li><label></label><input type="submit" name="resetPassword" class="button btn btn-success" value="Send New Password"></li>
         </ul>
         <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->
        </form>
       </div>
       <div id="tabsHeader-4" class="tabContent">

       </div>
      </div>
     </div>
    </div>    

   </div>
  </div>

 </div>

</div>

<?php include_template('footer.inc') ?>
