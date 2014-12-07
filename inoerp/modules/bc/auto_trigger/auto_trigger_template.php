<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="sys_profile_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> <?php $f = new inoform(); ?>
      <!--    End of place for showing error messages-->
      <div id="form_all"><span class="heading">Bar code Label Auto Trigger </span>
       <form action=""  method="post" id="sys_auto_trigger"  name="sys_auto_trigger">
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column">
              <li><label>Transaction Type : </label>
               <?php echo $f->select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $transaction_type_id, 'transaction_type_id', ''); ?>
              </li>
              <li><label>Association Level : </label>
               <?php echo $f->select_field_from_array('association_level', bc_auto_trigger::$association_level_a, $$class->association_level, 'association_level'); ?>
               <a name="show" class="show sys_association_level clickable"> <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li>
             </ul>
            </div>
           </div>
          </div>
         </div>
        </div>
       </form>
       <div id ="form_line" class="form_line"><span class="heading">Label Association </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Values</a></li>
         </ul>
         <div class="tabContainer"> 
          <form action=""  method="post" id="bc_auto_trigger_line"  name="bc_auto_trigger_line">
           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Line Id</th> 
               <th>Default Printer</th> 
               <?php
               switch ($association_level) {
                case 'SITE' :
                 echo "<th>Site</th>";
                  break;

                case 'BUSINESS' :
                 echo "<th>Business Org</th>";
                 break;

                case 'INVENTORY' :
                 echo "<th>Inventory Org</th>";
                 break;

                case 'USER' :
                 echo "<th>User Name</th>";
                 break;

                default :
                 echo "<th>Multi Level</th>";
                 break;
               }
               ?>
               <th>Label Format </th> 
              </tr>
             </thead>
             <tbody class="form_data_line_tbody bc_auto_trigger_values" >
              <?php
              $count = 0;
              $org = new org();
              foreach ($bc_auto_trigger_object as $bc_auto_trigger) {
               ?>         
               <tr class="bc_auto_trigger<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($bc_auto_trigger->bc_label_auto_trigger_id); ?>"></li>           
                  <li><?php echo form::hidden_field('transaction_type_id', $transaction_type_id); ?></li>
                  <li><?php echo form::hidden_field('association_level', $association_level); ?></li>
                 </ul>
                </td>
                <td><?php form::number_field_widsr('bc_label_auto_trigger_id'); ?></td>
                <td><?php echo $f->select_field_from_object('sys_printer_id', sys_printer::find_all(), 'sys_printer_id', 'printer_name', $$class->sys_printer_id) ?></td>
                <td>
                 <?php
                 $association_level = empty($bc_auto_trigger->association_level) ? $association_level : $bc_auto_trigger->association_level;
                 switch ($association_level) {
                  case 'SITE' :
                   echo $f->text_field('association_level_value', 'SITE', '', '', '', 1, 1);
                   break;

                  case 'BUSINESS' :
                   echo $f->select_field_from_object('association_level_value', $org->findAll_business(), 'org_id', 'org', $$class->association_level_value, '', '', 1);
                   break;

                  case 'INVENTORY' :
                   echo $f->select_field_from_object('association_level_value', $org->findAll_inventory(), 'org_id', 'org', $$class->association_level_value, '', '', 1);
                   break;


                  case 'USER' :
                   echo $f->select_field_from_object('association_level_value', user::find_all(), 'user_id', 'username', $$class->association_level_value, '', '', 1);
                   break;
                 }
                 ?>
                </td>
                <td>
                 <?php
                 echo $f->select_field_from_object('bc_label_format_header_id', bc_label_format_header::find_all(), 'bc_label_format_header_id', 'format_name', $$class->bc_label_format_header_id, '', '', 1) . "</td>";
                 ?>
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
           </div>
          </form>
         </div>

        </div>
       </div> 
      </div>
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>