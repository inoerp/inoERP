<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
set_time_limit(0);

include_once("includes/basics/header_public.inc");
?>
<link href="<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<?php
$db = new dbObject();
$dbc = new dbc();


$xml_content = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE labels SYSTEM "label.dtd">
<labels _FORMAT="E:M_STK_M.ZPL" _QUANTITY="1" _PRINTERNAME="SNG_ZM400_1" _JOBNAME="LBL512027">
<label>
<variable name= "COHR_DATE">19-NOV-2014</variable>
<variable name= "COHR_ITEM">1214874</variable>
<variable name= "COHR_ITEM_DESC">Power Supply, OBIS, 12 VDC, with 8ft USA-type Power Cord</variable>
<variable name= "COHR_LOCATOR">RAW-01.04.01.03.</variable>
<variable name= "COHR_LOT"></variable>
<variable name= "COHR_QTY">50</variable>
<variable name= "COHR_RCPT"></variable>
<variable name= "COHR_SUB">RAW-01</variable>
<variable name= "COHR_UOM">EA</variable>
</label>
</labels>
';


if(!($sock = socket_create(AF_INET, SOCK_STREAM, 0)))
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
     
    die("Couldn't create socket: [$errorcode] $errormsg \n");
}
 
echo "Socket created \n";
 
//Connect socket to remote server
if(!socket_connect($sock , '10.194.4.10' , 9100))
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
     
    die("Could not connect: [$errorcode] $errormsg \n");
}
 
echo "Connection established \n";
 
//$message = "GET / HTTP/1.1\r\n\r\n";
 
//Send the message to the server
if( ! socket_send ( $sock , $xml_content , strlen($xml_content) , 0))
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
     
    die("Could not send data: [$errorcode] $errormsg \n");
}
 
echo "Message send successfully \n";

//$fp = stream_socket_client("10.194.4.10:80", $errno, $errstr, 30);
//if (!$fp) {
//    echo "$errstr ($errno)<br />\n";
//} else {
//    fwrite($fp, $xml_content);
//    while (!feof($fp)) {
//        echo fgets($fp, 1024);
//    }
//    fclose($fp);
//}


//execution_time();
execution_time();
include_template('footer.inc')
?>
