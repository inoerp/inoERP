<?php

class ino_doc {

 public $current_page;
 private $_title = 'inoERP Doc';
 private $_author = 'No Author';
 private $_last_author = 'No Last Author';
 public $per_page;
 public $_current_page_no;

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_show_update_path':
     $this->$property = !empty($value) ? true : false;

    case '_show_view_path':
     $this->$property = !empty($value) ? true : false;

    case '_form_name':
     $this->$property = $value;

    case '_result':
     $this->$property = is_array($value) ? $value : false;


    default:
     $this->$property = $value;
     break;
   }
  }
 }

 private function _generate_pre_body() {
  $pre_body = '<?xml version="1.0" encoding="utf-8" standalone="yes"?>
<?mso-application progid="Word.Document"?>
<w:wordDocument
   xmlns:w="http://schemas.microsoft.com/office/word/2003/wordml"
   xmlns:wx="http://schemas.microsoft.com/office/word/2003/auxHint"
   xmlns:o="urn:schemas-microsoft-com:office:office"
   w:macrosPresent="no"
   w:embeddedObjPresent="no"
   w:ocxPresent="no"
   xml:space="preserve">
  <o:DocumentProperties>
    <o:Title>' . $this->_title . '</o:Title>
    <o:Author>' . $this->_author . '</o:Author>
    <o:LastAuthor>' . $this->_last_author . '</o:LastAuthor>
    <o:Revision>1</o:Revision>
    <o:TotalTime>0</o:TotalTime>
    <o:Created>' . current_time() . '</o:Created>
    <o:LastSaved>' . current_time() . '</o:LastSaved>
    <o:Pages>1</o:Pages>
    <o:Words>6</o:Words>
    <o:Characters>40</o:Characters>
    <o:Company>SCO Group, Inc.</o:Company>
    <o:Lines>1</o:Lines>
    <o:Paragraphs>1</o:Paragraphs>
    <o:CharactersWithSpaces>45</o:CharactersWithSpaces>
    <o:Version>11.6359</o:Version>
  </o:DocumentProperties>
  <w:fonts>
    <w:defaultFonts
       w:ascii="Times New Roman"
       w:fareast="Times New Roman"
       w:h-ansi="Times New Roman"
       w:cs="Times New Roman" />
  </w:fonts>
  <w:styles>
    <w:versionOfBuiltInStylenames w:val="4" />
    <w:latentStyles w:defLockedState="off" w:latentStyleCount="156" />
    <w:style w:type="paragraph" w:default="on" w:styleId="Normal">
      <w:name w:val="Normal" />
      <w:rPr>
        <wx:font wx:val="Times New Roman" />
        <w:sz w:val="24" />
        <w:sz-cs w:val="24" />
        <w:lang w:val="EN-US" w:fareast="EN-US" w:bidi="AR-SA" />
      </w:rPr>
    </w:style>
    <w:style w:type="paragraph" w:styleId="Heading1">
      <w:name w:val="heading 1" />
      <wx:uiName wx:val="Heading 1" />
      <w:basedOn w:val="Normal" />
      <w:next w:val="Normal" />
      <w:rsid w:val="00D93B94" />
      <w:pPr>
        <w:pStyle w:val="Heading1" />
        <w:keepNext />
        <w:spacing w:before="240" w:after="60" />
        <w:outlineLvl w:val="0" />
      </w:pPr>
      <w:rPr>
        <w:rFonts w:ascii="Arial" w:h-ansi="Arial" w:cs="Arial" />
        <wx:font wx:val="Arial" />
        <w:b />
        <w:b-cs />
        <w:kern w:val="32" />
        <w:sz w:val="32" />
        <w:sz-cs w:val="32" />
      </w:rPr>
    </w:style>
    <w:style w:type="character" w:default="on" w:styleId="DefaultParagraphFont">
      <w:name w:val="Default Paragraph Font" />
      <w:semiHidden />
    </w:style>
    <w:style w:type="table" w:default="on" w:styleId="TableNormal">
      <w:name w:val="Normal Table" />
      <wx:uiName wx:val="Table Normal" />
      <w:semiHidden />
      <w:rPr>
        <wx:font wx:val="Times New Roman" />
      </w:rPr>
      <w:tblPr>
        <w:tblInd w:w="0" w:type="dxa" />
        <w:tblCellMar>
          <w:top w:w="0" w:type="dxa" />
          <w:left w:w="108" w:type="dxa" />
          <w:bottom w:w="0" w:type="dxa" />
          <w:right w:w="108" w:type="dxa" />
        </w:tblCellMar>
      </w:tblPr>
    </w:style>
    <w:style w:type="list" w:default="on" w:styleId="NoList">
      <w:name w:val="No List" />
      <w:semiHidden />
    </w:style>
  </w:styles>
  <w:docPr>
    <w:view w:val="print" />
    <w:zoom w:percent="100" />
    <w:doNotEmbedSystemFonts />
    <w:proofState w:spelling="clean" w:grammar="clean" />
    <w:attachedTemplate w:val="" />
    <w:defaultTabStop w:val="720" />
    <w:punctuationKerning />
    <w:characterSpacingControl w:val="DontCompress" />
    <w:optimizeForBrowser />
    <w:validateAgainstSchema />
    <w:saveInvalidXML w:val="off" />
    <w:ignoreMixedContent w:val="off" />
    <w:alwaysShowPlaceholderText w:val="off" />
    <w:compat>
      <w:breakWrappedTables />
      <w:snapToGridInCell />
      <w:wrapTextWithPunct />
      <w:useAsianBreakRules />
      <w:dontGrowAutofit />
    </w:compat>
  </w:docPr>';

  return $pre_body;
 }

 private function _create_body($data_a) {
  $lines = '<w:body>';
  $lines .= '<wx:sect>';
  $lines .='<wx:sub-section>
        <w:p>
          <w:pPr>
            <w:pStyle w:val="Heading1" />
          </w:pPr>
          <w:r>
            <w:t>Export Data</w:t>
          </w:r>
        </w:p>
        <w:sectPr>
          <w:pgSz w:w="12240" w:h="15840" />
          <w:pgMar w:top="1440"
		   w:right="1800"
		   w:bottom="1440"
		   w:left="1800"
		   w:header="720"
		   w:footer="720"
		   w:gutter="0" />
          <w:cols w:space="720" />
          <w:docGrid w:line-pitch="360" />
        </w:sectPr>
      </wx:sub-section><w:br/><w:br/>';

  foreach ($data_a as $key => $data) {
   $lines .= "<w:p>
              <w:pPr>
            <w:pStyle w:val=\"Heading1\" />
          </w:pPr>
        <w:r><w:rPr><w:b/>
          <w:t>Data Set Count $key </w:t></w:rPr>
        </w:r>
      </w:p>";
   foreach ($data as $data_key => $data_v) {
    $lines .= "<w:p>
        <w:r><w:rPr><w:b/>
          <w:t>$data_key  :</w:t></w:rPr></w:r><w:r><w:t>" . strip_tags($data_v) . " </w:t>
        </w:r>
      </w:p>";
   }
   $lines .= '<w:br/><w:br/>';
  }
  $lines .='</wx:sect>
  </w:body>';
  return $lines;
 }

 public function get_document($data_a) {
  $doc = $this->_generate_pre_body();
  $doc .= $this->_create_body($data_a);
  $doc .= '</w:wordDocument>';
  return $doc;
 }

 public function offset() {
  return ($this->current_page - 1) * $this->per_page;
 }

 public function total_pages() {
  try {
   return ceil($this->total_count / $this->per_page);
  } catch (Exception $e) {
   echo 'Caught exception :ino_doc01 ', $e->getMessage(), "\n";
  }
 }

 public function previous_page() {
  return $this->current_page - 1;
 }

 public function next_page() {
  return $this->current_page + 1;
 }

 public function has_previous_page() {
  return $this->previous_page() >= 1 ? true : false;
 }

 public function has_next_page() {
  return $this->next_page() <= $this->total_pages() ? true : false;
 }

 public function show_ino_doc() {
  $ino_doc_statement = "";

  if ($this->total_pages() > 1) {
   if ($this->current_page > 6) {
    $ino_doc_statement .= " <a href=\"$this->_path.php?pageno=1&" . $this->_query_string;
    $ino_doc_statement .= '">First</a>';
   }

   if ($this->has_previous_page()) {
    $ino_doc_statement .= "<a href=\"$this->_path.php?pageno=";
    $ino_doc_statement .= $this->previous_page() . '&' . $this->_query_string;
    $ino_doc_statement .= "\"> &laquo; " . gettext('Previous') . " </a> ";
   }

   if (($this->current_page > 5 ) && ($this->total_pages() > 10 )) {
    $starting_page_no = $this->current_page - 5;
   } else {
    $starting_page_no = 1;
   }
   $ino_doc_count = 1;

   do {
    if ($starting_page_no < $this->total_pages()) {
     if ($starting_page_no == $this->current_page) {
      $ino_doc_statement .= " <span class=\"selected\">{$starting_page_no}</span> ";
     } else {
      $ino_doc_statement .= " <a href=\"$this->_path.php?pageno={$starting_page_no}&" . $this->_query_string;
      $ino_doc_statement .= '">' . $starting_page_no . '</a>';
     }
     $starting_page_no++;
     $ino_doc_count++;
    } else {
     break;
    }
   } while ($ino_doc_count < 10);

   if ($this->has_next_page()) {
    $ino_doc_statement .= " <a href=\"$this->_path.php?pageno=";
    $ino_doc_statement .= $this->next_page() . '&' . $this->_query_string;
    $ino_doc_statement .= "\">" . gettext('Next') . " &raquo;</a> ";
   }
  }
  return $ino_doc_statement;
 }

 public function x_show_ino_doc($ino_doc, $path, $query_string, $pageno = 1) {
  $ino_doc_statement = "";
  if ($ino_doc->total_pages() > 1) {
   if ($ino_doc->has_previous_page()) {
    $ino_doc_statement .= "<a href=\"$path.php?pageno=";
    $ino_doc_statement .= $ino_doc->previous_page() . '&' . $query_string;
    $ino_doc_statement .= "\"> &laquo; Previous </a> ";
   }

   for ($i = 1; $i <= $ino_doc->total_pages(); $i++) {
    if ($i == $pageno) {
     $ino_doc_statement .= " <span class=\"selected\">{$i}</span> ";
    } else {
     $ino_doc_statement .= " <a href=\"$path.php?pageno={$i}&" . $query_string;
     $ino_doc_statement .= '">' . $i . '</a>';
    }
   }

   if ($ino_doc->has_next_page()) {
    $ino_doc_statement .= " <a href=\"$path.php?pageno=";
    $ino_doc_statement .= $ino_doc->next_page() . '&' . $query_string;
    $ino_doc_statement .= "\">" . gettext('Next') . " &raquo;</a> ";
   }
  }
  return $ino_doc_statement;
 }

}

?>
