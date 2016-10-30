<link href="user.css" media="all" rel="stylesheet" type="text/css" />

<div class="white-wrapper">
 <div class="container">
  <div id="structure">
   <div id="userDiv">
    <!--    START OF FORM HEADER-->
    <div class="error"></div><div id="loading"></div>
    <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
    <!--    End of place for showing error messages-->
    <div id ="form_header" class="login-form">
     <div id="tabsHeader">
      <ul class="tabMain">
       <li><a href="#tabsHeader-1"><?php echo gettext('User Login'); ?></a></li>
       <li><a href="#tabsHeader-2"><?php echo gettext('New Account'); ?></a></li>
       <li><a href="#tabsHeader-3"><?php echo gettext('Password Reset'); ?></a></li>
       <li><a href="#tabsHeader-4"><?php echo gettext('Role Request'); ?></a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsHeader-1" class="tabContent">
        <div class="col-md-8">
         <form name="user_login_onPage" action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_login_onPage">
          <ul class="single-column">
           <span id="username_tip" maxlength="50" size="30"  ></span>
           <li><label><?php echo gettext('User Name'); ?></label>
            <input type="text" name="username" maxlength="50" size="30" id="username" placeholder="<?php echo gettext('example') . ' : ' . gettext(ucwords('sachin.god')); ?>"
                   value="<?php echo ($user->username); ?>">
           </li> 
           <li><label>Password</label>
            <input type="password" name="password" maxlength="50" size="30" id="password" placeholder="<?php echo gettext('example') . ' : uVrt@%35'; ?>"
                   value="<?php echo ($user->password); ?>" >
           </li>
           <li><?php $f->l_select_field_from_object('user_language', ino_user::all_languages(), 'option_line_code', 'description', $user->user_language, 'user_language'); ?>  </li>
           <li><label></label><input type="submit" name="submitLogin" class="button btn btn-success" value="<?php echo gettext('Log in'); ?>"></li>
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
          <ul class="single-column"><li><label><?php echo gettext('First Name'); ?></label><?php echo form::text_field('first_name', $user->first_name); ?></li>
           <li><label><?php echo gettext('Last Name'); ?></label><?php echo form::text_field('last_name', $user->last_name); ?></li>
           <li><label><?php echo gettext('Username'); ?></label><?php echo form::text_field('username', $user->username); ?></li>
           <li><label><?php echo gettext('Email Id'); ?></label><?php echo form::text_field('email', $user->email); ?></li>
           <li><label><?php echo gettext('Password'); ?></label><input type="password" name="enteredPassword[]" maxlength="50" id="enteredPassword" size="30" >
            <!--<span class="hint">(Min 8 letter, 1 small, 1 CAP, 1 <i>Special</i>)</span>
            pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" 
            -->
           </li>
           <li><label><?php echo gettext('Confirm Password'); ?></label><input type="password" name="enteredRePassword[]" maxlength="50" id="enteredRePassword" size="30" ></li>
           <li><label><?php echo gettext('Phone'); ?></label><?php echo form::number_field('phone', $user->phone); ?></li>
           <li><label></label><input type="submit" name="newUser" class="button btn btn-success" value="<?php echo gettext('Create Account'); ?>"></li>
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
          <li><label><?php echo gettext('Username'); ?></label><?php echo form::text_field('username', $user_password_reset->username, 35, 200, '', 'Login User Name', 'reset_password_user_name', '', 'reset_password_user_name'); ?>         </li>
          <li><label></label> <?php echo gettext('Or'); ?> </li>
          <li><label><?php echo gettext('Email'); ?></label><?php echo form::text_field('email', $user_password_reset->email, 35, 200, '', 'Registered email id', 'reset_password_email', '', 'reset_password_email'); ?>           </li>
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
