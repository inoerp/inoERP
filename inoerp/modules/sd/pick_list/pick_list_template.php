<?php
if (empty($_SESSION['pick_list'])) {
 return;
}
?>
<div id ="form_header">
 <?php
 $data_ar = [];
 foreach ($_SESSION['pick_list'] as $record) {
  $curren_r = new stdClass();
  $sd_so_i = new sd_so_all_v();
  $sd_so_v = $sd_so_i->findBY_soLineId($record['value']);
  $curren_r->item_number = $sd_so_v->item_number;
  $curren_r->item_description = $sd_so_v->item_description;
  $curren_r->staging_subinventory = $sd_so_v->staging_subinventory;
  $curren_r->staging_locator = $sd_so_v->staging_locator;
  $picked_qty = 0;
  $onhand_v = onhand_v::find_by_itemId_orgId($sd_so_v->item_id_m, $sd_so_v->org);
  if (empty($onhand_v)) {
   $curren_r->line_quantity = 'No Onhand';
   array_push($data_ar, $curren_r);
   continue;
  }
  foreach ($onhand_v as $onhand_r) {
   if ($picked_qty >= $sd_so_v->line_quantity) {
    break;
   }
   $remaining_qty = $sd_so_v->line_quantity - $picked_qty;
   if ($onhand_r->onhand <= $remaining_qty) {
    $curren_r->line_quantity = $onhand_r->onhand;
    $picked_qty += $onhand_r->onhand;
    array_push($data_ar, $curren_r);
   }
  }
 }
 
 pa($data_ar);
 ?>
</div>
