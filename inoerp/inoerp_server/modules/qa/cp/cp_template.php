<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Collection Plan') ?></span>
 <form method="post" id="qa_cp_header"  name="qa_cp_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('qa_cp_header_id') ?>
       <a name="show" href="form.php?class_name=qa_cp_header&<?php echo "mode=$mode"; ?>" class="show document_id qa_cp_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li> <?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>  </li>
      <li><?php $f->l_text_field_dm('plan_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
      <li><?php $f->l_select_field_from_object('plan_type', option_header::find_options_byName('QA_COLLECTION_PLAN_TYPE'), 'option_line_code', 'option_line_value', $$class->plan_type, 'plan_type'); ?></li> 
      <li><?php $f->l_select_field_from_object('qa_specification_header_id', qa_specification_header::find_all(), 'qa_specification_header_id', 'specification_name', $$class->plan_type, 'qa_specification_header_id'); ?></li> 
      <li><?php $f->l_select_field_from_array('specification_type', qa_specification_header::$specification_type_a, $$class->specification_type, 'specification_type'); ?></li> 
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
        $reference_table = 'qa_cp_header';
        $reference_id = $$class->qa_cp_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Collection Plan Elements') ?></span>
 <form  method="post" id="qa_cp_line"  name="qa_cp_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Element') ?>#</th>
        <th><?php echo gettext('Prompt') ?></th>
        <th><?php echo gettext('Enabled') ?></th>
        <th><?php echo gettext('Mandatory') ?></th>
        <th><?php echo gettext('Readonly') ?></th>
        <th><?php echo gettext('Displayed') ?></th>
        <th><?php echo gettext('Information Only') ?></th>
        <th><?php echo gettext('Default') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($qa_cp_line_object as $qa_cp_line) {
        ?>         
        <tr class="qa_cp_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($qa_cp_line->qa_cp_line_id, array('qa_cp_header_id' => $qa_cp_header->qa_cp_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('qa_cp_line_id', 'always_readonly dontCopy line_id'); ?></td>
         <td><?php echo $f->number_field('sequence', $$class_second->sequence); ?></td>
         <td><?php echo $f->select_field_from_object('qa_ce_header_id', qa_ce_header::find_all(), 'qa_ce_header_id', 'element_name', $$class_second->qa_ce_header_id); ?></td>
         <td><?php $f->text_field_wid2('prompt'); ?></td>
         <td><?php $f->checkBox_field_wid2('enabled_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('mandatory_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('readonly_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('displayed_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('information_cb'); ?></td>
         <td><?php $f->text_field_wid2('dafault_value'); ?></td>
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
  <li class="headerClassName" data-headerClassName="qa_cp_header" ></li>
  <li class="lineClassName" data-lineClassName="qa_cp_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="qa_cp_header_id" ></li>
  <li class="form_header_id" data-form_header_id="qa_cp_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="qa_cp_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="qa_cp_header_id" ></li>
  <li class="docLineId" data-docLineId="qa_cp_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="qa_cp_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>