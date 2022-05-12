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
