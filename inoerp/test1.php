<?php
$f = new inoform();
$bc = new ino_barcode();
$trnx_a = ['SUB_INV' => 'Subinventory Transfer', 'PUR_REQ' => 'Purchase Requisition'];
echo $f->select_field_from_array('transaction_type', $trnx_a, '', 'transaction_type', 'medium');
?>
<div id ="form_header" ><span class="heading">Barcoded Min Max Board </span>
 <div class="tabContainer">
  <ul class="inRow asperWidth headerBgColor">
   <li><lable>Inventory Org </lable>
   <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $org_id, 'org_id'); ?>
   </li>
   <li><lable>Sub Inventory </lable>
   <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($org_id), 'subinventory_id', 'subinventory', $subinventory_id, 'subinventory_id'); ?>
   </li>
   <li><lable>Planner </lable>
   <?php echo $f->text_field('planner', ''); ?>
   </li>
   <li><lable>Type </lable>
   <?php $f->select_field_from_object('make_buy', item::manufacturing_item_types(), 'option_line_code', 'option_line_value', $item->make_buy, 'make_buy'); ?> 
   </li>
   <li>  <a name="show3" href="form.php?class_name=fp_minmax_barcode_board_v" class="show3 onhand_id">	
     <i class="fa fa-refresh"></i></a> </li>
   <li><button class="button btn btn-success" role="button" onclick="startDataLoad()" >Transact</button></li>
  </ul>
 </div>
 <div id="barcode_min_max_boardId">

  <?php
  if ($mm_details) {
   $mm_details_ai = new ArrayIterator($mm_details);
   $mm_details_ai->seek($position);
   while ($mm_details_ai->valid()) {
    $recod = $mm_details_ai->current();

    if (empty($recod->open_po)) {
     $bgcolor = ($recod->onhand_delta >= 0 ) ? 'bgGreen' : 'bgRed';
    } else if ($recod->onhand_delta >= 0) {
     $bgcolor = 'bgGreen';
    } else {
     $bgcolor = ($recod->onhand_delta + $recod->open_po >= 0 ) ? 'bgPurple' : 'bgRed';
    }
    $onhand_min_delta = round($recod->onhand - $recod->minmax_min_quantity);
    $onhand_max_delta = round($recod->minmax_max_quantity - $recod->onhand);
    if ($recod->minmax_min_quantity) {
     $height_p = round(($recod->onhand / $recod->minmax_min_quantity) * 100);
     $height_p = $height_p >= 100 ? 100 : $height_p;
    } else {
     $height_p = 0;
    }
    if (empty($recod->open_po)) {
     $bgcolor = ($onhand_min_delta >= 0 ) ? 'bgGreen' : 'bgRed';
    } else if ($onhand_min_delta >= 0) {
     $bgcolor = 'bgGreen';
    } else if ($recod->open_po >= 0) {
     $bgcolor = ($onhand_min_delta + $recod->open_po >= 0 ) ? 'bgPurple' : 'bgRed';
    } else {
     $bgcolor = ($onhand_min_delta >= 0 ) ? 'bgGreen' : 'bgRed';
    }

    if ($recod->total_delta < 0) {
     if (!empty($recod->flm)) {
      $order_quantity = roundUpToNextMultiplier(abs($recod->total_delta), $recod->flm);
     } else {
      $order_quantity = $recod->total_delta;
     }
    } else {
     $order_quantity = 0;
    }

//    if ($recod->LOCATOR_ID) {
//     $desti_locator = findLocator_fromLocatorId_ora($recod->LOCATOR_ID);
//    } else {
//     $desti_locator = null;
//    }
//    if (!empty($recod->SUBINVENTORY_CODE)) {
//     $source_locator = findDefault_RecevingLocator_ByItemSubInventory($recod->ORGANIZATION_ID, $recod->SOURCE, $recod->INVENTORY_ITEM_ID);
//    } else {
//     $source_locator = null;
//    }

    echo "<div class='panel panel-default {$bgcolor} parent draggable_element medium'>";
    echo '<div class="panel-heading">
     <h3 class="panel-title"><input type="checkbox" name="data_loader_element" class="data_loader checkBox" title="Select To Transact" value="" >&nbsp;' . $recod->ITEM_NUMBER . ' - ' . $recod->DESCRIPTION . '</h3>
      <div class="progress">
  <div class="progress-bar progress-bar-success progress-bar-striped active" role="progressbar" 
    aria-valuenow="' . $height_p . '" aria-valuemin="0" aria-valuemax="100" style="width: ' . $height_p . '%" title="' . $height_p . '">
    <span class="sr-only">' . $height_p . '% Available</span>
  </div>
</div>
    </div>';
    echo '<div class="panel-body">';
    
        echo "<li class='{$bgcolor} parent draggable_element' ><ul class='child' title='{$height_p} %' data-height='{$height_p}' >";

    echo '<li>' . $recod->subinventory . '</li>';
    echo '<li>Min : ' . round($recod->minmax_min_quantity) . ' Max : ' . round($recod->minmax_max_quantity) . ' </li>';
    echo '<li>Min Delta :' . round($recod->onhand_delta) . '</li><li>Max Delta :' . round($recod->minmax_max_quantity - $recod->onhand) . '</li>';
    echo '<li>Onhand :' . round($recod->onhand) . '</li>';
    echo '<li>Open PO :' . round($recod->open_po) . '</li>';
    echo '</ul></li>';
    
    echo "<ul class='child'  title='{$height_p} %' data-height='{$height_p}'>";
    echo '<li class="item_number">' . $recod->item_number;
    echo ' : ' . $recod->planner . '</li>';
    echo '<li>';
    if (!empty($recod->item_number)) {
     $bc = new ino_barcode();
     $bc->setProperty('_text', $recod->item_number);
     $bc->draw_barcode();
     unset($bc);
    }
    echo '</li>';
    echo '<li>Min : ' . $recod->minmax_min_quantity . ' Max : ' . $recod->minmax_max_quantity . ' </li>';
    echo '<li>Min Delta :' . $onhand_min_delta . '</li><li>Max Delta :' . $onhand_max_delta . '</li>';
    echo '<li>Total Supp Delta :' . $recod->min_delta . '</li>';
    echo '<li>Onhand :' . $recod->onhand . '</li>';
    echo '<li>Make/Buy :' . $recod->make_buy . '</li>';
    if (!empty($recod->subinventory)) {
     echo '<li>Dest. SubInv :' . $recod->subinventory . '</li>';
     echo '<li>';
     if (!empty($recod->subinventory)) {
      $bc = new ino_barcode();
      $bc->setProperty('_text', $recod->subinventory);
      $bc->draw_barcode();
      unset($bc);
     }
     echo '</li>';
     echo '<br>';
//     echo '<li>Dest. Loc :' . $desti_locator . '</li>';
//     echo '<li>';
//     if (!empty($desti_locator)) {
//      $bc = new ino_barcode();
//      $bc->setProperty('_text', $desti_locator);
//      $bc->draw_barcode();
//      unset($bc);
//     }
//     echo '</li>';
    }
//    echo '<li>Source Type :' . $recod->SOURCE_TYPE . '</li>';
    echo '<li>Open PO :' . $recod->open_po . '</li>';
//    echo '<li>Source :' . $recod->SOURCE . '</li>';
//    echo '<li>';
//    if (!empty($recod->SOURCE)) {
//     $bc = new ino_barcode();
//     $bc->setProperty('_text', $recod->SOURCE);
//     $bc->draw_barcode();
//     unset($bc);
//    }
//    echo '</li>';
//    echo '<li>Source2 :' . $source_locator . '</li>';
//    echo '<li>';
//    if (!empty($source_locator)) {
//     $bc = new ino_barcode();
//     $bc->setProperty('_text', $source_locator);
//     $bc->draw_barcode();
//     unset($bc);
//    }
//    echo '</li>';
    echo '<li class="imp">Order Qty: ' . $order_quantity . '</li>';
    echo '<li>';
    if (!empty($order_quantity)) {
     $bc = new ino_barcode();
     $bc->setProperty('_text', $order_quantity);
     $bc->draw_barcode();
     unset($bc);
    }
    echo '</li>';
    echo '</ul></div>'; //end of panel body
    echo '</div>'; //end of panel
    $mm_details_ai->next();
    if ($mm_details_ai->key() == $position + $per_page) {
     break;
    }
   }
  }
  ?>

 </div>
</div>
<?php echo $pagination->show_pagination(); ?>