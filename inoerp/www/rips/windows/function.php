<table width='100%'>
<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.

**/

include('../config/general.php');

	// prepare output to style with CSS
	function highlightline($line, $line_nr)
	{
		$tokens = @token_get_all('<? '.$line.' ?>');
		$output = "<tr><td class=\"linenrcolumn\" valign=\"top\"><span class=\"linenr\">$line_nr</span>&nbsp;&nbsp;&nbsp;</td><td>";

		foreach ($tokens as $token)
		{
			if (is_string($token))
			{		
				$output .= '<span class="phps-code">';
				$output .= htmlentities($token, ENT_QUOTES, 'utf-8');
				$output .= '</span>';
			} 
			else if (is_array($token) 
			&& $token[0] !== T_OPEN_TAG
			&& $token[0] !== T_CLOSE_TAG) 
			{					
				if ($token[0] !== T_WHITESPACE)
				{
					$text = '<span class="phps-'.str_replace('_', '-', strtolower(token_name($token[0]))).'">';
					$text.= htmlentities($token[1], ENT_QUOTES, 'utf-8').'</span>';
				}
				else
				{
					$text = str_replace(' ', '&nbsp;', $token[1]);
					$text = str_replace("\t", str_repeat('&nbsp;', 8), $text);
				}
				
				$output .= $text;
			}
		}
		return $output.'</td></tr>';
	}

	// print function code
	
	$file = $_GET['file'];
	$start = (int)$_GET['start'];
	$end = (int)$_GET['end'];
	$ext = '.'.pathinfo($file, PATHINFO_EXTENSION);


	if(!empty($file) && is_file($file) && in_array($ext, $FILETYPES))
	{
		$lines = file($file); 
		
		if( isset($lines[$start]) && isset($lines[$end]) )
		{
			for($i=$start; $i<=$end; $i++)
			{
				echo highlightline($lines[$i], $i);
			}
		} else
		{
			echo '<tr><td>Sorry, wrong file referenced.</td></tr>';
		}
	} else
	{
		echo '<tr><td>Sorry, no file referenced.</td></tr>';
	}
?>
</table>