<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="approval_limit_assignment_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv">
        <form action=""  method="post" id="hr_approval_limit_assignment_line"  name="approval_limit_assignment_line"><span class="heading">Approval Limit Assignment </span>
         <div id="tabsLine">
          <table class="form_table">
           <tr><td>
             <label>Position :</label>
             <?php echo $f->select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $position_id_h, 'position_id', $readonly1); ?>
            </td>
           <td>
             <label>Job :</label>
             <?php echo $f->select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $job_id_h, 'job_id', $readonly1); ?>
            </td>
           <td>
             <label>BU Org :</label>
             <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $bu_org_id_h, 'bu_org_id', $readonly1); ?>
             <a name="show" class="show hr_approval_limit_assignment clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </td></tr>
          </table>
          <div id ="form_line" class="hr_approval_limit_assignment">
           <ul class="tabMain">
            <li><a href="#tabsLine-1">Basic </a></li>
            <li><a href="#tabsLine-2">Future </a></li>
           </ul>
           <div class="tabContainer"> 

            <div id="tabsLine-1" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th>Action</th>
                <th>Seq#</th>
                <th>Id</th>
                <th>Document Type</th>
                <th>Approval Limit</th>
                <th>Start Date </th>
                <th>End Date</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody approval_limit_assignment_values" >
               <?php
                $count = 0;
                foreach ($approval_limit_assignment_object as $hr_approval_limit_assignment) {
                 ?>         
                 <tr class="approval_limit_assignment_line<?php echo $count ?>">
                  <td>    
                   <ul class="inline_action">
                    <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->hr_approval_limit_assignment_id); ?>"></li> 
                    <li><?php echo $f->hidden_field('bu_org_id', $bu_org_id_h); ?>
                     <?php echo $f->hidden_field('job_id', $job_id_h); ?>
                    <?php echo $f->hidden_field('position_id', $position_id_h); ?></li>

                   </ul>
                  </td>
                  <td><?php $f->seq_field_d($count) ?></td>
                  <td><?php $f->text_field_widsr('hr_approval_limit_assignment_id') ?></td>
                  <td><?php echo $f->select_field_from_object('document_type', option_header::document_types(), 'option_line_code', 'option_line_value', $$class->document_type, '', '', 1, $readonly); ?></td>
                  <td><?php echo $f->select_field_from_object('hr_approval_limit_header_id', hr_approval_limit_header::find_all(), 'hr_approval_limit_header_id', 'limit_name', $$class->hr_approval_limit_header_id, '', '', 1, $readonly); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('end_date', $$class->end_date); ?></td>
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
                <th>BU Org Id </th>
                <th>Job Id</th>
                <th>Position Id</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody approval_limit_assignment_values" >
               <?php
                $count = 0;
                foreach ($approval_limit_assignment_object as $hr_approval_limit_assignment) {
                 ?>         
                 <tr class="approval_limit_assignment_line<?php echo $count ?>">
                  <td><?php $f->seq_field_d($count) ?></td>
                    <td><?php echo  $$class->bu_org_id; ?></td>
                    <td><?php echo  $$class->job_id; ?></td>
                    <td><?php echo  $$class->position_id; ?></td>
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