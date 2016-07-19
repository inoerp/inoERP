
<div class="row small-left-padding">
<div id="form_all">
 <form  method="post" id="fa_depreciation_method"  name="fa_depreciation_method">
  <span class="heading"><?php echo gettext('Depreciation Method') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('fa_depreciation_method_id'); ?>
         <a name="show" href="form.php?class_name=fa_depreciation_method&<?php echo "mode=$mode"; ?>" class="show document_id fa_depreciation_method_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_d('depreciation_method'); ?> </li>
        <li><?php $f->l_select_field_from_array('method_type', fa_depreciation_method::$method_type_a, $$class->method_type, 'method_type', '', 1, $readonly1); ?></li>
        <li><?php $f->l_select_field_from_array('calculation_basis', fa_depreciation_method::$calculation_basis_a, $$class->calculation_basis, 'calculation_basis', '', 1, $readonly1); ?></li>
        <li><?php $f->l_text_field_dm('description'); ?></li>
        <li><?php $f->l_text_field_dm('life_month'); ?> </li>
        <li><?php $f->l_number_field('reducing_balance_rate', $$class->reducing_balance_rate); ?> </li>
        <li><?php $f->l_select_field_from_array('status', fa_depreciation_method::$status_a, $$class->status, 'status', '', 1, 1, 1); ?> </li>
        <li><?php $f->l_checkBox_field_d('validate_cb'); ?> </li>
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
         $reference_table = 'fa_depreciation_method';
         $reference_id = $$class->fa_depreciation_method_id;
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
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Depreciation Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Rates') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Calculation') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="fa_depreciation_method_rate_line"  name="fa_depreciation_method_rate_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Year') ?></th>
         <th><?php echo gettext('Period') ?></th>
         <th><?php echo gettext('Rate Percentage') ?></th>
         <th><?php echo gettext('Description') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody fa_depreciation_method_rate_values" >
        <?php
        $count = 0;
        $fa_depreciation_method_rate_object_ai = new ArrayIterator($fa_depreciation_method_rate_object);
        $fa_depreciation_method_rate_object_ai->seek($position);
        while ($fa_depreciation_method_rate_object_ai->valid()) {
         $fa_depreciation_method_rate = $fa_depreciation_method_rate_object_ai->current();
         ?>         
         <tr class="fa_depreciation_method_rate<?php echo $count ?>">
          <td><?php
           echo ino_inline_action($$class->fa_depreciation_method_id, 
            array('fa_depreciation_method_rate_id' => $fa_depreciation_method_rate->fa_depreciation_method_rate_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('fa_depreciation_method_rate_id'); ?></td>
          <td><?php form::number_field_wid2('year'); ?></td>
          <td><?php form::number_field_wid2('period'); ?></td>
          <td><?php form::number_field_wid2('rate'); ?></td>
          <td><?php form::number_field_wid2('description'); ?></td>
         </tr>
         <?php
         $fa_depreciation_method_rate_object_ai->next();
         if ($fa_depreciation_method_rate_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">

     </div>
    </form>
   </div>

  </div>
 </div> 
</div>
</div>

<div class="row small-top-margin" >
<div id="pagination" >
 <?php echo $pagination->show_pagination(); ?>
</div>
 </div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_depreciation_method" ></li>
  <li class="lineClassName" data-lineClassName="fa_depreciation_method_rate" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_depreciation_method_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_depreciation_method" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fa_depreciation_method_rate" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_depreciation_method_id" ></li>
  <li class="docLineId" data-docLineId="fa_depreciation_method_rate_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_depreciation_method" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_depreciation_method_rate" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>