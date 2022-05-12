async function getOrgDetails(inputData){
  log("Js getOrgDetails in SAP.js: " +inputData);

  log("Js getOrgDetails in SAP.js file WorkCenterInternalID: " + inputData['WorkCenterInternalID']);

  let host = 'http://localhost:8085/api/ierp/Org(orgId=1)';
  if(inputData['WorkCenterInternalID'] == '10000000'){
    host = 'http://localhost:8085/api/ierp/Org(orgId=4)';
  }
  let data2={host:host};
  let retData = await getRequest(JSON.stringify(data2));

  log("Js getOrgDetails in SAP.js file: " +retData);
  return retData;
}



async function getOrgDetails(inputData){
//The rest URL can be the application URL or any external URLs
  let host = 'http://localhost:8085/api/ierp/Org(orgId=1)';

//You can use any vanilla javascript objects/functions/logics
  if(inputData['WorkCenterInternalID'] == '10000000'){
    host = 'http://localhost:8085/api/ierp/Org(orgId=4)';
  }
  let data2={host:host};
  let retData = await getRequest(JSON.stringify(data2));

  return retData;
}

