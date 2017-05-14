<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form method="post" id="inv_item_relation_line"  name="item_relation_line">
    <span class="heading"><?php      echo gettext('Item Relationships')   ?></span>
    <div id="form_serach_header" class="tabContainer">
     <label><?php echo gettext('Relationship Type') ?></label>
     <?php echo $f->select_field_from_object('relation_type_h', inv_item_relation::item_relation(), 'option_line_code', 'option_line_value', $relation_type_h, 'relation_type' ,'medium action'); ?>
     <a name="show2" href="form.php?class_name=inv_item_relation&<?php echo "mode=$mode"; ?>" class="show2 document_id relation_type">
      <i class="fa fa-refresh"></i></a> 
    </div>
    <div id ="form_line" class="inv_item_relation"><span class="heading"><?php echo gettext('Relationship Details') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('From Item') ?></th>
           <th><?php echo gettext('Relationship Type') ?></th>
           <th><?php echo gettext('To Item') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('From Date') ?></th>
           <th><?php echo gettext('To Date') ?></th>
           <th><?php echo gettext('Status') ?></th>
           <th><?php echo gettext('Planned') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody item_relation_values" >
          <?php
          $count = 0;
          $item_relation_object_ai = new ArrayIterator($item_relation_object);
          $item_relation_object_ai->seek($position);
          while ($item_relation_object_ai->valid()) {
           $inv_item_relation = $item_relation_object_ai->current();
           if (!empty($$class->from_item_id_m)) {
            $from_item_i = item::find_by_item_id_m($$class->from_item_id_m);
            if ($from_item_i) {
             $$class->from_item_number = $from_item_i->item_number;
            } else {
             $$class->from_item_number = null;
            }
           } else {
            $$class->from_item_number = null;
           }

           if (!empty($$class->to_item_id_m)) {
            $to_item_i = item::find_by_item_id_m($$class->to_item_id_m);
            if ($to_item_i) {
             $$class->to_item_number = $to_item_i->item_number;
            } else {
             $$class->to_item_number = null;
            }
           } else {
            $$class->to_item_number = null;
           }
           if(empty($$class->inv_item_relation_id)){
            $$class->relation_type = $relation_type_h;
           }
           ?>         
           <tr class="inv_item_relation<?php echo $count ?>">
            <td><?php 
             echo ino_inline_action($$class->inv_item_relation_id, array('relation_type_h' => $relation_type_h));
             ?>    
            </td>
            <td><?php form::number_field_drs('inv_item_relation_id' , 'always_readonly') ?></td>
            <td><?php
             echo $f->hidden_field('from_item_id_m', $$class->from_item_id_m);
             $f->text_field_dm('from_item_number', 'select_item_number item_number');
             ?><i class="select_item_number_only select_popup clickable fa fa-search"></i>
            </td>
            <td><?php echo $f->select_field_from_object('relation_type', inv_item_relation::item_relation(), 'option_line_code', 'option_line_value', $$class->relation_type); ?></td>
            <td><?php
             echo $f->hidden_field('to_item_id_m', $$class->to_item_id_m );
             $f->text_field_dm('to_item_number', 'select_item_number item_number');
             ?><i class="select_item_number_only select_popup clickable fa fa-search"></i></td>
            <td><?php $f->text_field_d('description'); ?></td>
            <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
            <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
            <td><?php echo $f->select_field_from_array('status', inv_item_relation::$status_a, $$class->status); ?></td>
            <td><?php $f->checkBox_field_d('planning_cb'); ?></td>
           </tr>
           <?php
           $item_relation_object_ai->next();
           if ($item_relation_object_ai->key() == $position + $per_page) {
            break;
           }
           $count = $count + 1;
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
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_item_relation" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_item_relation_id" ></li>
  <li class="lineClassName" data-lineClassName="inv_item_relation" ></li>
  <li class="line_key_field" data-line_key_field="relation_type" ></li>
  <li class="no_headerid_check" data-no_headerid_check="9" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_item_relation" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_item_relation_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="inv_item_relation" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>