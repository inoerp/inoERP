<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/

	// get all php files from directory, including all subdirectories
	function read_recursiv($path, $scan_subdirs)
	{  
		$result = array(); 

		$handle = opendir($path);  

		if ($handle)  
		{  
			while (false !== ($file = readdir($handle)))  
			{  
				if ($file !== '.' && $file !== '..')  
				{  
					$name = $path . '/' . $file; 
					if (is_dir($name) && $scan_subdirs) 
					{  
						$ar = read_recursiv($name, true); 
						foreach ($ar as $value) 
						{ 
							if(in_array(substr($value, strrpos($value, '.')), $GLOBALS['FILETYPES']))
								$result[] = $value; 
						} 
					} else if(in_array(substr($name, strrpos($name, '.')), $GLOBALS['FILETYPES'])) 
					{  
						$result[] = $name; 
					}  
				}  
			}  
		}  
		closedir($handle); 
		return $result;  
	}  
	
?>	