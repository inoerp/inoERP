<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="engine_divId">
     <!--    START OF FORM HEADER-->
     <div class="error"></div><div id="loading"></div>
     <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
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
              $f = new inoform();
              $count = 1;
              foreach ($all_data as $mod_name => $modules) {
               $mod_name = strtoupper($mod_name);
               echo "<tr><td colspan='10' class='major_row'>$mod_name </td></tr>";
               foreach ($modules as $submodules) {
                if (!is_array($submodules)) {
                 continue;
                }
                $this_engine_i = $engine->findBy_className($submodules['obj_class_name']);
                if ($this_engine_i) {
                 $installed_cb_v = true;
                 $enabled_cb_v = ($this_engine_i->enabled_cb) ? true : false;
                 $engine_id_v = $this_engine_i->engine_id;
                } else {
                 $installed_cb_v = $enabled_cb_v = $engine_id_v= false;
                }
                ?>         
                <tr class="engine_line<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($submodules['name']); ?>"></li>           
                   <li><?php echo $count ?></li>
                   <?php echo $f->hidden_field('type', $dir_path) ?>
                   <?php // echo $f->hidden_field('engine_id', $engine_id_v) ?>
                  </ul>
                 </td>
                 <td><?php echo $f->text_field_ap(['name' => 'name', 'value' => $submodules['name'], 'size' => '15', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'number', 'value' => $submodules['number'], 'size' => '10', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'engine_id', 'value' => $engine_id_v, 'size' => '3', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'obj_class_name', 'value' => $submodules['obj_class_name'], 'size' => '25', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'description', 'value' => $submodules['description'], 'size' => '55', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'db_version', 'value' => $submodules['db_version'], 'size' => '6', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'db_version', 'value' => $submodules['db_version'], 'size' => '6', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->checkBox_field('installed_cb', $installed_cb_v, '', '', 1); ?></td>
                 <td><?php echo $f->checkBox_field('enabled_cb', $enabled_cb_v); ?></td>
                </tr>
                <?php
                $count = $count + 1;
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
               <th>Un install</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody engine_values" >
              <?php
              $count = 1;
              foreach ($all_data as $mod_name => $modules) {
               $mod_name = strtoupper($mod_name);
               echo "<tr><td colspan='9' class='major_row'>$mod_name </td></tr>";
               foreach ($modules as $submodules) {
                if (!is_array($submodules)) {
                 continue;
                }
                ?>         
                <tr class="engine_line<?php echo $count ?>">
                 <td><?php echo $count ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'module_name', 'value' => $submodules['module_name'], 'size' => '12', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'weight', 'value' => $submodules['weight'], 'size' => '6', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'version', 'value' => $submodules['version'], 'size' => '6', 'readonly' => 1]) ?></td>

                 <td><?php echo $f->text_field_ap(['name' => 'mod_version', 'value' => $submodules['mod_version'], 'size' => '8', 'readonly' => 1]) ?></td>
                 <td><?php
                  $dms = '';
                  if (!empty($submodules['dependent_class']) && (is_array($submodules['dependent_class']))) {
                   foreach ($submodules['dependent_class'] as $key => $val) {
                    $dms .= $val . ', ';
                   }
                  }

                  echo $f->text_field_ap(['name' => 'dependent_class', 'value' => $dms, 'size' => '50', 'readonly' => 1]);
                  ?></td>
                 <td><?php echo $f->text_field_ap(['name' => 'path', 'value' => $submodules['path'], 'size' => '52', 'readonly' => 1]) ?></td>
                 <td><?php echo $f->checkBox_field('uninstall_cb', ''); ?></td>
                </tr>
                <?php
                $count = $count + 1;
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
      <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
      ?>
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