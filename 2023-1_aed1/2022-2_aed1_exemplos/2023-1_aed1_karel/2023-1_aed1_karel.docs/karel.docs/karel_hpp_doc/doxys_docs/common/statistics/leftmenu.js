function WriteLeftMenu(divID, aID, divClassName, aClassName)
{
document.write("<div id=\"divID24\" class=\"headerLeftMenuInActive\"><a id=\"aID24\" href=\"#\" OnMouseOver=\"link('_statsindex','index',this)\" class=\"leftMenuLinkHeadInActive\">Statistics</a></div>\n");
document.write("<div id='leftmenutree' class='treeLeftMenu'>\n");
var treeLeftMenu = new TreeClass('treeLeftMenu', false);
treeLeftMenu.setTreeHeightDelta(-205);
treeLeftMenu.m_iDefaultExpandedLevel = 1;treeLeftMenu.setExpandCollapseNames('Expand All','Collapse All');
treeLeftMenu.startTree( true );
  treeLeftMenu.startParentNode('Default mainpage','"#"','','../directoryBlue', { "onmouseover":"link('','../../index',this);" });
  treeLeftMenu.startParentNode('karel_hpp_doc','"#"','','../directoryBlue', { "onmouseover":"link('_dir','../../karel_hpp_doc/karel_hpp_doc0',this);" });
  treeLeftMenu.startParentNode('Classes','"#"','','../classesBlue');
  treeLeftMenu.addNode('Box','"#"','','../class', { "onmouseover":"link('_class','../../karel_hpp_doc/Box0',this);" });
  treeLeftMenu.addNode('Robot','"#"','','../class', { "onmouseover":"link('_class','../../karel_hpp_doc/Robot0',this);" });
  treeLeftMenu.addNode('World','"#"','','../class', { "onmouseover":"link('_class','../../karel_hpp_doc/World0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Functions','"#"','','../functionsBlue');
  treeLeftMenu.addNode('clreol','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/clreol122',this);" });
  treeLeftMenu.addNode('clrscr','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/clrscr122',this);" });
  treeLeftMenu.addNode('delay','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/delay243606788',this);" });
  treeLeftMenu.addNode('fatal_Error','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/fatal_Error86138908',this);" });
  treeLeftMenu.addNode('get_Error','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/get_Error122',this);" });
  treeLeftMenu.addNode('gotoxy','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/gotoxy231090242',this);" });
  treeLeftMenu.addNode('has_Error','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/has_Error122',this);" });
  treeLeftMenu.addNode('set_Error','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/set_Error60979',this);" });
  treeLeftMenu.addNode('set_Speed','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/set_Speed60979',this);" });
  treeLeftMenu.addNode('show_Board','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/show_Board252067370',this);" });
  treeLeftMenu.addNode('show_Error','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/show_Error189216495',this);" });
  treeLeftMenu.addNode('show_Screen','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/show_Screen246775574',this);" });
  treeLeftMenu.addNode('show_Text','"#"','','../function', { "onmouseover":"link('_member','../../karel_hpp_doc/show_Text189216495',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Attributes','"#"','','../attributesBlue');
  treeLeftMenu.addNode('baseDelay','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/baseDelay0',this);" });
  treeLeftMenu.addNode('box_now','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/box_now0',this);" });
  treeLeftMenu.addNode('debug_txt','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/debug_txt0',this);" });
  treeLeftMenu.addNode('error_code','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/error_code0',this);" });
  treeLeftMenu.addNode('error_txt','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/error_txt0',this);" });
  treeLeftMenu.addNode('has_debug','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/has_debug0',this);" });
  treeLeftMenu.addNode('has_Text','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/has_Text0',this);" });
  treeLeftMenu.addNode('message','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/message0',this);" });
  treeLeftMenu.addNode('msg_board','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/msg_board0',this);" });
  treeLeftMenu.addNode('msg_txt','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/msg_txt0',this);" });
  treeLeftMenu.addNode('robot_now','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/robot_now0',this);" });
  treeLeftMenu.addNode('stepDelay','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/stepDelay0',this);" });
  treeLeftMenu.addNode('world','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/world0',this);" });
  treeLeftMenu.addNode('world_now','"#"','','../variable', { "onmouseover":"link('_member','../../karel_hpp_doc/world_now0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Types','"#"','','../typesBlue');
  treeLeftMenu.addNode('ref_Box','"#"','','../type', { "onmouseover":"link('_member','../../karel_hpp_doc/ref_Box0',this);" });
  treeLeftMenu.addNode('ref_Robot','"#"','','../type', { "onmouseover":"link('_member','../../karel_hpp_doc/ref_Robot0',this);" });
  treeLeftMenu.addNode('ref_World','"#"','','../type', { "onmouseover":"link('_member','../../karel_hpp_doc/ref_World0',this);" });
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endTree();
treeLeftMenu.readStateFromCookie();
document.write("</div>\n");
document.write("<div class=\"paragraphLeftMenu\">Pages</div>\n");
document.write("<div id=\"divID145\" class=\"leftMenuTreeInActive\"><a id=\"aID145\" href=\"#\" OnMouseOver=\"link('_statsgeneral','stats_general',this)\" class=\"leftMenuLinkInActive\">General</a></div>\n");
document.write("<div id=\"divID146\" class=\"leftMenuTreeInActive\"><a id=\"aID146\" href=\"#\" OnMouseOver=\"link('_statsundoc','stats_undoc',this)\" class=\"leftMenuLinkInActive\">Undocumented</a></div>\n");
document.write("<div id=\"divID147\" class=\"leftMenuTreeInActive\"><a id=\"aID147\" href=\"#\" OnMouseOver=\"link('_statsmsg','stats_msg_msg',this)\" class=\"leftMenuLinkInActive\">Msg-Messages</a></div>\n");
document.write("<div id=\"divID148\" class=\"leftMenuTreeInActive\"><a id=\"aID148\" href=\"#\" OnMouseOver=\"link('_statsmsg','stats_msg_warn',this)\" class=\"leftMenuLinkInActive\">Msg-Warnings</a></div>\n");
document.write("<div id=\"divID149\" class=\"leftMenuTreeInActive\"><a id=\"aID149\" href=\"#\" OnMouseOver=\"link('_statsmsg','stats_msg_err',this)\" class=\"leftMenuLinkInActive\">Msg-Errors</a></div>\n");
document.write("<div id=\"divID150\" class=\"leftMenuTreeInActive\"><a id=\"aID150\" href=\"#\" OnMouseOver=\"link('_statsmsg','stats_msg_dbg',this)\" class=\"leftMenuLinkInActive\">Msg-Debug</a></div>\n");
if(divID != "" && aID != "")
{
  var elemDiv = document.getElementById(divID);
  var elemA = document.getElementById(aID);
  if (elemDiv != undefined && elemA != undefined ) { // this is needed to abvoid crashing js on some memberpages 
    elemDiv.className = divClassName;
    elemA.className = aClassName;
  }
}
}
