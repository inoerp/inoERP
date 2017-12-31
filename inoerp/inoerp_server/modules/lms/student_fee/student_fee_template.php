<div class="row small-left-padding">
 <div id="form_all">
	<div id="form_headerDiv">
	 <form  method="post" id="lms_student_fee_line"  name="student_fee_line">
		<span class="heading"><?php echo gettext('Student Fees') ?></span>
		<div id="form_serach_header form_header " >
     <ul class="inRow asperWidth tabContent tabContainer form-single-row">
			<li><label><?php echo gettext('Student Name') ?></label><?php
			  	echo $f->val_field('employee_name', $$class->employee_name, '', '', 'vf_select_member_employee_name', '', '', 'hr_employee_v', 'employee_name');
					echo $f->hidden_field_withCLass('hr_employee_id', $$class->hr_employee_id, 'employee_id');
					?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i>
			 <a name="show" href="form.php?class_name=hr_leave_balance&<?php echo "mode=$mode"; ?>" class="show document_id employee_id">
        <i class="fa fa-refresh"></i></a></li>
     </ul>
		</div>
		<div id ="form_line" class="lms_student_fee"><span class="heading">Tax Details </span>
		 <div id="tabsLine">
			<ul class="tabMain">
			 <li><a href="#tabsLine-1"><?php echo gettext('Tax Code') ?></a></li>
			 <li><a href="#tabsLine-2"><?php echo gettext('Reporting') ?></a></li>
			</ul>
			<div class="tabContainer"> 
			 <div id="tabsLine-1" class="tabContent">
				<table class="form_table">
				 <thead> 
					<tr>
					 <th><?php echo gettext('Action') ?></th>
					 <th><?php echo gettext('Seq') ?>#</th>
					 <th><?php echo gettext('Id') ?></th>
					 <th><?php echo gettext('Fee Structure') ?></th>
					 <th><?php echo gettext('Currency') ?></th>
					 <th><?php echo gettext('Amout') ?></th>
					 <th><?php echo gettext('Description') ?></th>
					 <th><?php echo gettext('Tax Amount') ?></th>
					 <th><?php echo gettext('Paid Amount') ?></th>
					 <th><?php echo gettext('Status') ?></th>
					 <th><?php echo gettext('Invoice Status') ?></th>
					</tr>
				 </thead>
				 <tbody class="form_data_line_tbody student_fee_values" >
						 <?php
						 $f = new inoform();
						 $count = 0;
						 $student_fee_object_ai = new ArrayIterator($student_fee_object );
						 $student_fee_object_ai->seek($position);
						 while ($student_fee_object_ai->valid()) {
							$lms_student_fee = $student_fee_object_ai->current();
							?>         
 					<tr class="lms_student_fee<?php echo $count ?>">
 					 <td><?php
								echo ino_inline_action($$class->lms_student_fee_id, array('lms_student_id' => $lms_student_id_h));
								?>    
 					 </td>
 					 <td><?php $f->seq_field_d($count) ?></td>
 					 <td><?php form::number_field_drs('lms_student_fee_id') ?></td>
 					 <td><?php echo form::select_field_from_object('lms_fee_struct_header_id', lms_fee_struct_header::find_all(), 'lms_fee_struct_header_id', 'struct_name', $$class->lms_fee_struct_header_id, '', $readonly); ?></td>
 					 <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, '', 'doc_currency', 1, $readonly); ?></td>
 					 <td><?php echo $f->number_field('amount', $$class->amount) ?></td>
 					 <td><?php $f->text_field_wid('description') ?></td>
 					 <td><?php echo $f->number_field('tax_amount', $$class->tax_amount , '', '' ,'small'); ?></td>
 					 <td><?php echo $f->number_field('paid_amount', $$class->paid_amount, '', '' ,'small'); ?></td>
 					 <td><?php $f->text_field_wids('status') ?></td>
 					 <td><?php $f->text_field_wids('invoice_status') ?></td>
 					</tr>
					 <?php
					 $student_fee_object_ai->next();
					 if ($student_fee_object_ai->key() == $position + $per_page) {
						break;
					 }
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
					 <th><?php echo gettext('Start Date') ?></th>
					 <th><?php echo gettext('End Date') ?>#</th>
					 <th><?php echo gettext('Transaction Id') ?>#</th>
					 <th><?php echo gettext('Receipt Id') ?></th>
					 <th><?php echo gettext('Receipt Status') ?></th>
					 <th><?php echo gettext('Tax Status') ?></th>
					</tr>
				 </thead>
				 <tbody class="form_data_line_tbody student_fee_values" >
						 <?php
						 $count = 0;
						 $student_fee_object_ai = new ArrayIterator($student_fee_object);
						 $student_fee_object_ai->seek($position);
						 while ($student_fee_object_ai->valid()) {
							$lms_student_fee = $student_fee_object_ai->current();
							?>         
 					<tr class="lms_student_fee<?php echo $count ?>">
 					 <td><?php $f->seq_field_d($count) ?></td>
 					 <td><?php echo $f->date_fieldAnyDay('effective_start_date', $$class->effective_start_date) ?></td>
 					 <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class->effective_end_date) ?></td>
 					 <td><?php $f->text_field_widr('ar_transaction_header_id') ?></td>
 					 <td><?php $f->text_field_widr('ar_receipt_header_id') ?></td>
 					 <td><?php $f->text_field_widr('receipt_status'); ?></td>
 					 <td><?php $f->text_field_widr('tax_status'); ?></td>
 					</tr>
					 <?php
					 $student_fee_object_ai->next();
					 if ($student_fee_object_ai->key() == $position + $per_page) {
						break;
					 }
					 $count = $count + 1;
					}
					?>
				 </tbody>
				</table>
			 </div>
			</div>
		 </div>
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
  <li class="lineClassName" data-lineClassName="lms_student_fee" ></li>
  <li class="line_key_field" data-line_key_field="student_fee" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="lms_student_fee" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="lms_student_fee_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="lms_student_fee" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>