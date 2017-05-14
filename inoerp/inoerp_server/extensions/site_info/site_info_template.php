<form  method="post" id="site_info"  name="site_info">
 <span class="heading"><?php echo gettext('Site Information') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Maintenance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Java Script Defaults') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Colors') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Global Settings') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_d('site_name'); ?> </li> 
      <li><?php $f->l_text_field_d('email'); ?> </li> 
      <li><?php $f->l_text_field_d('phone_no'); ?> </li> 
      <li><label><?php echo gettext('Home Page') . '  ' . HOME_URL ?></label><?php echo $f->text_field('default_home_page', $$class->default_home_page, '20'); ?> </li>
     </ul>

    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><label><?php echo gettext('Put in Maintenance Mode') ?></label> <?php $f->checkBox_field_d('maintenance_cb') ?></li> 
      </ul>
      <ul class="inRow asperWidth"> 
       <li><label><?php echo gettext('Maintenance Message') ?></label> 
        <textarea name="maintenance_msg" class="plaintext" rows="4" cols="100"><?php echo htmlentities($$class->maintenance_msg); ?> </textarea>
       </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_select_field_from_array('move_line_wo_header', site_info::$move_line_wo_header_a, $$class->move_line_wo_header, 'move_line_wo_header'); ?> </li> 
      
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_color_field_d('mandatory_field_color'); ?> </li> 
      <li><?php $f->l_color_field_d('heading_color'); ?> </li> 
      <li><?php $f->l_color_field_d('content_color'); ?> </li> 
      <li><?php $f->l_checkBox_field_d('show_bg_image_cb'); ?> </li> 
      <li><label><?php echo gettext('BG Image ') . HOME_URL ?></label><?php echo $f->text_field('bg_image_path', $$class->bg_image_path, '20'); ?> </li> 
      <li><?php $f->l_number_field_d('bg_opacity'); ?> </li> 
     </ul>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field"> 
     <li><?php $f->l_select_field_from_array('disabled_action', site_info::$disabled_action_a, $$class->disabled_action, 'disabled_action'); ?> </li> 
     <li><?php $f->l_checkBox_field_d('ar_revenue_schedule_cb'); ?> </li>
     </ul>
    </div>
   </div>

  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Line Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Messages') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Hidden Texts') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_d('posts_in_fp') ?></li> 
       <li><?php $f->l_text_field_d('summary_char_fp') ?></li> 
       <li><?php $f->l_text_field_d('anonymous_user') ?></li> 
       <li><?php $f->l_text_field_d('anonymous_user_role') ?></li> 
      </ul>
      <ul class="inRow asperWidth"> 
       <li><label><?php echo gettext('Footer Message') ?></label> 
        <textarea required name="footer_message" class="plaintext" rows="4" cols="80"><?php echo htmlentities($$class->footer_message); ?> </textarea>
       </li> 
       <li><label><?php echo gettext('Site Logo Path') ?></label> <?php echo HOME_URL . $f->text_field('logo_path', $$class->logo_path, '60'); ?> </li> 
      </ul>
     </div>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="inRow asperWidth"> 
       <li><label><?php echo gettext('Access Denied Message') ?></label> 
        <textarea required name="footer_message" class="plaintext" rows="8" cols="80"><?php echo htmlentities($$class->access_denied); ?> </textarea>
       </li> 
      </ul>
     </div>
     <!--                end of tab2 div three_column-->
    </div>

    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="inRow asperWidth"> 
       <li><label><?php echo gettext('Analytics Code') ?></label> 
        <textarea name="analytics_code" class="plaintext" rows="8" cols="80"><?php echo htmlentities($$class->analytics_code); ?> </textarea>
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
