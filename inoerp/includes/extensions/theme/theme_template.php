<?php
echo (!empty($show_message)) ? $show_message : "";
$all_data_ai = new ArrayIterator($all_data);
$all_data_ai->seek($position);
?> 
<!--    End of place for showing error messages-->
<form  method="post" id="sys_extn_theme"  name="sys_extn_theme">
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Theme List') ?></span>
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
        <th>Theme Name</th>
        <th>Id</th>
        <th>Description</th>
        <th>Version</th>
        <th>Enabled</th>
        <th>Default</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody extn_theme_values" >
       <?php
       $count = 1;
       while ($all_data_ai->valid()) {
        $themes = $all_data_ai->current();
        $this_extn_theme_i = extn_theme::find_by_themeName($themes['theme_name']);
        if ($this_extn_theme_i) {
         $enabled_cb_v = true;
         $default_cb_v = ($this_extn_theme_i->default_cb) ? true : false;
         $extn_theme_id_v = $this_extn_theme_i->extn_theme_id;
         $version_v = $this_extn_theme_i->version_number;
        } else {
         $default_cb_v = $enabled_cb_v = $extn_theme_id_v = $version_v = false;
        }
        ?>         
        <tr class="extn_theme_line line_no<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="remove_row_img"><i class='fa fa-minus-circle'></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo ($extn_theme_id_v); ?>"></li>           
           <li><?php echo $count ?></li>
           <?php echo $f->hidden_field('extn_theme_id', $extn_theme_id_v) ?>
          </ul>
         </td>
         <td><?php echo $f->text_field_ap(['name' => 'theme_name', 'value' => $themes['theme_name'], 'size' => '25', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'existing_extn_theme_id', 'value' => $extn_theme_id_v, 'size' => '10', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'description', 'value' => $themes['description'], 'size' => '75', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'version_number', 'value' => $themes['version_number'], 'size' => '10', 'readonly' => 1]) ?></td>
         <td><?php echo $f->checkBox_field('enabled_cb', $enabled_cb_v); ?></td>
         <td><?php echo $f->checkBox_field('default_cb', $default_cb_v); ?></td>
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
        <th>Name</th>
        <th>Developed By</th>
        <th>Developer Email</th>
        <th>Developer Details</th>
       </tr>
      </thead>

      <tbody class="form_data_line_tbody extn_theme_values" >
       <?php
       unset($mod_name);
       $all_data_ai->rewind();
       $all_data_ai->seek($position);
       $count = 1;
       while ($all_data_ai->valid()) {
        $themes = $all_data_ai->current();
        ?>         
        <tr class="extn_theme_line<?php echo $count ?>">
         <td><?php echo $count ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'themen_name2', 'value' => $themes['theme_name'], 'size' => '34', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'developer_name', 'value' => $themes['developer_name'], 'size' => '34', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'developer_email', 'value' => $themes['developer_email'], 'size' => '34', 'readonly' => 1]) ?></td>
         <td><?php echo $f->text_field_ap(['name' => 'developer_details', 'value' => $themes['developer_details'], 'size' => '34', 'readonly' => 1]) ?></td>
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
 <?php echo $pagination->show_pagination(); ?>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_theme" ></li>
  <li class="lineClassName" data-lineClassName="extn_theme" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="obj_class_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="extn_theme_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
