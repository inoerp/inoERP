<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_overhead_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all"><span class="heading">Over Head</span>
       <form action=""  method="post" id="bom_overhead"  name="bom_overhead">
        <div id ="form_header">
         <div id="tabsHeader">
          <div class="large_shadow_box">
           <ul class="column five_column">
            <li>
             <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_overhead_id select_popup clickable">
              Overhead Id : </label>
             <?php echo $f->text_field_dr('bom_overhead_id'); ?>
             <a name="show" class="show bom_overhead_id_show">
              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </li>
            <li><label>Inventory (1): </label>
             <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
            </li>
            <li><label>Overhead (2): </label>
             <?php echo form::text_field_d('overhead'); ?>
            </li>
            <li><label>Description : </label>
             <?php echo form::text_field_d('description'); ?>
            </li>
            <li><label>Overhead Type : </label>
             <?php echo form::select_field_from_object('overhead_type', bom_header::bom_overhead_type(), 'option_line_code', 'option_line_value', $$class->overhead_type, 'overhead_type', $readonly, 'overhead_type'); ?>
            </li>
            <li><label>Default Basis : </label>
             <?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class->default_basis, 'default_basis', $readonly, 'default_basis'); ?>
            </li>
            <li><label>Ef Id : </label>
             <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
            </li>
            <li><label>Status : </label>                      
             <?php echo form::status_field($$class->status, $readonly); ?>
            </li>
            <li><label>Absorption Ac: </label><?php $f->ac_field_d('absorption_ac_id'); ?></li>
           </ul>
          </div>

         </div>
        </div>
       </form>
       <span class="heading"> Over Head Details </span>
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">Resource Assignment</a></li>
         <li><a href="#tabsLine-2">Rate Assignment</a></li>
        </ul>
        <div class="tabContainer"> 
         <div id="tabsLine-1" class="tabContent">
          <div id ="form_line" class="form_line">
           <form action=""  method="post" id="bom_overhead_resource_assignment_line"  name="bom_overhead_resource_assignment_line">
            <table class="form_line_data_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Resource Assignment Id</th>
               <th>Cost Type</th>
               <th>Description</th>
               <th>Resource</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody bom_overhead_resource_assignment_values" >
              <?php
               $count = 0;
               foreach ($bom_overhead_resource_assignment_object as $bom_overhead_resource_assignment) {
                if (!empty($bom_overhead_resource_assignment->bom_cost_type)) {
                 $bcy = new bom_cost_type();
                 $bcy_i = $bcy->find_by_keyColumn($bom_overhead_resource_assignment->bom_cost_type);
                 $bom_overhead_resource_assignment->bom_cost_type_description = $bcy_i->description;
                } else {
                 $bom_overhead_resource_assignment->bom_cost_type_description = null;
                }
                ?>         
                <tr class="bom_overhead_resource_assignment<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($bom_overhead_resource_assignment->bom_overhead_resource_assignment_id); ?>"></li>           
                   <li><?php echo form::hidden_field('bom_overhead_id', $$class->bom_overhead_id); ?></li>
                  </ul>
                 </td>
                 <td><?php form::text_field_wid2('bom_overhead_resource_assignment_id'); ?></td>
                 <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->bom_cost_type, '', '', 1, $readonly); ?></td>
                 <td><?php $f->text_field_wid2r('bom_cost_type_description'); ?></td>
                 <td>
                  <?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_second->resource_id, '', $readonly, 'resource_id'); ?>
                 </td>
                </tr>
                <?php
                $count = $count + 1;
               }
              ?>
             </tbody>
            </table>
           </form>
          </div>
         </div> 

         <div id="tabsLine-2" class="tabContent">
          <div id ="form_line2" class="form_line2">
           <form action=""  method="post" id="bom_overhead_rate_assignment_line"  name="bom_overhead_rate_assignment_line">
            <table class="form_line_data_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Rate Assignment Id</th>
               <th>Cost Type</th>
               <th>Default Basis</th>
               <th>Rate</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody2 bom_overhead_rate_assignment_values" >
              <?php
               $count = 0;
               foreach ($bom_overhead_rate_assignment_object as $bom_overhead_rate_assignment) {
                $class_third = 'bom_overhead_rate_assignment';
                $$class_third = & $bom_overhead_rate_assignment;
                ?>         
                <tr class="bom_overhead_rate_assignment<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($bom_overhead_rate_assignment->bom_overhead_rate_assignment_id); ?>"></li>           
                   <li><?php echo form::hidden_field('bom_overhead_id', $$class->bom_overhead_id); ?></li>
                  </ul>
                 </td>
                 <td><?php form::text_field_wid3('bom_overhead_rate_assignment_id'); ?></td>
                 <td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_third->bom_cost_type, '', '', 1, $readonly); ?></td>
                 <td><?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->default_basis, '', $readonly, 'default_basis'); ?> </td>
                 <td><?php form::text_field_wid3('rate'); ?></td>
                </tr>
                <?php
                $count = $count + 1;
               }
              ?>
             </tbody>
            </table>
           </form>
          </div>
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
