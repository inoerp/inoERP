<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php
   echo gettext('Collection Elements')
  ?></span>
 <form  method="post" id="qa_ce_header"  name="qa_ce_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Controls') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('qa_ce_header_id') ?>
       <a name="show" href="form.php?class_name=qa_ce_header&<?php echo "mode=$mode"; ?>" class="show document_id qa_ce_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('element_name'); ?> </li>
      <li><?php $f->l_text_field_dr('sys_element_name'); ?></li>
      <li><?php $f->l_select_field_from_object('element_type', option_header::find_options_byName('QA_ELEMENT_TYPE'), 'option_line_code', 'option_line_value', $$class->element_type, 'element_type', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_select_field_from_object('data_type', option_header::find_options_byName('SYS_EXTRA_FIELD_TYPE'), 'option_line_code', 'option_line_value', $$class->data_type, 'data_type', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_number_field('data_length', $$class->data_length, '', 'data_length'); ?>          </li>
      <li><?php $f->l_select_field_from_array('display_type', qa_ce_header::$display_type_a, $$class->display_type); ?>       </li>
      <li><?php $f->l_checkBox_field_d('active_cb', $$class->active_cb); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
     </ul> 
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('element_label'); ?> </li>
      <li><?php $f->l_text_field_d('hint'); ?></li>
      <li><?php $f->l_number_field('decimal_position', $$class->decimal_position, '', 'decimal_position'); ?>          </li>
      <li><?php $f->l_text_field_d('default_value'); ?></li>
      <li><?php $f->l_text_field_d('target_value'); ?></li>
      <li><?php $f->l_select_field_from_object('option_header_id', option_header::find_all(), 'option_header_id', 'option_type', $$class->option_header_id, 'option_header_id', '', '', $readonly1); ?>        </li>
      <div class="panel panel-collapse panel-ino-classy extra_large_box">
       <div class="panel-heading"><div class="panel-title font-medium"><?php echo gettext('Specification Limits') ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('user_range_low'); ?></li>
         <li><?php $f->l_text_field_d('user_range_high'); ?></li>
         <li><?php $f->l_text_field_d('specification_range_high'); ?></li>
         <li><?php $f->l_text_field_d('specification_range_low'); ?></li>
         <li><?php $f->l_text_field_d('reasonable_range_high'); ?></li>
         <li><?php $f->l_text_field_d('reasonable_range_low'); ?></li>
        </ul>
       </div>
      </div>
     </ul> 
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'qa_ce_header';
        $reference_id = $$class->qa_ce_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
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

<span class="heading"><?php echo gettext('Element Type Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Values') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Actions') ?></a></li>
 </ul>
 <div class="tabContainer">
  <form action=""  method="post" id="qa_ce_line"  name="qa_ce_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Element Value') ?>#</th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('End Date') ?>?</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($qa_ce_line_object as $qa_ce_line) {
        if (!empty($$class_second->prj_category_header_id)) {
         $$class_second->category_description = prj_category_header::find_by_id($$class_second->prj_category_header_id)->description;
        }
        ?>         
        <tr class="qa_ce_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($qa_ce_line->qa_ce_line_id, array('qa_ce_header_id' => $qa_ce_header->qa_ce_header_id));
          ?>
         </td>

         <td><?php echo form::text_field_wid2sr('qa_ce_line_id'); ?></td>
         <td><?php $f->text_field_wid2('element_value'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php echo $f->date_field('end_date', $$class_second->end_date); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form action=""  method="post" id="qa_ce_action"  name="qa_ce_action">
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Action Id') ?></th>
        <th><?php echo gettext('Condition') ?></th>
        <th><?php echo gettext('Comparison') ?></th>
        <th><?php echo gettext('Value From') ?></th>
        <th><?php echo gettext('Value To') ?></th>
        <th><?php echo gettext('Spec Value') ?></th>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($qa_ce_action_object as $qa_ce_action) {
        ?>         
        <tr class="qa_ce_action<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($qa_ce_action->qa_ce_action_id); ?>"></li>           
           <li><?php echo form::hidden_field('qa_ce_header_id', $$class->qa_ce_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('qa_ce_action_id'); ?></td>
         <td><?php echo $f->select_field_from_array('action_condition' , dbObject::$control_type_a, $$class_third->action_condition ,'' ,'medium'); ?></td>
         <td><?php echo $f->select_field_from_array('comparison' , qa_ce_action::$comparison_a, $$class_third->comparison ,'' ,'medium'); ?></td>
         <td><?php echo $f->text_field_wid3('value_from'); ?></td>
         <td><?php echo $f->text_field_wid3('value_to'); ?></td>
         <td><?php echo $f->select_field_from_array('spec_value' , qa_ce_action::$spec_value_a, $$class_third->spec_value ,'' ,'medium'); ?></td>
         <td><?php echo $f->select_field_from_object('quality_action', option_header::find_options_byName('QA_QUALITY_ACTION'), 'option_line_code', 'option_line_value', $$class_third->quality_action) ;  ?></td>
         <td><?php echo $f->text_field_wid3('description'); ?></td>
          </tr>
        <?php
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="qa_ce_header" ></li>
  <li class="lineClassName" data-lineClassName="qa_ce_line" ></li>
  <li class="lineClassName2" data-lineClassName2="qa_ce_action" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="qa_ce_header_id" ></li>
  <li class="form_header_id" data-form_header_id="qa_ce_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="qa_ce_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="qa_ce_header_id" ></li>
  <li class="docLineId" data-docLineId="qa_ce_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="qa_ce_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
