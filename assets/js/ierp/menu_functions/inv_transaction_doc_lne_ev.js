function updateTransactionDetails() {
  let formData = data["formData"];
  let entityDefinition = data["entityDefinition"];
  let formFieldsStr = entityDefinition["formFields"];
  let formFieldsMap = JSON.parse(formFieldsStr);
  let formFields = formFieldsMap["fieldData"];
  let items = formData["items"];
  let projectFields = [
    "prjProjectActivityMatId",
    "vvTrnxActivityDescription",
    "vvTrnxActivitySequence",
    "vvTrnxProjectName",
    "vvTrnxProjectNumber",
    "vvTrnxTaskName",
  ];
  let soFields = [
    "sdSoDetailId",
    "vvSoShipmentNumber",
    "vvSoNumber",
    "vvSoLineNumber",
  ];

  let poFields = [
    "poDetailId",
    "vvPoNumber",
    "vvPoLineNumber",
    "vvPoShipmentNumber",
  ];

  let wipFields = [
    "prjProjectActivityMatId",
    "vvTrnxActivityDescription",
    "vvTrnxActivitySequence",
    "vvTrnxProjectName",
    "vvTrnxProjectNumber",
    "vvTrnxTaskNumber",
  ];

  let firstRow = {};
  if (typeof items != "undefined" && items.constructor === Array) {
    firstRow = items[0];
  } else {
    firstRow = formData;
  }

  if (
    firstRow["vvTransactionType"] == "SO_PICKING" ||
    firstRow["vvTransactionType"] == "SO_SHIPPING" ||
    firstRow["vvTransactionType"] == "SO_REVERSE_PICKING" ||
    firstRow["vvTransactionType"] == "SO_REVERSE_SHIPPING" ||
    firstRow["vvTransactionType"] == "SO_RETURN"
  ) {
    for (var i = 0; i < formFields.length; i++) {
      if (formFields[i]["name"] == "sdSoDetailId") {
        formFields[i]["isRequired"] = true;
      } else if (
        projectFields.includes(formFields[i]["name"]) ||
        poFields.includes(formFields[i]["name"]) ||
        wipFields.includes(formFields[i]["name"])
      ) {
        formFields[i]["isDisabled"] = true;
        formFields[i]["isHidden"] = true;
      }
    }
  } else if (
    firstRow["vvTransactionType"] == "PRJ_MATERIAL_ISSUE" ||
    firstRow["vvTransactionType"] == "PRJ_MATERIAL_RETURN"
  ) {
    for (var i = 0; i < formFields.length; i++) {
      if (formFields[i]["name"] == "prjProjectActivityMatId") {
        formFields[i]["isRequired"] = true;
      } else if (
        soFields.includes(formFields[i]["name"]) ||
        poFields.includes(formFields[i]["name"]) ||
        wipFields.includes(formFields[i]["name"])
      ) {
        formFields[i]["isDisabled"] = true;
        formFields[i]["isHidden"] = true;
      }
    }
  } else if (
    firstRow["vvTransactionType"] == "PO_RECEIPT" ||
    firstRow["vvTransactionType"] == "PO_DELIVERY" ||
    firstRow["vvTransactionType"] == "PO_RETURN"
  ) {
    for (var i = 0; i < formFields.length; i++) {
      if (formFields[i]["name"] == "poDetailId") {
        formFields[i]["isRequired"] = true;
      }else if (
        soFields.includes(formFields[i]["name"]) ||
        projectFields.includes(formFields[i]["name"]) ||
        wipFields.includes(formFields[i]["name"])
      ) {
        formFields[i]["isDisabled"] = true;
        formFields[i]["isHidden"] = true;
      }
    }
  } else if (
    firstRow["vvTransactionType"] == "WIP_MATERIAL_ISSUE" ||
    firstRow["vvTransactionType"] == "WIP_MATERIAL_RETURN" ||
    firstRow["vvTransactionType"] == "WIP_NEGATIVE_ISSUE" ||
    firstRow["vvTransactionType"] == "WIP_NEGATIVE_RETURN" ||
    firstRow["vvTransactionType"] == "WIP_WOL_COMPLETION" ||
    firstRow["vvTransactionType"] == "WIP_WOL_RETURN" ||
    firstRow["vvTransactionType"] == "WIP_ASSEMBLY_COMPLETION" ||
    firstRow["vvTransactionType"] == "WIP_ASSEMBLY_RETURN"
  ) {
    for (var i = 0; i < formFields.length; i++) {
      if (formFields[i]["name"] == "wipWoLineMatId") {
        formFields[i]["isRequired"] = true;
      }else if (
        soFields.includes(formFields[i]["name"]) ||
        poFields.includes(formFields[i]["name"]) ||
        wipFields.includes(formFields[i]["name"])
      ) {
        formFields[i]["isDisabled"] = true;
        formFields[i]["isHidden"] = true;
      }
    }
  }

  data["entityDefinition"]["formFields"] = formFields;
  data["entityDefinition"] = entityDefinition;
  data["formData"] = formData;
  return data;
}
updateTransactionDetails();
