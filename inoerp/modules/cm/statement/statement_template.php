<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<?php $f = new inoform(); ?>
<div id ="form_header"><span class="heading"><?php echo gettext('Bank Statement') ?></span>
 <form method="post" id="cm_statement_header"  name="cm_statement_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Amount') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
	 </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('cm_statement_header_id') ?>
       <a name="show" href="form.php?class_name=cm_statement_header&<?php echo "mode=$mode"; ?>" class="show document_id cm_statement_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('statement_num', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $cm_statement_header->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_text_field_dr('status') ?></li>
			<li><?php $f->l_text_field_d('description') ?></li>
			<li><?php $f->l_date_fieldAnyDay('statement_date', $$class->statement_date) ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
			<li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('opening_balance', $$class->opening_balance, '15', 'opening_balance'); ?></li>
      <li><?php $f->l_number_field('closing_balance', $$class->closing_balance, '15', 'closing_balance'); ?></li>
      <li><?php $f->l_number_field('receipt', $$class->receipt, '15', 'receipt'); ?></li>
      <li><?php $f->l_number_field('payments', $$class->payments, '15', 'payments'); ?></li>
     </ul>
    </div>
		<div id="tabsHeader-3" class="tabContent">
		 <div id="comments">
			<div id="comment_list">
					<?php echo!(empty($comments)) ? $comments : ""; ?>
			</div>
			<div id ="display_comment_form">
					<?php
					$reference_table = 'cm_statement_header';
					$reference_id = $$class->cm_statement_header_id;
					?>
			</div>
			<div id="new_comment">
			</div>
		 </div>
		</div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Statement Lines') ?></span>
 <form method="post" id="so_site"  name="cm_statement_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Price') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Dates') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Org') ?></th>
        
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Line Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($cm_statement_line_object as $cm_statement_line) {
					 ?>         
 			 <tr class="cm_statement_line<?php echo $count ?>">
 				<td>
						 <?php
						 echo ino_inline_action($cm_statement_line->cm_statement_line_id, array('cm_statement_header_id' => $cm_statement_header->cm_statement_header_id,
								 'tax_code_value' => $$class_second->tax_code_value));
						 ?>
 				</td>
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php form::text_field_wid2sr('cm_statement_line_id', 'line_id always_readonly'); ?></td>
 				<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
				<td><?php echo $f->select_field_from_array('line_type', cm_statement_line::$line_type_a, $$class_second->line_type ); ?></td>
 				<td><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->shipping_org_id, '', '', 1, $readonly); ?></td>
 				<td><?php $f->text_field_wid2('item_description'); ?></td>
 				<td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
 				<td><?php form::number_field_wid2s('line_quantity'); ?></td>
 				<td><?php $f->text_field_wid2r('line_status'); ?></td>
 			 </tr>
				<?php
				$count = $count + 1;
			 }
			 ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Price List') ?></th>
        <th><?php echo gettext('Price Date') ?></th>
        <th><?php echo gettext('Unit Price') ?>#</th>
        <th><?php echo gettext('Line Price') ?>#</th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('Tax Amount') ?></th>
        <th><?php echo gettext('GL Line Price') ?></th>
        <th><?php echo gettext('GL Tax Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($cm_statement_line_object as $cm_statement_line) {
					 if ((empty($cm_statement_line->price_list_header_id)) && !empty($document_type_i->price_list_header_id)) {
						$cm_statement_line->price_list_header_id = $document_type_i->price_list_header_id;
						$cm_statement_line->price_date = empty($cm_statement_line->price_date) ? current_time(true) : $cm_statement_line->price_date;
					 }
					 ?>         
 			 <tr class="cm_statement_line<?php echo $count ?>">
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
 				</td>
 				<td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date) ?></td>
 				<td><?php form::number_field_wid2('unit_price'); ?></td>
 				<td><?php form::number_field_wid2('line_price'); ?></td>
 				<td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_inv_org_id($$class_second->shipping_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium') ?></td>
 				<td><?php form::number_field_wid2('tax_amount'); ?></td>
 				<td><?php form::number_field_wid2sr('gl_line_price'); ?></td>
 				<td><?php form::number_field_wid2sr('gl_tax_amount'); ?></td>
 			 </tr>
				<?php
				$count = $count + 1;
			 }
			 ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-3" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Requested Date') ?></th>
        <th><?php echo gettext('Promise Date') ?></th>
        <th><?php echo gettext('Schedule Ship / Receipt Date') ?>#</th>
        <th><?php echo gettext('Actual Ship / Receipt Date') ?>#</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($cm_statement_line_object as $cm_statement_line) {
					 ?>         
 			 <tr class="cm_statement_line<?php echo $count ?>">
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php echo $f->date_field('requested_date', ($$class_second->requested_date), '', '', 'dateFromToday'); ?></td>
 				<td><?php echo $f->date_fieldFromToday('promise_date', $$class_second->promise_date) ?></td>
 				<td><?php echo $f->date_field('schedule_ship_date', ($$class_second->schedule_ship_date), '', '', 'dateFromToday copyValue'); ?></td>
 				<td><?php echo $f->date_fieldFromToday('actual_ship_date', $$class_second->actual_ship_date, 'always_readonly') ?></td>
 			 </tr>
				<?php
				$count = $count + 1;
			 }
			 ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="cm_statement_header" ></li>
  <li class="lineClassName" data-lineClassName="cm_statement_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="cm_statement_header_id" ></li>
  <li class="form_header_id" data-form_header_id="cm_statement_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="cm_statement_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="cm_statement_header_id" ></li>
  <li class="docLineId" data-docLineId="cm_statement_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="cm_statement_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>