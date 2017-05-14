<div id ="form_header">
 <span class="heading"><?php echo gettext('Process Flow Header') ?></span>
 <form action=""  method="post" id="process_flow_header"  name="process_flow_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('sys_process_flow_header_id') ?>
       <a name="show" href="form.php?class_name=sys_process_flow_header&<?php echo "mode=$mode"; ?>" class="show document_id sys_process_flow_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('process_flow'); ?> </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_select_field_from_array('type', sys_process_flow_header::$type_a, $$class->type); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_select_field_from_object('module_name', option_header::modules(), 'option_line_code', 'option_line_value', $$class->module_name, 'module_name', '', 1, $readonly) ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'sys_process_flow_header';
       $reference_id = $$class->sys_process_flow_header_id;
       ?>
      </div>
      <div id="new_comment">
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Process Flow Lines') ?></span>
 <form action=""  method="post" id="process_flow_line"  name="process_flow_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Decision') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Flow Diagram') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line Number') ?></th>
        <th><?php echo gettext('Sub Process Name') ?></th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Class Name') ?></th>
        <th><?php echo gettext('Method Name') ?></th>
        <th><?php echo gettext('Process Actions') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sys_process_flow_line_object as $sys_process_flow_line) {
        ?>         
        <tr class="sys_process_flow_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->sys_process_flow_line_id, array('sys_process_flow_header_id' => $$class->sys_process_flow_header_id));
          ?>    
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2sr('sys_process_flow_line_id'); ?></td>
         <td><?php echo $f->text_field_ap(array('name' => 'line_number', 'value' => $$class_second->line_number, 'class_name' => 'lines_number small')); ?></td>
         <td><?php $f->text_field_wid2('line_name'); ?></td>
         <td><?php echo $f->select_field_from_array('line_type', sys_process_flow_line::$line_type_a, $$class_second->line_type); ?></td>
         <td><?php $f->text_field_wid2l('description'); ?></td>
         <td><?php $f->text_field_wid2('class_name'); ?></td>
         <td><?php $f->text_field_wid2('method_name'); ?></td>
         <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
          <!--</td></tr>-->	
          <?php
          $sys_process_flow_line_id = $sys_process_flow_line->sys_process_flow_line_id;
          if (!empty($sys_process_flow_line_id)) {
           $sys_process_flow_action_object = sys_process_flow_action::find_by_parent_id($sys_process_flow_line_id);
          } else {
           $sys_process_flow_action_object = array(new sys_process_flow_action());
          }
          if (empty($sys_process_flow_action_object)) {
           $sys_process_flow_action_object = array(new sys_process_flow_action());
          }
          ?>
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Action Id') ?>#</th>
                  <th><?php echo gettext('Seq Number') ?></th>
                  <th><?php echo gettext('Action Type') ?></th>
                  <th><?php echo gettext('Role') ?></th>
                  <th><?php echo gettext('User') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($sys_process_flow_action_object as $sys_process_flow_action) {
                  $class_third = 'sys_process_flow_action';
                  $$class_third = &$sys_process_flow_action;
                  ?>
                  <tr class="sys_process_flow_action<?php echo $count . '-' . $detailCount; ?>">
                   <td>   
                    <ul class="inline_action">
                     <li class="add_row_detail_img"><i class="fa fa-plus-circle"></i></li>
                     <li class="remove_row_img"><i class="fa fa-minus-circle"> </i></li>
                     <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($sys_process_flow_action->sys_process_flow_action_id); ?>"></li>           
                     <li><?php echo form::hidden_field('sys_process_flow_line_id', $$class_second->sys_process_flow_line_id); ?></li>
                     <li><?php echo form::hidden_field('sys_process_flow_header_id', $$class->sys_process_flow_header_id); ?></li>
                    </ul>
                   </td>
                   <td><?php form::text_field_wid3sr('sys_process_flow_action_id'); ?></td>
                   <td><?php echo $f->number_field('action_number', $$class_third->action_number, '', '', 'detail_number'); ?></td>
                   <td><?php echo $f->select_field_from_array('pf_action_type', sys_process_flow_action::$pf_action_type_a, $$class_third->pf_action_type); ?></td>
                   <td><?php echo $f->select_field_from_object('role_code', role_access::roles(), 'option_line_code', 'option_line_value', $$class_third->role_code, 'role_code'); ?></td>
                   <td><?php
                    echo $f->hidden_field('user_id', $$class_third->user_id);
                    $$class_third->username = !empty($$class_third->user_id) ? ino_user::find_by_id($$class_third->user_id)->username : null;
                    echo $f->text_field('username', $$class_third->username);
                    ?>
                    <img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="user_id select_popup clickable">
                   </td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
             </div>
            </div>


           </fieldset>

          </div>

         </td>
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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Next Seq On Pass') ?></th>
        <th><?php echo gettext('Next Seq If Fail') ?></th>
        <th><?php echo gettext('Next Seq On Return') ?>#</th>
        <th><?php echo gettext('Activity Path') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sys_process_flow_line_object as $sys_process_flow_line) {
        ?>         
        <tr class="sys_process_flow_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2('next_line_seq_pass'); ?></td>
         <td><?php $f->text_field_wid2('next_line_seq_fail'); ?></td>
         <td><?php $f->text_field_wid2('next_line_seq_onhold'); ?></td>
         <td><?php $f->text_field_wid2('activity_path'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-3" class="scrollElement tabContent">
     <?php echo sys_process_flow_header::processFlowDiagram($sys_process_flow_line_object); ?>
    </div>
   </div>
  </div>
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_process_flow_header" ></li>
  <li class="lineClassName" data-lineClassName="sys_process_flow_line" ></li>
  <li class="detailClassName" data-detailClassName="sys_process_flow_action" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_process_flow_header_id" ></li>
  <li class="form_header_id" data-form_header_id="process_flow_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <!--<li class="single_line" data-enable_select="true" ></li>-->
  <li class="form_line_id" data-form_line_id="form_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_process_flow_header_id" ></li>
  <li class="docLineId" data-docLineId="sys_process_flow_line_id" ></li>
  <li class="docDetailId" data-docDetailId="sys_process_flow_action_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_process_flow_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="sys_process_flow_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>