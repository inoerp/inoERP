<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Menu') ?></span>
 <form method="post" id="extn_menu_header"  name="extn_menu_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('extn_menu_header_id') ?>
       <a name="show" href="form.php?class_name=extn_menu_header&<?php echo "mode=$mode"; ?>" class="show document_id extn_menu_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('menu_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php echo $f->l_select_field_from_array('priority', dbObject::$position_array, $$class->priority, '', 'medium'); ?></li>
      <li><?php $f->l_text_field_d('css_class'); ?></li>
      <li><?php $f->l_checkBox_field_d('active_cb'); ?></li>
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
        $reference_table = 'extn_menu_header';
        $reference_id = $$class->extn_menu_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Menu Links') ?></span>
 <form action=""  method="post" id="extn_menu_line"  name="extn_menu_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Link Details') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Link Position') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Id') ?></th>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Parent') ?></th>
        <th><?php echo gettext('Title') ?></th>
        <th><?php echo gettext('Path') ?></th>
        <th><?php echo gettext('External Link (Full Path)') ?></th>
        <th><?php echo gettext('Intenal Link (Relative Path)') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($extn_menu_line_object as $extn_menu_line) {
        ?>         
        <tr class="extn_menu_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($extn_menu_line->extn_menu_line_id, array('extn_menu_header_id' => $$class->extn_menu_header_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('extn_menu_line_id'); ?></td>
         <td><?php $f->seq_field_d($count); ?></td>  
         <td><?php $f->text_field_wid2('link_name'); ?></td>
         <td><?php echo $f->select_field_from_object('parent_id', extn_menu_line::find_by_parent_id($$class->extn_menu_header_id), 'extn_menu_line_id', 'link_name', $$class_second->parent_id, '', 'medium'); ?></td>
         <td><?php $f->text_field_wid2('link_title'); ?></td>
         <td><?php echo $f->select_field_from_object('path_id', path::find_all(), 'path_id', array('module_code', 'name'), $$class_second->path_id, '', 'medium', '', '', 1); ?></td>
         <td><?php $f->text_field_wid2l('external_link') ?></td>
         <td><?php $f->text_field_wid2l('interanl_link') ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>

        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Dropdown Parent') ?></th>
        <th><?php echo gettext('CSS Class') ?></th>
        <th><?php echo gettext('Icon CSS Class') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Priority') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;  
       foreach ($extn_menu_line_object as $extn_menu_line) {
        ?>         
        <tr class="extn_menu_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>  
         <td><?php $f->checkBox_field_wid2('dropdown_cb'); ?></td>
         <td><?php $f->text_field_wid2('css_class'); ?></td>
         <td><?php $f->text_field_wid2('icon_css_class'); ?></td>
         <td><?php $f->text_field_wid2l('description'); ?></td>
         <td><?php echo $f->select_field_from_array('priority', dbObject::$position_array, $$class_second->priority, '', 'medium'); ?></td>
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
  <li class="headerClassName" data-headerClassName="extn_menu_header" ></li>
  <li class="lineClassName" data-lineClassName="extn_menu_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_menu_header_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_menu_header" ></li>
  <li class="line_key_field" data-line_key_field="header_type_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="extn_menu_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_menu_header_id" ></li>
  <li class="docLineId" data-docLineId="extn_menu_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_menu_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>