<div id ="form_header">
 <span class="heading"><?php echo gettext('Catalog Value') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><?php $f->l_text_field('reference_table', $reference_table_h, '', 'reference_table', '', '', 1); ?></li>
     <li><?php $f->l_text_field('reference_id', $reference_id_h, '', 'reference_id', '', '', 1); ?></li>
     <li><?php $f->l_select_field_from_object('sys_catalog_header_id', sys_catalog_header::find_all(), 'sys_catalog_header_id', 'catalog', $sys_catalog_header_id_h, 'sys_catalog_header_id', '', 1); ?>
      <a name="show2" href="form.php?class_name=sys_catalog_value&<?php echo "mode=$mode"; ?>" class="show2 document_id sys_catalog_header_id"><i class="fa fa-refresh"></i></a> </li>
    </ul>
   </div>
  </div>
 </div>
</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Catalog Values') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Name & Values') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="sys_catalog_value"  name="sys_catalog_value">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Value Id') ?></th>
        <th><?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Values') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody sys_catalog_value_values" >
       <?php
       $count = 0;
       foreach ($sys_catalog_value_object as $sys_catalog_value) {
        $val_group_lines = null;
        if (!empty($sys_catalog_value->sys_value_group_header_id)) {
         $val_group_lines = sys_value_group_line::find_by_parent_id($sys_catalog_value->sys_value_group_header_id);
        }
        ?>         
        <tr class="sys_catalog_value<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class->sys_catalog_value_id, array('sys_catalog_header_id' => $sys_catalog_header_id_h,
           'reference_table' => $reference_table_h, 'reference_id' => $reference_id_h,
           'sys_catalog_line_id' => $$class->sys_catalog_line_id
          ));
          ?>
         </td>
         <td><?php $f->text_field_widr('sys_catalog_value_id'); ?></td>
         <td><?php $f->text_field_widr('line_name'); ?></td>
         <td><?php $f->text_field_widr('description'); ?></td>
         <td><?php
          if (!empty($val_group_lines)) {
          echo $f->select_field_from_object('line_value', $val_group_lines, 'code', 'code_value', $$class->line_value);
          } else {
           $f->text_field_wid('line_value');
          }
          ?>
         </td>
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_catalog_value" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_catalog_value_id" ></li>
  <li class="lineClassName" data-lineClassName="sys_catalog_value" ></li>
  <li class="line_key_field" data-line_key_field="line_value" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sys_catalog_value" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="sys_catalog_value_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="sys_catalog_value" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>