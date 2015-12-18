<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Non-Labor Resource') ?></span>
 <form  method="post" id="prj_nlr_header"  name="prj_nlr_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_nlr_header_id') ?>
       <a name="show" href="form.php?class_name=prj_nlr_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_nlr_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('resource_name'); ?></li>
      <li><?php $f->l_select_field_from_object('prj_expenditure_type_id', prj_expenditure_type_header::find_all(),'prj_expenditure_type_header_id','expenditure_type',$$class->prj_expenditure_type_id,'prj_expenditure_type_id','',1); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
      <li><?php $f->l_checkBox_field_d('equipment_cb'); ?></li> 
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
        $reference_table = 'prj_nlr_header';
        $reference_id = $$class->prj_nlr_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Org Cost Values') ?></span>
 <form  method="post" id="prj_nlr_line"  name="prj_nlr_line">
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
        <th><?php echo gettext('Org Id') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('From Date') ?></th>
        <th><?php echo gettext('To Date') ?></th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Rate') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_nlr_line_object as $prj_nlr_line) {
        ?>         
        <tr class="prj_nlr_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_nlr_line->prj_nlr_line_id, array('prj_nlr_header_id' => $prj_nlr_header->prj_nlr_header_id));
          ?>
         </td>
         <td><?php $f->text_field_d2sr('prj_nlr_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class_second->bu_org_id); ?>						 </td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_from', $$class_second->effective_from); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_to', $$class_second->effective_to); ?></td>
         <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class_second->currency); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php $f->text_field_d2('rate'); ?></td>
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
  <li class="headerClassName" data-headerClassName="prj_nlr_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_nlr_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_nlr_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_nlr_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_nlr_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_nlr_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_nlr_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_nlr_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>