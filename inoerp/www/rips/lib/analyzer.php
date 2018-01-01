<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/
		
class Analyzer
{	
	// reconstructs string from a list of tokens
	function get_tokens_value($file_name, $tokens, $var_declares, $var_declares_global, $tokenid, $start=0, $stop=0, $source_functions=array())
	{
		$value = '';
		if(!$stop) $stop = count($tokens);
		// check all tokens until instruction ends
		for($i=$start; $i<$stop; $i++)
		{
			if( is_array($tokens[$i]) )
			{		
				// trace variables for its values
				if( $tokens[$i][0] === T_VARIABLE 
				|| ($tokens[$i][0] === T_STRING 
				&& $tokens[$i+1] !== '(' ) )
				{
					if(!in_array($tokens[$i][1], Sources::$V_USERINPUT))
					{						
						// constant CONSTANTS
						if ($tokens[$i][1] === 'DIRECTORY_SEPARATOR')
							$value .= '/';
						else if ($tokens[$i][1] === 'PATH_SEPARATOR')	
							$value .= ';';
						// global $varname -> global scope, CONSTANTS
						else if( (isset($tokens[$i-1]) && is_array($tokens[$i-1]) && $tokens[$i-1][0] === T_GLOBAL) || $tokens[$i][1][0] !== '$' )
							$value .= self::get_var_value($file_name, $tokens[$i], $var_declares_global, $var_declares_global, $tokenid);
						// local scope
						else
							$value .= self::get_var_value($file_name, $tokens[$i], $var_declares, $var_declares_global, $tokenid); 
					} else
					{
						if(isset($tokens[$i][3]))
							$parameter_name = str_replace(array("'",'"'), '', $tokens[$i][3][0]);
						else
							$parameter_name = '';
							
						// mark userinput for quote analysis
						if( ($tokens[$i][1] !== '$_SERVER' || (empty($parameter_name) || in_array($parameter_name, Sources::$V_SERVER_PARAMS) || substr($parameter_name,0,5) === 'HTTP_'))
						&& !((is_array($tokens[$i-1]) 
						&& in_array($tokens[$i-1][0], Tokens::$T_CASTS))
						|| (is_array($tokens[$i+1]) 
						&& in_array($tokens[$i+1][0], Tokens::$T_ARITHMETIC))) )
							$value.='$_USERINPUT';
						else
							$value.='1';
					}
				}
				// add strings 
				// except first string of define('var', 'value')
				else if( $tokens[$i][0] === T_CONSTANT_ENCAPSED_STRING 
				&& !($tokens[$i-2][0] === T_STRING && $tokens[$i-2][1] === 'define'))
				{
					// add string without quotes
					$value .= substr($tokens[$i][1], 1, -1); 
				}
				// add directory name dirname(__FILE__)
				else if( $tokens[$i][0] === T_FILE 
				&& ($tokens[$i-2][0] === T_STRING && $tokens[$i-2][1] === 'dirname'))
				{
					 // overwrite value because __FILE__ is absolute
					 // add slash just to be sure
					$value = dirname($file_name).'/';
				}
				// add numbers
				else if( $tokens[$i][0] === T_LNUMBER || $tokens[$i][0] === T_DNUMBER || $tokens[$i][0] === T_NUM_STRING )
				{
					$value .= round($tokens[$i][1]);
				}
				else if( $tokens[$i][0] === T_ENCAPSED_AND_WHITESPACE )
				{
					$value .= $tokens[$i][1];
				}
				// if in foreach($bla as $key=>$value) dont trace $key, $value back
				else if( $tokens[$i][0] === T_AS )
				{
					break;
				}
				// function calls
				else if($tokens[$i][0] === T_STRING && $tokens[$i+1] === '(')
				{
					// stop if strings are fetched from database/file (otherwise SQL query will be added)
					if (in_array($tokens[$i][1], Sources::$F_DATABASE_INPUT) || in_array($tokens[$i][1], Sources::$F_FILE_INPUT) || isset(Info::$F_INTEREST[$tokens[$i][1]]))
					{
						break;
					}
					// add userinput for functions that return userinput
					else if(in_array($tokens[$i][1], $source_functions))
					{
						$value .= '$_USERINPUT';
					}
				}	
			}
		}

		return $value;

	}
	
	// traces values of variables and reconstructs string 
	function get_var_value($file_name, $var_token, $var_declares, $var_declares_global, $last_token_id, $source_functions=array())
	{
		$var_value = '';

		// CONSTANTS
		if($var_token[1][0] !== '$')
			$var_token[1] = strtoupper($var_token[1]);

		// check if var declaration could be found for this var
		if( isset($var_declares[$var_token[1]]) )
		{
			foreach($var_declares[$var_token[1]] as $var_declare)
			{
				// check if array keys are the same (if it is an array)
				$array_key_diff = false;
				if( isset($var_token[3]) && !empty($var_declare->array_keys) )		
					$array_key_diff = array_diff_assoc($var_token[3], $var_declare->array_keys);	

				if( $var_declare->id < $last_token_id && empty($array_key_diff))											
					$var_value .= self::get_tokens_value($file_name, $var_declare->tokens, $var_declares, $var_declares_global, $var_declare->id, $var_declare->tokenscanstart, $var_declare->tokenscanstop, $source_functions);

				if($var_value)
					break;
			}
		}
		return $var_value;
	}
	
	// get end of codeblock (Detect brace ending, ignore new brace opening and closing in between)
	function getBraceEnd($tokens, $i)
	{
		$c=1;
		$newbraceopen = 1;
		while( !($newbraceopen === 0 || $tokens[$i + $c] === ';') )
		{
			// watch function calls in function call
			if( $tokens[$i + $c] === '(' )
			{
				$newbraceopen++;
			}
			else if( $tokens[$i + $c] === ')' )
			{
				$newbraceopen--;
			}
			if($c>50)break;
			$c++;
		}
		return $c;
	}
	
	function get_ini_paths($path)
	{
		if(!preg_match('/([;\\\\]|\W*[C-Z]{1}:)/', $path))	
			$path = str_replace(':', ';', $path);
		return explode(';', $path);
	}
}	
	
?>	