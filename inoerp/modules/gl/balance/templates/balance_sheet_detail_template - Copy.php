<h1 class="text-center">DETAILED BALANCE SHEETS</h1>
<h2 class="text-center"><?php echo $org_name ?></h2>
<table class ="balance_sheet table table-bordered simple_table">
 <thead> 
  <tr>
   <th>Elements</th>
   <th>As of <?php echo $current_period ; ?></th>
   <th>As of <?php echo $last_period ; ?></th>
  </tr>
 </thead>
 <tbody>
  <tr class="label_one">
   <td>ASSETS:</td><td></td><td></td>
  </tr>
  <?php
  $coa = new coa();
  $coa->coa_id = 1;
  $coa->only_parent = true;
  $coa->account_qualifier = 'A';
  $total_asset = 0;
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
//  pa($all_asset_parent_segments_ai);
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '104000');
  echo $ret_a['statement'];
  $sum_amount_cash_eq = $ret_a['sum'];
  $total_asset += $sum_amount_cash_eq;
  ?>
  <tr class="label_three">
   <td>Total Cash & Receivables</td>
   <td><?php echo $sum_amount_cash_eq ?></td>
   <td></td>
  </tr>

  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '104500');
  echo $ret_a['statement'];
  $sum_amount_deffered_ic_tax = $ret_a['sum'];
  $total_asset += $sum_amount_deffered_ic_tax;
  ?>

  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '105300');
  echo $ret_a['statement'];
  $sum_amount_gi = $ret_a['sum'];
  $total_asset += $sum_amount_gi;
  ?>
  <tr class="label_three">
   <td>Gross Inventory</td>
   <td><?php echo ($sum_amount_gi) ?></td>
   <td></td>
  </tr>

  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '105500');
  echo $ret_a['statement'];
  $sum_amount_reserve = $ret_a['sum'];
  $total_asset += $sum_amount_reserve;
  ?>
  <tr class="label_three">
   <td>Net Inventory</td>
   <td><?php echo ($sum_amount_gi - $sum_amount_reserve ) ?></td>
   <td></td>
  </tr>
  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '106000');
  $sum_pre_paid_exp = $ret_a['sum'];
  $total_asset += $sum_pre_paid_exp;
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Current Assets</td>
   <td><?php echo $total_asset; ?></td>
   <td></td>
  </tr>

  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '199999');
  $sum_nonc_asset = $ret_a['sum'];
  $total_asset += $sum_nonc_asset;
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Non Current Assets</td>
   <td><?php echo $sum_nonc_asset; ?></td>
   <td></td>
  </tr>

  <tr class="label_one with_data">
   <td>TOTAL ASSETS</td>
   <td><?php echo ($total_asset); ?></td>
   <td></td>
  </tr>

  <tr class="label_one">
   <td>LIABILITIES & EQUITY:</td><td></td><td></td>
  </tr>

  <?php
  $coa = new coa();
  $coa->coa_id = 1;
  $coa->only_parent = true;
  $coa->account_qualifier = 'L';
  $liability_sum = 0;
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  $position = 0;
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '250000', '200000');
  echo $ret_a['statement'];
  $liability_sum += $ret_a['sum'];
  ?>
  <tr class="label_two with_data">
   <td>Total Current Liabilities</td><td><?php echo $ret_a['sum']; ?></td><td></td>
  </tr>

  <?php
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '299999');
  echo $ret_a['statement'];
  $liability_sum += $ret_a['sum'];
  ?>
  <tr class="label_two with_data">
   <td>Total Long-Term Liabilities</td>
   <td><?php echo $ret_a['sum']; ?></td><td></td>
  </tr>
  <tr class="label_two with_data">
   <td>Total Liabilities</td>
   <td><?php echo $liability_sum; ?></td><td></td>
  </tr>

  <?php
  $coa = new coa();
  $coa->coa_id = 1;
  $equity_sum = 0;
  $coa->only_parent = true;
  $coa->account_qualifier = 'E';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  $position = 0;
  $ret_a = gl_balance_v::show_balance_rows_detailed($period_id, $all_asset_parent_segments_ai, '399999', '300000');
  echo $ret_a['statement'];
  $equity_sum += $ret_a['sum'];
  ?>

  <?php
  $ret_expected = (- $total_asset ) -  $liability_sum - $equity_sum  ;
  if (!empty(($ret_expected))) {
   echo '<tr class="label_two with_data">';
   echo '<td>Retained Earnings - Expected</td>';
   echo $ret_expected;
   echo '</tr>';
  }
  ?>

  <tr class="label_two with_data">
   <td>Total Shareholders Equity</td>
   <td><?php echo ($ret_a['sum'] + $ret_expected); ?></td><td></td>
  </tr>

  <tr class="label_one with_data">
   <td>TOTAL LIABILITIES & EQUITY</td>
   <td><?php echo ($liability_sum + $equity_sum + $ret_expected ); ?></td><td></td>
  </tr>
 </tbody>
</table>

