<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php   echo gettext('Service Activity')   ?></span>
 <form action=""  method="post" id="hd_service_activity_header"  name="hd_service_activity_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Billing Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hd_service_activity_header_id') ?>
       <a name="show" href="form.php?class_name=hd_service_activity_header&<?php echo "mode=$mode"; ?>" class="show document_id hd_service_activity_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('activity_name'); ?></li>
      <li><?php $f->l_text_field_d('activity_description'); ?></li>
      <li><?php $f->l_select_field_from_array('line_category', hd_service_activity_header::$line_category_a, $$class->line_category, 'line_category'); ?>						 </li>
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
      <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date) ?></li>
      <li><?php $f->l_checkBox_field_d('allow_quantity_update_cb'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_checkBox_field_d('create_charge_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('create_cost_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('zero_charge_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('expense_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('labor_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('material_cb'); ?></li>
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
        $reference_table = 'hd_service_activity_header';
        $reference_id = $$class->hd_service_activity_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Service Activity Lines') ?></span>
 <form action=""  method="post" id="hd_service_activity_line"  name="hd_service_activity_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Order Type') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Business Org') ?></th>
        <th><?php echo gettext('Header Type') ?></th>
        <th><?php echo gettext('Line Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_activity_line_object as $hd_service_activity_line) {
        ?>         
        <tr class="hd_service_activity_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($hd_service_activity_line->hd_service_activity_line_id, array('hd_service_activity_header_id' => $$class->hd_service_activity_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_service_activity_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class_second->bu_org_id, '', 'large', 1); ?>						 </td>
         <td><?php echo $f->select_field_from_object('header_type_id', sd_document_type::find_all_header_levels(), 'sd_document_type_id', 'document_type_name', $$class_second->header_type_id, '', 'large', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('line_type_id', sd_document_type::find_all_line_levels(), 'sd_document_type_id', 'document_type_name', $$class_second->line_type_id, '', 'large', 1, $readonly); ?></td>
         <td><?php $f->text_field_wid2('description' , 'xlarge'); ?></td>
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
  <li class="headerClassName" data-headerClassName="hd_service_activity_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_service_activity_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_service_activity_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_service_activity_header" ></li>
  <li class="line_key_field" data-line_key_field="header_type_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hd_service_activity_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_service_activity_header_id" ></li>
  <li class="docLineId" data-docLineId="hd_service_activity_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_service_activity_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>