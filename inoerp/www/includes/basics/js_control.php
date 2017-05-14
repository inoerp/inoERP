<?php  require_once 'wloader.inc';
include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc'); ?>
readonly_field='<?php echo strip_tags(gettext('Read Only Field')); ?>'
select_bu_first="<?php echo gettext('Select BU First!'); ?>"
no_period_available_to_open="<?php echo gettext("No period avaibale to open"); ?>"
no_data_found="<?php echo gettext("No Data Found"); ?>"
invalid_value="<?php echo gettext("Invalid Value"); ?>"
invalid_data="<?php echo gettext("Invalid Data"); ?>"
move_line_wo_header="<?php echo !empty($site_info->move_line_wo_header) ? $site_info->move_line_wo_header : ''; ?>"
mandatory_field_color="<?php echo !empty($site_info->mandatory_field_color) ? $site_info->mandatory_field_color : ''; ?>"
content_color="<?php echo !empty($site_info->content_color) ? $site_info->content_color : ''; ?>"
bg_image_path="<?php echo !empty($site_info->bg_image_path) ? $site_info->bg_image_path : ''; ?>"
bg_opacity="<?php echo !empty($site_info->bg_opacity) ? $site_info->bg_opacity : '1'; ?>"
ino_light="<?php echo '#ccc'; ?>"
unsaved_change="<?php echo gettext("Unsaved Change"); ?>"
unsaved_changes="<?php echo gettext("Unsaved Changes"); ?>"