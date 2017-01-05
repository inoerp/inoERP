<?php include_once __DIR__.'/../../../includes/basics/basics.inc' ;
$user = new user();
$user_role = new user_role();
$user_password_reset = new user_password_reset();
?>

<!-- Button trigger modal -->
<button type="button" class="btn btn-default btn-sm" data-toggle="modal" data-target="#myModal"> <i class="fa fa-user"></i> <?php echo gettext('Login / Register'); ?></button>

<!-- Modal -->
<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
 <div class="modal-dialog">
  <div class="modal-content">
   <div class="modal-body">
    <div id ="form_header">
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('User Login'); ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('New Account'); ?></a></li>
       <li><a href="#tabsLine-3"><?php echo gettext('Password Reset'); ?></a></li>
       <li><a href="#tabsLine-4"><?php echo gettext('Role Request'); ?></a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsLine-1" class="tabContent">
        <form name="user_login" action="<?php echo HOME_URL?>extensions/user/user_login.php" method="post" id="user_login">
         <ul class="inRow asperWidth">
          <li><label><?php echo gettext('User Name') ?></label>
           <input type="text" name="username" maxlength="50" size="30" id="username" placeholder="<?php echo gettext('example') . ' : ' . gettext(ucwords('sachin.god')); ?>"
                readonly  value="demouser">
          </li> 
          <li><label><?php echo gettext('Password') ?></label>
           <input type="password" name="password" maxlength="50" size="30" id="password" placeholder="<?php echo gettext('example') . ' : uVrt@%35'; ?>"
                readonly  value="demouser" >
          </li>
          <li><?php $f->l_select_field_from_object('user_language', user::all_languages(), 'option_line_code', 'description', $user->user_language, 'user_language'); ?>  </li>
          <li><input type="submit" name="submitLogin" class="button btn btn-success" value="<?php echo gettext('Log in'); ?>"></li>
          <li><input type="button" name="cancelLogin" id="cancelLogin" class="button btn btn-warning" value="<?php echo gettext('Cancel & Go Back'); ?>"></li>
         </ul>

        </form>
       </div>


       <div id="tabsLine-2" class="tabContent">
        <div id="create_new_user">
         <form action="<?php HOME_URL?>extensions/user/user_login.php" method="post" id="user_header" name="user_header">
          <ul class="two_column"><li><label><?php echo gettext('First Name'); ?></label><?php echo form::text_field('first_name', $user->first_name); ?></li>
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
          </ul>
          <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->
          <input  disabled type="submit" name="newUser" class="button btn btn-success" value="<?php echo gettext('Create Account'); ?>">
         </form>
        </div>
       </div>

       <div id="tabsLine-3" class="tabContent">
        <form action="<?php HOME_URL?>extensions/user/user_login.php" method="post" id="user_reset_password" name="user_reset_password">
          <ul class="column four_column">
           <li><label><?php echo gettext('Username'); ?></label><?php echo form::text_field('username', $user_password_reset->username, 35, 200, '', 'Login User Name', 'reset_password_user_name', '', 'reset_password_user_name'); ?>         </li>
           <li> <?php echo gettext('Or'); ?> </li>
           <li><label><?php echo gettext('Email'); ?></label><?php echo form::text_field('email', $user_password_reset->email, 35, 200, '', 'Registered email id', 'reset_password_email', '', 'reset_password_email'); ?>           </li>
           <li><input disabled type="submit" name="resetPassword" class="button btn btn-success" value="<?php echo gettext('Send New Password'); ?>"></li>
          </ul>
          <!--<input type="hidden" class="hidden" name='submit_user' value='1'>-->
        </form>
       </div>
       <div id="tabsLine-4" class="tabContent">

       </div>
      </div>
     </div>
    </div>    
   </div>
   <div class="modal-footer">
    <button type="button" class="btn btn-default" data-dismiss="modal"><?php echo gettext('Close')?></button>
<!--    <button type="button" class="btn btn-primary">Save changes</button>-->
   </div>
  </div>
 </div>
</div>


