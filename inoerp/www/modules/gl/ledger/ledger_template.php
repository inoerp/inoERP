<div id="form_all">
 <span class="heading"><?php echo gettext('Ledger Header') ?></span>
 <form method="post" id="gl_ledger"  name="gl_ledger">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Accounts') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php echo $f->l_text_field_dr_withSearch('gl_ledger_id'); ?>
        <a name="show" href="form.php?class_name=gl_ledger&<?php echo "mode=$mode"; ?>" class="show document_id gl_ledger_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('ledger'); ?></li>
       <li><?php $f->l_text_field_dm('description'); ?></li>
       <li><?php $f->l_select_field_from_object('coa_id', coa::find_all(), 'coa_id', 'description', $$class->coa_id, 'coa_id', '', 1, $readonly1, '', '', '', 'coa_structure_id'); ?></li>
       <li><?php $f->l_select_field_from_object('coa_structure_id', coa::coa_structures(), 'option_header_id', 'option_type', $$class->coa_structure_id, 'coa_structure_id', '', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('currency_code', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency_code, 'currency_code', '', 1, $readonly1); ?></li>
       <li><?php $f->l_select_field_from_object('calendar_option_line_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $$class->calendar_option_line_code, 'option_line_code', '', 1, $readonly1); ?></li>
       <li><?php $f->l_number_field_d('future_enabled_periods'); ?></li>
       <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
       <li><?php $f->l_text_field_d('rev_number'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_ac_field_d('retained_earnings_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('suspense_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('currency_balancing_ac_id'); ?></li>
       </ul>
      </div>
     </div>
    </div>
   </div>
  </div>
 </form>
 <div id ="form_line" class="gl_ledger_balancing_values"><span class="heading"><?php echo gettext('Ledger Options') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Balancing Segment Values') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form  method="post" id="gl_ledger_balancing_values_line"  name="gl_ledger_balancing_values_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Balance Segment Value') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody gl_ledger_balancing_values_values" >
        <?php
        $count = 0;
        foreach ($gl_ledger_balancing_values_object as $gl_ledger_balancing_values) {
         ?>         
         <tr class="gl_ledger_balancing_values<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($gl_ledger_balancing_values->gl_ledger_balancing_values_id, array('gl_ledger_id' => $$class->gl_ledger_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('gl_ledger_balancing_values_id'); ?></td>
          <td><?php
           $svgl = new sys_value_group_line();
           $descp = ['code_value', 'description'];
           echo form::select_field_from_object('balancing_values', $svgl->findBy_parentId($value_group_headerid), 'code', $descp, $$class_second->balancing_values, '', $readonly);
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
     </div>
    </form>
   </div>

  </div>
 </div> 
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="gl_ledger" ></li>
  <li class="lineClassName" data-lineClassName="gl_ledger_balancing_values" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_ledger_id" ></li>
  <li class="form_header_id" data-form_header_id="gl_ledger" ></li>
  <li class="line_key_field" data-line_key_field="balancing_values" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_ledger_balancing_values" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="gl_ledger_id" ></li>
  <li class="docLineId" data-docLineId="gl_ledger_balancing_values_id" ></li>
  <li class="btn1DivId" data-btn1DivId="gl_ledger" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="gl_ledger_balancing_values" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>