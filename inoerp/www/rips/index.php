<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			

Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.		

**/

include 'config/general.php';

?><html>
<head>
	<meta charset="UTF-8">
	<link rel="stylesheet" type="text/css" href="css/rips.css" />
	<?php

	foreach($stylesheets as $stylesheet)
	{
		echo "\t<link type=\"text/css\" href=\"css/$stylesheet.css\" rel=\"";
		if($stylesheet != $default_stylesheet) echo "alternate ";
		echo "stylesheet\" title=\"$stylesheet\" />\n";
	}
	?>
	<script src="js/script.js"></script>
	<script src="js/exploit.js"></script>
	<script src="js/hotpatch.js"></script>
	<script src="js/netron.js"></script>
	<title>RIPS - A static source code analyser for vulnerabilities in PHP scripts</title>
</head>
<body>

<div class="menu">
	<div style="float:left; width:100%;">
	<table width="100%">
	<tr><td width="75%" nowrap>
		<table class="menutable" width="50%" style="float:left;">
		<tr>
			<td nowrap><b>path / file:</b></td>
			<td colspan="3" nowrap><input type="text" size=80 id="location" value="<?php echo BASEDIR; ?>" title="enter path to PHP file(s)" placeholder="/var/www/">
			</td>
			<td nowrap><input type="checkbox" id="subdirs" value="1" title="check to scan subdirectories" checked/>subdirs
			</td>
		</tr>
		<tr>
			<td nowrap>verbosity level:</td>
			<td nowrap>
				<select id="verbosity" style="width:100%" title="select verbosity level">
					<?php 
					
						$verbosities = array(
							1 => '1. user tainted only',
							2 => '2. file/DB tainted +1',
							3 => '3. show secured +1,2',
							4 => '4. untainted +1,2,3',
							5 => '5. debug mode'
						);
						
						foreach($verbosities as $level=>$description)
						{
							echo "<option value=\"$level\">$description</option>\n";							
						}
					?>
				</select>
			</td>
			<td align="right" nowrap>
			vuln type:
			</td>
			<td>
				<select id="vector" style="width:100%" title="select vulnerability type to scan">
					<?php 
					
						$vectors = array(
							'all' 			=> 'All',
							'server' 		=> 'All server-side',							
							'code' 			=> '- Code Execution',
							'exec' 			=> '- Command Execution',
							'file_read' 	=> '- File Disclosure',
							'file_include' 	=> '- File Inclusion',							
							'file_affect' 	=> '- File Manipulation',
							'ldap' 			=> '- LDAP Injection',
							'unserialize' 	=> '- PHP Object Injection',
							'connect'		=> '- Protocol Injection',							
							'ri'		 	=> '- Reflection Injection',
							'database' 		=> '- SQL Injection',
							'xpath' 		=> '- XPath Injection',
							'other' 		=> '- other',
							'client' 		=> 'All client-side',
							'xss' 			=> '- Cross-Site Scripting',
							'httpheader'	=> '- HTTP Response Splitting',
							'fixation'		=> '- Session Fixation',
							//'crypto'		=> 'Crypto hints'
						);
						
						foreach($vectors as $vector=>$description)
						{
							echo "<option value=\"$vector\" ";
							if($vector == $default_vector) echo 'selected';
							echo ">$description</option>\n";
						}
					?>
				</select>
			</td>
			<td><input type="button" value="scan" style="width:100%" class="Button" onClick="scan(false);" title="start scan" /></td>
		</tr>
		<tr>
			<td nowrap>code style:</td>
			<td nowrap>
				<select name="stylesheet" id="css" onChange="setActiveStyleSheet(this.value);" style="width:49%" title="select color schema for scan result">
					<?php 
						foreach($stylesheets as $stylesheet)
						{
							echo "<option value=\"$stylesheet\" ";
							if($stylesheet == $default_stylesheet) echo 'selected';
							echo ">$stylesheet</option>\n";
						}
					?>	
				</select>
				<select id="treestyle" style="width:49%" title="select direction of code flow in scan result">
					<option value="1">bottom-up</option>
					<option value="2">top-down</option>
				</select>	
			</td>	
			<td align="right">
				/regex/:
			</td>
			<td>
				<input type="text" id="search" style="width:100%" />
			</td>
			<td>
				<input type="button" class="Button" style="width:100%" value="search" onClick="search()" title="search code by regular expression" />
			</td>
		</tr>
		</table>
		<div id="options" style="margin-top:-10px; display:none; text-align:center;" >
			<p class="textcolor">windows</p>
			<input type="button" class="Button" style="width:50px" value="files" onClick="openWindow(5);eval(document.getElementById('filegraph_code').innerHTML);" title="show list of scanned files" />
			<input type="button" class="Button" style="width:80px" value="user input" onClick="openWindow(4)" title="show list of user input" /><br />
			<input type="button" class="Button" style="width:50px" value="stats" onClick="document.getElementById('stats').style.display='block';" title="show scan statistics" />
			<input type="button" class="Button" style="width:80px" value="functions" onClick="openWindow(3);eval(document.getElementById('functiongraph_code').innerHTML);" title="show list of user-defined functions" />
		</div>
	</td>
	<td width="25%" align="center" valign="center" nowrap>
		<!-- Logo by Gareth Heyes -->
		<div class="logo"><a id="logo" href="https://www.ripstech.com/latest/" target="_blank" title="get the latest version"><?php echo VERSION ?></a></div>
	</td></tr>
	</table>
	</div>
	
	<div style="clear:left;"></div>
</div>
<div class="menushade"></div>

<div class="scanning" id="scanning">scanning ...
<div class="scanned" id="scanned"></div>
</div>

<div id="result">
	
	<div style="margin-left:30px;color:#000000;font-size:14px">
		<h3>Quickstart:</h3>
		<p>Locate your local PHP source code <b>path/file</b> (e.g. <em>/var/www/project1/</em> or <em>/var/www/index.php</em>), choose the <b>vulnerability type</b> you are looking for and click <u>scan</u>!<br />
		Check <b>subdirs</b> to include all subdirectories into the scan. It is recommended to scan only the root directory of your project. Files in subdirectories will be automatically scanned by RIPS when included by the PHP code. However enabling <b>subdirs</b> can improve the scan result and the include success rate (shown in the result).</p>
		<h3>Advanced:</h3>
		<p>Debug errors or improve your scan result by choosing a different <b>verbosity level</b> (default level 1 is recommended).<br />
		After the scan finished 4 new button will appear in the upper right. You can select between different types of vulnerabilities that have been found by clicking on their name in the <b>stats</b> window. You can click <b>user input</b> in the upper right to get a list of entry points, <b>functions</b> for a list and graph of all user defined functions or <b>files</b> for a list and graph of all scanned files and their includes. All lists are referenced to the Code Viewer.</p>
		<h3>Style:</h3>
		<p>Change the syntax highlighting schema on-the-fly by selecting a different <b>code style</b>.<br />
		Before scanning you can choose which way the code flow should be displayed: <b>bottom-up</b> or <b>top-down</b>.</p>
		<h3>Icons:</h3>
		<ul>
		<li class="userinput"><font color="black"><b>User input</b> has been found in this line. Potential entry point for vulnerability exploitation.</font></li>
		<li class="functioninput"><font color="black">Vulnerability exploitation depends on the <b>parameters</b> passed to the function declared in this line. Have a look at the calls in the scan result.<br />Click <b>&uArr;</b> or <b>&dArr;</b> to jump to the next declaration or call of this function.</font></li>
		<li class="validated"><font color="black">User-implemented <b>securing</b> has been detected in this line. This may prevent exploitation.</font></li>
		</ul>
		<h3>Options:</h3>
		<ul>
		<li><div class="fileico"></div>&nbsp;Click the file icon to open the <b>Code Viewer</b> to review the original code. A new window will be opened with all relevant lines highlighted.<br />
		Highlight variables temporarily by mouseover or persistently by clicking on the variable. Jump into the code of a user-defined function by clicking on the call. Click <u>return</u> on the bottom of the code viewer to jump back. This also works for nested function calls.</li>
		<li><div class="minusico"></div>&nbsp;Click the minimize icon to <b>hide</b> a specific code trace. You may display it later by clicking the icon again.</li>
		<li><div class="exploit"></div>&nbsp;Click the target icon to open the <b>Exploit Creator</b>. A new window will open where you can enter exploit details and create PHP Curl exploit code.</li>
		<li><div class="help"></div>&nbsp;Click the help icon to get a <b>description</b>, example code, example exploitation, patch and related securing functions for this vulnerability type.</li>
		<li><div class="dataleak"></div>&nbsp;Click the data leak icon to check if the output of the tainted sink <b>leaks</b> somewhere (is embedded to the HTTP response via echo/print).</li>
		</ul>
		<h3>Hints:</h3>
		<ul>
		<li>RIPS implements <i>static</i> source code analysis. It only scans source code files and will not execute the code.</li>
		<li>Object-oriented code (classes) is not supported in this version.</li>
		<li>Make sure RIPS has file permissions on the files to be scanned.</li>
		<li>Don't leave the webinterface of RIPS open to the public internet. Use it on your <b>local</b> webserver only.</li>
		<li>Only tested with Firefox.</li>
		</ul>
	</div>
	
</div>

</body>
</html>