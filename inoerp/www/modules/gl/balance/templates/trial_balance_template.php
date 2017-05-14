<h1 class="text-center"><?php echo gettext('Trial Balance'); ?></h1>
<h2 class="text-center"><?php echo $org_name ?></h2>
<table class ="balance_sheet table table-bordered simple_table" >
 <thead> 
  <tr>
   <th>Period Name</th>
   <th>Combination</th>
   <th>Description</th>
   <th>Balance Type</th>
   <th>Beginning Balance </th>
   <th>Debits</th>
   <th>Credits</th>
   <th>Ending Balance</th>
  </tr>
 </thead>
 <tbody>
  <?php
  foreach ($result as $record) {
   echo '<tr>';
   echo "<td> $record->period_name</td>";
   echo "<td> $record->combination</td>";
   echo "<td> $record->description</td>";
   echo "<td> $record->balance_type</td>";
   echo "<td> $record->begining_balance</td>";
   echo "<td> $record->debits</td>";
   echo "<td> $record->credits</td>";
   echo "<td> $record->ending_balance</td>";
   echo '</tr>';
  }
  ?>
  <tr>
   <td></td>
   <td></td>
   <td></td>
  </tr>
 </tbody>
</table>