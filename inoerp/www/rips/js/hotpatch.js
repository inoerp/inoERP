function getParams(method)
{
	var query = "";
	var elements = document.getElementById(method).elements;
	for(var i=0;i<elements.length;i++)
	{
		if(elements[i].name !== 'filter')
		{
		query = query + elements[i].name + '=' + elements[i].value;
		if(i != elements.length-2)
			query = query + '&';
		}	
	}
	return query;
}

function createHotpatch()
{	
	var output = "mod_security rule:<br><br>";
		
	if(document.getElementById('$_GET') != undefined)
	{
		var getquery = getParams('$_GET');
		output = output + "SecFilterSelective QUERY_STRING \""+getquery+"\" \"deny,log,auditlog,status:404,msg:'Protected by RIPS',id:'990002',severity:'4'\"";
	}
	

	var exploitdiv = document.getElementById('hotpatchcode');
	exploitdiv.innerHTML = output;
	exploitdiv.style.display = "block";
	document.getElementById('hotpatchbuild').style.display = "none";
}

/*
// snort

alert tcp $EXTERNAL_NET any -> $HTTP_SERVERS $HTTP_PORTS (msg:"WEB-CGI yabb directory traversal attempt"; flow:to_server,established; uricontent:"/YaBB"; nocase; content:"../"; classtype:attempted-recon;)


// mod_security

// SERVER
SecRule REQUEST_HEADERS:User-Agent "(?:\b(?:m(?:ozilla\/4\.0 \(compatible\)|etis)|webtrends security analyzer|pmafind)\b|n(?:-stealth|sauditor|essus|ikto)|b(?:lack ?widow|rutus|ilbo)|(?:jaascoi|paro)s|webinspect|\.nasl)" 
        "deny,log,auditlog,status:404,msg:'Request Indicates a Security Scanner Scanned the Site',id:'990002',severity:'4'"

		http://www.modsecurity.org/documentation/modsecurity-apache/1.9.3/html-multipage/04-rules.html
	*/	