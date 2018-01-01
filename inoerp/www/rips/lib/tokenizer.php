<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.

**/

class Tokenizer
{	
	public $filename;
	public $tokens;

	function __construct($filename)
	{
		$this->filename = $filename;
	}

	// main
	public function tokenize($code)
	{
		$this->tokens = token_get_all($code);			
		$this->prepare_tokens();
		$this->array_reconstruct_tokens();
		$this->fix_tokens();	
		$this->fix_ternary();
		#die(print_r($this->tokens));
		return $this->tokens;
	}
	
	// adds braces around offsets
	function wrapbraces($start, $between, $end)
	{
		$this->tokens = array_merge(
			array_slice($this->tokens, 0, $start), array('{'), 
			array_slice($this->tokens, $start, $between), array('}'),
			array_slice($this->tokens, $end)
		);	
	}

	// delete all tokens to ignore while scanning, mostly whitespaces	
	function prepare_tokens()
	{	
		// delete whitespaces and other unimportant tokens, rewrite some special tokens
		for($i=0, $max=count($this->tokens); $i<$max; $i++)
		{
			if( is_array($this->tokens[$i]) ) 
			{
				if( in_array($this->tokens[$i][0], Tokens::$T_IGNORE) )
					unset($this->tokens[$i]);
				else if( $this->tokens[$i][0] === T_CLOSE_TAG )
					$this->tokens[$i] = ';';	
				else if( $this->tokens[$i][0] === T_OPEN_TAG_WITH_ECHO )
					$this->tokens[$i][1] = 'echo';
			} 
			// @ (depress errors) disturbs connected token handling
			else if($this->tokens[$i] === '@') 
			{
				unset($this->tokens[$i]);
			}	
			// rewrite $array{index} to $array[index]
			else if( $this->tokens[$i] === '{'
			&& isset($this->tokens[$i-1]) && ((is_array($this->tokens[$i-1]) && $this->tokens[$i-1][0] === T_VARIABLE)
			|| $this->tokens[$i-1] === ']') )
			{
				$this->tokens[$i] = '[';
				$f=1;
				while($this->tokens[$i+$f] !== '}')
				{
					$f++;
					if(!isset($this->tokens[$i+$f]))
					{
						addError('Could not find closing brace of '.$this->tokens[$i-1][1].'{}.', array_slice($this->tokens, $i-1, 2), $this->tokens[$i-1][2], $this->filename);
						break;	
					}
				}
				$this->tokens[$i+$f] = ']';
			}	
		}
		
		// rearranged key index of tokens
		$this->tokens = array_values($this->tokens);
	}	
		
	// some tokenchains need to be fixed to scan correctly later	
	function fix_tokens()
	{	
		for($i=0; $i<($max=count($this->tokens)); $i++)
		{
		// convert `backticks` to backticks()
			if( $this->tokens[$i] === '`' )
			{		
				$f=1;
				while( $this->tokens[$i+$f] !== '`' )
				{	
					// get line_nr of any near token
					if( is_array($this->tokens[$i+$f]) )
						$line_nr = $this->tokens[$i+$f][2];

					$f++;
					if(!isset($this->tokens[$i+$f]) || $this->tokens[$i+$f] === ';')
					{
						addError('Could not find closing backtick `.', array_slice($this->tokens, $i, 5), $this->tokens[$i+1][2], $this->filename);
						break;	
					}
				}
				if(!empty($line_nr))
				{ 
					$this->tokens[$i+$f] = ')';
					$this->tokens[$i] = array(T_STRING, 'backticks', $line_nr);
				
					// add element backticks() to array 			
					$this->tokens = array_merge(
						array_slice($this->tokens, 0, $i+1), array('('), 
						array_slice($this->tokens, $i+1)
					);	
				}

			}
		// real token
			else if( is_array($this->tokens[$i]) )
			{	
			// rebuild if-clauses, for(), foreach(), while() without { }
				if ( ($this->tokens[$i][0] === T_IF || $this->tokens[$i][0] === T_ELSEIF || $this->tokens[$i][0] === T_FOR 
				|| $this->tokens[$i][0] === T_FOREACH || $this->tokens[$i][0] === T_WHILE) && $this->tokens[$i+1] === '(' )
				{		
					// skip condition in ( )
					$f=2;
					$braceopen = 1;
					while($braceopen !== 0 ) 
					{
						if($this->tokens[$i+$f] === '(')
							$braceopen++;
						else if($this->tokens[$i+$f] === ')')
							$braceopen--;
						$f++;

						if(!isset($this->tokens[$i+$f]))
						{
							addError('Could not find closing parenthesis of '.$this->tokens[$i][1].'-statement.', array_slice($this->tokens, $i, 5), $this->tokens[$i][2], $this->filename);
							break;	
						}
					}	

					// alternate syntax while(): endwhile;
					if($this->tokens[$i+$f] === ':')
					{
						switch($this->tokens[$i][0])
						{
							case T_IF:
							case T_ELSEIF: $endtoken = T_ENDIF; break;
							case T_FOR: $endtoken = T_ENDFOR; break;
							case T_FOREACH: $endtoken = T_ENDFOREACH; break;
							case T_WHILE: $endtoken = T_ENDWHILE; break;
							default: $endtoken = ';';
						}
					
						$c=1;
						while( $this->tokens[$i+$f+$c][0] !== $endtoken)
						{
							$c++;
							if(!isset($this->tokens[$i+$f+$c]))
							{
								addError('Could not find end'.$this->tokens[$i][1].'; of alternate '.$this->tokens[$i][1].'-statement.', array_slice($this->tokens, $i, $f+1), $this->tokens[$i][2], $this->filename);
								break;	
							}
						}
						$this->wrapbraces($i+$f+1, $c+1, $i+$f+$c+2);
					}
					// if body not in { (and not a do ... while();) wrap next instruction in braces
					else if($this->tokens[$i+$f] !== '{' && $this->tokens[$i+$f] !== ';')
					{
						$c=1;
						while($this->tokens[$i+$f+$c] !== ';' && $c<$max)
						{
							$c++;
						}
						$this->wrapbraces($i+$f, $c+1, $i+$f+$c+1);
					}
				} 
			// rebuild else without { }	
				else if( $this->tokens[$i][0] === T_ELSE 
				&& $this->tokens[$i+1][0] !== T_IF
				&& $this->tokens[$i+1] !== '{')
				{	
					$f=2;
					while( $this->tokens[$i+$f] !== ';' && $f<$max)
					{		
						$f++;
					}
					$this->wrapbraces($i+1, $f, $i+$f+1);
				}
			// rebuild switch (): endswitch;		
				else if( $this->tokens[$i][0] === T_SWITCH && $this->tokens[$i+1] === '(')
				{
					$newbraceopen = 1;
					$c=2;
					while( $newbraceopen !== 0 )
					{
						// watch function calls in function call
						if( $this->tokens[$i + $c] === '(' )
						{
							$newbraceopen++;
						}
						else if( $this->tokens[$i + $c] === ')' )
						{
							$newbraceopen--;
						}					
						else if(!isset($this->tokens[$i+$c]) || $this->tokens[$i + $c] === ';')
						{
							addError('Could not find closing parenthesis of switch-statement.', array_slice($this->tokens, $i, 10), $this->tokens[$i][2], $this->filename);
							break;	
						}
						$c++;
					}
					// switch(): ... endswitch;
					if($this->tokens[$i + $c] === ':')
					{
						$f=1;
						while( $this->tokens[$i+$c+$f][0] !== T_ENDSWITCH)
						{
							$f++;
							if(!isset($this->tokens[$i+$c+$f]))
							{
								addError('Could not find endswitch; of alternate switch-statement.', array_slice($this->tokens, $i, $c+1), $this->tokens[$i][2], $this->filename);
								break;	
							}
						}
						$this->wrapbraces($i+$c+1, $f+1, $i+$c+$f+2);
					}
				}
			// rebuild switch case: without { }	
				else if( $this->tokens[$i][0] === T_CASE )
				{
					$e=1;
					while($this->tokens[$i+$e] !== ':' && $this->tokens[$i+$e] !== ';')
					{
						$e++;
						
						if(!isset($this->tokens[$i+$e]))
						{
							addError('Could not find : or ; after '.$this->tokens[$i][1].'-statement.', array_slice($this->tokens, $i, 5), $this->tokens[$i][2], $this->filename);
							break;	
						}
					}
					$f=$e+1;
					if(($this->tokens[$i+$e] === ':' || $this->tokens[$i+$e] === ';')
					&& $this->tokens[$i+$f] !== '{' 
					&& $this->tokens[$i+$f][0] !== T_CASE && $this->tokens[$i+$f][0] !== T_DEFAULT)
					{
						$newbraceopen = 0;
						while($newbraceopen || (isset($this->tokens[$i+$f]) && $this->tokens[$i+$f] !== '}' 
						&& !(is_array($this->tokens[$i+$f]) 
						&& ($this->tokens[$i+$f][0] === T_BREAK || $this->tokens[$i+$f][0] === T_CASE 
						|| $this->tokens[$i+$f][0] === T_DEFAULT || $this->tokens[$i+$f][0] === T_ENDSWITCH) ) ))
						{		
							if($this->tokens[$i+$f] === '{')
								$newbraceopen++;
							else if($this->tokens[$i+$f] === '}')	
								$newbraceopen--;
							$f++;
							
							if(!isset($this->tokens[$i+$f]))
							{
								addError('Could not find ending of '.$this->tokens[$i][1].'-statement.', array_slice($this->tokens, $i, $e+5), $this->tokens[$i][2], $this->filename);
								break;	
							}
						}
						if($this->tokens[$i+$f][0] === T_BREAK)
						{
							if($this->tokens[$i+$f+1] === ';')
								$this->wrapbraces($i+$e+1, $f-$e+1, $i+$f+2);
							// break 3;	
							else
								$this->wrapbraces($i+$e+1, $f-$e+2, $i+$f+3);
						}	
						else
						{
							$this->wrapbraces($i+$e+1, $f-$e-1, $i+$f);
						}	
						$i++;
					}
				}
			// rebuild switch default: without { }	
				else if( $this->tokens[$i][0] === T_DEFAULT
				&& $this->tokens[$i+2] !== '{' )
				{
					$f=2;
					$newbraceopen = 0;
					while( $this->tokens[$i+$f] !== ';' && $this->tokens[$i+$f] !== '}' || $newbraceopen )
					{		
						if($this->tokens[$i+$f] === '{')
							$newbraceopen++;
						else if($this->tokens[$i+$f] === '}')	
							$newbraceopen--;
						$f++;
						
						if(!isset($this->tokens[$i+$f]))
						{
							addError('Could not find ending of '.$this->tokens[$i][1].'-statement.', array_slice($this->tokens, $i, 5), $this->tokens[$i][2], $this->filename);
							break;	
						}
					}
					$this->wrapbraces($i+2, $f-1, $i+$f+1);
				}
			// lowercase all function names because PHP doesn't care	
				else if( $this->tokens[$i][0] === T_FUNCTION )
				{
					$this->tokens[$i+1][1] = strtolower($this->tokens[$i+1][1]);
				}	
				else if( $this->tokens[$i][0] === T_STRING && $this->tokens[$i+1] === '(')
				{
					$this->tokens[$i][1] = strtolower($this->tokens[$i][1]);
				}	
			// switch a do while with a while (the difference in loop rounds doesnt matter
			// and we need the condition to be parsed before the loop tokens)
				else if( $this->tokens[$i][0] === T_DO )
				{
					$f=2;
					$otherDOs = 0;
					// f = T_WHILE token position relative to i
					while( $this->tokens[$i+$f][0] !== T_WHILE || $otherDOs )
					{		
						if($this->tokens[$i+$f][0] === T_DO)
							$otherDOs++;
						else if($this->tokens[$i+$f][0] === T_WHILE)
							$otherDOs--;
						$f++;
						
						if(!isset($this->tokens[$i+$f]))
						{
							addError('Could not find WHILE of DO-WHILE-statement.', array_slice($this->tokens, $i, 5), $this->tokens[$i][2], $this->filename);
							break;	
						}
					}
					
					// rebuild do while without {} (should never happen but we want to be sure)
					if($this->tokens[$i+1] !== '{')
					{
						$this->wrapbraces($i+1, $f-1, $i+$f);
						// by adding braces we added two new tokens
						$f+=2;
					}

					$d=1;
					// d = END of T_WHILE condition relative to i
					while( $this->tokens[$i+$f+$d] !== ';' && $d<$max )
					{
						$d++;
					}
					
					// reorder tokens and replace DO WHILE with WHILE
					$this->tokens = array_merge(
						array_slice($this->tokens, 0, $i), // before DO 
						array_slice($this->tokens, $i+$f, $d), // WHILE condition
						array_slice($this->tokens, $i+1, $f-1), // DO WHILE loop tokens
						array_slice($this->tokens, $i+$f+$d+1, count($this->tokens)) // rest of tokens without while condition
					);	
				}
			}	
		}
		// return tokens with rearranged key index
		$this->tokens = array_values($this->tokens);
	}
	
	// rewrite $arrays[] to	$variables and save keys in $tokens[$i][3]
	function array_reconstruct_tokens()
	{	
		for($i=0,$max=count($this->tokens); $i<$max; $i++)
		{
			// check for arrays
			if( is_array($this->tokens[$i]) && $this->tokens[$i][0] === T_VARIABLE && $this->tokens[$i+1] === '[' )
			{	
				$this->tokens[$i][3] = array();
				$has_more_keys = true;
				$index = -1;
				$c=2;
				
				// loop until no more index found: array[1][2][3]
				while($has_more_keys && $index < MAX_ARRAY_KEYS)
				{
					$index++;
					// save constant index as constant
					if(($this->tokens[$i+$c][0] === T_CONSTANT_ENCAPSED_STRING || $this->tokens[$i+$c][0] === T_LNUMBER || $this->tokens[$i+$c][0] === T_NUM_STRING || $this->tokens[$i+$c][0] === T_STRING) && $this->tokens[$i+$c+1] === ']')
					{ 		
						unset($this->tokens[$i+$c-1]);
						$this->tokens[$i][3][$index] = str_replace(array('"', "'"), '', $this->tokens[$i+$c][1]);
						unset($this->tokens[$i+$c]);
						unset($this->tokens[$i+$c+1]);
						$c+=2;
					// save tokens of non-constant index as token-array for backtrace later	
					} else
					{
						$this->tokens[$i][3][$index] = array();
						$newbraceopen = 1;
						unset($this->tokens[$i+$c-1]);
						while($newbraceopen !== 0)
						{	
							if( $this->tokens[$i+$c] === '[' )
							{
								$newbraceopen++;
							}
							else if( $this->tokens[$i+$c] === ']' )
							{
								$newbraceopen--;
							}
							else
							{
								$this->tokens[$i][3][$index][] = $this->tokens[$i+$c];
							}	
							unset($this->tokens[$i+$c]);
							$c++;
							
							if(!isset($this->tokens[$i+$c]))
							{
								addError('Could not find closing bracket of '.$this->tokens[$i][1].'[].', array_slice($this->tokens, $i, 5), $this->tokens[$i][2], $this->filename);
								break;	
							}
						}
						unset($this->tokens[$i+$c-1]);
					}
					if($this->tokens[$i+$c] !== '[')
						$has_more_keys = false;
					$c++;	
				}	
				
				$i+=$c-1;
			}
		}
	
		// return tokens with rearranged key index
		$this->tokens = array_values($this->tokens);		
	}
	
	// handle ternary operator (remove condition, only values should be handled during trace)
	// problem: tainting in the condition is not actual tainting the line -> remove condition	
	function fix_ternary()
	{
		for($i=0,$max=count($this->tokens); $i<$max; $i++)
		{
			if( $this->tokens[$i] === '?' )
			{
				unset($this->tokens[$i]);
				// condition in brackets: fine, delete condition
				if($this->tokens[$i-1] === ')')
				{
					unset($this->tokens[$i-1]);
					// delete tokens till ( 
					$newbraceopen = 1;
					$f = 2;
					while( $newbraceopen !== 0 && $this->tokens[$i - $f] !== ';')
					{
						if( $this->tokens[$i - $f] === '(' )
						{
							$newbraceopen--;
						}
						else if( $this->tokens[$i - $f] === ')' )
						{
							$newbraceopen++;
						}
						unset($this->tokens[$i - $f]);	
						$f++;
						
						if(($i-$f)<0)
						{
							addError('Could not find opening parenthesis in ternary operator (1).', array_slice($this->tokens, $i-5, 10), $this->tokens[$i+1][2], $this->filename);
							break;	
						}
					}

					//delete token before, if T_STRING
					if($this->tokens[$i-$f] === '!' || (is_array($this->tokens[$i-$f]) 
					&& ($this->tokens[$i-$f][0] === T_STRING || $this->tokens[$i-$f][0] === T_EMPTY || $this->tokens[$i-$f][0] === T_ISSET)))
					{
						unset($this->tokens[$i-$f]);
					}
					
				}
				// condition is a check or assignment
				else if(in_array($this->tokens[$i-2][0], Tokens::$T_ASSIGNMENT) || in_array($this->tokens[$i-2][0], Tokens::$T_OPERATOR) )
				{
					// remove both operands
					unset($this->tokens[$i-1]);
					unset($this->tokens[$i-2]);
					// if operand is in braces
					if($this->tokens[$i-3] === ')')
					{
						// delete tokens till ( 
						$newbraceopen = 1;
						$f = 4;
						while( $newbraceopen !== 0 )
						{
							if( $this->tokens[$i - $f] === '(' )
							{
								$newbraceopen--;
							}
							else if( $this->tokens[$i - $f] === ')' )
							{
								$newbraceopen++;
							}
							unset($this->tokens[$i - $f]);	
							$f++;
							
							if(($i-$f)<0 || $this->tokens[$i - $f] === ';')
							{
								addError('Could not find opening parenthesis in ternary operator (2).', array_slice($this->tokens, $i-8, 6), $this->tokens[$i+1][2], $this->filename);
								break;	
							}
						}

						//delete token before, if T_STRING
						if(is_array($this->tokens[$i-$f]) 
						&& ($this->tokens[$i-$f][0] === T_STRING || $this->tokens[$i-$f][0] === T_EMPTY || $this->tokens[$i-$f][0] === T_ISSET))
						{
							unset($this->tokens[$i-$f]);
						}
					}

					unset($this->tokens[$i-3]);
					
				}
				// condition is a single variable, delete
				else if(is_array($this->tokens[$i-1]) && $this->tokens[$i-1][0] === T_VARIABLE)
				{
					unset($this->tokens[$i-1]);
				}
			}	
		}
		// return tokens with rearranged key index
		$this->tokens = array_values($this->tokens);	
	}
}	
	
?>	