<?php 
if (!isset($readonly1)) {
 $readonly1 = $readonly;
}
?>
<span class="heading-right"><?php echo gettext('Journal Header') ?></span>
<div id ="form_header">
 <form method="post" id="gl_journal_header"  name="gl_journal_header">
  
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Reference Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php echo $f->l_text_field_dr_withSearch('gl_journal_header_id') ?>
       <a name="show" href="form.php?class_name=gl_journal_header&<?php echo "mode=$mode"; ?>" class="show document_id gl_journal_header_id">
        <i class="fa fa-refresh"></i></a> </li>
      <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', 1, $readonly1); 
      echo $f->hidden_field_withId('coa_id', $$class->coa_id);    ?></li>
      <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'ledger_currency', '', 1, 1); ?>  </li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->doc_currency, 'doc_currency', '', 1, $readonly1); ?>  </li>
      <li><label>Period Name(3)</label><?php echo $period_name_stmt; ?></li>
      <li><?php $f->l_date_fieldFromToday_m('document_date', $$class->document_date) ?></li>
      <li><?php $f->l_text_field_dm('journal_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_select_field_from_object('balance_type', $$class->gl_balance_type(), 'option_line_code', 'option_line_value', $$class->balance_type, 'balance_type', '', 1, $readonly1); ?></li>
      <li><?php $f->l_select_field_from_array('status', $$class->status_a, $$class->status, 'status','always_readonly', 1); ?></li>
      <li><?php $f->l_date_fieldFromToday_d('post_date', $$class->post_date) ?></li>
      <li id="document_status"><?php $f->l_select_field_from_array('action', $action_a, $$class->action, 'action'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="vertical-align-top">
      <div class="panel panel-collapse panel-ino-classy large_box">
       <div class="panel-heading"><div class="panel-title font-medium"><?php echo gettext('Rate & Amounts') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_select_field_from_object('exchange_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_type, 'exchange_type', '', '', $readonly); ?></li>
         <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
         <li><?php $f->l_number_field('running_total_dr', $$class->running_total_dr, '15', 'running_total_dr'); ?></li>
         <li><?php $f->l_number_field('running_total_cr', $$class->running_total_cr, '15', 'running_total_cr'); ?></li>
         <li><?php $f->l_number_field('running_toatl_ac_dr', $$class->running_toatl_ac_dr, '15', 'running_toatl_ac_dr'); ?></li>
         <li><?php $f->l_number_field('running_toatl_ac_cr', $$class->running_toatl_ac_cr, '15', 'running_toatl_ac_cr'); ?></li>
         <li><?php $f->l_number_field('control_total', $$class->control_total, '15', 'control_total'); ?></li>
        </ul>
       </div>
      </div>
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title font-medium"><?php echo gettext('References') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_select_field_from_object('journal_source', option_header::find_options_byName('GL_JOURNAL_SOURCE'), 'option_line_code', 'option_line_value', $$class->journal_source, 'journal_source', '', 1) ?>				</li>
         <li><?php $f->l_select_field_from_object('journal_category', $$class->gl_journal_category(), 'option_line_code', 'option_line_value', $$class->journal_category, 'journal_category', '', '', 1, $readonly1); ?></li>
         <li><?php $f->l_text_field_d('reference_type'); ?></li>
         <li><?php $f->l_text_field_d('reference_key_name'); ?></li>
         <li><?php $f->l_text_field_d('reference_key_value'); ?></li>
         <li><label><?php echo gettext('View Ref Doc') ?></label><?php echo $ref_doc_stmt; ?></li>
        </ul>
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'gl_journal_header';
       $reference_id = $$class->gl_journal_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id ="form_line" class="gl_journal_line"><span class="heading"><?php echo gettext('Journal Lines') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Other Info') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form  method="post" id="gl_journal_line"  name="gl_journal_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line #') ?></th>
        <th><?php echo gettext('Account') ?></th>
        <th><?php echo gettext('Debit') ?></th>
        <th><?php echo gettext('Credit') ?></th>
        <th><?php echo gettext('Ledger Dr') ?></th>
        <th><?php echo gettext('Ledger Cr') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody gl_journal_line_values" >
       <?php
       $count = 0;
       foreach ($gl_journal_line_object as $gl_journal_line) {
        ?>         
        <tr class="gl_journal_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->gl_journal_line_id, array('gl_journal_header_id' => $$class->gl_journal_header_id,
           'ledger_id' => $$class->ledger_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('gl_journal_line_id'); ?></td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php echo form::text_field('line_num', $$class_second->line_num, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php $f->ac_field_wid2('code_combination_id', 'dontCopy'); ?> </td>
         <td><?php form::number_field_wid2('total_dr'); ?></td>
         <td><?php form::number_field_wid2('total_cr'); ?></td>
         <td><?php form::number_field_wid2('total_ac_dr'); ?></td>
         <td><?php form::number_field_wid2('total_ac_cr'); ?></td>
         <td><?php
          $status = empty($$class_second->status) ? 'U' : $$class_second->status;
          echo $f->text_field('status', $status, 8, '', 'copy', '', 1);
          ?></td>

        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Ref Type') ?></th>
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Value') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody gl_journal_line_values" >
       <?php
       $count = 0;
       foreach ($gl_journal_line_object as $gl_journal_line) {
        ?>         
        <tr class="gl_journal_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php form::text_field_wid2l('description'); ?></td>
         <td><?php form::text_field_wid2r('reference_type'); ?></td>
         <td><?php form::text_field_wid2r('reference_key_name'); ?></td>
         <td><?php form::text_field_wid2r('reference_key_value'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>

 </div>
</div> 

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="gl_journal_header" ></li>
  <li class="lineClassName" data-lineClassName="gl_journal_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_journal_header_id" ></li>
  <li class="form_header_id" data-form_header_id="gl_journal_header" ></li>
  <li class="line_key_field" data-line_key_field="code_combination_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_journal_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="gl_journal_header_id" ></li>
  <li class="docLineId" data-docLineId="gl_journal_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="gl_journal_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="gl_journal_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>