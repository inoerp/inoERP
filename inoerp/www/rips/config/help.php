<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/

$HELP_XSS = array(
'description' => 'An attacker might execute arbitrary HTML/JavaScript Code in the clients browser context with this security vulnerability. User tainted data is embedded into the HTML output by the application and rendered by the users browser, thus allowing an attacker to embed and render malicious code. Preparing a malicious link will lead to an execution of this malicious code in another users browser context when clicking the link. This can lead to local website defacement, phishing or cookie stealing and session hijacking.',
'link' => 'https://www.owasp.org/index.php/XSS',
'code' => '<?php print("Hello " . $_GET["name"]); ?>',
'poc' => '/index.php?name=<script>alert(1)</script>',
'patchtext' => 'Encode all user tainted data with PHP buildin functions before embedding the data into the output. Make sure to set the parameter ENT_QUOTES to avoid an eventhandler injections to existing HTML attributes and specify the correct charset.',
'patch' => '<?php print("Hello " . htmlentities($_GET["name"], ENT_QUOTES, "utf-8"); ?>' 
);

$HELP_HTTP_HEADER = array(
'description' => 'An attacker can inject arbitrary headers to the HTTP response header. This can be abused for a redirect when injecting a "Location:" header or help within a session fixation attack when the "Set-Cookie:" header is added. Additionally, the HTTP response can be overwritten and JavaScript can be injected leading to Cross-Site Scripting attacks. In PHP version below 4.4.2 or 5.1.2 the characters \n\r (LF CR) can be used for header line termination (cross-browser). In PHP below 5.4 the character \r (CR) can still be used for header line termination (Chrome, IE).',
'link' => 'https://www.owasp.org/index.php/HTTP_Response_Splitting',
'code' => '<?php header("Location: ".$_GET["url"]); ?>',
'poc' => '/index.php?url=a%0a%0dContent-Type:%20text/html%0a%0d%0a%0d<script>alert(1)</script>',
'patchtext' => 'Update PHP to prevent header injection or implement a whitelist.',
'patch' => '<?php if(!in_array($_GET["url"], $whitelist)) exit; ?>'
);

$HELP_SESSION_FIXATION = array(
'description' => 'An attacker can force a user to use a specific session id. Once the user logs in, the attacker can use the previously fixated session id to access the account.',
'link' => 'https://www.owasp.org/index.php/Session_fixation',
'code' => '<?php setcookie("PHPSESSID", $_GET["sessid"]); ?>',
'poc' => '/index.php?sessid=1f3870be274f6c49b3e31a0c6728957f',
'patchtext' => 'Do not use a session token supplied by the user.',
'patch' => 'No code.'
);

$HELP_CODE = array(
'description' => 'An attacker might execute arbitrary PHP code with this vulnerability. User tainted data is embedded into a function that compiles PHP code on the run and executes it thus allowing an attacker to inject own PHP code that will be executed. This vulnerability can lead to full server compromise.',
'link' => 'https://www.owasp.org/index.php/Code_Injection',
'code' => '<?php eval("\$color = \'" . $_GET["color"] . "\';"); ?>',
'poc' => '/index.php?color=\';phpinfo();//',
'patchtext' => 'Build a whitelist for positive code with regular expressions (e.g. alphanumeric only) or arrays. Do not try to blacklist for evil PHP code.',
'patch' => '<?php $colors = array("blue", "red"); if(!in_array($_GET["color"], $colors)) exit; ?>'
);

$HELP_REFLECTION = array(
'description' => 'An attacker might execute arbitrary functions with this vulnerability. User tainted data is used as a function name. This can lead to unexpected behaviour of the application.',
'link' => 'https://www.owasp.org/index.php/Reflection_injection',
'code' => '<?php call_user_func($_GET["func"]); ?>',
'poc' => '/index.php?func=phpinfo',
'patchtext' => 'Build a whitelist for allowed functions.',
'patch' => '<?php $funcs = array("test1", "test2"); if(!in_array($_GET["func"], $funcs)) exit; ?>'
);

$HELP_FILE_INCLUDE = array(
'description' => 'An attacker might include local or remote PHP files or read non-PHP files with this vulnerability. User tainted data is used when creating the file name that will be included into the current file. PHP code in this file will be evaluated, non-PHP code will be embedded to the output. This vulnerability can lead to full server compromise.',
'link' => 'http://websec.wordpress.com/2010/02/22/exploiting-php-file-inclusion-overview/',
'code' => '<?php include("includes/" . $_GET["file"]); ?>',
'poc' => '/index.php?file=../../../../../../../etc/passwd',
'patchtext' => 'Build a whitelist for positive file names. Do not only limit the file name to specific paths or extensions.',
'patch' => '<?php $files = array("index.php", "main.php"); if(!in_array($_GET["file"], $files)) exit; ?>'
);

$HELP_FILE_READ = array(
'description' => 'An attacker might read local files with this vulnerability. User tainted data is used when creating the file name that will be opened and read, thus allowing an attacker to read source code and other arbitrary files on the webserver that might lead to new attack vectors. In example the attacker can detect new vulnerabilities in source code files or read user credentials.',
'link' => '',
'code' => '<?php echo file_get_contents("files/" . $_GET["file"]); ?>',
'poc' => '/index.php?file=../../../../../../../etc/passwd',
'patchtext' => 'Build a whitelist for positive file names. Do not only limit the file name to specific paths or extensions.',
'patch' => '<?php $files = array("index.php", "main.php"); if(!in_array($_GET["file"], $files)) exit; ?>'
);

$HELP_FILE_AFFECT = array(
'description' => 'An attacker might write to arbitrary files or inject arbitrary code into a file with this vulnerability. User tainted data is used when creating the file name that will be opened or when creating the string that will be written to the file. An attacker can try to write arbitrary PHP code in a PHP file allowing to fully compromise the server.',
'link' => '',
'code' => '<?php $h = fopen($_GET["file"], "w"); fwrite($h, $_GET["data"]); ?>',
'poc' => '/index.php?file=shell.php&data=<?php phpinfo();?>',
'patchtext' => 'Build a whitelist for positive file names. Do not only limit the file name to specific paths or extensions. If you write into PHP files make sure an attacker can not write own PHP code. Use a whitelist with arrays or regular expressions (e.g. alphanumeric only).',
'patch' => '<?php $files = array("index.php", "main.php"); if(!in_array($_GET["file"], $files)) exit; ?>'
);

$HELP_EXEC = array(
'description' => 'An attacker might execute arbitrary system commands with this vulnerability. User tainted data is used when creating the command that will be executed on the underlying operating system. This vulnerability can lead to full server compromise.',
'link' => '',
'code' => '<?php exec("./crypto -mode " . $_GET["mode"]); ?>',
'poc' => '/index.php?mode=1;sleep 10;',
'patchtext' => 'Limit the code to a very strict character subset or build a whitelist of allowed commands. Do not try to filter for evil commands. Try to avoid the usage of system command executing functions if possible.',
'patch' => '<?php $modes = array("r", "w", "a"); if(!in_array($_GET["mode"], $modes)) exit; ?>'
);

$HELP_DATABASE = array(
'description' => 'An attacker might execute arbitrary SQL commands on the database server with this vulnerability. User tainted data is used when creating the database query that will be executed on the database management system (DBMS). An attacker can inject own SQL syntax thus initiate reading, inserting or deleting database entries or attacking the underlying operating system depending on the query, DBMS and configuration.',
'link' => 'https://www.owasp.org/index.php/SQL_Injection',
'code' => '<?php mysql_query("SELECT * FROM users WHERE id = " . $_GET["id"]); ?>',
'poc' => '/index.php?id=1 OR 1=1-- -',
'patchtext' => 'Always embed expected strings into quotes and escape the string with a PHP buildin function before embedding it to the query. Always embed expected integers without quotes and typecast the data to integer before embedding it to the query. Escaping data but embedding it without quotes is not safe.',
'patch' => '<?php mysql_query("SELECT * FROM users WHERE id = " . (int)$_GET["id"]); '."\n".' mysql_query("SELECT * FROM users WHERE name = \'" . mysql_real_escape_string($_GET["name"]) . "\'"); ?>'
);

$HELP_XPATH = array(
'description' => 'An attacker might execute arbitrary XPath expressions with this vulnerability. User tainted data is used when creating the XPath expression that will be executed on a XML resource. An attacker can inject own XPath syntax to read arbitrary XML entries.',
'link' => 'http://packetstormsecurity.org/files/view/33380/Blind_XPath_Injection_20040518.pdf',
'code' => '<?php $ctx->xpath_eval("//user[name/text()=\'" . $_GET["name"] . "\']/account/text()"); ?>',
'poc' => '/index.php?name=\' or \'\'=\'',
'patchtext' => 'Always embed expected strings into quotes and escape the string with a PHP buildin function before embedding it to the expression. Always embed expected integers without quotes and typecast the data to integer before embedding it to the expression. Escaping data but embedding it without quotes is not safe.',
'patch' => '<?php $ctx->xpath_eval("//user[name/text()=\'" . addslashes($_GET["name"]) . "\']/account/text()"); ?>'
);

$HELP_LDAP = array(
'description' => 'An attacker might execute arbitrary LDAP expressions with this vulnerability. User tainted data is used when creating a LDAP filter that will be executed on a LDAP server. An attacker can inject own LDAP syntax to read arbitrary LDAP entries.',
'link' => 'http://www.blackhat.com/presentations/bh-europe-08/Alonso-Parada/Whitepaper/bh-eu-08-alonso-parada-WP.pdf',
'code' => '<?php ldap_search($ds, $dn, "(&(sn=person)(person=".$_GET["person"]."))"); ?>',
'poc' => '/index.php?person=*',
'patchtext' => 'Expected strings are not embedded into quotes in LDAP. Limit the input character set to alphanumeric (if possible) to prevent an injection of filter syntax.',
'patch' => '<?php if(!preg_match(\'/^[a-z0-9]+$/\', $_GET["person"])) exit; ?>'
);

$HELP_CONNECT = array(
'description' => 'An attacker might change connection handling parameters or data that is being transfered with this vulnerability. User tainted data is used when selecting parameters or creating data that will be transfered thus allowing an attacker to change them. Depending on the type of connection this might lead to further attacks.',
'link' => '',
'code' => 'Can not be generalized.',
'poc' => 'Can not be generalized.',
'patchtext' => 'Can not be generalized.',
'patch' => 'Can not be generalized.'
);

$HELP_POP = array(
'description' => 'When userinput is parsed by the unserialize() function an attacker may abuse this by supplying serialized objects that will be used in the current application scope. These objects can only be instances of classes of this application. Several gadgets such as __wakeup() or __destruct() functions of those classes will be automatically called when the object is resurrected during the unserialization and object variables specified by the attacker may lead to vulnerabilities in those gadgets.',
'link' => 'https://media.blackhat.com/bh-us-10/presentations/Esser/BlackHat-USA-2010-Esser-Utilizing-Code-Reuse-Or-Return-Oriented-Programming-In-PHP-Application-Exploits-slides.pdf',
'code' => '<?php
class foo { 
	public $file = "test.txt";
	public $data = "text"; 
	function __destruct() 
	{ 
		file_put_contents($this->file, $this->data); 
	} 
} 
$a = unserialize($_GET["s"]);
?>',
'poc' => '/index.php?s=O:3:"foo":2:{s:4:"file";s:9:"shell.php";s:4:"data";s:29:"<?php passthru($_GET["c"]);?>";}',
'patchtext' => 'Prevent using unserialize because it contains much more flaws.',
'patch' => 'No code.'
);
?>