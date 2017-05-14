<?php
$stmt = '';
echo (!empty($show_message)) ? $show_message : "";
$all_data_ai = new ArrayIterator($all_data);
$all_data_ai->seek($position);
?> 
<!--    End of place for showing error messages-->
<form  method="post" id="sys_engine"  name="sys_engine">
 <div id ="form_line" class="form_line"><span class="heading"><?php echo ucfirst($dir_path); ?><?php echo gettext('Details') ?>
	<a role="button" class="ajax-link btn btn-success pull-right" href="<?php echo HOME_URL.'form.php?class_name=engine&mode=9' ?>"><?php echo gettext('All Modules') ?></a></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Related Details') ?> </a></li>
   </ul>
   <div class="tabContainer"> 

    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action-Row #') ?></th>
        <th><?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Number') ?></th>
        <th><?php echo gettext('Id') ?></th>
        <th><?php echo gettext('Class Name') ?></th>
        <th><?php echo gettext('Module') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('File DB Ver') ?></th>
        <th><?php echo gettext('DB Ver') ?></th>
        <th><?php echo gettext('Installed') ?></th>
        <th><?php echo gettext('Enabled') ?></th>
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
        } else if ($mod_name != strtoupper($modules['module_name'])) {
         $mod_name = strtoupper($modules['module_name']);
         echo "<tr class='major_row_tr'><td colspan='10' class='major_row'>$mod_name </td></tr>";
         continue;
        }
        $this_engine_i = $engine->findBy_className($modules['obj_class_name']);
        if ($this_engine_i) {
         $installed_cb_v = true;
         $enabled_cb_v = ($this_engine_i->enabled_cb) ? true : false;
         $engine_id_v = $this_engine_i->engine_id;
         $db_version_v = $this_engine_i->db_version;
        } else {
         $installed_cb_v = $enabled_cb_v = $engine_id_v = $db_version_v = false;
        }
//        $stmt .= "<br> $count|".$modules['name'].'|'.$modules['number'].'|'.$modules['description'] .'|' .$enabled_cb_v ;
        ?>         
        <tr class="engine_line line_no<?php  echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="remove_row_img"><i class="fa fa-minus-circle" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($engine_id_v); ?>"></li>           
           <li><?php echo $count ?></li>
           <?php echo $f->hidden_field('type', $dir_path) ?>
           <?php echo $f->hidden_field('module_name', $modules['module_name']) ?>
           <?php echo $f->hidden_field('engine_id', $engine_id_v) ?>
          </ul>
         </td>
         <td><?php echo $f->text_field_ap(['name' => 'name', 'value' => $modules['name'], 'size' => '15', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'number', 'value' => $modules['number'], 'size' => '10', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'existing_engine_id', 'value' => $engine_id_v, 'size' => '3', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'obj_class_name', 'value' => $modules['obj_class_name'], 'size' => '25', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'module_name', 'value' => $modules['module_name'], 'size' => '15', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'description', 'value' => $modules['description'], 'size' => '55', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'db_version', 'value' => $modules['db_version'], 'size' => '6', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'db_version_db', 'value' => $db_version_v, 'size' => '6', 'readonly' => 1]) ?></td>
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
        <th><?php echo ucfirst($dir_path) ?> <?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Weight') ?></th>
        <th><?php echo gettext('Version') ?></th>
        <th><?php echo gettext('Mod Version') ?></th>
        <th><?php echo gettext('Dependent') ?></th>
        <th><?php echo gettext('Path') ?></th>
        <th><?php echo gettext('Update DB') ?></th>
        <th><?php echo gettext('Un install') ?></th>
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
        } else if ($mod_name != strtoupper($modules['module_name'])) {
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

<div id="pagination" style="clear: both;">
 <?php echo $stmt;  echo $pagination->show_pagination(); ?>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="engine" ></li>
  <li class="lineClassName" data-lineClassName="engine" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="obj_class_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="engine_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
