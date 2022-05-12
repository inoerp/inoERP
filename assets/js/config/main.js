function main(){
    let allMethods =  {
        "RdSecUser" : {
            "afterGet" : ["user/user.js","removePassword"],
            "BeforePatch" : ["user/user.js","validatePassword"],
            "BeforePost" : ["user/user.js","validatePassword"],
        },
        "RdSecRole" : {
            "BeforeGet" : ["user/user.js","validatePassword"],
            "AfterGet" : ["user/user.js","validatePassword"],
            "BeforePatch" : ["user/user.js","validatePassword"],
            "AfterPatch" : ["user/user.js","validatePassword"],
            "BeforePost" : ["user/user.js","validatePassword"],
            "AfterPost" : ["user/user.js","validatePassword"],
            "BeforeDelete" : ["user/user.js","validatePassword"],
            "AfterDelete" : ["user/user.js","validatePassword"],
        },
    };

    return allMethods;
} 

function global(){
    LOG("In global function");
}

function getData(inputData){
    if (typeof inputData === "string") {
        return JSON.parse(inputData);
      } else {
       return inputData;
      }
}

