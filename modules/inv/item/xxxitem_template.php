<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="item_divId">
			<?php
			$current_page_path = "item.php";
			if (empty($readonly)) {
			 form::form_button($current_page_path);
			 $readonly = "";
			} else {
			 $readonly = 1;
			}
			?>
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			
			 <form action=""  method="post" id="item"  name="item">
				<div id ="form_header">
				 	  <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Categories</a></li>
          <li><a href="#tabsHeader-3">Catalogs</a></li>
          <li><a href="#tabsHeader-4">Cross References</a></li>
         </ul>
         <div id="tabsHeader-1">
          <div class="three_column"> 
           <ul>
            <li>
             <label><a href="find_item.php" class="item_id_popup">
               <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
              Item Id : </label>
             <input type="text" readonly name="item_id" value="<?php echo htmlentities($item->item_id); ?>" 
                    maxlength="50" id="item_id" placeholder="System generated number">
             <a name="show" href="item.php?item_id=" class="show item_id">
              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </li>
            <li>
             <label> Inventory Org : </label>
             <select name="org_id" id="org_id" class="org_id" required> 
              <option value=""> </option>
              <?php
              if (!empty($item->org_id )) {
               $inventory_org = org::find_all_inventory();
               foreach ($inventory_org as $key => $value) {
                echo '<option value="' . htmlentities($value->org_id) . '"';
                echo ($item->org_id == $value->org_id) ? " selected" : "";
                echo '>' . $value->org . '</option>';
                 }
              } else {
               $item_masters = org::find_all_item_master();
               foreach ($item_masters as $key => $value) {
                echo '<option value="' . htmlentities($value->org_id) . '"';
                //    echo $types[$i]->option_line_code == $org->type ? 'selected' : 'NONE';
                echo '>' . $value->org . '</option>';
               }
              }
              ?> 
             </select>
            </li>
            <li><label><a href="find_item_number.php" class="item_number_popup">
               <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>Item Number : </label>
             <input type="text" required name="item_number" value="<?php echo htmlentities($item->item_number); ?>" 
                    id="item_number" maxlength="50" >
             <a name="show" href="item.php?item_number=" class="show item_number">
              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </li>               
            <li><label>Item Description : </label>
             <input type="text" required id="description" name="description" value="<?php echo htmlentities($item->description); ?>" maxlength="50" >
            </li>

           </ul>
          </div>
         </div>
         <div id="tabsHeader-2">
          <div class="three_column"> 
           <ul>
            <li><label>Inventory Category : </label>
             <input type="text" name="ffu" value="<?php echo htmlentities($item->ef1); ?>" 
                    id="ffu" maxlength="50" >
            </li>               
            <li><label>Purchasing Category : </label>
             <input type="text" id="ef1" name="ef1" value="<?php echo htmlentities($item->ef1); ?>" maxlength="50" >
            </li>
            <li><label>Sales Category : </label>
             <input type="text" name="address_id" id="address_id" value="<?php echo htmlentities($item->ef1); ?>" 
                    maxlength="50" >
            </li>
            <li><label>Financial Category : </label>
             <input type="text" name="address_id" id="address_id" value="<?php echo htmlentities($item->ef1); ?>" 
                    maxlength="50" >
            </li>

           </ul>
          </div>
         </div>
         <div id="tabsHeader-3">
          <div class="three_column"> 
           <ul>
            <li><label>Physical : </label>
             <input type="text" name="ef1" value="<?php echo htmlentities($item->ef1); ?>" 
                    id="ef1" maxlength="50" >
            </li>               
            <li><label>Marketing : </label>
             <input type="text" id="ef1" name="ef1" value="<?php echo htmlentities($item->ef1); ?>" maxlength="50" >
            </li>
            <li><label>Specification : </label>
             <input type="text" name="address_id" id="address_id" value="<?php echo htmlentities($item->ef1); ?>" 
                    maxlength="50" >
            </li>
           </ul>
          </div>
         </div>
         <div id="tabsHeader-4">
          <div> 
           <ul>
            <li><label>Cross Item : </label>
             <input type="text" name="ef1" value="<?php echo htmlentities($item->ef1); ?>" 
                    id="ef1" maxlength="50" >
            </li>               
            <li><label>MPN : </label>
             <input type="text" id="ef1" name="ef1" value="<?php echo htmlentities($item->ef1); ?>" maxlength="50" >
            </li>
            <li><label>Customer Item : </label>
             <input type="text" name="address_id" id="address_id" value="<?php echo htmlentities($item->ef1); ?>" 
                    maxlength="50" >
            </li>
            <li><label>Replaced Item : </label>
             <input type="text" name="address_id" id="address_id" value="<?php echo htmlentities($item->ef1); ?>" 
                    maxlength="50" >
            </li>
           </ul>
          </div>
         </div>
        </div>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Sub Inventory Details </span>
 <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Inventory</a></li>
          <li><a href="#tabsLine-3">Sales</a></li>
          <li><a href="#tabsLine-4">Purchasing</a></li>
          <li><a href="#tabsLine-5">Manufacturing</a></li>
          <li><a href="#tabsLine-6">Planning</a></li>
          <li><a href="#tabsLine-7">Financial</a></li>
         </ul>
         <div id="tabsLine-1">
          <div class="three_column"> 
           <ul> 
            <li><label>Item Type : </label> 
             <select name="item_type" id="item_type" required> 
              <option value=""> </option>
              <?php
              $item_types = item::item_types();
              foreach ($item_types as $key => $value) {
               echo '<option value="' . htmlentities($value->option_line_code) . '"';
               echo $value->option_line_code == $item->item_type ? 'selected' : 'NONE';
               echo '>' . $value->option_line_code . '</option>';
              }
              ?> 

             </select>
            </li> 

            <li><label>UOM : </label> 
             <input type="text" required id="uom" name="uom"  value="<?php echo htmlentities($item->uom); ?>" maxlength="50" > 
            </li>
            <li><label>Item Status : </label> 
             <input type="text" required id="item_status" name="item_status" value="<?php echo htmlentities($item->item_status); ?>" maxlength="50" > 
            </li> 
            <li><label>Rev Enabled : </label> 
             <input type="checkbox" name="rev_enabled" 
                    value="<?php echo (empty($item->rev_enabled)) ? "1" : ""; ?>"  id="rev_enabled" 
                    <?php
                    if ($item->rev_enabled == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li> 
            <li><label>Rev Number : </label> 
             <input type="text" name="rev_number" value="<?php echo htmlentities($item->rev_number); ?>
                    " maxlength="50" id="rev_number"> 
            </li>
            <div class="medium_box itemMaster_Main"><box_heading>Long Descriptions </box_heading> 
             <li><textarea name="long_description" id="long_description" cols="22" rows="3">
               <?php echo htmlentities($item->long_description); ?>
              </textarea>
             </li>
            </div>
            <div class="large_box itemMaster_leadtimes"><box_heading>Lead time Information </box_heading> 
             <li><label>Pre Processing : </label> 
              <input type="number" name="pre_processing_lt" value="<?php echo htmlentities($item->pre_processing_lt); ?>" 
                     maxlength="50"  id="pre_processing_lt"> 
             </li>
             <li><label>Processing : </label> 
              <input type="number" name="processing_lt" value="<?php echo htmlentities($item->processing_lt); ?>" 
                     maxlength="50"  id="processing_lt"> 
             </li> 
             <li><label>Post Processing : </label> 
              <input type="number" name="post_processing_lt" value="<?php echo htmlentities($item->post_processing_lt); ?>
                     " maxlength="50" id="post_processing_lt"> 
             </li> 
             <li><label>Cumulative Mfg : </label> 
              <input type="number" name="cumulative_mfg_lt" value="<?php echo htmlentities($item->cumulative_mfg_lt); ?>
                     " maxlength="50" id="cumulative_mfg_lt"> 
             </li>
             <li><label>Cumulative Total : </label> 
              <input type="number" name="cumulative_total_lt" value="<?php echo htmlentities($item->cumulative_total_lt); ?>
                     " maxlength="50" id="cumulative_total_lt"> 
             </li>
             <li><label>Lead time Lot Size : </label> 
              <input type="number" name="lt_lot_size" value="<?php echo htmlentities($item->lt_lot_size); ?>
                     " maxlength="50" id="lt_lot_size"> 
             </li>
            </div>
           </ul> 
          </div> 
          <!--end of tab1 div three_column-->
         </div> 
         <!--end of tab1-->
         <div id="tabsLine-2">
          <div class="three_column"> 
           <ul>
            <li><label>Inventory Item : </label> 
             <input type="checkbox" name="inventory_item" 
                    value="<?php echo (empty($item->inventory_item)) ? "1" : ""; ?>"  id="inventory_item" 
                    <?php
                    if ($item->inventory_item == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Stockable : </label> 
             <input type="checkbox" name="stockable" 
                    value="<?php echo (empty($item->stockable)) ? "1" : ""; ?>"  id="stockable" 
                    <?php
                    if ($item->stockable == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Transactable : </label> 
             <input type="checkbox" name="transactable" 
                    value="<?php echo (empty($item->transactable)) ? "1" : ""; ?>"  id="transactable" 
                    <?php
                    if ($item->transactable == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Reservable : </label> 
             <input type="checkbox" name="reservable" 
                    value="<?php echo (empty($item->reservable)) ? "1" : ""; ?>"  id="reservable" 
                    <?php
                    if ($item->reservable == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Cycle count enabled : </label> 
             <input type="checkbox" name="cycle_count_enabled" 
                    value="<?php echo (empty($item->cycle_count_enabled)) ? "1" : ""; ?>"  id="cycle_count_enabled" 
                    <?php
                    if ($item->cycle_count_enabled == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Equipment : </label> 
             <input type="checkbox" name="equipment" 
                    value="<?php echo (empty($item->equipment)) ? "1" : ""; ?>"  id="equipment" 
                    <?php
                    if ($item->equipment == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Electronic Format : </label> 
             <input type="checkbox" name="electronic_format" 
                    value="<?php echo (empty($item->electronic_format)) ? "1" : ""; ?>"  id="electronic_format" 
                    <?php
                    if ($item->electronic_format == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Item Rev Enabled : </label> 
             <input type="checkbox" name="rev_enabled" 
                    value="<?php echo (empty($item->rev_enabled)) ? "1" : ""; ?>"  id="rev_enabled" 
                    <?php
                    if ($item->rev_enabled == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li> 
            <li><label>Rev Number : </label> 
             <input type="text" name="rev_number" value="<?php echo htmlentities($item->rev_number); ?>
                    " maxlength="50" id="rev_number"> 
            </li>
            <li><label>Locator Control : </label> 
             <input type="text" name="locator_control" value="<?php echo htmlentities($item->locator_control); ?>
                    " maxlength="50" id="locator_control"> 
            </li>
            <div class="small_box itemMaster_lot"><box_heading>Lot Information </box_heading> 
             <li><label>Lot Uniqueness : </label> 
              <input type="text" name="lot_uniqueness" value="<?php echo htmlentities($item->lot_uniqueness); ?>" 
                     maxlength="50"  id="lot_uniqueness"> 
             </li>
             <li><label>Lot Generation : </label> 
              <input type="text" name="lot_generation" value="<?php echo htmlentities($item->lot_generation); ?>" 
                     maxlength="50"  id="lot_generation"> 
             </li> 
             <li><label>Lot Prefix : </label> 
              <input type="text" name="lot_prefix" value="<?php echo htmlentities($item->lot_prefix); ?>
                     " maxlength="50" id="lot_prefix"> 
             </li> 
             <li><label>Lot Starting Number : </label> 
              <input type="text" name="lot_starting_number" value="<?php echo htmlentities($item->lot_starting_number); ?>
                     " maxlength="50" id="lot_starting_number"> 
             </li>
            </div>
            <div class="small_box itemMaster_lot"><box_heading>Serial Information </box_heading> 
             <li><label>Serial Uniqueness : </label> 
              <input type="text" name="serial_uniqueness" value="<?php echo htmlentities($item->serial_uniqueness); ?>" 
                     maxlength="50"  id="serial_uniqueness"> 
             </li>
             <li><label>Serial Generation : </label> 
              <input type="text" name="serial_generation" value="<?php echo htmlentities($item->serial_generation); ?>" 
                     maxlength="50"  id="serial_generation"> 
             </li> 
             <li><label>Serial Prefix : </label> 
              <input type="text" name="serial_prefix" value="<?php echo htmlentities($item->serial_prefix); ?>
                     " maxlength="50" id="serial_prefix"> 
             </li> 
             <li><label>Serial Starting Number : </label> 
              <input type="text" name="serial_starting_number" value="<?php echo htmlentities($item->serial_starting_number); ?>
                     " maxlength="50" id="serial_starting_number"> 
             </li>
            </div>
            <div class="large_box itemMaster_physical"><box_heading>Item Information </box_heading> 
             <li><label>Weight UOM : </label> 
              <input type="text" name="weight_uom" value="<?php echo htmlentities($item->weight_uom); ?>" 
                     maxlength="50"  id="weight_uom"> 
             </li>
             <li><label>Weight : </label> 
              <input type="text" name="weight" value="<?php echo htmlentities($item->weight); ?>" 
                     maxlength="50"  id="weight"> 
             </li> 
             <li><label>Volume UOM : </label> 
              <input type="text" name="volume_uom" value="<?php echo htmlentities($item->volume_uom); ?>" maxlength="50" id="volume_uom"> 
             </li> 
             <li><label>Volume : </label> 
              <input type="text" name="volume" value="<?php echo htmlentities($item->volume); ?>" maxlength="50" id="volume"> 
             </li>
             <li><label>Dimension UOM : </label> 
              <input type="text" name="dimension_uom" value="<?php echo htmlentities($item->dimension_uom); ?>
                     " maxlength="50" id="dimension_uom"> 
             </li>
             <li><label>Length : </label> 
              <input type="text" name="length" value="<?php echo htmlentities($item->length); ?>" maxlength="50" id="length"> 
             </li>
             <li><label>Width : </label> 
              <input name="text" value="<?php echo htmlentities($item->width); ?>" maxlength="50" id="width"> 
             </li>
             <li><label>Volume : </label> 
              <input type="text" name="volume" value="<?php echo htmlentities($item->volume); ?>" maxlength="50" id="volume"> 
             </li>
            </div>
           </ul>

          </div> 
          <!--                end of tab2 div three_column-->
         </div>
         <!--end of tab2 (purchasing)!!!! start of sales tab-->
         <div id="tabsLine-3">
          <div class="three_column"> 
           <ul>
            <li><label>Customer Ordered : </label> 
             <input type="checkbox" name="customer_ordered" 
                    value="<?php echo (empty($item->customer_ordered)) ? "1" : ""; ?>"  id="customer_ordered" 
                    <?php
                    if ($item->customer_ordered == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Internal Ordered : </label> 
             <input type="checkbox" name="internal_ordered" 
                    value="<?php echo (empty($item->internal_ordered)) ? "1" : ""; ?>"  id="internal_ordered" 
                    <?php
                    if ($item->internal_ordered == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Shippable : </label> 
             <input type="checkbox" name="shippable" 
                    value="<?php echo (empty($item->shippable)) ? "1" : ""; ?>"  id="shippable" 
                    <?php
                    if ($item->shippable == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Returnable : </label> 
             <input type="checkbox" name="returnable" 
                    value="<?php echo (empty($item->returnable)) ? "1" : ""; ?>"  id="returnable" 
                    <?php
                    if ($item->returnable == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <div class="small_box rule"><box_heading>Rule Information </box_heading> 
             <li><label>Available to promise : </label> 
              <input type="text" name="atp" value="<?php echo htmlentities($item->atp); ?>" 
                     maxlength="50"  id="atp"> 
             </li>
             <li><label>Picking Rule : </label> 
              <input type="text" name="picking_rule" value="<?php echo htmlentities($item->picking_rule); ?>" 
                     maxlength="50"  id="picking_rule"> 
             </li>
             <li><label>Sourcing Rule : </label> 
              <input type="text" name="sourcing_rule" value="<?php echo htmlentities($item->sourcing_rule); ?>" 
                     maxlength="50"  id="sourcing_rule"> 
             </li>
            </div>
           </ul>

          </div> 
          <!--                end of tab2 div three_column-->
         </div>
         <!--end of tab3 (sales)!!!!start of purchasing tab-->
         <div id="tabsLine-4">
          <div class="three_column"> 
           <ul>
            <li><label>Purchased : </label> 
             <input type="checkbox" name="purchased" 
                    value="<?php echo (empty($item->purchased)) ? "1" : ""; ?>"  id="purchased" 
                    <?php
                    if ($item->purchased == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>ASL usage mandatory : </label> 
             <input type="checkbox" name="use_asl" 
                    value="<?php echo (empty($item->use_asl)) ? "1" : ""; ?>"  id="use_asl" 
                    <?php
                    if ($item->use_asl == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>Invoice Matching : </label> 
             <input type="text" name="invoice_matching" value="<?php echo htmlentities($item->invoice_matching); ?>" 
                    size="25" maxlength="150"  id="invoice_matching"> 
            </li>
            <li><label>Default Buyer : </label> 
             <input type="text" name="default_buyer" value="<?php echo htmlentities($item->default_buyer); ?>" 
                    size="25" maxlength="150"  id="default_buyer"> 
            </li>
            <li><label>List Price : </label> 
             <input type="text" name="list_price" value="<?php echo htmlentities($item->list_price); ?>" 
                    size="25" maxlength="150"  id="list_price"> 
            </li> 
            <li><label>UN Number : </label> 
             <input type="text" name="un_number" value="<?php echo htmlentities($item->un_number); ?>"
                    size="25" maxlength="150" id="un_number"> 
            </li> 
            <div class="large_box itemMaster_receipt"><box_heading>Receipt Information </box_heading> 
             <li><label>Receipt Routing : </label> 
              <input type="text" name="receipt_routing" value="<?php echo htmlentities($item->receipt_routing); ?>
                     " maxlength="50" id="receipt_routing"> 
             </li> 
             <li><label>Receiving SubInventory : </label> 
              <input type="text" name="receipt_sub_inventory" value="<?php echo htmlentities($item->receipt_sub_inventory); ?>
                     " maxlength="50" id="receipt_sub_inventory"> 
             </li> 
             <li><label>Over Receipt % : </label> 
              <input type="number" name="over_receipt_percentage" value="<?php echo htmlentities($item->over_receipt_percentage); ?>" 
                     maxlength="50"  id="over_receipt_percentage"> 
             </li>
             <li><label>Over Receipt Action : </label> 
              <input type="text" name="over_receipt_action" value="<?php echo htmlentities($item->over_receipt_action); ?>" 
                     maxlength="50"  id="over_receipt_action"> 
             </li>
             <li><label>Allowed early receipt days : </label> 
              <input type="number" name="receipt_days_early" value="<?php echo htmlentities($item->receipt_days_early); ?>" 
                     maxlength="50"  id="receipt_days_early"> 
             </li> 
             <li><label>Allowed late receipt days : </label> 
              <input type="number" name="receipt_days_late" value="<?php echo htmlentities($item->receipt_days_late); ?>" maxlength="50" id="receipt_days_late"> 
             </li> 
             <li><label>Receipt Day Action : </label> 
              <input type="text" name="receipt_day_action" value="<?php echo htmlentities($item->receipt_day_action); ?>" maxlength="50" id="receipt_day_action"> 
             </li>
            </div>
           </ul>

          </div> 
         </div>
         <!--end of tab4(purchasing)!!! start of MFG tab-->
         <div id="tabsLine-5">
          <div class="three_column"> 
           <ul>
            <li><label>Make or Buy : </label> 
             <input type="text" name="make_buy" required value="<?php echo htmlentities($item->make_buy); ?>" 
                    size="25" maxlength="150"  id="make_buy"> 
            </li>
            <li><label>BOM Enabled : </label> 
             <input type="checkbox" name="bom_enabled" 
                    value="<?php echo (empty($item->bom_enabled)) ? "1" : ""; ?>"  id="bom_enabled" 
                    <?php
                    if ($item->bom_enabled == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>BOM Type: </label> 
             <input type="text" name="bom_type" value="<?php echo htmlentities($item->bom_type); ?>" 
                    size="25" maxlength="150"  id="bom_type"> 
            </li>
            <li><label>Build in WIP : </label> 
             <input type="checkbox" name="build_in_wip" 
                    value="<?php echo (empty($item->purchased)) ? "1" : ""; ?>"  id="build_in_wip" 
                    <?php
                    if ($item->build_in_wip == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li>
            <li><label>WIP Supply Type: </label> 
             <input type="text" name="wip_supply_type" value="<?php echo htmlentities($item->wip_supply_type); ?>" 
                    size="25" maxlength="150"  id="wip_supply_type"> 
            </li>
            <div class="small_box rule"><box_heading>Cost Information </box_heading> 
             <li><label>Costing Enabled : </label> 
              <input type="checkbox" name="costing_enabled" 
                     value="<?php echo (empty($item->costing_enabled)) ? "1" : ""; ?>"  id="costing_enabled" 
                     <?php
                     if ($item->costing_enabled == 1) {
                      echo " checked";
                     } else {
                      echo "";
                     }
                     ?> > 
             </li>
             <li><label>Inventory Asset : </label> 
              <input type="checkbox" name="inventory_asset" 
                     value="<?php echo (empty($item->inventory_asset)) ? "1" : ""; ?>"  id="inventory_asset" 
                     <?php
                     if ($item->inventory_asset == 1) {
                      echo " checked";
                     } else {
                      echo "";
                     }
                     ?> > 
             </li>
             <li><label>COGS Ac : </label> 
              <input type="text" name="cogs_ac" value="<?php echo htmlentities($item->cogs_ac); ?>" 
                     maxlength="50"  id="cogs_ac"> 
             </li>
             <li><label>Deferred COGS Ac : </label> 
              <input type="text" name="deffered_cogs_ac" value="<?php echo htmlentities($item->deffered_cogs_ac); ?>" 
                     maxlength="50"  id="deffered_cogs_ac"> 
             </li>
            </div>
           </ul>

          </div> 
         </div>
         <!--end of tab5 (Manufacturing)!! start of planning -->
         <div id="tabsLine-6">
          <div class="three_column"> 
           <ul>
            <li><label>Allow Negative Balance: </label> 
             <input type="checkbox" name="allow_negative_balance" 
                    value="<?php echo (empty($item->allow_negative_balance)) ? "1" : ""; ?>"  id="allow_negative_balance" 
                    <?php
                    if ($item->allow_negative_balance == 1) {
                     echo " checked";
                    } else {
                     echo "";
                    }
                    ?> > 
            </li> 
            <li><label>Planner: </label> 
             <input type="text" name="planner" value="<?php echo htmlentities($item->planner); ?>" 
                    size="25" maxlength="50"  id="planner"> 
            </li>
            <li><label>Planning Method: </label> 
             <input type="text" name="planning_method" value="<?php echo htmlentities($item->planning_method); ?>" 
                    size="25" maxlength="50"  id="planning_method"> 
            </li>
            <li><label>Forecast Method: </label> 
             <input type="text" name="forecast_method" value="<?php echo htmlentities($item->forecast_method); ?>" 
                    size="25" maxlength="50"  id="forecast_method"> 
            </li>
            <li><label>Forecast Control: </label> 
             <input type="text" name="forecast_control" value="<?php echo htmlentities($item->forecast_control); ?>" 
                    size="25" maxlength="50"  id="forecast_control"> 
            </li>
            <div class="small_box order_modifiers"><box_heading>Order Modifiers </box_heading> 
             <li><label>Fix Order Quantity : </label> 
              <input type="number" name="fix_order_quantity" value="<?php echo htmlentities($item->fix_order_quantity); ?>" 
                     maxlength="50"  id="fix_order_quantity"> 
             </li>
             <li><label>Fix Days Supply : </label> 
              <input type="number" name="fix_days_supply" value="<?php echo htmlentities($item->fix_days_supply); ?>" 
                     maxlength="50"  id="fix_days_supply"> 
             </li>
             <li><label>Fix Lot Multiplier : </label> 
              <input type="number" name="fix_lot_multiplier" value="<?php echo htmlentities($item->fix_lot_multiplier); ?>" 
                     maxlength="50"  id="fix_lot_multiplier"> 
             </li>
             <li><label>Minimum Order Quantity : </label> 
              <input type="number" name="minimum_order_quantity" value="<?php echo htmlentities($item->minimum_order_quantity); ?>" 
                     maxlength="50"  id="minimum_order_quantity"> 
             </li>
             <li><label>Maximum Order Quantity : </label> 
              <input type="number" name="maximum_order_quantity" value="<?php echo htmlentities($item->maximum_order_quantity); ?>" 
                     maxlength="50"  id="maximum_order_quantity"> 
             </li>
            </div> 
            <div class="small_box timefence"><box_heading>Time Fences </box_heading> 
             <li><label>Demand Time Fence : </label> 
              <input type="number" name="demand_timefence" value="<?php echo htmlentities($item->demand_timefence); ?>" 
                     maxlength="50"  id="demand_timefence"> 
             </li>
             <li><label>Planning Time Fence : </label> 
              <input type="number" name="planning_timefence" value="<?php echo htmlentities($item->planning_timefence); ?>" 
                     maxlength="50"  id="planning_timefence"> 
             </li>
             <li><label>Release Time Fence : </label> 
              <input type="number" name="release_timefence" value="<?php echo htmlentities($item->release_timefence); ?>" 
                     maxlength="50"  id="release_timefence"> 
             </li>
            </div> 
           </ul>

          </div> 
         </div>
         <!--end of tab6 (planning)...start of lead times-->
         <div id="tabsLine-7">
          <div class="three_column"> 
           <ul>
            <li><label>Invoicable: </label> 
             <input type="text" name="invoiceable" value="<?php echo htmlentities($item->invoiceable); ?>" 
                    size="25" maxlength="50"  id="invoiceable"> 
            </li>
            <li><label>Invoice Matching: </label> 
             <input type="text" name="invoice_matching" value="<?php echo htmlentities($item->invoice_matching); ?>" 
                    size="25" maxlength="50"  id="invoice_matching"> 
            </li>
            <li><label>AP Tax: </label> 
             <input type="text" name="ap_tax" value="<?php echo htmlentities($item->ap_tax); ?>" 
                    size="25" maxlength="50"  id="ap_tax"> 
            </li>
            <li><label>Sales Tax: </label> 
             <input type="text" name="sales_tax" value="<?php echo htmlentities($item->sales_tax); ?>" 
                    size="25" maxlength="50"  id="sales_tax"> 
            </li>
            <li><label>AP Payment Term: </label> 
             <input type="text" name="ap_payment_term" value="<?php echo htmlentities($item->ap_payment_term); ?>" 
                    size="25" maxlength="50"  id="ap_payment_term"> 
            </li>
            <li><label>AR Payment Term: </label> 
             <input type="text" name="ar_payment_term" value="<?php echo htmlentities($item->ar_payment_term); ?>" 
                    size="25" maxlength="50"  id="ar_payment_term"> 
            </li>
           </ul>
          </div> 
          <div class="two_column">
           <ul>
            <li><label>Material Ac: </label> 
             <input type="text" name="material_ac" value="<?php echo htmlentities($item->material_ac_id); ?>" 
                    size="75" maxlength="150"  id="material_ac"> 
            </li>
            <li><label>Material OH Ac: </label> 
             <input type="text" name="material_oh_ac" value="<?php echo htmlentities($item->material_oh_ac); ?>" 
                    size="75" maxlength="150"  id="material_oh_ac"> 
            </li>
            <li><label>OverHead Ac: </label> 
             <input type="text" name="overhead_ac" value="<?php echo htmlentities($item->overhead_ac); ?>" 
                    size="75" maxlength="150"  id="overhead_ac"> 
            </li>
            <li><label>Resource Ac: </label> 
             <input type="text" name="resource_ac" value="<?php echo htmlentities($item->resource_ac); ?>" 
                    size="75" maxlength="150"  id="resource_ac"> 
            </li>
            <li><label>Expense Ac: </label> 
             <input type="text" name="expense_ac" value="<?php echo htmlentities($item->expense_ac); ?>" 
                    size="75" maxlength="150"  id="expense_ac"> 
            </li>
            <li><label>OSP Ac: </label> 
             <input type="text" name="osp_ac" value="<?php echo htmlentities($item->osp_ac); ?>" 
                    size="75" maxlength="150"  id="osp_ac"> 
            </li>
            <li><label>Sales Ac: </label> 
             <input type="text" name="sales_ac" value="<?php echo htmlentities($item->sales_ac); ?>" 
                    size="75" maxlength="150"  id="sales_ac"> 
            </li>
           </ul>
          </div> 
         </div>
         <!--                  end of tab7 (Fiance)-->

        </div>
				</div> 
			 </form>
		
			<!--END OF FORM HEADER-->
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
