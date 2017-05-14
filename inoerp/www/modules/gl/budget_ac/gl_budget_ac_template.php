<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<?php $f = new inoform(); ?>
<div id ="form_header"><span class="heading"><?php echo gettext('Budget Account') ?></span>
 <form method="post" id="gl_budget_ac_header"  name="gl_budget_ac_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('gl_budget_ac_header_id') ?>
       <a name="show" href="form.php?class_name=gl_budget_ac_header&<?php echo "mode=$mode"; ?>" class="show document_id gl_budget_ac_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
			<li><?php $f->l_text_field_dm('ac_name'); ?> 					</li>
			<li><?php $f->l_select_field_from_object('gl_ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'gl_ledger_id', '', '', $readonly1, 1); ?>             </li>
			<li><?php $f->l_text_field_d('description'); ?> 					</li>
			<li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
			<li><?php $f->l_date_fieldFromToday('end_date', $$class->end_date) ?></li>
			<li><?php $f->l_select_field_from_object('role_code', role_access::roles(), 'option_line_code', 'option_line_value', $$class->role_code, 'role_code'); ?></li>
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
					 $reference_table = 'gl_budget_ac_header';
					 $reference_id = $$class->gl_budget_ac_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Accounts Assignments') ?></span>
 <form action=""  method="post" id="so_site"  name="gl_budget_ac_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
				<th><?php echo gettext('Account') ?></th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Currency') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($gl_budget_ac_line_object as $gl_budget_ac_line) {
					 ?>         
 			 <tr class="gl_budget_ac_line<?php echo $count ?>">
 				<td><?php echo ino_inline_action($gl_budget_ac_line->gl_budget_ac_line_id, array('gl_budget_ac_header_id' => $gl_budget_ac_header->gl_budget_ac_header_id)); ?></td>
 				<td><?php form::text_field_wid2sr('gl_budget_ac_line_id', 'line_id always_readonly'); ?></td>
 				<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 				<td><?php $f->ac_field_wid2m('ppv_ac_id', 'copyValue large'); ?></td>
 				<td><?php $f->text_field_wid2('type'); ?></td>
 				<td><?php $f->text_field_wid2('description'); ?></td>
 				<td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, '', 'large'); ?></td>
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
  <li class="headerClassName" data-headerClassName="gl_budget_ac_header" ></li>
  <li class="lineClassName" data-lineClassName="gl_budget_ac_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_budget_ac_header_id" ></li>
  <li class="form_header_id" data-form_header_id="gl_budget_ac_header" ></li>
  <li class="line_key_field" data-line_key_field="coa_combination_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_budget_ac_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="gl_budget_ac_header_id" ></li>
  <li class="docLineId" data-docLineId="gl_budget_ac_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="gl_budget_ac_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>