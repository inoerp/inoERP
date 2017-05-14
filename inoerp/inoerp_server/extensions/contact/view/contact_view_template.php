<?php
$ref_stmt = '';
if (empty($all_contacts)) {
 return;
} else {
 $reference_table = !empty($_SESSION['comment_reference_table']) ? $_SESSION['comment_reference_table'] : '';
 $reference_id = !empty($_SESSION['comment_reference_id']) ? $_SESSION['comment_reference_id'] : '';
 $ref_stmt = "&reference_table=$reference_table&reference_id=$reference_id";
 unset($_SESSION['comment_reference_table']);
 unset($_SESSION['comment_reference_id']);
}
?>
<div class="tabsDetail">
 <ul class="tabMain">
  <li class="tabLink"><a href="#tabsDetail-1"><?php echo gettext('Basic')?></a></li>
  <li class="tabLink"><a href="#tabsDetail-2"><?php echo gettext('Others')?></a></li>
 </ul>
 <div class="tabContainer">
  <div id="tabsDetail-1" class="tabContent">
   <table class="form form_detail_data_table detail">
    <thead>
     <tr>
      <th><?php echo gettext('Action')?></th>
      <th><?php echo gettext('Seq')?>#</th>
      <th><?php echo gettext('Contact Name')?></th>
      <th><?php echo gettext('Last Name')?></th>
      <th><?php echo gettext('First Name')?></th>
      <th><?php echo gettext('Middle Name')?></th>
      <th><?php echo gettext('Email')?></th>
      <th><?php echo gettext('Job Title')?></th>
      <th><?php echo gettext('Contact Type')?></th>
      <th><?php echo gettext('Mobile')?></th>
     </tr>
    </thead>
    <tbody class="form_data_detail_tbody">
     <?php
     $detailCount = 0;
     foreach ($all_contacts as $cont) {
      ?>
      <tr class="extn_contact<?php echo $detailCount; ?>">
       <td>   
        <ul class="inline_action">
         <li class="send_email"><a target="_blank" class="contact_link" 
                                   href="form.php?class_name=web_mail&window_type=popup&<?php echo 'email=' . $cont->email_id . $ref_stmt; ?>">
           <i class="fa fa-envelope-o clickable"></i></a></li>
         <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
         <li class="clickable delete_ref" data-delete_id = "<?php echo htmlentities($cont->extn_contact_reference_id); ?>"><i class="fa fa-trash-o"></i></li>
        </ul>
       </td>
       <td><?php $f->seq_field_detail_d($detailCount) ?></td>
       <td><?php
        echo $f->hidden_field('extn_contact_id', $cont->extn_contact_id);
        echo $f->text_field('contact_name', $cont->contact_name);
        ?> 					</td>
       <td><?php echo $f->text_field('last_name', $cont->last_name, '', '', 'medium'); ?> 					</td>
       <td><?php echo $f->text_field('first_name', $cont->last_name, '', '', 'medium'); ?> 					</td>
       <td><?php echo $f->text_field('middle_name', $cont->middle_name, '', '', 'medium'); ?> 					</td>
       <td><?php echo $f->text_field('email_id', $cont->email_id, '', '', 'medium'); ?> 					</td>
       <td><?php echo $f->text_field('job_titile', $cont->job_titile, '', '', 'medium'); ?> 					</td>
       <td><?php echo $f->text_field('type', $cont->type); ?> 					</td>
       <td><?php echo $f->text_field('mobile_number', $cont->mobile_number, '', '', 'medium'); ?> 					</td>
      </tr>
      <?php
      $detailCount++;
     }
     ?>
    </tbody>
   </table>
  </div>
  <div id="tabsDetail-2" class="tabContent">
   <table class="form form_detail_data_table detail">
    <thead>
     <tr>
      <th><?php echo gettext('Seq')?>#</th>
      <th><?php echo gettext('Office')?></th>
      <th><?php echo gettext('Phone 2')?></th>
      <th><?php echo gettext('Fax')?></th>
      <th><?php echo gettext('Alternate e-Mail')?></th>
      <th><?php echo gettext('Time Zone')?></th>
      <th><?php echo gettext('Preferred Time')?></th>
     </tr>
    </thead>
    <tbody class="form_data_detail_tbody">
     <?php
     $detailCount = 0;
     foreach ($all_contacts as $cont) {
      ?>
      <tr class="extn_contact<?php echo $detailCount; ?> ">
       <td><?php echo $f->seq_field_detail_d($detailCount) ?></td>
       <td><?php echo $f->text_field('office_number', $cont->office_number); ?> 					</td>
       <td><?php echo $f->text_field('contact_number2', $cont->contact_number2); ?> 					</td>
       <td><?php echo $f->text_field('fax_no', $cont->fax_no); ?> 					</td>
       <td><?php echo $f->text_field('email_id2', $cont->email_id2); ?> 					</td>
       <td><?php echo $f->text_field('timezone', $cont->timezone); ?> 					</td>
       <td><?php echo $f->text_field('time_to_contact', $cont->time_to_contact); ?> 					</td>      
      </tr>
      <?php
      $detailCount++;
     }
     ?>
    </tbody>
   </table>
  </div>
 </div>
</div>
