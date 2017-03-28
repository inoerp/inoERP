<?php

 class view_ora extends dbOraObject {

  public static $table_name = "view_ora";
  public static $primary_column = "view_ora_id";
  public static $key_column = 'view_ora_name';
  public static $module = "extension";
  public static $js_fileName = 'modules/po/js/multi_select.js';
  //  data base variables as stored database column name
  public static $condition_operator_type_a = [
   'database' => 'Database',
   'manual' => 'Manual',
   'remove' => 'Remove'
  ];
  public $field_a = [
   "view_ora_id",
   "view_ora_name",
   "description",
   'custom_div_class',
   'header_text',
   'footer_text',
   'remove_default_header_cb',
   "logical_settings",
   "query_v",
   "select_v",
   "from_v",
   "where_v",
   "order_by",
   'group_by_v',
   "query_end",
   "filters",
   "display_type",
   "page",
   "page_title",
   "page_header",
   "page_footer",
   "use_pager_cb",
   "default_per_page",
   'no_of_grid_columns',
   'list_type',
   "path",
   'path_id',
   "block",
   "block_title",
   "block_header",
   "block_footer",
   "block_type",
   "block_more",
   "rev_enabled_cb",
   "rev_number",
   'chart_type',
   'chart_width',
   'chart_height',
   'chart_label',
   'chart_value',
   'chart_legend',
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
// public static $array_field_array =[
//		 "path"
// ];
//variables used for showing data


  public $initial_search = [
   "view_ora_id",
   "view_ora_name",
   "description",
  ];
  public $checkbox = [
   "rev_enabled_cb",
   'update_parent_id_cb',
   'use_pager_cb'
  ];
  public $column = [
   "rev_enabled_cb",
   "view_ora_id",
   "view_ora_name",
   "description",
  ];
  public $base_encoded_array = [
   "logical_settings",
   "query_v"
  ];
  public $requiredField = [
   "view_ora_name",
   "description",
   "query_v"
  ];
  public $fields_inForm_notInDataBase = [
  ];
  public $search = [
   '_show_update_path' => 1,
   '_show_view_ora_path' => 1,
  ];
  public $pageTitle = " view_oras "; //page Title
  public $all_table_names;
  public $view_ora_id;
  public $view_ora_name;
  public $custom_div_class;
  public $logical_settings;
  public $description;
  public $header_text;
  public $footer_text;
  public $remove_default_header_cb;
  public $query_v;
  public $select_v;
  public $from_v;
  public $where_v;
  public $group_by_v;
  public $order_by;
  public $query_end;
  public $filters;
  public $display_type;
  public $page;
  public $page_title;
  public $page_header;
  public $page_footer;
  public $use_pager_cb;
  public $default_per_page;
  public $no_of_grid_columns;
  Public $list_type;
  public $path;
  public $path_id;
  public $block;
  public $block_title;
  public $block_header;
  public $block_footer;
  public $block_type;
  public $block_more;
  public $rev_number;
  public $rev_enabled_cb;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  private $_table_schema;
  public $column_name;
  public $per_page = 20;
  public $query_string;
  public $pageno = 1;
  public $parent_id;
  public $update_parent_id_cb;
  public $condition_operator_type;
  public $add_to_menu;
  private $_class_name;
  public $chart_type;
  public $chart_width;
  public $chart_height;
  public $chart_label;
  public $chart_value;
  public $chart_legend;
  public $user_filter;
  public $user_sort;

//  function __construct() {
//   global $dbOrac;
//   $sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//   $prepare = $dbOrac->connection->prepare($sql_fields);
//   $prepare->execute();
//   self::$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//   $this->_table_schema = DB_NAME;
//  }

  Public static function view_ora_display_type() {
   $option_header = option_header::find_by_name('EXT_view_ora_DISPLAY_TYPE');
   $ol = option_line::find_by_option_id($option_header->option_header_id);
   return $ol;
  }

  public function _before_save() {
   
  }

  public function _after_save() {
   if (empty($this->path) && !empty($this->view_ora_id)) {
    $this->path = "form.php?class_name=view_ora_result&mode=2&view_ora_id=$this->view_ora_id";
    $this->save_onWebForm();
   }

   if (!empty($this->update_parent_id_cb) && (!empty($_POST['parent_id'][0]))) {
    $path = new path();
    $path->path_id = !empty($this->path_id) ? $this->path_id : '';
    $update_path_id = empty($this->path_id) ? true : false;
    $path->parent_id = $_POST['parent_id'][0];
    $path->path_link = $this->path;
    $path->path_type = 'REPORT';
    $path->name = 'Custom report ' . $this->view_ora_name;
    $path->description = 'Custom report ' . $this->view_ora_name . ' - ' . $this->description;
    $path->module_code = 'sys';
    $path->mode = '2';
    $path->save();
    if ($update_path_id) {
     $this->path_id = $path->path_id;
     $this->save_onWebForm();
    }
   }
  }

  Public static function view_ora_display_types() {
   $org_header = option_header::find_by_name('view_ora_DISPLAY_TYPE');
   $type = option_line::find_by_option_id($org_header->option_header_id);
   return $type;
  }

  public static function find_all_tables() {
   global $dbOra;
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '" . DB_NAME . "' ";
   $result = $dbOra->find_by_sql($query);

   $table_name_array = array();
   foreach ($result as $object) {
    $table_name_array [] = $object->TABLE_NAME;
   }
   return $table_name_array;
  }

  public static function find_all_tables_and_view() {
   global $dbOra;
   $query = " SELECT TABLE_NAME from information_schema.tables  "
     . " where TABLE_SCHEMA= '" . DB_NAME . "' ";
   $result = $dbOra->find_by_sql($query);
   return $result;
  }

  public static function find_all_tables_and_view_ora() {
   global $dbOra;
   $query = " SELECT OWNER, VIEW_NAME as TABLE_NAME FROM ALL_VIEWS
UNION
SELECT OWNER, TABLE_NAME FROM ALL_TABLES  ";
   
   $result = $dbOra->find_by_sql($query);
   
   return $result;
  }

  public static function count_all_tables() {
   global $dbOra;
   $query = " SELECT count(TABLE_NAME) as table_count from information_schema.tables  "
     . " WHERE TABLE_SCHEMA= '" . DB_NAME . "' ";
   $result = $dbOra->find_by_sql($query);
   return !empty($result) ? array_pop($result) : null;
  }

  public static function find_all_tables_gen() {
   global $dbOra;
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '" . DB_NAME . "' ";
   $result = $dbOra->find_by_sql($query);

   foreach ($result as $object) {
    yield $object->TABLE_NAME;
   }
  }

  public function findAll_tables() {
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '" . DB_NAME . "' ";
   $result = $this->findBySql($query);
   $table_name_array = array();
   foreach ($result as $object) {
    $table_name_array [] = $object->TABLE_NAME;
   }
   return $table_name_array;
  }

  public static function find_columns_of_table($table_name) {
   global $dbOra;
   if (!empty($table_name)) {
    $query = "SHOW COLUMNS FROM $table_name ";
    $result = $dbOra->find_by_sql($query);

    $column_name_array = array();
    foreach ($result as $object) {
     $column_name_array [] = $object->Field;
    }
    return $column_name_array;
   }
  }
  
  public static function find_columns_of_table_ora($table_name) {
// global $dbOra;
  global $dbOra;
  $columns = [];
  if (!empty($table_name)) {
   $sql_fields = " SELECT * FROM  " . $table_name . " WHERE ROWNUM < 2 ";
   $fields = $dbOra->findBySql($sql_fields);
   if (!empty($fields[0])) {
    foreach ($fields[0] as $key => $val) {
     array_push($columns, $key);
    }
   }
   return !empty($columns) ? ($columns) : false;
  }
 }


  public static function find_columns_of_table_obj($table_name) {
   global $dbOra;
   if (!empty($table_name)) {
    $query = "SHOW COLUMNS FROM $table_name ";
    $result = $dbOra->find_by_sql($query);
    return $result;
   }
  }

  public static function find_columns_of_table_obj_ora($table_name) {
   global $dbOraOra;
   $columns = [];
   if (!empty($table_name)) {
    $sql_fields = " SELECT COLUMN_NAME
FROM all_tab_cols
WHERE table_name = '{$table_name}'  ";
    $fields = $dbOraOra->findBySql($sql_fields);
    return !empty($fields) ? ($fields) : false;
   }
  }

  public static function find_all_idColumns() {
   global $dbOra;
   $all_id_columns_array = [];
   $all_tables = self::find_all_tables();
//	pa($all_tables);
   foreach ($all_tables AS $key => $values) {
    if (!empty($values)) {
     $column_name = $values . '_id';
     $query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
     $result = $dbOra->find_by_sql($query);
     if ((count($result) > 0) && (!empty($result[0]->Field))) {
      $all_id_columns_array[] = $result[0]->Field;
     }
    }
   }
//	pa($all_id_columns_array);
   return $all_id_columns_array;
  }

  public static function find_all_idColumns_gen() {
   $all_tables = self::find_all_tables_gen();
   foreach ($all_tables AS $key => $values) {
    if (!empty($values)) {
     $column_name = $values . '_id';
     $query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
     $result = self::find_by_sql($query);
     if ((count($result) > 0) && (!empty($result[0]->Field))) {
      yield $result[0]->Field;
     }
    }
   }
  }

  private function xx_table_display($result) {
   if (empty($this->query_string)) {
    $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
   }
   $total_count = count($result);
   $pagination = new pagination($this->pageno, $this->per_page, $total_count);
   $pagination->setProperty('_path', "form.php?class_name=view_ora&mode=2&view_ora_id={$this->view_ora_id}");
   $pagination->setProperty('_query_string', '');

   $content_string = '<div class="table_container scrollElement">';
   if ($result) {
    $con_count = 0;
    if (count($result) > 0) {
     $content_string .='<table class="view_ora top_margin10 form_line_data_table page_wise_list"><thead><tr>';
     foreach ($result[0] as $h_k => $h_v) {
      $h_k_a = explode('__', $h_k);
      $content_string .="<th class=\"$h_k \">" . ucwords(str_replace('_', ' ', $h_k_a[1])) . "</th> ";
     }
     $content_string .="</tr>	</thead> ";
     foreach ($result as $recod_k => $records) {
      $continue = true;
      if (($recod_k > ($this->pageno - 1) * $this->per_page) && ($recod_k <= (($this->pageno - 1) * $this->per_page) + $this->per_page)) {
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
   $content_string .= '<div id="view_ora_pagination_table" class="ajax_view_ora pagination">';
   $content_string .= $pagination->show_pagination();
   $content_string .= '</div>';
   return $content_string;
  }

  private function _table_display($result) {
   if (empty($this->query_string)) {
    $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
   }
   $no_of_columns_per_tab = 9;
   $column_array_s = [];
   foreach ($result[0] as $h_k => $h_v) {
    array_push($column_array_s, $h_k);
   }

   $total_columns = count($column_array_s) + (int) (count($column_array_s) / $no_of_columns_per_tab); //1 for count
   $no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
   $total_count = count($result);
   $pagination = new pagination($this->pageno, $this->per_page, $total_count);
   $pagination->setProperty('_path', "form.php?class_name=view_ora&mode=2&view_ora_id={$this->view_ora_id}");
   $pagination->setProperty('_query_string', '');

   $content_string = '<div class="table_container scrollElement">';
   if ($result) {
    $content_string = '';
    $content_string .= '<div id="tabsDetail">
				 <ul class="tabMain">';
    for ($l = 0; $l < $no_of_tabs; $l++) {
     $content_string .= "<li><a href=\"#tabsDetail-$l\">Tab No $l </a></li>";
    }
    $content_string .= ' </ul>
				 <div class="tabContainer"> ';
    for ($i = 0; $i < $no_of_tabs; $i++) {
     $content_string .= "<div id=\"tabsDetail-$i\" class='tabContent'>";
     $content_string .= '<table class="view_ora top_margin10 form_line_data_table page_wise_list"><thead><tr>';
     $content_string .= "<th>Seq#</th>";
     $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
     $new_end = $new_start + ($no_of_columns_per_tab - 1);
     for ($j = $new_start; $j <= $new_end; $j++) {
      if ($j > $total_columns - 2) {
       break;
      }
      $content_string .= "<th data-fieldName='{$column_array_s[$j]}'><ul>";
      $content_string .= '<li><img src=" ' . HOME_URL . 'themes/default/images/filter_add.png" class="filter_add clickable"></li>';
      $content_string .= '<li class="field_value">' . ucwords(str_replace('__', ' ', $column_array_s[$j])) . '</li>';
      $content_string .= '<li class="sort_elements"><img src=" ' . HOME_URL . 'themes/default/images/sort_up_16.png" class="sort_up clickable">';
      $content_string .= '<img src=" ' . HOME_URL . 'themes/default/images/sort_down_16.png" class="sort_down clickable"></li>';
      $content_string .= '</ul></th>';
     }
     $content_string .='</tr></thead>';
     If (!empty($result)) {
      $content_string .= '<tbody class="form_data_line_tbody search_results" >';
      $count = 0;
      foreach ($result as $recod_k => $record) {
       $continue = true;
       if (empty($recod_k)) {
        $continue = false;
       } else if (!empty($recod_k) && ($recod_k > ($this->pageno - 1) * $this->per_page) && ($recod_k <= (($this->pageno - 1) * $this->per_page) + $this->per_page)) {
        $continue = false;
       }
       if ($continue) {
        continue;
       }
       $count++;
       $content_string .='<tr>';
       $content_string .= "<td>$count</td>";
       $new_start1 = ($i * ($no_of_columns_per_tab - 1)) + $i;
       $new_end1 = $new_start1 + ($no_of_columns_per_tab - 1);
       for ($k = $new_start; $k <= $new_end1; $k++) {
        if ($k > $total_columns - 2) {
         break;
        }
        $col_val = $column_array_s[$k];
        if (isset($record->$col_val)) {
         $content_string .= '<td>' . ucwords(str_replace('_', ' ', $record->$col_val)) . '</td>';
        } else {
         $content_string .= '<td> </td>';
        }
       }
       $content_string .= '</tr>';
      }
      $content_string .= '</tbody>';
     } else {
      $content_string .= gettext('No Records Found!');
     }
     $content_string .= '</table> </div>';
    }
    $content_string .= '</div>';
   }
   $content_string .='</div>';
   $content_string .= '<div id="view_ora_pagination_table" class="ajax_view_ora pagination">';
   $content_string .= $pagination->show_pagination();
   $content_string .= '</div>';
   return $content_string;
  }

  private function _update_queryByFilter() {
   $whereFields = [];
   $existing_search = [];
//to check number of criterias
   $noof_criteria = 0;
   foreach ($this->user_filter as $key => $value) {
    $key = str_replace('__', '.', $key);
    $entered_search_criteria = str_replace(' ', '%', trim($value));
    array_push($existing_search, $value);
    if (substr($entered_search_criteria, 0, 1) == '=') {
     $whereFields[] = sprintf("%s = '%s' ", $key, trim(substr($entered_search_criteria, 1)));
    } else if (substr($entered_search_criteria, 0, 2) == '!=') {
     $whereFields[] = sprintf("%s != '%s' ", $key, trim(substr($entered_search_criteria, 2)));
    } else if (substr($entered_search_criteria, 0, 1) == '>') {
     $whereFields[] = sprintf("%s > '%s' ", $key, trim(substr($entered_search_criteria, 1)));
    } else if (substr($entered_search_criteria, 0, 1) == '<') {
     $whereFields[] = sprintf("%s < '%s' ", $key, trim(substr($entered_search_criteria, 1)));
    } else {
     $whereFields[] = sprintf("%s LIKE '%%%s%%'", $key, trim(mysql_prep($entered_search_criteria)));
    }
    $noof_criteria++;
   }
   $whereClause = implode(" AND ", $whereFields);
   return $whereClause;
  }

  private function _update_orderBY() {
   $orderBy = '';
   foreach ($this->user_sort as $key => $value) {
    $value = ($value == 'sort_down') ? ' DESC ' : 'ASC';
    $key = str_replace('__', '.', $key);
    $orderBy .= $key . ' ' . $value . ',';
   }
   $orderBy = rtrim($orderBy, ',');
   return $orderBy;
  }

  private function _list_display($result) {
   if (empty($this->query_string)) {
    $query_string = !empty($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';
   }
   $total_count = count($result);
   $pagination = new pagination($this->pageno, $this->per_page, $total_count);
   $pagination->setProperty('_path', "form.php?class_name=view_ora&mode=2&view_ora_id={$this->view_ora_id}");
   $pagination->setProperty('_query_string', '');

   $content_string = '<div class="list_container scrollElement">';
   if ($result) {
    $con_count = 0;
    if (count($result) > 0) {
     $content_string .='<ul class="view_ora top_margin10 main_list page_wise_list">';
     foreach ($result as $recod_k => $records) {

      $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
      $content_string .= "<li class=\"view_ora_list_record $even_odd \"><ul class='second_level'>";
      $continue = true;
      if (($recod_k > ($this->pageno - 1) * $this->per_page) && ($recod_k <= (($this->pageno - 1) * $this->per_page) + $this->per_page)) {
       $continue = false;
      }
      if ($continue) {
       continue;
      }
      foreach ($records as $r_k => $r_v) {
       $content_string .="<li class=\"$r_k \">" . ucwords(str_replace('_', ' ', $r_k)) . ' : ' . $r_v . "</li> ";
      }
      $content_string .= '</ul></li>';

      $con_count++;
     }
     $content_string .='</ul>';
    }
   }
   $content_string .='</div>';
   $content_string .= '<div id="view_ora_pagination_table" class="ajax_view_ora pagination">';
   $content_string .= $pagination->show_pagination();
   $content_string .= '</div>';
   return $content_string;
  }

  private function _grid_display($result) {
   $columns = !empty($this->no_of_grid_columns) ? $this->no_of_grid_columns + 1 : 4;
   if (empty($this->query_string)) {
    $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
   }
   $total_count = count($result);
   $pagination = new pagination($this->pageno, $this->per_page, $total_count);
   $pagination->setProperty('_path', "form.php?class_name=view_ora&mode=2&view_ora_id={$this->view_ora_id}");
   $pagination->setProperty('_query_string', '');

   $content_string = '<div class="grid_container scrollElement">';
   $content_string = '<table class="view_ora view_ora_grid_container"><tbody>';
   if ($result) {
    $con_count = 0;
    if (count($result) > 0) {
     $column_count = 1;
     foreach ($result as $recod_k => $records) {
      $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
      if ($column_count == 1) {
       $content_string .= "<tr class=\"view_ora_grid_record $even_odd \">";
      }
      $continue = true;
      if (($recod_k > ($this->pageno - 1) * $this->per_page) && ($recod_k <= (($this->pageno - 1) * $this->per_page) + $this->per_page)) {
       $continue = false;
      }
      if ($continue) {
       continue;
      }
      $content_string .= '<td>';
      foreach ($records as $r_k => $r_v) {
       $content_string .="<span class=\"view_ora_grid $r_k \">" . ucwords(str_replace('_', ' ', $r_k)) . ' : ' . $r_v . "</span> ";
      }
      $content_string .= '</td>';
      $column_count++;
      if ($column_count == $columns) {
       $content_string .= '</tr>';
       $column_count = 1;
      }
      $con_count++;
     }
    }
   }
   $content_string .='</tbody></table>';
   $content_string .='</div>';
   $content_string .= '<div id="view_ora_pagination_table" class="ajax_view_ora pagination">';
   $content_string .= $pagination->show_pagination();
   $content_string .= '</div>';
   return $content_string;
  }

  public function update_view_ora_query_by_userInputs() {
   $view_ora_i = view_ora::find_by_id($this->view_ora_id);
   $this->query_v = base64_decode($view_ora_i->query_v);
   if (!empty($this->user_filter) || !empty($this->user_sort)) {
    $this->query_v = ' SELECT ' . $view_ora_i->select_v;
    $this->query_v .= ' FROM ' . $view_ora_i->from_v;
    $this->query_v .= ' WHERE ' . $view_ora_i->where_v;
    if (!empty($this->user_filter)) {
     $user_filter = $this->_update_queryByFilter();
     if (empty($view_ora_i->where_v)) {
      $this->query_v .= $user_filter;
     } else {
      $this->query_v .= ' AND ' . $user_filter;
     }
    }

    $this->query_v .=!empty($view_ora_i->group_by_v) ? ' GROUP BY ' . $view_ora_i->group_by_v : '';
    $this->query_v .=!empty($view_ora_i->order_by) ? ' ORDER BY ' . $view_ora_i->order_by : '';
    if (!empty($this->user_sort)) {
     $user_sort = $this->_update_orderBY();
     if (empty($view_ora_i->order_by)) {
      $this->query_v .= ' ORDER BY ' . $user_sort;
     } else {
      $this->query_v .= ' , ' . $user_sort;
     }
    }
   }
   $this->_class_name = $view_ora_i->custom_div_class . ' ' . $view_ora_i->view_ora_name;
   $this->header_text = $view_ora_i->header_text;
   $this->footer_text = $view_ora_i->footer_text;
   $this->display_type = $view_ora_i->display_type;
   $this->no_of_grid_columns = $view_ora_i->no_of_grid_columns;
  }

  public function show_view_oraResult($view_ora_id = '') {
   $return_stmt = '';
   $this->view_ora_id = !empty($view_ora_id) ? $view_ora_id : $this->view_ora_id;
   if (!empty($this->view_ora_id)) {
    $this->update_view_ora_query_by_userInputs();
    $result = $this->findBySql($this->query_v);
   } else if (!empty($this->query_v)) {

    $result = $this->findBySql(($this->query_v));
   } else {
    return false;
   }

   if (empty($this->pageno)) {
    $this->pageno = $view_ora_i->pageno;
   }

   if (!$result) {
    return false;
   }

   $return_stmt .= show_download_button($result);
   $return_stmt .= $this->header_text;
   switch ($this->display_type) {
    case 'LIST' :
    case 'PARAGRAPH':
     $return_stmt .= $this->_list_display($result);
     break;

    case 'GRID' :
     $return_stmt .= $this->_grid_display($result);
     break;

    case 'TABLE' :
    case 'default' :
     $return_stmt .= $this->_table_display($result);
     break;
   }

   $return_stmt .= $this->footer_text;
   if (!empty($this->_class_name)) {
    $return_stmt = '<div class="' . $this->_class_name . '"><div id="view_ora_display_data">' . $return_stmt . '</div></div>';
   } else {
    $return_stmt = '<div id="view_ora_display_data">' . $return_stmt . '</div>';
   }
   return $return_stmt;
  }

 }

//end of view_ora class
?>
