	g_iMainContentFrameDeltaHeight= -135;
	mainDirDescription = "INDEX_DESCRIPTION";
	normalDescription = "_description";
	originalAllInheritance_List = "Simple, Inherited";

	// Cookie stuff //
	cookieName = "DoxyS";
	cookieNameStay = "DoxySstay";

	cookieInnerNamePage = "page"; // Used for innerName in cookie
	cookieInnerNameAllInheritance = "allInheritance";

	tabType_List = "_class,_member,_file,_namespace,_package,_page,_dir,_unit,_group,_examples,,_search,_statsindex,_statsgeneral,_statsmsg,_statsundoc";
	tabDefault_List = "_description,_description,_description,_description,_description,_description,_description,_description,_description,_description,INDEX_DESCRIPTION,_quickSearch,_description,_time,_progress,_structural";
	pageConnectLookFor_List = ",_maindirgraph,_dir,_dirgraph";
	pageConnectReplace_List = "_dir,_dirgraph,,_maindirgraph";
	tabExtention = ".html";

	var today = new Date();
	var expires = ''
	var expiresYear = new Date(today.getTime() + (365 * 86400000)); // One year
function Body1()
{
document.write("<link rel=\"stylesheet\" type=\"text/css\" href=\"" + relPathToCommmon + loadStyleSheet() + "\">");
document.write("</HEAD>\n");
document.write("<BODY MARGINWIDTH=0 MARGINHEIGHT=0>\n");
document.write("<div id=overDiv style=\"position:absolute; visibility:hidden; z-index:1000;\"><!-- overLIB --></div>\n");
document.write("<div class=\"headerBox\">\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 width=100%>\n");
document.write("<TR><TD nowrap>\n");
}
function Body2()
{
document.write("</TD>\n");
document.write("<TD width=100% align=right valign=bottom>\n");
document.write("<table cellspacing=0 cellpadding=0 border=0>\n");
document.write("<TR><TD><a href=\"#\" OnMouseOver=\"link('");
document.write(toSearchPage);
document.write("',this)\" class=\"showHideOtherLinks\">Search</A></TD></TR>\n");
document.write("<TR><TD>&nbsp;</TD></TR>\n");
document.write("</TABLE>\n");
document.write("</TD><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD></TR></table>\n");
document.write("</div>\n");
document.write("<div class=\"headerVSpaceToTab\"></div>\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 width=100%>\n");
document.write("<tr VALIGN=TOP align=left>\n");
}
function BodyLeftMenuStart()
{
document.write("<td nowrap>\n");
document.write("\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 width=100%>\n");
document.write("<tr><td nowrap>\n");
document.write("<div class=\"vSpaceLeftMenu\">\n");
document.write("<div class=\"frameLeftMenu\">\n");
}
function BodyLeftMenuEnd()
{
document.write("<div class=\"leftMenuAirBottom\">");
document.write("<img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" width=130 height=1>");
document.write("</div>\n");
document.write("</div>\n");
document.write("</div>\n");
document.write("</td></tr>\n");
document.write("	<tr><td align=center valign=top class=\"logo\">\n");
document.write("<img src=\"");
document.write(relPathToCommmon);
document.write("logo.gif");
document.write("\" border=0>");
document.write("</td></tr>\n");
document.write("</table>\n");
document.write("</td>\n");
}
function Body3()
{
document.write("<td width=100%>\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 width=100%><TR><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD><TD class=\"tabFix\">\n");
}
function Body4()
{
document.write("</TD><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD></TR></table>\n");
document.write("<div>\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 class=\"width\"><TR><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD><TD>\n");
document.write("<div id=\"MainContentFrame\" class=\"frame\" >\n");
}
function Body5()
{
document.write("</div>\n");
document.write("</TD><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD></TR></table>\n");
document.write("</div>\n");
document.write("<div class=\"doxygenFooter\">\n");
document.write("<table cellspacing=0 cellpadding=0 border=0 class=\"width\"><TR><TD align=right>\n");
document.write("<a href=\"http://www.doxys.dk\" class=\"generatedDoxygen\" onmouseover=\"overLibGeneratedByDoxyS();return overlib('Generated by DoxyS 1.1.5.0<br>Mon Feb 14 15:42 2022');\" onmouseout=\"return nd();\">Generated by DoxyS</A>\n");
document.write("</TD><TD class=\"sideIndent\"><img src=\"");
document.write(relPathToCommmon);
document.write("dot.gif\" class=\"sideIndent\"></TD></TR></table>\n");
document.write("</div>\n");
document.write("</td></tr>\n");
document.write("</table>\n");
}
function Body6()
{
document.write("</BODY>\n");
document.write("</HTML>\n");
onloadOrRefresh();
}

function Statistics(link, projectname, definitiontype, pagename, pagetype)
{
document.write("<img src=\"");
if(link == "") {
document.write(relPathToCommmon);
document.write("dot.gif");
}
else {
document.write(link);
document.write("?projectname=");
document.write(projectname);
document.write("&definitiontype=");
document.write(definitiontype);
document.write("&pagename=");
document.write(pagename);
document.write("&pagetype=");
document.write(pagetype);
}
document.write("\"");
document.write(" width=1 height=1 style=\"display: none;\">\n");
}
function Legend()
{
document.write("<div id=\"LegendHiden\">\n");
document.write("<div class=\"paragraph2\">");
document.write("<a href=\"javascript:hideElement( 'LegendHiden' );javascript:showElement( 'LegendShown' );\">");
document.write("<img src=\"");
document.write(relPathToCommmon);
document.write("expand.gif\" border=0></a>&nbsp;");
document.write("Legend");
document.write("</div>\n");
document.write("</div>\n");
document.write("<div id=\"LegendShown\" style=\"display:none;visibility:hidden\">\n");
document.write("<div class=\"paragraph2\">");
document.write("<a href=\"javascript:hideElement( 'LegendShown' );javascript:showElement( 'LegendHiden' );\">");
document.write("<img src=\"");
document.write(relPathToCommmon);
document.write("collapse.gif\" border=0></a>&nbsp;");
document.write("Legend");
document.write("</div>\n");
document.write("<div class=\"paddingMembers\">");
document.write("The boxes in the graph below have the following meaning:<ul><li class=\"legend\"><span class=\"legendColorBlackBox\">&nbsp;Test&nbsp;box&nbsp;</span> A filled black box represents the struct or class for which the graph is generated.<li class=\"legend\"><span class=\"legendColorBlack\">&nbsp;Test&nbsp;box&nbsp;</span> A box with a black border denotes a documented struct or class.<li class=\"legend\"><span class=\"legendColorGray\">&nbsp;Test&nbsp;box&nbsp;</span> A box with a grey border denotes an undocumented struct or class.<li class=\"legend\"><span class=\"legendColorRed\">&nbsp;Test&nbsp;box&nbsp;</span> A box with a red border denotes a documented struct or class forwhich not all inheritance/containment relations are shown. %A graph is truncated if it does not fit within the specified boundaries.</ul>The arrows have the following meaning:<ul><li class=\"legend\"><span class=\"legendColorDarkBlue\">&nbsp;</span> A dark blue arrow is used to visualize a public inheritance relation between two classes.<li class=\"legend\"><span class=\"legendColorDarkGreen\">&nbsp;</span> A dark green arrow is used for protected inheritance.<li class=\"legend\"><span class=\"legendColorDarkRed\">&nbsp;</span> A dark red arrow is used for private inheritance.<li class=\"legend\"><span class=\"legendColorPurple\">&nbsp;</span> A purple dashed arrow is used if a class is contained or used by another class. The arrow is labeled with the variable(s) through which the pointed class or struct is accessible.<li class=\"legend\"><span class=\"legendColorDarkYellow\">&nbsp;</span> A yellow dashed arrow denotes a relation between a template instance and the template class it was instantiated from. The arrow is labeled with the template parameters of the instance.</ul>");
document.write("<div>");
document.write("<img src=\"");
document.write(relPathToCommmon);
document.write("graph_legend.");
document.write("png");
document.write("\" border=0>");
document.write("</div>");
document.write("</div>\n");
document.write("</div>\n");
document.write("<div class=\"contentAirBottom\"></div>\n");
}