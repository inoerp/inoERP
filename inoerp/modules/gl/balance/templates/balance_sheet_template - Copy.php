<h1>CONSOLIDATED BALANCE SHEETS</h1>
<h2><?php echo $org_name ?></h2>
<table class ="balance_sheet table table-bordered simple_table">
 <thead> 
  <tr>
   <th>Elements</th>
   <th>As of <?php echo $last_period; ?></th>
   <th>As of <?php echo $current_period; ?></th>
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

  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  $position = 0;
  $count = 0;
  $sum_amount = 0;
  $all_asset_parent_segments_ai->seek($position);
  while ($all_asset_parent_segments_ai->valid()) {
   $asset_parent_line = $all_asset_parent_segments_ai->current();
   $key_current = $all_asset_parent_segments_ai->key();
   $key_last = $key_current - 1;

   if ($key_last > 0) {
    $all_asset_parent_segments_ai->seek($key_last);
    $asset_parent_last_line = $all_asset_parent_segments_ai->current();
    $account_l = $asset_parent_last_line->code;
   } else {
    $account_l = 1;
   }
   $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $asset_parent_line->code);
   $sum_amount += $gl_balances->balance;
   ?>         
   <tr class="asset_parent_line<?php echo $count ?>">
    <td><?php echo $asset_parent_line->description; ?></td>
    <td><?php echo $gl_balances->balance ?></td>
    <td></td>
   </tr>
   <?php
   $all_asset_parent_segments_ai->next();
   $all_asset_parent_segments_ai->next();
   if ($asset_parent_line->code == '104000') {
    break;
   }
   $count = $count + 1;
  }
  ?>
  <tr class="label_three">
   <td>Total Cash & Receivables</td>
   <td><?php echo $sum_amount ?></td>
   <td></td>
  </tr>
  
  <?php

  function show_bs_rows(&$all_asset_parent_segments_ai, $account_code) {
   $count = $val_sum = 0;
   $ret_ar = [];
   $row_stmt = '';
   while ($all_asset_parent_segments_ai->valid()) {
    $asset_parent_line = $all_asset_parent_segments_ai->current();
    $key_current = $all_asset_parent_segments_ai->key();
    $key_last = $key_current - 1;

    if ($key_last > 0) {
     $all_asset_parent_segments_ai->seek($key_last);
     $asset_parent_last_line = $all_asset_parent_segments_ai->current();
     $account_l = $asset_parent_last_line->code;
    } else {
     $account_l = 1;
    }
    $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $asset_parent_line->code);
    if ($gl_balances) {
     $val_sum += $gl_balances->balance;
     $curr_bal = $gl_balances->balance;
    } else {
     $curr_bal = null;
    }
    $row_stmt .=' <tr class="asset_parent_line' . $count . '">';
    $row_stmt .= ' <td>' . $asset_parent_line->description . '</td>';
    $row_stmt .= ' <td>' . $curr_bal . '</td>';
    $row_stmt .= '<td></td>';
    $row_stmt .= '</tr>';
    $all_asset_parent_segments_ai->next();
    $all_asset_parent_segments_ai->next();
    if ($asset_parent_line->code == $account_code) {
     break;
    }
    $count = $count + 1;
   }
   $ret_ar['sum'] = $val_sum;
   $ret_ar['statement'] = $row_stmt;
   return $ret_ar;
  }

  $sum_deffered_income = 0;
  while ($all_asset_parent_segments_ai->valid()) {
   $asset_parent_line = $all_asset_parent_segments_ai->current();
   $key_current = $all_asset_parent_segments_ai->key();
   $key_last = $key_current - 1;

   if ($key_last > 0) {
    $all_asset_parent_segments_ai->seek($key_last);
    $asset_parent_last_line = $all_asset_parent_segments_ai->current();
    $account_l = $asset_parent_last_line->code;
   } else {
    $account_l = 1;
   }
   $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $asset_parent_line->code);
   $sum_deffered_income += $gl_balances->balance;
   ?>         
   <tr class="asset_parent_line<?php echo $count ?>">
    <td><?php echo $asset_parent_line->description; ?></td>
    <td><?php echo $gl_balances->balance ?></td>
    <td></td>
   </tr>
   <?php
   $all_asset_parent_segments_ai->next();
   $all_asset_parent_segments_ai->next();
   if ($asset_parent_line->code == '104500') {
    break;
   }
   $count = $count + 1;
  }
  ?>
  
  <?php
  $gross_inv_sum_amount = 0;
  while ($all_asset_parent_segments_ai->valid()) {
   $asset_parent_line = $all_asset_parent_segments_ai->current();
   $key_current = $all_asset_parent_segments_ai->key();
   $key_last = $key_current - 1;

   if ($key_last > 0) {
    $all_asset_parent_segments_ai->seek($key_last);
    $asset_parent_last_line = $all_asset_parent_segments_ai->current();
    $account_l = $asset_parent_last_line->code;
   } else {
    $account_l = 1;
   }
   $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $asset_parent_line->code);
   $gross_inv_sum_amount += $gl_balances->balance;
   ?>         
   <tr class="asset_parent_line<?php echo $count ?>">
    <td><?php echo $asset_parent_line->description; ?></td>
    <td><?php echo $gl_balances->balance ?></td>
    <td></td>
   </tr>
   <?php
   $all_asset_parent_segments_ai->next();
   $all_asset_parent_segments_ai->next();
   if ($asset_parent_line->code == '105300') {
    break;
   }
   $count = $count + 1;
  }
  ?>
  <tr class="label_three">
   <td>Gross Inventory</td>
   <td><?php echo $gross_inv_sum_amount ?></td>
   <td></td>
  </tr>
    <?php
  $ret_a = show_bs_rows($all_asset_parent_segments_ai, '105500');
  echo $ret_a['statement'];
  ?>
  <tr class="label_three">
   <td>Net Inventory</td>
   <td></td>
   <td></td>
  </tr>
  <tr class="label_two with_data">
   <td>Total Current Assets</td><td></td><td></td>
  </tr>
  
  <?php
  $ret_a = show_bs_rows($all_asset_parent_segments_ai, '106000');
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Non Current Assets</td><td></td><td></td>
  </tr>
  <tr class="label_one with_data">
   <td>TOTAL ASSETS</td><td></td><td></td>
  </tr>
  
  <tr class="label_one">
   <td>LIABILITIES & EQUITY:</td><td></td><td></td>
  </tr>
  
  <?php
  $coa->account_qualifier = 'L';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  $position = 0;
  $ret_a = show_bs_rows($all_asset_parent_segments_ai, '250000');
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Current Liabilities</td><td><?php echo $ret_a['sum']; ?></td><td></td>
  </tr>
  
  <?php
  $ret_a = show_bs_rows($all_asset_parent_segments_ai, '299999');
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Long-Term Liabilities</td>
   <td><?php echo $ret_a['sum']; ?></td><td></td>
  </tr>
  
  <?php
  $coa->account_qualifier = 'E';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  $position = 0;
  $ret_a = show_bs_rows($all_asset_parent_segments_ai, '399999');
  echo $ret_a['statement'];
  ?>
  <tr class="label_two with_data">
   <td>Total Shareholders Equity</td>
   <td><?php echo $ret_a['sum']; ?></td><td></td>
  </tr>

  <tr class="label_one with_data">
   <td>TOTAL LIABILITIES & EQUITY</td><td></td><td></td>
  </tr>
 </tbody>
</table>

