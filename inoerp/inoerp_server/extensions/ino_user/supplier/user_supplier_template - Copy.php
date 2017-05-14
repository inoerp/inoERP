<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="user_supplier_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
      echo (!empty($show_message)) ? $show_message : "";
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv"><h1 class="error"><?php echo gettext('Not availabe for your product. Use supplier @ user level') ?></h1>
        <form method="post" id="user_supplier_line"  name="user_supplier_line"><span class="heading"><?php echo gettext('User Basic Info') ?> </span>
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column header_field">
              <li><?php
               echo $f->l_val_field_d('username', 'ino_user', 'username', '', 'vf_select_user username');
               echo $f->hidden_field_withId('user_id', $user_id_h);
               ?><i class="generic g_select_lead_employee_name select_popup clickable fa fa-search" data-class_name="ino_user"></i>
              <i class="fa fa-refresh"></i></li>
              <li><label><?php echo gettext('First Name') ?></label>	<?php echo $f->text_field_d('first_name'); ?> </li>
              <li><label><?php echo gettext('Last Name') ?></label><?php echo $f->text_field_d('last_name'); ?>	 </li> 
             </ul>
            </div>
           </div>
          </div>

         </div>
         <div id="tabsLine">
          <div id ="form_line" class="user_supplier"><span class="heading"><?php echo gettext('User Supplier Association') ?> </span>
           <ul class="tabMain">
            <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?> </a></li>
            <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
           </ul>
           <div class="tabContainer"> 

            <div id="tabsLine-1" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th><?php echo gettext('Action') ?></th>
                <th><?php echo gettext('Seq') ?>#</th>
                <th><?php echo gettext('User Supplier Id') ?></th>
                <th><?php echo gettext('Supplier Id') ?></th>
                <th><?php echo gettext('Supplier Name') ?></th>
                <th><?php echo gettext('Supplier Site') ?></th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody user_supplier_values" >
               <?php
               $count = 0;
               foreach ($user_supplier_object as $user_supplier) {
                if (!empty($$class->supplier_id)) {
                 $sup = new supplier();
                 $sup->findBy_id($$class->supplier_id);
                 $$class->supplier_name = $sup->supplier_name;
                 $supplier_site = supplier_site::find_by_id($$class->supplier_site_id);
                 $supplier_site_obj = [];
                 if ($supplier_site) {
                  array_push($supplier_site_obj, $supplier_site);
                  $supplier_site_name_statement = $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, '', 'supplier_site_id', '', $readonly);
                 } else {
                  $supplier_site_obj = supplier_site::find_by_parent_id($$class->supplier_id);
                  $supplier_site_name_statement = $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, '', 'supplier_site_id', '', $readonly);
                 }
                } else {
                 $$class->supplier_name = null;
                 $supplier_site_name_statement = form::text_field('supplier_site_id', $$class->supplier_site_id);
                }
                ?>         
                <tr class="user_supplier_line<?php echo $count ?>">
                 <td><?php echo ino_inline_action($$class->user_supplier_id, array('user_id' => $user_id_h)); ?>  </td>
                 <td><?php $f->seq_field_d($count) ?></td>
                 <td><?php $f->text_field_widsr('user_supplier_id') ?></td>
                 <td><?php $f->text_field_widr('supplier_id'); ?></td>
                 <td><?php $f->text_field_widm('supplier_name', 'select_supplier_name'); ?>
                  <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_supplier_name select_popup clickable"></td>
                 <td><?php echo $supplier_site_name_statement; ?></td>
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
           </div>

          </div>
         </div> 
        </form>
       </div>
      </div>
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of coa_structure_id-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>
