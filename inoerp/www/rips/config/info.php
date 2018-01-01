<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/

final class Info
{	
	// interesting functions, output and comment them if seen
	public static $F_INTEREST = array(
		'phpinfo'						=> 'phpinfo() detected',
		'registerPHPFunctions'			=> 'registerPHPFunctions() allows code exec in XML',
		'session_start'					=> 'uses sessions',
		#'session_destroy'				=> 'session_destroy(), delete arbitrary file in PHP 5.1.2',
		'dbase_open' 					=> 'using DBMS dBase',
		'dbplus_open' 					=> 'using DBMS DB++',
		'dbplus_ropen' 					=> 'using DBMS DB++',
		'fbsql_connect' 				=> 'using DBMS FrontBase' ,
		'ifx_connect'					=> 'using DBMS Informix',
		'db2_connect'					=> 'using DBMS IBM DB2',
		'db2_pconnect'					=> 'using DBMS IBM DB2',
		'ftp_connect'					=> 'using FTP server', 
		'ftp_ssl_connect' 				=> 'using FTP server', 
		'ingres_connect'				=> 'using DBMS Ingres',
		'ingres_pconnect'				=> 'using DBMS Ingres',
		'ldap_connect'					=> 'using LDAP server',
		'msession_connect'	 			=> 'using msession server',
		'msql_connect'					=> 'using DBMS mSQL',
		'msql_pconnect'					=> 'using DBMS mSQL',
		'mssql_connect'					=> 'using DBMS MS SQL',
		'mssql_pconnect'				=> 'using DBMS MS SQL',
		'mysql_connect'					=> 'using DBMS MySQL',
		#'mysql_escape_string'			=> 'insecure mysql_escape_string',
		'mysql_pconnect'				=> 'using DBMS MySQL',
		'mysqli'						=> 'using DBMS MySQL, MySQLi Extension',
		'mysqli_connect'				=> 'using DBMS MySQL, MySQLi Extension',
		'mysqli_real_connect'			=> 'using DBMS MySQL, MySQLi Extension',
		'oci_connect'					=> 'using DBMS Oracle OCI8',
		'oci_new_connect'				=> 'using DBMS Oracle OCI8',
		'oci_pconnect'					=> 'using DBMS Oracle OCI8',
		'ocilogon'						=> 'using DBMS Oracle OCI8',
		'ocinlogon'						=> 'using DBMS Oracle OCI8',
		'ociplogon'						=> 'using DBMS Oracle OCI8',
		'ora_connect'					=> 'using DBMS Oracle',
		'ora_pconnect'					=> 'using DBMS Oracle',
		'ovrimos_connect'				=> 'using DBMS Ovrimos SQL',
		'pg_connect'					=> 'using DBMS PostgreSQL',
		'pg_pconnect'					=> 'using DBMS PostgreSQL',
		'sqlite_open'					=> 'using DBMS SQLite',
		'sqlite_popen'					=> 'using DBMS SQLite',
		'SQLite3'						=> 'using DBMS SQLite3',
		'sybase_connect'				=> 'using DBMS Sybase',
		'sybase_pconnect'				=> 'using DBMS Sybase',
		'TokyoTyrant'					=> 'using DBMS TokyoTyrant',
		'xptr_new_context'				=> 'using XML document',
		'xpath_new_context'				=> 'using XML document'
	);	
	
	// interesting functions for POP/Unserialze
	public static $F_INTEREST_POP = array(
		'__autoload'					=> 'function __autoload',
		'__destruct'					=> 'POP gagdet __destruct',
		'__wakeup'						=> 'POP gagdet __wakeup',
		'__toString'					=> 'POP gagdet __toString',
		'__call'						=> 'POP gagdet __call',
		'__callStatic'					=> 'POP gagdet __callStatic',
		'__get'							=> 'POP gagdet __get',
		'__set'							=> 'POP gagdet __set',
		'__isset'						=> 'POP gagdet __isset',
		'__unset'						=> 'POP gagdet __unset'
	);
	
}

?>	