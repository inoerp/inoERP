<?php include_once("option.inc"); ?>

<div id="structure">
    <div id="option"><div id="option_details">
            <h2>All Option Headers </h2>
                      
             <?php
             echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>Option Id</th>
                    <th>Access Level</th>
                    <th>Type</th>
                    <th>Description</th>
                    <th>Module</th>
                    <th>efid</th>
                    <th>Status</th>
                    <th>Rev Enabled</th>
                    <th>Rev No</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Updated By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>' ;
             
             $option = option_header::find_all_headers();
//             echo '<pre>';
//             print_r($option);
//             echo '<pre>';
              foreach($option as $record){
               echo '<tr><td>'. $record->option_id. '</td>';
               echo '<td>'. $record->access_level. '</td>';
               echo '<td><a href="option.php?option_id_l='. $record->option_id.'"/>'.$record->option_type .'</a>' .'</td>';
               echo '<td>'. $record->description . '</td> ';
               echo '<td>'. $record->module . '</td>';
               echo '<td>'. $record->efid . '</td>';
               echo '<td>'. $record->status . '</td>';
               echo '<td>'. $record->rev_enabled . '</td>';
               echo '<td>'. $record->rev_number . '</td>';
               echo '<td>'. $record->created_by . '</td>';
               echo '<td>'. $record->creation_date . '</td> ';
               echo '<td>'. $record->last_update_by . '</td>';
               echo '<td>'. $record->last_update_date . '</td>';
               echo '<td><a href="option.php?option_id_l='. $record->option_id .'">Update</a></td></tr>'  ;
               }
               
               echo ' </tbody> </table>';
               ?>   
           
<!--            end of table-->
        </div></div>
    <p><br/>
              
  </div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
