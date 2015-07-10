<?php
class JaxWsSoapClient extends SoapClient {

 public function __call($method, $arguments) {
  $response = parent::__call($method, $arguments);
  return $response->return;
 }

}

ini_set('soap.wsdl_cache_enabled', 0);
ini_set('soap.wsdl_cache_ttl', 0);
try {
 $client = new SoapClient("http://116.66.198.19:80/us/UnitedSolutions?wsdl", array("trace" => 1,
  "location" => "http://116.66.198.19:80/us/UnitedSolutions",
  "uri" => "http://booking.us.org/"));
 $addRequest = new stdClass();
 $addRequest->strUserId = "NEPTRI";
 $addRequest->strAirlineId = "RMK";
 $addRequest->strPassword = "PASSWORD";
 $addRequest->strAgencyId = "PLZ029";
 $addRequest->strSectorFrom = "KTM";
 $addRequest->strSectorTo = "PKR";
 $addRequest->strFlightDate = "17-JUL-2015";
 $addRequest->strReturnDate = "";
 $addRequest->strTripType = "O";
 $addRequest->strNationality = "US";
 $addRequest->intAdult = "1";
 $addRequest->intChild = "0";
 $addRequest->strPnoNo = "ZSPW2A";
 $addRequest->strTicketNo = "195329";
 $addRequest->strFromDate = "15-JUL-2015";
 $addRequest->strToDate = "25-JUL-2015";
//$addRequest->strFlightId = "0d1579f3-3840-41b1-a61d-68b3e5adc386";

 $client->FlightAvailability($addRequest);


 $xmlstr = $client->__getLastResponse();
  $doc = new DOMDocument();
 $doc->loadXML($xmlstr);
 echo '<pre>';
 echo $xmlstr;
 print_r($doc);
 
 function xml_to_array($root) {
    $result = array();

    if ($root->hasAttributes()) {
        $attrs = $root->attributes;
        foreach ($attrs as $attr) {
            $result['@attributes'][$attr->name] = $attr->value;
        }
    }

    if ($root->hasChildNodes()) {
        $children = $root->childNodes;
        if ($children->length == 1) {
            $child = $children->item(0);
            if ($child->nodeType == XML_TEXT_NODE) {
                $result['_value'] = $child->nodeValue;
                return count($result) == 1
                    ? $result['_value']
                    : $result;
            }
        }
        $groups = array();
        foreach ($children as $child) {
            if (!isset($result[$child->nodeName])) {
                $result[$child->nodeName] = xml_to_array($child);
            } else {
                if (!isset($groups[$child->nodeName])) {
                    $result[$child->nodeName] = array($result[$child->nodeName]);
                    $groups[$child->nodeName] = 1;
                }
                $result[$child->nodeName][] = xml_to_array($child);
            }
        }
    }

    return $result;
}


$doc_a = xml_to_array($doc);
 print_r($doc_a);
// print_r($xml);
//// print_r($doc);
////$arrFeeds = array();
 foreach ($doc_a as $node) {
  $Airline = $node->getElementsByTagName('Airline')->item(0)->nodeValue;
  $FlightNo = $node->getElementsByTagName('FlightNo')->item(0)->nodeValue;
  $Departure = $node->getElementsByTagName('Departure')->item(0)->nodeValue;
  $Arrival = $node->getElementsByTagName('Arrival')->item(0)->nodeValue;
  $Class = $node->getElementsByTagName('FlightClassCode')->item(0)->nodeValue;
  $Currency = $node->getElementsByTagName('Currency')->item(0)->nodeValue;
  echo $Fare = $node->getElementsByTagName('ResFare')->item(0)->nodeValue;
 }
} catch (SoapFault $exception) {
 print_r("We Have Some Issue/Error:<br/>");
 print_r($exception->getMessage());
}
?>