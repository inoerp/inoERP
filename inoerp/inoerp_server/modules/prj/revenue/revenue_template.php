<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php
  echo gettext('Project Revenue')
  ?></span>
 <form  method="post" id="prj_revenue_header"  name="prj_revenue_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('References') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_revenue_header_id') ?>
       <a name="show" href="form.php?class_name=prj_revenue_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_revenue_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('revenue_number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php
       $f->l_text_field_dr('project_number');
       echo $f->hidden_field_withCLass('prj_project_header_id', $$class->prj_project_header_id, 'popup_value');
       ?></li>
      <li><?php $f->l_text_field_d('revenue_class'); ?></li>
      <li><?php $f->l_select_field_from_array('revenue_status', prj_revenue_header::$status_a, $$class->revenue_status ,'revenue_status','always_readonly'); ?></li>
      <li><?php $f->l_text_field_dr('transfer_status'); ?></li>

     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_ac_field_d('unearned_coa_id'); ?></li>
      <li><?php $f->l_ac_field_d('unbilled_coa_id'); ?></li>
      <li><?php $f->l_ac_field_d('revenue_coa_id'); ?></li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency always_readonly', 1, 1); ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
      <li><?php $f->l_text_field_dr('unearned_amount'); ?></li>
      <li><?php $f->l_text_field_dr('unbilled_amount'); ?></li>
      <li><?php $f->l_text_field_dr('revenue_amount'); ?></li>
      <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', 1, $readonly1); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr('gl_journal_header_id', 'always_readonly'); ?></li>
      <li><?php $f->l_text_field_dr('rejection_reason', 'always_readonly'); ?></li>
      <li><?php $f->l_text_field_dr('reference_type'); ?></li>
      <li><?php $f->l_text_field_dr('reference_key_name'); ?></li>
      <li><?php $f->l_text_field_dr('reference_key_value'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('release_date', $$class->release_date); ?></li>
      <li><?php $f->l_date_fieldAnyDay('transfer_date', $$class->transfer_date); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_revenue_header';
        $reference_id = $$class->prj_revenue_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <ul class="column header_field">
      <li id="document_status"><label><?php echo gettext('Action') ?></label>
       <?php echo $f->select_field_from_array('action', $$class->action_a, '', 'action'); ?>
      </li>
     </ul>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Revenue Lines') ?></span>
 <form  method="post" id="prj_revenue_line"  name="prj_revenue_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Reference') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line') #    ?></th>
        <th><?php echo gettext('Revenue Category') ?></th>
        <th><?php echo gettext('Revenue Source') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Release Date') ?></th>
        <th><?php echo gettext('Transfer Date') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_revenue_line_object as $prj_revenue_line) {
        ?>         
        <tr class="prj_revenue_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_revenue_line->prj_revenue_line_id, array('prj_revenue_header_id' => $prj_revenue_header->prj_revenue_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('prj_revenue_line_id', 'line_id always_readonly'); ?></td>
         <td><?php $f->text_field_wid2sr('line_number', 'lines_number always_readonly'); ?></td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2('revenue_category'); ?></td>
         <td><?php $f->text_field_wid2('revenue_source'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2('amount'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('release_date', $$class_second->release_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('transfer_date', $$class_second->transfer_date); ?></td>

        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Reject Reason') ?></th>
        <th><?php echo gettext('Document Number') ?></th>
        <th><?php echo gettext('Reference Type') ?></th>
        <th><?php echo gettext('Reference Key') ?></th>
        <th><?php echo gettext('Reference Value') ?></th>
        <th><?php echo gettext('Journal Header Id') ?></th>
        <th><?php echo gettext('Transferred') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_revenue_line_object as $prj_revenue_line) {
        ?>         
        <tr class="prj_revenue_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2('rejection_reason'); ?></td>
         <td><?php $f->text_field_wid2('document_number'); ?></td>
         <td><?php $f->text_field_wid2r('reference_type', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2l('reference_key_name', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2l('reference_key_value', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2r('gl_journal_header_id'); ?></td>        
         <td><?php echo $f->checkBox_field('gl_journal_interface_cb', $$class_second->gl_journal_interface_cb,'','always_readonly'); ?></td>        
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
  <li class="headerClassName" data-headerClassName="prj_revenue_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_revenue_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_revenue_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_revenue_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_revenue_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_revenue_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_revenue_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_revenue_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
