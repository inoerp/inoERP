function createWorkOrder(params) {
  const invItemMasterId = params["invItemMasterId"];
  const invOrgId = params["invOrgId"];
  const quantity = params["quantity"];
  const startDate = params["startDate"];
  let amAssetInstanceId = "";
  if (
    params["amAssetInstanceId"] != null &&
    params["amAssetInstanceId"] != ""
  ) {
    amAssetInstanceId = params["amAssetInstanceId"];
  }
}
