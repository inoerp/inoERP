<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Rate Schedule') ?></span>
 <form  method="post" id="prj_rate_schedule_header"  name="prj_rate_schedule_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_rate_schedule_header_id') ?>
       <a name="show" href="form.php?class_name=prj_rate_schedule_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_rate_schedule_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_text_field_d('schedule_name'); ?></li>
      <li><?php $f->l_select_field_from_array('rate_type', prj_rate_schedule_header::$rate_type_a, $$class->rate_type, 'rate_type', '', 1, $readonly1); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_rate_schedule_header';
        $reference_id = $$class->prj_rate_schedule_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Rate Schedule Details') ?></span>
 <form action=""  method="post" id="prj_rate_schedule_line"  name="prj_rate_schedule_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Employee') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Job') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Non Labor') ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Resource Class') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <?php
     if (empty($$class->rate_type)) {
      echo "<pre><h2>Save the header with a resource type Employee to view Employee rate form </h2></pre>";
     } else if (!empty($$class->rate_type) && $$class->rate_type != 'EMPLOYEE') {
      echo "<pre><h2>Check {$$class->rate_type} tab to enter the rate details </h2></pre>";
     } else {
      include_once __DIR__ . '/line_templates/employee_template.php';
     }
     ?>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <?php
     if (empty($$class->rate_type)) {
      echo "<pre><h2>Save the header with a resource type Job to view Job rate form </h2></pre>";
     } else if (!empty($$class->rate_type) && $$class->rate_type != 'JOB') {
      echo "<pre><h2>Check {$$class->rate_type} tab to enter the rate details </h2></pre>";
     } else {
      include_once __DIR__ . '/line_templates/job_template.php';
     }
     ?>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <?php
     if (empty($$class->rate_type)) {
      echo "<pre><h2>Save the header with a resource type 'Non Labor Resource' to view 'Non Labor Resource' rate form </h2></pre>";
     } else if (!empty($$class->rate_type) && $$class->rate_type != 'NON_LABOR') {
      echo "<pre><h2>Check {$$class->rate_type} tab to enter the rate details </h2></pre>";
     } else {
      include_once __DIR__ . '/line_templates/nlr_template.php';
     }
     ?>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <?php
     if (empty($$class->rate_type)) {
      echo "<pre><h2>Save the header with a resource type 'Resource Class' to view 'Resource Class' rate form </h2></pre>";
     } else if (!empty($$class->rate_type) && $$class->rate_type != 'RESOURCE_CLASS') {
      echo "<pre><h2>Check {$$class->rate_type} tab to enter the rate details </h2></pre>";
     } else {
      include_once __DIR__ . '/line_templates/resource_class_template.php';
     }
     ?>
    </div>


   </div>
  </div>
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_rate_schedule_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_rate_schedule_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_rate_schedule_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_rate_schedule_header" ></li>
  <li class="line_key_field" data-line_key_field="reference_key_value" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_rate_schedule_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_rate_schedule_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_rate_schedule_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_rate_schedule_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>