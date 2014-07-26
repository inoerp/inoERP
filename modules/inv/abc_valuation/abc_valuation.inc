<?php
if (!empty($$class->inv_abc_valuation_id)) {
 $inv_abc_valuation_id = $$class->inv_abc_valuation_id;
 $result_link = HOME_URL. "search.php?inv_abc_valuation_result_id[]=&inv_abc_valuation_id[]=$inv_abc_valuation_id"
				 . "&seq_number[]=&item_id_m[]=&new_search_criteria=seq_number"
				 . "&column_array=YToxMDp7aTowO3M6Mjc6Imludl9hYmNfdmFsdWF0aW9uX3Jlc3VsdF9pZCI7aToxO3M6MjA6Imludl9hYmNfdmFsdWF0aW9uX2lkIjtpOjI7czoxMDoic2VxX251bWJlciI7aTozO3M6OToiaXRlbV9pZF9tIjtpOjQ7czoxMToiaXRlbV9udW1iZXIiO2k6NTtzOjE2OiJpdGVtX2Rlc2NyaXB0aW9uIjtpOjY7czoxMjoiY3VtX3F1YW50aXR5IjtpOjc7czo5OiJjdW1fdmFsdWUiO2k6ODtzOjg6InF1YW50aXR5IjtpOjk7czo1OiJ2YWx1ZSI7fQ%3D%3D"
				 . "&search_class=inv_abc_valuation_result&new_column[]=&search_order_by[]=seq_number&search_asc_desc[]=asc&per_page=100&class_name=inv_abc_valuation_result&submit_search=Search";

 $result_stmt = '<a class="button" target="_blank" href="'.$result_link.'" >Valuation Result</a>';
}else{
 $result_stmt = '<a class="button" href="#" >No Result</a>';
}
?>