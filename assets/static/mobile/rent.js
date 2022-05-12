async function validateTotalTime(inputData) {
  
  let retValue = true;
  log("validateTotalTime in js_methods inputData  key & value : " + inputData);

  let freeDays = 0;
  for (key in inputData) {
    if(key == 'ferdig'){
      freeDays = parseInt(inputData[key]);
    }
    log(
      "validateTotalTime in js_methods inputData  key & value : " +
        key +
        " : " +
        typeof inputData[key] +
        " : " +
        inputData[key]
    );
  }

  log("validateTotalTime in js_methods freeDays : " + freeDays);

  if(freeDays > 3){
    log("validateTotalTime in js_methods freeDays 2 : " + freeDays);
    return true;
  }else{
    log("validateTotalTime in js_methods freeDays 3 : " + freeDays);
    let retMessage = {
      'rikProceedFlag' : false,
      'message' : 'No of free days must be greater than 3'
    };
    return retMessage;
  }
}




