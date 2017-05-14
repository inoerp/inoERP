<div class="row small-left-padding">
 <div id="option">
  <!--    START OF FORM HEADER-->
  <form method="post" id="option_header"  name="option_header">
   <span class="heading"><?php     echo gettext('Option Header')     ?></span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('option_header_id'); ?>
         <a name="show" href="form.php?class_name=option_header&<?php echo "mode=$mode"; ?>" class="show document_id option_header_id">
          <i class="fa fa-refresh"></i></a>  
        </li>
        <li><label><?php echo gettext('Option Name') ?></label><?php echo $f->text_field_d('option_type', $readonly1_class); ?></li>
        <li><?php $f->l_select_field_from_array('access_level', option_header::$access_level_a, $option_header->access_level, 'access_level', '', '', $readonly); ?>					</li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_object('module_code', option_header::find_options_byName('SYS_MODULE'), 'option_line_code', 'option_line_value', $$class->module_code, 'module_code', '', 1) ?>				</li>
        <li><?php $f->l_select_field_from_object('option_assignments', option_header::find_options_byName('OPTION_ASSIGNMENT', $order_by_field), 'option_line_code', 'option_line_value', $option_header->option_assignments, 'option_assignments', $readonly); ?>					</li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
        <li><?php $f->l_text_field_d('rev_number'); ?></li>
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
          $reference_table = 'option_header';
          $reference_id = $$class->option_header_id;
          ?>
         </div>
         <div id="new_comment">
         </div>
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </form>
  <!--END OF FORM HEADER-->
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Option Line') ?></span>
   <form  method="post" id="option_line"  name="option_line">
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Effectivity') ?> </a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_line_data_table">
        <thead>
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Option Code') ?></th>
          <th><?php echo gettext('Value') ?></th>
          <th><?php echo gettext('Description') ?></th>
          <th><?php echo gettext('Priority') ?></th>
          <th><?php echo gettext('Mapper 1') ?></th>
          <th><?php echo gettext('Mapper 2') ?></th>
          <th><?php echo gettext('Value Group') ?></th>
          <th class="add_detail_values_header"><?php echo gettext('Details') ?></th>
         </tr>
        </thead>
        <tbody  class="form_data_line_tbody">
         <?php
         $linecount = 0;
         $option_line_object_ai = new ArrayIterator($option_line_object);
         $option_line_object_ai->seek($position);
         while ($option_line_object_ai->valid()) {
          $option_line = $option_line_object_ai->current();
          ?>
          <tr class="option_line<?php echo $linecount; ?>">
           <td><?php
            echo ino_inline_action($$class_second->option_line_id, array('option_header_id' => $$class->option_header_id));
            ?>   
           </td>
           <td><?php $f->seq_field_d($linecount) ?></td>
           <td><?php form::number_field_d2sr('option_line_id'); ?></td>
           <td><?php form::text_field_d2m('option_line_code'); ?></td>
           <td><?php form::text_field_d2m('option_line_value'); ?></td>
           <td><?php form::text_field_d2('description'); ?></td>
           <td><?php form::text_field_d2('priority'); ?></td>
           <td><?php form::text_field_d2('mapper1'); ?></td>
           <td><?php form::text_field_d2('mapper2'); ?></td>
           <td><?php echo form::select_field_from_object('value_group_id', sys_value_group_header::find_all(), 'sys_value_group_header_id', 'value_group', $$class_second->value_group_id, '', $readonly, '', ''); ?></td>
           <td class="add_detail_values">
            <i class="fa fa-arrow-circle-down add_detail_values_img"></i>
            <?php
            $option_line_id = $option_line->option_line_id;
            if (!empty($option_line_id)) {
             $option_detail_object = option_detail::find_by_option_line_id($option_line_id);
            } else {
             $option_detail_object = array();
            }
            if (count($option_detail_object) == 0) {
             $option_detail = new option_detail();
             $option_detail_object = array();
             array_push($option_detail_object, $option_detail);
            }
            ?>
            <div class="class_detail_form">
             <fieldset class="form_detail_data_fs"><legend><?php echo gettext('Detail Data') ?></legend>
              <table class="form form_detail_data_table detail">
               <thead>
                <tr>
                 <th><?php echo gettext('Action') ?></th>
                 <th><?php echo gettext('Seq') ?>#</th>
                 <th><?php echo gettext('Detail Id') ?></th>
                 <th><?php echo gettext('Value') ?></th>
                 <th><?php echo gettext('Description') ?></th>
                 <th><?php echo gettext('Start Date') ?></th>
                 <th><?php echo gettext('End Date') ?></th>
                </tr>
               </thead>
               <tbody class="form_data_detail_tbody">
                <?php
                $detailCount = 0;
                foreach ($option_detail_object as $option_detail) {
                 ?>
                 <tr class="option_detail_tr<?php echo $detailCount; ?>">
                  <td>   
                   <ul class="inline_action">
                    <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($option_detail->option_detail_id); ?>"></li>           
                    <li><?php echo form::hidden_field('option_line_id', $option_line->option_line_id); ?></li>
                    <li><?php echo form::hidden_field('option_header_id', $$class->option_header_id); ?></li>
                   </ul>
                  </td>
                  <td><?php $f->text_field_wid3sr('option_detail_id'); ?></td>
                  <td><?php $f->text_field_wid3('option_detail_value'); ?></td>
                  <td><?php $f->text_field_wid3('description'); ?></td>
                  <td><?php $f->text_field_wid3s('rev_number'); ?></td>
                  <td><?php echo $f->date_field('effective_start_date', $option_detail->effective_start_date); ?></td>
                  <td><?php echo $f->date_field('effective_end_date', $option_detail->effective_end_date); ?></td>
                 </tr>
                 <?php
                 $detailCount++;
                }
                ?>
               </tbody>
              </table>

             </fieldset>

            </div>

           </td>

          </tr>
          <?php
          $option_line_object_ai->next();
          if ($option_line_object_ai->key() == $position + $per_page) {
           break;
          }

          $linecount++;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Status') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody">
         <?php
         $linecount = 0;
         $option_line_object_ai = new ArrayIterator($option_line_object);
         $option_line_object_ai->seek($position);
         while ($option_line_object_ai->valid()) {
          $option_line = $option_line_object_ai->current();
          ?>         
          <tr class="option_line<?php echo $linecount ?>">
           <td><?php $f->seq_field_d($linecount) ?></td>
           <td><?php echo form::status_field($option_line->status); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_start_date', $option_line->effective_start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('effective_end_date', $option_line->effective_end_date); ?></td>
          </tr>
          <?php
          $option_line_object_ai->next();
          if ($option_line_object_ai->key() == $position + $per_page) {
           break;
          }
          $linecount++;
         }
         ?>
        </tbody>
        <!--                  Showing a blank form for new entry-->
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
  <li class="headerClassName" data-headerClassName="option_header" ></li>
  <li class="lineClassName" data-lineClassName="option_line" ></li>
  <li class="detailClassName" data-detailClassName="option_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="option_header_id" ></li>
  <li class="form_header_id" data-form_header_id="option_header" ></li>
  <li class="line_key_field" data-line_key_field="option_line_code" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="option_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="option_header_id" ></li>
  <li class="docLineId" data-docLineId="option_line_id" ></li>
  <li class="docDetailId" data-docDetailId="option_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="option_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="option_header" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
