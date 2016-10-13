<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Budget Entry') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
		<ul class="column header_field">
		 <li><?php
				 $f->budget_name('wo_number', 'gl_budget', 'budget_name', 'ledger_id', '');
				 echo $f->hidden_field_withId('gl_budget_entry_id', $$class->gl_budget_entry_id);
//				 echo $f->hidden_field_withCLass('wo_status', 'RELEASED', 'popup_value');
				 ?>
			<i class="generic g_select_wo_number select_popup clickable fa fa-search" data-class_name="wip_wo_header"></i>
			<a name="show2" href="form.php?class_name=gl_budget_entry&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wo_header_id">
			 <i class="fa fa-refresh"></i></a> 
		 </li>
		 <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
		 <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
		 <li><?php $f->l_select_field_from_object('transaction_type', wip_move_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', '', 1, 1, 1); ?>       
			<a name="show2" href="form.php?class_name=gl_budget_entry&<?php echo "mode=$mode"; ?>" class="show2 document_id gl_budget_entry_id">
			 <i class="fa fa-refresh"></i></a> 
		 </li> 
		</ul>
   </div>
  </div>
 </div>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Operation Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Operation') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="gl_budget_entry"  name="gl_budget_entry">
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
      <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
					<?php
					$lineCount = 0;
					foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
					 $class_third = 'wip_wo_routing_detail';
					 $$class_third = &$wip_wo_routing_detail;
					 ?>
 			 <tr class="gl_budget_entry<?php echo $lineCount ?>">
 				<td>    
 				 <ul class="inline_action">
 					<li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
 					<li class="remove_row_img"><i class="fa fa-minus-circle-circle"></i></li>
 					<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_routing_line->wip_wo_routing_line_id); ?>"></li>           
 				 </ul>
 				</td>
 				<td><?php form::number_field_wid('gl_budget_entry_id'); ?></td>
 				<td><?php $f->ac_field_widm('gl_account_id'); ?></td>
 				<td><?php echo $f->text_field_wid('budget_amount'); ?></td>
 				<td><?php echo $f->text_field_wid('description'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_type'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_key_name'); ?></td>
 				<td><?php echo $f->text_field_wid('reference_key_value'); ?></td>
 			 </tr>
				<?php
				$lineCount++;
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
  <li class="lineClassName" data-lineClassName="gl_budget_entry" ></li>
  <li class="line_key_field" data-line_key_field="name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_budget_entry" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="gl_budget_entry_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="gl_budget_entry" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>