<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php   echo gettext('Catalog')   ?></span>
 <form method="post" id="sys_catalog_header"  name="sys_catalog_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('sys_catalog_header_id') ?>
        <a name="show" href="form.php?class_name=sys_catalog_header&<?php echo "mode=$mode"; ?>" class="show document_id sys_catalog_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('catalog'); ?></li>
       <li><?php $f->l_select_field_from_array('status', sys_catalog_header::$status_a, $sys_catalog_header->status); ?>	 </li>
       <li><?php $f->l_select_field_from_object('parent_catalog_header_id', sys_catalog_header::find_all(), 'sys_catalog_header_id', 'catalog', $$class->parent_catalog_header_id, 'parent_catalog_header_id'); ?>	 </li>
       <li><?php $f->l_text_field_d('description'); ?></li> 
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
        $reference_table = 'sys_catalog_header';
        $reference_id = $$class->sys_catalog_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Catalog Lines') ?></span>
 <form method="post" id="sys_catalog_line"  name="sys_catalog_line">
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
        <th><?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Required') ?></th>
        <th><?php echo gettext('Value Group') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sys_catalog_line_object as $sys_catalog_line) {
        ?>         
        <tr class="sys_catalog_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($sys_catalog_line->sys_catalog_line_id, array('sys_catalog_header_id' => $sys_catalog_header->sys_catalog_header_id));
          ?>
         </td>
         <td><?php $f->text_field_d2sr('sys_catalog_line_id'); ?></td>
         <td><?php $f->text_field_d2('line_name'); ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->checkBox_field('required_cb', $$class_second->required_cb); ?></td>
         <td><?php echo $f->select_field_from_object('sys_value_group_header_id', sys_value_group_header::find_all(), 'sys_value_group_header_id', 'value_group', $$class_second->sys_value_group_header_id); ?></td>
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
  <li class="headerClassName" data-headerClassName="sys_catalog_header" ></li>
  <li class="lineClassName" data-lineClassName="sys_catalog_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_catalog_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_catalog_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sys_catalog_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_catalog_header_id" ></li>
  <li class="docLineId" data-docLineId="sys_catalog_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_catalog_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>