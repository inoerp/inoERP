function afterGet(data) {
  
    var dataDefinition = {};
    let allKeys = Object.keys(data);
    for (let i = 0; i < allKeys.length; i++) {
      const k = allKeys[i];
      if (k != null) {
        let dd = {"name" : k}
        if (k == "description" || k == "orderSourceType") {
          dd["readonly"] = "0";
        }else{
          dd["readonly"] = "1";
        }
        console.log( "dd : " + dd);
        console.log( dd);

        dataDefinition[k] = dd;
        console.log( "dataDefinition : ");
        console.log( dataDefinition[k]);

      }
    }

  var dataDefinition2 = {"description" : {"readonly" : 1}, "orderSourceType" : {"readonly" : 1}};
    data["dataDefinition"] = dataDefinition;
    data["dataDefinition2"] = dataDefinition2;
  
    return data;
  }

  data = {
    "aggrementEndDate": "",
    "agreementStartDate": "0000-00-00",
    "approvalStatus": "DISABLED",
    "arCustomerId": "1",
    "arCustomerSiteId": "3"}
  console.log(afterGet(data));