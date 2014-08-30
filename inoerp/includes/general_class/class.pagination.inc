<?php

class pagination {

 public $current_page;
 public $per_page;
 public $total_count;
 private $_path = 'search';
 private $_query_string;
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

 public function __construct($pageno = 1, $per_page = 20, $total_count = 0) {
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
	try{
	return ceil($this->total_count / $this->per_page);
	}catch (Exception $e){
	 echo 'Caught exception :PAGINATION01 ',  $e->getMessage(), "\n";
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

	if ($this->total_pages() > 1) {
	 if ($this->current_page > 6) {
$pagination_statement .= " <a href=\"$this->_path.php?pageno=1&" . $this->_query_string;
			$pagination_statement .= '">First</a>';
	 }

	 if ($this->has_previous_page()) {
		$pagination_statement .= "<a href=\"$this->_path.php?pageno=";
		$pagination_statement .= $this->previous_page() . '&' . $this->_query_string;
		$pagination_statement .= "\"> &laquo; Previous </a> ";
	 }

	 if (($this->current_page > 5 ) && ($this->total_pages() > 10 )) {
		$starting_page_no = $this->current_page - 5;
	 } else {
		$starting_page_no = 1;
	 }
	 $pagination_count = 1;
	 
	 do {
		if ($starting_page_no < $this->total_pages()) {
		 if ($starting_page_no == $this->current_page) {
			$pagination_statement .= " <span class=\"selected\">{$starting_page_no}</span> ";
		 } else {
			$pagination_statement .= " <a href=\"$this->_path.php?pageno={$starting_page_no}&" . $this->_query_string;
			$pagination_statement .= '">' . $starting_page_no . '</a>';
		 }
		 $starting_page_no++;
		 $pagination_count++;
		}else{
		 break;
		}
	 } while ($pagination_count < 10);

	 if ($this->has_next_page()) {
		$pagination_statement .= " <a href=\"$this->_path.php?pageno=";
		$pagination_statement .= $this->next_page() . '&' . $this->_query_string;
		$pagination_statement .= "\">Next &raquo;</a> ";
	 }
	}
	return $pagination_statement;
 }

 public function x_show_pagination($pagination, $path, $query_string, $pageno = 1) {
	$pagination_statement = "";
	if ($pagination->total_pages() > 1) {
	 if ($pagination->has_previous_page()) {
		$pagination_statement .= "<a href=\"$path.php?pageno=";
		$pagination_statement .= $pagination->previous_page() . '&' . $query_string;
		$pagination_statement .= "\"> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_pages(); $i++) {
		if ($i == $pageno) {
		 $pagination_statement .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $pagination_statement .= " <a href=\"$path.php?pageno={$i}&" . $query_string;
		 $pagination_statement .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_page()) {
		$pagination_statement .= " <a href=\"$path.php?pageno=";
		$pagination_statement .= $pagination->next_page() . '&' . $query_string;
		$pagination_statement .= "\">Next &raquo;</a> ";
	 }
	}
	return $pagination_statement;
 }

}

?>