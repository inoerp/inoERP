<form action=""  method="post" id="site_info"  name="site_info"><span class="heading">Site Information </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Maintenance</a></li>
    <li><a href="#tabsHeader-3">Address</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column four_column"> 
       <li><label>Site Name : </label> <?php echo $f->text_field('site_name', $$class->site_name, '20'); ?> </li> 
       <li><label>Default e-mail : </label> <?php echo $f->text_field('email', $$class->email, '40'); ?> </li> 
       <li><label>Default Phone#: </label> <?php echo $f->text_field('phone_no', $$class->phone_no, '30'); ?> </li> 
       <li><label>Disable Action : </label> <?php echo $f->select_field_from_array('disabled_action', site_info::$disabled_action_a, $$class->disabled_action, 'disabled_action'); ?> </li> 
       <li><label>Home Page : </label> <?php echo HOME_URL . $f->text_field('default_home_page', $$class->default_home_page, '20'); ?> </li> 
       
      </ul> 
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column four_column"> 
       <li><label>Put in Maintenance Mode: </label> <?php $f->checkBox_field_d('maintenance_cb') ?></li> 
      </ul>
      <ul class="inRow asperWidth"> 
       <li><label>Maintenance Message: </label> 
        <textarea name="maintenance_msg" class="plaintext" rows="4" cols="100"><?php echo htmlentities($$class->maintenance_msg); ?> </textarea>
       </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
    </div>
   </div>

  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading">Line Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">Messages</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column four_column"> 
       <li><label>Posts in Front Page: </label> <?php $f->text_field_d('posts_in_fp') ?></li> 
       <li><label>Limit Summary Characters : </label> <?php $f->text_field_d('summary_char_fp') ?></li> 
       <li><label>Anonymous User : </label> <?php $f->text_field_d('anonymous_user') ?></li> 
       <li><label>Anonymous Role : </label> <?php $f->text_field_d('anonymous_user_role') ?></li> 

      </ul>
      <ul class="inRow asperWidth"> 
       <li><label>Footer Message: </label> 
        <textarea required name="footer_message" class="plaintext" rows="4" cols="80"><?php echo htmlentities($$class->footer_message); ?> </textarea>
       </li> 
       <li><label>Site Logo Path : </label> <?php echo HOME_URL . $f->text_field('logo_path', $$class->logo_path, '60'); ?> </li> 
      </ul>
     </div>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="inRow asperWidth"> 
       <li><label>Access Denied Message: </label> 
        <textarea required name="footer_message" class="plaintext" rows="8" cols="80"><?php echo htmlentities($$class->access_denied); ?> </textarea>
       </li> 
      </ul>
     </div>
     <!--                end of tab2 div three_column-->
    </div>
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="site_info" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="form_header_id" data-form_header_id="site_info" ></li>
 </ul>
</div>