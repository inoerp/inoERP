<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php $f = new inoform(); echo gettext('Cash Management Controls') ?></span>
 <form method="post" id="cm_sys_control"  name="cm_sys_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('cm_sys_control_id', $$class->cm_sys_control_id); ?>
    <li><?php $f->l_select_field_from_object('legal_org_id', org::find_all_legal(), 'legal_org_id', 'org', $$class->legal_org_id, 'legal_org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=cm_sys_control&<?php echo "mode=$mode"; ?>" class="show document_id cm_sys_control_id">
      <i class='fa fa-refresh'></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('System Controls') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future Rules') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field two_column_form"> 
        <li><?php $f->l_checkBox_field_d('show_cleared_trnx_cb'); ?></li>
				<li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?></li>
				<li><?php $f->l_checkBox_field_d('show_void_trnx_cb'); ?></li>
				<li><?php $f->l_checkBox_field_d('allow_lines_cb'); ?></li>
				<li><?php $f->l_checkBox_field_d('archive_cb'); ?></li>
				<li><?php $f->l_checkBox_field_d('purge_cb'); ?></li>
				<li><?php $f->l_date_fieldAnyDay('cf_rate_date', $$class->cf_rate_date); ?></li>
				<li><?php $f->l_date_fieldAnyDay('bank_transfer_rate_date', $$class->bank_transfer_rate_date); ?></li>
        <li><?php  $f->l_text_field_d('exchange_rate_type') ?> </li>
        <li><?php  $f->l_text_field_d('signing_auth_approval') ?> </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column five_column"> 

       </ul> 
      </div> 
     </div>
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="cm_sys_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="legal_org_id" ></li>
  <li class="form_header_id" data-form_header_id="cm_sys_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="cm_sys_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="cm_sys_control_id" ></li>
 </ul>
</div>