/** 

RIPS - A static source code analyser for vulnerabilities in PHP scripts 
	by Johannes Dahse (johannes.dahse@rub.de)
			
			
**/

/* SCAN */

function scanAnimation(height, idprefix)
{
	var div = document.getElementById(idprefix+'ned');
	div.style.height = height+"px";
}


function handleResponse(idprefix) {
	if (client.readyState != 4 && client.readyState != 3)
		return;
	if (client.readyState == 3 && client.status != 200)
		return;
	if (client.readyState == 4 && client.status != 200) {
		return;
	}

	if (client.responseText === null)
		return;

	while (prevDataLength != client.responseText.length) {
		if (client.readyState == 4  && prevDataLength == client.responseText.length)
			break;
			
		prevDataLength = client.responseText.length;

		var lines = client.responseText.split('\n');
		var newline = lines[lines.length-2];

		if(newline == 'STATS_DONE.') {				
			console.log("done");
			stats_done = true;
			return;	
		} else if(newline != undefined)
		{
			data = newline.split('|');
			if(data[0] != undefined && data[1] != undefined && data[2] != undefined && data[3] != undefined)
			{
				document.getElementById(idprefix+"file").innerHTML = data[2];
				procent = Math.round((data[0]/data[1])*100);
				
				scanAnimation((procent * 75)/100, idprefix)
				
				document.getElementById(idprefix+"progress").innerHTML = '<span style="font-size:20px">' + procent + '%</span><br />(' + data[0] + '/' + data[1] + ')';
				document.getElementById(idprefix+"timeleft").innerHTML = 'appr. timeleft: ' + ( (Math.round(data[3]/60) > 1) ? (Math.round(data[3]/60) + ' min') : (Math.round(data[3]) + ' sec') );
			} else
			{
				stats_done = true;
			}
		}
	}	

	if (client.readyState == 4 && prevDataLength == client.responseText.length) {
		return;
	}	

}


function scan(ignore_warning)
{
	var location = encodeURIComponent(document.getElementById("location").value);
	var subdirs = Number(document.getElementById("subdirs").checked);
	var	verbosity = document.getElementById("verbosity").value;
	var vector = document.getElementById("vector").value;
	var treestyle = document.getElementById("treestyle").value;
	var stylesheet = document.getElementById("css").value;
	
	var params = "loc="+location+"&subdirs="+subdirs+"&verbosity="+verbosity+"&vector="+vector+"&treestyle="+treestyle+"&stylesheet="+stylesheet;

	if(ignore_warning)
		params+="&ignore_warning=1";
	
	document.getElementById("scanning").style.backgroundImage="url(css/scanning.gif)";
	document.getElementById("scanning").innerHTML='scanning ...<div class="scanfile" id="scanfile"></div><div class="scanned" id="scanned"></div><div class="scanprogress" id="scanprogress"></div><div class="scantimeleft" id="scantimeleft"></div>'
	document.getElementById("scanning").style.display="block";
	
	prevDataLength = 0;
	nextLine = '';
	
	var a = true;
	stats_done = false;
	client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 3 && !stats_done)
			handleResponse('scan');
		else if(this.readyState == 4 && this.status == 200 && a) 
		{
			if(!this.responseText.match(/^\s*warning:/))
			{
				document.getElementById("scanning").style.display="none";
				document.getElementById("options").style.display="";
				
				nostats = this.responseText.split("STATS_DONE.\n");
				if(nostats[1])
					result = nostats[1];
				else
					result = nostats[0];
				
				document.getElementById("result").innerHTML=(result);
				generateDiagram();
			}
			else
			{
				var amount = this.responseText.split(':')[1];
				var warning = "<div class=\"warning\">";
				warning+="<h2>warning</h2>";
				warning+="<p>You are about to scan " + amount + " files. ";
				warning+="Depending on the amount of codelines and includes this may take a while.";
				warning+="The author of RIPS recommends to scan only the root directory of your project without subdirs.</p>";
				warning+="<p>Do you want to continue anyway?</p>";	
				warning+="<input type=\"button\" class=\"Button\" value=\"continue\" onClick=\"scan(true);\"/>&nbsp;";
				warning+="<input type=\"button\" class=\"Button\" value=\"cancel\" onClick=\"document.getElementById('scanning').style.display='none';\"/>";
				warning+="</div>";
				document.getElementById("scanning").style.backgroundImage="none";
				document.getElementById("scanning").innerHTML=warning;
			}
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			var warning = "<div class=\"warning\">";
			warning+="<h2>Network error (HTTP "+this.status+")</h2>";
			if(this.status == 0)
				warning+="<p>Could not access <i>main.php</i>. Make sure your webserver is running.</p>";
			else if(this.status == 404)
				warning+="<p>Could not access <i>main.php</i>. Make sure you copied all files.</p>";
			else if(this.status == 500)	
				warning+="<p>Scan aborted. Try to scan only one entry file at once or increase the <i>set_time_limit()</i> in </i>config/general.php</i>.</p>";
			warning+="</div>";
			document.getElementById("scanning").style.backgroundImage="none";
			document.getElementById("scanning").innerHTML=warning;
		}
	}
	client.open("POST", "main.php", true);
	client.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	client.setRequestHeader("Content-length", params.length);
	client.setRequestHeader("Connection", "close");
	client.send(params);
}

function leakScan(hoveritem, varname, line, ignore_warning)
{
	var title = 'Data Leak Scan - ' + varname;
	var mywindow = document.getElementById("window2");	
	mywindow.style.display="block";
	mywindow.style.width=700;
	mywindow.style.height=350;
	
	if(hoveritem)
	{
		if(hoveritem != 3 && hoveritem != 4)
			var tmp = hoveritem.offsetParent;
		else	
			var tmp = document.getElementById("windowtitle"+hoveritem);
		
		mywindow.style.top = tmp.offsetParent.offsetTop - 90; 
		mywindow.style.right = 250; 
	}	
	
	document.getElementById("windowtitle2").innerHTML=title;
	
	var location = encodeURIComponent(document.getElementById("location").value);
	var subdirs = Number(document.getElementById("subdirs").checked);
	var treestyle = document.getElementById("treestyle").value;
	
	var params = "loc="+location+"&subdirs="+subdirs+"&treestyle="+treestyle+"&varname="+varname+"&line="+line;

	if(ignore_warning)
		params+="&ignore_warning=1";
	
	document.getElementById("windowcontent2").innerHTML = '';
	var scandiv = document.createElement('div');
	scandiv.className="scanning";
	scandiv.style.marginTop="30px";
	scandiv.style.marginLeft="150px";
	scandiv.style.backgroundImage="url(css/scanning.gif)";
	scandiv.innerHTML='scanning ...<div class="scanfile" id="leakscanfile"></div><div class="scanned" id="leakscanned"></div><div class="scanprogress" id="leakscanprogress"></div><div class="scantimeleft" id="leakscantimeleft"></div>';
	scandiv.id="dataleakscanning";
	scandiv.style.display="block";
	
	document.getElementById("windowcontent2").appendChild(scandiv);
	
	var a = true;
	stats_done = false;
	client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 3 && !stats_done)
			handleResponse('leakscan');
		else if(this.readyState == 4 && this.status == 200 && a) 
		{
			if(!this.responseText.match(/^\s*warning:/))
			{
				document.getElementById("dataleakscanning").style.display="none";

				nostats = this.responseText.split("STATS_DONE.\n");
				
				if(nostats[1])
					document.getElementById("windowcontent2").innerHTML=(nostats[1]);
				else
					document.getElementById("windowcontent2").innerHTML='<br /><center>No data leak found. You need blind exploitation techniques.</center>';
			}	
			else
			{
				var amount = this.responseText.split(':')[1];
				var warning = "<div class=\"warning\">";
				warning+="<h2>warning</h2>";
				warning+="<p>You are about to scan " + amount + " files. ";
				warning+="Depending on the amount of codelines and includes this may take a while. ";
				warning+="The author of RIPS recommends to scan only the root directory of your project without subdirs.</p>";
				warning+="<p>Do you want to continue anyway?</p>";	
				warning+="<input type=\"button\" class=\"Button\" value=\"continue\" onClick=\"document.getElementById('dataleakscanning').style.display='none';leakScan(null, '"+varname+"', '"+line+"', true);\"/>&nbsp;";
				warning+="<input type=\"button\" class=\"Button\" value=\"cancel\" onClick=\"document.getElementById('windowcontent2').removeChild(document.getElementById('dataleakscanning'));closeWindow(2);\"/>";
				warning+="</div>";
				document.getElementById("dataleakscanning").style.backgroundImage="none";
				document.getElementById("dataleakscanning").innerHTML=warning;
			}
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			var warning = "<div class=\"warning\">";
			warning+="<h2>Network error (HTTP "+this.status+")</h2>";
			if(this.status == 0)
				warning+="<p>Could not access <i>windows/leakscan.php</i>. Make sure your webserver is running.</p>";
			else if(this.status == 404)
				warning+="<p>Could not access <i>windows/leakscan.php</i>. Make sure you copied all files.</p>";
			else if(this.status == 500)	
				warning+="<p>Scan aborted. Try to scan only one entry file at once or increase the <i>set_time_limit()</i> in </i>config/general.php</i>.</p>";
			warning+="</div>";
			document.getElementById("dataleakscanning").style.backgroundImage="none";
			document.getElementById("dataleakscanning").innerHTML=warning;
		}
	}
	client.open("POST", "windows/leakscan.php", true);
	client.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	client.setRequestHeader("Content-length", params.length);
	client.setRequestHeader("Connection", "close");
	client.send(params);
}

/* SEARCH */

function search()
{
	var location = encodeURIComponent(document.getElementById("location").value);
	var subdirs = Number(document.getElementById("subdirs").checked);
	var regex = encodeURIComponent(document.getElementById("search").value);
	var stylesheet = document.getElementById("css").value;
	
	var params = 'loc='+location+'&subdirs='+subdirs+'&search=1&regex='+regex+'&ignore_warning=1&treestyle=1&stylesheet='+stylesheet;

	document.getElementById("scanning").style.backgroundImage="url(css/scanning.gif)";
	document.getElementById("scanning").innerHTML='searching ...<div class="scanned" id="scanned"></div>';
	document.getElementById("scanning").style.display="block";
	var animation = window.setInterval("scanAnimation(document.getElementById('scanned'))", 300);
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("scanning").style.display="none";
			window.clearInterval(animation);
			document.getElementById("options").style.display="none";
			document.getElementById("result").innerHTML=(this.responseText);
			a=false;
		}
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("POST", "main.php", true);
	client.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	client.setRequestHeader("Content-length", params.length);
	client.setRequestHeader("Connection", "close");
	client.send(params);
}


/* CODE STYLE */	

function setActiveStyleSheet(title)
{
	var i, a;
	for(i=0; (a = document.getElementsByTagName("link")[i]); i++)
	{
		if(a.getAttribute("rel").indexOf("style") != -1 && a.getAttribute("title")) 
		{
			a.disabled = true;
			if(a.getAttribute("title") == title) a.disabled = false;
		}
	}
}

function hide(tag)
{
	if(document.getElementById(tag).style.display != "none")
	{
		document.getElementById(tag).style.display="none";
		document.getElementById("pic"+tag).className='plusico';
	}
	else
	{
		document.getElementById(tag).style.display="block";
		document.getElementById("pic"+tag).className='minusico';
	}
}

function catshow(tag)
{
	var elements = document.getElementsByName('allcats');
	for(var i=0;i<elements.length;i++)
	{
		if(elements[i].firstChild.getAttribute('name') == tag)
			elements[i].firstChild.style.display="block";
		else
			elements[i].firstChild.style.display="none";
	}	
	
	var elements = document.getElementsByName('pic'+tag);
	for(var i=0;i<elements.length;i++)
	{
			elements[i].className='minusico';
	}	
}

function showAllCats()
{
	var elements = document.getElementsByName('allcats');
	for(var i=0;i<elements.length;i++)
	{
		elements[i].firstChild.style.display="block";
	}		
}

function markVariable(variable)
{
	if(document.getElementsByName("phps-var-"+variable).length < 100)
	{
	var i, a;
	for(i=0; (a = document.getElementsByName("phps-var-"+variable)[i]); i++)
	{
		if(a.className == 'phps-t-variable' || a.className == 'phps-tainted-var')
			a.className = 'phps-t-variable-marked';	
		else
			a.className = 'phps-t-variable';
	}
	}
}

function mouseFunction(name, item)
{
	if(document.getElementById('fol_'+name) != null)
	{
		item.style.cursor='pointer';
		item.style.textDecoration='underline';
		item.title='jump to function code';
	}	
}

var stack = new Array(); 

function openFunction(name, linenr)
{
	if(document.getElementById('fol_'+name) != null)
	{
		var code = String(document.getElementById('fol_'+name).onclick).split("\n");
		eval(code[1]);
		var save = new Array(document.getElementById('windowcontent1').innerHTML, linenr);
		stack.push(save);
		document.getElementById('return').style.display='block';
	}	
}

function returnLastCode()
{
	var recover = stack.pop();
	if(stack.length < 1)
		document.getElementById('return').style.display='none';
	document.getElementById('windowcontent1').innerHTML = recover[0];
	document.getElementById("scrollcode").innerHTML=document.getElementById("codeonly").innerHTML;
	document.getElementById(recover[1]).scrollIntoView();
	document.body.scrollTop = document.body.scrollTop - 100;
}


/* MANAGE WINDOWS */

function closeFuncCode()
{
	document.getElementById("funccode").style.display = "none";
}

function closeWindow(id)
{
	document.getElementById("window"+id).style.display="none";
}

var lastheight = "200px";
var lastwidth = "400px";
function maxWindow(id, newwidth)
{
	lastheight = document.getElementById("window"+id).style.height;
	lastwidth = document.getElementById("window"+id).style.width;
	document.getElementById("window"+id).style.height = 400;
	document.getElementById("window"+id).style.width = newwidth+"px";
	if(id==1)
	{
		document.getElementById("windowcontent1").style.width = newwidth-84 + "px";
		scroller();
	}	
}

function minWindow(id, oldwidth)
{
	document.getElementById("window"+id).style.height = lastheight;
	document.getElementById("window"+id).style.width = lastwidth;
}

function toTop(wid)
{
	var windows = document.getElementsByName("window");
	for(var i=0; i<windows.length; i++)
	{
		if(windows[i].id == "window"+wid)
			windows[i].style.zIndex = 3;
		else
			windows[i].style.zIndex = 1;
	}
}

function showgraph(type)
{
	document.getElementById(type+'canvas').style.display="block";
	document.getElementById(type+'listdiv').style.display="none";
	document.getElementById(type+'graphbutton').style.background="white";
	document.getElementById(type+'graphbutton').style.color="black";
	document.getElementById(type+'listbutton').style.background="#454545";
	document.getElementById(type+'listbutton').style.color="white";
}

function showlist(type)
{
	document.getElementById(type+'canvas').style.display="none";
	document.getElementById(type+'listdiv').style.display="block";
	document.getElementById(type+'listbutton').style.background="white";
	document.getElementById(type+'listbutton').style.color="black";
	document.getElementById(type+'graphbutton').style.background="#454545";
	document.getElementById(type+'graphbutton').style.color="white";
}

function scroller() 
{
	var content = document.getElementById('windowcontent1');
	var win = document.getElementById('scrollwindow');
	var code1 = document.getElementById('scrollcode');
	try {
		var code2 = document.getElementById('codetable');
		if(code2.clientHeight<code1.clientHeight)
			var code = code2;
		else
			var code = code1;
	} catch(e)
	{
		code = code1;
	}
	
	win.style.height=(0.1 * content.clientHeight) + 'px';
	code1.scrollTop=((content.scrollTop / (content.scrollHeight-content.clientHeight)) * ((code.scrollHeight-code.clientHeight)));
	win.style.top=((content.scrollTop / (content.scrollHeight-content.clientHeight)) * (code.clientHeight-win.clientHeight)) + 'px';
}

/* LOAD WINDOWS */

function openWindow(id)
{
	var style = document.getElementById("window"+id).style;

	if(style.display == "" || style.display == "none") {
		style.display = "block";
		style.zIndex = 3;
	}	
	else {
		style.display = "none";
	}	
}
	
function getFuncCode(hoveritem, file, start, end)
{
	var codediv = document.getElementById("funccode");
	codediv.style.display="block"; 
	codediv.style.zIndex = 3;
	
	if(file.length > 50)
		title = '...'+file.substr(file.length-50,50);
	else
		title = file;
	document.getElementById("funccodetitle").innerHTML=title;
	
	var tmp = hoveritem.offsetParent;
	codediv.style.top = tmp.offsetParent.offsetTop; 
	codediv.style.left = hoveritem.offsetLeft;
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("funccodecontent").innerHTML=(this.responseText);
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("GET", "windows/function.php?file="+file+"&start="+start+"&end="+end);
	client.send();
}

function openHelp(hoveritem, type, thefunction, get, post, cookie, files, server)
{
	var title = 'Help - ';
	if(type.length > 50)
		title+= type.substr(0,80)+'...';
	else
		title+=type;
	
	var mywindow = document.getElementById("window2");	
	mywindow.style.display="block";
	
	if(hoveritem != 3 && hoveritem != 4)
		var tmp = hoveritem.offsetParent;
	else	
		var tmp = document.getElementById("windowtitle"+hoveritem);
		
	mywindow.style.top = tmp.offsetParent.offsetTop - 100; 
	mywindow.style.right = 200; 
	
	document.getElementById("windowtitle2").innerHTML=title;
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("windowcontent2").innerHTML=(this.responseText);
					
			document.getElementById("windowcontent2").scrollIntoView();
		
			document.body.scrollTop = tmp.offsetParent.offsetTop - 200;
			
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("GET", 
		"windows/help.php?type="+type+"&function="+thefunction+"&get="+get+"&post="+post+"&cookie="+cookie+"&files="+files+"&server="+server);
	client.send();
}

function openHotpatch(hoveritem, file, get, post, cookie, files, server)
{
	var title = 'HotPatcher - ';
	if(file.length > 50)
		title+= '...'+file.substr(file.length-50,50);
	else
		title+= file;
		
	var mywindow = document.getElementById("window2");	
	mywindow.style.display="block";
	
	var tmp = hoveritem.offsetParent;
	
	mywindow.style.top = tmp.offsetParent.offsetTop - 100; 
	mywindow.style.right = 200; 
	
	document.getElementById("windowtitle2").innerHTML=title;
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("windowcontent2").innerHTML=(this.responseText);
					
			document.getElementById("windowcontent2").scrollIntoView();
		
			document.body.scrollTop = tmp.offsetParent.offsetTop - 200;
			
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("GET", 
		"windows/hotpatch.php?file="+file+"&get="+get+"&post="+post+"&cookie="+cookie+"&files="+files+"&server="+server);
	client.send();
}

function openCodeViewer(hoveritem, file, lines)
{
	var linenrs = lines.split(",");
	var title = 'CodeViewer - ';
	if(file.length > 50)
		title+= '...'+file.substr(file.length-50,50);
	else
		title+= file;
		
	var mywindow = document.getElementById("window1");	
	mywindow.style.display="block";
	
	if(hoveritem != 3 && hoveritem != 4)
		var tmp = hoveritem.offsetParent;
	else	
		var tmp = document.getElementById("windowtitle"+hoveritem);
		
	if(tmp.offsetParent != null)	
		mywindow.style.top = tmp.offsetParent.offsetTop - 100; 
	mywindow.style.right = 200; 
	
	document.getElementById("windowtitle1").innerHTML=title;
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("windowcontent1").innerHTML=(this.responseText);
					
			if(document.getElementById(linenrs[0]) != null)	
				document.getElementById(linenrs[0]).scrollIntoView();
		
			if(tmp.offsetParent != null)
				document.body.scrollTop = tmp.offsetParent.offsetTop - 200;
			else
				document.body.scrollTop = document.body.scrollTop - 100;
			
			document.getElementById("scrollcode").innerHTML=document.getElementById("codeonly").innerHTML;
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("GET", "windows/code.php?file="+file+"&lines="+lines);
	client.send();
}

function openExploitCreator(hoveritem, file, get, post, cookie, files, server)
{
	var title = 'ExploitCreator - ';
	if(file.length > 50)
		title+= '...'+file.substr(file.length-50,50);
	else
		title+= file;
		
	var mywindow = document.getElementById("window2");	
	mywindow.style.display="block";
	
	var tmp = hoveritem.offsetParent;
	
	mywindow.style.top = tmp.offsetParent.offsetTop - 100; 
	mywindow.style.right = 200; 
	
	document.getElementById("windowtitle2").innerHTML=title;
	
	var a = true;
	var client = new XMLHttpRequest();
	client.onreadystatechange = function () 
	{ 
		if(this.readyState == 4 && this.status == 200 && a) 
		{
			document.getElementById("windowcontent2").innerHTML=(this.responseText);
					
			document.getElementById("windowcontent2").scrollIntoView();
		
			document.body.scrollTop = tmp.offsetParent.offsetTop - 200;
			
			a=false;
		} 
		else if (this.readyState == 4 && this.status != 200) 
		{
			alert("Network error ("+this.status+").");
		}
	}
	client.open("GET", 
		"windows/exploit.php?file="+file+"&get="+get+"&post="+post+"&cookie="+cookie+"&files="+files+"&server="+server);
	client.send();
}

function saveCanvas(canvas, id)
{
	var objCanvas = document.getElementById(canvas);
	var ctx = objCanvas.getContext('2d');
	var c = document.createElement('canvas');
	c.width  = ctx.canvas.width;
	c.height = ctx.canvas.height;
	var newctx = c.getContext('2d');
	newctx.fillStyle = '#FFF';
	newctx.fillRect(0,0,c.width,c.height);
	newctx.fillStyle = "#223344";
	newctx.fillText('created with RIPS', c.width-100, c.height-7);
	newctx.drawImage(ctx.canvas,0,0);
	document.getElementById("canvas"+id).innerHTML="<img src='"+c.toDataURL()+"' title='right-click to save graph' />";
	document.getElementById("canvas"+id).style.display='block';
	document.getElementById(canvas).style.display='none';
	document.getElementById(canvas+'save').value='edit graph';
	var onC='restoreCanvas("'+canvas+'", '+id+')'; 
	document.getElementById(canvas+'save').onclick = new Function(onC);
}

function restoreCanvas(canvas, id)
{
	document.getElementById("canvas"+id).style.display='none';
	document.getElementById(canvas).style.display='block';
	document.getElementById(canvas+'save').value='save graph';
	var onC='saveCanvas("'+canvas+'", '+id+')'; 
	document.getElementById(canvas+'save').onclick = new Function(onC);
}
	
/* DRAG WINDOW */	
	
var dragobjekt = null;
var dragx = 0;
var dragy = 0;
var posx = 0;
var posy = 0;

function draginit() {
  document.onmousemove = drag;
  document.onmouseup = dragstop;
}

function dragstart(id) {
  dragobjekt = document.getElementById("window"+id);
  dragx = posx - dragobjekt.offsetLeft;
  dragy = posy - dragobjekt.offsetTop;
}

function dragstop() {

dragobjekt=null;
if(document.getElementById("scrollcode") != null)
scroller();
}

function drag(ereignis) {
  posx = document.all ? window.event.clientX : ereignis.pageX;
  posy = document.all ? window.event.clientY : ereignis.pageY;
  if(dragobjekt != null) {
    dragobjekt.style.left = (posx - dragx) + "px";
    dragobjekt.style.top = (posy - dragy) + "px";
  }
}		

/* RESIZE WINDOW */

var curWidth = 0;
var curHeight = 0;
var curX = 0;
var curY = 0;
var newX = 0;
var newY = 0;
var mouseButtonPos = "up";
var windowid = 1;

function resizeStart(e, id)
{
	windowid = id;
	curEvent = ((typeof event == "undefined")? e: event);
	mouseButtonPos = "down";	
	curX = curEvent.clientX;
	curY = curEvent.clientY;
	
	var tempWidth = document.getElementById("window"+id).style.width;
	var tempHeight = document.getElementById("window"+id).style.height;

	var widthArray = tempWidth.split("p");
	curWidth = parseInt(widthArray[0]);
	var heightArray=tempHeight.split("p");
	curHeight=parseInt(heightArray[0]);
}

function getPos(e)
{
	if( mouseButtonPos == "down" )
	{
		curEvent = ((typeof event == "undefined")? e: event);
		newY = curEvent.clientY;
		newX = curEvent.clientX;
		var pxMoveY = parseInt(newY - curY);
		var pxMoveX = parseInt(newX - curX);

		var newWidth = parseInt(curWidth + pxMoveX);
		var newHeight = parseInt(curHeight + pxMoveY);

		newWidth = ((newWidth < 200)? 200: newWidth);
		newHeight=(newHeight<5?5:newHeight);

		document.getElementById("window"+windowid).style.width = newWidth + "px";
		if(windowid == 1)
			document.getElementById("windowcontent1").style.width = newWidth-84 + "px";
		document.getElementById("window"+windowid).style.height = newHeight + "px";
	}
}

/* DIAGRAM */


var myColor = [
"#9F42FF", // code
"#FFCE42", // exec
"#FF8042", // connect
"#FF4242", // file read
"#FDFF42", // file inc
"#48D141", // file affect
"#47CAC5", // ldap
"#477FCA", // sqli
"#4A47CA", // xpath
"#DADFE3", // XSS
"#16FB3B", // HTTP Header 
"#DF4242", // other
"#818C96", // pop
"#ff99ff", // reflection
"#ff33ff", // 
];

var myData = Array();
	
function generateDiagram()
{
	var canvas;
	var ctx;
	var lastend = 0;
	var myTotal = 0;
	
	// generate data
	for (var j = 0; j < 15; j++)
	{
		if(document.getElementById('vuln'+(j+1)))
		{
			myTotal += Number(document.getElementById('vuln'+(j+1)).innerHTML);
			myData[j] = Number(document.getElementById('vuln'+(j+1)).innerHTML);
		}	
		else
			myData[j] = 0;
	}
	
	canvas = document.getElementById("diagram");
	ctx = canvas.getContext("2d");
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	
	for (var i = 0; i < myData.length; i++)
	{
		if(myData[i] != 0)
		{
			document.getElementById('chart'+(i+1)).style.backgroundColor = myColor[i];
			ctx.fillStyle = myColor[i];
			ctx.beginPath();
			ctx.moveTo(45,35);
			ctx.arc(45,35,35,lastend,lastend+(Math.PI*2*(myData[i]/myTotal)),false);
			ctx.lineTo(45,35);
			ctx.fill();
			lastend += Math.PI*2*(myData[i]/myTotal);
		}
	}
}