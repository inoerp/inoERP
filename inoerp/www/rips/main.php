<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			

Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.		

**/

	###############################  INCLUDES  ################################

	include('config/general.php');			// general settings
	include('config/sources.php');			// tainted variables and functions
	include('config/tokens.php');			// tokens for lexical analysis
	include('config/securing.php');			// securing functions
	include('config/sinks.php');			// sensitive sinks
	include('config/info.php');				// interesting functions
	
	include('lib/constructer.php'); 		// classes	
	include('lib/filer.php');				// read files from dirs and subdirs
	include('lib/tokenizer.php');			// prepare and fix token list
	include('lib/analyzer.php');			// string analyzers
	include('lib/scanner.php');				// provides class for scan
	include('lib/printer.php');				// output scan result
	include('lib/searcher.php');			// search functions
		
	###############################  MAIN  ####################################
	
	$start = microtime(TRUE);
	
	$output = array();
	$info = array();
	$scanned_files = array();
	
	if(!empty($_POST['loc']))
	{		
		$location = realpath($_POST['loc']);
		
		if(is_dir($location))
		{
			$scan_subdirs = isset($_POST['subdirs']) ? $_POST['subdirs'] : false;
			$files = read_recursiv($location, $scan_subdirs);
			
			if(count($files) > WARNFILES && !isset($_POST['ignore_warning']))
				die('warning:'.count($files));
		}	
		else if(is_file($location) && in_array(substr($location, strrpos($location, '.')), $FILETYPES))
		{
			$files[0] = $location;
		}
		else
		{
			$files = array();
		}
		
	
		// SCAN
		if(empty($_POST['search']))
		{
			$user_functions = array();
			$user_functions_offset = array();
			$user_input = array();
			
			$file_sinks_count = array();
			$count_xss=$count_sqli=$count_fr=$count_fa=$count_fi=$count_exec=$count_code=$count_eval=$count_xpath=$count_ldap=$count_con=$count_other=$count_pop=$count_inc=$count_inc_fail=$count_header=$count_sf=$count_ri=0;
			
			$verbosity = isset($_POST['verbosity']) ? $_POST['verbosity'] : 1;
			$scan_functions = array();
			$info_functions = Info::$F_INTEREST;
			
			if($verbosity != 5)
			{
				switch($_POST['vector']) 
				{
					case 'xss':			$scan_functions = $F_XSS;			break;
					case 'httpheader':	$scan_functions = $F_HTTP_HEADER;	break;
					case 'fixation':	$scan_functions = $F_SESSION_FIXATION;	break;
					case 'code': 		$scan_functions = $F_CODE;			break;
					case 'ri': 			$scan_functions = $F_REFLECTION;	break;
					case 'file_read':	$scan_functions = $F_FILE_READ;		break;
					case 'file_affect':	$scan_functions = $F_FILE_AFFECT;	break;		
					case 'file_include':$scan_functions = $F_FILE_INCLUDE;	break;			
					case 'exec':  		$scan_functions = $F_EXEC;			break;
					case 'database': 	$scan_functions = $F_DATABASE;		break;
					case 'xpath':		$scan_functions = $F_XPATH;			break;
					case 'ldap':		$scan_functions = $F_LDAP;			break;
					case 'connect': 	$scan_functions = $F_CONNECT;		break;
					case 'other':		$scan_functions = $F_OTHER;			break;
					case 'unserialize':	{
										$scan_functions = $F_POP;				
										$info_functions = Info::$F_INTEREST_POP;
										$source_functions = array('unserialize');
										$verbosity = 2;
										} 
										break;
					case 'client':
						$scan_functions = array_merge(
							$F_XSS,
							$F_HTTP_HEADER,
							$F_SESSION_FIXATION
						);
						break;
					case 'server': 
						$scan_functions = array_merge(
							$F_CODE,
							$F_REFLECTION,
							$F_FILE_READ,
							$F_FILE_AFFECT,
							$F_FILE_INCLUDE,
							$F_EXEC,
							$F_DATABASE,
							$F_XPATH,
							$F_LDAP,
							$F_CONNECT,
							$F_POP,
							$F_OTHER
						); break;	
					case 'all': 
					default:
						$scan_functions = array_merge(
							$F_XSS,
							$F_HTTP_HEADER,
							$F_SESSION_FIXATION,
							$F_CODE,
							$F_REFLECTION,
							$F_FILE_READ,
							$F_FILE_AFFECT,
							$F_FILE_INCLUDE,
							$F_EXEC,
							$F_DATABASE,
							$F_XPATH,
							$F_LDAP,
							$F_CONNECT,
							$F_POP,
							$F_OTHER
						); break;
				}
			}	
			
			if($_POST['vector'] !== 'unserialize')
			{
				$source_functions = Sources::$F_OTHER_INPUT;
				// add file and database functions as tainting functions
				if( $verbosity > 1 && $verbosity < 5 )
				{
					$source_functions = array_merge(Sources::$F_OTHER_INPUT, Sources::$F_FILE_INPUT, Sources::$F_DATABASE_INPUT);
				}
			}	
					
			$overall_time = 0;
			$timeleft = 0;
			$file_amount = count($files);		
			for($fit=0; $fit<$file_amount; $fit++)
			{
				// for scanning display
				$thisfile_start = microtime(TRUE);
				$file_scanning = $files[$fit];
				
				echo ($fit) . '|' . $file_amount . '|' . $file_scanning . '|' . $timeleft . '|' . "\n";
				@ob_flush();
				flush();
	
				// scan
				$scan = new Scanner($file_scanning, $scan_functions, $info_functions, $source_functions);
				$scan->parse();
				$scanned_files[$file_scanning] = $scan->inc_map;
				
				$overall_time += microtime(TRUE) - $thisfile_start;
				// timeleft = average_time_per_file * file_amount_left
				$timeleft = round(($overall_time/($fit+1)) * ($file_amount - $fit+1),2);
			}
			#die("done");
			echo "STATS_DONE.\n";
			@ob_flush();
			flush();
			
		}
		// SEARCH
		else if(!empty($_POST['regex']))
		{
			$count_matches = 0;
			$verbosity = 0;
			foreach($files as $file_name)
			{
				searchFile($file_name, $_POST['regex']);
			}
		}
	} 
	
	$elapsed = microtime(TRUE) - $start;

	################################  RESULT  #################################	
?>	
<div id="window1" name="window" style="width:600px; height:250px;">
	<div class="windowtitlebar">
		<div id="windowtitle1" onClick="toTop(1)" onmousedown="dragstart(1)" class="windowtitle"></div>
		<input id="maxbutton1" type="button" class="maxbutton" value="&nabla;" onClick="maxWindow(1, 800)" title="maximize" />
		<input type="button" class="closebutton" value="x" onClick="closeWindow(1)" title="close" />
	</div>

	<div style="position:relative;width:100%;">
	<div id="scrolldiv">
		<div id="scrollwindow"></div>
		<div id="scrollcode"></div>
	</div>
	<div id="windowcontent1" class="windowcontent" onscroll="scroller()"></div>
	<div style="clear:left;"></div>
	</div>
	
	<div id="return" class="return" onClick="returnLastCode()">&crarr; return</div>
	<div class="windowfooter" onmousedown="resizeStart(event, 1)"></div>
</div>

<div id="window2" name="window" style="width:600px; height:250px;">
	<div class="windowtitlebar">
		<div id="windowtitle2" onClick="toTop(2)" onmousedown="dragstart(2)" class="windowtitle"></div>
		<input type="button" class="closebutton" value="x" onClick="closeWindow(2)" title="close" />
	</div>
	<div id="windowcontent2" class="windowcontent"></div>
	<div class="windowfooter" onmousedown="resizeStart(event, 2)"></div>
</div>

<div id="window3" name="window" style="width:300px; height:300px;">
	<div class="funclisttitlebar">
		<div id="windowtitle3" onClick="toTop(3)" onmousedown="dragstart(3)" class="funclisttitle">
		user defined functions and calls
		</div>
		<input type="button" class="closebutton" value="x" onClick="closeWindow(3)" title="close" />
	</div>
	<div id="windowcontent3" class="funclistcontent">
		<div >
			<input type="button" id="functionlistbutton" class="button" onclick="showlist('function');minWindow(3, 650);" value="list" style="background:white;color:black;" />
			<input type="button" id="functiongraphbutton" class="button" onclick="showgraph('function');maxWindow(3, 650);" value="graph"/>
			<input type="button" id="functioncanvassave" class="button" onclick="saveCanvas('functioncanvas', 3)" value="save graph" />
			<?php  if($verbosity == 5) echo '<br>(graph not available in debug mode)'; ?>
		</div>
		<?php
			createFunctionList($user_functions_offset);		
		?>
		<div id="canvas3" style="display:none"></div>
		<canvas id="functioncanvas" tabindex="0" width="650" height="<?php echo (count($user_functions_offset)/4)*70+200; ?>"></canvas>	
	</div>	
	<div class="funclistfooter" onmousedown="resizeStart(event, 3)"></div>
</div>

<div id="window4" name="window" style="width:300px; height:300px;">
	<div class="funclisttitlebar">
		<div id="windowtitle4" onClick="toTop(4)" onmousedown="dragstart(4)" class="funclisttitle">
		user input
		</div>
		<input type="button" class="closebutton" value="x" onClick="closeWindow(4)" title="close" />
	</div>
	<div id="windowcontent4" class="funclistcontent">
		<?php
			createUserinputList($user_input);		
		?>
	</div>
	<div class="funclistfooter" onmousedown="resizeStart(event, 4)"></div>
</div>

<div id="window5" name="window" style="width:300px; height:300px;">
	<div class="funclisttitlebar">
		<div id="windowtitle4" onClick="toTop(5)" onmousedown="dragstart(5)" class="funclisttitle">
		scanned files and includes
		</div>
		<input type="button" class="closebutton" value="x" onClick="closeWindow(5)" title="close" />
	</div>
	<div id="windowcontent5" class="funclistcontent">
		<div >
			<input type="button" id="filelistbutton" class="button" onclick="showlist('file');minWindow(5, 650);" value="list" style="background:white;color:black;"/>
			<input type="button" id="filegraphbutton" class="button" onclick="showgraph('file');maxWindow(5, 650);" value="graph"/>
			<input type="button" id="filecanvassave" class="button" onclick="saveCanvas('filecanvas', 5)" value="save graph" />
		</div>
		<?php
			createFileList($scanned_files, $file_sinks_count);		
		?>
		<div id="canvas5" style="display:none"></div>
		<canvas id="filecanvas" tabindex="0" width="650" height="<?php echo (count($files)/4)*70+200; ?>"></canvas>
	</div>
	<div class="funclistfooter" onmousedown="resizeStart(event, 5)"></div>
</div>		

<div id="funccode" onclick="closeFuncCode()">
	<div id="funccodetitle" onmouseout="closeFuncCode()"></div>
	<div id="funccodecontent"></div>
</div>

<div id="stats" class="stats">
	<table class="textcolor" width="100%">
		<tr>
			<th align="left" style="font-size:22px;padding-left:10px">Result</th>
			<th align="right"><input class="button" type="button" value="x" onClick="document.getElementById('stats').style.display='none';" title="close" /></th>
		</tr>
	</table>	
	<hr />	
	<table class="textcolor" width="100%">	
<?php 
	// output stats
	if(empty($_POST['search']))
	{
		$count_all=$count_xss+$count_sqli+$count_fr+$count_fa+$count_fi+$count_exec+$count_code+$count_eval+$count_xpath+$count_ldap+$count_con+$count_other+$count_pop+$count_header+$count_sf+$count_ri;
		if($count_all > 0)
		{
			if($count_code > 0)
				statsRow(1, $NAME_CODE, $count_code, $count_all);
			if($count_exec > 0)	
				statsRow(2, $NAME_EXEC, $count_exec, $count_all);
			if($count_con > 0)	
				statsRow(3, $NAME_CONNECT, $count_con, $count_all);
			if($count_fr > 0)	
				statsRow(4, $NAME_FILE_READ, $count_fr, $count_all);
			if($count_fi > 0)	
				statsRow(5, $NAME_FILE_INCLUDE, $count_fi, $count_all);
			if($count_fa > 0)	
				statsRow(6, $NAME_FILE_AFFECT, $count_fa, $count_all);
			if($count_ldap > 0)	
				statsRow(7, $NAME_LDAP, $count_ldap, $count_all);
			if($count_sqli > 0)	
				statsRow(8, $NAME_DATABASE, $count_sqli, $count_all);
			if($count_xpath > 0)	
				statsRow(9, $NAME_XPATH, $count_xpath, $count_all);
			if($count_xss > 0)	
				statsRow(10, $NAME_XSS, $count_xss, $count_all);
			if($count_header > 0)	
				statsRow(11, $NAME_HTTP_HEADER, $count_header, $count_all);	
			if($count_sf > 0)	
				statsRow(12, $NAME_SESSION_FIXATION, $count_sf, $count_all);	
			if($count_other > 0)	
				statsRow(13, $NAME_OTHER, $count_other, $count_all);
			if($count_ri > 0)	
				statsRow(14, $NAME_REFLECTION, $count_ri, $count_all);
			if($count_pop > 0)	
				statsRow(15, $NAME_POP, $count_pop, $count_all);	
			echo '<tr><td nowrap width="160" onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';" onClick="showAllCats()" style="cursor:pointer;" title="show all categories">Sum:</td><td>',$count_all,'</td></tr>';
		} else
		{
			echo '<tr><td colspan="2" width="160">No vulnerabilities found.</td></tr>';
		}
	} else
	{
		echo '<tr><td colspan="2">',(($count_matches == 0) ? 'No' : $count_matches),' matches found.</td></tr>';
	}

	echo '</table><hr /><table class="textcolor" width="100%">',
		'<tr><td nowrap width="160" onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';" onClick="openWindow(5);eval(document.getElementById(\'filegraph_code\').innerHTML);maxWindow(5, 650);" style="cursor:pointer;" title="open files window">Scanned files:</td><td nowrap colspan="2">',count($files),'</td></tr>';
	if(empty($_POST['search']))
	{
		echo '<tr><td nowrap width="160">Include success:</td><td nowrap colspan="2">';
	
		if($count_inc > 0)
		{
			echo ($count_inc_success=$count_inc-$count_inc_fail).'/'.$count_inc, 
			' ('.$round_inc_success=round(($count_inc_success/$count_inc)*100,0).'%)'; 
		} else
		{
			echo 'No includes.';
		}
		
		echo '</td></tr>',
		'<tr><td nowrap>Considered sinks:</td><td nowrap>',count($scan_functions),'</td><td rowspan="4" >';
		if(empty($_POST['search']) && $count_all > 0)
		{
			echo '<div class="diagram"><canvas id="diagram" width="80" height="70"></canvas></div>';
		}
		echo '</td></tr>',
		'<tr><td nowrap onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';" onClick="openWindow(3);eval(document.getElementById(\'functiongraph_code\').innerHTML);maxWindow(3, 650);" style="cursor:pointer;" title="open functions window">User-defined functions:</td><td nowrap>'.(count($user_functions_offset)-(count($user_functions_offset)>0?1:0)).'</td></tr>',
		'<tr><td nowrap onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';" onClick="openWindow(4);" style="cursor:pointer;" title="open userinput window">Unique sources:</td><td nowrap>'.count($user_input).'</td></tr>',
		'<tr><td nowrap>Sensitive sinks:</td><td nowrap>'.(is_array($file_sinks_count) ? array_sum($file_sinks_count) : 0).'</td></tr>',
		'</table><hr />';
		
		// output info gathering
		if( !empty($info) || ($count_inc>0 && $round_inc_success < 75 && !$scan_subdirs && count($files)>1) )
		{
			$info = array_unique($info);
			echo '<table class="textcolor" width="100%">';
			foreach($info as $detail)
			{
				echo '<tr><td width="160">Info:</td><td><small>',$detail,'</small></td></tr>';
			}	
			if($count_inc>0 && $round_inc_success < 75 && !$scan_subdirs && count($files)>1)
			{
				echo '<tr><td width="160">Info:</td><td><small><font color="orange">Your include success is low. Enable <i>subdirs</i> for better filename guesses.</font></small></td></tr>';
			}
			echo '</table><hr />';
		}
		
		echo '<center><a href="https://www.ripstech.com/latest/" target="_blank" style="text-decoration:none;font-size:11pt" onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';">Get the next generation of <font color="#FC4">RIPS</font><br />with state-of-the-art code analysis!</a></center><hr />';
	}	
		?>
		<table class="textcolor" width="100%">
		<tr><td nowrap width="160">Scan time:</td><td nowrap><span id="scantime"><?php printf("%.03f seconds", $elapsed); ?></span></td></tr>
	</table>		

</div>

<?php 
	// scan result
	@printoutput($output, $_POST['treestyle']); 
?>