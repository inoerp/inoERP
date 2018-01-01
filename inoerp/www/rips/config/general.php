<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/
	
	#error_reporting(E_ALL);
	error_reporting(E_ERROR | E_PARSE);
	// various settings making flush() work correctly
	if(function_exists('apache_setenv'))
		apache_setenv('no-gzip', 1);
	ini_set('zlib.output_compression', 0);
	ini_set('implicit_flush', 0);
	ini_set('output_buffering', 0);
	
	ini_set('short_open_tag', 1);			// who knows if I use them ;)
	ini_set('auto_detect_line_endings', 1);	// detect newlines in MAC files
	ini_set("memory_limit","1000M");		// set memory size to 1G
	set_time_limit(0);						// 5 minutes
	
	if (extension_loaded('tokenizer') === false) 
	{
		echo 'Please enable the PHP tokenizer extension to run RIPS.';
		exit;
	}
		
	define('VERSION', '0.55');				// RIPS version to be displayed	
	define('MAXTRACE', 30);					// maximum of parameter traces per sensitive sink
	define('WARNFILES', 50);				// warn user if amount of files to scan is higher than this value, also limits the graphs so they dont get too confusing and prevents browser hanging
	define('BASEDIR', '');					// default directory shown
	define('PHPDOC', 'http://php.net/');	// PHP documentation link
	define('MAX_ARRAY_ELEMENTS', 50);		// maximum array(1,2,3,4,...) elements to be indexed
	define('MAX_ARRAY_KEYS', 10);			// maximum array key $array[1][2][3][4]..
	define('PRELOAD_SHOW_LINE', 500);		// every X line a preloader information is added
	
	define('SCAN_REGISTER_GLOBALS', false);	// EXPERIMENTAL: scan as if register_globals=on
	
	$FILETYPES = array(						// filetypes to scan
		'.php', 
		'.inc', 
		'.phps', 
		'.php4', 
		'.php5', 
		//'.html', 
		//'.htm', 
		//'.txt',
		'.phtml', 
		'.tpl',  
		'.cgi',
		'.test',
		'.module',
		'.plugin'
	); 
	
	// available stylesheets (filename without .css ending)
	// more colors at http://wiki.macromates.com/Themes/UserSubmittedThemes
	$stylesheets = array(
		'print',
		'phps',
		'code-dark',
		'twilight',
		'espresso',
		'term',
		'barf',
		'notepad++',
		'ayti'
	);
	
	// track chosen stylesheet permanently
	if(isset($_POST['stylesheet']) && $_POST['stylesheet'] !== $_COOKIE['stylesheet'])
		$_COOKIE['stylesheet'] = $_POST['stylesheet'];
	$default_stylesheet = isset($_COOKIE['stylesheet']) ? $_COOKIE['stylesheet'] : 'ayti';
	setcookie("stylesheet", $default_stylesheet);
	
	$default_vector = 'all';
		
?>	