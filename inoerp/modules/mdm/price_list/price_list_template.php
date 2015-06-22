<div class="row small-left-padding">
 <div id="form_all">
  <form action=""  method="post" id="mdm_price_list_header"  name="mdm_price_list_header">
   <span class="heading"><?php echo gettext('Price List') ?></span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Other') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
      <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('mdm_price_list_header_id'); ?>
         <a name="show" href="form.php?class_name=mdm_price_list_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_price_list_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_dm('price_list'); ?> </li>
        <li><?php $f->l_select_field_from_array('module_name', mdm_price_list_header::$module_a, $$class->module_name, 'module_name', '', '', $readonly); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_object('currency_code', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency_code, 'currency_code', $readonly, '', '', 1); ?> </li>
       </ul>
      </div>
      <div id="tabsHeader-2" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li><?php $f->l_status_field_d('status'); ?></li>
         <li><?php $f->l_checkBox_field_d('allow_mutli_currency_cb'); ?></li>
         <li><?php $f->l_select_field_from_object('currency_conversion_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->currency_conversion_type, 'currency_conversion_type', '', 1, $readonly); ?></li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <div> 
        <div id="comments">
         <div id="comment_list">
          <?php echo!(empty($comments)) ? $comments : ""; ?>
         </div>
         <div id ="display_comment_form">
          <?php
          $reference_table = 'mdm_price_list_header';
          $reference_id = $$class->mdm_price_list_header_id;
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
  <div id ="form_line" class="form_line"><span class="heading">Price List Lines </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Values') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Prices') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Restrictions') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <form action=""  method="post" id="mdm_price_list_line_line"  name="mdm_price_list_line_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Type') ?></th>
          <th><?php echo gettext('Item') ?></th>
          <th><?php echo gettext('Description') ?></th>
          <th><?php echo gettext('UOM') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody mdm_price_list_line_values" >
         <?php
         $count = 0;
         $mdm_price_list_line_object_ai = new ArrayIterator($mdm_price_list_line_object);
         $mdm_price_list_line_object_ai->seek($position);
         while ($mdm_price_list_line_object_ai->valid()) {
          $mdm_price_list_line = $mdm_price_list_line_object_ai->current();
          ?>         
          <tr class="mdm_price_list_line<?php echo $count ?>">
           <td><?php
            echo ino_inline_action($$class_second->mdm_price_list_line_id, array('mdm_price_list_header_id' => $$class->mdm_price_list_header_id));
            ?>    
           </td>
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php form::number_field_wid2sr('mdm_price_list_line_id'); ?></td>
           <td><?php echo $f->select_field_from_array('line_type', mdm_price_list_line::$line_type_a, $$class_second->line_type); ?></td>
           <td><?php
            echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
            form::text_field_wid2('item_number', 'select_item_number');
            ?>
            <i class="select_item_number select_popup clickable fa fa-search"></i></td>
           <td><?php form::text_field_wid2('item_description'); ?></td>
           <td><?php
            echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
            ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
          </tr>
          <?php
          $mdm_price_list_line_object_ai->next();
          if ($mdm_price_list_line_object_ai->key() == $position + $per_page) {
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
          <th><?php echo gettext('Unit Price') ?></th>
          <th><?php echo gettext('Formula') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody mdm_price_list_line_values" >
         <?php
         $count = 0;
         $mdm_price_list_line_object_ai = new ArrayIterator($mdm_price_list_line_object);
         $mdm_price_list_line_object_ai->seek($position);
         while ($mdm_price_list_line_object_ai->valid()) {
          $mdm_price_list_line = $mdm_price_list_line_object_ai->current();
          ?>         
          <tr class="mdm_price_list_line<?php echo $count ?>">
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php $f->text_field_wid2('unit_price'); ?></td>
           <td><?php $f->text_field_wid2('formula'); ?></td>
          </tr>
          <?php
          $mdm_price_list_line_object_ai->next();
          if ($mdm_price_list_line_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-3" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Inventory Org') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody mdm_price_list_line_values" >
         <?php
         $count = 0;
         $mdm_price_list_line_object_ai = new ArrayIterator($mdm_price_list_line_object);
         $mdm_price_list_line_object_ai->seek($position);
         while ($mdm_price_list_line_object_ai->valid()) {
          $mdm_price_list_line = $mdm_price_list_line_object_ai->current();
          ?>         
          <tr class="mdm_price_list_line<?php echo $count ?>">
           <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->org_id, '', '', '', $readonly); ?></td>
          </tr>
          <?php
          $mdm_price_list_line_object_ai->next();
          if ($mdm_price_list_line_object_ai->key() == $position + $per_page) {
           break;
          }
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
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="mdm_price_list_header" ></li>
  <li class="lineClassName" data-lineClassName="mdm_price_list_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="mdm_price_list_header_id" ></li>
  <li class="form_header_id" data-form_header_id="mdm_price_list_header" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="mdm_price_list_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="mdm_price_list_header_id" ></li>
  <li class="docLineId" data-docLineId="mdm_price_list_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="mdm_price_list_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="mdm_price_list_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>