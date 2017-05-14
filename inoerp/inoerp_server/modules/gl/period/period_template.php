<div class="row small-left-padding">
 <div id ="form_header">
  <form method="post" id="gl_period"  name="gl_period">
   <span class="heading"><?php echo gettext('GL Periods') ?></span>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Accounting Period') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $gl_period_object[0]->ledger_id, 'gl_ledger_id','action'); ?>
         <a name="show" href="form.php?class_name=gl_period&<?php echo "mode=$mode"; ?>" class="show document_id gl_ledger_id ">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><label><?php echo gettext('Current Open Period') ?></label><?php echo $cop_stmt; ?></li>
        <li><?php $f->l_select_field_from_object('gl_calendar_id', $next_open_period, 'gl_calendar_id', 'name', '', 'new_gl_calendar_id', '', '', $readonly); ?></li>
        <li><?php $f->l_text_field('status', 'AVAILABLE', '', '', 'status', '', 1); ?></li>
        <li><label><?php echo gettext('Next Period') ?></label><input type="button" class="btn btn-warning" role="button" id="open_next_period" value="Open" 
                                                                      <?php echo ($readonly == 1) ? 'disabled' : ''; ?>				></li>
       </ul>
      <div id="tabsHeader-2" class="tabContent">
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'gl_period';
         $reference_id = $$class->gl_period_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>
     </div>
    </div>

   </div>
  </form>
 </div>

 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Existing & Available Periods') ?></span>
  <form  method="post" id="gl_period_line"  name="gl_period_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Calendar View') ?></a></li>
     <li><a href="#tabsLine-2">Future </a></li>
    </ul>
    <div class="tabContainer"> 

     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Period Id') ?>#</th>
         <th><?php echo gettext('Period Name') ?></th>
         <th><?php echo gettext('Status') ?>#</th>
         <th><?php echo gettext('Year') ?></th>
         <th><?php echo gettext('Quarter') ?></th>
         <th><?php echo gettext('Number') ?></th>
         <th><?php echo gettext('From Date') ?></th>
         <th><?php echo gettext('To Date') ?></th>
         <th><?php echo gettext('Cal Name') ?></th>
         <th><?php echo gettext('Cal Id') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody calendar_values" >
        <?php
        $count = 0;
        $gl_period_object_ai = new ArrayIterator($gl_period_object);
        $gl_period_object_ai->seek($position);
        while ($gl_period_object_ai->valid()) {
         $gl_period = $gl_period_object_ai->current();
         if (!empty($$class->gl_calendar_id)) {
          $cal_i = gl_calendar::find_by_id($$class->gl_calendar_id);
         } else {
          $cal_i = new gl_calendar();
         }
         ?>         
         <tr class="calendar_line<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class->gl_period_id, array('ledger_id' => $gl_period->ledger_id));
           ?>
          </td>
          <td><?php            $f->text_field_dsr('gl_period_id');  ?></td>
          <td><?php $f->text_field_d('period_name') ?></td>
          <td><?php
           echo form::select_field_from_object_ap(array('name' => 'status', 'ob' => gl_period::gl_period_status(),
            'ob_value' => 'option_line_code', 'ob_desc' => 'option_line_value', 'value' => $gl_period->status, 'disabled' => $gl_period->en_dis));
           ?></td>
          <td class="yearPicker"><?php echo $f->text_field_ap(['name' => 'c_year', 'value' => $cal_i->c_year, 'class_name' => 'small', 'readonly' => true]); ?></td>
          <td><?php echo $f->text_field_ap(['name' => 'c_quarter', 'value' => $cal_i->c_quarter, 'class_name' => 'small', 'readonly' => true]); ?></td>
          <td><?php echo $f->text_field_ap(['name' => 'c_number', 'value' => $cal_i->c_number, 'class_name' => 'small', 'readonly' => true]); ?></td>
          <td><?php echo $f->date_fieldAnyDay('from_date', $cal_i->from_date, 'medium'); ?></td>
          <td><?php echo $f->date_fieldAnyDay('to_date', $cal_i->to_date, 'medium'); ?></td>
          <td><?php echo $f->text_field_ap(['name' => 'cal_period_name', 'value' => $cal_i->name, 'class_name' => 'medium', 'readonly' => true]); ?><?php // echo form::text_field('cal_period_name', $gl_period->name, 15, '', 1, '', '', 1);     ?></td>
          <td><?php $f->text_field_dsr('gl_calendar_id'); ?></td>
         </tr>
         <?php
         $gl_period_object_ai->next();
         if ($gl_period_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">

     </div>

    </div>

   </div>
  </form>

 </div>

</div>
<div class="row small-top-margin">
 <div id="pagination">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="gl_period" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_ledger_id" ></li>
  <li class="line_key_field" data-line_key_field="period_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_period" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="gl_period_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="calendar_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>