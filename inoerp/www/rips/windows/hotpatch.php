<?php
/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
Copyright (C) 2012 Johannes Dahse

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.	

**/

if(!empty($_GET['file']))
{
	$file = $_GET['file'];
?>

<div style="padding: 20px; width: 400px">
	

<div id="hotpatchbuild">

Create mod_security rule.

<?php
	
	function getFilterOptions($id)
	{
		return '<select name="filter" onchange="document.getElementById('.$id.').value=this.value">'
			.'<option value="alpha">alphanum</option>'
			.'<option value="alpha">numerical</option>'
			.'</select>';
	}
	
	function creatediv($method, $name)
	{
		if(!empty($method))
		{
			$method = htmlentities($method, ENT_QUOTES, 'utf-8');
?>		

<div id="<?php echo $name.'box'; ?>" class="exploitbox">
	<div class="exploittitlebox">
		<div class="exploittitle"><?php echo $name ?> parameter:</div>
		<input type="button" class="closebutton" style="position:relative;top:4px;right:5px;" value="x" onClick="deleteMethod('<?php echo $name; ?>')" />
		<div style="clear: left;"></div>
	</div>

	<div class="exploitcontentbox">
	<form id="<?php echo $name; ?>">
		<table class="textcolor" cellspacing=0px cellpadding=2px>
<?php		
			$params =  explode(',', $method);
			foreach($params as $param)
			{
				if($name != '$_SERVER' || ($name == '$_SERVER' && substr($param,0,4) == 'HTTP'))
				{
					$param = htmlentities($param, ENT_QUOTES, 'utf-8');
					echo "\n<tr><td>$param:</td>\n",
					"\t<td><input type='text' id='{$method}{$param}' name='$param' value='' /></td>",
					"<td>".getFilterOptions($method.$param)."</td>\n",
					'</tr>';
				} else
				{
					echo "\n<tr><td colspan='2'>You can taint \$_SERVER['$param'] by editing the target URL.</td></tr>\n";
				}
			}
?>
		</table>
	</form>
	</div>	
</div>	
<?php			
		}
	}
	
	if(isset($_GET['get'])) creatediv($_GET['get'], '$_GET');
	if(isset($_GET['post'])) creatediv($_GET['post'], '$_POST');
	if(isset($_GET['cookie'])) creatediv($_GET['cookie'], '$_COOKIE');
	if(isset($_GET['files'])) creatediv($_GET['files'], '$_FILES');
	if(isset($_GET['server'])) creatediv($_GET['server'], '$_SERVER');

	
?>
	
	<input type="button" class="Button" value="create" onClick="createHotpatch()" />&nbsp;
	<br /><br />
</div>	

<div id="hotpatchcode">

</div>

<?php
} else
{
	echo 'No file loaded';
}

?>

</div>