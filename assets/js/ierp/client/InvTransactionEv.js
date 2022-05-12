function updateTransactionDetails(){
    let formData = data["formData"];
    let items = formData["items"];
    let menuPath = data["menuPath"];
    let pathCode = menuPath["path_code"];
    var dataMap;
    if (typeof items != "undefined" && items.constructor === Array) {
      dataMap = items[0];
      dataMap["invTransactionCode"] = pathCode;
      dataMap["description"] = pathCode;
      dataMap["status"] = "test01";
      formData["items"] = items;
    } else {
      dataMap = items;
      dataMap["invTransactionCode"] = pathCode;
      dataMap["description"] = pathCode;
      dataMap["status"] = "test01";
      formData["items"] = items;
    }
     data["formData"] = formData;
     return data;
  }
  updateTransactionDetails();
  