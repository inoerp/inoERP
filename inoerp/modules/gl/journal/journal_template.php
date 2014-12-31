<?php
if (!isset($readonly1)) {
 $readonly1 = $readonly;
}
?>
<div id ="form_header">
 <form action=""  method="post" id="gl_journal_header"  name="gl_journal_header"><span class="heading">Journal Header </span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Reference Details</a></li>
    <li><a href="#tabsHeader-3">Attachments</a></li>
    <li><a href="#tabsHeader-4">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="gl_journal_header_id select_popup">
         Journal Header Id</label><?php echo $f->text_field_dsr('gl_journal_header_id') ?>
        <a name="show" href="form.php?class_name=gl_journal_header&<?php echo "mode=$mode"; ?>" class="show document_id gl_journal_header_id">
         <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> </li>
       <li><label>Ledger Name(1)</label><?php echo $f->select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', 1, $readonly1); ?></li>
       <li><label>Currency(2)</label><?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'currency', '', 1, $readonly1); ?>  </li>
       <li><label>Period Name(3)</label><?php echo $period_name_stmt; ?></li>
       <li><label>COA</label><?php echo form::text_field_dsrm('coa_id'); ?></li>
       <li><label>Document Date</label><?php echo form::date_fieldFromToday_m('document_date', $$class->document_date) ?></li>
       <li><label>Journal Name</label><?php echo form::text_field_dm('journal_name'); ?></li>
       <li><label>Description</label><?php echo form::text_field_d('description'); ?></li>
       <li><label>Balance Type</label><?php echo form::select_field_from_object('balance_type', $$class->gl_balance_type(), 'option_line_code', 'option_line_value', $$class->balance_type, 'balance_type', $readonly1, '', '', 1); ?></li>
       <li><label>Status</label><?php echo form::text_field('status', $$class->status, '', '', '', '', '', 1); ?></li>
       <li><label>Posted Date</label><?php echo form::date_fieldFromToday('post_date', $$class->post_date) ?></li>
       <li><label>Revision</label><?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></li> 
       <li><label>Rev Number</label><?php form::text_field_wid('rev_number'); ?></li> 
       <li id="document_status"><label>Action</label><?php echo $f->select_field_from_array('action', $action_a, $$class->action, 'action'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="small_box gl_exchange_details">
       <box_heading>Exchange Rate Details</box_heading> 
       <li><label>Exchange Rate Type : </label>
        <?php echo form::text_field_d('exchange_type'); ?>
       </li>
       <li><label>Exchange Date : </label>
        <?php echo form::date_fieldAnyDay('document_date', $$class->document_date) ?>
       </li>
       <li><label>Exchange Rate : </label>
        <?php form::number_field_d('exchange_rate'); ?>
       </li>
      </ul>
      <ul class="small_box amount_details">
       <box_heading>Header Amounts</box_heading> 
       <li><label>Total Dr : </label>
        <?php form::number_field_dr('running_total_dr'); ?>
       </li>
       <li><label>Total Cr: </label>
        <?php form::number_field_dr('running_total_cr'); ?>
       </li>
       <li><label>Ledger Total Dr : </label>
        <?php form::number_field_dr('running_toatl_ac_dr'); ?>
       </li>
       <li><label>Ledger Total Cr : </label>
        <?php form::number_field_dr('running_toatl_ac_cr'); ?>
       </li>
       <li><label>Control Total : </label>
        <?php form::text_field_d('control_total'); ?>
       </li>
      </ul>
      <ul class="large_box reference_details">
       <box_heading>Journal References</box_heading> 
       <li><label>Journal Source : </label>
        <?php echo form::text_field_dm('journal_source'); ?>
       </li>
       <li><label>Reference Category : </label>
        <?php echo form::select_field_from_object('journal_category', $$class->gl_journal_category(), 'option_line_code', 'option_line_value', $$class->journal_category, 'journal_category', $readonly1, '', '', 1); ?>
       </li>
       <li><label>Reference Type : </label>
        <?php echo form::text_field_d('reference_type'); ?>
       </li>
       <li><label>Ref Key Name : </label>
        <?php echo form::text_field_d('reference_key_name'); ?>
       </li>
       <li><label>Ref Key Value : </label>
        <?php echo form::text_field_d('reference_key_value'); ?>
       </li>
       <li><label>View Ref Doc : </label>
        <?php echo $ref_doc_stmt; ?>
       </li>
      </ul>

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

<div id ="form_line" class="gl_journal_line"><span class="heading">Journal Lines </span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1">Basic </a></li>
   <li><a href="#tabsLine-2">Other Info </a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="gl_journal_line"  name="gl_journal_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Line Id</th>
        <th>Line Number</th>
        <th>Account</th>
        <th>Debit</th>
        <th>Credit</th>
        <th>Ledger Dr</th>
        <th>Ledger Cr</th>
        <th>Status</th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody gl_journal_line_values" >
       <?php
       $count = 0;
       foreach ($gl_journal_line_object as $gl_journal_line) {
        ?>         
        <tr class="gl_journal_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->gl_journal_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('gl_journal_header_id', $$class->gl_journal_header_id); ?></li>
           <li><?php echo form::hidden_field('ledger_id', $$class->ledger_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid2sr('gl_journal_line_id'); ?></td>
         <td><?php echo form::text_field('line_num', $$class_second->line_num, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php $f->ac_field_d2('code_combination_id'); ?> </td>
         <td><?php form::number_field_wid2('total_dr'); ?></td>
         <td><?php form::number_field_wid2('total_cr'); ?></td>
         <td><?php form::number_field_wid2('total_ac_dr'); ?></td>
         <td><?php form::number_field_wid2('total_ac_cr'); ?></td>
         <td><?php
          $status = empty($$class_second->status) ? 'U' : $$class_second->status;
          echo $f->text_field('status', $status, 8, '', '', '', 1);
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
        <th>Description</th>
        <th>Ref Type </th>
        <th>Ref Key Name</th>
        <th>Ref Value</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody gl_journal_line_values" >
       <?php
       $count = 0;
       foreach ($gl_journal_line_object as $gl_journal_line) {
        ?>         
        <tr class="gl_journal_line<?php echo $count ?>">
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