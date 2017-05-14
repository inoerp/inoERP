<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
set_time_limit(0);

include_once("includes/template/header_public.inc");
?>
<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<?php
$db = new dbObject();
$dbc = new dbc();


if(!($sock = socket_create(AF_INET, SOCK_STREAM, 0)))
{
    $errorcode = socket_last_error();
    $errormsg = socket_strerror($errorcode);
     
    die("Couldn't create socket: [$errorcode] $errormsg \n");
}
 
echo "Socket created \n";
 
//Connect socket to remote server
if(!socket_connect($sock , '10.10.10.10' , 9100))
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
