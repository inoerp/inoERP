<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Service Type') ?></span>
 <form action=""  method="post" id="hd_service_type_header"  name="hd_service_type_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Repair Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hd_service_type_header_id') ?>
       <a name="show" href="form.php?class_name=hd_service_type_header&<?php echo "mode=$mode"; ?>" class="show document_id hd_service_type_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('service_type'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_select_field_from_array('repair_mode', hd_service_type_header::$repair_mode_a, $$class->repair_mode, 'repair_mode'); ?></li>
      <li><?php $f->l_select_field_from_object('primary_service_type', hd_service_type_header::primary_service_type(), 'option_line_code', 'option_line_value', $$class->primary_service_type, 'primary_service_type'); ?></li>
      <li><?php $f->l_select_field_from_object('prices_list_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class->prices_list_id, 'prices_list_id'); ?></li>
      <li><?php $f->l_checkBox_field_d('active_cb'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <?php
      $service_activity_return = hd_service_activity_header::find_by_oneColumn(['column_name' => 'line_category', 'column_value' => 'RETURN']);
      $service_activity_so = hd_service_activity_header::find_by_oneColumn(['column_name' => 'line_category', 'column_value' => 'ORDER']);
      ?>
      <li><?php $f->l_select_field_from_object('pre_repair_activity_rma', $service_activity_return, 'hd_service_activity_header_id', 'activity_name', $$class->pre_repair_activity_rma, 'pre_repair_activity_rma'); ?></li>
      <li><?php $f->l_select_field_from_object('pre_repair_activity_so', $service_activity_so, 'hd_service_activity_header_id', 'activity_name', $$class->pre_repair_activity_so, 'pre_repair_activity_so'); ?></li>
      <li><?php $f->l_select_field_from_object('post_repair_activity_rma', $service_activity_return, 'hd_service_activity_header_id', 'activity_name', $$class->post_repair_activity_rma, 'post_repair_activity_rma'); ?></li>
      <li><?php $f->l_select_field_from_object('post_repair_activity_so', $service_activity_so, 'hd_service_activity_header_id', 'activity_name', $$class->post_repair_activity_so, 'post_repair_activity_so'); ?></li>
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
        $reference_table = 'hd_service_type_header';
        $reference_id = $$class->hd_service_type_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Service Type Lines') ?></span>
 <form action=""  method="post" id="hd_service_type_line"  name="hd_service_type_line">
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
        <th><?php echo gettext('Billing Type') ?></th>
        <th><?php echo gettext('Service Activity') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_service_type_line_object as $hd_service_type_line) {
        ?>         
        <tr class="hd_service_type_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($hd_service_type_line->hd_service_type_line_id, array('hd_service_type_header_id' => $$class->hd_service_type_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_service_type_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('billing_type', hd_service_type_header::billing_type(), 'option_line_code', 'option_line_value', $$class_second->billing_type); ?></td>
         <td><?php echo $f->select_field_from_object('service_activity_id', hd_service_activity_header::find_all(), 'hd_service_activity_header_id', 'activity_name', $$class_second->service_activity_id); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
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
  <li class="headerClassName" data-headerClassName="hd_service_type_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_service_type_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_service_type_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_service_type_header" ></li>
  <li class="line_key_field" data-line_key_field="billing_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hd_service_type_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_service_type_header_id" ></li>
  <li class="docLineId" data-docLineId="hd_service_type_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_service_type_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>