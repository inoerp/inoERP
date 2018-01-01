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
	function highlightline($line, $line_nr, $marklines, $in_comment)
	{
		$tokens = @token_get_all('<? '.$line.' ?>');
		$output = (in_array($line_nr, $marklines)) ? '<tr><td nowrap class="markline">' : '<tr><td nowrap class="codeline">';

		for($i=0; $i<count($tokens); $i++)
		{				
			if(is_array($tokens[$i]) && ($tokens[$i][0] === T_COMMENT || $tokens[$i][0] === T_DOC_COMMENT)
			&& ($tokens[$i][1][0] === '/' && $tokens[$i][1][1] === '*' && substr(trim($tokens[$i][1]),-2,2) !== '*/')) 
			{ 
				$in_comment = true;
				if(is_array($tokens[$i]))
					$tokens[$i][1] = str_replace('?'.'>', '', $tokens[$i][1]);
			}
			if($tokens[$i] === '/' && $tokens[$i-1] === '*')
			{
				$in_comment = false;
			}

			if($i == count($tokens)-1 && $tokens[$i-1][0] !== T_CLOSE_TAG)
				$tokens[$i][1] = str_replace('?'.'>', '', $tokens[$i][1]);
			
			if($in_comment)
			{
				if($tokens[$i][1] !== '<?' && $tokens[$i][1] !== '?'.'>')
				{
					$trimmed = is_array($tokens[$i]) ? trim($tokens[$i][1]) : trim($tokens[$i]);
					$output .= '<span class="phps-t-comment">';
					$output .= empty($trimmed) ? '&nbsp;' : htmlentities($trimmed, ENT_QUOTES, 'utf-8'); 
					$output .= '</span>';
				}
			}
			else if($tokens[$i] === '/' && $tokens[$i-1] === '*')
				$output .= '<span class="phps-t-comment">*/</span>';
			else if (is_string($tokens[$i]))
			{	
				$output .= '<span class="phps-code">';
				$output .= htmlentities(trim($tokens[$i]), ENT_QUOTES, 'utf-8');
				$output .= '</span>';
			} 
			else if (is_array($tokens[$i]) 
			&& $tokens[$i][0] !== T_OPEN_TAG
			&& $tokens[$i][0] !== T_CLOSE_TAG) 
			{					
				if ($tokens[$i][0] !== T_WHITESPACE)
				{
					$text = '<span ';
					if($tokens[$i][0] === T_VARIABLE)
					{
						$cssname = str_replace('$', '', $tokens[$i][1]);
						$text.= 'style="cursor:pointer;" name="phps-var-'.$cssname.'" onClick="markVariable(\''.$cssname.'\')" ';
						$text.= 'onmouseover="markVariable(\''.$cssname.'\')" onmouseout="markVariable(\''.$cssname.'\')" ';
					}	
					else if($tokens[$i][0] === T_STRING && $tokens[$i+1] === '(' && $tokens[$i-2][0] !== T_FUNCTION)
					{
						$text.= 'onmouseover="mouseFunction(\''.strtolower($tokens[$i][1]).'\', this)" onmouseout="this.style.textDecoration=\'none\'" ';
						$text.= 'onclick="openFunction(\''.strtolower($tokens[$i][1])."','$line_nr');\" ";
					}
					$text.= 'class="phps-'.str_replace('_', '-', strtolower(token_name($tokens[$i][0]))).'" ';
					$text.= '>'.htmlentities($tokens[$i][1], ENT_QUOTES, 'utf-8').'</span>';
				}
				else
				{
					$text = str_replace(' ', '&nbsp;', $tokens[$i][1]);
					$text = str_replace("\t", str_repeat('&nbsp;', 8), $text);
				}
				
				$output .= $text;
			}
		}
		
		if(strstr($line, '*/'))
			$in_comment = false;
		
		echo $output.'</td></tr>';
		return $in_comment;
	}
	
	// print source code and mark lines
	
	$file = $_GET['file'];
	$marklines = explode(',', $_GET['lines']);
	$ext = '.'.pathinfo($file, PATHINFO_EXTENSION);

	
	if(!empty($file) && is_file($file) && in_array($ext, $FILETYPES))
	{
		$lines = file($file); 
		
		// place line numbers in extra table for more elegant copy/paste without line numbers
		echo '<tr><td><table>';
		for($i=1, $max=count($lines); $i<=$max;$i++) 
			echo "<tr><td class=\"linenrcolumn\"><span class=\"linenr\">$i</span><A id='".($i+2).'\'></A></td></tr>';
		echo '</table></td><td id="codeonly"><table id="codetable" width="100%">';
		
		$in_comment = false;
		for($i=0; $i<$max; $i++)
		{				
			$in_comment = highlightline($lines[$i], $i+1, $marklines, $in_comment);
		}
	} else
	{
		echo '<tr><td>Invalid file specified.</td></tr>';
	}
?>
</table>
</td></tr></table>