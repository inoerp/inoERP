<?php

class pagination {

 public $current_page;
 public $enable_ajax_pagination = false;
 public $per_page;
 public $total_count;
 private $_path = 'search';
 private $_query_string;
 private $_total_pages;
 public static $noOfPages = <<<'VAR'
     <div id="noOfpages">
      <form action="" method="POST">
       <select name="per_page">
        <option value="3"> 3 </option>
        <option value="5"> 5 </option>
        <option value="10"> 10 </option>
        <option value="20"> 20 </option>
        <option value="50"> 50 </option>
       </select>
       <input type="submit" class="button" value="Per Page">
      </form>
     </div> 
VAR;
 public $data_result;
 public $headers;
 public $max_char = 50;

 public function __construct($pageno = 1, $per_page = 20, $total_count = 0) {
  if (!empty($_GET['pageno'])) {
   $pageno = is_array($_GET['pageno']) ? $_GET['pageno'][0] : $_GET['pageno'];
   $pageno = empty($pageno) ? 1 : $pageno;
  }
  if (!empty($_GET['per_page'])) {
   $per_page = is_array($_GET['per_page']) ? $_GET['per_page'][0] : $_GET['per_page'];
   $per_page = empty($per_page) ? 20 : $per_page;
  }
  $this->current_page = (int) $pageno;
  $this->per_page = (int) $per_page;
  $this->total_count = (int) $total_count;
 }

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_path':
     $this->$property = $value;

    default:
     $this->$property = $value;
     break;
   }
  }
 }

 public function offset() {
  return ($this->current_page - 1) * $this->per_page;
 }

 public function total_pages() {
  try {
   return ceil($this->total_count / $this->per_page);
  } catch (Exception $e) {
   echo 'Caught exception :PAGINATION01 ', $e->getMessage(), "\n";
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

 public function show_pagination() {
  $pagination_statement = "";
  if (empty($this->_query_string)) {
   $this->_query_string = $_SERVER['QUERY_STRING'];
  }
  if (!empty($this->_query_string)) {
   if (strpos($this->_query_string, 'pageno') !== false) {
    $pageno_value = $_GET['pageno'];
    $pageno_string = 'pageno=' . $pageno_value;
    $new_query_string1 = str_replace($pageno_string, "", $this->_query_string);
    $this->_query_string = $new_query_string1;
   }
   if (!empty($this->_query_string)) {
    if (strpos($this->_query_string, '&&') !== false) {
     $this->_query_string = str_replace('&&', '&', $this->_query_string);
    }
   }
  }
  $this->_total_pages = $this->total_pages();
  if ($this->_total_pages > 1) {
   $pagination_statement .= "<div class='page_nos'><nav>";
   $pagination_statement .= "<ul class='pagination'>";
   if ($this->current_page > 6) {
    if (strpos($this->_path, '.php') !== false) {
     $pagination_statement .= "<li> <a href=\"$this->_path&amp;pageno=1&amp;" . $this->_query_string;
    } else {
     $pagination_statement .= "<li> <a href=\"$this->_path.php?pageno=1&amp;" . $this->_query_string;
    }
    $pagination_statement .= '">First</a></li>';
   }

   if ($this->has_previous_page()) {
    if (strpos($this->_path, '.php') !== false) {
     $pagination_statement .= "<li><a aria-label=\"Previous\" href=\"$this->_path&pageno=";
    } else {
     $pagination_statement .= "<li><a aria-label=\"Previous\" href=\"$this->_path.php?pageno=";
    }
    $pagination_statement .= $this->previous_page() . '&amp;' . $this->_query_string;
    $pagination_statement .= "\"> <span aria-hidden='true'>&laquo; " . gettext('Previous') . "</span></a></li> ";
   }

   if (($this->current_page > 5 ) && ($this->_total_pages > 10 )) {
    $starting_page_no = $this->current_page - 5;
   } else {
    $starting_page_no = 1;
   }
   $pagination_count = 1;

   do {
    if ($starting_page_no < $this->_total_pages) {
     if ($starting_page_no == $this->current_page) {
      $pagination_statement .= " <span class=\"selected\">{$starting_page_no}</span> ";
     } else {
      if (strpos($this->_path, '.php') !== false) {
       $pagination_statement .= "<li> <a href=\"$this->_path&amp;pageno={$starting_page_no}&amp;" . $this->_query_string;
      } else {
       $pagination_statement .= " <li><a href=\"$this->_path.php?pageno={$starting_page_no}&amp;" . $this->_query_string;
      }
      $pagination_statement .= '">' . $starting_page_no . '</a></li>';
     }
     $starting_page_no++;
     $pagination_count++;
    } else {
     break;
    }
   } while ($pagination_count < 10);

   if ($this->has_next_page()) {
    if (strpos($this->_path, '.php') !== false) {
     $pagination_statement .= "<li> <a aria-label='Next' href=\"$this->_path&amp;pageno=";
    } else {
     $pagination_statement .= " <li><a aria-label='Next' href=\"$this->_path.php?pageno=";
    }

    $pagination_statement .= $this->next_page() . '&amp;' . $this->_query_string;
    $pagination_statement .= "\"><span aria-hidden='true'>" . gettext('Next') . " &raquo;</span></a> </li>";
   }

   if ($this->_total_pages > $pagination_count) {
    if (strpos($this->_path, '.php') !== false) {
     $pagination_statement .= "<li> <a href=\"$this->_path&amp;pageno=";
    } else {
     $pagination_statement .= "<li> <a href=\"$this->_path.php?pageno=";
    }
    $pagination_statement .= $this->_total_pages . '&amp;' . $this->_query_string;
    $pagination_statement .= "\">" . gettext('Last') . "</a> </li>";
   }

   $pagination_statement .= '</ul></nav></div>';
   $pagination_statement .= select_per_page($this->per_page);
  }

  if ($this->enable_ajax_pagination) {
   $pagination_statement = '<div class="do_ajax_pagination">' . $pagination_statement . '</div>';
  }
  return $pagination_statement;
 }

 public function show_result_withPagination_table() {

  if (empty($this->_query_string)) {
   $query_string = !empty($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';
  }
  $total_count = count($this->data_result);
  $pagination = new pagination($this->current_page, $this->per_page, $total_count);
  $pagination->setProperty('_path', $this->_path);
  $pagination->setProperty('_query_string', $this->_query_string);

  $content_string = '<div class="table_container">';
  if ($this->data_result) {
   $con_count = 0;
   if (count($this->data_result) > 0) {
    $content_string .='<table class="top_margin10 form_line_data_table page_wise_list"><thead><tr>';
    if (!empty($this->headers)) {
     foreach ($this->headers as $h_k => $h_v) {
      $content_string .="<th class=\"$h_k \">$h_v</th> ";
     }
    } else {
     foreach ($this->data_result[0] as $h_k => $h_v) {
      $content_string .="<th class=\"$h_k \">$h_v</th> ";
     }
    }
    $content_string .="</tr>	</thead> ";
    foreach ($this->data_result as $recod_k => $records) {
     $continue = true;
     if (($recod_k > ($this->current_page - 1) * $this->per_page) && ($recod_k <= (($this->current_page - 1) * $this->per_page) + $this->per_page)) {
      $continue = false;
     }
     if ($continue) {
      continue;
     }
     $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
     $content_string .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> ";
     foreach ($records as $r_k => $r_v) {
      $content_string .="<td class=\"$r_v \">$r_v</td> ";
     }
     $content_string .= '</tr>';
     $con_count++;
    }
   }

   $content_string .='</table>';
  }
  $content_string .='</div>';
  $content_string .= '<div class="pagination show_result_withPagination ajax_pagination">';
  $content_string .= $pagination->show_pagination();
  $content_string .= '</div>';

  return $content_string;
 }

}

?>
