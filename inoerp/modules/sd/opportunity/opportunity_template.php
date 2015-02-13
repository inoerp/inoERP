<div id ="form_header">
 <form action=""  method="post" id="sd_opportunity"  name="sd_opportunity"><span class="heading">Sales Opportunity </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">New Contact</a></li>
     <li><a href="#tabsHeader-3">Attachments</a></li>
     <li><a href="#tabsHeader-4">Notes</a></li>
     <li><a href="#tabsHeader-5">Action</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="sd_opportunity_id select_popup clickable">
          Id</label><?php $f->text_field_dsr('sd_opportunity_id') ?>
         <a name="show" href="form.php?class_name=sd_opportunity&<?php echo "mode=$mode"; ?>" class="show document_id sd_opportunity_id"><i class="fa fa-refresh"></i></a> 
        </li>
        <li><label>Lead Id</label><?php $f->text_field_dr('sd_lead_id'); ?> 					</li>
        <li><label>Number</label><?php $f->text_field_dm('opportunity_number'); ?> 					</li>
        <li><label>Subject</label><?php $f->text_field_dm('opportunity_subject'); ?> 					</li>
        <li><label>Status</label><?php echo $f->select_field_from_array('status', sd_opportunity::$status_a, $$class->status, 'status', '', '', 1, 1); ?> 					</li>
        <li><label>Win Probability</label><?php echo $f->number_field('win_probability', $$class->win_probability); ?> 					</li>
        <li><label>Doc Currency</label><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency'); ?></li>
        <li><label>Amount</label><?php echo $f->number_field('forecast_amount', $$class->forecast_amount); ?> 					</li>
        <li><label>Close Date</label><?php echo $f->date_fieldFromToday('expected_close_date', $$class->expected_close_date); ?> 					</li>
        <li><label>Referral Source</label><?php $f->text_field_d('referral_source'); ?> 					</li>
        <li><label>Sales Channel</label><?php echo $f->select_field_from_object('sales_channel', sd_lead::sales_channel(), 'option_line_code', 'option_line_value', $$class->sales_channel, 'sales_channel'); ?> 					</li>
        <li><label>Description</label><?php $f->text_field_dl('description'); ?> 					</li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><label>Last Name</label><?php $f->text_field_d('last_name'); ?> 					</li>
        <li><label>First Name</label><?php $f->text_field_d('first_name'); ?> 					</li>
        <li><label>Mobile</label><?php $f->text_field_d('mobile_number'); ?> 					</li>
        <li><label>Office</label><?php $f->text_field_d('office_number'); ?> 					</li>
        <li><label>Fax</label><?php $f->text_field_d('fax_no'); ?> 					</li>
        <li><label>e-Mail</label><?php $f->text_field_d('email_id'); ?> 					</li>
        <li><label>Time Zone</label><?php $f->text_field_d('timezone'); ?> 					</li>
        <li><label>Preferred Time</label><?php $f->text_field_d('time_to_contact'); ?> 					</li>
        <li><label>Web site</label><?php $f->text_field_d('contact_website'); ?> 					</li>
        <li><label>Address</label><?php $f->text_field_dl('contact_address'); ?> 					</li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'sd_opportunity';
         $reference_id = $$class->sd_opportunity_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label>Action</label>
         <?php
         echo $f->select_field_from_array('action', $$class->action_a, '', 'action');
         ?>
        </li>
        <li><label>Close Reason :</label><?php $f->text_field_d('close_reason'); ?> 					</li>
       </ul>

       <div id="comment" class="shoe_comments">
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>

  <div id ="form_line"><span class="heading">Other Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Existing Info</a></li>
     <li><a href="#tabsLine-2">Address Details</a></li>
     <li><a href="#tabsLine-3">Contact</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column four_column"> 
        <li><?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?>
         <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup clickable">
          Customer Name : </label> <?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1); ?></li>
        <li><label class="auto_complete">Customer Number : </label><?php $f->text_field_d('customer_number'); ?></li>
        <li><label>Customer Site : </label>
         <?php echo $f->select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
        <li><label>System Campaign:</label><?php $f->text_field_d('campaign_id'); ?> 					</li>
        <li><label>Other Campaign:</label><?php $f->text_field_d('campaign_os'); ?> 					</li>
        <li><label>Sales Team:</label><?php echo $f->select_field_from_object('sales_team', hr_team_header::find_all_sales_team(), 'hr_team_header_id', 'team_name', $$class->sales_team, 'sales_team'); ?> 					</li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_employee_name select_popup clickable">
          Primary Sales Person</label><?php $f->text_field_d('sales_person_employee_name'); ?>
         <?php echo $f->hidden_field_withId('sales_person_employee_id', $$class->sales_person_employee_id); ?>
        </li>
        <li><label> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
          Address :</label><?php $f->text_field_d('address_name'); ?>
         <?php echo $f->hidden_field_withId('address_id', $$class->address_id); ?></li> 
       </ul>
      </div>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <ul class="address inline_list">
       <li><label>Phone  : </label> <?php $f->text_field_dr('phone'); ?></li>
       <li><label>Email  : </label> <?php $f->text_field_dr('website'); ?></li>
       <li><label>Web-site  : </label><?php $f->text_field_dr('website'); ?></li>
       <li><label>Country  : </label><?php $f->text_field_dr('country'); ?></li>
       <li><label>Postal Code  : </label> <?php $f->text_field_dr('postal_code'); ?></li>
       <li><label>Address :</label>  
        <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="Select address Id"><?php echo trim(htmlentities($$class->address)); ?></textarea>
       </li>
      </ul>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <?php
      if (!empty($all_contacts)) {
       include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
      }
      ?>
      <div>
       <ul id="new_contact_reference">
        <li class='new_object1'><label><img class="extn_contact_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
          Lead Contact : </label>  
         <?php
         echo $f->hidden_field('extn_contact_id_new', '');
         echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
         ?>  </li>
        <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
       </ul>
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sd_opportunity" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_opportunity_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_opportunity" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_opportunity_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_opportunity" ></li>
 </ul>
</div>