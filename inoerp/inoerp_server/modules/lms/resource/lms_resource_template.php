<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header">
 <form  method="post" id="lms_resource"  name="lms_resource">
  <span class="heading"><?php echo gettext('Learning Management Resources') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Costing') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Employee') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Equipment') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('lms_resource_id'); ?>
        <a name="show" href="form.php?class_name=lms_resource&<?php echo "mode=$mode"; ?>" class="show document_id lms_resource_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly1); ?>      </li>
       <li><?php $f->l_text_field_d('resource'); ?> </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_select_field_from_object('resource_type', lms_resource::resource_type(), 'option_line_code', 'option_line_value', $$class->resource_type, '', '', 1, $readonly1); ?>       </li>
       <li><?php $f->l_select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class->charge_type, '', '', 1, $readonly); ?>       </li> 
       <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom', '', 1, $readonly1); ?>       </li>
       <li><?php $f->l_status_field_d('status'); ?></li>
      </ul>
    </div>

    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field"> 
       <li><?php $f->l_checkBox_field_d('costed_cb'); ?>       </li>
       <li><?php $f->l_ac_field_d('absorption_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('variance_ac_id'); ?></li>
       <li><?php $f->l_checkBox_field_d('standard_rate_cb'); ?>       </li>
      </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="large_shadow_box">

     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="large_shadow_box">

     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'lms_resource';
        $reference_id = $$class->lms_resource_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>

   </div>


  </div>
 
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Resource Cost Lines') ?> </span>
 <form   method="post" id="lms_resource_cost"  name="lms_resource_cost">
  <div id="tabsLine">
   <div class="tabContainer">
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th><?php echo gettext('Action') ?></th>
       <th><?php echo gettext('Seq') ?>#</th>
       <th><?php echo gettext('Resource Cost Id') ?></th>
       <th><?php echo gettext('Cost Type') ?></th>
       <th><?php echo gettext('Description') ?></th>
       <th><?php echo gettext('Rate') ?></th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      $count = 0;
      foreach ($lms_resource_cost_object as $lms_resource_cost) {
       if (!empty($lms_resource_cost->lms_cost_type)) {
        $bcy = new bom_cost_type();
        $bcy_i = $bcy->find_by_keyColumn($lms_resource_cost->lms_cost_type);
        $lms_resource_cost->lms_cost_type_description = $bcy_i->description;
       } else {
        $lms_resource_cost->lms_cost_type_description = null;
       }
       ?>         
       <tr class="lms_resource_cost<?php echo $count ?>">
        <td>
         <?php
         echo ino_inline_action($$class_second->lms_resource_cost_id, array('lms_resource_id' => $$class->lms_resource_id));
         ?>
        </td>
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php form::text_field_wid2r('lms_resource_cost_id'); ?></td>
        <td><?php echo $f->select_field_from_object('lms_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->lms_cost_type, '', 'medium', 1, $readonly); ?></td>
        <td><?php $f->text_field_wid2r('lms_cost_type_description' , 'xlarge'); ?></td>
        <td><?php echo $f->number_field('resource_rate', $$class_second->resource_rate); ?></td>
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
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="lms_resource" ></li>
  <li class="lineClassName" data-lineClassName="lms_resource_cost" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_resource_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_resource" ></li>
  <li class="line_key_field" data-line_key_field="lms_cost_type" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="lms_resource_cost" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_resource_id" ></li>
  <li class="docLineId" data-docLineId="lms_resource_cost_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_resource" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-doctrClass="lms_resource_cost" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
