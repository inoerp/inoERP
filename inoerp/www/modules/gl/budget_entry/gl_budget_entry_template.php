<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<?php $f = new inoform(); ?>
<div id ="form_header"><span class="heading"><?php echo gettext('Budget Entry') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
		<ul class="column header_field">
		 <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', 1, $readonly1, '','','','currency_code'); ?>             </li>
		 <li><?php
				 $f->l_val_field_d('budget_name', 'gl_budget', 'budget_name', 'gl_ledger_id', '');
				 echo $f->hidden_field_withId('gl_budget_id', $$class->gl_budget_id);
				 ?>
      <i class="generic g_select_budget_name select_popup clickable fa fa-search" data-class_name="gl_budget"></i>
     </li>
		 <li><?php
				 $f->l_val_field_d('ac_name', 'gl_budget_ac_header', 'ac_name', 'gl_ledger_id', '');
				 echo $f->hidden_field_withId('gl_budget_ac_header_id', $$class->gl_budget_ac_header_id);
				 ?>
      <i class="generic g_selectgl_budget_ac_name select_popup clickable fa fa-search" data-class_name="gl_budget_ac_header"></i>
     </li>
		 <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'ledger_currency', 1, 1); ?></li>
		 <li><label><?php echo gettext('From Period') ?></label><?php
				 if (!empty($period_name_stmt)) {
					echo $period_name_stmt;
				 } else {
					$f->text_field_d('first_period_id');
				 }
				 ?>
			<a name="show2" href="form.php?class_name=gl_budget_entry&<?php echo "mode=$mode"; ?>" class="show2 document_id gl_budget_entry_id">
			 <i class="fa fa-refresh"></i></a> 
		 </li> 
		</ul>
   </div>
  </div>
 </div>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Budget Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form method="post" id="gl_budget_entry"  name="gl_budget_entry">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Entry Id') ?></th>
        <th><?php echo gettext('Account') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Ref Type') ?></th>
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Key Value') ?></th>
       </tr>
      </thead>
			<tbody class="form_data_line_tbody budget_ac_values" >
					<?php
					$count = 0;
					$budget_ac_object_ai = new ArrayIterator($budget_ac_object);
					$budget_ac_object_ai->seek($position);
					while ($budget_ac_object_ai->valid()) {
					 $gl_budget_entry = $budget_ac_object_ai->current();
					 ?>         
 			 <tr class="gl_budget_entry<?php echo $count ?>">
 				<td><?php echo ino_inline_action($$class->gl_budget_entry_id, array('gl_budget_id' => $gl_budget_id_h, 'currency' => $currency_h, 'gl_budget_ac_header_id' => $gl_budget_ac_header_id_h, 'ledger_id' => $ledger_id_h)); ?> </td>
 				<td><?php form::number_field_wid('gl_budget_entry_id'); ?></td>
 				<td><?php $f->ac_field_widm('gl_account_id'); ?></td>
 				<td><?php echo $f->text_field_wid('budget_amount'); ?></td>
 				<td><?php echo $f->text_field_wid('description'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_type'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_key_name'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_key_value'); ?></td>
 			 </tr>
				<?php
				$budget_ac_object_ai->next();
				if ($budget_ac_object_ai->key() == $position + $per_page) {
				 break;
				}
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


<div class="row small-top-margin">
<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>
 </div>

<div id="js_data">
 <ul id="js_saving_data">
	<li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="lineClassName" data-lineClassName="gl_budget_entry" ></li>
  <li class="line_key_field" data-line_key_field="gl_budget_ac_line_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_budget_entry" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="gl_budget_entry_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="gl_budget_entry" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
