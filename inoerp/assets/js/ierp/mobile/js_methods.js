function main(){
  let allMethods =  [
    {
      "applicationCode" : "OracleCloud",
      "entityPath" : "user",
      "triggerPoint" : "BeforeGet",
      "jsFilePath" : "http://localhost:8085/js/user.js",
      "jsMethodName" : "validatePassword",
    },
    {
      "applicationCode" : "OracleCloud",
      "entityPath" : "user",
      "triggerPoint" : "BeforePost",
      "jsFilePath" : "http://localhost:8085/js/user.js",
      "jsMethodName" : "validatePassword",
    },
    {
      "applicationCode" : "SapHanaCloud",
      "entityPath" : "A_WorkCenterAllCapacity",
      "triggerPoint" : "BeforeGet",
      "jsFilePath" : "http://localhost:8085/js/mobile/sap.js",
      "jsMethodName" : "getOrgList",
    }
   ];

  return allMethods;
}

async function getRequest(inputData) {
  log(
    "type of inputData in js getRequest" + typeof inputData + " : " + inputData
  );
  let data2 = restGet(inputData).then((data) => {
    log("type of data " + typeof data);
    var jsonData;
    if (typeof data === "string") {
      jsonData = JSON.parse(data);
    } else {
      jsonData = data;
    }
    if (Array.isArray(jsonData)) {
      for (let i = 0; i < jsonData.length; i++) {
        let e = jsonData[i];
        log("Js Array Log Data : " + e);
        for (var k in e) {
          log(k + " : " + e[k]);
        }
      }
    } else {
      for (var k in jsonData) {
        log("Js Obj Log : " + k + " : " + jsonData[k]);
      }
    }
  });
  let data3 =  await restGet(inputData)
  log("Js Obj retData  data3 : " +data3);
  for (var k in data3) {
    log("Js Obj data3 : " + k + " : " + data3[k]);
  }
  return data2;
}

async function getOrgList(){
  let data2={host:"http://localhost:8085/api/ierp/Org"};
  let retData = await getRequest(JSON.stringify(data2));
  for (var k in retData) {
    log("Js Obj retData : " + k + " : " + retData[k]);
  }
  return retData;
}