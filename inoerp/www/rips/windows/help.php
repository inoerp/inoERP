<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/

include '../config/general.php';
include '../config/securing.php';
include '../config/sinks.php';
include '../config/tokens.php';
include '../config/sources.php';
include '../config/help.php';
include '../lib/printer.php';

$function = htmlentities($_GET['function'], ENT_QUOTES, 'utf-8');
$type = htmlentities($_GET['type'], ENT_QUOTES, 'utf-8');
$type = explode(" (", $type);
$type = $type[0];

switch($type)
{
	case $NAME_XSS: 			$HELP = $HELP_XSS;	
								$FUNCS = $F_SECURING_XSS;
								break;
	case $NAME_HTTP_HEADER: 	$HELP = $HELP_HTTP_HEADER;	
								$FUNCS = array();
								break;	
	case $NAME_SESSION_FIXATION: 	$HELP = $HELP_SESSION_FIXATION;	
								$FUNCS = array();
								break;							
	case $NAME_CODE: 			$HELP = $HELP_CODE;	
								$FUNCS = $F_SECURING_PREG;
								break;
	case $NAME_REFLECTION: 		$HELP = $HELP_REFLECTION;	
								$FUNCS = array();
								break;							
	case $NAME_FILE_INCLUDE: 	$HELP = $HELP_FILE_INCLUDE;
								$FUNCS = $F_SECURING_FILE;
								break;
	case $NAME_FILE_READ: 		$HELP = $HELP_FILE_READ;
								$FUNCS = $F_SECURING_FILE;
								break;
	case $NAME_FILE_AFFECT: 	$HELP = $HELP_FILE_AFFECT;
								$FUNCS = $F_SECURING_FILE;
								break;
	case $NAME_EXEC: 			$HELP = $HELP_EXEC;	
								$FUNCS = $F_SECURING_SYSTEM;
								break;
	case $NAME_DATABASE: 		$HELP = $HELP_DATABASE;
								$FUNCS = $F_SECURING_SQL;
								break;
	case $NAME_XPATH: 			$HELP = $HELP_XPATH;
								$FUNCS = $F_SECURING_XPATH;
								break;
	case $NAME_LDAP: 			$HELP = $HELP_LDAP;
								$FUNCS = $F_SECURING_LDAP;
								break;							
	case $NAME_CONNECT: 		$HELP = $HELP_CONNECT; 
								$FUNCS = array();
								break;
	case $NAME_POP: 			$HELP = $HELP_POP; 
								$FUNCS = array();
								break;							
	default: 					
		$HELP = array(
			'description' => 'No description available for this vulnerability.',
			'link' => '',		
			'code' => 'Not available.',
			'poc' => 'Not available.'
		);	
		break;
}
?>

<div style="padding-left:30px;padding-right:30px">
<h2><?php echo $type; ?></h2>
<h3>vulnerability concept:</h3>

<table class="textcolor">
<tr>
	<th class="helptitle">source</th>
	<th></th>
	<th class="helptitle">sink</th>
	<th></th>
	<th class="helptitle">vulnerability</th>
</tr>
<tr>
<td align="left" class="helpbox">
<ul style="margin-left:-25px">
<?php
if($_GET['get'] || (empty($_GET['get']) && empty($_GET['post']) && empty($_GET['cookie']) && empty($_GET['files']) && empty($_GET['server']))) 	
	echo '<li class="userinput"><a href="'.PHPDOC.'reserved.variables.get" target="_blank">$_GET</a></li>';
if($_GET['post'])	
	echo '<li class="userinput"><a href="'.PHPDOC.'reserved.variables.post" target="_blank">$_POST</a></li>';;
if($_GET['cookie'])	
	echo '<li class="userinput"><a href="'.PHPDOC.'reserved.variables.cookie" target="_blank">$_COOKIE</a></li>';
if($_GET['files']) 	
	echo '<li class="userinput"><a href="'.PHPDOC.'reserved.variables.files" target="_blank">$_FILES</a></li>';
if($_GET['server'])	
	echo '<li class="userinput"><a href="'.PHPDOC.'reserved.variables.server" target="_blank">$_SERVER</a></li>';
?>
</ul>
</td>
<td align="center" valign="center"><h1>+</h1></td>
<td align="center" class="helpbox">
	<?php echo '<a class="link" href="'.PHPDOC.$function.'" target="_blank">'.$function.'()</a>'; ?>
</td>
<td align="center" valign="center"><h1>=</h1></td>
<td align="center" class="helpbox">
<?php echo $type; ?>
</td>
</tr>
</table>

<h3>vulnerability description:</h3>
<p><?php echo $HELP['description']; ?></p>
<p><?php if(!empty($HELP['link'])) echo "More information about $type can be found <a href=\"{$HELP['link']}\" target=\"_blank\">here</a>."; ?></p>

<h3>vulnerable example code:</h3>
<pre><?php echo highlightline(token_get_all($HELP['code']), '', 1); ?></pre>

<h3>proof of concept:</h3>
<p><?php echo htmlentities($HELP['poc']); ?></p>

<h3>patch:</h3>
<p><?php echo htmlentities($HELP['patchtext']); ?></p>
<pre><?php echo highlightline(token_get_all($HELP['patch']), '', 1); ?></pre>

<h3>related securing functions:</h3>
<ul>
<?php
if(!empty($FUNCS))
{
	foreach($FUNCS as $func)
	{
		echo '<li><a class="darkcolor" href="'.PHPDOC.$func.'" target="_blank">'.$func."</a></li>\n";
	}
} else
{
	echo 'None.';
}
?>
</ul>
</div>