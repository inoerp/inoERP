function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (
    action == "po_import_requisitions" ||
    action == "po_convert_requisitions"
  ) {
  } else {
    return data;
  }

  consoleLog(
    "\n\nIn beforePatch po_import_requisitions " + JSON.stringify(data)
  );

  // Import PO Requisitions
  let refreshResult = 0;
  if (action == "po_import_requisitions") {
    return importRequisitions(data);
  } else if (action == "po_convert_requisitions") {
    releaseAllPlannedOrders(data);
  }

  retDataMap["rd_proceed_message"] = "Release is successfully completed";

  return retDataMap;
}

function importRequisitions(data) {
  let buOrgId = data["formData"]["buOrgId"];
  let retDataMap = {};
  let sql =
    " SELECT * FROM `inoerp`.`po_requisition_interface` " +
    " WHERE (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) AND bu_org_id = '" +
    buOrgId +
    "' ";

  let sqlRequest = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let responseData = sqlResponse["data"];
  if (responseData.length > 0) {
  } else {
    retDataMap["rd_proceed_status"] = false;
    retDataMap["rd_proceed_message"] =
      "No Purchase Requisition is available for import.";
    return retDataMap;
  }

  const groupedData = groupPendingLinesBySupplierId(responseData);

  for (const supplierSiteId in groupedData) {
    const listData = groupedData[supplierSiteId];
    let poRequisitionInterfaceId = listData[0]["poRequisitionInterfaceId"];
    if (poRequisitionInterfaceId != undefined && poRequisitionInterfaceId > 0) {
      let newHeaderId = createRequisitionHeader(poRequisitionInterfaceId);
      createRequisitionLines(newHeaderId, supplierSiteId);
    } else {
      continue;
    }
  }

  retDataMap["rd_proceed_status"] = false;
  retDataMap["rd_proceed_message"] =
    "No of requisitions successfully imported are " + responseData.length;
  return retDataMap;
}

function createRequisitionLines(newHeaderId, supplierSiteId) {
  let lineSql =
    " INSERT INTO po_requisition_line (  src_entity_name, src_entity_id ,po_requisition_header_id,doc_status, " +
    " approval_status,ship_to_id,price_list_header_id,exchange_rate,rev_number,line_number,receiving_inv_org_id,inv_item_master_id, " +
    " revision_name,line_type,product_description,uom_code,line_quantity,price_date,unit_price,line_price,tax_code,tax_amount, " +
    " reference_doc_type,reference_doc_number,line_description,kit_configured_cb,hold_cb,fp_mrp_supply_id, " +
    " need_by_date,kit_cb,line_discount_amount,discount_code  )  " +
    "  SELECT  'po_requisition_interface', 'po_requisition_interface_id','" +
    newHeaderId +
    "',doc_status,approval_status, " +
    " ship_to_id,price_list_header_id,exchange_rate,rev_number,line_number,receiving_inv_org_id, " +
    " inv_item_master_id,revision_name,line_type,product_description,uom_code,line_quantity,price_date, " +
    " unit_price,line_price,tax_code,tax_amount,reference_doc_type,reference_doc_number, " +
    " line_description,kit_configured_cb,hold_cb,fp_mrp_supply_id,need_by_date,kit_cb, " +
    " line_discount_amount,discount_code  from po_requisition_interface " +
    " WHERE (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) ";

  if (supplierSiteId > 0) {
    lineSql += " AND supplier_site_id = '" + supplierSiteId + "' ";
  } else {
    lineSql += " AND supplier_site_id is null ";
  }

  insertRequest = {
    sql: lineSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(insertRequest);

  let updateSql =
    " UPDATE po_requisition_interface SET doc_status = 'CLOSED' " +
    " WHERE (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) and supplier_site_id = '" +
    supplierSiteId +
    "' ";

  updateSqlRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlUpdate(updateSqlRequest);
}

function createRequisitionHeader(poRequisitionInterfaceId) {
  let lineSql =
    " INSERT INTO po_requisition_header (  src_entity_name, src_entity_id ,document_type,bu_org_id," +
    " doc_status,approval_status,doc_currency, " +
    " doc_number,ref_po_rfq_header_id,supplier_id,supplier_site_id,buyer,hr_employee_id, " +
    " description,ship_to_id,bill_to_id,price_list_header_id,payment_term_id, " +
    " exchange_rate_type,exchange_rate,multi_bu_cb,rev_number,gl_ac_profile_header_id," +
    " ref_po_quote_header_id,requisition_number)   " +
    " SELECT 'po_requisition_interface', '" +
    poRequisitionInterfaceId +
    "',document_type,bu_org_id,doc_status,approval_status, " +
    " doc_currency,doc_number,ref_po_rfq_header_id,supplier_id,supplier_site_id,buyer,hr_employee_id,description," +
    " ship_to_id,bill_to_id,price_list_header_id,payment_term_id,exchange_rate_type,exchange_rate,multi_bu_cb, " +
    " rev_number,gl_ac_profile_header_id,ref_po_quote_header_id,requisition_number " +
    " from po_requisition_interface WHERE po_requisition_interface_id='" +
    poRequisitionInterfaceId +
    "' ";

  headerInsertRequest = {
    sql: lineSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let headerResponse = sqlInsert(headerInsertRequest);
  let headerResponseData = headerResponse["data"];
  let headerId = headerResponseData[0]["lastInsertId"];
  return headerId;
}

function groupPendingLinesBySupplierId(responseData) {
  let groupedData = {};

  for (let index = 0; index < responseData.length; index++) {
    const rowData = responseData[index];

    let supplierSiteId = rowData["supplierSiteId"];
    if (supplierSiteId == undefined) {
      supplierSiteId = 0;
    }

    if (groupedData.hasOwnProperty(supplierSiteId)) {
      groupedData[supplierSiteId].push(rowData);
    } else {
      groupedData[supplierSiteId] = [];
      groupedData[supplierSiteId].push(rowData);
    }
  }

  return groupedData;
}
