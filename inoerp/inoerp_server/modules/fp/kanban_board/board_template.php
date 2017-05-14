<?php
$f = new inoform();
$bc = new ino_barcode();
$trnx_a = ['SUB_INV' => 'Subinventory Transfer', 'PUR_REQ' => 'Purchase Requisition'];
?>
<div id ="form_header" ><span class="heading"><?php echo gettext('Barcoded Min Max Board') ?> </span>
 <div class="tabContainer">
  <ul class="inRow asperWidth headerBgColor">
   <li><label><?php echo gettext('Inventory Org') ?> </label>
   <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $org_id, 'org_id'); ?>
   </li>
   <li><label><?php echo gettext('Subinventory') ?> </label>
   <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($org_id), 'subinventory_id', 'subinventory', $subinventory_id, 'subinventory_id'); ?>
   </li>
   <li><label><?php echo gettext('Planner') ?> </label>
   <?php echo $f->text_field('planner', ''); ?>
   </li>
   <li><label><?php echo gettext('Type') ?> </label>
   <?php echo $f->select_field_from_object('make_buy', item::manufacturing_item_types(), 'option_line_code', 'option_line_value', '', 'make_buy'); ?> 
   </li>
   <li>  <a name="show" href="form.php?class_name=fp_minmax_barcode_board_v" class="show onhand_id">	
     <i class="fa fa-refresh"></i></a> </li>

  </ul>
 </div>
 <div id="barcode_min_max_boardId">

  <?php
  if ($mm_details) {
   $mm_details_ai = new ArrayIterator($mm_details);
   $mm_details_ai->seek($position);
   while ($mm_details_ai->valid()) {
    $recod = $mm_details_ai->current();

    $onhand_min_delta = round($recod->onhand - $recod->minmax_min_quantity);
    $onhand_max_delta = round($recod->onhand - $recod->minmax_max_quantity);
    if (!empty($recod->minmax_min_quantity)) {
     if (empty($recod->minmax_min_quantity) && empty($recod->onhand)) {
      $height_p = 0;
     } else {
      try {
       if (empty($recod->minmax_min_quantity) || (empty($recod->onhand)) || $recod->minmax_min_quantity = '0.00000') {
        $height_p = 0;
       } else if ((!empty($recod->minmax_min_quantity)) && (!empty($recod->onhand))) {
        $height_p = round(($recod->onhand / $recod->minmax_min_quantity) * 100);
       }
      } catch (Exception $e) {
       $height_p = 0;
      }
     }

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
      $order_quantity = round($recod->total_delta, NUM_ROUND);
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
     <h3 class="panel-title"><input type="checkbox" name="data_loader_element" class="data_loader checkBox" title="Select To Transact" value="" >&nbsp;' . $recod->item_number . ' - ' . $recod->item_description . '</h3>
      <div class="progress">
  <div class="progress-bar progress-bar-success progress-bar-striped active" role="progressbar" 
    aria-valuenow="' . $height_p . '" aria-valuemin="0" aria-valuemax="100" style="width: ' . $height_p . '%" title="' . $height_p . '">
    <span class="sr-only">' . $height_p . '% Available</span>
  </div>
</div>
    </div>';
    echo '<div class="panel-body">';
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
    echo '<li>' . gettext('Min') . ' : ' . $recod->minmax_min_quantity . ' </li>';
    echo '<li>' . gettext('Max') . ' : ' . $recod->minmax_max_quantity . ' </li>';
    echo '<li>' . gettext('Min Delta') . ' :' . $onhand_min_delta . '</li><li>' . gettext('Max Delta') . ' :' . $onhand_max_delta . '</li>';
    echo '<li>' . gettext('Total Supp Delta') . ' :' . round($recod->total_delta, NUM_ROUND) . '</li>';
    echo '<li>' . gettext('On Hand') . ' :' . $recod->onhand . '</li>';
    echo '<li>' . gettext('Open PO') . ' :' . $recod->open_po . '</li>';
    echo '<li>' . gettext('Make/Buy') . ' :' . $recod->make_buy . '</li>';
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
