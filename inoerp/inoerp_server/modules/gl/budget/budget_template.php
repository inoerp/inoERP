<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->


<div id ="form_header">
 <form method="post" id="gl_budget"  name="gl_budget">
  <span class="heading"><?php echo gettext('GL Budget') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_dr_withSearch('gl_budget_id') ?>
        <a name="show" href="form.php?class_name=gl_budget&<?php echo "mode=$mode"; ?>" class="show document_id gl_budget_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('budget_name'); ?> 					</li>
			 <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', '', $readonly1, 1); ?>             </li>
			 <li><?php $f->l_select_field_from_array('status', gl_budget::$status_a, $$class->status, 'status', '', 1); ?>         </li> 
			 <li><?php $f->l_date_fieldAnyDay_r('created_on', $$class->created_on, 'always_readonly') ?></li>
			 <li><?php $f->l_date_fieldAnyDay_r('frozen_date', $$class->created_on, 'always_readonly') ?></li>
			 <li><label><?php echo gettext('First Period') ?></label><?php
					 if (!empty($period_name_stmt)) {
						echo $period_name_stmt;
					 } else {
						$f->text_field_d('first_period_id');
					 }
					 ?>
			 </li>
			 <li><label><?php echo gettext('Current Period') ?></label><?php
					 if (!empty($period_name_stmt)) {
						echo $period_name_stmt;
					 } else {
						$f->text_field_d('first_period_id');
					 }
					 ?>
			 </li>

       <li><?php $f->l_text_field_d('description'); ?> 					</li>
			 <li><label><?php echo gettext('Freeze Budget') ; ?></label><?php echo $f->checkBox_field('freeze_cb', ''); ?> 					</li>
      </ul>
     </div>

     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
						<?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
						<?php
						$reference_table = 'gl_budget';
						$reference_id = $$class->gl_budget_id;
						?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="gl_budget" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="gl_budget_id" ></li>
  <li class="form_header_id" data-form_header_id="gl_budget" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="gl_budget_id" ></li>
  <li class="btn1DivId" data-btn1DivId="gl_budget" ></li>
 </ul>
</div>