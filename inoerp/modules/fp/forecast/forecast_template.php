<div class="row small-left-padding">
 <div id='fp_forecast_header_divId'>
  <div id ="form_header"><span class="heading"><?php echo gettext('Forecast Header') ?></span>
   <form method="post" id="fp_forecast_header"  name="fp_forecast_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
      <li><a href="#tabsHeader-4"><?php echo gettext('Secondary') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('fp_forecast_header_id'); ?>
         <a name="show" href="form.php?class_name=fp_forecast_header&<?php echo "mode=$mode"; ?>" class="show document_id fp_forecast_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
        <li><?php $f->l_text_field_dm('forecast'); ?>  </li>
        <li><?php $f->l_select_field_from_object('forecast_group_id', fp_forecast_group::find_all(), 'fp_forecast_group_id', 'forecast_group', $$class->forecast_group_id, 'forecast_group_id', '', '', $readonly) ?>  </li>
        <li><?php $f->l_status_field_d('status'); ?> </li>
        <li><?php $f->l_text_field_d('demand_class'); ?> </li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup">
          Customer Id</label><?php echo $f->text_field_dr('ar_customer_id'); ?></li>
        <li><label class="auto_complete">
          <?php echo gettext('Customer Name') ?></label><?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly); ?></li>
        <li><?php $f->l_text_field_d('description'); ?>  </li>
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
          $reference_table = 'fp_forecast_header';
          $reference_id = $$class->fp_forecast_header_id;
          ?>
         </div>
         <div id="new_comment">
         </div>
        </div>
       </div>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
      </div>
     </div>

    </div>
   </form>
  </div>

  <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Forecast Lines') ?></span>
   <form  method="post" id="forecast_line"  name="forecast_line">
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Quantity') ?> </a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Item Number') ?></th>
          <th><?php echo gettext('Description') ?></th>
          <th><?php echo gettext('UOM') ?></th>
          <th><?php echo gettext('Bucket') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
          <th><?php echo gettext('No Of Bucket') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody">
         <?php
         $count = 0;
         $fp_forecast_line_object_ai = new ArrayIterator($fp_forecast_line_object);
         $fp_forecast_line_object_ai->seek($position);
         while ($fp_forecast_line_object_ai->valid()) {
          $fp_forecast_line = $fp_forecast_line_object_ai->current();
          if (!empty($fp_forecast_line->item_id_m)) {
           $item_i = item::find_by_id($fp_forecast_line->item_id_m);
           $fp_forecast_line->item_number = $item_i->item_number;
           $fp_forecast_line->item_description = $item_i->item_description;
           $fp_forecast_line->uom_id = $item_i->uom_id;
          } else {
           $fp_forecast_line->item_number = $fp_forecast_line->item_description = $fp_forecast_line->uom_id = null;
          }  
          ?>         
          <tr class="fp_forecast_line<?php echo $count ?>">
           <td><?php echo ino_inline_action($$class_second->fp_forecast_line_id, array('fp_forecast_header_id' => $$class->fp_forecast_header_id));  ?>  </td>
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php form::text_field_wid2sr('fp_forecast_line_id'); ?></td>
           <td><?php echo $f->hidden_field('item_id_m', $$class_second->item_id_m); ?> 
            <?php form::text_field_wid2('item_number', 'select_item_number'); ?>
            <i class="select_item_number select_popup clickable fa fa-search"></i></td>
           <td><?php form::text_field_wid2r('item_description'); ?></td>
           <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'medium', '', 1); ?></td>
           <td><?php echo $f->select_field_from_object('bucket_type', fp_forecast_header::fp_bucket(), 'option_line_code', 'option_line_value', $$class_second->bucket_type, '', 'medium', 1, $readonly); ?></td>
           <td><?php echo $f->date_fieldFromToday('start_date', $$class_second->start_date); ?></td>
           <td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
           <td><?php $f->text_field_wid2s('no_of_bucket'); ?></td>
          </tr>
          <?php
          $fp_forecast_line_object_ai->next();
          if ($fp_forecast_line_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="scrollElement tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Current') ?></th>
          <th><?php echo gettext('Original') ?></th>
          <th><?php echo gettext('Total Current') ?></th>
          <th><?php echo gettext('Total Original') ?></th>
          <th><?php echo gettext('Forecast Details') ?></th>
          <th><?php echo gettext('Consumption Id') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody">
         <?php
         $count = 0;
         $fp_forecast_line_object_ai = new ArrayIterator($fp_forecast_line_object);
         $fp_forecast_line_object_ai->seek($position);
         while ($fp_forecast_line_object_ai->valid()) {
          $fp_forecast_line = $fp_forecast_line_object_ai->current();
          $$class_second->current = $$class_second->total_current = null;
          ?>         
          <tr class="fp_forecast_line<?php echo $count ?>">
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php echo $f->number_field('current', $$class_second->current, '', '', 'always_readonly'); ?></td>
           <td><?php echo $f->number_field('original', $$class_second->original); ?></td>
           <td><?php echo $f->number_field('total_current', $$class_second->total_current, '', '', 'always_readonly'); ?></td>
           <td><?php echo $f->number_field('total_original', $$class_second->total_original, '', '', 'always_readonly'); ?></td>
           <td><?php
            $link_fd = HOME_URL . "search.php?fp_forecast_line_id[]=%3D{$$class_second->fp_forecast_line_id}&search_order_by[]=fp_forecast_line_date_id&search_asc_desc[]=desc&per_page[]=10&search_class_name=fp_forecast_line_date_v&submit_search=Search";
            echo '<a target="_blank" window_type="popup" class=\'button\' href="' . $link_fd . '">Date Specific</a>';
            ?></td>
           <td><?php $f->text_field_d2r('fp_consumption_id', 'always_readonly'); ?></td>
          </tr>
          <?php
          $fp_forecast_line_object_ai->next();
          if ($fp_forecast_line_object_ai->key() == $position + $per_page) {
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
  <li class="headerClassName" data-headerClassName="fp_forecast_header" ></li>
  <li class="lineClassName" data-lineClassName="fp_forecast_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_forecast_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_forecast_header" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fp_forecast_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_forecast_header_id" ></li>
  <li class="docLineId" data-docLineId="fp_forecast_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_forecast_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>