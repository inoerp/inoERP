<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form  method="post" id="prj_default_account_line"  name="default_account_line">
    <span class="heading"><?php echo gettext('Project Default Accounts') ?></span>
    <div id="form_serach_header" class="tabContainer">
     <label><?php echo gettext('Project Type') ?></label></label>
     <?php echo $f->select_field_from_object('prj_project_type_header_id', prj_project_type_header::find_all(), 'prj_project_type_header_id', 'project_type', $prj_project_type_header_id_h, 'prj_project_type_header_id', 'action'); ?>
     <a name="show" href="form.php?class_name=prj_default_account&<?php echo "mode=$mode"; ?>" class="show document_id prj_default_account_id action">
      <i class="fa fa-refresh"></i></a> 
    </div>
    <div id ="form_line" class="prj_default_account"><span class="heading"><?php echo gettext('Line Details') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Default Accounts') ?></a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Document Type') ?>#</th>
           <th><?php echo gettext('Account') ?>#</th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Status') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody default_account_values" >
          <?php 
          $count = 0;
          $default_account_object_ai = new ArrayIterator($default_account_object);
          $default_account_object_ai->seek($position);
          while ($default_account_object_ai->valid()) {
           $prj_default_account = $default_account_object_ai->current();
           ?>         
           <tr class="prj_default_account<?php echo $count ?>">
            <td><?php
             echo ino_inline_action($$class->prj_default_account_id, array('prj_project_type_header_id' => $prj_project_type_header_id_h));
             ?>    
            </td>
             <td><?php form::number_field_drs('prj_default_account_id') ?></td>
             <td><?php echo $f->select_field_from_object('document_type', option_header::find_options_byName('PRJ_DOCUMENT_TYPE'), 'option_line_code', 'option_line_value', $$class->document_type, '', 'medium', '', $readonly); ?>        </td>
            <td><?php $f->ac_field_dm('ac_id'); ?></td>
            <td><?php form::text_field_wid('description'); ?></td>
            <td><?php $f->status_field_d('status'); ?></td>
           </tr>
           <?php
           $default_account_object_ai->next();
           if ($default_account_object_ai->key() == $position + $per_page) {
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
  <li class="primary_column_id" data-primary_column_id="prj_project_type_header_id" ></li>
  <li class="lineClassName" data-lineClassName="prj_default_account" ></li>
  <li class="line_key_field" data-line_key_field="default_account" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_default_account" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="prj_default_account_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="prj_default_account" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>