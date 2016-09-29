<div id ="form_header"><span class="heading"><?php echo gettext('Submitted Program Details') ?></span>
 <form  method="post" id="sys_program"  name="sys_program">
  <div class="tabContainer"> 
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('sys_program_id') ?>
     <a name="show" href="form.php?class_name=sys_program&<?php echo "mode=$mode"; ?>" class="show document_id sys_program_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
    <li><?php $f->l_text_field_dm('program_name'); ?> </li> 
    <li><?php $f->l_text_field_d('status'); ?> </li> 
    <li><?php $f->l_text_field_d('module_name'); ?> </li> 
    <li><?php $f->l_text_field_d('class'); ?> </li> 
    <li><?php $f->l_text_field_dr('program_source'); ?> </li>
    <li><?php $f->l_text_field_dr('op_email_address'); ?> </li>
    <li><?php $f->l_text_field_dr('op_email_format'); ?> </li>
    <li><?php $f->l_select_field_from_array('email_format', dbObject::$download_format, 'excel_format') ?> </li>
    <li><?php $f->l_select_field_from_array('request_type', sys_program_schedule::$request_type_a, $$class->request_type, 'request_type', '', '', 1, 1); ?> </li>
    <li><?php $f->l_text_field_d('description'); ?> </li> 
   </ul> 
  </div>
 </form>
</div>
<div id ="form_line">
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Program Output') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Report Query') ?></a></li>
   <li><a href="#tabsLine-3"><?php echo gettext('Email Address') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsLine-1" class="tabContent">
    <span class="heading"><?php echo gettext('Output') ?> </span><?php
    if (!empty($$class->output_path)) {
     $home_url_wos = rtrim(HOME_URL, '/');
     echo "<a href='" . $home_url_wos . $$class->output_path . "' target='new'> View </a> ";
    }
    ?>
    <span class="heading"><?php echo gettext('Parameters') ?> </span>
    <?php
    if (DB_TYPE == 'ORACLE' && !empty($$class->parameters)) {
     $$class->parameters = stream_get_contents($$class->parameters);
    }
    echo '<pre>';
    print_r(unserialize($$class->parameters));
    echo '</pre>';
    ?>
    <span class="heading"><?php echo gettext('Message Details') ?></span>
    <?php
    if (DB_TYPE == 'ORACLE' && !empty($$class->message)) {
     $$class->message = stream_get_contents($$class->message);
    }
    echo $$class->message;
    ?>
   </div>
   <div id="tabsLine-2" class="tabContent"><label>SQL Query</label>
    <?php echo form::text_area('parameter', base64_decode($$class->report_query), '10', '150', '', '', '', 1); ?>
   </div>
   <div id="tabsLine-3" class="tabContent">
    <?php echo form::text_area('email_addresses', $$class->op_email_address, '3', '120', '', gettext('Separate each email address by comma(,) or a new line'),'',1) ?>
   </div>
  </div>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_program" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_program_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_program" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_program_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_program_id" ></li>
 </ul>
</div>
