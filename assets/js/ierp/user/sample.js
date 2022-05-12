const userData1 =
  '[{"arCustomerId":"","assignedIp":"","blockNotifCount":"","buAccessGroupLov":"BU_ACCESS_ALL","createdBy":"","creationDate":"","dateFormat":"","debugMode":"","email":"demodemo","firstName":"demo2","id":"1","invAccessGroupLov":"INV_ACCESS_ALL","lastName":"demodemo","lastUpdateDate":"","lastUpdatedBy":"","links":[{"href":"http://localhost:8085/api/config/RdSecUser(id=1)","kind":"item","name":"RdSecUser","rel":"self"}],"orgCodeLov":"ORG_CODE_ALL","password":"$2a$10$D/0pW6UGgJcfCJlsHn5tiO3zGM1fLLi5jrrjMpqlGS7FdnqEhJq/q","phone":"","status":"","userLanguage":"","username":"demo"},{"arCustomerId":"","assignedIp":"","blockNotifCount":"","buAccessGroupLov":"BU_ACCESS_ALL","createdBy":"","creationDate":"","dateFormat":"","debugMode":"","email":"","firstName":"fName","id":"2","invAccessGroupLov":"INV_ACCESS_ALL","lastName":"lName","lastUpdateDate":"","lastUpdatedBy":"","links":[{"href":"http://localhost:8085/api/config/RdSecUser(id=2)","kind":"item","name":"RdSecUser","rel":"self"}],"orgCodeLov":"ORG_CODE_ALL","password":"$2a$10$Tg9/n/WM2AdIaLVbZEuP8upGFaAyC1T1t1sG9PbS1tCD3zu4SfwEa","phone":"","status":"","userLanguage":"","username":"admin"},{"arCustomerId":"","assignedIp":"","blockNotifCount":"","buAccessGroupLov":"BU_ACCESS_ALL","createdBy":"","creationDate":"","dateFormat":"","debugMode":"","email":"","firstName":"","id":"3","invAccessGroupLov":"INV_ACCESS_ALL","lastName":"","lastUpdateDate":"","lastUpdatedBy":"","links":[{"href":"http://localhost:8085/api/config/RdSecUser(id=3)","kind":"item","name":"RdSecUser","rel":"self"}],"orgCodeLov":"ORG_CODE_ALL","password":"test04","phone":"","status":"","userLanguage":"","username":"demo2"},{"arCustomerId":"","assignedIp":"","blockNotifCount":"","buAccessGroupLov":"BU_ACCESS_ALL","createdBy":"","creationDate":"","dateFormat":"","debugMode":"","email":"","firstName":"eeee","id":"4","invAccessGroupLov":"INV_ACCESS_ALL","lastName":"","lastUpdateDate":"","lastUpdatedBy":"","links":[{"href":"http://localhost:8085/api/config/RdSecUser(id=4)","kind":"item","name":"RdSecUser","rel":"self"}],"orgCodeLov":"ORG_CODE_ALL","password":"","phone":"","status":"","userLanguage":"","username":"demo3"}]';

function getRequest(inputData) {
  let allData;
  if (typeof inputData === "string") {
    allData = JSON.parse(inputData);
  } else {
    allData = inputData;
  }

  newRequest = {
    host: "http://localhost:8085/api/ierp/MdmTaxCode",
  };

  let data = allData["data"];
  let requestData = allData["request"];
  if ("Authorization" in requestData) {
    newRequest["authorization"] = requestData["Authorization"];
    LOG("Input data in javascript getRequest 1 " + newRequest["authorization"]);
  }

  let response = get(newRequest);
  let body = response.body;

  LOG("Input data in javascript getRequest 2 " + body);

  LOG("type of body " + typeof body);
  if (typeof body === "string") {
    body = JSON.parse(response);
  }

  if (Array.isArray(body)) {
    for (let i = 0; i < body.length; i++) {
      let e = body[i];
      LOG("getRequest response row number : " + i);
      printNestedObject(e);
    }
  } else {
    printNestedObject(body);
  }
}

function sqlQuery(inputData) {
  request = {
    sql: "SELECT * from sys_value_group_header",
    dbType: "MySQL",
    connName: "password",
  };

  let response = queryUsingSql(request);
  printNestedObject(response.data);
}

function sqlUpdate(inputData) {
  request = {
    sql: "UPDATE sys_value_group_header SET description = 'Legal Entity 001' WHERE sys_value_group_header_id = '1' ",
    dbType: "MySQL",
    connName: "password",
  };

  let response = updateUsingSql(request);
  printNestedObject(response.data);
}

function sqlInsert(inputData) {
  let sql =  "INSERT INTO sys_value_group_header (value_group, description, access_level, validation_type, created_by,last_update_by) ";
      sql += " VALUES ('TEST_VG02', 'TEST Value Group02', 'user', 'NONE', '1', '1' ) ";
  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "password",
  };

  let response = insertUsingSql(request);
  printNestedObject(response.data);
}

function sqlDelete(inputData) {
  request = {
    sql: "DELETE FROM sys_value_group_header WHERE sys_value_group_header_id = '19' ",
    dbType: "MySQL",
    connName: "password",
  };

  let response = deleteUsingSql(request);
  printNestedObject(response.data);
}

function printNestedObject(obj) {
  if (typeof obj === "string") {
    LOG(obj);
  } else if (Object.keys(obj).length > 0) {
    let allKeys = Object.keys(obj);
    for (let i = 0; i < allKeys.length; i++) {
      const k = allKeys[i];
      LOG(k + " : " + obj[k]);
      if (typeof obj[k] === "object" && Object.keys(obj[k]).length > 0) {
        printNestedObject(obj[k]);
      }
    }
  }
}

function removePassword(inputData) {
  LOG("Input data in javascript 1 " + inputData);
  //let allData = getData("inputData");
  if (typeof inputData === "string") {
    allData = JSON.parse(inputData);
  } else {
    allData = inputData;
  }
  let data = allData["data"];
  let request = allData["request"];
  LOG("Input data in javascript 2 " + data);
  //getRequest(inputData);
  //sqlQuery(inputData);
  //sqlUpdate(inputData);
  //sqlInsert(inputData)
  sqlDelete(inputData)
  if (Array.isArray(data)) {
    let retData = new Array();
    for (let i = 0; i < data.length; i++) {
      let e = data[i];
      let newObj = new Object();
      for (var k in e) {
        if (k !== "password") {
          newObj[k] = e[k];
        }
      }
      retData.push(newObj);
    }
    return retData;
  } else {
    let newObj = new Object();
    for (var k in data) {
      if (k !== "password") {
        newObj[k] = data[k];
      }
    }
    return newObj;
  }
}

// LOG(removePassword(userData1))

function getRequestTest(data) {
  request = {
    host: "http://localhost:8085/api/ierp/MdmTaxCode",
  };
  //response = GET(request);
  response = result;
  // let body = response.body
  let body = JSON.parse(response);
  //LOG("getRequest response 2 " + JSON.stringify(body));
  LOG("type of body " + typeof body);

  if (Array.isArray(body)) {
    for (let i = 0; i < body.length; i++) {
      let e = body[i];
      LOG("getRequest response 2.1 : " + e);
      for (var k in e) {
        LOG(k + " : " + e[k]);
      }
    }
  } else {
    for (var k in body) {
      LOG(k + " : " + body[k]);
    }
  }
}

//getRequestTest();

function validatePassword(data) {
  try {
    if (data["password"] === data["confirmPassword"]) {
      return true;
    } else {
      return false;
    }
  } catch (error) {
    return error;
  }
}

function returnDataExample() {
  let userData = {
    user1: "password1",
    user2: "password2",
    user3: 123,
  };
  let retData = {
    NextGoFunc: "HelloInGo",
    NextGoFuncData: userData,
    NextJsFunc: "HelloInGo",
    NextJsFuncData: userData,
  };
  return retData;
}

let userData = {
  user1: "password1",
  user2: "password2",
  user3: 123,
  fullName: function () {
    return "firstName" + " " + "lastName";
  },
};

function anotherExample() {
  let fName = userData.fullName();

  let retData = {
    NextGoFunc: "HelloInGo",
    NextGoFuncData: userData,
    NextJsFunc: "HelloInGo",
    NextJsFuncData: userData,
    fullName: fName,
  };
  return retData;
}

function updateTransactionDetails(){
  let formData = data["formData"];
  let items = formData["items"];
  let menuPath = data["menuPath"];
  let pathCode = menuPath["path_code"];
  var dataMap;
  if (typeof items != "undefined" && items.constructor === Array) {
    for (let i = 0; i < items.length; i++) {
      items[i]["invTransactionCode"] = pathCode;
      items[i]["description"] = pathCode;
    }
    formData["items"] = items;
  } else {
    dataMap = items;
    dataMap["invTransactionCode"] = pathCode;
    dataMap["description"] = pathCode;
    formData["items"] = items;
  }
   data["formData"] = formData;
   return data;
}

updateTransactionDetails();


function updateTransactionDetails(){
  let formData = data["formData"];
  let items = formData["items"];
  
  let pathCode = "path_code";
  var dataMap;

  //console.log(items);

  if (typeof items != "undefined" && items.constructor === Array) {
    for (let i = 0; i < items.length; i++) {
      items[i]["invTransactionCode"] = pathCode;
      items[i]["description"] = pathCode;
      console.log( items[i]);
      
    }
    formData["items"] = items;
  } else {
    dataMap = items;
    dataMap["invTransactionCode"] = pathCode;
    dataMap["description"] = pathCode;
    formData["items"] = items;
  }
   data["formData"] = formData;
   return data;

}

data = {"formData" : {"items": [{"invTransactionCode": "TEST_TRANSACTION_CODE", "description": "TEST_TRANSACTION_CODE"}, {"invTransactionCode": "TEST_TRANSACTION_CODE2", "description": "TEST_TRANSACTION_CODE2"}]}};
updateTransactionDetails();
