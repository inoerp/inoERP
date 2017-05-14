   <div id="content">
    <div id="structure">
     <div id="user_dashboard_configId">
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <form action=""  method="post" id="user_dashboard_config"  name="user_dashboard_config"><span class="heading"><?php echo gettext('Dashboard Configuration') ?> </span>
       <!--END OF FORM HEADER-->
       <div id ="form_line" class="user_dashboard_config">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Details') ?> </a></li>
         </ul>
         <div class="tabContainer"> 
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th><?php echo gettext('Action') ?></th>
              <th><?php echo gettext('Id') ?></th>
              <th><?php echo gettext('Config Level') ?></th>
              <th><?php echo gettext('User Role') ?></th>
              <th><?php echo gettext('User Name') ?></th>
              <th><?php echo gettext('Group') ?></th>
              <th><?php echo gettext('Report Type') ?></th>
              <th><?php echo gettext('Report Name') ?> </th>
              <th><?php echo gettext('Priority') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody user_dashboard_config_values" >
             <?php
              $count = 0;
              foreach ($user_dashboard_config_object as $user_dashboard_config) {
               $report_a = [];
               if (!empty($user_dashboard_config->report_type)) {
                switch ($user_dashboard_config->report_type) {
                 case 'block' :
                  $block_i = block::find_all();
                  foreach ($block_i as $block_data) {
                   $block_id = $block_data->block_id;
                   $report_a[$block_id] = $block_data->title;
                  }
                  break;

                 case 'view' :
                  $view_i = view::find_all();
                  foreach ($view_i as $view_data) {
                   $view_id = $view_data->view_id;
                   $report_a[$view_id] = $view_data->view_name;
                  }
                  break;
                }
                if(!empty($user_dashboard_config->user_dashboard_config_id)){
                 if(empty($user_dashboard_config->user_id)){
                  $user->uesr_id = $user->username =  null;
                 }else{
                  $user = user::find_by_id($user_dashboard_config->user_id);
                 }
                }
                
               }
               ?>         
               <tr class="user_dashboard_config_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->user_dashboard_config_id); ?>"></li>           
                 </ul>
                </td>
                <td><?php $f->text_field_widsr('user_dashboard_config_id') ?></td>
                <td><?php
                 if ($admin) {
                  echo $f->select_field_from_array('config_level', user_dashboard_config::$config_level_a, $$class->config_level);
                 } else {
                  echo $f->select_field_from_array('config_level', array('USER'), 'USER', '', '', 1, 1, 1);
                 }
                 ?></td>
                <td><?php
                 if ($admin) {
                  echo $f->select_field_from_object('user_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->user_role);
                 } else {
                  echo 'No Access';
                 }
                 ?></td>

                <td><?php
                 $$class->username = isset($$class->username) ? $$class->username : '';
                 echo $f->text_field_ap(array('name' => 'username', 'value' => $user->username));
                 echo $f->hidden_field_withCLass('user_id', $user->user_id, 'copyData');
                 if (isset($_SESSION['is_admin']) && $_SESSION['is_admin'] == 1) {
                  echo '<img src="' . HOME_URL . 'themes/default/images/serach.png" class="user_id select_popup clickable">';
                 }
                 ?></td>
                <td><?php echo $f->select_field_from_object('report_group', user_dashboard_config::report_group(), 'option_line_code', 'option_line_value', $$class->report_group); ?></td>
                <td><?php echo $f->select_field_from_array('report_type', user_dashboard_config::$report_type_a, $$class->report_type); ?></td>
                <td><?php echo $f->select_field_from_array('report_id', $report_a, $$class->report_id, '', 'medium') ?></td>
                <td><?php echo $f->select_field_from_array('priority', dbObject::$position_array, $$class->priority); ?></td>
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
       </div> 
      </form>
     </div>
    </div>
    <!--   end of structure-->
   </div>
