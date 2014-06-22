<?php

if (!empty($_GET['submit_search']) && ($_GET['search_class'] === $class)) {
 		if (count($whereFields) > 0) {
		 $whereClause = " WHERE " . implode(" AND ", $whereFields);
		 // And then create the SQL query itself.
		 $sql = "SELECT * FROM " . $table_name . $whereClause;
		 $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
		 $all_download_sql = "SELECT * FROM  " . $table_name . $whereClause;
		} else {
		 $sql = "SELECT * FROM " . $table_name;
		 $count_sql = "SELECT COUNT(*) FROM " . $table_name;
		 $all_download_sql = "SELECT * FROM  " . $table_name;
		}

		if (!empty($_GET['group_by'])) {
		 $sql .= " GROUP BY " . $_GET['group_by'];
		 $count_sql .= " GROUP BY " . $_GET['group_by'];
		 $all_download_sql .= " GROUP BY " . $_GET['group_by'];
		}

		if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
		 if (is_array($search_order_by)) {
			$sql .= ' ORDER BY ';
			$all_download_sql .= ' ORDER BY ';
			foreach ($search_order_by as $key_oby => $value_oby) {
			 if (empty($search_asc_desc[$key_oby])) {
				$search_asc_desc[$key_oby] = ' DESC ';
			 }
			 $sql .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
			 $all_download_sql .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
			}
			$sql = rtrim($sql, ',');
			$all_download_sql = rtrim($all_download_sql, ',');
		 } else {
			$sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
			$all_download_sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
		 }
		}
//		echo "<br> sql is $sql";
		$total_count = $class::count_all_by_sql($count_sql);

		if (!empty($per_page)) {
		 $pagination = new pagination($pageno, $per_page, $total_count);
		 $pagination->setProperty('_query_string', $query_string);
		 $pagination_statement = $pagination->show_pagination();

		 $sql .=" LIMIT {$per_page} ";
		 $sql .=" OFFSET {$pagination->offset()}";
		}

		$search_result = $class::find_by_sql($sql);
}
?>