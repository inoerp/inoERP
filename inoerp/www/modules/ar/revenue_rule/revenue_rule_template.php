<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Revenue Rule'); ?></span>
 <form method="post" id="ar_revenue_rule_header"  name="ar_revenue_rule_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ar_revenue_rule_header_id') ?>
       <a name="show" href="form.php?class_name=ar_revenue_rule_header&<?php echo "mode=$mode"; ?>" class="show document_id ar_revenue_rule_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('rule_name'); ?></li>
      <li><?php $f->l_select_field_from_array('rule_type', ar_revenue_rule_header::$rule_type_a, $$class->rule_type, 'rule_type'); ?>						 </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_text_field_d('period'); ?></li>
      <li><?php $f->l_text_field_d('no_of_period'); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
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
        $reference_table = 'ar_revenue_rule_header';
        $reference_id = $$class->ar_revenue_rule_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Revenue Rule Lines') ?></span>
 <form method="post" id="ar_revenue_rule_line"  name="ar_revenue_rule_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Revenue Schedules') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Period Number') ?></th>
        <th><?php echo gettext('Percentage') ?></th>
        <th><?php echo gettext('Date') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_revenue_rule_line_object as $ar_revenue_rule_line) {
        ?>         
        <tr class="ar_revenue_rule_line<?php echo $count ?>">
         <td><?php echo ino_inline_action($ar_revenue_rule_line->ar_revenue_rule_line_id, array('ar_revenue_rule_header_id' => $$class->ar_revenue_rule_header_id)); ?></td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2r('ar_revenue_rule_line_id'); ?></td>
         <td><?php echo $f->number_field('period_number', $$class_second->period_number); ?></td>
         <td><?php $f->text_field_wid2('description', 'percent'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('schedule_date', $$class_second->schedule_date); ?></td>
         <td><?php $f->text_field_wid2('description', 'xlarge'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_revenue_rule_header" ></li>
  <li class="lineClassName" data-lineClassName="ar_revenue_rule_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_revenue_rule_header_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_revenue_rule_header" ></li>
  <li class="line_key_field" data-line_key_field="period_number" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_revenue_rule_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_revenue_rule_header_id" ></li>
  <li class="docLineId" data-docLineId="ar_revenue_rule_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_revenue_rule_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>