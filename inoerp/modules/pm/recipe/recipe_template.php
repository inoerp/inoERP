<!-- * 
inoERP
 *
 * @copyright   2016 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php   echo gettext('Recipe')   ?></span>
 <form method="post" id="pm_recipe_header"  name="pm_recipe_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Material') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('pm_recipe_header_id') ?>
       <a name="show" href="form.php?class_name=pm_recipe_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_recipe_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('recipe_name'); ?></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php
       echo $f->l_val_field_dm('formula_name', 'pm_formula_header', 'formula_name', '', 'formula_name', 'vf_select_formula_name');
       echo $f->hidden_field_withId('pm_formula_header_id', $$class->pm_formula_header_id);
       ?><i class="generic g_select_routing_name select_popup clickable fa fa-search" data-class_name="pm_formula_header"></i></li>
      <li><?php
       echo $f->l_val_field_dm('routing_name', 'pm_process_routing_header', 'routing_name', '', 'routing_name', 'vf_select_routing_name');
       echo $f->hidden_field_withId('pm_process_routing_header_id', $$class->pm_process_routing_header_id);
       echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value org_id');
       ?><i class="generic g_select_routing_name select_popup clickable fa fa-search" data-class_name="pm_process_routing_header"></i></li>
      <li><?php $f->l_select_field_from_array('recipe_type', pm_recipe_header::$recipe_type_a, $$class->recipe_type); ?></li>
      <li><?php $f->l_text_field_d('revision'); ?></li>
      <li><?php $f->l_text_field_d('comment'); ?></li>
      <li><label><?php echo gettext('Owner') ?></label><?php $f->text_field_d('pm_employee_name', 'employee_name'); ?>
<?php echo $f->hidden_field_withId('owner_employee_id', $$class->owner_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('description') ?></li>
     </ul> 
    </div>
        <div id="tabsHeader-2" class="tabContent">
     <div><a class="btn btn-info btn-lg" target="_new" 
             href="form.php?class_name=pm_recipe_material_header&mode=9&pm_recipe_header_id=<?php echo $$class->pm_recipe_header_id; ?>"><?php echo gettext('Recipe Material') ?></a>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
<?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'pm_recipe_header';
        $reference_id = $$class->pm_recipe_header_id;
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

<span class="heading"><?php echo gettext('Recipe Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Organization') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Customers') ?></a></li>
  
 </ul>
 <div class="tabContainer">
  <form method="post" id="pm_recipe_line"  name="pm_recipe_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Organization') ?></th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Planned Loss') ?></th>
        <th><?php echo gettext('Fixed Loss UOM') ?></th>
        <th><?php echo gettext('Fixed Loss') ?></th>
        <th><?php echo gettext('Contiguous') ?>?</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       $pm_recipe_line_object_ai = new ArrayIterator($pm_recipe_line_object);
       $pm_recipe_line_object_ai->seek($position);
       while ($pm_recipe_line_object_ai->valid()) {
        $pm_recipe_line = $pm_recipe_line_object_ai->current();
        ?>         
        <tr class="pm_recipe_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_recipe_line->pm_recipe_line_id, array('pm_recipe_header_id' => $pm_recipe_header->pm_recipe_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('pm_recipe_line_id', 'line_id always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->org_id, '', '', 1, $readonly1); ?></td>
         <td><?php echo $f->select_field_from_array('org_type', pm_recipe_line::$org_type_a, $$class_second->org_type, '', 'medium'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php echo $f->number_field('planned_loss', $$class_second->planned_loss, '', '', 'allow_change'); ?></td>
         <td><?php echo form::select_field_from_object('fixed_loss_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->fixed_loss_uom_id, '', '', 'uom_id'); ?></td>
         <td><?php echo $f->number_field('fixed_loss', $$class_second->fixed_loss, '', '', 'allow_change'); ?></td>
         <td><?php echo $f->checkBox_field('contiguous_cb', $$class_second->contiguous_cb, '', 'dontCopy'); ?></td>
        </tr>
        <?php
        $pm_recipe_line_object_ai->next();
        if ($pm_recipe_line_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form  method="post" id="pm_recipe_customer"  name="pm_recipe_customer">
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Business Org') ?></th>
        <th><?php echo gettext('Customer') ?></th>
        <th><?php echo gettext('Customer Site') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($pm_recipe_customer_object as $pm_recipe_customer) {
        if (!empty($pm_recipe_customer->ar_customer_id)) {
         $pm_recipe_customer->customer_name = ar_customer::find_by_id($pm_recipe_customer->ar_customer_id)->customer_name;
        }
        if (!empty($$class_third->ar_customer_site_id)) {
         $arc = new ar_customer_site();
         $arc_i = $arc->findBy_id($$class_third->ar_customer_site_id);
         array_push($customer_site_obj, $arc_i);
        }
        ?>         
        <tr class="pm_recipe_customer<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($pm_recipe_customer->pm_recipe_customer_id); ?>"></li>           
           <li><?php echo form::hidden_field('pm_recipe_header_id', $$class->pm_recipe_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('pm_recipe_customer_id');?></td>
         <td><?php echo $f->select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class_third->org_id, '', 'large', '', $readonly); ?>						 </td>
         <td><?php
          echo $f->val_field('customer_name', $pm_recipe_customer->customer_name ,'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name large');
          echo $f->hidden_field_withId('ar_customer_id', $$class_third->ar_customer_id);
          ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></td>
         <td><?php echo $f->select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class_third->ar_customer_site_id, '', 'large'); ?> </td>
         <td><?php $f->text_field_wid3('description', 'large'); ?></td>
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

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
<?php echo $pagination->show_pagination(); ?>
 </div>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="pm_recipe_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_recipe_line" ></li>
  <li class="lineClassName2" data-lineClassName2="pm_recipe_customer" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_recipe_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_recipe_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_recipe_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_recipe_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_recipe_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_recipe_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>