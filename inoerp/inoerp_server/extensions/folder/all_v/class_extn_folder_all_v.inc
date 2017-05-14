<?php

class extn_folder_all_v extends extn_folder {

 public static $table_name = "extn_folder_all_v";
 public static $primary_column = "extn_folder_id";
 public static $form_class_name = "extn_folder_all_v";
 public static $system_info = [
		 'name' => 'Folder All View',
		 'number' => '2220',
		 'description' => 'View for all Folder Information',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'extn',
		 'weight' => 1
 ];
 public $field_a = [
		 'extn_file_id',
		 'file_path',
		 'file_name',
		 'extn_folder_id',
		 'description',
		 'creation_date',
		 'display_type',
		 'file_reference_id',
		 'status',
		 'major_extn_folder_id',
		 'parent_id',
		 'folder',
		 'folder_type',
		 'org',
		 'reference_table',
		 'reference_id',
		 'org_id'
 ];
 public $initial_search = [
		 'description',
		 'display_type',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
		 '_update_path' => 'form.php?class_name=extn_folder',
		 '_view_path' => 'form.php?class_name=extn_folder',
 ];
 public $pageTitle = " Folder "; //page Title
 public $extn_file_id;
 public $file_path;
 public $file_name;
 public $creation_date;
 public $extn_folder_id;
 public $description;
 public $display_type;
 public $file_reference_id;
 public $reference_table;
 public $reference_id;
 public $status;
 public $major_extn_folder_id;
 public $parent_id;
 public $folder;
 public $folder_type;
 public $org;
 public $org_id;

 private function create_extn_folder_all_v() {
	$sql = "
CREATE OR REPLACE VIEW extn_folder_all_v
(
extn_file_id, file_path, creation_date,
file_name, extn_folder_id, 
description,display_type,
reference_table,reference_id,
file_reference_id, status,
major_extn_folder_id, parent_id,
folder, folder_type, org, org_id
)
AS
SELECT extn_file.extn_file_id, extn_file.file_path, extn.file_creation_date,
extn_file.file_name, extn_file.extn_folder_id, 
extn_file.description,extn_file.display_type,
file_reference.reference_table,file_reference.reference_id,
file_reference.file_reference_id, file_reference.status,
extn_folder.major_extn_folder_id, extn_folder.parent_id,
extn_folder.folder, extn_folder.folder_type, org.org, org.org_id
FROM 
extn_file
LEFT JOIN file_reference ON file_reference.file_id = extn_file.extn_file_id 
LEFT JOIN extn_folder ON extn_folder.extn_folder_id = extn_file.extn_folder_id
LEFT JOIN org ON extn_folder.extn_folder_id = org.org_id

";
 }



}

//end of extn_folder_detail class
?>