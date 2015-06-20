<table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Resource Class') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Rate') ?></th>
        <th><?php echo gettext('Markup') ?></th>
        <th><?php echo gettext('From Date') ?></th>
        <th><?php echo gettext('To Date') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_rate_schedule_line_object as $prj_rate_schedule_line) {
        ?>         
        <tr class="prj_rate_schedule_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_rate_schedule_line->prj_rate_schedule_line_id, array('prj_rate_schedule_header_id' => $prj_rate_schedule_header->prj_rate_schedule_header_id,
           'reference_key_name' => $$class->rate_type));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('prj_rate_schedule_line_id', 'always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_object('reference_key_value', prj_rate_schedule_line::resource_class(), 'option_line_code', 'option_line_value', $$class_second->reference_key_value, '', 'reference_key_value'); ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id); ?></td>
         <td><?php $f->text_field_d2('rate'); ?></td>
         <td><?php $f->text_field_d2('mark_up_percentage'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_from', $$class_second->effective_from); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_to', $$class_second->effective_to); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>