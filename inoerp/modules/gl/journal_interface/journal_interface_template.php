<div id="journal_interface_divId">
 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
 <!--    End of place for showing error messages-->
 <div id ="form_header">
  <form  method="post" id="gl_journal_interface" name="gl_journal_interface"  >
   <span class="heading"><?php echo gettext('Journal Interface Details') ?></span>
   <div class="tabContainer"> 
    <ul class="column header_field"> 
     <li><?php $f->l_text_field_dr_withSearch('gl_journal_interface_id') ?>
      <a name="show" href="form.php?class_name=gl_journal_interface&<?php echo "mode=$mode"; ?>" class="show document_id gl_journal_interface_id">
       <i class="fa fa-refresh"></i></a> 
     </li>
     <li><?php $f->l_text_field_dr('gl_journal_header_id', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('gl_journal_line_id', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('ledger_id', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('currency', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('document_date', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('period_id', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('journal_source', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('journal_category', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('journal_name', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('description', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('balance_type', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('post_date', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('header_amount', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('doc_currency', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('exchange_type', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('exchange_date', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('exchange_rate', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('control_total', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('running_total_dr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('running_total_cr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('running_toatl_ac_dr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('running_toatl_ac_cr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('reference_type', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('reference_key_name', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('reference_key_value', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_num', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_status', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_type', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_description', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('code_combination_id', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('total_dr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('total_cr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('total_ac_dr', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_reference_type', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_reference_key_name', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('line_reference_key_value', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('created_by', 'always_readonly'); ?></li>
     <li><?php $f->l_text_field_dr('creation_date', 'always_readonly'); ?></li>
     
     
    </ul>
   </div>
  </form> 
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="gl_journal_interface" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_journal_interface_id" ></li>
  <li class="form_header_id" data-form_header_id="gl_journal_interface" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="gl_journal_interface_id" ></li>
  <li class="btn1DivId" data-btn1DivId="gl_journal_interface_id" ></li>
 </ul>
</div>