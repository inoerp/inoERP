<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/	
	
	// add parsing error to output
	function addError($message, $tokens, $line_nr, $filename)
	{
		$GLOBALS['info'][] = '<font color="red">Parsing error occured. Use verbosity level=debug for details.</font>';
		if($GLOBALS['verbosity'] == 5)
		{
			$value = highlightline($tokens, '', $line_nr);
			$new_find = new InfoTreeNode($value);
			$new_find->title = 'Parse error: '.$message;
			$new_find->lines[] = $line_nr;
			$new_find->filename = $filename;
								
			$new_block = new VulnBlock('error', 'Debug');
			$new_block->treenodes[] = $new_find;
			$new_block->vuln = true;
			$GLOBALS['output'][$filename]['error'] = $new_block;
		}	
	}
	
	// tokens to string for comments
	function tokenstostring($tokens)
	{
		$output = '';
		for($i=0;$i<count($tokens);$i++)
		{
			$token = $tokens[$i];
			if (is_string($token))
			{	
				if($token === ',' || $token === ';')
					$output .= "$token ";
				else if(in_array($token, Tokens::$S_SPACE_WRAP) || in_array($token, Tokens::$S_ARITHMETIC))
					$output .= " $token ";
				else	
					$output .= $token;
			}	
			else if(in_array($token[0], Tokens::$T_SPACE_WRAP) || in_array($token[0], Tokens::$T_OPERATOR) || in_array($token[0], Tokens::$T_ASSIGNMENT))
				$output .= " {$token[1]} ";
			else
				$output .= $token[1];
		}
		return $output;
	}
	
	// prepare output to style with CSS
	function highlightline($tokens=array(), $comment='', $line_nr, $title=false, $udftitle=false, $tainted_vars=array())
	{
		$reference = true;
		$output = "<span class=\"linenr\">$line_nr:</span>&nbsp;";
		if($title)
		{
			$output.='<a class="link" href="'.PHPDOC.$title.'" title="open php documentation" target=_blank>';
			$output.="$title</a>&nbsp;";
		} 
		else if($udftitle)
		{
			$output.='<a class="link" style="text-decoration:none;" href="#'.$udftitle.'_declare" title="jump to declaration">&uArr;</a>&nbsp;';
		}
		
		$var_count = 0;
		
		for($i=0;$i<count($tokens);$i++)
		{
			$token = $tokens[$i];
			if (is_string($token))
			{		
				if($token === ',' || $token === ';')
					$output .= "<span class=\"phps-code\">$token&nbsp;</span>";
				else if(in_array($token, Tokens::$S_SPACE_WRAP) || in_array($token, Tokens::$S_ARITHMETIC))
					$output .= '<span class="phps-code">&nbsp;'.$token.'&nbsp;</span>';
				else
					$output .= '<span class="phps-code">'.htmlentities($token, ENT_QUOTES, 'utf-8').'</span>';
					
			} 
			else if (is_array($token) 
			&& $token[0] !== T_OPEN_TAG
			&& $token[0] !== T_CLOSE_TAG) 
			{
				
				if(in_array($token[0], Tokens::$T_SPACE_WRAP) || in_array($token[0], Tokens::$T_OPERATOR) || in_array($token[0], Tokens::$T_ASSIGNMENT))
				{
					$output.= '&nbsp;<span class="phps-'.str_replace('_', '-', strtolower(token_name($token[0])))."\">{$token[1]}</span>&nbsp;";
				}	
				else
				{
					if($token[0] === T_FUNCTION)
					{
						$reference = false;
						$funcname = $tokens[$i+1][0] === T_STRING ? $tokens[$i+1][1] : $tokens[$i+2][1];
						$output .= '<A NAME="'.$funcname.'_declare" class="jumplink"></A>';
						$output .= '<a class="link" style="text-decoration:none;" href="#'.$funcname.'_call" title="jump to call">&dArr;</a>&nbsp;';
					}	
					
					$text = htmlentities($token[1], ENT_QUOTES, 'utf-8');
					$text = str_replace(array(' ', "\n"), '&nbsp;', $text);

					if($token[0] === T_FUNCTION)
						$text.='&nbsp;';
						
					if($token[0] === T_STRING && $reference 
					&& isset($GLOBALS['user_functions_offset'][strtolower($text)]))
					{				
						$text = @'<span onmouseover="getFuncCode(this,\''.addslashes($GLOBALS['user_functions_offset'][strtolower($text)][0]).'\',\''.$GLOBALS['user_functions_offset'][strtolower($text)][1].'\',\''.$GLOBALS['user_functions_offset'][strtolower($text)][2].'\')" style="text-decoration:underline" class="phps-'.str_replace('_', '-', strtolower(token_name($token[0])))."\">$text</span>\n";
					}	
					else 
					{
						$span = '<span ';
					
						if($token[0] === T_VARIABLE)
						{
							$var_count++;
							$cssname = str_replace('$', '', $token[1]);
							$span.= 'style="cursor:pointer;" name="phps-var-'.$cssname.'" onClick="markVariable(\''.$cssname.'\')" ';
							$span.= 'onmouseover="markVariable(\''.$cssname.'\')" onmouseout="markVariable(\''.$cssname.'\')" ';
						}	
						
						if($token[0] === T_VARIABLE && @in_array($var_count, $tainted_vars))
							$span.= "class=\"phps-tainted-var\">$text</span>";	
						else
							$span.= 'class="phps-'.str_replace('_', '-', strtolower(token_name($token[0])))."\">$text</span>";
							
						$text = $span;	
						
						// rebuild array keys
						if(isset($token[3]))
						{
							foreach($token[3] as $key)
							{
								if($key != '*')
								{
									$text .= '<span class="phps-code">[</span>';
									if(!is_array($key))
									{
										if(is_numeric($key))
											$text .= '<span class="phps-t-lnumber">' . $key . '</span>';
										else
											$text .= '<span class="phps-t-constant-encapsed-string">\'' . htmlentities($key, ENT_QUOTES, 'utf-8') . '\'</span>';
									} else
									{
										foreach($key as $token)
										{
											if(is_array($token))
											{
												$text .= '<span ';
												
												if($token[0] === T_VARIABLE)
												{
													$cssname = str_replace('$', '', $token[1]);
													$text.= 'style="cursor:pointer;" name="phps-var-'.$cssname.'" onClick="markVariable(\''.$cssname.'\')" ';
													$text.= 'onmouseover="markVariable(\''.$cssname.'\')" onmouseout="markVariable(\''.$cssname.'\')" ';
												}	
												
												$text .= 'class="phps-'.str_replace('_', '-', strtolower(token_name($token[0]))).'">'.htmlentities($token[1], ENT_QUOTES, 'utf-8').'</span>';
											}	
											else
												$text .= "<span class=\"phps-code\">{$token}</span>";
										}
									}
									$text .= '<span class="phps-code">]</span>';
								}
							}
						}
					}
					$output .= $text;
					if(is_array($token) && (in_array($token[0], Tokens::$T_INCLUDES) || in_array($token[0], Tokens::$T_XSS) || $token[0] === 'T_EVAL'))
						$output .= '&nbsp;';
				}		
			}
		}
		
		if(!empty($comment))
			$output .= '&nbsp;<span class="phps-t-comment">// '.htmlentities($comment, ENT_QUOTES, 'utf-8').'</span>';

		return $output;
	}
	
	// detect vulnerability type given by the PVF name
	// note: same names are used in help.php!
	function getVulnNodeTitle($func_name)
	{
		if(isset($GLOBALS['F_XSS'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_XSS'];  }
		else if(isset($GLOBALS['F_HTTP_HEADER'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_HTTP_HEADER'];  }	
		else if(isset($GLOBALS['F_SESSION_FIXATION'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_SESSION_FIXATION'];  }
		else if(isset($GLOBALS['F_DATABASE'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_DATABASE'];  }	
		else if(isset($GLOBALS['F_FILE_READ'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_FILE_READ'];  }
		else if(isset($GLOBALS['F_FILE_AFFECT'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_FILE_AFFECT']; }		
		else if(isset($GLOBALS['F_FILE_INCLUDE'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_FILE_INCLUDE'];  }	
		else if(isset($GLOBALS['F_CONNECT'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_CONNECT']; }		
		else if(isset($GLOBALS['F_EXEC'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_EXEC'];  }
		else if(isset($GLOBALS['F_CODE'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_CODE']; }
		else if(isset($GLOBALS['F_REFLECTION'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_REFLECTION']; }
		else if(isset($GLOBALS['F_XPATH'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_XPATH'];	 } 
		else if(isset($GLOBALS['F_LDAP'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_LDAP'];}
		else if(isset($GLOBALS['F_POP'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_POP'];  }
		else if(isset($GLOBALS['F_OTHER'][$func_name])) 
		{	$vulnname = $GLOBALS['NAME_OTHER']; } // :X			 			
		else 
			$vulnname = "unknown";
		return $vulnname;	
	}
	
	// detect vulnerability type given by the PVF name
	// note: same names are used in help.php!
	function increaseVulnCounter($func_name)
	{
		if(isset($GLOBALS['F_XSS'][$func_name])) 
		{	$GLOBALS['count_xss']++; }	
		else if(isset($GLOBALS['F_HTTP_HEADER'][$func_name])) 
		{	$GLOBALS['count_header']++; }
		else if(isset($GLOBALS['F_SESSION_FIXATION'][$func_name])) 
		{	$GLOBALS['count_sf']++; }
		else if(isset($GLOBALS['F_DATABASE'][$func_name])) 
		{	$GLOBALS['count_sqli']++; }	
		else if(isset($GLOBALS['F_FILE_READ'][$func_name])) 
		{	$GLOBALS['count_fr']++; }
		else if(isset($GLOBALS['F_FILE_AFFECT'][$func_name])) 
		{	$GLOBALS['count_fa']++; }		
		else if(isset($GLOBALS['F_FILE_INCLUDE'][$func_name])) 
		{	$GLOBALS['count_fi']++; }	
		else if(isset($GLOBALS['F_CONNECT'][$func_name])) 
		{	$GLOBALS['count_con']++; }
		else if(isset($GLOBALS['F_EXEC'][$func_name])) 
		{	$GLOBALS['count_exec']++; }
		else if(isset($GLOBALS['F_CODE'][$func_name])) 
		{	$GLOBALS['count_code']++; }
		else if(isset($GLOBALS['F_REFLECTION'][$func_name])) 
		{	$GLOBALS['count_ri']++; }
		else if(isset($GLOBALS['F_XPATH'][$func_name])) 
		{	$GLOBALS['count_xpath']++; } 
		else if(isset($GLOBALS['F_LDAP'][$func_name])) 
		{	$GLOBALS['count_ldap']++; }	
		else if(isset($GLOBALS['F_POP'][$func_name])) 
		{	$GLOBALS['count_pop']++; }
		else if(isset($GLOBALS['F_OTHER'][$func_name])) 
		{	$GLOBALS['count_other']++; } // :X
	}	
		
	// traced parameter output bottom-up
	function traverseBottomUp($tree) 
	{
		echo '<ul';
		switch($tree->marker) 
		{
			case 1: echo ' class="userinput"'; break;
			case 2: echo ' class="validated"'; break;
			case 3: echo ' class="functioninput"'; break;
			case 4: echo ' class="persistent"'; break;
		}
		echo '><li>' . $tree->value;

		if($tree->children)
		{
			foreach ($tree->children as $child) 
			{
				traverseBottomUp($child);
			}
		}
		echo '</li></ul>',"\n";
	}
	
	// traced parameter output top-down
	function traverseTopDown($tree, $start=true, $lines=array()) 
	{
		if($start) echo '<ul>';
	
		foreach ($tree->children as $child) 
		{
			$lines = traverseTopDown($child, false, $lines);
		}
		
		// do not display a line twice
		// problem: different lines in different files with equal line number
		if(!isset($lines[$tree->line]))
		{
			echo '<li';
			switch($tree->marker) 
			{
				case 1: echo ' class="userinput"'; break;
				case 2: echo ' class="validated"'; break;
				case 3: echo ' class="functioninput"'; break;
				case 4: echo ' class="persistent"'; break;
			}
			echo '>',$tree->value,'</li>',"\n";
			// add to array to ignore next time
			$lines[$tree->line] = 1;
		}	
			
		if($start) echo '</ul>';
		
		return $lines;
	}	

	// requirements output
	function dependenciesTraverse($tree) 
	{
		if(!empty($tree->dependencies))
		{
			echo '<ul><li><span class="requires">requires:</span>';

			foreach ($tree->dependencies as $linenr=>$dependency) 
			{
				if(!empty($dependency))
				{
					echo '<ul><li>'.highlightline($dependency, '', $linenr).'</li></ul>';
				}
			}

			echo '</li></ul>',"\n";
		}
	}
	
	// check for vulns found in file
	function fileHasVulns($blocks)
	{
		foreach($blocks as $block)
		{
			if($block->vuln)
				return true;
		}
		return false;
	}	
	
	// print the scanresult
	function printoutput($output, $treestyle=1)
	{
		if(!empty($output))
		{
			$nr=0;
			reset($output);
			do
			{				
				if(key($output) != "" && !empty($output[key($output)]) && fileHasVulns($output[key($output)]))
				{		
					echo '<div class="filebox">',
					'<span class="filename">File: ',key($output),'</span><br>',
					'<div id="',key($output),'"><br>';
	
					foreach($output[key($output)] as $vulnBlock)
					{	
						if($vulnBlock->vuln)	
						{
							$nr++;
							echo '<div class="vulnblock">',
							'<div id="pic',$vulnBlock->category,$nr,'" class="minusico" name="pic',$vulnBlock->category,'" style="margin-top:5px" title="minimize"',
							' onClick="hide(\'',$vulnBlock->category,$nr,'\')"></div><div class="vulnblocktitle">',$vulnBlock->category,'</div>',
							'</div><div name="allcats"><div class="vulnblock" style="border-top:0px" name="',$vulnBlock->category,'" id="',$vulnBlock->category,$nr,'">';
							
							if($treestyle == 2)
								krsort($vulnBlock->treenodes);
							
							foreach($vulnBlock->treenodes as $tree)
							{
								// we do not have a prescan yet so RIPS misses function calls before the actual declaration, so we output vulns in functions without function call too (could have happened earlier)
								// if(empty($tree->funcdepend) || $tree->foundcallee )
								{	
									echo '<div class="codebox"><table border=0>',"\n",
									'<tr><td valign="top" nowrap>',"\n",
									'<div class="fileico" title="review code" ',
									'onClick="openCodeViewer(this,\'',
									addslashes($tree->filename), '\',\'',
									implode(',', $tree->lines), '\');"></div>'."\n",
									'<div id="pic',key($output),$tree->lines[0],'" class="minusico" title="minimize"',
									' onClick="hide(\'',addslashes(key($output)),$tree->lines[0],'\')"></div><br />',"\n";

									if(isset($GLOBALS['scan_functions'][$tree->name]))
									{
										// help button
										echo '<div class="help" title="get help" onClick="openHelp(this,\'',
										$vulnBlock->category,'\',\'',$tree->name,'\',\'',
										(int)!empty($tree->get),'\',\'',
										(int)!empty($tree->post),'\',\'',
										(int)!empty($tree->cookie),'\',\'',
										(int)!empty($tree->files),'\',\'',
										(int)!empty($tree->cookie),'\')"></div>',"\n";
										
										if(isset($GLOBALS['F_DATABASE'][$tree->name])
										|| isset($GLOBALS['F_FILE_AFFECT'][$tree->name]) 
										|| isset($GLOBALS['F_FILE_READ'][$tree->name]) 
										|| isset($GLOBALS['F_LDAP'][$tree->name])
										|| isset($GLOBALS['F_XPATH'][$tree->name])
										|| isset($GLOBALS['F_POP'][$tree->name]) )
										{
											// data leak scan
											if(!empty($vulnBlock->dataleakvar))
											{
												echo '<div class="dataleak" title="check data leak" onClick="leakScan(this,\'',
												$vulnBlock->dataleakvar[1],'\',\'', // varname
												$vulnBlock->dataleakvar[0],'\', false)"></div>',"\n"; // line
											} else
											{
												$tree->title .= ' (Blind exploitation)';
											}
										}	
									}
									
									if(!empty($tree->get) || !empty($tree->post) 
									|| !empty($tree->cookie) || !empty($tree->files)
									|| !empty($tree->server) )
									{
										/*echo '<div class="hotpatch" title="hotpatch" ',
										'onClick="openHotpatch(this, \'',
										addslashes($tree->filename),
										'\',\'',implode(',',array_unique($tree->get)),
										'\',\'',implode(',',array_unique($tree->post)),
										'\',\'',implode(',',array_unique($tree->cookie)),
										'\',\'',implode(',',array_unique($tree->files)),
										'\',\'',implode(',',array_unique($tree->server)),'\');"></div>',"\n",*/
										
										echo '<div class="exploit" title="generate exploit" ',
										'onClick="openExploitCreator(this, \'',
										addslashes($tree->filename),
										'\',\'',implode(',',array_unique($tree->get)),
										'\',\'',implode(',',array_unique($tree->post)),
										'\',\'',implode(',',array_unique($tree->cookie)),
										'\',\'',implode(',',array_unique($tree->files)),
										'\',\'',implode(',',array_unique($tree->server)),'\');"></div>';
									}
									// $tree->title
									echo '</td><td><span class="vulntitle">',$tree->title,'</span>',
									'<div class="code" id="',key($output),$tree->lines[0],'">',"\n";

									if($treestyle == 1)
										traverseBottomUp($tree);
									else if($treestyle == 2)
										traverseTopDown($tree);

										echo '<ul><li>',"\n";
									dependenciesTraverse($tree);
									echo '</li></ul>',"\n",	'</div>',"\n", '</td></tr></table></div>',"\n";
								}
							}	
							
							if(!empty($vulnBlock->alternatives))
							{
								echo '<div class="codebox"><table><tr><td><ul><li><span class="vulntitle">Vulnerability is also triggered in:</span>';
								foreach($vulnBlock->alternatives as $alternative)
								{
									echo '<ul><li>'.$alternative.'</li></ul>';
								}
								echo '</li></ul></td></table></div>';
							}
							
							echo '</div></div><div style="height:20px"></div>',"\n";
						}	
					}

					echo '</div><div class="buttonbox">',"\n",
					'<input type="submit" class="Button" value="hide all" ',
					'onClick="hide(\'',addslashes(key($output)),'\')">',"\n",
					'</div></div><hr>',"\n";
				}	
				else if(count($output) == 1)
				{
					echo '<div style="margin-left:30px;color:#000000">Nothing vulnerable found. Change the verbosity level or vulnerability type  and try again.</div>';
				}
			}
			while(next($output));
		}
		else if(count($GLOBALS['scanned_files']) > 0)
		{
			echo '<div style="margin-left:30px;color:#000000">Nothing vulnerable found. Change the verbosity level or vulnerability type and try again.</div>';
		}
		else
		{
			echo '<div style="margin-left:30px;color:#000000">Nothing to scan. Please check your path/file name.</div>';
		}
		
	}
	
	// build list of available functions
	function createFunctionList($user_functions_offset)
	{
		if(!empty($user_functions_offset))
		{
			ksort($user_functions_offset);
			if($GLOBALS['file_amount'] <= WARNFILES)
				$js = 'graph2 = new Graph(document.getElementById("functioncanvas"));'."\n";
			else
				$js = 'canvas = document.getElementById("functioncanvas");ctx = canvas.getContext("2d");ctx.fillStyle="#ff0000";ctx.fillText("Graphs have been disabled for a high file amount (>'.WARNFILES.').", 20, 30);';
			$x=20;
			$y=50;
			$i=0;
			
			if($GLOBALS['file_amount'] <= WARNFILES)
			{
				// create JS graph elements
				foreach($user_functions_offset as $func_name => $info)
				{				
					if($func_name !== '__main__')
					{
						$x = ($i%4==0) ? $x=20 : $x=$x+160;
						$y = ($i%4==0) ? $y=$y+70 : $y=$y;
						$i++;
						
						$func_varname = str_replace('::', '', $func_name);
						
						$js.= "var e$func_varname = graph2.addElement(pageTemplate, { x:$x, y:$y }, '".addslashes($func_name)."( )', '', '".(isset($info[5]) ? $info[5] : 0)."', '".(isset($info[6]) ? $info[6] : 0)."', 0);\n";
					} else
					{	
						$js.='var e__main__ = graph2.addElement(pageTemplate, { x:260, y:20 }, "__main__", "", "'.(isset($info[5]) ? $info[5] : 0).'", "'.(isset($info[6]) ? $info[6] : 0).'", 0);'."\n";
					}	
				}
			}
			
			echo '<div id="functionlistdiv"><table><tr><th align="left">declaration</th><th align="left">calls</th></tr>';
			foreach($user_functions_offset as $func_name => $info)
			{
				if($func_name !== '__main__')
				echo '<tr><td><div id="fol_',$func_name,'" class="funclistline" title="',$info[0],'" ',
				'onClick="openCodeViewer(3, \'',addslashes($info[0]),'\', \'',($info[1]+1),
				',',(!empty($info[2]) ? $info[2]+1 : 0),'\')">',$func_name,'</div></td><td>';
								
				$calls = array();
				if(isset($info[3]))
				{
					foreach($info[3] as $call)
					{
						$calls[] = '<span class="funclistline" title="'.$call[0].
						'" onClick="openCodeViewer(3, \''.addslashes($call[0]).'\', \''.$call[1].'\')">'.$call[1].'</span>';
					}
				}
				echo implode(',',array_unique($calls)).'</td></tr>';
				
				if(isset($info[4]) && $GLOBALS['file_amount'] <= WARNFILES)
				{
					foreach($info[4] as $call)
					{
						if(!is_array($call))
						{
							$color = (isset($info[4][$call])) ? '#F00' : '#000';
							$js.="try{graph2.addConnection(e$call.getConnector(\"links\"), e$func_name.getConnector(\"parents\"), '$color');}catch(e){}\n";
						}	
					}
				}
			}
			if($GLOBALS['file_amount'] <= WARNFILES)
				$js.='graph2.update();';
			echo '</table></div>',"\n<div id='functiongraph_code' style='display:none'>$js</div>\n";
		} else
		{
			echo "<div id='functiongraph_code' style='display:none'>document.getElementById('windowcontent3').innerHTML='No user defined functions found.'</div>\n";
		}
	}
	
	// build list of all entry points (user input)
	function createUserinputList($user_input)
	{
		if(!empty($user_input))
		{
			ksort($user_input);
			echo '<table><tr><th align="left">type[parameter]</th><th align="left">taints</th></tr>';
			foreach($user_input as $input_name => $file)
			{
				$finds = array();
				foreach($file as $file_name => $lines)
				{
					foreach($lines as $line)
					{
						$finds[] = '<span class="funclistline" title="'.htmlentities($file_name).'" onClick="openCodeViewer(4, \''.htmlentities($file_name, ENT_QUOTES)."', '$line')\">$line</span>\n";
					}
				}
				echo "<tr><td nowrap>$input_name</td><td nowrap>",implode(',',array_unique($finds)),'</td></tr>';

			}
			echo '</table>';
		} else
		{
			echo 'No userinput found.';
		}
	}
	
	// build list of all scanned files
	function createFileList($files, $file_sinks)
	{
		if(!empty($files))
		{
			if($GLOBALS['file_amount'] <= WARNFILES)
				$js = 'graph = new Graph(document.getElementById("filecanvas"));'."\n";
			else	
				$js = 'canvas = document.getElementById("filecanvas");ctx = canvas.getContext("2d");ctx.fillStyle="#ff0000";ctx.fillText("Graphs have been disabled for a high file amount (>'.WARNFILES.').", 20, 30);';
	
			// get vuln files
			$vulnfiles = array();
			foreach($GLOBALS['output'] as $filename => $blocks)
			{		
				foreach($blocks as $block)
				{
					if($block->vuln)
					{
						$vulnfiles[] = $block->treenodes[0]->filename;
					}	
				}	
			}	

			// sort files by "include weight" (main files on top, included files bottom)
			$mainfiles = array();
			$incfiles = array();
			foreach($files as $file => $includes)
			{
				$mainfiles[] = realpath($file);
				if(!empty($includes))
				{
					foreach($includes as $include)
					{
						$incfiles[] = realpath($include);
					}
				}	
			}
			$elements = array_unique(array_merge(array_diff($mainfiles,$incfiles), array('__break__'), $incfiles));
			$x=20;
			$y=-50;
			$i=0;
			$style = 'pageTemplate';

			// add JS elements
			foreach($elements as $file)
			{
				if($file !== '__break__')
				{
					$x = ($i%4==0) ? $x=20 : $x=$x+160;
					$y = ($i%4==0) ? $y=$y+70 : $y=$y;
					$i++;
					
					// leave space for legend symbols
					if($i==3)
						$i++;
					
					$file = realpath($file);

					$filename = is_dir($_POST['loc']) ? str_replace(realpath($_POST['loc']), '', $file) : str_replace(realpath(str_replace(basename($_POST['loc']),'', $_POST['loc'])),'',$file);
					$varname = preg_replace('/[^A-Za-z0-9]/', '', $filename); 

					$userinput = 0;
					foreach($GLOBALS['user_input'] as $inputname)
					{
						if(isset($inputname[$file]))
							$userinput++;
					}			
					
					if($GLOBALS['file_amount'] <= WARNFILES)
						$js.= "var e$varname = graph.addElement($style, { x:$x, y:$y }, '".htmlentities($filename, ENT_QUOTES)."', '', '".$userinput."', '".htmlentities($file_sinks[$file], ENT_QUOTES)."', ".(in_array($file, $vulnfiles) ? 1 : 0).");\n";

				} else
				{
					// add to $i what is missing til new row is created
					$i=$i+(4-($i%4));
					$y+=30;
					$style = 'scriptTemplate';
				}
			}	
			
			// build file list and add connection to includes
			echo '<div id="filelistdiv"><table>';
			foreach($files as $file => $includes)
			{				
				$file = realpath($file);

				$filename = is_dir($_POST['loc']) ? str_replace(realpath($_POST['loc']), '', $file) : str_replace(realpath(str_replace(basename($_POST['loc']),'', $_POST['loc'])),'',$file);
				$varname = preg_replace('/[^A-Za-z0-9]/', '', $filename); 

				if(empty($includes))
				{
					echo '<tr><td><div class="funclistline" title="',htmlentities($file),'" ',
					'onClick="openCodeViewer(3, \'',htmlentities($file, ENT_QUOTES),'\', \'0\')">',htmlentities($filename),'</div></td></tr>',"\n";
				}	
				else
				{
					$parent = $varname;
					echo '<tr><td><div class="funclistline" title="',htmlentities($file),'" ',
					'onClick="openCodeViewer(3, \'',htmlentities($file, ENT_QUOTES),'\', \'0\')">',htmlentities($filename),'</div><ul style="margin-top:0px;">',"\n";
					foreach($includes as $include)
					{
						$include = realpath($include);
	
						$includename = is_dir($_POST['loc']) ? str_replace(realpath($_POST['loc']), '', $include) : str_replace(realpath(str_replace(basename($_POST['loc']),'', $_POST['loc'])),'',$include);
						$incvarname = preg_replace('/[^A-Za-z0-9]/', '', $includename); 
	
						echo '<li><div class="funclistline" title="',htmlentities($include),'" ',
						'onClick="openCodeViewer(3, \'',htmlentities($include, ENT_QUOTES),'\', \'0\')">',htmlentities($includename),'</div></li>',"\n";
						
						if($GLOBALS['file_amount'] <= WARNFILES)
							$js.="try{graph.addConnection(e$incvarname.getConnector(\"links\"), e$parent.getConnector(\"parents\"), '#000');}catch(e){}\n";
					}
					echo '</ul></td></tr>',"\n";
				}	

			}
			if($GLOBALS['file_amount'] <= WARNFILES)
				$js.='graph.update();';
			echo '</table></div>',"\n<div id='filegraph_code' style='display:none'>$js</div>\n";
		}
	}
	
	function statsRow($nr, $name, $amount, $all)
	{
		echo '<tr><td nowrap onmouseover="this.style.color=\'white\';" onmouseout="this.style.color=\'#DFDFDF\';" onClick="catshow(\'',$name,'\')" style="cursor:pointer;" title="show only vulnerabilities of this category">',$name,':</td><td nowrap><div id="chart'.$nr.'" class="chart" style="width:',
			round(($amount/$all)*100,0),'"></div><div id="vuln'.$nr.'">',$amount,'</div></td></tr>';
	}
	
?>	