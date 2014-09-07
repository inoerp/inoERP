<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="hold_reference_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv">
        <form action=""  method="post" id="sys_hold_reference_line"  name="hold_reference_line"><span class="heading">Hold Basic Info </span>
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column five_column">
              <li>
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_hold_reference_id select_popup clickable">Hold Reference Id  :</label>
               <?php echo $f->text_field_dsr('sys_hold_reference_id'); ?>
               <a name="show" class="show sys_hold_reference clickable"> <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li>
              <li><label>Reference Doc : </label>  <?php echo $f->text_field('reference_table_h', $reference_table_h,'','reference_table','','',1); ?>   </li>
              <li><label>Reference Id : </label>  <?php echo $f->text_field('reference_id_h', $reference_id_h,'','reference_id','','',1); ?>   
               <a name="show" class="show sys_hold_reference_docId clickable"> <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> </li>
             </ul>
            </div>
           </div>
          </div>

         </div>
         <div id="tabsLine">
          <div id ="form_line" class="sys_hold_reference"><span class="heading">Hold Reference </span>
           <ul class="tabMain">
            <li><a href="#tabsLine-1">Basic </a></li>
            <li><a href="#tabsLine-2">Release </a></li>
           </ul>
           <div class="tabContainer"> 

            <div id="tabsLine-1" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th>Action</th>
                <th>Seq#</th>
                <th>Line Id</th>
                <th>Reference Doc</th>
                <th>Reference Id</th>
                <th>Applied By </th>
                <th>Applied On</th>
                <th>Reason</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody hold_reference_values" >
               <?php
                $count = 0;
                foreach ($hold_reference_object as $sys_hold_reference) {
                 ?>         
                 <tr class="hold_reference_line<?php echo $count ?>">
                  <td>    
                   <ul class="inline_action">
                    <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->sys_hold_reference_id); ?>"></li> 
                   </ul>
                  </td>
                  <td><?php $f->seq_field_d($count) ?></td>
                  <td><?php $f->text_field_widsr('sys_hold_reference_id') ?></td>
                  <td><?php $f->text_field_widr('reference_table'); ?></td>
                  <td><?php $f->text_field_widsr('reference_id'); ?></td>
                  <td><?php $f->text_field_widr('hold_applied_by'); ?></td>
                  <td><?php $f->text_field_widr('hold_applied_on'); ?></td>
                  <td><?php $f->text_field_widl('application_reason'); ?></td>
                 </tr>
                 <?php
                 $count = $count + 1;
                }
               ?>
              </tbody>
             </table>
            </div>
            <div id="tabsLine-2" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th>Seq#</th>
                <th>Hole Name </th>
                <th>Description</th>
                <th>Released By </th>
                <th>Released On</th>
                <th>Reason</th>
                <th>Release Hold ?</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody hold_reference_values" >
               <?php
                $sh = sys_hold::find_by_code($hold_reference_object[0]->hold_code);
                $hold_name = $sh->hold_name;
                $description = $sh->description;
                $count = 0;
                foreach ($hold_reference_object as $sys_hold_reference) {
                 ?>         
                 <tr class="hold_reference_line<?php echo $count ?>">
                  <td><?php $f->seq_field_d($count) ?></td>
                  <td><?php echo $f->text_field_ap(array('name' => 'hold_name', 'value' => $hold_name, 'readonly' => 1)) ?></td>
                  <td><?php echo $f->text_field_ap(array('name' => 'description', 'value' => $description, 'readonly' => 1)) ?></td>
                  <td><?php $f->text_field_wid('hold_removed_by'); ?></td>
                  <td><?php $f->text_field_wid('hold_removed_on'); ?></td>
                  <td><?php $f->text_field_wid('removal_reason'); ?></td>
                  <td><?php echo $f->checkBox_field('release_hold_cb', ''); ?></td>
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

      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
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

<?php include_template('footer.inc') ?>