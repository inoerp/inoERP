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

	include('../config/general.php');		// general settings
	include('../config/sources.php');		// tainted variables and functions
	include('../config/tokens.php');		// tokens for lexical analysis
	include('../config/securing.php');		// securing functions
	include('../config/sinks.php');			// sensitive sinks
	include('../config/info.php');			// interesting functions
	
	include('../lib/constructer.php'); 		// classes	
	include('../lib/filer.php');			// read files from dirs and subdirs
	include('../lib/tokenizer.php');		// prepare and fix token list
	include('../lib/analyzer.php');			// string analyzers
	include('../lib/scanner.php');			// scan for sinks in token list
	include('../lib/printer.php');			// output scan result
	include('../lib/searcher.php');			// search functions
		
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
			$user_functions = array();
			$user_functions_offset = array();
			$file_sinks_count = array();
			$user_input = array();
			
			$count_xss=$count_sqli=$count_fr=$count_fa=$count_fi=$count_exec=$count_code=$count_eval=$count_xpath=$count_ldap=$count_con=$count_other=$count_pop=$count_inc=$count_inc_fail=$count_header=0;
			
			$verbosity = 3;

			$scan_functions = array_merge($F_XSS, $F_HTTP_HEADER, $F_SESSION_FIXATION);
			$F_USERINPUT = array();
			$V_USERINPUT = array($_POST['varname']);
			$F_SECURING_XSS = array();
			$_POST['vector'] = 'client';
			
			$overall_time = 0;
			$timeleft = 0;
			$file_amount = count($files);

			for($fit=0; $fit<$file_amount; $fit++)
			{
				// for scanning display
				$thisfile_start = microtime(TRUE);
				$file_scanning = $files[$fit];
				
				echo ($fit) . '|' . $file_amount . '|' . $file_scanning . '|' . $timeleft . '|' ."\n";
				@ob_flush();
				flush();
				
				$scan = new Scanner($file_scanning, $scan_functions, array(), array());
				$scan->parse();
				
				$overall_time += microtime(TRUE) - $thisfile_start;
				// timeleft = average_time_per_file * file_amount_left
				$timeleft = round(($overall_time/($fit+1)) * ($file_amount - $fit+1),2);
			}
			echo "STATS_DONE.\n";
			@ob_flush();
			flush();
	} 
	
	$elapsed = microtime(TRUE) - $start;

	################################  RESULT  #################################	

	$treestyle = $_POST['treestyle'];
	
	function checkLeak($tree, $line, $varname)
	{
		if($tree->children)
		{
			foreach ($tree->children as $child) 
			{
				// really dirty :(
				if(preg_match("/$line:.*markVariable\('$varname/", $child->value))
					return true;
				return checkLeak($child, $line, $varname);
			}
		}
		return false;
	}
	
	// check for line leaks found in vulnblock
	function lineLeakes($line, $var, $block)
	{
		foreach($block->treenodes as $tree)
		{
			if(checkLeak($tree, $line, $var))
				return true;
		}
		return false;
	}	
	
		if(!empty($output))
		{
			$nr=0;
			reset($output);
			do
			{			
				if(key($output) != "" && !empty($output[key($output)]) )
				{		
					foreach($output[key($output)] as $vulnBlock)
					{	
						if(lineLeakes($_POST['line'], str_replace('$','',$_POST['varname']), $vulnBlock))	
						{
							$nr++;
							echo '<div style="margin-left:10px;margin-top:10px"><div class="vulnblock">',
							'<div id="picleak',$nr,'" class="minusico" name="picleak" style="margin-top:5px" title="minimize"',
							' onClick="hide(\'leak',$nr,'\')"></div><div class="vulnblocktitle">Data Leak</div>',
							'</div><div name="allcats"><div class="vulnblock" style="border-top:0px;" name="leak" id="leak',$nr,'">';
							
							if($treestyle == 2)
								krsort($vulnBlock->treenodes);
							
							foreach($vulnBlock->treenodes as $tree)
							{
								echo '<div class="codebox"><table border=0>',"\n",
								'<tr><td valign="top" nowrap>',"\n",
								'<div class="fileico" title="review code" ',
								'onClick="openCodeViewer(this,\'',
								addslashes($tree->filename), '\',\'',
								implode(',', $tree->lines), '\');"></div>'."\n",
								'<div id="pic',key($output),$tree->lines[0],'" class="minusico" title="minimize"',
								' onClick="hide(\'',addslashes(key($output)),$tree->lines[0],'\')"></div><br />',"\n";
								
								echo '</td><td><span class="vulntitle">The return value of the sensitive sink is embedded into the HTML output.</span>',
								'<div class="code" id="',key($output),$tree->lines[0],'">',"\n";

								if($treestyle == 1)
									traverseBottomUp($tree);
								else if($treestyle == 2)
									traverseTopDown($tree);

									echo '<ul><li>',"\n";
								dependenciesTraverse($tree);
								echo '</li></ul>',"\n",	'</div>',"\n", '</td></tr></table></div>',"\n";
							}	
							echo '</div></div><div style="height:20px"></div></div>',"\n";
						}	
					}

				}	
			}
			while(next($output));
		}
?>