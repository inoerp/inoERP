function afterPost(inputData) {
  var data = inputData["data"];
  var itemIdM = data["itemIdM"];
  var runSql = true;
  if (itemIdM && itemIdM > 0) {
    runSql = false;
  }
  if (runSql) {
    request = {
      sql:
        "UPDATE inv_item  SET item_id_m = item_id  WHERE item_id_m IS NULL or item_id_m= 0;",
      dbType: "MySQL",
      connName: "Inoerp",
    };
   sqlUpdate(request);
  }

}

function beforePatch(inputData) {
  consoleLog (" In beforePatch 1 ");
  var data = inputData["data"];
  var vvAssignToOrgId = data["vvAssignToOrgId"];
  var invItemMasterId = data["invItemMasterId"];
  consoleLog(vvAssignToOrgId + " : " + vvAssignToOrgId);
  consoleLog(invItemMasterId + " : " + invItemMasterId);
  consoleLog (" In beforePatch 2 ");
  printNestedObject(data);
  if (vvAssignToOrgId && invItemMasterId) {
    request = {
      sql:
        " INSERT INTO inv_item (mdm_inventory_org_id, inv_item_master_id,image_file_id,product_line,product_line_percentage,locator_control,allow_negative_balance_cb,long_description,uom_code,origination_type,origination_date,item_type,item_status,inventory_item_cb,stockable_cb,transactable_cb,reservable_cb,cycle_count_enabled_cb,kit_cb,bom_enabled_cb,bom_type,costing_enabled_cb,inventory_asset_cb,default_cost_group,material_ac_id,material_oh_ac_id,overhead_ac_id,resource_ac_id,osp_ac_id,expense_ac_id,lot_uniqueness,lot_control,lot_prefix,lot_starting_number,serial_uniqueness,serial_control,serial_prefix,serial_starting_number,purchased_cb,use_asl_cb,invoice_matching,default_buyer,list_price,contract_item_type,duration_uom_id,receipt_sub_inventory,over_receipt_percentage,over_receipt_action,receipt_days_early,receipt_days_late,receipt_day_action,receipt_routing,weight_uom_id,weight,volume_uom_id,volume,dimension_uom_id,length,width,height,equipment_cb,electronic_format_cb,planning_method,planner,make_buy,wip_supply_subinventory,wip_supply_locator,fix_order_quantity,saftey_stock_days,saftey_stock_percentage,saftey_stock_quantity,fix_days_supply,fix_lot_multiplier,minimum_order_quantity,maximum_order_quantity,minmax_min_quantity,minmax_max_quantity,minmax_multibin_number,minmax_multibin_size,forecast_method,forecast_control,demand_timefence,planning_timefence,release_timefence,pre_processing_lt,post_processing_lt,processing_lt,cumulative_mfg_lt,cumulative_total_lt,lt_lot_size,build_in_wip_cb,wip_supply_type,customer_ordered_cb,internal_ordered_cb,shippable_cb,returnable_cb,invoiceable_cb,billing_type,service_request_cb,atp,picking_rule,sales_ac_id,cogs_ac_id,deffered_cogs_ac_id,ip_tax_class,op_tax_class,ap_payment_term,ar_payment_term,duration,rev_enabled_cb,rounding_option,onhand_with_rev_cb,item_rev_number,am_asset_type,am_activity_cause,am_activity_type,am_activity_source,discount_class) " +
        " SELECT '"+vvAssignToOrgId+"',inv_item_master_id,image_file_id,product_line,product_line_percentage,locator_control,allow_negative_balance_cb,long_description,uom_code,origination_type,origination_date,item_type,item_status,inventory_item_cb,stockable_cb,transactable_cb,reservable_cb,cycle_count_enabled_cb,kit_cb,bom_enabled_cb,bom_type,costing_enabled_cb,inventory_asset_cb,default_cost_group,material_ac_id,material_oh_ac_id,overhead_ac_id,resource_ac_id,osp_ac_id,expense_ac_id,lot_uniqueness,lot_control,lot_prefix,lot_starting_number,serial_uniqueness,serial_control,serial_prefix,serial_starting_number,purchased_cb,use_asl_cb,invoice_matching,default_buyer,list_price,contract_item_type,duration_uom_id,receipt_sub_inventory,over_receipt_percentage,over_receipt_action,receipt_days_early,receipt_days_late,receipt_day_action,receipt_routing,weight_uom_id,weight,volume_uom_id,volume,dimension_uom_id,length,width,height,equipment_cb,electronic_format_cb,planning_method,planner,make_buy,wip_supply_subinventory,wip_supply_locator,fix_order_quantity,saftey_stock_days,saftey_stock_percentage,saftey_stock_quantity,fix_days_supply,fix_lot_multiplier,minimum_order_quantity,maximum_order_quantity,minmax_min_quantity,minmax_max_quantity,minmax_multibin_number,minmax_multibin_size,forecast_method,forecast_control,demand_timefence,planning_timefence,release_timefence,pre_processing_lt,post_processing_lt,processing_lt,cumulative_mfg_lt,cumulative_total_lt,lt_lot_size,build_in_wip_cb,wip_supply_type,customer_ordered_cb,internal_ordered_cb,shippable_cb,returnable_cb,invoiceable_cb,billing_type,service_request_cb,atp,picking_rule,sales_ac_id,cogs_ac_id,deffered_cogs_ac_id,ip_tax_class,op_tax_class,ap_payment_term,ar_payment_term,duration,rev_enabled_cb,rounding_option,onhand_with_rev_cb,item_rev_number,am_asset_type,am_activity_cause,am_activity_type,am_activity_source,discount_class " +
        "FROM inv_item_master " +
        " WHERE 1 = 1 " +
        " AND inv_item_master_id  = '" +
        invItemMasterId +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlUpdate(request);

    return true;
  }


}


function xxbeforePatch(inputData) {
  consoleLog (" In beforePatch 1 ");
  var data = inputData["data"];
  var vvAssignToOrgId = data["vvAssignToOrgId"];
  var invItemMasterId = data["invItemMasterId"];
  consoleLog("vvAssignToOrgId" + " : " + vvAssignToOrgId);
  consoleLog("invItemMasterId" + " : " + invItemMasterId);
  printNestedObject(data);
  if (vvAssignToOrgId && invItemMasterId) {
    request = {
      sql:
        " INSERT INTO inv_item (inv_org_id, inv_item_master_id,item_number,item_description,image_file_id,product_line,product_line_percentage,locator_control,allow_negative_balance_cb,long_description,uom_code,origination_type,origination_date,item_type,item_status,inventory_item_cb,stockable_cb,transactable_cb,reservable_cb,cycle_count_enabled_cb,kit_cb,bom_enabled_cb,bom_type,costing_enabled_cb,inventory_asset_cb,default_cost_group,material_ac_id,material_oh_ac_id,overhead_ac_id,resource_ac_id,osp_ac_id,expense_ac_id,lot_uniqueness,lot_control,lot_prefix,lot_starting_number,serial_uniqueness,serial_control,serial_prefix,serial_starting_number,purchased_cb,use_asl_cb,invoice_matching,default_buyer,list_price,contract_item_type,duration_uom_id,receipt_sub_inventory,over_receipt_percentage,over_receipt_action,receipt_days_early,receipt_days_late,receipt_day_action,receipt_routing,weight_uom_id,weight,volume_uom_id,volume,dimension_uom_id,length,width,height,equipment_cb,electronic_format_cb,planning_method,planner,make_buy,wip_supply_subinventory,wip_supply_locator,fix_order_quantity,saftey_stock_days,saftey_stock_percentage,saftey_stock_quantity,fix_days_supply,fix_lot_multiplier,minimum_order_quantity,maximum_order_quantity,minmax_min_quantity,minmax_max_quantity,minmax_multibin_number,minmax_multibin_size,forecast_method,forecast_control,demand_timefence,planning_timefence,release_timefence,pre_processing_lt,post_processing_lt,processing_lt,cumulative_mfg_lt,cumulative_total_lt,lt_lot_size,build_in_wip_cb,wip_supply_type,customer_ordered_cb,internal_ordered_cb,shippable_cb,returnable_cb,invoiceable_cb,billing_type,service_request_cb,atp,picking_rule,sourcing_rule_id,sales_ac_id,cogs_ac_id,deffered_cogs_ac_id,ip_tax_class,op_tax_class,ap_payment_term,ar_payment_term,duration,rev_enabled_cb,rounding_option,onhand_with_rev_cb,item_rev_number,am_asset_type,am_activity_cause,am_activity_type,am_activity_source,discount_class) " +
        " SELECT '"+vvAssignToOrgId+"',inv_item_master_id,item_number,item_description,image_file_id,product_line,product_line_percentage,locator_control,allow_negative_balance_cb,long_description,uom_code,origination_type,origination_date,item_type,item_status,inventory_item_cb,stockable_cb,transactable_cb,reservable_cb,cycle_count_enabled_cb,kit_cb,bom_enabled_cb,bom_type,costing_enabled_cb,inventory_asset_cb,default_cost_group,material_ac_id,material_oh_ac_id,overhead_ac_id,resource_ac_id,osp_ac_id,expense_ac_id,lot_uniqueness,lot_control,lot_prefix,lot_starting_number,serial_uniqueness,serial_control,serial_prefix,serial_starting_number,purchased_cb,use_asl_cb,invoice_matching,default_buyer,list_price,contract_item_type,duration_uom_id,receipt_sub_inventory,over_receipt_percentage,over_receipt_action,receipt_days_early,receipt_days_late,receipt_day_action,receipt_routing,weight_uom_id,weight,volume_uom_id,volume,dimension_uom_id,length,width,height,equipment_cb,electronic_format_cb,planning_method,planner,make_buy,wip_supply_subinventory,wip_supply_locator,fix_order_quantity,saftey_stock_days,saftey_stock_percentage,saftey_stock_quantity,fix_days_supply,fix_lot_multiplier,minimum_order_quantity,maximum_order_quantity,minmax_min_quantity,minmax_max_quantity,minmax_multibin_number,minmax_multibin_size,forecast_method,forecast_control,demand_timefence,planning_timefence,release_timefence,pre_processing_lt,post_processing_lt,processing_lt,cumulative_mfg_lt,cumulative_total_lt,lt_lot_size,build_in_wip_cb,wip_supply_type,customer_ordered_cb,internal_ordered_cb,shippable_cb,returnable_cb,invoiceable_cb,billing_type,service_request_cb,atp,picking_rule,sourcing_rule_id,sales_ac_id,cogs_ac_id,deffered_cogs_ac_id,ip_tax_class,op_tax_class,ap_payment_term,ar_payment_term,duration,rev_enabled_cb,rounding_option,onhand_with_rev_cb,item_rev_number,am_asset_type,am_activity_cause,am_activity_type,am_activity_source,discount_class " +
        "FROM inv_item_master " +
        " WHERE 1 = 1 " +
        " AND inv_item_master_id  = '" +
        invItemMasterId +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(request);

    return true;
  }


}