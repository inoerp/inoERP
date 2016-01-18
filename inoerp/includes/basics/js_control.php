<?php 
include_once 'basics.inc';
?>
readonly_field='<?php echo strip_tags(__('Readonly Field')); ?>'
select_bu_first="<?php echo __('Select BU First!'); ?>"
no_period_available_to_open="<?php echo __("No period avaibale to open"); ?>"
no_data_found="<?php echo __("No Data Found"); ?>"
invalid_value="<?php echo __("Invalid Value"); ?>"
invalid_data="<?php echo __("Invalid Data"); ?>"
move_line_wo_header="<?php echo !empty($site_info->move_line_wo_header) ? $site_info->move_line_wo_header : ''; ?>"
mandatory_field_color = 'rgba(233, 209, 234, 0.61)'