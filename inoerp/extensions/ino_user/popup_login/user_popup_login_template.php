<?php
include_once __DIR__ . '/../../../includes/basics/basics.inc';
$user = new ino_user();
$class = 'ino_user';
$user_role = new user_role();
$user_password_reset = new user_password_reset();
$f = new inoform();
?>

<!-- Button trigger modal -->
<button type="button" class="btn btn-default btn-sm" data-toggle="modal" data-target="#myModal"> <i class="fa fa-user"></i> Login / Register</button>

<div class="modal fade login-form" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
 <div class="modal-dialog">
  <div class="modal-content">
   <div class="modal-body">
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
        <div class="col-md-8"> 
         <form name="user_login" action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_login">
          <fieldset>
           <div class="row">
            <div class="col-sm-12 col-md-10  col-md-offset-1 ">
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-user"></i>
               </span> 
               <input type="text" id="username"  class="form-control  username"  value="" name="username[]" placeholder="Username" autofocus>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-lock"></i>
               </span>
               <input type="password" value="" placeholder="Password" id="password"  name="password" class="form-control">
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="fa fa-language"></i>
               </span>
               <?php echo $f->select_field_from_object('user_language', ino_user::all_languages(), 'option_line_code', 'description', $user->user_language, 'user_language', 'form-control'); ?>
              </div>
             </div>
             <div class="form-group">
              <input type="submit" name="submitLogin" class="btn btn-lg btn-primary btn-block" value="Log in">
             </div>
            </div>
           </div>
          </fieldset>
         </form>
        </div>
        <div class="col-md-4"> 
         <?php echo extn_social_login::sl_stmt(); ?>
        </div>

       </div>


       <div id="tabsLine-2" class="tabContent">
        <div id="create_new_user" class="col-md-8">
         <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_header" name="user_header">
          <fieldset>
           <div class="row">
            <div class="col-sm-12 col-md-10  col-md-offset-1 ">
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-user"></i>
               </span> 
               <input type="text" id="first_name"  class="form-control  first_name"  value="" name="first_name[]" placeholder="First Name" required>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-user"></i>
               </span>
               <input type="text" id="last_name"  class="form-control  last_name"  value="" name="last_name[]" placeholder="Last Name" required>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="fa fa-user"></i>
               </span> 
               <input type="text" id="username"  class="form-control  username"  value="" name="username[]" placeholder="Username" required>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="fa fa-envelope"></i>
               </span>
               <input type="email" id="email"  class="form-control  email"  value="" name="email[]" placeholder="eMail" required>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="fa fa-phone"></i>
               </span>
               <input type="text" id="phone"  class="form-control  phone"  value="" name="phone[]" placeholder="Phone #">
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-lock"></i>
               </span>
               <input type="password" value="" placeholder="Password" id="enteredPassword"  name="enteredPassword[]" class="form-control" required>
              </div>
             </div>
             <div class="form-group">
              <div class="input-group">
               <span class="input-group-addon">
                <i class="glyphicon glyphicon-lock"></i>
               </span>
               <input type="password" value="" placeholder="Re-enter Password" id="enteredRePassword"  name="enteredRePassword[]" class="form-control" required>
              </div>
             </div>
             <div class="form-group">
              <input type="submit" name="newUser" class="btn  btn-lg btn-info btn-block" value="Create Account">
             </div>
            </div>
           </div>
          </fieldset>
         </form>
        </div>
        <div class="col-md-4"> 
         <?php echo extn_social_login::sl_stmt(); ?>
        </div>
       </div>

       <div id="tabsLine-3" class="tabContent">
        <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_reset_password_onPage" name="user_reset_password_onPage">
         <fieldset>
          <div class="row">
           <div class="col-sm-12 col-md-10  col-md-offset-1 ">
            <div class="form-group">
             <div class="input-group">
              <span class="input-group-addon">
               <i class="glyphicon glyphicon-user"></i>
              </span> 
              <input type="text" id="reset_password_user_name"  class="form-control  username"  value="" name="username[]" placeholder="Username" autofocus>
             </div>
            </div>
            <div class="form-group">
             <div class="input-group">

              <input type="button" value="Or" class="btn btn-sm btn-default btn-block">
             </div>
            </div>
            <div class="form-group">
             <div class="input-group">
              <span class="input-group-addon">
               <i class="fa fa-envelope"></i>
              </span>
              <input type="text" id="reset_password_email"  class="form-control  email"  value="" name="email[]" placeholder="eMail">
             </div>
            </div>
            <div class="form-group">
             <input type="submit" name="resetPassword" class="btn btn-lg btn-primary btn-block" value="Send New Password">
            </div>
           </div>
          </div>
         </fieldset>
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
    <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
    <!--    <button type="button" class="btn btn-primary">Save changes</button>-->
   </div>
  </div>
 </div>
</div>

