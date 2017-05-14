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
class extn_report extends dbObject {

 public static $table_name = "extn_report";
 public static $primary_column = "extn_report_id";
 public static $key_column = 'report_name';
 public static $module = "extension";
 //  data base variables as stored database column name
 public static $system_info = [
  'name' => 'extn_report',
  'number' => '10036',
  'description' => 'Create & Update extn_report',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('extn_report_path'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 23
 ];
 public static $condition_operator_type_a = [
  'database' => 'Database',
  'manual' => 'Manual',
  'remove' => 'Remove'
 ];
 public $field_a = [
  'extn_report_id',
  'report_name',
  'description',
  'custom_div_class',
  'module_code',
  'logical_settings',
  'query_v',
  'report_columns',
  'display_type',
  'page',
  'page_title',
  'page_header',
  'page_footer',
  'use_pager_cb',
  'default_per_page',
  'no_of_grid_columns',
  'path',
  'path_id',
  'block_id',
  'block_title',
  'show_graph_only_cb',
  'rev_enabled_cb',
  'dont_show_graph_cb',
  'rev_number',
  'header_text',
  'footer_text',
  'remove_default_header_cb',
  'list_type',
  'chart_type',
  'chart_width',
  'chart_height',
  'chart_label',
  'chart_value',
  'chart_legend',
  'chart_legend2',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
// public static $array_field_array =[
//		 "path"
// ];
//variables used for showing data

 public $column = [
  'extn_report_id',
  'report_name',
  'description',
  'custom_div_class',
  'module_code',
  'logical_settings',
  'report_columns',
  'display_type',
  'page',
  'page_title',
  'page_header',
  'page_footer',
  'use_pager_cb',
  'default_per_page',
  'no_of_grid_columns',
  'path',
  'path_id',
  'block_id',
  'block_title',
  'show_graph_only_cb',
  'rev_enabled_cb',
  'rev_number',
  'header_text',
  'footer_text',
  'remove_default_header_cb',
  'list_type',
  'chart_type',
  'chart_width',
  'chart_height',
  'chart_label',
  'chart_value',
  'chart_legend',
  'chart_legend2',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "extn_report_id",
  "report_name",
  "description",
 ];
 public $checkbox = [
  "rev_enabled_cb",
  'update_parent_id_cb',
  'use_pager_cb',
  'create_block_cb'
 ];
 public $base_encoded_array = [
  "query_v"
 ];
 public $requiredField = [
  "report_name",
  "query_v"
 ];
 public $numberField = [
  'chart_width',
  'chart_height',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_extn_report_path' => 1,
 ];
 
  public $option_lists = [
  'module_code' => 'SYS_MODULE'
 ];
  
 public $pageTitle = " Report Builder "; //page Title
 public $extn_report_id;
 public $report_name;
 public $description;
 public $module_code;
 public $custom_div_class;
 public $logical_settings;
 public $query_v;
 public $report_columns;
 public $display_type;
 public $page;
 public $page_title;
 public $page_header;
 public $page_footer;
 public $use_pager_cb;
 public $default_per_page;
 public $no_of_grid_columns;
 public $path;
 public $path_id;
 public $block_id;
 public $block_title;
 public $show_graph_only_cb;
 public $dont_show_graph_cb;
 public $rev_enabled_cb;
 public $rev_number;
 public $header_text;
 public $footer_text;
 public $remove_default_header_cb;
 public $list_type;
 public $chart_type;
 public $chart_width;
 public $chart_height;
 public $chart_label;
 public $chart_value;
 public $chart_legend;
 public $chart_legend2;
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
 public $user_filter;
 public $user_sort;
 public $create_block_cb;

//  function __construct() {
//   global $dbc;
//   $sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//   $prepare = $dbc->connection->prepare($sql_fields);
//   $prepare->execute();
//   self::$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//   $this->_table_schema = DB_NAME;
//  }

 Public static function extn_report_display_type() {
  $option_header = option_header::find_by_name('EXT_VIEW_DISPLAY_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function module_code() {
  return !empty($this->module_code) ? $this->module_code : self::$module;
 }

 public static function find_by_blockId($block_id) {
  $sql = " SELECT * from ";
  $sql .= self::$table_name;
  $sql .= " WHERE block_id = '{$block_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function _before_save() {
  if (!empty($this->query_v)) {
   $result = self::find_by_sql(base64_decode($this->query_v));
   if ($result) {
    $this->report_columns = json_encode(array_keys((array) $result[0]));
   } else {
    echo $this->query_v;
    echo "<br>SQL error. Verify your sql query again";
    return -90;
   }
  }
 }

 private function _delete_block() {
  
 }

 public function inoextn_report_block_config() {
  
 }

 public function inoextn_report_block($parm) {
  if (!empty($parm['block_id'])) {
   $block_id = $parm['block_id'];
   $extn_report_b = self::find_by_blockId($block_id);
   if (empty($extn_report_b)) {
    return false;
   }
  } else {
   return false;
  }
  $extn_report_i = new extn_report();
  $extn_report_i->findBy_id($extn_report_b->extn_report_id);
  if (!empty($extn_report_i->show_graph_only_cb)) {
   ob_start();
   $extn_report_i->extn_report_resultImage_byId();
   $content = ob_get_contents();
   ob_end_clean();
  } else {
   ob_start();
   $extn_report_i->reportResultById();
   $content = ob_get_contents();
   ob_end_clean();
  }
  return $content;
 }

 public function _after_save() {
  global $db;
  if (empty($this->path) && !empty($this->extn_report_id)) {
   $this->path = "form.php?class_name=extn_report_result&mode=2&extn_report_id=$this->extn_report_id";
   $this->save_onWebForm();
  }

  if (!empty($this->create_block_cb) && !empty($this->extn_report_id) && empty($this->block_id)) {
   $block = new block();
   $block->name = 'inoextn_report';
   $block->title = 'extn_report of ' . $this->extn_report_name;
   $block->show_title_cb = 1;
   $block->position = 0;
   $block->weight = 0;
   $block->reference_table = 'extn_report';
   $block->reference_key_value = $this->extn_report_id;
   $block->enabled_cb = false;
   $block->visibility_option = 'hide';
   try {
    $block->save();
    $this->block_id = $block->block_id;
    $this->save_onWebForm();
   } catch (Exception $e) {
    echo "<br>Failed to save the block. Error @ class extn_report @@ line " . __LINE__;
    $db->rollback = true;
   }
  }

  if (!empty($this->update_parent_id_cb) && (!empty($_POST['parent_id'][0]))) {
   $path = new path();
   $path->path_id = !empty($this->path_id) ? $this->path_id : '';
   $update_path_id = empty($this->path_id) ? true : false;
   $path->parent_id = $_POST['parent_id'][0];
   $path->path_link = $this->path;
   $path->path_type = 'REPORT';
   $path->name = 'Custom report ' . $this->extn_report_name;
   $path->description = 'Custom report ' . $this->extn_report_name . ' - ' . $this->description;
   $path->module_code = 'sys';
   $path->mode = '2';
   $path->save();
   if ($update_path_id) {
    $this->path_id = $path->path_id;
    $this->save_onWebForm();
   }
  }
 }

 Public static function extn_report_display_types() {
  $org_header = option_header::find_by_name('extn_report_DISPLAY_TYPE');
  $type = option_line::find_by_option_id($org_header->option_header_id);
  return $type;
 }

 public static function find_all_idColumns() {
  global $db;
  $all_id_columns_array = [];
  $all_tables = self::find_all_tables();
//	pa($all_tables);
  foreach ($all_tables AS $key => $values) {
   if (!empty($values)) {
    $column_name = $values . '_id';
    $query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
    $result = $db->find_by_sql($query);
    if ((count($result) > 0) && (!empty($result[0]->field))) {
     $all_id_columns_array[] = $result[0]->field;
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
    if ((count($result) > 0) && (!empty($result[0]->field))) {
     yield $result[0]->field;
    }
   }
  }
 }

 private function _table_display($result) {
  $drop_down_icon = ino_search_dropDownSettings();
  if (empty($this->query_string)) {
   $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
  }
  $no_of_columns_per_tab = 9;
  $column_array_s = [];
  foreach ($result[0] as $h_k => $h_v) {
   array_push($column_array_s, $h_k);
  }

  $total_columns = count($column_array_s) + floor((count($column_array_s) / $no_of_columns_per_tab)); //1 for count
  $no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
  $total_count = count($result);
  $pagination = new pagination($this->pageno, $this->per_page, $total_count);
  $pagination->setProperty('_path', "form.php?class_name=extn_report_result&mode=2&extn_report_id={$this->extn_report_id}");
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
    $content_string .= '<table class="extn_report top_margin10 form_line_data_table page_wise_list"><thead><tr>';
    $content_string .= "<th>Seq#</th>";

    $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
    $new_end = $new_start + ($no_of_columns_per_tab - 1);
    for ($j = $new_start; $j <= $new_end; $j++) {
     if ($j > $total_columns - 2) {
      break;
     }
     $content_string .= '<th data-field_name="' . $column_array_s[$j] . '">' . $drop_down_icon . ucwords(str_replace('_', ' ', $column_array_s[$j])) . '</th>';
//     $content_string .= "<th data-fieldName='{$column_array_s[$j]}'>";
//     $content_string .= "<ul>";
//     $content_string .= '<li><img src=" ' . HOME_URL . 'themes/default/images/filter_add.png" class="filter_add clickable"></li>';
//     $content_string .= '<li class="field_value">' . ucwords(str_replace('__', ' ', $column_array_s[$j])) . '</li>';
//     $content_string .= '<li class="sort_elements"><img src=" ' . HOME_URL . 'themes/default/images/sort_up_16.png" class="sort_up clickable">';
//     $content_string .= '<img src=" ' . HOME_URL . 'themes/default/images/sort_down_16.png" class="sort_down clickable"></li>';
//     $content_string .= '</ul></th>';
    }
    $content_string .='</tr></thead>';
    If (!empty($result)) {
     $content_string .= '<tbody class="form_data_line_tbody search_results tbody_row' . $i . ' " >';
     $count = 0;
     foreach ($result as $recod_k => $record) {
      $continue = true;

      if (empty($recod_k) && ($this->pageno == 1)) {
       $continue = false;
      } else if (!empty($recod_k) && ($recod_k > ($this->pageno - 1) * $this->per_page) && ($recod_k <= ((($this->pageno - 1) * $this->per_page) + $this->per_page))) {
       $continue = false;
//       echo "<br> recod_k is $recod_k and page no is {$this->pageno} & per page is $this->per_page record value not shown $record->item_number ";
      }
      if ($continue) {
       continue;
      }
      $count++;
      $content_string .='<tr class="row' . $recod_k . '">';
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
  $content_string .= '<div id="extn_report_pagination_table" class="ajax_extn_report pagination">';
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
   $key = 'temp_table.' . $key;
   if (strpos(trim($value), ',') != false) {
    $comma_sep_search_parameters = explode(',', trim($value));
    $comma_sep_search_parameters_in_str = '(\'' . implode('\', \'', $comma_sep_search_parameters) . '\')';
    $whereFields[] = sprintf("%s IN %s ", $key, $comma_sep_search_parameters_in_str);
   } else {
    $entered_search_criteria = str_replace(' ', '%', trim($value));
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
   }
   array_push($existing_search, $value);
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
  $pagination->setProperty('_path', "form.php?class_name=extn_report&mode=2&extn_report_id={$this->extn_report_id}");
  $pagination->setProperty('_query_string', '');

  $content_string = '<div class="list_container scrollElement">';
  if ($result) {
   $con_count = 0;
   if (count($result) > 0) {
    $content_string .='<ul class="extn_report top_margin10 main_list page_wise_list">';
    foreach ($result as $recod_k => $records) {

     $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
     $content_string .= "<li class=\"extn_report_list_record $even_odd \"><ul class='second_level'>";
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
  $content_string .= '<div id="extn_report_pagination_table" class="ajax_extn_report pagination">';
  $content_string .= $pagination->show_pagination();
  $content_string .= '</div>';
  return $content_string;
 }

 private function _grid_display($result) {
  $columns = !empty($this->no_of_grid_columns) ? $this->no_of_grid_columns + 1 : 4;
  if (empty($this->query_string)) {
   $query_string = !empty($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';
  }
  $total_count = count($result);
  $pagination = new pagination($this->pageno, $this->per_page, $total_count);
  $pagination->setProperty('_path', "form.php?class_name=extn_report&mode=2&extn_report_id={$this->extn_report_id}");
  $pagination->setProperty('_query_string', '');

  $content_string = '<div class="grid_container scrollElement">';
  $content_string = '<table class="extn_report extn_report_grid_container"><tbody>';
  if ($result) {
   $con_count = 0;
   if (count($result) > 0) {
    $column_count = 1;
    foreach ($result as $recod_k => $records) {
     $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
     if ($column_count == 1) {
      $content_string .= "<tr class=\"extn_report_grid_record $even_odd \">";
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
      $content_string .="<span class=\"extn_report_grid $r_k \">" . ucwords(str_replace('_', ' ', $r_k)) . ' : ' . $r_v . "</span> ";
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
  $content_string .= '<div id="extn_report_pagination_table" class="ajax_extn_report pagination">';
  $content_string .= $pagination->show_pagination();
  $content_string .= '</div>';
  return $content_string;
 }

 public function update_extn_report_query_by_userInputs() {
  $extn_report_i = extn_report::find_by_id($this->extn_report_id);
  if (DB_TYPE == 'ORACLE') {
   $extn_report_i->query_v = !empty($extn_report_i->query_v) ?  stream_get_contents($extn_report_i->query_v) : null ;
   $extn_report_i->logical_settings = !empty($extn_report_i->logical_settings) ?  stream_get_contents($extn_report_i->logical_settings) : null;
   $extn_report_i->report_columns = !empty($extn_report_i->report_columns)?  stream_get_contents($extn_report_i->report_columns): null;
   $extn_report_i->page_header = !empty($extn_report_i->page_header) ?  stream_get_contents($extn_report_i->page_header) : null;
   $extn_report_i->page_footer = !empty($extn_report_i->page_footer) ? stream_get_contents($extn_report_i->page_footer) : null;
   $extn_report_i->header_text =  !empty($extn_report_i->header_text) ? stream_get_contents($extn_report_i->header_text) : null ;
   $extn_report_i->footer_text =  !empty($extn_report_i->footer_text) ? stream_get_contents($extn_report_i->footer_text) : null;
  }



  $this->query_v = base64_decode($extn_report_i->query_v);

  if (!empty($this->user_filter) || !empty($this->user_sort)) {
   $this->query_v = ' SELECT  * FROM ( ' . $this->query_v . ' ) AS temp_table';

   if (!empty($this->user_filter)) {
    $user_filter = $this->_update_queryByFilter();
    if (!empty($user_filter)) {
     $this->query_v .= ' WHERE ' . $user_filter;
    }
   }

   if (!empty($this->user_sort)) {
    $user_sort = $this->_update_orderBY();
    $this->query_v .= ' ORDER BY ' . $user_sort;
   }
  }

  $this->_class_name = $extn_report_i->custom_div_class . ' ' . $extn_report_i->report_name;
  $this->header_text = $extn_report_i->header_text;
  $this->footer_text = $extn_report_i->footer_text;
  $this->display_type = $extn_report_i->display_type;
  $this->no_of_grid_columns = $extn_report_i->no_of_grid_columns;
 }

 public function show_reportResult($extn_report_id = '') {
  $return_stmt = '';
  $this->extn_report_id = !empty($extn_report_id) ? $extn_report_id : $this->extn_report_id;
  if (!empty($this->extn_report_id)) {
   $this->update_extn_report_query_by_userInputs();
//    echo $this->query_v;
   $result = $this->findBySql($this->query_v);
  } else if (!empty($this->query_v)) {

   $result = $this->findBySql(($this->query_v));
  } else {
   return false;
  }

  if (empty($this->pageno)) {
   $this->pageno = $extn_report_i->pageno;
  }

  if (!$result) {
   return false;
  }

  $return_stmt .= show_download_button_inSelectFormat($result);
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
   $return_stmt = '<div class="' . $this->_class_name . '"><div class="extn_report_display_data" id="report_id' . $this->extn_report_id . '">' . $return_stmt . '</div></div>';
  } else {
   $return_stmt = '<div class="extn_report_display_data">' . $return_stmt . '</div>';
  }
  return $return_stmt;
 }

 public function reportResultById($extn_report_id = '') {
  $this->extn_report_id = !empty($extn_report_id) ? $extn_report_id : $this->extn_report_id;
  $this->findBy_id($this->extn_report_id);

  if (DB_TYPE == 'ORACLE') {
   $this->query_v = stream_get_contents($this->query_v);
  }

  if (!empty($this->extn_report_id) && !empty($this->chart_type)) {
   $svgimg = new getsvgimage();
   $result = $result1 = dbObject::find_by_sql(base64_decode($this->query_v));
   $svgimg->setProperty('_chart_name', $this->report_name);
   $svgimg->setProperty('_chart_width', $this->chart_width);
   $svgimg->setProperty('_chart_height', $this->chart_height);
   $svgimg->setProperty('_chart_type', $this->chart_type);
   $svgimg->result = $result;
   $svgimg->legend_name = str_replace('.', '__', $this->chart_legend);
   $svgimg->legend_name2 = str_replace('.', '__', $this->chart_legend2);
   $svgimg->chart_label = str_replace('.', '__', $this->chart_label);
   $svgimg->chart_value = str_replace('.', '__', $this->chart_value);
   $svg_chart = $svgimg->getSvgChart_forView();
  }

  $column_list = [];
  if (!empty($this->extn_report_id)) {
   $extn_report_i = extn_report::find_by_id($this->extn_report_id);
   if (DB_TYPE == 'ORACLE') {
    $extn_report_i->report_columns = !empty($extn_report_i->report_columns) ? stream_get_contents($extn_report_i->report_columns) : null;
   }

   if (!empty($extn_report_i->report_columns)) {
    $column_list_k = json_decode($extn_report_i->report_columns);
    $column_list = array_combine($column_list_k, $column_list_k);
   }
  }

  $class = 'extn_report_result';
  $$class = $this;
  global $f;
  include __DIR__ . DS . 'result/display/display_template.php';
  return;
 }

 public function extn_report_resultImage_byId($extn_report_id = '') {
  $this->extn_report_id = !empty($extn_report_id) ? $extn_report_id : $this->extn_report_id;
  $this->findBy_id($this->extn_report_id);
  if (!empty($this->extn_report_id) && !empty($this->chart_type)) {
   $svgimg = new getsvgimage();
   $result = $result1 = dbObject::find_by_sql(base64_decode($this->query_v));
   $svgimg->setProperty('_chart_name', $this->extn_report_name);
   $svgimg->setProperty('_chart_width', $this->chart_width);
   $svgimg->setProperty('_chart_height', $this->chart_height);
   $svgimg->setProperty('_chart_type', $this->chart_type);
   $svgimg->result = $result;
   $svgimg->legend_name = str_replace('.', '__', $this->chart_legend);
   $svgimg->legend_name2 = str_replace('.', '__', $this->chart_legend2);
   $svgimg->chart_label = str_replace('.', '__', $this->chart_label);
   $svgimg->chart_value = str_replace('.', '__', $this->chart_value);
   $svg_chart = $svgimg->getSvgChart_forextn_report();
  }

  if (!empty($this->extn_report_id)) {
   $extn_report_i = extn_report::find_by_id($this->extn_report_id);
   $column_list = [];
   if (!empty($extn_report_i->select_v)) {
    $select_v = explode(',', $this->select_v);
    if (!empty($select_v)) {
     foreach ($select_v as $k2 => $v2) {
      if (strpos($v2, 'AS') !== false) {
       $v_a = explode('AS', $v2);
       $colmn_v = trim($v_a[1]);
       $column_list[$colmn_v] = $colmn_v;
      }
     }
    }
   }
  }
  $class = 'extn_report_result';
  $$class = $this;
  global $f;
  include 'result/display/image_display_template.php';
  return;
 }

}

//end of extn_report class
?>
