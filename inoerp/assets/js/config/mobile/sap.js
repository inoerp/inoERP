function getRequest(inputData) {
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
        log("Js Array Log : " + e);
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
}

function getOrgList(){
  let data2={host:"http://localhost:8085/api/ierp/Org"};
  return getRequest(JSON.stringify(data2));
}


function restRequest(inputData, type, newRequest) {
  let allData;
  if (typeof inputData === "string") {
    allData = JSON.parse(inputData);
  } else {
    allData = inputData;
  }

  let data = allData["data"];
  let requestData = allData["request"];
  if ("Authorization" in requestData) {
    newRequest["authorization"] = requestData["Authorization"];
  }
  
  let response;
  switch (type) {
     case restRequestType.post:
      response = restPost(newRequest);
      break;
    case restRequestType.patch:
      response = restPatch(newRequest);
      break;
    case restRequestType.delete:
      response = restDelete(newRequest);
      break;
    case restRequestType.get:
    default:
      response = restGet(newRequest);
      break;
  }

  let body = response.body;
  if (typeof body === "string") {
    body = JSON.parse(response);
  }

  if (Array.isArray(body)) {
    for (let i = 0; i < body.length; i++) {
      let e = body[i];
      printNestedObject(e);
    }
  } else {
    printNestedObject(body);
  }
}