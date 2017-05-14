<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('WIP Accounting Group') ?></span>
 <form method="post" id="wip_accounting_group"  name="wip_accounting_group">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('wip_accounting_group_id'); ?>
        <a name="show" href="form.php?class_name=wip_accounting_group&<?php echo "mode=$mode"; ?>" class="show document_id wip_accounting_group_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>    </li>
       <li><?php $f->l_text_field_d('wip_accounting_group'); ?></li>
       <li><?php $f->l_select_field_from_object('wo_type', wip_wo_header::wip_wo_type(), 'option_line_code', 'option_line_value', $$class->wo_type, 'wo_type', $readonly, 'wo_type'); ?>    </li>
       <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
       <li><?php $f->l_text_field_d('rev_number'); ?>    </li>
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
        $reference_table = 'wip_accounting_group';
        $reference_id = $$class->wip_accounting_group_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>

  <div id ="form_line" class="form_line">
   <span class="heading"><?php echo gettext('Accounting Group Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Actual Accounts') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Variance Accounts') ?></a></li>
    </ul>
    <div class="tabContainer">

     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field two_column_form"> 
        <li><?php $f->l_ac_field_d('material_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('material_oh_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('overhead_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('resource_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('osp_ac_id'); ?></li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2" class="tabContent">
      <div> 
       <ul class="column header_field two_column_form">
        <li><?php $f->l_ac_field_d('var_material_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('var_material_oh_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('var_overhead_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('var_resource_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('var_osp_ac_id'); ?></li>
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
  <li class="headerClassName" data-headerClassName="wip_accounting_group" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_accounting_group_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_accounting_group" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="wip_accounting_group_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_accounting_group" ></li>
 </ul>
</div>