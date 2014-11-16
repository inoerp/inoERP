<?php

class downloads {

 private $_downloaded_data;
 private $_submit_form_name = 'download_all';
 private $_submit_button_value = 'Download';
 private $_submit_button_path = false;
 private $_submit_action_url = 'download.php';

 public function setProperty($property, $value) {
	if (property_exists($this, $property)) {
	 switch ($property) {
		case '_module':
		 $this->$property = !empty($value) ? _downloaded_data : 'No data to download';

		default:
		 $this->$property = $value;
		 break;
	 }
	}
 }

 public function show_download_form() {
	$value = base64_encode(serialize($this->_downloaded_data));
	$stmt = '<div class="submit_form">';
	$stmt .= "<form action='" . HOME_URL . $this->_submit_action_url . "' method=\"POST\" name=\"$this->_submit_form_name\" id=\"$this->_submit_form_name\">";
	$stmt .= "<input type='hidden'  name='data' value=\"$value\">";
  $stmt .= "<input type='hidden'  name='download_format' value=\"excel_format\">";
	$stmt .= "<input type='submit'  name=\"$this->_submit_form_name\" form=\"$this->_submit_form_name\" value=\"$this->_submit_button_value\">";
	$stmt .= '</form></div>';
	return $stmt;
 }

}

//end of forma class
?>