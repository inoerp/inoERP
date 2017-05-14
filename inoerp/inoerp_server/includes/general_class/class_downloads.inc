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
  $stmt .= "<input type='hidden'  name='download_format[]' value=\"excel_format\">";
	$stmt .= "<input type='submit'  name=\"$this->_submit_form_name\" form=\"$this->_submit_form_name\" value=\"$this->_submit_button_value\">";
	$stmt .= '</form></div>';
	return $stmt;
 }
 
 public static function show_download_button($result_data) {
 $return_stmt = '<div id="searchResultMessages">';
 $return_stmt .='<ul class="inline_list"><li>';
 $return_stmt .='<h3>' . gettext('Total Records') . ' : ' . count($result_data) . '</h3></li>';
 $return_stmt .= '<li>';
 $result_data_all = json_decode(json_encode($result_data), true);
 $return_stmt .= '<form action="' . HOME_URL . 'download.php"  method="POST" name="download_all" id="download_all" target="_blank">';
 $return_stmt .= '<input type="hidden"  name="data" value="' . base64_encode(serialize($result_data_all)) . '" >';
 $return_stmt .= '<input type="radio" name="download_format" checked="checked" value="excel_format">' . gettext('Excel') . ' ' . '
     <input type="radio" name="download_format" value="text_format">' . gettext('Text') . '
     <input type="radio" name="download_format" value="pdf_format">' . gettext('Pdf') . '
     <input type="radio" name="download_format" value="xml_format">' . gettext('XML') . '
     <input type="radio" name="download_format" value="worddoc_format">' . gettext('Word Doc') . '
     <input type="submit"  name="export_allResult" value="' . gettext('Download') . '" id="export_excel_allResult" class="clickable button"  >
    </form></li>';
 $return_stmt .= '<li id="export_excel_searchResult" class="clickable" title="' . gettext('Export to Excel') . '"><i class="fa fa-file-excel-o"></i></li>
  <li id="print_searchResult" class="print clickable" title="' . gettext('Print') . '"><i class="fa fa-print"></i></li>
</ul>
</div>';
 return $return_stmt;
}

public static function show_download_button_inSelectFormat($result_data, $total_count = 0, $total_count_all = 0) {
 global $f;
 $return_stmt = '<div id="searchResultMessages">';
 $return_stmt .='<ul class="inline_list">';
 $return_stmt .= '<li>';
 $result_data_all = json_decode(json_encode($result_data), true);
 $return_stmt .= '<form action="' . HOME_URL . 'download.php"  method="POST" name="download_all" id="download_all" target="_blank">';
 $return_stmt .= '<input type="hidden"  name="data" value="' . base64_encode(serialize($result_data_all)) . '" >';
 $return_stmt .= $f->select_field_from_array('download_format', dbObject::$download_format, 'excel_format');
 $return_stmt .= '<input type="submit"  role="button" name="export_allResult" value="' . gettext('Download') . '" id="export_excel_allResult" class="clickable btn btn-sm btn-default"  >';
 $return_stmt .= '</form></li>';
 $return_stmt .= '<li id="export_excel_searchResult" class="clickable"  title="' . gettext('Export to Excel') . '"><i class="fa fa-file-excel-o"></i></li>
  <li id="print_searchResult" class="print clickable" title="' . gettext('Print') . '"><i class="fa fa-print"></i></li>';
 if (!empty($total_count)) {
  $return_stmt .= '  <li><button class="btn btn-primary" type="button">' . gettext('Accessible Records') .'<span class="badge">' . $total_count . '</span></button></li>
    <li><button class="btn btn-warning" type="button">' . gettext('Total Records') . ' ' .'<span class="badge">' . $total_count_all . '</span></button></li>';
 }

 $return_stmt .='</ul>
</div>';
 return $return_stmt;
}

}

//end of forma class
?>
