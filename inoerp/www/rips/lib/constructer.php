<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/
	
	// variable declarations = childs
	class VarDeclare
	{
		public $id;
		public $tokens;	
		public $tokenscanstart;
		public $tokenscanstop;
		public $value;
    	public $comment;
    	public $line;	
		public $marker;
		public $dependencies;
		public $stopvar;
		public $array_keys;
		
		function __construct($tokens = array(), $comment = '') 
		{
			$this->id = 0;
			$this->tokens = $tokens;
			$this->tokenscanstart = 0;
			$this->tokenscanstop = count($tokens);
			$this->value = '';
			$this->comment = $comment;
			$this->line = '';
			$this->marker = 0;
			$this->dependencies = array();
			$this->stopvar = false;
			$this->array_keys = array();
		}
	}
	
	// group vulnerable parts to one vulnerability trace
	class VulnBlock
	{
		public $uid;
		public $vuln;
    	public $category;
    	public $treenodes;
		public $sink;
		public $dataleakvar;
		public $alternates;
		
		function __construct($uid = '', $category = 'match', $sink = '') 
		{
			$this->uid = $uid;
			$this->vuln = false;
			$this->category = $category;
			$this->treenodes = array();
			$this->sink = $sink;
			$this->dataleakvar = array();
			$this->alternates = array();
		}
	}
	
	// used to store new finds
	class VulnTreeNode
	{
		public $id;
    	public $value;
		public $dependencies;
		public $title;
		public $name;
		public $marker;
		public $lines;
		public $filename;
		public $children;
		public $funcdepend;
		public $funcparamdepend;
		public $foundcallee;
		public $get;
		public $post;
		public $cookie;
		public $files;
		public $server;

		function __construct($value = null) 
		{
			$this->id = 0;
			$this->value = $value;
			$this->title = '';
			$this->dependencies = array();
			$this->name = '';
			$this->marker = 0;
			$this->lines = array();
			$this->filename = '';
			$this->children = array();
			$this->funcdepend = '';
			$this->funcparamdepend = null;
			$this->foundcallee = false;
		}
	}
	
	// information gathering finds
	class InfoTreeNode
	{
    	public $value;
		public $dependencies;
		public $name;
		public $lines;
		public $title;
		public $filename;

		function __construct($value = null) 
		{
			$this->title = 'File Inclusion';
			$this->value = $value;
			$this->dependencies = array();
			$this->name = '';
			$this->lines = array();
			$this->filename = '';
		}
	}
	
	// function declaration
	class FunctionDeclare
	{
		public $value;
		public $tokens;
		public $name;
		public $line;
		public $marker;
		public $parameters;
		
		function __construct($tokens) 
		{
			$this->value = '';
			$this->tokens = $tokens;
			$this->name = '';
			$this->line = 0;
			$this->marker = 0;
			$this->parameters = array();
		}
	}

?>	