<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="engine_divId">
     <!--    START OF FORM HEADER-->
     <div class="error"></div><div id="loading"></div>
     <?php
     echo (!empty($show_message)) ? $show_message : "";
     $f = new inoform();
     $all_data_ai = new ArrayIterator($all_data);
     $all_data_ai->seek($position);
     ?> 
     <!--    End of place for showing error messages-->
     <div id="form_all">
      <div id="form_headerDiv">
       <form action=""  method="post" id="engine_line"  name="engine_line">
        <div id ="form_line" class="engine"><span class="heading"><?php echo ucfirst($dir_path); ?>  Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Basic Info </a></li>
           <li><a href="#tabsLine-2">Related Details </a></li>
          </ul>
          <div class="tabContainer"> 

           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Action-Row #</th>
               <th>Name</th>
               <th>Number</th>
               <th>Id</th>
               <th>Class Name</th>
               <th>Description</th>
               <th>File DB Ver</th>
               <th>DB Ver</th>
               <th>Installed</th>
               <th>Enabled</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody engine_values" >
              <?php
              $count = 1;
              while ($all_data_ai->valid()) {
               $modules = $all_data_ai->current();
               if (empty($mod_name)) {
                $mod_name = strtoupper($modules['module_name']);
                echo "<tr class='major_row_tr'><td colspan='10' class='major_row'>$mod_name </td></tr>";
                continue;
               }else if ($mod_name != strtoupper($modules['module_name'])) {
                $mod_name = strtoupper($modules['module_name']);
                echo "<tr class='major_row_tr'><td colspan='10' class='major_row'>$mod_name </td></tr>";
                continue;
               }
               $this_engine_i = $engine->findBy_className($modules['obj_class_name']);
               if ($this_engine_i) {
                $installed_cb_v = true;
                $enabled_cb_v = ($this_engine_i->enabled_cb) ? true : false;
                $engine_id_v = $this_engine_i->engine_id;
               } else {
                $installed_cb_v = $enabled_cb_v = $engine_id_v = false;
               }
               ?>         
               <tr class="engine_line line_no<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($modules['name']); ?>"></li>           
                  <li><?php echo $count ?></li>
                  <?php echo $f->hidden_field('type', $dir_path) ?>
                  <?php // echo $f->hidden_field('engine_id', $engine_id_v)   ?>
                 </ul>
                </td>
                <td><?php echo $f->text_field_ap(['name' => 'name', 'value' => $modules['name'], 'size' => '15', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'number', 'value' => $modules['number'], 'size' => '10', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'engine_id', 'value' => $engine_id_v, 'size' => '3', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'obj_class_name', 'value' => $modules['obj_class_name'], 'size' => '25', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'description', 'value' => $modules['description'], 'size' => '55', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'db_version', 'value' => $modules['db_version'], 'size' => '6', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'db_version', 'value' => $modules['db_version'], 'size' => '6', 'readonly' => 1]) ?></td>
                <td><?php echo $f->checkBox_field('installed_cb', $installed_cb_v, '', '', 1); ?></td>
                <td><?php echo $f->checkBox_field('enabled_cb', $enabled_cb_v); ?></td>
               </tr>
               <?php
               $count = $count + 1;
               $all_data_ai->next();
               if ($all_data_ai->key() >= $position + $per_page) {
                break;
               }
              }
              ?>
             </tbody>
            </table>
           </div>
           <div id="tabsLine-2" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Row #</th>
               <th><?php echo ucfirst($dir_path) ?> Name</th>
               <th>Weight</th>
               <th>Version</th>
               <th>Mod Version</th>
               <th>Dependent</th>
               <th>Path</th>
               <th>Update DB</th>
               <th>Un install</th>
              </tr>
             </thead>

             <tbody class="form_data_line_tbody engine_values" >
              <?php
              unset($mod_name);
              $all_data_ai->rewind();
                   $all_data_ai->seek($position);
              $count = 1;
              while ($all_data_ai->valid()) {
               $modules = $all_data_ai->current();
               if (empty($mod_name)) {
                $mod_name = strtoupper($modules['module_name']);
                echo "<tr class='major_row_tr'><td colspan='10' class='major_row'>$mod_name </td></tr>";
                continue;
               }else if ($mod_name != strtoupper($modules['module_name'])) {
                $mod_name = strtoupper($modules['module_name']);
                echo "<tr class='major_row_tr'><td colspan='10' class='major_row'>$mod_name </td></tr>";
                continue;
               }
               ?>         
               <tr class="engine_line<?php echo $count ?>">
                <td><?php echo $count ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'name', 'value' => $modules['name'], 'size' => '15', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'weight', 'value' => $modules['weight'], 'size' => '6', 'readonly' => 1]) ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'version', 'value' => $modules['version'], 'size' => '6', 'readonly' => 1]) ?></td>

                <td><?php echo $f->text_field_ap(['name' => 'mod_version', 'value' => $modules['mod_version'], 'size' => '8', 'readonly' => 1]) ?></td>
                <td><?php
                 $dms = '';
                 if (!empty($modules['dependent_class']) && (is_array($modules['dependent_class']))) {
                  foreach ($modules['dependent_class'] as $key => $val) {
                   $dms .= $val . ', ';
                  }
                 }
                 echo $f->text_field_ap(['name' => 'dependent_class', 'value' => $dms, 'size' => '40', 'readonly' => 1]);
                 ?></td>
                <td><?php echo $f->text_field_ap(['name' => 'path', 'value' => $modules['path'], 'size' => '50', 'readonly' => 1]) ?></td>
                <td><?php echo $f->checkBox_field('update_db_cb', ''); ?></td>
                <td><?php echo $f->checkBox_field('uninstall_cb', ''); ?></td>
               </tr>
               <?php
               $count = $count + 1;

               $all_data_ai->next();
               if ($all_data_ai->key() >= $position + $per_page) {
                break;
               }
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

     <div id="pagination" style="clear: both;">
      <?php echo $pagination->show_pagination(); ?>
     </div>
     <!--END OF FORM -->
    </div>

   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>