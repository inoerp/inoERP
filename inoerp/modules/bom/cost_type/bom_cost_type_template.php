<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<form method="post" id="bom_cost_type"  name="bom_cost_type">
 <span class="heading"><?php echo gettext('Cost Type Header') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field two_column_form"> 
      <li><?php $f->l_text_field_dr_withSearch('bom_cost_type_id'); ?>
       <a name="show" href="form.php?class_name=bom_cost_type&<?php echo "mode=$mode"; ?>" class="show document_id bom_cost_type_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly); ?></li>
      <li><?php $f->l_text_field('cost_type_code', $$class->cost_type_code, '12', '', '', 1, $readonly1); ?></li>     
      <li><?php $f->l_text_field_d('cost_type'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_checkBox_field_d('multi_org_cb'); ?>      </li>
      <li><?php $f->l_select_field_from_object('default_cost_type', bom_cost_type::find_all(), 'bom_cost_type_id', 'cost_type', $$class->default_cost_type, 'default_cost_type', '', '', $readonly); ?>      </li>

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
        $reference_table = 'org';
        $reference_id = $$class->org_id;
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


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_cost_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_cost_type_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_cost_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_cost_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_cost_type" ></li>
 </ul>
</div>