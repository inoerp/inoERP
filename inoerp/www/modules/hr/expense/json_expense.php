<?php

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if (!empty($_GET['expense_template_id']) && ($_GET['find_expense_details'] = 1)) {
 echo '<div id="expense_template_details">';
 $expense_details = hr_expense_tpl_line::find_by_parent_id($_GET['expense_template_id']);

 if (empty($expense_details)) {
  return false;
 } else {
  echo '<option value=""></option>';
  foreach ($expense_details as $key => $value) {
   echo '<option value="' . $value->hr_expense_tpl_line_id . '" data-expense_category = "' . $value->expense_category . '" ';
   echo '>' . $value->expense_item . '</option>';
  }
 }
 echo '</div>';
}
?>

