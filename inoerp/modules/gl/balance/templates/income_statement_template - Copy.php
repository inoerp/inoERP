<h1 class="text-center">CONSOLIDATED STATEMENTS OF INCOME</h1>
<h2 class="text-center"><?php echo $org_name ?></h2>
<table class ="balance_sheet table table-bordered simple_table">
 <thead> 
  <tr>
   <th>Elements</th>
   <th>As of <?php echo $current_period; ?></th>
   <th>As of <?php echo $last_period; ?></th>
  </tr>
 </thead>
 <tbody>
  <tr class="label_one">
   <td>SALES :</td><td></td><td></td>
  </tr>
  <?php
  $coa = new coa();
  $coa->coa_id = 1;
  $coa->only_parent = true;
  $coa->account_qualifier = 'R';
  $total_income = 0;
  $all_revenue_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_revenue_parent_segments_ai = new ArrayIterator($all_revenue_parent_segments);
//  pa($all_revenue_parent_segments_ai);
  $ret_a = gl_balance_v::show_balance_rows($period_id, $all_revenue_parent_segments_ai, '499999', '400000');
  echo $ret_a['statement'];
  $sum_amount_revn = $ret_a['sum'];
  $total_income += $sum_amount_revn;
  ?>
  <tr class="label_three">
   <td>Total Sales</td>
   <td><?php echo $sum_amount_revn ?></td>
   <td></td>
  </tr>

  <tr class="label_one">
   <td>COST OF SALES :</td><td></td><td></td>
  </tr>

  <?php
  $total_expense = 0;
  $coa->account_qualifier = 'X';
  $all_expense_segments = $coa->findAll_accounts_from_coaId();
  $all_expense_segments_ai = new ArrayIterator($all_expense_segments);
  $ret_a =  gl_balance_v::show_balance_rows($period_id, $all_expense_segments_ai, '599999', '500000');
//  pa($all_expense_segments_ai);
  echo $ret_a['statement'];
  $sum_cos = $ret_a['sum'];
  $total_expense += $sum_cos;
  ?>
  <tr class="label_three">
   <td>Total Cost Of Sales</td>
   <td><?php echo $sum_cos ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td>Gross Profit</td>
   <td><?php echo $total_income + $sum_cos ?></td>
   <td></td>
  </tr>
  <tr class="label_one">
   <td>EXPENSES :</td><td></td><td></td>
  </tr>

  <?php
  $ret_a =  gl_balance_v::show_balance_rows($period_id, $all_expense_segments_ai, '699999', '600000');
  echo $ret_a['statement'];
  $sum_cos_indirect = $ret_a['sum'];
  $total_expense += $sum_cos_indirect;
  ?>
  <tr class="label_three">
   <td>Total Expenses</td>
   <td><?php echo $sum_cos_indirect ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td>Operating Income</td>
   <td><?php echo $total_income + $total_expense ?></td>
   <td></td>
  </tr>

  <tr class="label_one">
   <td>OTHER INCOME & EXPENSE :</td><td></td><td></td>
  </tr>
  <?php
  $ret_a =  gl_balance_v::show_balance_rows($period_id, $all_expense_segments_ai, '999999', '700000');
  echo $ret_a['statement'];
  $sum_other_exp = $ret_a['sum'];
  $total_expense += $sum_other_exp;
  ?>
  <tr class="label_three">
   <td>Total Other Income & Expenses</td>
   <td><?php echo $sum_other_exp ?></td>
   <td></td>
  </tr>

  <tr class="label_three">
   <td>PRETAX INCOME</td>
   <td><?php echo $total_income + $total_expense ?></td>
   <td></td>
  </tr>

 </tbody>
</table>

