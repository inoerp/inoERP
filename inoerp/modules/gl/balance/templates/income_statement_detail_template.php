<h1 class="text-center"><?php echo gettext('STATEMENTS OF INCOME - DETAILED'); ?></h1>
<h2 class="text-center"><?php echo $org_name ?></h2>
<table class ="balance_sheet table table-bordered simple_table">
 <thead> 
  <tr>
   <th><?php echo gettext('Elements'); ?></th>
   <th><?php echo gettext('As of') . ' ' . $current_period; ?></th>
   <th><?php echo gettext('As of') . ' ' . $last_period; ?></th>
  </tr>
 </thead>
 <tbody>
  <tr class="label_one">
   <td><?php echo gettext('SALES'); ?></td><td></td><td></td>
  </tr>
  <?php
  if (!empty($_GET['org_id'][0])) {
   $org_id = $_GET['org_id'][0];
   $org_fin_details = org::find_financial_details_from_orgId($org_id);
   if (!empty($org_fin_details)) {
    $coa_id = $org_fin_details->coa_id;
   }
  }

  if (empty($coa_id)) {
   $coa_id = 1;
  }

  $coa = new coa();
  $coa->coa_id = $coa_id;
  $coa->only_parent = true;
  $coa->account_qualifier = 'R';
  $total_income = 0;

  $gbv = new gl_balance_v();
  $gbv->period_id_for_fs = $period_id;
  $gbv->account_code_low_limit = $coa->field4_low = '400000';
  $gbv->account_code_upper_limit = $coa->field4_high = '499999';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
  $gbv->fs_detail_data = 1;
  $ret_a = $gbv->financeStatement_showBalance();

  echo $ret_a['statement'];
  $sum_amount_revn = $ret_a['sum'];
  $total_income += $sum_amount_revn;
  ?>
  <tr class="label_three">
   <td><?php echo gettext('Total Sales'); ?></td>
   <td><?php echo $sum_amount_revn ?></td>
   <td></td>
  </tr>

  <tr class="label_one">
   <td><?php echo gettext('COST OF SALES'); ?></td><td></td><td></td>
  </tr>

  <?php
  $total_expense = 0;
  $coa->account_qualifier = 'X';
  $gbv->account_code_low_limit = $coa->field4_low = '500000';
  $gbv->account_code_upper_limit = $coa->field4_high = '599999';
  $all_expense_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_expense_segments_ai = new ArrayIterator($all_expense_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_expense_segments_ai;

  $ret_a = $gbv->financeStatement_showBalance();
  echo $ret_a['statement'];
  $sum_cos = $ret_a['sum'];
  $total_expense += $sum_cos;
  ?>
  <tr class="label_three">
   <td><?php echo gettext('Total Cost Of Sales'); ?></td>
   <td><?php echo $sum_cos ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td><?php echo gettext('Gross Profit'); ?></td>
   <td><?php echo $total_income + $sum_cos ?></td>
   <td></td>
  </tr>
  <tr class="label_one">
   <td><?php echo gettext('EXPENSES'); ?></td><td></td><td></td>
  </tr>

  <?php
  $gbv->account_code_low_limit = $coa->field4_low = '600000';
  $gbv->account_code_upper_limit = $coa->field4_high = '699999';
  $all_expense_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_expense_segments_ai = new ArrayIterator($all_expense_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_expense_segments_ai;
  $ret_a = $gbv->financeStatement_showBalance();
  echo $ret_a['statement'];
  $sum_cos_indirect = $ret_a['sum'];
  $total_expense += $sum_cos_indirect;
  ?>
  <tr class="label_three">
   <td><?php echo gettext('Total Expenses'); ?></td>
   <td><?php echo $sum_cos_indirect ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td><?php echo gettext('Operating Income'); ?></td>
   <td><?php echo $total_income + $total_expense ?></td>
   <td></td>
  </tr>

  <tr class="label_one">
   <td><?php echo gettext('OTHER INCOME & EXPENSE'); ?></td><td></td><td></td>
  </tr>
  <?php
  $gbv->account_code_low_limit = $coa->field4_low = '700000';
  $gbv->account_code_upper_limit = $coa->field4_high = '999999';
  $all_expense_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_expense_segments_ai = new ArrayIterator($all_expense_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_expense_segments_ai;

  $ret_a = $gbv->financeStatement_showBalance();
  echo $ret_a['statement'];
  $sum_other_exp = $ret_a['sum'];
  $total_expense += $sum_other_exp;
  ?>
  <tr class="label_three">
   <td><?php echo gettext('Total Other Income & Expenses'); ?></td>
   <td><?php echo $sum_other_exp ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td><?php echo gettext('PRETAX INCOME'); ?></td>
   <td><?php echo $total_income + $total_expense ?></td>
   <td></td>
  </tr>

 </tbody>
</table>
