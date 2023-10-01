
// ---------------------------------
// OnLoad Functions
// ---------------------------------

function onloadOrRefresh()
{
	// Get cookie for 'show/hide inheritance' and sets it
	var showStr = "";
	var cookieStr = getCookie( cookieName );
	if( cookieStr != null) { // The cookie is found
		cookieContent = getCookieContent( cookieStr, cookieInnerNameAllInheritance );
		if( cookieContent != false && isObj( cookieContent ) ) {
			showStr = cookieContent;
		}
		else {
			showStr = splitReturnFirst( originalAllInheritance_List );
		}
	}
	else {
		showStr = splitReturnFirst( originalAllInheritance_List );
	}
 if( isObj( showStr ) ){
 	showElementStoreCookie( showStr, cookieInnerNameAllInheritance );
 }
	
	hideMe = originalAllInheritance_List.split( "," );
	for( i=0; i<hideMe.length; i++ ) {
		oneOfHideMe = hideMe[i].replace( " ", "" );
		if( isObj( oneOfHideMe ) && showStr != oneOfHideMe ) {
			hideElement( oneOfHideMe );
		}
	}
	
 // Get cookie for 'show/hide overloads'
 var showStr = "";
 var cookieStr = getCookie( cookieName );
 if( cookieStr != null) { // The cookie is found
   cookieContent = getCookieContentCut( cookieStr, "overload" , "show");
   if(cookieContent.length > 0) {
     strSplit = cookieContent.split( "&" );
     for( i=0; i< strSplit.length; i++ ) {
       showOverload( strSplit[i] );
     }
   }
 }
 // Get cookie for 'show/hide on description page'
 var showStr = "";
 var cookieStr = getCookie( cookieName );
 if( cookieStr != null) { // The cookie is found
   cookieContent = getCookieContentCut( cookieStr, "desc" , "hide");
   if(cookieContent.length > 0) {
     strSplit = cookieContent.split( "&" );
     for( i=0; i< strSplit.length; i++ ) {
       hideDescription( strSplit[i] );
     }
   }
 }
}


// ---------------------------------
// Help Functions
// ---------------------------------

function isObj( objString )
{
	if(document.getElementById( "" + objString + "" )) {
		return true;
	}
	else {
		return false;
	}
}

// Splits the string and returs the first obj
function splitReturnFirst( commaString ) {

	str = commaString.split( "," );
	str[0] = str[0].replace(" ", "");
	return str[0];
}


// ---------------------------------
// My Cookie Functions
// ---------------------------------

function setMyCookie( cookieName, innerName, value )
{
	var cookieStr = getCookie( cookieName );
	if( cookieStr != null) { // The cookie is found
		cookieContent = cookieStr.split( "&" );
		for( i=0; i<cookieContent.length; i++ ) {
			innerStr = cookieContent[i].split( "=" );
			if( innerStr[0] == innerName ) { // Look for name in cookie
				// Name found, make cookie with changed value
				cookieContent[i] = innerStr[0] + "=" + value;
				newCookieStr = assembleCookieStr( cookieContent );
				setCookie( cookieName, newCookieStr, expires );
				return;
			}
		}
		// Name Not found, make cookie with this name
		newCookieStr = assembleCookieStr( cookieContent, innerName, value );
		setCookie( cookieName, newCookieStr, expires );
		return;
	}
	// Cookie Not found, make cookie with this name
	newCookieStr = innerName + "=" + value;
	setCookie( cookieName, newCookieStr, expires );
	return;
}

function assembleCookieStr( contentArray, innerName, value )
{
	newStr = '';
	for( i=0; i<contentArray.length; i++ ) {
		if( newStr != '') {
			newStr += "&"
		}
		newStr += contentArray[i];
	}

	// Add my name and value to the cookie if innerName != ''
	if( innerName != null ) {
		if( newStr != '' ) {
			newStr += "&"
		}
		newStr += innerName + "=" + value;
	}
	return newStr;
}


function getCookieContent( cookieStr, innerName )
{
	cookieStr = cookieStr.split( "&" );
	for( i=0; i<cookieStr.length; i++ ) {
		innerStr = cookieStr[i].split( "=" );
		if( innerStr[0] == innerName ) {
			return innerStr[1];
		}
	}
	return false;
}


function getCookieContentCut( cookieStr, innerName, findWhat )
{
  var arrayStr = "";
  cookieStr = cookieStr.split( "&" );
  for( i=0; i<cookieStr.length; i++ ) {
    innerStr = cookieStr[i].split( "=" );
    if( innerStr[0].indexOf(innerName) == 0 && innerStr[1] == findWhat) { // Found at first pos and found findWhat
      if(arrayStr.length > 0) arrayStr += "&";
      arrayStr += innerStr[0];
    }
  }
  return arrayStr;
}


// ---------------------------------
// Pure Cookie Functions
// ---------------------------------

function getCookie(name)
{
	var cookies = document.cookie;
	var start = cookies.indexOf(name + '=');
	if (start == -1) return null;
	var len = start + name.length + 1;
	var end = cookies.indexOf(';',len);
	if (end == -1) end = cookies.length;
	return unescape(cookies.substring(len,end));
}

function setCookie(name, value, expires, path, domain, secure)
{
	if(path == null) {path = "/"};
	value = escape(value);
	expires = (expires) ? ';expires=' + expires.toGMTString() :'';
	path    = (path)    ? ';path='    + path                  :'';
	domain  = (domain)  ? ';domain='  + domain                :'';
	secure  = (secure)  ? ';secure'                           :'';

	document.cookie =	name + '=' + value + expires + path + domain + secure;
}

function deleteCookie(name, path, domain)
{
	var expires = ';expires=Thu, 01-Jan-70 00:00:01 GMT';
	(path)    ? ';path='    + path                  : '';
	(domain)  ? ';domain='  + domain                : '';

	if (getCookie(name))
		document.cookie = name + '=' + expires + path + domain;
}


// ---------------------------------
// showElement / hideElement Functions
// ---------------------------------

function showElementStoreCookie( object, cookieInnerName )
{
	if(cookieInnerName != null){ ;
	  setMyCookie( cookieName, cookieInnerName, object );
	}
	d = document.getElementById( "" + object + "" );
 if(!d) return;
	d.style.visibility = "visible";
	d.style.display = '';
}

function showElement( object )
{
	d = document.getElementById( "" + object + "" );
 if(!d) return;
	d.style.visibility = "visible";
	d.style.display = '';
}

function hideElement( object )
{
	d = document.getElementById( "" + object + "" );
 if(!d) return;
	d.style.visibility = "hidden";
	d.style.display = 'none';
}

function showOverload( obj )
{
  showElement(obj + "All");
  showElement(obj + "AllSpan");

  hideElement(obj + "Single");
  hideElement(obj + "SingleSpan");
}


function hideDescription( obj )
{
  showElement(obj + "ExpSpan");

  hideElement(obj);
  hideElement(obj + "ColSpan");
}


// ---------------------------------------------
// Link function, to navigate around the website
// ---------------------------------------------

function link3( type, preLinkPart, dirarraynr, pageTab )
{
  for (var i=0; i<arr_find.length; i++)
  {
    preLinkPart=preLinkPart.split(arr_find[i]).join(arr_replace[i]);
  }
  var sSlash = "";
  if(arr_dir[dirarraynr] != "") {
    sSlash = "/";
  }
  return link2( type, arr_dir[dirarraynr] + sSlash + preLinkPart, pageTab );
}


function linkTab( type, preLinkPart, pageTab, obj )
{
  obj.href = link2( type, preLinkPart, pageTab );
}


function SetPageTab( type, pageTab )
{
    cookieContent = pageTab;
    setMyCookie( cookieName, 'tab_' + type, cookieContent );
    setMyCookie( cookieName, 'curPageType', type );
    setMyCookie( cookieName, 'curPageTab', pageTab );
}


function link( type, preLinkPart, obj )
{
  obj.href = link2( type, preLinkPart, "" );
}


function link2( type, preLinkPart, pageTab )
{
  var cookieVar = getCookie( cookieName );
  var cookieContent;
  var cookieContentConnectType;
  var cookieContentConnectTab;
  if( cookieVar == null ) {
    cookieContent = false;
  }
  else {
    cookieContent = getCookieContent( cookieVar, 'tab_' + type );
    cookieContentConnectType = getCookieContent( cookieVar, 'curPageType');
    cookieContentConnectTab = getCookieContent( cookieVar, 'curPageTab');
  };
  if( cookieContent == false ) {
    typeList = tabType_List.split( "," );
    typeDefaultList = tabDefault_List.split( "," );
    cookieContent = "";
    for( i=0; i<typeList.length; i++ ) {
     if( type == typeList[i].replace( " ", "" ) ) {
        cookieContent = typeDefaultList[i].replace( " ", "" );
      }
    }
    if( cookieContent == mainDirDescription) {
      cookieContent = "";
    }
    else if(cookieContent =="") {
      cookieContent = normalDescription;
    }
  }

  if( pageTab == mainDirDescription) {
    cookieContent = "";
  }
  else if( pageTab != "") {
    cookieContent = pageTab;
  }
  else if (cookieContent == mainDirDescription) {
    cookieContent = "";
  }
    var connectPage = -1;
    connectLookForList = pageConnectLookFor_List.split( "," );
    connectReplaceList = pageConnectReplace_List.split( "," );
    for( i=0; i<connectLookForList.length; i+=2 ) {
      if ( cookieContentConnectType == connectLookForList[i+0] && cookieContentConnectTab == connectLookForList[i+1] ) {
        connectPage = i
      }
    }
    if (connectPage != -1 && connectPage+1 <= connectReplaceList.length) {
      if ( type == connectReplaceList[connectPage+0] ) {
        cookieContent = connectReplaceList[connectPage+1];
      }
    }
  strlink = preLinkPart + type + cookieContent + tabExtention;
  return strlink;
}


// ---------------------------------
// Test Functions
// ---------------------------------

// ---------------------------------
// Style Sheets Functions
// ---------------------------------

function loadStyleSheet()
{
	// Get cookie for the 'Style Sheet' link and sets it
/*
	var str;
	var cookieStr = getCookie( cookieName );
	if( cookieStr != null) { // The cookie is found
		cookieContent = getCookieContent( cookieStr, cookieInnerNameOldLinks );
		if( cookieContent != false && isObj( cookieContent ) ) {
			str = cookieContent;
		}
		else {
			str = splitReturnFirst( originalLinks_List );
		}
	}
	else {
		str = splitReturnFirst( originalLinks_List );
	}
	showElementStoreCookie( str, cookieInnerNameOldLinks );
*/



	return "default.css";
}

function changeStyleSheet()
{
	return "default.css";
}
// ---------------------------------
// Search Functions
// ---------------------------------
function init()
{
  FromSearchCookie(); // gets the cookievalues
  enableDisableSearchButton();
  var OutputDiv = document.getElementById("OutputDiv");
  OutputDiv.innerHTML = "&nbsp;Loading...";
  readData();
  window.setTimeout("Search();", 50);
  var SearchStringDiv = document.getElementById("SearchString");
  SearchStringDiv.focus();
}

function readData()
{
  var OutputDiv = document.getElementById("OutputDiv");
  // Load data by direct calls
  addData(); 
  OutputDiv.innerHTML = "&nbsp;Ready";

  var dataDiv = document.getElementById("dataDiv");
  dataDiv.innerHTML = "";	
}

function enableDisableSearchButton()
{
  IncSearch = document.getElementById("chkIncSearch");
  ButtonSearch = document.getElementById("butSearch");

  ButtonSearch.disabled = IncSearch.checked;
}

function searchEnterCheck(e) {
  IncSearch = document.getElementById("chkIncSearch");
  if(IncSearch.checked) {
    return;
  }
  if (e.type == "keypress") {
    var whichCode = e.keyCode;
  }
  else {
    var whichCode = e.button;
  }

  if (e.type == "keypress") {
    if(whichCode == 13) {
      Search(true);
    }
  }
  else {
    alert("click: code=" + whichCode);
  }
}

// Search -------------------------------------------- Search

function Search(bSearchButton)
{
 var OutputDiv = document.getElementById("OutputDiv");
 searchString = document.getElementById("SearchString");
  strSearch = searchString.value.toLowerCase();
  IncSearch = document.getElementById("chkIncSearch");

  if(strSearch == "")
  {
    OutputDiv.innerHTML = "";
  }
  else
  {
    if(IncSearch.checked)
    {
      Searching();
    }
    else if(bSearchButton)
    {
      Searching();
    }
  }
}

function Searching()

{
  var OutputDiv = document.getElementById("OutputDiv");
  arrayOutput = new Array;
  searchString = document.getElementById("SearchString");
  strSearch = searchString.value.toLowerCase();
  rows = document.getElementById("rowsNumber");
  searchName = document.getElementById("chkName");
  searchBrief = document.getElementById("chkBrief");
  searchKeywords = document.getElementById("chkKeywords");
  searchClass = document.getElementById("chkClass");
  searchMethod = document.getElementById("chkMethod");
  searchAttribute = document.getElementById("chkOthers");
  var j = 0; // Number of items on output list counter
  var k = 0;

  arrayOutput[0] = "<br><table cellspacing=0 cellpadding=0 border=0 class='widthAndBorderTop'><TR VALIGN='top'><TD class='paddingHeadMultiColumn1' width=20%>" + translatorForName + "</TD><TD class='paddingHeadMultiColumn1' width=70%>" + translatorForBriefDes + "</TD><TD class='paddingHeadMultiColumn2' width=10%>" + translatorForParent + "</TD></TR>";
  if(searchClass.checked)
  {
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_class") != -1)
	     {
	       SearchArray(eval(arr_array_of_arraynames[k]),arr_types[0]);
	     }
    }
  }
  if(searchMethod.checked)
  {
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_member") != -1)
	     {
	       SearchArray(eval(arr_array_of_arraynames[k]),arr_types[1]);
	     }
    }
  }
  if(searchAttribute.checked)
  {
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_file") != -1)
	     {
		     SearchArray(eval(arr_array_of_arraynames[k]),arr_types[2]);
	     }
    }
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_namespace") != -1)
	     {
		     SearchArray(eval(arr_array_of_arraynames[k]),arr_types[3]);
	     }
    }
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_page") != -1)
	     {
	       SearchArray(eval(arr_array_of_arraynames[k]),arr_types[4]);
	     }
    }
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
	     if(arr_array_of_arraynames[k].indexOf("arr_directory") != -1)
	     {
        SearchArray(eval(arr_array_of_arraynames[k]),arr_types[5]);
      }
    }
    for (k=0; k<arr_array_of_arraynames.length; k++)
    {
      if(arr_array_of_arraynames[k].indexOf("arr_unit") != -1)
      {
        SearchArray(eval(arr_array_of_arraynames[k]),arr_types[6]);
      }
    }
  }
  arrayOutput[arrayOutput.length] = "</table>";
  OutputDiv.innerHTML = arrayOutput.join("");

  function SearchArray(ArrayToSearch, membertype)
  {
    for (var i=3; i<ArrayToSearch.length; i=i+6)
    {
      if (rows.value != "") // Check see if we need output more
        if (j >= rows.value)
          break;
      var found = false;
      if (searchName.checked)
      {
        if (ArrayToSearch[i].toLowerCase().indexOf(strSearch) != -1)
        {
          j++
            found = true;
        }
      }
      if(ArrayToSearch[i-1] == "" || ArrayToSearch[i-1] == null) ArrayToSearch[i-1] = "&nbsp;"
      if (searchBrief.checked && !found)
      {
        if (ArrayToSearch[i-1].toLowerCase().indexOf(strSearch) != -1)
        {
          j++
            found = true;
        }
      }
      if(ArrayToSearch[i+2] == "" || ArrayToSearch[i+2] == null) ArrayToSearch[i+2] = "&nbsp;"
      if (chkKeywords.checked && !found)
      {
        if (ArrayToSearch[i+2].toLowerCase().indexOf(strSearch) != -1)
        {
          j++
            found = true;
        }
      }
      if(found)
      {
        arrayOutput[arrayOutput.length] = "<tr valign='top'><td class='paddingNormal1'><a href='" + link3(membertype,ArrayToSearch[i]+ ArrayToSearch[i-3],ArrayToSearch[i-2],'') + "'>" + ArrayToSearch[i] + "</a></td><td class='paddingNormal1'>" + ArrayToSearch[i-1] + "</td><td class='paddingNormal2'>" + ArrayToSearch[i+1] + "</td></tr>";
      }
    }
  }
}

function ToSearchCookie(id, value)
{
	 expiresTemp = expires;
	 expires = expiresYear; // sets the global expire date for a cookie to one year
	 setMyCookie( cookieNameStay, 'search' + id, value );
	 expires = expiresTemp; // setting expires back to what it was before
}

function FromSearchCookie()
{
   var rowsNumberDefault = 15;

   var rowsNumber = rowsNumberDefault;
	  var chkName = false;
		var chkBrief = false;
		var chkKeywords = false;
		var chkClass = false;
		var chkMethod = false;
		var chkOthers = false;
		var chkIncSearch = true;

 	// Get cookie
 	var showStr = "";
 	var cookieStr = getCookie( cookieNameStay );
 	if( cookieStr != null) { // The cookie is found
  		rowsNumber = getCookieContent( cookieStr, 'search' + 'rowsNumber' );
	 	  chkName = getCookieContent( cookieStr, 'search' + 'chkName' );
		  chkBrief = getCookieContent( cookieStr, 'search' + 'chkBrief' );
		  chkKeywords = getCookieContent( cookieStr, 'search' + 'chkKeywords' );
		  chkClass = getCookieContent( cookieStr, 'search' + 'chkClass' );
		  chkMethod = getCookieContent( cookieStr, 'search' + 'chkMethod' );
		  chkOthers = getCookieContent( cookieStr, 'search' + 'chkOthers' );
		  chkIncSearch = getCookieContent( cookieStr, 'search' + 'chkIncSearch' );
	 }

  if(!rowsNumber) { rowsNumber = rowsNumberDefault; }
  if(!chkName) {chkName = 'true'} // set to 'true' if no cookie or content is found
  if(!chkClass) {chkClass = 'true'} // set to 'true' if no cookie or content is found

  document.getElementById("rowsNumber").value = rowsNumber;
  if(chkName == 'true') {document.getElementById("chkName").checked = true;}
  if(chkBrief == 'true') {document.getElementById("chkBrief").checked = true;}
  if(chkKeywords == 'true') {document.getElementById("chkKeywords").checked = true;}
  if(chkClass == 'true') {document.getElementById("chkClass").checked = true;}
  if(chkMethod == 'true') {document.getElementById("chkMethod").checked = true;}
  if(chkOthers == 'true') {document.getElementById("chkOthers").checked = true;}
  if(chkIncSearch == 'true') {document.getElementById("chkIncSearch").checked = true;}

}

// ----------------------
// --- Treeview Class ---
// ----------------------
// Google chrome does not read cookies as default from file://
// See http://code.google.com/p/chromium/issues/detail?id=535
// Can be enabled by running Chrome with command line switch: --enable-file-cookies
// i.e.: 'google-chrome --enable-file-cookies'
var g_trees = new Object(); 
function TreeClass (treeid, collapseExpandOnText, cookieDurationDays ) {
	var self = this;
	
	this.setCookie=function(name, value, days){ 
		var expireDate = new Date();
		//set 'expstring' to either future or past date, to set or delete cookie, respectively
		var expstring=expireDate.setDate(expireDate.getDate()+parseInt(days));
		document.cookie = name + '=' + value + '; expires=' + expireDate.toGMTString() + '; path=/';
	}
	
	this.getCookie=function(name){ 
		var re=new RegExp(name+'=[^;]+', 'i'); //construct RE to search for target name/value pair
		if (document.cookie.match(re)) return document.cookie.match(re)[0].split('=')[1];
		return '';
	}

	this.getViewport=function()
	{
		var w;
		var h;
		// the more standards compliant browsers (mozilla/netscape/opera/IE7) use window.innerWidth and window.innerHeight
		if (typeof window.innerWidth != 'undefined') {
			w = window.innerWidth,
			h = window.innerHeight
		}
		// IE6 in standards compliant mode (i.e. with a valid doctype as the first line in the document)
		else if (typeof document.documentElement != 'undefined'
			&& typeof document.documentElement.clientWidth !=
			'undefined' && document.documentElement.clientWidth != 0) {
			w = document.documentElement.clientWidth,
			h = document.documentElement.clientHeight
		}
		// older versions of IE
		else{
			w = document.getElementsByTagName('body')[0].clientWidth,
			h = document.getElementsByTagName('body')[0].clientHeight
		}
		return  { 'w':w, 'h':h }; 
	}

	
	this.rememberState=function(treeid, durationdays){ 
		var aState=self.getState();
		var sState = aState.join(',');
		sState = sState + '#' + self.getSelectedIndex();
		sState = sState + '#' + self.getTreeScrollPosition();
		self.setCookie(treeid, sState, durationdays); 
	}
	
	this.readStateFromCookie=function(){ 
		var sCookie=self.getCookie(self.treeid);
		// If no cookie found expand first parent node.
		if ( sCookie == undefined || sCookie == '' ) {
			self.collapseAll();
			var firstParentNode = document.getElementsByName(self.treeid + 'parentNodeImage' + 0)[0]; 
			var aPath = firstParentNode.src.split("/");
			var sImgBaseName = aPath[aPath.length-1];
			sImgBaseName = sImgBaseName.replace("Plus.png", "");
			self.treeOnParentNodeImageClick( firstParentNode, sImgBaseName );
			return;
		}
		
		var aState = sCookie.split('#');
		self.setState( aState[0].split(','));
		self.setSelectedNodebyIndex(aState[1]);
		self.setTreeScrollPosition(aState[2]);
	}
	this.dotask=function(target, functionref, tasktype){ //assign a function to execute to an event handler (ie: onunload)
		var tasktype=(window.addEventListener)? tasktype : 'on'+tasktype;
		if (target.addEventListener) 	target.addEventListener(tasktype, functionref, false);
		else if (target.attachEvent)	target.attachEvent(tasktype, functionref);
	}

	this.setExpandCollapseNames=function( sExpandAll, sCollapseAll ) {
		if ( sExpandAll 	== undefined ) sExpandAll 	= 'Expand All';
		if ( sCollapseAll 	== undefined ) sCollapseAll = 'Collapse All';
		self.m_sExpandAll 	= sExpandAll;
		self.m_sCollapseAll	= sCollapseAll;
	}
	
	// Use this function tyo set the treeheight delta to e.g. -100 if tree should have a height of less 
	// than total browser viewport height. If set to undefined the height is not set (in this case you could )
	// use the CSS '#TREEID_tree' property to set the height if needed or jus the function 
	this.setTreeHeightDelta=function( iTreeHeightDelta ) {
		self.m_iTreeHeightDelta	= iTreeHeightDelta;
	}

	this.setTreeHeight=function( iTreeHeight ) {
		self.m_iTreeHeight	= iTreeHeight;
	}
	
	
	this.treeOnParentNodeImageClick=function (node, parentImgBaseName) {
		var divNode = document.getElementById(node.name.replace(self.treeid + 'parentNodeImage',self.treeid + 'parentNodeDiv'));
		var imageNode = node;
		if (divNode.style.display == 'none'){
			imageNode.src = parentImgBaseName + 'Minus.png';
			divNode.style.display = '';
		}
		else {
			imageNode.src = parentImgBaseName + 'Plus.png';
			divNode.style.display = 'none';
		}
	}
	
	this.treeOnParentNodeTextClick=function ( node, parentImgBaseName) {
		var divNode = document.getElementById(node.name.replace(self.treeid + 'parentNodeText',self.treeid + 'parentNodeDiv'));
		var imageNode = document.getElementsByName(node.name.replace(self.treeid + 'parentNodeText',self.treeid + 'parentNodeImage'))[0];
		if ( self.collapseExpandOnText ) {
			if (divNode.style.display == 'none'){
				imageNode.src = parentImgBaseName + 'Minus.png';
				divNode.style.display = '';
			}
			else {
				imageNode.src = parentImgBaseName + 'Plus.png';
				divNode.style.display = 'none';
			}
		}
		self.resetSelectedNode();
	}
	
	this.onNodeTextClick=function (node, nodeImgBaseName) {
		var imageNode = document.getElementsByName(node.name.replace(self.treeid + 'nodeText',self.treeid + 'nodeImage'))[0];
		self.setSelectedNode(imageNode, nodeImgBaseName);
		////self.setTreeScrollPosition(self.getTreeScrollPosition());
		//console.log("this.onNodeTextClick");
	}
	
	this.onNodeImageClick=function (node, nodeImgBaseName){
		// for now we just return from here, since the page is not changed
		// when image is clicked, due to DoxyS more elaborate javascript for opening pages
		// Hopefully we can fix this later, but for now we disable 'marking' the clicked 
		// image to avoid confusion. user just need to click the actual link
		return;
// 		var imageNode = node
// 		self.setSelectedNode(imageNode, nodeImgBaseName);
	}

	this.setTreeScrollPosition=function(iYPos) {
		var sTreeDivID = this.treeid + '_tree';
		document.getElementById(sTreeDivID).scrollTop = iYPos;
		//document.getElementById(sTreeDivID).scrollTop = 50;
		//console.log("setTreeScrollPosition: " + iYPos );
	}

	this.getTreeScrollPosition=function() {
		var sTreeDivID = this.treeid + '_tree';
		return document.getElementById(sTreeDivID).scrollTop;
	}
	
	this.setSelectedNode=function (imageNode, nodeImgBaseName ){
		for (index = 0; index < self.nodeCount; index++) {
			document.getElementsByName(self.treeid + 'nodeImage' + index)[0].src = self.aNodeBaseNames[index] + 'Normal.png';
		}
		imageNode.src = nodeImgBaseName + 'Selected.png';
	}
	
	this.resetSelectedNode=function (){
		for (index = 0; index < self.nodeCount; index++) {
			document.getElementsByName(self.treeid + 'nodeImage' + index)[0].src = self.aNodeBaseNames[index] + 'Normal.png';
		}
	}
	
	this.setSelectedNodebyIndex=function ( imageNodeIndex ){
		if ( imageNodeIndex == -1 )	return;
		for (index = 0; index < self.nodeCount; index++) {
			if ( index == imageNodeIndex ) {
				document.getElementsByName(self.treeid + 'nodeImage' + index)[0].src = self.aNodeBaseNames[index] + 'Selected.png';
			}
			else {
				document.getElementsByName(self.treeid + 'nodeImage' + index)[0].src = self.aNodeBaseNames[index] + 'Normal.png';
			}
		}
	}
	
	this.expandAll=function (){
		for (index = 0; index < self.parentNodeCount; index++) {
			document.getElementById(self.treeid + 'parentNodeDiv' + index).style.display = '';
			document.getElementsByName(self.treeid + 'parentNodeImage' + index)[0].src = self.aParentBaseNames[index] + 'Minus.png';     
		}
	}
	
	this.collapseAll=function (){
		for (index = 0; index < self.parentNodeCount; index++) {
			document.getElementById(self.treeid + 'parentNodeDiv' + index).style.display = 'none';
			document.getElementsByName(self.treeid + 'parentNodeImage' + index)[0].src = self.aParentBaseNames[index] + 'Plus.png';     
		}
	}
	
	this.setState=function (aState){
		for (index = 0; index < self.parentNodeCount; index++) {
			if ( aState[index] == '0' ) {
				document.getElementById(self.treeid + 'parentNodeDiv' + index).style.display = 'none';
				document.getElementsByName(self.treeid + 'parentNodeImage' + index)[0].src = self.aParentBaseNames[index] + 'Plus.png';     
			}
			else {
				document.getElementById(self.treeid + 'parentNodeDiv' + index).style.display = '';
				document.getElementsByName(self.treeid + 'parentNodeImage' + index)[0].src = self.aParentBaseNames[index] + 'Minus.png';     
			}
		}
	}
	
	this.getState=function(){
		var aState = Array();
		for (index = 0; index < self.parentNodeCount; index++) {
			if ( document.getElementById(self.treeid + 'parentNodeDiv' + index).style.display == 'none' ) {
				aState[index] = '0';
			}
			else {
				aState[index] = '1';
			}
		}
		return aState;
	}
	
	this.getSelectedIndex=function(){
		var iSelectedIndex = -1;
		for (index = 0; index < self.nodeCount; index++) {
			var imgNode = document.getElementsByName(self.treeid + 'nodeImage' + index)[0];
			if ( imgNode.src.search('Selected.png') != -1 ) {
				return index;
			}
		}
		return iSelectedIndex;
	}

	
	this.startTree=function(bAddExpandCollapseAll, sExpandAll, sCollapseAll ){
		if ( bAddExpandCollapseAll == undefined ) bAddExpandCollapseAll = true;
		document.write('<div id="' + self.treeid + '" >' );
		if ( bAddExpandCollapseAll ) this.addExpandCollapseAll(self.m_sExpandAll, self.m_sCollapseAll);
		document.write('<div id="' + self.treeid + '_tree" style="overflow-y:auto; overflow-x:hidden; padding-right:20px;" >' );
	}
	
	this.endTree=function(){
		document.write("</div></div>" );
		var divTreeObj = document.getElementById(this.treeid + '_tree');
		if ( self.m_iTreeHeight != undefined ) {
			divTreeObj.style.height = self.m_iTreeHeight + "px";
		}
		else {
			divTreeObj.style.height = this.getViewport().h + self.m_iTreeHeightDelta + "px";
		}
	}

	
	this.startParentNode=function(text, url, target, parentBaseName, objLinkAttribs ){
		if ( parentBaseName 					== undefined )	parentBaseName = 'treeParent';
		var aPath = parentBaseName.split('/');
		var parentClassName = aPath[aPath.length -1];
		
		if ( objLinkAttribs 					== undefined )	objLinkAttribs = new Object();
		
		document.write("<table border=\"0\" cellpadding=\"1\" cellspacing=\"0\">");
		document.write('  <tr>');
		document.write("    <td><img src=\"" + parentBaseName + "Plus.png\" name=\"" + self.treeid + "parentNodeImage" + self.parentNodeCount + "\" onclick=\"g_trees['" + self.treeid + "'].treeOnParentNodeImageClick(this,'" + parentBaseName + "')\" style=\"cursor:pointer;\"/></td>");
		document.write("    <td nowrap ><a ");
		for ( var key in objLinkAttribs) {
			var sAttr = key + '="' + objLinkAttribs[key] + '" ';
 			document.write( sAttr );
		}
		document.write(" class=\"parentTreeNode " + parentClassName + "\" name=\"" + self.treeid + "parentNodeText" + self.parentNodeCount + "\" onclick=\"g_trees['" + self.treeid + "'].treeOnParentNodeTextClick(this,'" + parentBaseName + "');\" href=\"" + url + "\" target=\"" + target + "\" class=\"normalTreeNode\" onfocus=\"this.hideFocus=true;\" style=\"outline-style:none;\">" + text );
		document.write('</a>');
		document.write('  </td>');
		document.write('  </tr>');
		document.write('  <tr>');
		document.write('    <td></td><!-- SPACING -->');
		document.write("	<td><DIV id=\"" + self.treeid + "parentNodeDiv" + self.parentNodeCount + "\" style=\"display:none\">" );	
		self.aParentBaseNames[self.parentNodeCount] = parentBaseName;
		self.parentNodeCount = self.parentNodeCount + 1;
	}
	
	this.endParentNode=function(){
		document.write('</DIV></td>');
		document.write('  </tr>');
		document.write('</table>');
	}
	
	this.addNode=function(text, url, target, nodeBaseName, objLinkAttribs  ){
		if ( nodeBaseName 					== undefined )	nodeBaseName = 'treeNode';
		var aPath = nodeBaseName.split('/');
		var nodeClassName = aPath[aPath.length -1];
		
		if ( objLinkAttribs 					== undefined )	objLinkAttribs = new Object();
		document.write("<table border=\"0\" cellpadding=\"1\" cellspacing=\"0\">");
		document.write('  <tr>');
		document.write('	<td>');
		document.write('<a href="' + url + '" target="' + target + '" onfocus="this.hideFocus=true;" style="outline-style:none;">');
// 		document.write("<img src=\"" + nodeBaseName + "Normal.png\" border=\"0\" name=\"" + self.treeid + "nodeImage" + self.nodeCount + "\" onclick=\"g_trees['" + self.treeid + "'].onNodeImageClick(this,'" + nodeBaseName + "');\" />");
 		document.write("<img ");
// Does not make the page open on image click .. :|
// 		for ( var key in objLinkAttribs) {
// 			var sAttr = key + '="' + objLinkAttribs[key] + '" ';
//  			document.write( sAttr );
// 		}
		document.write(" src=\"" + nodeBaseName + "Normal.png\" border=\"0\" name=\"" + self.treeid + "nodeImage" + self.nodeCount + "\" onclick=\"g_trees['" + self.treeid + "'].onNodeImageClick(this,'" + nodeBaseName + "');\" />");
		
		document.write('</a>');
		document.write('	</td>');
		document.write("    <td nowrap ><a ");
		for ( var key in objLinkAttribs) {
			var sAttr = key + '="' + objLinkAttribs[key] + '" ';
 			document.write( sAttr );
		}
		document.write(" name=\"" + self.treeid + "nodeText" + self.nodeCount + "\" onclick=\"g_trees['" + self.treeid + "'].onNodeTextClick(this,'" + nodeBaseName + "');\" href=\"" + url + "\" target=\"" + target + "\" class=\"normalTreeNode " + nodeClassName + "\" onfocus=\"this.hideFocus=true;\" style=\"outline-style:none;\">" + text + "</a></td>");
		document.write('  </tr>');
		document.write('</table>');
		self.aNodeBaseNames[self.nodeCount] = nodeBaseName;
		self.nodeCount = self.nodeCount + 1;
	}
	
	this.addExpandCollapseAll=function (sExpandAll, sCollapseAll){
		document.write("<table width=\"99%\" border=\"0\">");	// If we use 100% here then right border of menu disappears in IE!
		document.write('  <tr>');
		document.write("    <td nowrap align=\"left\" width=\"auto\"><a onclick=\"g_trees['" + self.treeid + "'].expandAll();\" class=\"expandCollapse\" style=\"cursor:pointer;\">" + sExpandAll + "</a></td>");
		document.write("    <td width=\"20%\" </td>");
		document.write("    <td nowrap align=\"right\" width=\"auto\"><a onclick=\"g_trees['" + self.treeid + "'].collapseAll();\" class=\"expandCollapse\" style=\"cursor:pointer;\">" + sCollapseAll + "</a></td>");
		document.write("    <td width=\"80%\" </td>");
		document.write('  </tr>');
		document.write('</table>');  
	}

	this.treeid = treeid;
	this.m_iTreeHeightDelta = 0;
	this.m_iTreeHeight = undefined;
	if ( cookieDurationDays == undefined ) cookieDurationDays = 1;
	if ( collapseExpandOnText == undefined ) collapseExpandOnText = true;
	this.cookieDurationDays = cookieDurationDays;
	this.collapseExpandOnText = collapseExpandOnText;
	this.parentNodeCount = 0;
	this.nodeCount  = 0;
	this.selectedNodeIndex  = -1;
	this.aParentBaseNames = new Array(); 
	this.aNodeBaseNames 	= new Array(); 
	g_trees[treeid] = this;
	
	self.dotask(window, function(){ self.rememberState(treeid, self.cookieDurationDays)}, 'unload');
	self.dotask(window, function(){ self.readStateFromCookie()}, 'load');
}


function overLibDiagram() {
ol_css=CSSSTYLE;
ol_textfont="Courier,Arial,Verdana,Helvetica";
ol_textfont="Arial,Verdana,Helvetica";
ol_textcolor="#000000";
ol_textsize="12"; //px.
ol_textdecoration="none";
ol_textstyle="normal";
ol_textweight="normal";
ol_captionfont="Arial,Verdana,Helvetica";
ol_capcolor="#000000";
ol_captionsize="12"; //px.
ol_captiondecoration="none";
ol_captionstyle="normal";
ol_captionweight="bold";
ol_captionweight="normal";
ol_capbgcolor="#acd";
ol_fgcolor="#ddd";
ol_bgcolor="#000";
ol_hpos=8
ol_offsetx=0
ol_hauto="on";
ol_vauto="on";
ol_width=0;
ol_height=0;
}
function overLibLeftMenu() {
ol_css=CSSSTYLE;
ol_textfont="Arial,Verdana,Helvetica";
ol_textcolor="#000000";
ol_textsize="12"; //px.
ol_textdecoration="none";
ol_textstyle="normal";
ol_textweight="normal";
ol_fgcolor="#ddd";
ol_bgcolor="#000";
ol_hpos=8
ol_offsetx=0
ol_hauto="on";
ol_vauto="on";
ol_width=0;
ol_height=0;
}
function overLibHelp() {
ol_css=CSSSTYLE;
ol_textfont="Arial,Verdana,Helvetica";
ol_textcolor="#000000";
ol_textsize="12"; //px.
ol_textdecoration="none";
ol_textstyle="normal";
ol_textweight="normal";
ol_fgcolor="#ddd";
ol_bgcolor="#000";
ol_hpos=7
ol_offsetx=190
ol_width=0;
ol_height=0;
}
function overLibGeneratedByDoxyS() {
ol_css=CSSSTYLE;
ol_textfont="Arial,Verdana,Helvetica";
ol_textcolor="#000000";
ol_textsize="12"; //px.
ol_textdecoration="none";
ol_textstyle="normal";
ol_textweight="normal";
ol_fgcolor="#ddd";
ol_bgcolor="#000";
ol_hpos=7
ol_vpos=35
ol_offsetx=157
ol_width=0;
ol_height=0;
}
//\//////////////////////////////////////////////////////////////////////////////////
//\  overLIB 3.51  --  This notice must remain untouched at all times.
//\  Copyright Erik Bosrup 1998-2002. All rights reserved.
//\
//\  By Erik Bosrup (erik@bosrup.com).  Last modified 2002-11-01.
//\  Portions by Dan Steinman (dansteinman.com). Additions by other people are
//\  listed on the overLIB homepage.
//\
//\  Get the latest version at http://www.bosrup.com/web/overlib/
//\
//\  This script is published under an open source license. Please read the license
//\  agreement online at: http://www.bosrup.com/web/overlib/license.html
//\  If you have questions regarding the license please contact erik@bosrup.com.
//\
//\  This script library was originally created for personal use. By request it has
//\  later been made public. This is free software. Do not sell this as your own
//\  work, or remove this copyright notice. For full details on copying or changing
//\  this script please read the license agreement at the link above.
//\
//\  Please give credit on sites that use overLIB and submit changes of the script
//\  so other people can use them as well. This script is free to use, don't abuse.
//\//////////////////////////////////////////////////////////////////////////////////

//\  THIS IS A VERY MODIFIED VERSION. DO NOT EDIT OR PUBLISH. GET THE ORIGINAL!

var INARRAY=1;
var CAPARRAY=2;
var STICKY=3;
var BACKGROUND=4;
var NOCLOSE=5;
var CAPTION=6;
var LEFT=7;
var RIGHT=8;
var CENTER=9;
var OFFSETX=10;
var OFFSETY=11;
var FGCOLOR=12;
var BGCOLOR=13;
var TEXTCOLOR=14;
var CAPCOLOR=15;
var CLOSECOLOR=16;
var WIDTH=17;
var BORDER=18;
var STATUS=19;
var AUTOSTATUS=20;
var AUTOSTATUSCAP=21;
var HEIGHT=22;
var CLOSETEXT=23;
var SNAPX=24;
var SNAPY=25;
var FIXX=26;
var FIXY=27;
var FGBACKGROUND=28;
var BGBACKGROUND=29;
var PADX=30;// PADX2 out
var PADY=31;// PADY2 out
var FULLHTML=34;
var ABOVE=35;
var BELOW=36;
var CAPICON=37;
var TEXTFONT=38;
var CAPTIONFONT=39;
var CLOSEFONT=40;
var TEXTSIZE=41;
var CAPTIONSIZE=42;
var CLOSESIZE=43;
var FRAME=44;
var TIMEOUT=45;
var FUNCTION=46;
var DELAY=47;
var HAUTO=48;
var VAUTO=49;
var CLOSECLICK=50;
var CSSOFF=51;
var CSSSTYLE=52;
var CSSCLASS=53;
var FGCLASS=54;
var BGCLASS=55;
var TEXTFONTCLASS=56;
var CAPTIONFONTCLASS=57;
var CLOSEFONTCLASS=58;
var PADUNIT=59;
var HEIGHTUNIT=60;
var WIDTHUNIT=61;
var TEXTSIZEUNIT=62;
var TEXTDECORATION=63;
var TEXTSTYLE=64;
var TEXTWEIGHT=65;
var CAPTIONSIZEUNIT=66;
var CAPTIONDECORATION=67;
var CAPTIONSTYLE=68;
var CAPTIONWEIGHT=69;
var CLOSESIZEUNIT=70;
var CLOSEDECORATION=71;
var CLOSESTYLE=72;
var CLOSEWEIGHT=73;
var CAPBGCOLOR=74;
if(typeof ol_fgcolor=='undefined'){var ol_fgcolor="#CCCCFF";}
if(typeof ol_bgcolor=='undefined'){var ol_bgcolor="#333399";}
if(typeof ol_capbgcolor=='undefined'){var ol_capbgcolor="#333399";}
if(typeof ol_textcolor=='undefined'){var ol_textcolor="#000000";}
if(typeof ol_capcolor=='undefined'){var ol_capcolor="#FFFFFF";}
if(typeof ol_closecolor=='undefined'){var ol_closecolor="#9999FF";}
if(typeof ol_textfont=='undefined'){var ol_textfont="Verdana,Arial,Helvetica";}
if(typeof ol_captionfont=='undefined'){var ol_captionfont="Verdana,Arial,Helvetica";}
if(typeof ol_closefont=='undefined'){var ol_closefont="Verdana,Arial,Helvetica";}
if(typeof ol_textsize=='undefined'){var ol_textsize="1";}
if(typeof ol_captionsize=='undefined'){var ol_captionsize="1";}
if(typeof ol_closesize=='undefined'){var ol_closesize="1";}
if(typeof ol_width=='undefined'){var ol_width="200";}
if(typeof ol_border=='undefined'){var ol_border="1";}
if(typeof ol_offsetx=='undefined'){var ol_offsetx=10;}
if(typeof ol_offsety=='undefined'){var ol_offsety=10;}
if(typeof ol_text=='undefined'){var ol_text="Default Text";}
if(typeof ol_cap=='undefined'){var ol_cap="";}
if(typeof ol_sticky=='undefined'){var ol_sticky=0;}
if(typeof ol_background=='undefined'){var ol_background="";}
if(typeof ol_close=='undefined'){var ol_close="Close";}
if(typeof ol_hpos=='undefined'){var ol_hpos=8;}
if(typeof ol_status=='undefined'){var ol_status="";}
if(typeof ol_autostatus=='undefined'){var ol_autostatus=0;}
if(typeof ol_height=='undefined'){var ol_height=-1;}
if(typeof ol_snapx=='undefined'){var ol_snapx=0;}
if(typeof ol_snapy=='undefined'){var ol_snapy=0;}
if(typeof ol_fixx=='undefined'){var ol_fixx=-1;}
if(typeof ol_fixy=='undefined'){var ol_fixy=-1;}
if(typeof ol_fgbackground=='undefined'){var ol_fgbackground="";}
if(typeof ol_bgbackground=='undefined'){var ol_bgbackground="";}
if(typeof ol_padxl=='undefined'){var ol_padxl=1;}
if(typeof ol_padxr=='undefined'){var ol_padxr=1;}
if(typeof ol_padyt=='undefined'){var ol_padyt=1;}
if(typeof ol_padyb=='undefined'){var ol_padyb=1;}
if(typeof ol_fullhtml=='undefined'){var ol_fullhtml=0;}
if(typeof ol_vpos=='undefined'){var ol_vpos=36;}
if(typeof ol_aboveheight=='undefined'){var ol_aboveheight=0;}
if(typeof ol_capicon=='undefined'){var ol_capicon="";}
if(typeof ol_frame=='undefined'){var ol_frame=self;}
if(typeof ol_timeout=='undefined'){var ol_timeout=0;}
if(typeof ol_function=='undefined'){var ol_function=null;}
if(typeof ol_delay=='undefined'){var ol_delay=0;}
if(typeof ol_hauto=='undefined'){var ol_hauto=0;}
if(typeof ol_vauto=='undefined'){var ol_vauto=0;}
if(typeof ol_closeclick=='undefined'){var ol_closeclick=0;}
if(typeof ol_css=='undefined'){var ol_css=51;}
if(typeof ol_fgclass=='undefined'){var ol_fgclass="";}
if(typeof ol_bgclass=='undefined'){var ol_bgclass="";}
if(typeof ol_textfontclass=='undefined'){var ol_textfontclass="";}
if(typeof ol_captionfontclass=='undefined'){var ol_captionfontclass="";}
if(typeof ol_closefontclass=='undefined'){var ol_closefontclass="";}
if(typeof ol_padunit=='undefined'){var ol_padunit="px";}
if(typeof ol_heightunit=='undefined'){var ol_heightunit="px";}
if(typeof ol_widthunit=='undefined'){var ol_widthunit="px";}
if(typeof ol_textsizeunit=='undefined'){var ol_textsizeunit="px";}
if(typeof ol_textdecoration=='undefined'){var ol_textdecoration="none";}
if(typeof ol_textstyle=='undefined'){var ol_textstyle="normal";}
if(typeof ol_textweight=='undefined'){var ol_textweight="normal";}
if(typeof ol_captionsizeunit=='undefined'){var ol_captionsizeunit="px";}
if(typeof ol_captiondecoration=='undefined'){var ol_captiondecoration="none";}
if(typeof ol_captionstyle=='undefined'){var ol_captionstyle="normal";}
if(typeof ol_captionweight=='undefined'){var ol_captionweight="bold";}
if(typeof ol_closesizeunit=='undefined'){var ol_closesizeunit="px";}
if(typeof ol_closedecoration=='undefined'){var ol_closedecoration="none";}
if(typeof ol_closestyle=='undefined'){var ol_closestyle="normal";}
if(typeof ol_closeweight=='undefined'){var ol_closeweight="normal";}
if(typeof ol_texts=='undefined'){var ol_texts=new Array("Text 0", "Text 1");}
if(typeof ol_caps=='undefined'){var ol_caps=new Array("Caption 0", "Caption 1");}
var otext="";
var ocap="";
var osticky=0;
var obackground="";
var oclose="Close";
var ohpos=7;
var ooffsetx=2;
var ooffsety=2;
var ofgcolor="";
var obgcolor="";
var ocapbgcolor="";
var otextcolor="";
var ocapcolor="";
var oclosecolor="";
var owidth=100;
var oborder=1;
var ostatus="";
var oautostatus=0;
var oheight=-1;
var osnapx=0;
var osnapy=0;
var ofixx=-1;
var ofixy=-1;
var ofgbackground="";
var obgbackground="";
var opadxl=0;
var opadxr=0;
var opadyt=0;
var opadyb=0;
var ofullhtml=0;
var ovpos=36;
var oaboveheight=0;
var ocapicon="";
var otextfont="Verdana,Arial,Helvetica";
var ocaptionfont="Verdana,Arial,Helvetica";
var oclosefont="Verdana,Arial,Helvetica";
var otextsize="1";
var ocaptionsize="1";
var oclosesize="1";
var oframe=self;
var otimeout=0;
var otimerid=0;
var oallowmove=0;
var ofunction=null;
var odelay=0;
var odelayid=0;
var ohauto=0;
var ovauto=0;
var ocloseclick=0;
var ocss=51;
var ofgclass="";
var obgclass="";
var otextfontclass="";
var ocaptionfontclass="";
var oclosefontclass="";
var opadunit="px";
var oheightunit="px";
var owidthunit="px";
var otextsizeunit="px";
var otextdecoration="";
var otextstyle="";
var otextweight="";
var ocaptionsizeunit="px";
var ocaptiondecoration="";
var ocaptionstyle="";
var ocaptionweight="";
var oclosesizeunit="px";
var oclosedecoration="";
var oclosestyle="";
var ocloseweight="";
var ox=0;
var oy=0;
var oallow=0;
var oshowingsticky=0;
var oremovecounter=0;
var over=null;
var fnRef;
var ns4=(navigator.appName=='Netscape' && parseInt(navigator.appVersion)==4);
var ns6=(document.getElementById)? true:false;
var ie4=(document.all)? true:false;
if(ie4)var docRoot='document.body';
var ie5=false;
if(ns4){
var oW=window.innerWidth;
var oH=window.innerHeight;
window.onresize=function(){if(oW!=window.innerWidth||oH!=window.innerHeight)location.reload();}
}
if(ie4){
if((navigator.userAgent.indexOf('MSIE 5')> 0)||(navigator.userAgent.indexOf('MSIE 6')> 0)){
if(document.compatMode && document.compatMode=='CSS1Compat')docRoot='document.documentElement';
ie5=true;
}
if(ns6){
ns6=false;
}
}
if((ns4)||(ie4)||(ns6)){
document.onmousemove=mouseMove
if(ns4)document.captureEvents(Event.MOUSEMOVE)
}else{
overlib=no_overlib;
nd=no_overlib;
ver3fix=true;
}
function no_overlib(){
return ver3fix;
}
function overlib(){
otext=ol_text;
ocap=ol_cap;
osticky=ol_sticky;
obackground=ol_background;
oclose=ol_close;
ohpos=ol_hpos;
ooffsetx=ol_offsetx;
ooffsety=ol_offsety;
ofgcolor=ol_fgcolor;
obgcolor=ol_bgcolor;
ocapbgcolor=ol_capbgcolor;
otextcolor=ol_textcolor;
ocapcolor=ol_capcolor;
oclosecolor=ol_closecolor;
owidth=ol_width;
oborder=ol_border;
ostatus=ol_status;
oautostatus=ol_autostatus;
oheight=ol_height;
osnapx=ol_snapx;
osnapy=ol_snapy;
ofixx=ol_fixx;
ofixy=ol_fixy;
ofgbackground=ol_fgbackground;
obgbackground=ol_bgbackground;
opadxl=ol_padxl;
opadxr=ol_padxr;
opadyt=ol_padyt;
opadyb=ol_padyb;
ofullhtml=ol_fullhtml;
ovpos=ol_vpos;
oaboveheight=ol_aboveheight;
ocapicon=ol_capicon;
otextfont=ol_textfont;
ocaptionfont=ol_captionfont;
oclosefont=ol_closefont;
otextsize=ol_textsize;
ocaptionsize=ol_captionsize;
oclosesize=ol_closesize;
otimeout=ol_timeout;
ofunction=ol_function;
odelay=ol_delay;
ohauto=ol_hauto;
ovauto=ol_vauto;
ocloseclick=ol_closeclick;
ocss=ol_css;
ofgclass=ol_fgclass;
obgclass=ol_bgclass;
otextfontclass=ol_textfontclass;
ocaptionfontclass=ol_captionfontclass;
oclosefontclass=ol_closefontclass;
opadunit=ol_padunit;
oheightunit=ol_heightunit;
owidthunit=ol_widthunit;
otextsizeunit=ol_textsizeunit;
otextdecoration=ol_textdecoration;
otextstyle=ol_textstyle;
otextweight=ol_textweight;
ocaptionsizeunit=ol_captionsizeunit;
ocaptiondecoration=ol_captiondecoration;
ocaptionstyle=ol_captionstyle;
ocaptionweight=ol_captionweight;
oclosesizeunit=ol_closesizeunit;
oclosedecoration=ol_closedecoration;
oclosestyle=ol_closestyle;
ocloseweight=ol_closeweight;
fnRef='';
if((ns4)||(ie4)||(ns6)){
if(over)cClick();
oframe=ol_frame;
if(ns4)over=oframe.document.overDiv
if(ie4)over=oframe.overDiv.style
if(ns6)over=oframe.document.getElementById("overDiv");
}
var c=-1, udf, v=null;
var ar=arguments;
udf=(!ar.length ? 1 : 0);
for(i=0;i < ar.length;i++){
if(c < 0){
if(typeof ar[i]=='number'){
udf=(ar[i]==46 ? 0 : 1);
i--;
}else{
otext=ar[i];
}
c=0;
}else{
if(ar[i]==1){udf=0;otext=ol_texts[ar[++i]];continue;}
if(ar[i]==2){ocap=ol_caps[ar[++i]];continue;}
if(ar[i]==3){osticky=1;continue;}
if(ar[i]==4){obackground=ar[++i];continue;}
if(ar[i]==NOCLOSE){oclose="";continue;}
if(ar[i]==6){ocap=ar[++i];continue;}
if(ar[i]==9 || ar[i]==7 || ar[i]==8){ohpos=ar[i];continue;}
if(ar[i]==10){ooffsetx=ar[++i];continue;}
if(ar[i]==11){ooffsety=ar[++i];continue;}
if(ar[i]==12){ofgcolor=ar[++i];continue;}
if(ar[i]==13){obgcolor=ar[++i];continue;}
if(ar[i]==14){otextcolor=ar[++i];continue;}
if(ar[i]==15){ocapcolor=ar[++i];continue;}
if(ar[i]==16){oclosecolor=ar[++i];continue;}
if(ar[i]==17){owidth=ar[++i];continue;}
if(ar[i]==18){oborder=ar[++i];continue;}
if(ar[i]==19){ostatus=ar[++i];continue;}
if(ar[i]==20){oautostatus=(oautostatus==1)? 0 : 1;continue;}
if(ar[i]==21){oautostatus=(oautostatus==2)? 0 : 2;continue;}
if(ar[i]==22){oheight=ar[++i];oaboveheight=ar[i];continue;}// Same param again.
if(ar[i]==23){oclose=ar[++i];continue;}
if(ar[i]==24){osnapx=ar[++i];continue;}
if(ar[i]==25){osnapy=ar[++i];continue;}
if(ar[i]==26){ofixx=ar[++i];continue;}
if(ar[i]==27){ofixy=ar[++i];continue;}
if(ar[i]==28){ofgbackground=ar[++i];continue;}
if(ar[i]==29){obgbackground=ar[++i];continue;}
if(ar[i]==30){opadxl=ar[++i];opadxr=ar[++i];continue;}
if(ar[i]==31){opadyt=ar[++i];opadyb=ar[++i];continue;}
if(ar[i]==34){ofullhtml=1;continue;}
if(ar[i]==36 || ar[i]==35){ovpos=ar[i];continue;}
if(ar[i]==37){ocapicon=ar[++i];continue;}
if(ar[i]==38){otextfont=ar[++i];continue;}
if(ar[i]==39){ocaptionfont=ar[++i];continue;}
if(ar[i]==40){oclosefont=ar[++i];continue;}
if(ar[i]==41){otextsize=ar[++i];continue;}
if(ar[i]==42){ocaptionsize=ar[++i];continue;}
if(ar[i]==43){oclosesize=ar[++i];continue;}
if(ar[i]==44){opt_FRAME(ar[++i]);continue;}
if(ar[i]==45){otimeout=ar[++i];continue;}
if(ar[i]==46){udf=0;if(typeof ar[i+1] !='number')v=ar[++i];opt_FUNCTION(v);continue;}
if(ar[i]==47){odelay=ar[++i];continue;}
if(ar[i]==48){ohauto=(ohauto==0)? 1 : 0;continue;}
if(ar[i]==49){ovauto=(ovauto==0)? 1 : 0;continue;}
if(ar[i]==50){ocloseclick=(ocloseclick==0)? 1 : 0;continue;}
if(ar[i]==51){ocss=ar[i];continue;}
if(ar[i]==52){ocss=ar[i];continue;}
if(ar[i]==53){ocss=ar[i];continue;}
if(ar[i]==54){ofgclass=ar[++i];continue;}
if(ar[i]==55){obgclass=ar[++i];continue;}
if(ar[i]==56){otextfontclass=ar[++i];continue;}
if(ar[i]==57){ocaptionfontclass=ar[++i];continue;}
if(ar[i]==58){oclosefontclass=ar[++i];continue;}
if(ar[i]==59){opadunit=ar[++i];continue;}
if(ar[i]==60){oheightunit=ar[++i];continue;}
if(ar[i]==61){owidthunit=ar[++i];continue;}
if(ar[i]==62){otextsizeunit=ar[++i];continue;}
if(ar[i]==63){otextdecoration=ar[++i];continue;}
if(ar[i]==64){otextstyle=ar[++i];continue;}
if(ar[i]==65){otextweight=ar[++i];continue;}
if(ar[i]==66){ocaptionsizeunit=ar[++i];continue;}
if(ar[i]==67){ocaptiondecoration=ar[++i];continue;}
if(ar[i]==68){ocaptionstyle=ar[++i];continue;}
if(ar[i]==69){ocaptionweight=ar[++i];continue;}
if(ar[i]==70){oclosesizeunit=ar[++i];continue;}
if(ar[i]==71){oclosedecoration=ar[++i];continue;}
if(ar[i]==72){oclosestyle=ar[++i];continue;}
if(ar[i]==73){ocloseweight=ar[++i];continue;}
if(ar[i]==74){ocapbgcolor=ar[++i];continue;}
}
}
if(udf && ofunction)otext=ofunction();
if(odelay==0){
return overlib351();
}else{
odelayid=setTimeout("overlib351()", odelay);
return false;
}
}
function nd(){
if(oremovecounter >=1){oshowingsticky=0};
if((ns4)||(ie4)||(ns6)){
if(oshowingsticky==0){
oallowmove=0;
if(over !=null)hideObject(over);
}else{
oremovecounter++;
}
}
return true;
}
function overlib351(){
var layerhtml;
if(obackground !="" || ofullhtml){
layerhtml=ol_content_background(otext, obackground, ofullhtml);
}else{
if(ofgbackground !="" && ocss==CSSOFF){
ofgbackground="BACKGROUND=\""+ofgbackground+"\"";
}
if(obgbackground !="" && ocss==CSSOFF){
obgbackground="BACKGROUND=\""+obgbackground+"\"";
}
if(ofgcolor !="" && ocss==CSSOFF){
ofgcolor="BGCOLOR=\""+ofgcolor+"\"";
}
if(obgcolor !="" && ocss==CSSOFF){
obgcolor="BGCOLOR=\""+obgcolor+"\"";
}
if(oheight > 0 && ocss==51){
oheight="HEIGHT=" + oheight;
}else{
oheight="";
}
if(ocap==""){
layerhtml=ol_content_simple(otext);
}else{
if(osticky){
layerhtml=ol_content_caption(otext, ocap, oclose);
}else{
layerhtml=ol_content_caption(otext, ocap, "");
}
}
}
if(osticky){
if(otimerid > 0){
clearTimeout(otimerid);
otimerid=0;
}
oshowingsticky=1;
oremovecounter=0;
}
layerWrite(layerhtml);
if(oautostatus > 0){
ostatus=otext;
if(oautostatus > 1){
ostatus=ocap;
}
}
oallowmove=0;
if(otimeout > 0){
if(otimerid > 0)clearTimeout(otimerid);
otimerid=setTimeout("cClick()", otimeout);
}
disp(ostatus);
if(osticky)oallowmove=0;
return(ostatus !='');
}
function ol_content_simple(text){
if(ocss==CSSCLASS)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 class=\""+obgclass+"\"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 class=\""+ofgclass+"\"><TR><TD VALIGN=TOP><FONT class=\""+otextfontclass+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
if(ocss==CSSSTYLE)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 style=\"background-color: "+obgcolor+";height: "+oheight+oheightunit+";\"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 style=\"color: "+ofgcolor+";background-color: "+ofgcolor+";height: "+oheight+oheightunit+";\"><TR><TD VALIGN=TOP><FONT style=\"font-family: "+otextfont+";color: "+otextcolor+";font-size: "+otextsize+otextsizeunit+";text-decoration: "+otextdecoration+";font-weight: "+otextweight+";font-style:"+otextstyle+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
if(ocss==CSSOFF)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 "+obgcolor+" "+oheight+"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 "+ofgcolor+" "+ofgbackground+" "+oheight+"><TR><TD VALIGN=TOP><FONT FACE=\""+otextfont+"\" COLOR=\""+otextcolor+"\" SIZE=\""+otextsize+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
set_background("");
return txt;
}
function ol_content_caption(text, title, close){
closing="";
closeevent="onMouseOver";
if(ocloseclick==1)closeevent="onClick";
if(ocapicon !="")ocapicon="<IMG SRC=\""+ocapicon+"\"> ";
if(close !=""){
if(ocss==CSSCLASS)closing="<TD ALIGN=RIGHT><A HREF=\"javascript:return "+fnRef+"cClick();\" "+closeevent+"=\"return " + fnRef + "cClick();\" class=\""+oclosefontclass+"\">"+close+"</A></TD>";
if(ocss==CSSSTYLE)closing="<TD ALIGN=RIGHT><A HREF=\"javascript:return "+fnRef+"cClick();\" "+closeevent+"=\"return " + fnRef + "cClick();\" style=\"color: "+oclosecolor+";font-family: "+oclosefont+";font-size: "+oclosesize+oclosesizeunit+";text-decoration: "+oclosedecoration+";font-weight: "+ocloseweight+";font-style:"+oclosestyle+";\">"+close+"</A></TD>";
if(ocss==CSSOFF)closing="<TD ALIGN=RIGHT><A HREF=\"javascript:return "+fnRef+"cClick();\" "+closeevent+"=\"return " + fnRef + "cClick();\"><FONT COLOR=\""+oclosecolor+"\" FACE=\""+oclosefont+"\" SIZE=\""+oclosesize+"\">"+close+"</FONT></A></TD>";
}
if(ocss==CSSCLASS)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 class=\""+obgclass+"\"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=0 CELLSPACING=0><TR><TD><FONT class=\""+ocaptionfontclass+"\">"+ocapicon+title+"</FONT></TD>"+closing+"</TR></TABLE><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 class=\""+ofgclass+"\"><TR><TD VALIGN=TOP><FONT class=\""+otextfontclass+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
if(ocss==CSSSTYLE)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 style=\"background-color: "+obgcolor+";background-image: url("+obgbackground+");height: "+oheight+oheightunit+";\"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=1 CELLSPACING=0 style=\"background-color: "+ocapbgcolor+";\"><TR><TD><FONT style=\"font-family: "+ocaptionfont+";color: "+ocapcolor+";font-size: "+ocaptionsize+ocaptionsizeunit+";font-weight: "+ocaptionweight+";font-style: "+ocaptionstyle+";text-decoration: " + ocaptiondecoration + ";\">"+ocapicon+title+"</FONT></TD>"+closing+"</TR></TABLE><TABLE HEIGHT=1 WIDTH=100% BORDER=0 CELLPADDING=0 CELLSPACING=0 style=\"background-color: "+obgcolor+";\"><TR><TD HEIGHT=1></TD></TR></TABLE><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 style=\"color: "+ofgcolor+";background-color: "+ofgcolor+";height: "+oheight+oheightunit+";\"><TR><TD VALIGN=TOP><FONT style=\"font-family: "+otextfont+";color: "+otextcolor+";font-size: "+otextsize+otextsizeunit+";text-decoration: "+otextdecoration+";font-weight: "+otextweight+";font-style:"+otextstyle+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
if(ocss==CSSOFF)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING="+oborder+" CELLSPACING=0 "+obgcolor+" "+obgbackground+" "+oheight+"><TR><TD><TABLE WIDTH=100% BORDER=0 CELLPADDING=0 CELLSPACING=0><TR><TD><B><FONT COLOR=\""+ocapcolor+"\" FACE=\""+ocaptionfont+"\" SIZE=\""+ocaptionsize+"\">"+ocapicon+title+"</FONT></B></TD>"+closing+"</TR></TABLE><TABLE WIDTH=100% BORDER=0 CELLPADDING=2 CELLSPACING=0 "+ofgcolor+" "+ofgbackground+" "+oheight+"><TR><TD VALIGN=TOP><FONT COLOR=\""+otextcolor+"\" FACE=\""+otextfont+"\" SIZE=\""+otextsize+"\">"+text+"</FONT></TD></TR></TABLE></TD></TR></TABLE>";
set_background("");
return txt;
}
function ol_content_background(text, picture, hasfullhtml){
var txt;
if(hasfullhtml){
txt=text;
}else{
var pU, hU, wU;
pU=(opadunit=='%' ? '%' : '');
hU=(oheightunit=='%' ? '%' : '');
wU=(owidthunit=='%' ? '%' : '');
if(ocss==CSSCLASS)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING=0 CELLSPACING=0 HEIGHT="+oheight+"><TR><TD COLSPAN=3 HEIGHT="+opadyt+"></TD></TR><TR><TD WIDTH="+opadxl+"></TD><TD VALIGN=TOP WIDTH="+(owidth-opadxl-opadxr)+"><FONT class=\""+otextfontclass+"\">"+text+"</FONT></TD><TD WIDTH="+opadxr+"></TD></TR><TR><TD COLSPAN=3 HEIGHT="+opadyb+"></TD></TR></TABLE>";
if(ocss==CSSSTYLE)txt="<TABLE WIDTH="+owidth+wU+" BORDER=0 CELLPADDING=0 CELLSPACING=0 HEIGHT="+oheight+hU+"><TR><TD COLSPAN=3 HEIGHT="+opadyt+pU+"></TD></TR><TR><TD WIDTH="+opadxl+pU+"></TD><TD VALIGN=TOP WIDTH="+(owidth-opadxl-opadxr)+pU+"><FONT style=\"font-family: "+otextfont+";color: "+otextcolor+";font-size: "+otextsize+otextsizeunit+";\">"+text+"</FONT></TD><TD WIDTH="+opadxr+pU+"></TD></TR><TR><TD COLSPAN=3 HEIGHT="+opadyb+pU+"></TD></TR></TABLE>";
if(ocss==CSSOFF)txt="<TABLE WIDTH="+owidth+" BORDER=0 CELLPADDING=0 CELLSPACING=0 HEIGHT="+oheight+"><TR><TD COLSPAN=3 HEIGHT="+opadyt+"></TD></TR><TR><TD WIDTH="+opadxl+"></TD><TD VALIGN=TOP WIDTH="+(owidth-opadxl-opadxr)+"><FONT FACE=\""+otextfont+"\" COLOR=\""+otextcolor+"\" SIZE=\""+otextsize+"\">"+text+"</FONT></TD><TD WIDTH="+opadxr+"></TD></TR><TR><TD COLSPAN=3 HEIGHT="+opadyb+"></TD></TR></TABLE>";
}
set_background(picture);
return txt;
}
function set_background(pic){
if(pic==""){
if(ns4)over.background.src=null;
if(ie4)over.backgroundImage="none";
if(ns6)over.style.backgroundImage="none";
}else{
if(ns4){
over.background.src=pic;
}else if(ie4){
over.backgroundImage="url("+pic+")";
}else if(ns6){
over.style.backgroundImage="url("+pic+")";
}
}
}
function disp(statustext){
if((ns4)||(ie4)||(ns6)){
if(oallowmove==0){
placeLayer();
showObject(over);
oallowmove=1;
}
}
if(statustext !=""){
self.status=statustext;
}
}
function placeLayer(){
var placeX, placeY;
if(ofixx > -1){
placeX=ofixx;
}else{
winoffset=(ie4)? eval('oframe.'+docRoot+'.scrollLeft'): oframe.pageXOffset;
if(ie4)iwidth=eval('oframe.'+docRoot+'.clientWidth');
if(ns4 || ns6)iwidth=oframe.innerWidth;
if(ohauto==1){
if((ox - winoffset)>((eval(iwidth))/ 2)){
ohpos=7;
}else{
ohpos=8;
}
}
if(ohpos==9){// Center
placeX=ox+ooffsetx-(owidth/2);
if(placeX < winoffset)placeX=winoffset;
}
if(ohpos==8){// Right
placeX=ox+ooffsetx;
if((eval(placeX)+ eval(owidth))>(winoffset + iwidth)){
placeX=iwidth + winoffset - owidth;
if(placeX < 0)placeX=0;
}
}
if(ohpos==7){// Left
placeX=ox-ooffsetx-owidth;
if(placeX < winoffset)placeX=winoffset;
}
if(osnapx > 1){
var snapping=placeX % osnapx;
if(ohpos==7){
placeX=placeX -(osnapx + snapping);
}else{
placeX=placeX +(osnapx - snapping);
}
if(placeX < winoffset)placeX=winoffset;
}
}
if(ofixy > -1){
placeY=ofixy;
}else{
scrolloffset=(ie4)? eval('oframe.'+docRoot+'.scrollTop'): oframe.pageYOffset;
if(ovauto==1){
if(ie4)iheight=eval('oframe.'+docRoot+'.clientHeight');
if(ns4 || ns6)iheight=oframe.innerHeight;
iheight=(eval(iheight))/ 2;
if((oy - scrolloffset)> iheight){
ovpos=35;
}else{
ovpos=36;
}
}
if(ovpos==35){
if(oaboveheight==0){
var divref=(ie4)? oframe.document.all['overDiv'] : over;
oaboveheight=(ns4)? divref.clip.height : divref.offsetHeight;
}
placeY=oy -(oaboveheight + ooffsety);
if(placeY < scrolloffset)placeY=scrolloffset;
}else{
placeY=oy + ooffsety;
}
if(osnapy > 1){
var snapping=placeY % osnapy;
if(oaboveheight > 0 && ovpos==35){
placeY=placeY -(osnapy + snapping);
}else{
placeY=placeY +(osnapy - snapping);
}
if(placeY < scrolloffset)placeY=scrolloffset;
}
}
repositionTo(over, placeX, placeY);
}
function mouseMove(e){
if((ns4)||(ns6)){ox=e.pageX;oy=e.pageY;}
if(ie4){ox=event.x;oy=event.y;}
if(ie5){ox=eval('event.x+oframe.'+docRoot+'.scrollLeft');oy=eval('event.y+oframe.'+docRoot+'.scrollTop');}
if(oallowmove==1){
placeLayer();
}
}
function cClick(){
hideObject(over);
oshowingsticky=0;
return false;
}
function compatibleframe(frameid){
if(ns4){
if(typeof frameid.document.overDiv=='undefined')return false;
}else if(ie4){
if(typeof frameid.document.all["overDiv"]=='undefined')return false;
}else if(ns6){
if(frameid.document.getElementById('overDiv')==null)return false;
}
return true;
}
function layerWrite(txt){
txt +="";
if(ns4){
var lyr=oframe.document.overDiv.document
lyr.write(txt)
lyr.close()
}else if(ie4){
oframe.document.all["overDiv"].innerHTML=txt
}else if(ns6){
range=oframe.document.createRange();
range.setStartBefore(over);
domfrag=range.createContextualFragment(txt);
while(over.hasChildNodes()){
over.removeChild(over.lastChild);
}
over.appendChild(domfrag);
}
}
function showObject(obj){
if(ns4)obj.visibility="show";
else if(ie4)obj.visibility="visible";
else if(ns6)obj.style.visibility="visible";
}
function hideObject(obj){
if(ns4)obj.visibility="hide";
else if(ie4)obj.visibility="hidden";
else if(ns6)obj.style.visibility="hidden";
if(otimerid > 0)clearTimeout(otimerid);
if(odelayid > 0)clearTimeout(odelayid);
otimerid=0;
odelayid=0;
self.status="";
}
function repositionTo(obj,xL,yL){
if((ns4)||(ie4)){
obj.left=(ie4 ? xL + 'px' : xL);
obj.top=(ie4 ? yL + 'px' : yL);
}else if(ns6){
obj.style.left=xL + "px";
obj.style.top=yL+ "px";
}
}
function getFrameRef(thisFrame, ofrm){
var retVal='';
for(var i=0;i<thisFrame.length;i++){
if(thisFrame[i].length > 0){
retVal=getFrameRef(thisFrame[i],ofrm);
if(retVal=='')continue;
}else if(thisFrame[i] !=ofrm)continue;
retVal='['+i+']' + retVal;
break;
}
return retVal;
}
function opt_FRAME(frm){
oframe=compatibleframe(frm)? frm : ol_frame;
if(oframe !=ol_frame){
var tFrm=getFrameRef(top.frames, oframe);
var sFrm=getFrameRef(top.frames, ol_frame);
if(sFrm.length==tFrm.length){
l=tFrm.lastIndexOf('[');
if(l){
while(sFrm.substring(0,l)!=tFrm.substring(0,l))l=tFrm.lastIndexOf('[',l-1);
tFrm=tFrm.substr(l);
sFrm=sFrm.substr(l);
}
}
var cnt=0, p='', str=tFrm;
while((k=str.lastIndexOf('['))!=-1){
cnt++;
str=str.substring(0,k);
}
for(var i=0;i<cnt;i++)p=p + 'parent.';
fnRef=p + 'frames' + sFrm + '.';
}
if((ns4)||(ie4 ||(ns6))){
if(ns4)over=oframe.document.overDiv;
if(ie4)over=oframe.overDiv.style;
if(ns6)over=oframe.document.getElementById("overDiv");
}
return 0;
}
function opt_FUNCTION(callme){
otext=(callme ? callme():(ofunction ? ofunction(): 'No Function'));
return 0;
}

