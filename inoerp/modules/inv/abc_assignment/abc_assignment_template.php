<div class="row small-left-padding">
 <div id ="form_header"><span class="heading"><?php echo gettext('ABC Assignment Header') ?></span>
  <form method="post" id="inv_abc_assignment_header"  name="inv_abc_assignment_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Assign Items') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('inv_abc_assignment_header_id') ?>
        <a name="show" href="form.php?class_name=inv_abc_assignment_header&<?php echo "mode=$mode"; ?>" class="show document_id inv_abc_assignment_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('abc_assignment_name'); ?></li>
       <li><?php
        echo $f->l_val_field_dm('valuation_name', 'inv_abc_valuation', 'valuation_name', '', 'vf_select_supplier_name');
        echo $f->hidden_field_withId('inv_abc_valuation_id', $$class->inv_abc_valuation_id);
        ?><i class="generic g_select_valuation_name select_popup clickable fa fa-search" data-class_name="inv_abc_valuation"></i></li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>       </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr('total_no_of_items'); ?></li>
        <li><?php $f->l_text_field_dr('total_value'); ?></li>
        <li><?php $f->l_select_field_from_array('assignment_action', inv_abc_assignment_header::$assignment_action_a, ''); ?></li>
        </ul>
      </div>
      <div id="data_table">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('ABC Class') ?></th>
          <th><?php echo gettext('Sequence Number') ?></th>
          <th><?php echo gettext('Value') ?></th>
          <th><?php echo gettext('% of Items') ?></th>
          <th><?php echo gettext('% of Value') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody inv_abc_assignment_header_values" >
         <?php
         $count = 0;
         $all_abc_codes = inv_abc_assignment_header::inv_abc_codes();
         $no_of_class_codes = count($all_abc_codes);
         foreach ($all_abc_codes as $abc_code) {
          if ($count == $no_of_class_codes - 1) {
           $assign_seq_number_v = $$class->total_no_of_items;
           $assign_value_v = $$class->total_value;
           $assign_item_percentage_v = 100;
           $assign_value_percentage_ = 100;
          } else {
           $assign_seq_number_v = $assign_value_v = $assign_item_percentage_v = $assign_value_percentage_ = null;
          }
          ?>   
          <tr class="inv_abc_assignment_header<?php echo $count ?>">
           <td><?php echo $f->text_field('assign_abc_class_value', $abc_code->option_line_code, '8', '', '', '', 1); ?></td>
           <td><?php echo $f->text_field('assign_seq_number', $assign_seq_number_v); ?></td>
           <td><?php echo $f->text_field('assign_value', $assign_value_v, '30'); ?></td>
           <td><?php echo $f->text_field('assign_item_percentage', $assign_item_percentage_v, 30); ?></td>
           <td><?php echo $f->text_field('assign_value_percentage', $assign_value_percentage_, 30); ?></td>
          </tr>
          <?php
          $count++;
         }
         ?>
        </tbody>
       </table>
      </div>
     </div>
    </div>
   </div>
  </form>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('View & Update Items') ?> </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Item ABC Class') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="inv_abc_assignment_line_line"  name="inv_abc_assignment_line_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Master Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('ABC Class') ?></th>
         <th><?php echo gettext('Comments') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody inv_abc_assignment_line_values" >
        <?php
        $count = 0;
        $inv_abc_assignment_line_object_ai = new ArrayIterator($inv_abc_assignment_line_object);
        $inv_abc_assignment_line_object_ai->seek($position);
        while ($inv_abc_assignment_line_object_ai->valid()) {
         $inv_abc_assignment_line = $inv_abc_assignment_line_object_ai->current();
         ?>         
         <tr class="inv_abc_assignment_line<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->inv_abc_assignment_line_id, array('inv_abc_assignment_header_id' => $$class->inv_abc_assignment_header_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('inv_abc_assignment_line_id', 'always_readonly'); ?></td>
          <td><?php $f->text_field_d2sr('item_id_m'); ?></td>
          <td><?php $f->text_field_wid2('item_number', 'select_item_number');
           ?> <i class="select_item_number select_popup clickable fa fa-search"></i></td>
          <td><?php $f->text_field_wid2l('item_description'); ?></td>
          <td><?php $f->text_field_wid2s('abc_class'); ?></td>
          <td><?php $f->text_field_wid2('description'); ?></td>
         </tr>
         <?php
         $inv_abc_assignment_line_object_ai->next();
         if ($inv_abc_assignment_line_object_ai->key() == $position + $per_page) {
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

<div class="row small-top-margin" >
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_abc_assignment_header" ></li>
  <li class="lineClassName" data-lineClassName="inv_abc_assignment_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_abc_assignment_header_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_abc_assignment_header" ></li>
  <li class="line_key_field" data-line_key_field="code" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_abc_assignment_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_abc_assignment_header_id" ></li>
  <li class="docLineId" data-docLineId="inv_abc_assignment_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_abc_assignment_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>