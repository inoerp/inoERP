<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<span class="heading"><?php echo gettext('Sales Opportunity') ?></span>
<div id ="form_header">
 <form  method="post" id="sd_opportunity"  name="sd_opportunity">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('New Contact') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('sd_opportunity_id') ?>
        <a name="show" href="form.php?class_name=sd_opportunity&<?php echo "mode=$mode"; ?>" class="show document_id sd_opportunity_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dr('sd_lead_id'); ?> 					</li>
       <li><?php $f->l_text_field_dm('opportunity_number'); ?> 					</li>
       <li><?php $f->l_text_field_dm('opportunity_subject'); ?> 					</li>
       <li><?php $f->l_select_field_from_array('status', sd_opportunity::$status_a, $$class->status, 'status', '', '', 1, 1); ?> 					</li>
       <li><?php $f->l_number_field('win_probability', $$class->win_probability); ?> 					</li>
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency'); ?></li>
       <li><?php $f->l_number_field('forecast_amount', $$class->forecast_amount); ?> 					</li>
       <li><?php $f->l_date_fieldFromToday('expected_close_date', $$class->expected_close_date); ?> 					</li>
       <li><?php $f->l_text_field_d('referral_source'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('sales_channel', sd_lead::sales_channel(), 'option_line_code', 'option_line_value', $$class->sales_channel, 'sales_channel'); ?> 					</li>
       <li><?php $f->l_text_field_d('description'); ?> 					</li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('last_name'); ?> </li>
        <li><?php $f->l_text_field_d('first_name'); ?></li>
        <li><?php $f->l_text_field_d('mobile_number'); ?></li>
        <li><?php $f->l_text_field_d('office_number'); ?></li>
        <li><?php $f->l_text_field_d('fax_no'); ?></li>
        <li><?php $f->l_text_field_d('email_id'); ?></li>
        <li><?php $f->l_text_field_d('timezone'); ?></li>
        <li><?php $f->l_text_field_d('time_to_contact'); ?></li>
        <li><?php $f->l_text_field_d('contact_website'); ?></li>
        <li><?php $f->l_text_field_d('contact_address'); ?></li>
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
       <ul class="column header_field">
        <li><label><?php echo gettext('Action') ?></label>
         <?php
         echo $f->select_field_from_array('action', $$class->action_a, '', 'action');
         ?>
        </li>
        <li><label><?php echo gettext('Close Reason') ?></label><?php $f->text_field_d('close_reason'); ?> 					</li>
       </ul>

       <div id="comment" class="shoe_comments">
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>

  <div id ="form_line"><span class="heading"><?php echo gettext('Other Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Existing Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Address Details') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Contact') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', '', $readonly); ?>						 </li>
       <li><?php
        echo $f->l_val_field_dm('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
        echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
        ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
       <li><?php
        echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
        ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
       <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', '', '', $readonly); ?> </li>
       <li><?php $f->l_text_field_d('campaign_id'); ?>	</li>
       <li><?php $f->l_text_field_d('campaign_os'); ?>	</li>
       <li><?php $f->l_select_field_from_object('sales_team', hr_team_header::find_all_sales_team(), 'hr_team_header_id', 'team_name', $$class->sales_team, 'sales_team'); ?> 					</li>
       <li><?php
        echo $f->l_val_field_d('sales_person', 'hr_employee_v', 'employee_name', '', 'vf_select_document_owner employee_name');
        echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
        ?><i class="generic g_select_document_owner select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
      </ul>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <div class="address"><?php $f->address_field_d('address_id'); ?></div>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <?php echo $f->contact_field('sd_opportunity', $$class->sd_opportunity_id, $all_contacts); ?>
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