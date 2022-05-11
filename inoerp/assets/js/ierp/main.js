function main() {
  let allMethods = {
    CstItemCostHeaderEv: {
      BeforePatch: ["cst/cst_item_cost_header_ev.js", "beforePatch"],
    },
    FaAssetEv: {
      BeforePatch: ["fa/fa_asset.js", "beforePatch"],
    },
    FpMdsHeaderEv: {
      BeforePatch: ["fp/fp_mds_header.js", "beforePatch"],
    },
    FpMrpHeaderEv: {
      BeforePatch: ["fp/fp_mrp_header.js", "beforePatch"],
    },
    FpMrpSupplyEv: {
      BeforePatch: ["fp/fp_mrp_supply.js", "beforePatch"],
    },
    FpMrpPlannedOrderV: {
      BeforePatch: ["fp/fp_mrp_supply.js", "beforePatch"],
    },
    FpMrpReleasePrV: {
      BeforePatch: ["fp/fp_mrp_supply.js", "beforePatch"],
    },
    FpMrpReleaseWoV: {
      BeforePatch: ["fp/fp_mrp_supply.js", "beforePatch"],
    },
    GlAvailablePeriodsV: {
      BeforePatch: ["gl/gl_period_ev.js", "beforePatch"],
    },
    GlJournalHeaderEv: {
      AfterGet: ["gl/gl_journal_header.js", "afterGet"],
      BeforePatch: ["gl/gl_journal_header.js", "beforePatch"],
    },
    GlJournalHeader: {
      AfterGet: ["gl/gl_journal_header.js", "afterGet"],
      BeforePatch: ["gl/gl_journal_header.js", "beforePatch"],
    },
    InvTransactionEv: {
      BeforePost: ["inv/inv_transaction.js", "beforePost"],
      BeforePatch: ["inv/inv_transaction.js", "beforePatch"],
    },
    HrLeaveEntitlementHeader: {
      BeforePatch: ["hr/hr_employee.js", "beforePatch"],
    },
    InvTransactionDocHeaderEv: {
      AfterPatch: ["inv/inv_transaction_doc_header.js", "afterPatch"],
    },
    InvItemEv: {
      AfterPost: ["inv/inv_item.js", "afterPost"],
      BeforePatch: ["inv/inv_item.js", "beforePatch"],
    },
    InvItemMasterEv: {
      BeforePatch: ["inv/inv_item_master.js", "beforePatch"],
    },
    InvAbcValHeaderEv: {
      BeforePatch: ["inv/inv_abc_val_header.js", "beforePatch"],
    },
    InvCountHeaderEv: {
      BeforePatch: ["inv/inv_count_header.js", "beforePatch"],
    },
    /*     PoRfqHeaderEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    },
    PoRfqLineEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    },
    PoQuoteHeaderEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    },
    PoQuoteLineEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    },
    PoRequisitionHeaderEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    },
    PoRequisitionLineEv: {
      BeforePatch: ["po/purchasing_actions.js", "beforePatch"],
      AfterGet: ["po/purchasing_actions.js", "afterGet"],
    }, */
    PoRequisitionInterface: {
      BeforePatch: ["po/po_requisition.js", "beforePatch"],
    },
    PoHeaderEv: {
      BeforePatch: ["po/po_header.js", "beforePatch"],
      AfterGet: ["po/po_header.js", "afterGet"],
    },
    PoLineEv: {
      AfterPost: ["po/po_line.js", "afterPost"],
      AfterPatch: ["po/po_line.js", "afterPatch"],
    },
    SdSoHeaderEv: {
      BeforePatch: ["sd/so_header.js", "beforePatch"],
      AfterGet: ["sd/so_header.js", "afterGet"],
    },
    // SdDeliveryHeader: {
    //   BeforePatch: ["sd/sd_delivery_header.js", "beforePatch"],
    // },
    SdDeliveryLineEv: {
      BeforePatch: ["sd/sd_delivery_header.js", "beforePatch"],
    },
    WipWdHeaderEv: {
      AfterPost: ["wip/wd_header.js", "afterPost"],
    },
    WipWoInterface: {
      BeforePatch: ["wip/wo_header.js", "importWorkOrder"],
    },
    WipWoHeaderEv: {
      AfterPost: ["wip/wo_header.js", "afterPost"],
      AfterGet: ["wip/wo_header.js", "afterGet"],
      BeforePatch: ["wip/wo_header.js", "beforePatch"],
    },
    WipMoveTransactionEv: {
      BeforePost: ["wip/move_transaction.js", "beforePost"],
    },
    SdSoLineEv: {
      AfterGet: ["sd/so_header.js", "afterGet"],
      BeforePatch: ["sd/so_header.js", "beforePatch"],
    },
    RdSecUser: {
      afterGet: ["user/user.js", "removePassword"],
      BeforePatch: ["user/user.js", "validatePassword"],
      BeforePost: ["user/user.js", "validatePassword"],
    },
    RdSecRole: {
      BeforeGet: ["user/user.js", "validatePassword"],
      AfterGet: ["user/user.js", "validatePassword"],
      BeforePatch: ["user/user.js", "validatePassword"],
      AfterPatch: ["user/user.js", "validatePassword"],
      BeforePost: ["user/user.js", "validatePassword"],
      AfterPost: ["user/user.js", "validatePassword"],
      BeforeDelete: ["user/user.js", "validatePassword"],
      AfterDelete: ["user/user.js", "validatePassword"],
    },
    SysProgramHeaderV: {
      BeforePatch: ["sys/sys_program.js", "beforePatch"],
    },
  };

  return allMethods;
}

function global() {
  consoleLog("In global function");
}

function getData(inputData) {
  if (typeof inputData === "string") {
    return JSON.parse(inputData);
  } else {
    return inputData;
  }
}

function getFlatObject(obj, flatObject) {
  if (Object.keys(obj).length > 0) {
    let allKeys = Object.keys(obj);
    for (let i = 0; i < allKeys.length; i++) {
      const k = allKeys[i];
      if (k != null) {
        flatObject[k] = obj[k];
        if (typeof obj[k] === "object" && Object.keys(obj[k]).length > 0) {
          getFlatObject(obj[k], flatObject);
        }
      }
    }
  }
}

function getFormattedDate(date) {
  if (date != null) {
    try {
      let isoDate = new Date(date).toISOString();
      if (isoDate !== "Invalid Date") {
        return isoDate.split("T")[0];
      } else {
        consoleLog("\nInvalid Date 1 : " + date);
        return null;
      }
    } catch (error) {
      consoleLog("\nInvalid Date 2 : " + date);
      return null;
    }
  } else {
    return null;
  }
}

function getMessageFromSqlResponse(sqlResponse) {
  if (
    sqlResponse["data"] != undefined &&
    Array.isArray(sqlResponse["data"]) &&
    sqlResponse["data"].length > 0
  ) {
    return sqlResponse["data"][0]["message"];
  } else {
    return JSON.stringify(sqlResponse["data"]);
  }
}
function getStatusFromAction(action) {
  var status = null;
  // if (action == "cancel") {
  //   status = "CANCELLED";
  // } else if (action == "confirm") {
  //   status = "CONFIRMED";
  // } else if (action == "close") {
  //   status = "CLOSED";
  // } else if (action == "reopen" || action == "open") {
  //   status = "DRAFT";
  // } else if (action == "hold") {
  //   status = "ON_HOLD";
  // }

  switch (action) {
    case "cancel":
      status = "CANCELLED";
      break;
    case "confirm":
      status = "CONFIRMED";
      break;
    case "close":
      status = "CLOSED";
      break;
    case "reopen":
    case "open":
      status = "DRAFT";
      break;
    case "hold":
      status = "ON_HOLD";
      break;
    case "active":
      status = "ACTIVE";
      break;
    case "post":
      status = "POSTED";
      break;
    case "approve":
      status = "approved";
      break;
    case "reject":
      status = "rejected";
      break;
    case "need_more_info":
      status = "need_more_info";
  }
  return status;
}

function printNestedObject(obj) {
  if (typeof obj === "string") {
    consoleLog(obj);
  } else if (Object.keys(obj).length > 0) {
    let allKeys = Object.keys(obj);
    for (let i = 0; i < allKeys.length; i++) {
      const k = allKeys[i];
      if (k != null) {
        consoleLog(k + " : " + obj[k]);
        if (typeof obj[k] === "object" && Object.keys(obj[k]).length > 0) {
          printNestedObject(obj[k]);
        }
      }
    }
  }
}

function updateAsPerDocStatus(data) {
  var docStatus = data["docStatus"];
  var readOnly = true;
  var entityObjectReadOnly = false;

  if (docStatus == "DRAFT") {
    readOnly = false;
  } else if (
    docStatus == "CANCELLED" ||
    docStatus == "CLOSED" ||
    docStatus == "retired" ||
    docStatus == "POSTED"
  ) {
    entityObjectReadOnly = true;
  }
  var entityObject = { readonly: entityObjectReadOnly };
  var dataDefinition = { entityObject: entityObject };
  let allKeys = Object.keys(data);
  for (let i = 0; i < allKeys.length; i++) {
    const k = allKeys[i];
    if (k != null) {
      var dd = {};
      if (k == "description" || k == "orderSourceType") {
        dd["readonly"] = false;
      } else {
        dd["readonly"] = readOnly;
      }
      dataDefinition[k] = dd;
    }
  }
  data["dataDefinition"] = dataDefinition;
  return data;
}

function validationForAfterGet(inputData) {
  if (inputData != null) {
  } else {
    return inputData;
  }
  if (!inputData["pathParamValues"]) {
    return inputData["data"];
  }

  var data = inputData["data"];
  var isArray = data.constructor === Array ? true : false;

  if (isArray) {
    var retData = [];
    for (let index = 0; index < data.length; index++) {
      var element = data[index];
      updateAsPerDocStatus(element);
      retData.push(element);
    }
    return retData;
  } else {
    updateAsPerDocStatus(data);
    return data;
  }
}
