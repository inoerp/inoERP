<?php require_once __DIR__.'/../basics/wloader.inc';
		 include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc'); ?>
<?php

if (!empty($_GET['class_name'])) {
 $class = $class_names = $_GET['class_name'];
 $$class = new $class;
 $table_name = empty($table_name) ? $class::$table_name : $table_name;
 $primary_column = property_exists($$class, 'primary_column') ? $class::$primary_column : $table_name . '_id';

 if (!(empty($_GET['pageno']))) {
  $pageno = is_array($_GET['pageno']) ? (int) $_GET['pageno'][0] : (int) $_GET['pageno'];
 } else {
  $pageno = 1;
 }

 if (!(empty($_GET['per_page']))) {
  $per_page = is_array($_GET['per_page']) ? (int) $_GET['per_page'][0] : (int) $_GET['per_page'];
 } else {
  $per_page = null;
 }

 if (!empty($_GET['search_parameters'])) {
  $_GET = get_postArray_From_jqSearializedArray($_GET['search_parameters']);
 }

 $_GET['pageno'] = $pageno;
 $_GET['class_name'] = $class;
 $_GET['per_page'] = !empty($per_page) ? $per_page : '10';

 if (!empty($_GET['per_page'])) {
  if (!empty($_GET['per_page']) && ($_GET['per_page'] == "all"  OR  $_GET['per_page'][0] == "all")) {
   $per_page = 50000;
  } else if (!empty($_GET['per_page'])) {
   $per_page = (is_array($_GET['per_page'])) ? $_GET['per_page'][0] : $_GET['per_page'];
  }
  $per_page = empty($per_page) ? 10 : $per_page;
 }
 
 $search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'][0] : '';
 $search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'][0] : '';
 echo '<div id="json_search_result">';

 //start search
 $search_array = $$class->field_a;
// pa($search_array);
 global $search_result_statement;

 //pre populate
 if (method_exists($$class, 'search_pre_populate')) {
  $ppl = call_user_func(array($$class, 'search_pre_populate'));
  if (!empty($ppl)) {
   $search_pre_populate_a = [];
   foreach ($ppl as $search_key => $search_val) {
    array_push($search_pre_populate_a, $search_val);
   }
   $_GET[$search_key] = $search_pre_populate_a;
  }
 }

 //column details
 if (empty($_GET['column_array'][0])) {
  if (property_exists($class, 'column')) {
   $column_array = $$class->column;
  } else {
   $column_array = $$class->field_a;
  }
 } else {
  $column_array = unserialize(base64_decode($_GET['column_array'][0]));
 }
 if (!empty($_GET['new_column'][0])) {
  $new_column = $_GET['new_column'][0];
  if (!empty($new_column)) {
   foreach ($new_column as $key => $value) {
    if ((!(is_array($value))) && (!empty($value))) {
     array_push($column_array, $value);
    }
   }
  }
 }

 $whereFields = [];
 $sqlWhereFields = [];
 $existing_search = [];
//to check number of criterias
 $noof_criteria = 0;

 foreach ($search_array as $key => $value) {
  if (!empty($_GET[$value][0])) {
   array_push($existing_search, $value);
   if (strpos($_GET[$value][0], ',') != false) {
    $comma_sep_search_parameters = explode(',', trim($_GET[$value][0]));
    $comma_sep_search_parameters_in_str = '(\'' . implode('\', \'', $comma_sep_search_parameters) . '\')';
    $whereFields[] = sprintf("%s IN %s ", $value, $comma_sep_search_parameters_in_str);
   } else {
    $entered_search_criteria = str_replace(' ', '%', trim($_GET[$value][0]));
    $entered_search_criteria_1s = substr($entered_search_criteria, 0, 1); //1 character
    $entered_search_criteria_2s = substr($entered_search_criteria, 0, 2); //2 characters
    $entered_search_criteria_m1s = substr($entered_search_criteria, 1); //minus 1 string
    $is_id_eq_search = !(in_array($entered_search_criteria_1s, ['=', '>', '<'])  OR  in_array($entered_search_criteria_2s, ['!=', '>=', '<=']));

    if (($is_id_eq_search) && (strpos($value, '_ID') !== false  OR  strpos($value, '_id') !== false)) {
     if ($entered_search_criteria == 'null') {
      $whereFields[] = " $value IS NULL ";
     } else {
      $whereFields[] = sprintf("%s = %s ", $value, trim(str_replace('=', '', $entered_search_criteria)));
     }
    } else if ($entered_search_criteria_1s == '=') {
     if ($entered_search_criteria_m1s == 'null') {
      $whereFields[] = " $value IS NULL ";
     } else {
      $whereFields[] = sprintf("%s = '%s' ", $value, trim(substr($entered_search_criteria, 1)));
     }
    } else if ($entered_search_criteria_2s == '!=') {
     $whereFields[] = sprintf("%s != '%s' ", $value, trim(substr($entered_search_criteria, 2)));
    } else if ($entered_search_criteria_1s == '>') {
     $whereFields[] = sprintf("%s > '%s' ", $value, trim(substr($entered_search_criteria, 1)));
    } else if ($entered_search_criteria_1s == '<') {
     $whereFields[] = sprintf("%s < '%s' ", $value, trim(substr($entered_search_criteria, 1)));
    } else {
     $whereFields[] = sprintf("%s LIKE '%%%s%%'", $value, trim(mysql_prep($entered_search_criteria)));
    }
   }
   $noof_criteria++;
  }
  if (!empty($_GET[$value][1])) {
   array_push($existing_search, $value);
   if (substr($_GET[$value][1], 0, 1) == '>') {
    $whereFields[] = sprintf("%s > '%s' ", $value, trim(substr($_GET[$value][1], 1)));
   } else if (substr($_GET[$value][1], 0, 1) == '<') {
    $whereFields[] = sprintf("%s < '%s' ", $value, trim(substr($_GET[$value][1], 1)));
   }
   $noof_criteria++;
  }
 }
 if ((!empty($_GET['report_name'])) && method_exists($$class, $_GET['report_name'][0])) {
  $report_name = $_GET['report_name'][0];
  $search_result_statement = call_user_func(array($$class, $report_name), $_GET);
  echo '<div id="searchResult"><div id="search_result" class="search_report">';
  echo '<ul class="inline-block"> <li id="export_excel_searchResult" class="clickable" title="' . gettext('Export to Excel') . '"><i class="fa fa-file-excel-o"></i></li>
              <li id="print_searchResult" class=" print clickable" title="' . gettext('Print') . '"><i class="fa fa-print"></i></li>
             </ul>';
  echo $search_result_statement;
  echo '</div></div></div>';
  return;
 } else if ((!empty($_GET['function_name']))) {
  $function_name = is_array($_GET['function_name']) ? $_GET['function_name'][0] : $_GET['function_name'];
  if (method_exists($$class, $function_name)) {
   $search_details = call_user_func(array($$class, $function_name), $_GET);
   $search_counts = $function_name . '_search_counts';
   $search_records = $function_name . '_search_records';
   $search_downloads = $function_name . '_search_downloads';
   $whereClause = implode(" AND ", $whereFields);
   $_GET['whereClause'] = $whereClause;
   $total_count = call_user_func(array($$class, $search_counts), $_GET);
   $search_result = call_user_func(array($$class, $search_records), $_GET);
   $all_download_sql = call_user_func(array($$class, $search_downloads), $_GET);
   if (!empty($per_page) && !empty($total_count)) {
    $pagination = new pagination($pageno, $per_page, $total_count);
    $pagination_statement = $pagination->show_pagination();
   }
  }
 } else if (method_exists($$class, 'search_records')) {
  $whereClause = implode(" AND ", $whereFields);
  $_GET['whereClause'] = $whereClause;
  $total_count = call_user_func(array($$class, 'search_counts'), $_GET);
  $search_result = call_user_func(array($$class, 'search_records'), $_GET);
  $all_download_sql = call_user_func(array($$class, 'search_downloads'), $_GET);
  if (!empty($per_page) && !empty($total_count)) {
   $pagination = new pagination($pageno, $per_page, $total_count);
   $pagination_statement = $pagination->show_pagination();
  }
 } else {
  //validate organization access where applicable
  if (property_exists($$class, 'bu_org_id') && in_array('bu_org_id', $$class->field_a)) {
   if (empty($_SESSION['user_org_access'])) {
    $no_organization_access = true;
    return;
   }
   
   $all_orgs_in_cls = " BU_ORG_ID IN ('" . implode("','", array_keys($_SESSION['user_org_access'])) . "')   OR   BU_ORG_ID IS NULL ";
  } else if (property_exists($$class, 'org_id') && in_array('org_id', $$class->field_a)) {
   if (empty($_SESSION['user_org_access'])) {
    $no_organization_access = true;
    return;
   }
   $all_orgs_in_cls = " ORG_ID IN ('" . implode("','", array_keys($_SESSION['user_org_access'])) . "')  OR   ORG_ID IS NULL ";
  }

  if (count($whereFields) > 0) {
   $whereClause = " WHERE " . implode(" AND ", $whereFields);
   $count_sql_all_records = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
   if (!empty($all_orgs_in_cls)) {
    $whereClause .= ' AND ' . $all_orgs_in_cls;
   }
   // And then create the SQL query itself.
   $sql = "SELECT * FROM " . $table_name . $whereClause;
   $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
   $all_download_sql = "SELECT * FROM  " . $table_name . $whereClause;
  } else {
   $count_sql_all_records = "SELECT COUNT(*) FROM " . $table_name;
   if (!empty($all_orgs_in_cls)) {
    $whereClause = ' WHERE ' . $all_orgs_in_cls;
   } else {
    $whereClause = null;
   }
   $sql = "SELECT * FROM " . $table_name . $whereClause;
   $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
   $all_download_sql = "SELECT * FROM  " . $table_name . $whereClause;
  }

  if (!empty($_GET['group_by'][0])) {
   $sum_element = $$class->search_groupBy_sum;
   $fetch_as = 'sum_' . $sum_element;
   $sql = "SELECT * , SUM($sum_element) as $fetch_as FROM " . $table_name . $whereClause;
   $sql .= " GROUP BY " . $_GET['group_by'][0];
   $count_sql .= " GROUP BY " . $_GET['group_by'][0];
   $all_download_sql = "SELECT  * , SUM($sum_element) FROM  " . $table_name . $whereClause;
   $all_download_sql .= " GROUP BY " . $_GET['group_by'][0];
  }

  $total_count = $class::count_all_by_sql($count_sql);
  $total_count_all = $class::count_all_by_sql($count_sql_all_records);

  $order_by_sql = '';
  if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
   if (is_array($search_order_by)) {
    $order_by_sql .= ' ORDER BY ';
    foreach ($search_order_by as $key_oby => $value_oby) {
     if (empty($search_asc_desc[$key_oby])) {
      $search_asc_desc[$key_oby] = ' DESC ';
     }
     $order_by_sql .= strtoupper($value_oby) . ' ' . $search_asc_desc[$key_oby] . ' ,';
    }
    $order_by_sql = rtrim($sql, ',');
   } else {
    $order_by_sql .= ' ORDER BY ' . strtoupper($search_order_by) . ' ' . $search_asc_desc;
   }
  }
  $all_download_sql .= $order_by_sql;

  if (!empty($per_page)) {
   $pagination = new pagination($pageno, $per_page, $total_count);
   $pagination_statement = $pagination->show_pagination();
   $per_page_sql = ino_perPageSql($per_page, $pagination->offset());
   if (!empty($per_page_sql)) {
    switch (DB_TYPE) {
     case 'ORACLE' :
      if (stripos($sql, 'WHERE') !== false) {
       $sql .= ' AND ' . $per_page_sql . ' ' . $order_by_sql;
      } else {
       $sql .= ' WHERE ' . $per_page_sql . ' ' . $order_by_sql;
      }
      break;

     default:
      $sql .= $order_by_sql . '  ' . $per_page_sql;
      break;
    }
   }
  }

//  echo "<br><br><br> sql is $sql and per page is $per_page";
  $search_result = $class::find_by_sql($sql);
//  pa($search_result);
 }


 if (method_exists($class, 'search_add_extra_fields')) {
  $class::search_add_extra_fields($search_result);
 }

 if (property_exists($class, 'search')) {
  foreach ($$class->search as $searchParaKey => $searchParaValue) {
   $s->setProperty($searchParaKey, $searchParaValue);
  }
 }
 $total_count_all = empty($total_count_all) ? $total_count : $total_count_all;
 $s->setProperty('result', $search_result);
 $s->setProperty('_searching_class', $class);
 $s->setProperty('_per_page', $per_page);
 $s->setProperty('primary_column_s', $primary_column);
 $s->setProperty('column_array_s', $column_array);
 $select_result_statement = $search->select_result_op();

 include_once(__DIR__ . '/../template/json_select_template.inc');
 echo '</div>';
}
?>
