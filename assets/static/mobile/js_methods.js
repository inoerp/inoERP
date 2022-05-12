function main() {
  let allMethods = [
    {
      applicationCode: "OracleCloud",
      entityPath: "user",
      triggerPoint: "beforeGet",
      jsFilePath: "http://localhost:8085/js/user.js",
      jsMethodName: "validatePassword",
    },
    {
      applicationCode: "OracleCloud",
      entityPath: "user",
      triggerPoint: "beforePost",
      jsFilePath: "http://localhost:8085/js/user.js",
      jsMethodName: "validatePassword",
    },
    {
      applicationCode: "SapHanaCloud",
      entityPath: "A_WorkCenterAllCapacity",
      triggerPoint: "afterGet",
      jsFilePath: "http://localhost:8085/mobile/sap.js",
      jsMethodName: "getOrgDetails",
    },
    {
      applicationCode: "OracleCloud",
      entityPath: "cycleCountDefinitions",
      triggerPoint: "afterGet",
      jsFilePath: "http://localhost:8085/mobile/sap.js",
      jsMethodName: "accessDenied",
    },
    {
      applicationCode: "TimeSheet",
      entityPath: "Aktivitet",
      triggerPoint: "beforePost",
      jsFilePath: "http://localhost:8085/mobile/rent.js",
      jsMethodName: "validateTotalTime",
    },
    {
      applicationCode: "TimeSheet",
      entityPath: "Aktivitet",
      triggerPoint: "beforePatch",
      jsFilePath: "http://localhost:8085/mobile/rent.js",
      jsMethodName: "validateTotalTime",
    },
    {
      applicationCode: "TimeSheet",
      entityPath: "Aktivitet",
      triggerPoint: "beforeDelete",
      jsFilePath: "http://localhost:8085/mobile/rent.js",
      jsMethodName: "validateAktivitetDelete",
    },
  ];

  return allMethods;
}

async function getRequest(inputData) {
  log(
    "type of inputData in js getRequest" + typeof inputData + " : " + inputData
  );
  // let data2 = restGet(inputData).then((data) => {
  //   log("type of data " + typeof data);
  //   var jsonData;
  //   if (typeof data === "string") {
  //     jsonData = JSON.parse(data);
  //   } else {
  //     jsonData = data;
  //   }
  //   if (Array.isArray(jsonData)) {
  //     for (let i = 0; i < jsonData.length; i++) {
  //       let e = jsonData[i];
  //       log("Js Array Log Data : " + e);
  //       for (var k in e) {
  //         log(k + " : " + e[k]);
  //       }
  //     }
  //   } else {
  //     for (var k in jsonData) {
  //       log("Js Obj Log : " + k + " : " + jsonData[k]);
  //     }
  //   }
  // });
  let data3 = await restGet(inputData);
  log("Js Obj retData  data3 : " + data3);
  return data3;
}

async function getOrgList(inputData) {
  let data2 = { host: "http://localhost:8085/api/ierp/Org" };
  let retData = await getRequest(JSON.stringify(data2));
  log("Js Obj retData  data3 : " + retData);
  return retData;
}

async function xxxgetOrgDetails(inputData) {
  log(
    "getOrgDetails in js_methods inputData : " +
      typeof inputData +
      " : " +
      inputData
  );

  for (key in inputData) {
    log(
      "getOrgDetails in js_methods inputData  key & value : " +
        key +
        " : " +
        inputData[key]
    );
  }

  let data2 = { host: "http://localhost:8085/api/ierp/Org(orgId=1)" };
  let retData = await getRequest(JSON.stringify(data2));

  log("getOrgDetails in js_methods retData : " + retData);
  return retData;
}

async function accessDenied(inputData) {
  return false;
}



async function validateAktivitetDelete(inputData) {
  
  let retValue = true;
  log("validateAktivitetDelete in js_methods inputData  key & value : " + inputData);

  let freeDays = 0;
  for (key in inputData) {
    if(key == 'ferdig'){
      freeDays = parseInt(inputData[key]);
    }
    log(
      "validateAktivitetDelete in js_methods inputData  key & value : " +
        key +
        " : " +
        typeof inputData[key] +
        " : " +
        inputData[key]
    );
  }

  log("validateAktivitetDelete in js_methods freeDays : " + freeDays);

  if(freeDays < 2){
    log("validateAktivitetDelete in js_methods freeDays 2 : " + freeDays);
    return true;
  }else{
    log("validateTotalTime in js_methods freeDays 3 : " + freeDays);
    let retMessage = {
      'rikProceedFlag' : false,
      'message' : 'No of free days must be less than 2'
    };
    return retMessage;
  }
}