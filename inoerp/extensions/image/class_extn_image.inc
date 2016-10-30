<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * 
 *
 */
class extn_image extends extn_file {

 public static $table_name = "extn_image";
 public static $system_info = [
  'name' => 'image',
  'number' => '10034',
  'description' => 'Image System',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 16
 ];
//  data base variables as stored database column name
 public $field_a = [
  "extn_image_id",
  "file_path",
  "file_name",
  "file_size",
  "file_type",
  'display_type',
  'description',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
//variables used for showing data

 public $checkbox = [];
 public $column = [];
 public $requiredField = ["image_name"];
 protected $_allowedExts = [
  "pdf",
  "doc",
  "docx",
  "jpg",
  'JPG',
  'PNG',
  "png",
  "gif",
  "ppt",
  "pptx",
  "xls",
  "txt",
  "mpg",
  "xlsx",
  "csv"
 ];
 protected $_allowedMimeTypes = [
  'application/msword',
  'application/pdf',
  'image/gif',
  'image/jpeg',
  'image/png',
  'application/mspowerpoint',
  'application/excel',
  'text/plain',
  'audio/mpeg',
  'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
  'application/vnd.openxmlformats-officedocument.presentationml.presentation',
  'application/vnd.ms-excel'
 ];
 public static $primary_column = "extn_image_id";
 protected $_upload_types = ['only_server', 'data_base'];
 protected $_class_name;
 protected $_image_dir;
 protected $_upload_type;
 protected $_max_size = '2097152';

 const MAX_SIZE = '2097152';

 public $extn_image_id;
 public $file_path;
 public $file_name = 'image';
 public $file_size;
 public $file_type;
 public $display_type;
 public $description;
 public $reference_table;
 public $image_reference_id;
 public $reference_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function show_existing_images($image) {
  $f = new inoform();
  $attachment_statement = "<div class=\"existing-image\"><ul class='first_level'>";

  if (!empty($image) && count($image) > 0) {
   if ($image[0]->display_type == 'file') {
    $attachment_statement .= '<li><ul  class="second_level header"><li>Hide</li><li>Delete</li><li>image</li><li></li></ul></li>';
   }
   foreach ($image as $records) {
    switch ($records->display_type) {
     case 'file' :
      $attachment_statement .= '<li><ul class="second_level">';
      $attachment_statement .= '<li><input type="checkbox" class="hide_image" name="hide_image[]" value="' . $records->file_reference_id . '"></li>';
      $attachment_statement .= '<li><input type="checkbox" class="delete_image" name="delete_image[]" value="' . $records->file_reference_id . '"></li>';
      $attachment_statement .= '<li><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
//		$attachment_statement .= '<li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this image" /> </li>';
      $attachment_statement .= '</ul></li>';
      break;

     default:
      $attachment_statement .= '<li><img class="img img-large hidden-image" src="' . HOME_URL. $records->file_path . $records->file_name . '"/></li>';
      $attachment_statement .= '<li class="image-with-text inline"><img  class="img img-medium pos-relative" src="' .HOME_URL. $records->file_path . $records->file_name . '"/>';
      $attachment_statement .= '<span role="button" data-extn_image_reference_id="' . $records->extn_image_reference_id . '" '
       . 'class="delete_image btn btn-danger "  name="delete_extn_image">' . gettext('Delete Image') . '</span></li>';
      $attachment_statement .= '<li>'.$f->text_field('img_description1', $records->img_description1,'','','extra_large','','','Image Description 1').'</li>';
      $attachment_statement .= '<li>'.$f->text_field('img_description2', $records->img_description2,'','','extra_large','','','Image Description 2').'</li>';
      break;
    }
   }
  }

  $attachment_statement .= "</ul></div>";
  return $attachment_statement;
 }

 public static function ino_images($reference_table, $reference_id, $label = 'Image', $display_type = 'extn_image') {
  $images = self::find_by_reference_table_and_id($reference_table, $reference_id);
$stmt = "<div class='existing-image'>" . self::show_existing_images($images) . '</div>';
  $stmt .= '<div class="ino-images">';
  $stmt .= "<div class='show_attachment'>";
  $stmt .= '<div class="form-group">
							<ul class="inRow asperWidth"><label for="exampleInputFile">' . gettext($label) . '</label>
							 <li><input type="file" class="images" value="" name="uploaded_file[]" multiple/></li>
              <li><input type="hidden" class="hidden display_type" name="display_type[]" value="' . $display_type . '"/></li>
							 <li><button  form="file_upload" name="attach_submit" class="submit button upload_file">' . gettext('Upload') . '</button></li>';
  $stmt.='<li class="show_loading_small"><img alt="Loading..." src="' . HOME_URL . 'themes/images/small_loading.gif"/></li>
							</ul>
							<div class="uploaded_file_details"></div>
						 </div>';
  $stmt .= '</div>';
  $stmt .= '</div>';

  return $stmt;
 }
 
public function simple_carousel($div_class="box-54", $show_caption = true) {
  $images = self::find_by_reference_table_and_id($this->reference_table, $this->reference_id);
  if (empty($images)) {
   return;
  }
  $stmt = '<div id="myCarousel" class="carousel slide '.$div_class.' magnify" data-ride="carousel">';
  $stmt .= '<ol class="carousel-indicators">';
  for ($c = 0; $c < count($images); $c++) {
   $active = ($c == 0) ? ' class="active" ' : '';
   $stmt .= '<li data-target="#myCarousel" data-slide-to="' . $c . '" ' . $active . '></li>';
  }
  $stmt .= '</ol>';
  $stmt .= '<div class="carousel-inner" role="listbox">';
  foreach ($images as $d => $records) {
   $active = ($d == 0) ? ' active' : '';
   $stmt .= '<div class="item ' . $active . '">';
   $stmt .= '<div class="large"></div>';
   $stmt .= '<img  class="img img-medium pos-relative small" src="' . HOME_URL . $records->file_path . $records->file_name . '" alt="' . $records->file_name . '" >';
   if($show_caption && !empty($records->img_description1)){
    $stmt .='<div class="carousel-caption">
    <h3>'.$records->img_description1.'</h3>
    <p>'.$records->img_description2.'</p>
  </div>';
   }
   $stmt .= '</div>';
  }
  $stmt .= '</div>';
  $stmt .= '<a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
      </a>
      <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
      </a>';
  $stmt .= '</div>';

  return $stmt;
 }
 
 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
  $sql = "SELECT image.extn_image_id , image.file_path as file_path, 
               image.file_name as file_name,  image.description as description,
               image.display_type as display_type,
							 ir.extn_image_reference_id as extn_image_reference_id,
							 ir.status as status, ir.img_description1,ir.img_description2
       FROM 
       extn_image image , extn_image_reference ir
       WHERE ir.reference_table = '{$reference_table}'
       AND ir.reference_id = '{$reference_id}'
       AND image.extn_image_id = ir.extn_image_id";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function show_image_list(&$image) {

  $attachment_statement = "<div id=\"attachment_list\">";

  if (isset($image) && count($image) > 0) {
   $attachment_statement .= '<ul  class="attachment_list">';
   foreach ($image as $records) {
    $attachment_statement .= '<li><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
   }
   $attachment_statement .= '</ul>';
  }
  $attachment_statement .= "</div>";
  return $attachment_statement;
 }

 public function upload_file($FILES) {
  $errors = [];
  $uploaded_file_ids = [];
  foreach ($FILES as $new_files) {
   $extension_t = explode(".", $new_files["name"]);
   $extension = end($extension_t);
   try {
    $this->check_extension($extension);
   } catch (Exception $e) {
    echo 'Message: ' . $e->getMessage();
   }
   try {
    $this->check_mimetypes($new_files["type"]);
   } catch (Exception $e) {
    echo 'Message: ' . $e->getMessage();
   }

   $date = new DateTime();
   $uploaded_file_name_asis = trim($new_files['name']);
   $uploaded_file_name = preg_replace('/\s+/', '_', $uploaded_file_name_asis);
   $this->file_name = $date->getTimestamp() . '_' . $uploaded_file_name;
   $this->file_size = $new_files['size'];
   $file_tmp = $new_files['tmp_name'];
   $this->file_type = $new_files['type'];

   try {
    $this->check_file_size($this->file_size);
   } catch (Exception $e) {
    echo 'Message: ' . $e->getMessage();
   }

   if (!empty($errors)) {
    pa($errors);
    return;
   }
   if (!is_dir($this->_file_dir)) {
    mkdir("$this->_file_dir", 0777, true); // Create directory if it does not exist
   }
   if (is_dir("$this->_file_dir/" . $this->file_name) == false) {
    $upload_status = move_uploaded_file($file_tmp, "$this->_file_dir/" . $this->file_name);
   } else { //rename the file if another one exist
    $new_dir = "$this->_file_dir/" . $this->file_name . time();
    rename($file_tmp, $new_dir);
   }
//save to data base if in db mode
   if (($upload_status) && ($this->_upload_type == 'data_base')) {
    $fh = fopen("$this->_file_dir/$this->file_name", 'r');
    $data_array = [];
    while (($data = fgetcsv($fh, 3000, ",")) !== FALSE) {
     array_push($data_array, $data);
    }
    $this->mass_upload($data_array, $this->_class_name);
    fclose($fh);
   }

   if (($upload_status) && ($this->_upload_type == 'only_server')) {
    $new_entry = $this->save();
    if ($new_entry == 1) {
     $msg = "File is Successfully uploaded!";
     array_push($uploaded_file_ids, $this->extn_image_id);
     $this->extn_image_id = null;
    } else {
     $msg = "File is Successfully uploaded but record cldnt saved in database";
    }
   }
  }//complete of for loop
  if ((empty($errors)) && (($this->_upload_type == 'only_server'))) {
   if (!empty($uploaded_file_ids)) {
    echo '<div id="uploaded_files_list">';
    foreach ($uploaded_file_ids as $keys => $values) {
     $file = extn_image::find_by_id($values);
     echo '<ul class="inRow asperWidth">';
     echo '<li><button name="remove_file" class="remove_file" >Remove</button></li>';
     if (!empty($this->display_type) && ($this->display_type == 'extn_image')) {
      echo '<li><input type="hidden" name=extn_image_id_values[] class="hidden file_id_values" value="' . $values . '"></li>';
      
     } else {
      echo '<li><input type="hidden" name=file_id_values[] class="hidden file_id_values" value="' . $values . '"></li>';
     }
     echo '<li><img src="' . $file->file_path . $file->file_name . '"/ class="img img-medium"></li>';
     echo '<li><input class="textfield extra_large img_description1" type="text" data-toggle="tooltip" title="" placeholder="Image Description 1" size="" maxlength="256" value="" name="img_description1[]"></input></li>';
      echo '<li><input class="textfield extra_large img_description2" type="text" data-toggle="tooltip" title="" placeholder="Image Description 2" size="" maxlength="256" value="" name="img_description2[]"></input></li>';
     echo '</ul>';
    }
    echo '</div>';
   }
  }
 }

}

//$extn_image = new extn_image();
//$ei = & $extn_image;
//end of image class
?>
