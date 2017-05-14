<div id="form_all">
 <span class="heading"><?php echo gettext('Profile Header') ?></span>
 <form method="post" id="sys_profile_header"  name="sys_profile_header">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('sys_profile_header_id'); ?></li>
       <li><?php $f->l_select_field_from_array('access_level', sys_profile_header::$access_level_a, $$class->access_level); ?></li>
       <li><?php $f->l_text_field_dm('profile_name'); ?> </li>
       <li><?php $f->l_text_field_dm('profile_class_name'); ?> </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_select_field_from_array('profile_level', sys_profile_header::$profile_level_a, $$class->profile_level, 'profile_level'); ?>
        <a name="show" href="form.php?class_name=sys_profile_header&<?php echo "mode=$mode"; ?>" class="show2 document_id sys_profile_header_id">
         <i class="fa fa-refresh"></i></a>
       </li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Profile Values') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Values') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Custom Query') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="sys_profile_line_line"  name="sys_profile_line_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th> 
         <?php
         switch ($profile_level) {
          case 'SITE' :
           echo "<th>Site</th>";
           echo "<th>Value</th>";
           break;

          case 'BUSINESS' :
           echo "<th>Business Org</th>";
           echo "<th>Value</th>";
           break;

          case 'INVENTORY' :
           echo "<th>Inventory Org</th>";
           echo "<th>Value</th>";
           break;

          case 'USER' :
           echo "<th>User Name</th>";
           echo "<th>Value</th>";
           break;


          case 'default':
           echo "<th>Site</th>";
           echo "<th>Value</th>";
           break;
         }
         ?>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody sys_profile_line_values" >
        <?php
        $count = 0;
        $org = new org();
        foreach ($sys_profile_line_object as $sys_profile_line) {
         ?>         
         <tr class="sys_profile_line<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
            <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sys_profile_line->sys_profile_line_id); ?>"></li>           
            <li><?php echo form::hidden_field('sys_profile_header_id', $$class->sys_profile_header_id); ?></li>
            <li><?php echo form::hidden_field('profile_level', $$class->profile_level); ?></li>
           </ul>
          </td>
          <td><?php form::number_field_wid2sr('sys_profile_line_id'); ?></td>
          <?php
          switch ($profile_level) {
           case 'SITE' :
            echo "<td>";
            echo $f->text_field('level_name', 'SITE', '', '', '', 1, 1) . '</td><td>';
            break;

           case 'BUSINESS' :
            echo "<td>";
            echo $f->select_field_from_object('level_name', $org->findAll_business(), 'org_id', 'org', $$class_second->level_name, '', '', 1) . "</td><td>";
            break;

           case 'INVENTORY' :
            echo "<td>";
            echo $f->select_field_from_object('level_name', $org->findAll_inventory(), 'org_id', 'org', $$class_second->level_name, '', '', 1) . "</td><td>";
            break;


           case 'USER' :
            echo '<td>';
            echo $f->select_field_from_object('level_name', ino_user::find_all(), 'user_id', 'username', $$class_second->level_name, '', '', 1) . "</td><td>";
            break;
          }
          if (empty($line_values)) {
           echo $f->text_field_wid2('level_value') . '</td>';
          } else {
           echo $f->select_field_from_object('level_value', $line_values, $line_key, $line_desc, $$class_second->level_value, '', '', '') . "</td>";
          }
          ?>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
     </div>
    </form>
   </div>

  </div>
 </div> 
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_profile_header" ></li>
  <li class="lineClassName" data-lineClassName="sys_profile_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_profile_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_profile_header" ></li>
  <li class="line_key_field" data-line_key_field="level_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sys_profile_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_profile_header_id" ></li>
  <li class="docLineId" data-docLineId="sys_profile_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_profile_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="sys_profile_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>