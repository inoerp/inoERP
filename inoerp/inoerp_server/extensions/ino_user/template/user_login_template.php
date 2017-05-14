<div class="container-fluid">
 <div class="row">
  <div class="clearfix"></div>
  <div class="white-wrapper col-sm-12 col-xs-12 col-md-6 col-md-offset-3">
   <div>
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
         <li><a href="#tabsHeader-1"><?php echo gettext('User Login'); ?></a></li>
       	 <li><a href="#tabsHeader-2"><?php echo gettext('New Account'); ?></a></li>
       	 <li><a href="#tabsHeader-3"><?php echo gettext('Password Reset'); ?></a></li>
       	 <li><a href="#tabsHeader-4"><?php echo gettext('Role Request'); ?></a></li>
        </ul>
        <div class="tabContainer"> 

         <div id="tabsHeader-1" class="tabContent">
          <div class="col-md-8">
           <div >
            <div class="panel panel-default">
             <div class="panel-body">
              <form name="user_login_onPage" role="form" action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_login_onPage">
               <fieldset>
                <div class="row">
                 <div class="col-sm-12 col-md-10  col-md-offset-1 ">
                  <div class="form-group">
                   <div class="input-group">
                    <span class="input-group-addon">
                     <i class="glyphicon glyphicon-user"></i>
                    </span> 
                    <input type="text" id="username"  class="form-control  username"   name="username[]"  autofocus>
                   </div>
                  </div>
                  <div class="form-group">
                   <div class="input-group">
                    <span class="input-group-addon">
                     <i class="glyphicon glyphicon-lock"></i>
                    </span>
                    <input type="password"  id="password"  name="password" class="form-control">
                   </div>
                  </div>
                  <div class="form-group">
                   <div class="input-group">
                    <span class="input-group-addon">
                     <i class="fa fa-language"></i>
                    </span>
                    <?php echo $f->select_field_from_object('user_language', ino_user::all_languages(), 'option_line_code', 'description', $ino_user->user_language, 'user_language', 'form-control'); ?>
                   </div>
                  </div>
                  <div class="form-group">
                   <input type="submit" name="submitLogin" class="btn btn-lg btn-primary btn-block" value="<?php echo gettext('Log in'); ?>">
                  </div>
                 </div>
                </div>
               </fieldset>
              </form>
             </div>
            </div>
           </div>
          </div>
          <div class="col-md-4"> 
           <?php echo extn_social_login::sl_stmt(); ?>
          </div>
         </div>

         <div id="tabsHeader-2" class="tabContent">
          <div id="create_new_user" class="col-md-8">
           <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_header_onPage" name="user_header_onPage">
            <fieldset>
             <div class="row">
              <div class="col-sm-12 col-md-10  col-md-offset-1 ">
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="glyphicon glyphicon-user"></i>
                 </span> 
                 <input type="text" id="first_name"  class="form-control  first_name"  value="" name="first_name[]" placeholder="<?php echo gettext('First Name'); ?>" required>
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="glyphicon glyphicon-user"></i>
                 </span>
                 <input type="text" id="last_name"  class="form-control  last_name"  value="" name="last_name[]" placeholder="<?php echo gettext('Last Name'); ?>" required>
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="fa fa-user"></i>
                 </span> 
                 <input type="text" id="username"  class="form-control  username"  value="" name="username[]" placeholder="<?php echo gettext('Username'); ?>" required>
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="fa fa-envelope"></i>
                 </span>
                 <input type="email" id="email"  class="form-control  email"  value="" name="email[]" placeholder="<?php echo gettext('Email'); ?>" required>
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="fa fa-phone"></i>
                 </span>
                 <input type="text" id="phone"  class="form-control  phone"  value="" name="phone[]" placeholder="<?php echo gettext('Phone #'); ?>">
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="glyphicon glyphicon-lock"></i>
                 </span>
                 <input type="password" value="" placeholder="<?php echo gettext('Password'); ?>" id="enteredPassword"  name="enteredPassword[]" class="form-control" required>
                </div>
               </div>
               <div class="form-group">
                <div class="input-group">
                 <span class="input-group-addon">
                  <i class="glyphicon glyphicon-lock"></i>
                 </span>
                 <input type="password" value="" placeholder="<?php echo gettext('Re-enter Password'); ?>" id="enteredRePassword"  name="enteredRePassword[]" class="form-control" required>
                </div>
               </div>
               <div class="form-group">
                <input type="submit" name="newUser" class="btn  btn-lg btn-info btn-block" value="<?php echo gettext('Create Account'); ?>">
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

         <div id="tabsHeader-3" class="tabContent">
          <form action="<?php echo HOME_URL ?>extensions/ino_user/user_login.php" method="post" id="user_reset_password_onPage" name="user_reset_password_onPage">
           <fieldset>
            <div class="row">
             <div class="col-sm-12 col-md-10  col-md-offset-1 ">
              <div class="form-group">
               <div class="input-group">
                <span class="input-group-addon">
                 <i class="glyphicon glyphicon-user"></i>
                </span> 
                <input type="text" id="reset_password_user_name"  class="form-control  username"  value="" name="username[]" placeholder="<?php echo gettext('Username'); ?>" autofocus>
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
                <input type="text" id="reset_password_email"  class="form-control  email"  value="" name="email[]" placeholder="<?php echo gettext('Email'); ?>">
               </div>
              </div>
              <div class="form-group">
               <input type="submit" name="resetPassword" class="btn btn-lg btn-primary btn-block" value="<?php echo gettext('Send New Password'); ?>">
              </div>
             </div>
            </div>
           </fieldset>
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
 </div>
</div>

