<? ob_start(); ?>
<?php
defined('DS')        ? null : define ('DS', '/');
defined('HOME_DIR')  ? null : define('HOME_DIR', 'C:'.DS.'wamp'.DS.'www'.DS.'inoerp');
defined('HOME_URL')  ? null : define("HOME_URL", "http://localhost/inoerp/");
/*---------------------Dont Update anything Below--------------------------------------*/
//Basic Paths 
defined('INC_PATH')  ? null : define('INC_PATH' , HOME_DIR.DS.'includes');
defined('INC_BASICS')  ? null : define('INC_BASICS' , INC_PATH.DS.'basics');
defined('INC_CLASS')  ? null : define('INC_CLASS' , INC_PATH.DS.'general_class');
defined('INC_FUNCTION')  ? null : define('INC_FUNCTION' , INC_PATH.DS.'functions');
defined('INC_MODULE')  ? null : define('INC_MODULE' , HOME_DIR.DS.'modules');
defined('INC_EXTENSIONS')  ? null : define('INC_EXTENSIONS' , HOME_DIR.DS.'extensions');
defined('INC_TPARTY')  ? null : define('INC_TPARTY' , HOME_DIR.DS.'tparty');
defined('INC_USER')  ? null : define('INC_USER' , HOME_DIR.DS.'extensions'.DS.'user');
defined('INC_PATHS')  ? null : define('INC_PATHS' , HOME_DIR.DS.'extensions'.DS.'path');
defined('INC_SYSTEMS')  ? null : define('INC_SYSTEMS' , HOME_DIR.DS.'modules'.DS.'system');
defined('INC_SYS')  ? null : define('INC_SYS' , HOME_DIR.DS.'modules'.DS.'sys');
defined('INC_ORGS')  ? null : define('INC_ORGS' , HOME_DIR.DS.'modules'.DS.'org');
defined('INC_GL')  ? null : define('INC_GL' , HOME_DIR.DS.'modules'.DS.'gl');
defined('INC_INV')  ? null : define('INC_INV' , HOME_DIR.DS.'modules'.DS.'inv');
defined('INC_AP')  ? null : define('INC_AP' , HOME_DIR.DS.'modules'.DS.'ap');
defined('INC_AR')  ? null : define('INC_AR' , HOME_DIR.DS.'modules'.DS.'ar');
defined('INC_PO')  ? null : define('INC_PO' , HOME_DIR.DS.'modules'.DS.'po');
defined('INC_BOM')  ? null : define('INC_BOM' , HOME_DIR.DS.'modules'.DS.'bom');
defined('INC_WIP')  ? null : define('INC_WIP' , HOME_DIR.DS.'modules'.DS.'wip');



//load core objects
require_once(INC_BASICS.DS."dbsettings.inc"); 
require_once(INC_FUNCTION.DS."functions.inc");
require_once(INC_CLASS.DS."class.session.inc"); 

include_once(INC_CLASS.DS."class.dbc.inc"); 
require_once(INC_CLASS.DS."class.dbObject.inc"); 
require_once(INC_CLASS.DS."class.form.inc"); 
require_once(INC_CLASS.DS."class_inoform.inc"); 
require_once(INC_PATHS.DS."class.path.inc"); 
require_once(INC_CLASS.DS."class.pagination.inc"); 
require_once(INC_CLASS.DS."class.search.inc"); 
require_once(INC_CLASS.DS."class.ino_exception.inc"); 
require_once(INC_CLASS.DS."class_inosave.inc"); 
require_once(INC_CLASS.DS."class_downloads.inc"); 
require_once(INC_CLASS.DS."class_getsvgimage.inc"); 
require_once(INC_EXTENSIONS.DS."engine".DS."class_engine.inc");
require_once(INC_EXTENSIONS.DS."user".DS."class.user.inc");
require_once(INC_EXTENSIONS.DS."user".DS."class.user_role.inc");
require_once(INC_EXTENSIONS.DS."user".DS."class.user_password_reset.inc");
require_once(INC_EXTENSIONS.DS."role_access".DS."class_role_access.inc");
require_once(INC_EXTENSIONS.DS."role_path".DS."class_role_path.inc");
//require_once(INC_BASICS.DS."class.dbObject.inc"); 

//load other objects
require_once(INC_SYSTEMS.DS."module".DS."class.module.inc"); 
require_once(INC_SYS.DS."program".DS."class_sys_program.inc"); 
require_once(INC_SYS.DS."option".DS."class.option_header.inc"); 
require_once(INC_SYS.DS."option".DS."class.option_line.inc"); 
require_once(INC_SYS.DS."option".DS."class.option_detail.inc"); 
//require_once(INC_SYSTEMS.DS."role".DS."class.role_path.inc");
require_once(INC_SYS.DS."value_group".DS."class.sys_value_group_header.inc"); 
require_once(INC_SYS.DS."value_group".DS."class.sys_value_group_line.inc"); 
require_once(INC_ORGS.DS."class_org.inc"); 
require_once(INC_ORGS.DS."class_org_v.inc"); 
require_once(INC_ORGS.DS."enterprise".DS."class_enterprise.inc");
require_once(INC_ORGS.DS."legal".DS."class_legal.inc");
require_once(INC_ORGS.DS."business".DS."class_business.inc");
require_once(INC_ORGS.DS."inventory".DS."class_inventory.inc");
require_once(INC_ORGS.DS."address".DS."class_address.inc"); 
require_once(INC_GL.DS."coa".DS."class_coa.inc"); 
require_once(INC_GL.DS."coa_combination".DS."class_coa_combination.inc"); 
require_once(INC_GL.DS."calendar".DS."class_gl_calendar.inc"); 
require_once(INC_GL.DS."ledger".DS."class_gl_ledger.inc"); 
require_once(INC_GL.DS."ledger".DS."class_gl_ledger_balancing_values.inc"); 
require_once(INC_GL.DS."journal".DS."class_gl_journal_header.inc"); 
require_once(INC_GL.DS."journal".DS."class_gl_journal_line.inc"); 
require_once(INC_GL.DS."journal".DS."class_gl_journal_line_v.inc"); 
require_once(INC_GL.DS."balance".DS."class_gl_balance_v.inc"); 
require_once(INC_GL.DS."balance".DS."class_gl_balance.inc"); 
require_once(INC_GL.DS."payment_term".DS."class.payment_term.inc"); 
require_once(INC_GL.DS."payment_term".DS."class.payment_term_schedule.inc"); 
require_once(INC_GL.DS."payment_term".DS."class.payment_term_discount.inc"); 
require_once(INC_INV.DS."item".DS."class.item.inc"); 
require_once(INC_MODULE.DS."inv".DS."item".DS."class_ra_item.inc");
require_once(INC_INV.DS."onhand".DS."class_onhand.inc"); 
require_once(INC_INV.DS."onhand".DS."class_onhand_v.inc"); 
require_once(INC_INV.DS."subinventory".DS."class_subinventory.inc"); 
require_once(INC_INV.DS."locator".DS."class_locator.inc"); 
require_once(INC_INV.DS."uom".DS."class_uom.inc"); 
require_once(INC_INV.DS."transaction_type".DS."class.transaction_type.inc"); 
require_once(INC_AP.DS."supplier".DS."class_supplier.inc"); 
require_once(INC_AP.DS."supplier".DS."class_supplier_site.inc");
require_once(INC_AP.DS."supplier_bu".DS."class_supplier_bu.inc");
require_once(INC_AP.DS."supplier".DS."class_supplier_all_v.inc");
//require_once(INC_AP.DS."ap_transaction".DS."class_ap_transaction_header.inc");
//require_once(INC_AP.DS."ap_transaction".DS."class_ap_transaction_line.inc");
//require_once(INC_AP.DS."ap_transaction".DS."class_ap_transaction_detail.inc");
require_once(INC_AR.DS."customer".DS."class_ar_customer.inc"); 
require_once(INC_AR.DS."customer".DS."class_ar_customer_site.inc");
require_once(INC_AR.DS."customer_bu".DS."class_ar_customer_bu.inc");
require_once(INC_PO.DS."class_po_header.inc"); 
require_once(INC_PO.DS."class_po_line.inc"); 
require_once(INC_PO.DS."class_po_detail.inc"); 
require_once(INC_PO.DS."class_po_all_v.inc"); 
require_once(INC_MODULE.DS."po".DS."requisition".DS."class_po_requisition_header.inc");
require_once(INC_MODULE.DS."po".DS."requisition".DS."class_po_requisition_line.inc");
require_once(INC_MODULE.DS."po".DS."requisition".DS."class_po_requisition_detail.inc");
require_once(INC_MODULE.DS."po".DS."requisition".DS."class_po_requisition_all_v.inc");
require_once(INC_MODULE.DS."po".DS."requisition".DS."class_po_convert_requisition_v.inc");
require_once(INC_MODULE.DS."po".DS."sourcing_rule".DS."class_po_sourcing_rule_header.inc");
require_once(INC_MODULE.DS."po".DS."sourcing_rule".DS."class_po_sourcing_rule_line.inc");
require_once(INC_MODULE.DS."po".DS."po_purchasing_control".DS."class_po_purchasing_control.inc");
require_once(INC_INV.DS."inv_transaction".DS."class_inv_transaction.inc"); 
require_once(INC_INV.DS."receipt".DS."class_inv_receipt_header.inc"); 
require_once(INC_INV.DS."receipt".DS."class_inv_receipt_line.inc"); 
require_once(INC_INV.DS."receipt".DS."class_inv_receipt_v.inc"); 
require_once(INC_BOM.DS."class.bom_header.inc"); 
require_once(INC_BOM.DS."class.bom_line.inc"); 
require_once(INC_BOM.DS."class_bom_all_v.inc"); 
require_once(INC_BOM.DS."indented_bom".DS."class_indented_bom.inc"); 
require_once(INC_BOM.DS."bom_resource".DS."class_bom_resource.inc"); 
require_once(INC_BOM.DS."bom_resource".DS."class_bom_resource_cost.inc"); 
require_once(INC_BOM.DS."bom_cost_type".DS."class.bom_cost_type.inc"); 
require_once(INC_BOM.DS."bom_material_element".DS."class.bom_material_element.inc"); 
require_once(INC_BOM.DS."bom_overhead".DS."class.bom_overhead.inc"); 
require_once(INC_BOM.DS."bom_overhead".DS."class.bom_overhead_rate_assignment.inc"); 
require_once(INC_BOM.DS."bom_overhead".DS."class.bom_overhead_resource_assignment.inc"); 
require_once(INC_BOM.DS."bom_overhead".DS."class_bom_overhead_v.inc"); 
require_once(INC_BOM.DS."bom_department".DS."class.bom_department.inc"); 
require_once(INC_BOM.DS."bom_department".DS."class.bom_department_resource_assignment.inc"); 
require_once(INC_BOM.DS."bom_standard_operation".DS."class.bom_standard_operation.inc"); 
require_once(INC_BOM.DS."bom_standard_operation".DS."class.bom_standard_operation_resource_assignment.inc"); 
require_once(INC_BOM.DS."bom_routing".DS."class.bom_routing_header.inc"); 
require_once(INC_BOM.DS."bom_routing".DS."class.bom_routing_line.inc"); 
require_once(INC_BOM.DS."bom_routing".DS."class.bom_routing_detail.inc"); 
require_once(INC_WIP.DS."wip_wo".DS."class.wip_wo_header.inc"); 
require_once(INC_WIP.DS."wip_wo".DS."class.wip_wo_bom.inc"); 
require_once(INC_WIP.DS."wip_wo".DS."class.wip_wo_routing_line.inc"); 
require_once(INC_WIP.DS."wip_wo".DS."class.wip_wo_routing_detail.inc"); 
require_once(INC_WIP.DS."wip_wo".DS."class_wip_wo_routing_v.inc"); 
require_once(INC_MODULE.DS."wip".DS."wip_wo".DS."class_ra_wip.inc");
require_once(INC_WIP.DS."wip_move_transaction".DS."class.wip_move_transaction.inc"); 
require_once(INC_WIP.DS."wip_wo_completion".DS."class_wip_wo_completion.inc"); 
require_once(INC_WIP.DS."wip_material_transaction".DS."class_wip_material_transaction.inc"); 
require_once(INC_WIP.DS."wip_resource_transaction".DS."class.wip_resource_transaction.inc");
require_once(INC_MODULE.DS."wip".DS."accounting_group".DS."class_wip_accounting_group.inc");
require_once(INC_MODULE.DS."cst".DS."item_cost".DS."class_cst_item_cost_v.inc");
require_once(INC_MODULE.DS."cst".DS."item_cost".DS."class_cst_item_cost_header.inc");
require_once(INC_MODULE.DS."cst".DS."item_cost".DS."class_cst_item_cost_line.inc");
require_once(INC_MODULE.DS."cst".DS."item_cost".DS."class_cst_item_cost_line_pre.inc");
require_once(INC_MODULE.DS."fp".DS."forecast".DS."class_fp_forecast_header.inc");
require_once(INC_MODULE.DS."fp".DS."forecast".DS."class_fp_forecast_line.inc");
require_once(INC_MODULE.DS."fp".DS."mds".DS."class_fp_mds_header.inc");
require_once(INC_MODULE.DS."fp".DS."mds".DS."class_fp_mds_line.inc");
require_once(INC_MODULE.DS."fp".DS."source_list".DS."class_fp_source_list_header.inc");
require_once(INC_MODULE.DS."fp".DS."source_list".DS."class_fp_source_list_line.inc");
require_once(INC_MODULE.DS."fp".DS."minmax".DS."class_fp_minmax_header.inc");
require_once(INC_MODULE.DS."fp".DS."minmax".DS."class_fp_minmax_line.inc");
require_once(INC_MODULE.DS."fp".DS."minmax".DS."class_fp_minmax_demand.inc");
require_once(INC_MODULE.DS."fp".DS."minmax".DS."class_fp_minmax_demand_v.inc");
require_once(INC_MODULE.DS."fp".DS."minmax".DS."class_fp_minmax_suggestion_v.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_header.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."exception".DS."class_fp_mrp_exception.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_v.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_demand.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_planned_order.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_lowlevel_code.inc");
require_once(INC_MODULE.DS."fp".DS."mrp".DS."class_fp_mrp_existing_supply_v.inc");
require_once(INC_MODULE.DS."sd".DS."so".DS."class_sd_so_header.inc");
require_once(INC_MODULE.DS."sd".DS."so".DS."class_sd_so_line.inc");
require_once(INC_MODULE.DS."sd".DS."so".DS."class_sd_so_all_v.inc");
require_once(INC_MODULE.DS."sd".DS."shipping_control".DS."class_sd_shipping_control.inc");
require_once(INC_MODULE.DS."sd".DS."delivery".DS."class_sd_delivery_header.inc");
require_once(INC_MODULE.DS."sd".DS."delivery".DS."class_sd_delivery_line.inc");
require_once(INC_MODULE.DS."mdm".DS."tax_code".DS."class_mdm_tax_code.inc");
require_once(INC_MODULE.DS."mdm".DS."tax".DS."region".DS."class_mdm_tax_region.inc");

//include extensions

require_once(INC_EXTENSIONS.DS."page".DS."class_page.inc");
require_once(INC_EXTENSIONS.DS."comment".DS."class.comment.inc");
require_once(INC_EXTENSIONS.DS."file".DS."class.file.inc");
require_once(INC_EXTENSIONS.DS."file".DS."class.file_reference.inc");
require_once(INC_EXTENSIONS.DS."file".DS."class_massupload.inc"); 
require_once(INC_EXTENSIONS.DS."content_type".DS."class_content_type.inc");
require_once(INC_EXTENSIONS.DS."content_type".DS."class_new_content_type.inc");
require_once(INC_EXTENSIONS.DS."content_type".DS."class_content_type_reference.inc");
require_once(INC_EXTENSIONS.DS."content".DS."class.content.inc");
require_once(INC_EXTENSIONS.DS."block".DS."class.block.inc");
require_once(INC_EXTENSIONS.DS."block".DS."class.block_content.inc");
require_once(INC_EXTENSIONS.DS."block".DS."class_block_cache.inc");
require_once(INC_EXTENSIONS.DS."category".DS."class_category.inc");
require_once(INC_EXTENSIONS.DS."category".DS."class_category_reference.inc");
require_once(INC_EXTENSIONS.DS."view".DS."class.view.inc");
require_once(INC_EXTENSIONS.DS."view".DS."class.view_path.inc");
require_once(INC_EXTENSIONS.DS."site_info".DS."class_site_info.inc");
require_once(INC_EXTENSIONS.DS."site_control".DS."class.site_control_header.inc");
require_once(INC_EXTENSIONS.DS."site_control".DS."class.site_control_line.inc");
require_once(INC_EXTENSIONS.DS."web_tracking".DS."class_web_tracking.inc");




//require_once(INC_USER.DS."class.user.inc"); 

//Third party classes
require_once(INC_TPARTY.DS."fpdf".DS."fpdf.php");
require_once(INC_CLASS.DS."class_inopdf.inc"); 
//require_once(INC_FUNCTION.DS."module_functions.inc");
//require_once(INC_FUNCTION.DS."extension_functions.inc");

?>