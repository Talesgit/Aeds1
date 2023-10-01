function WriteLeftMenu(divID, aID, divClassName, aClassName)
{
document.write("<div id=\"divID0\" class=\"headerLeftMenuInActive\"><a id=\"aID0\" href=\"#\" OnMouseOver=\"link('','index',this)\" class=\"leftMenuLinkHeadInActive\">Default mainpage</a></div>\n");
document.write("<div id='leftmenutree' class='treeLeftMenu'>\n");
var treeLeftMenu = new TreeClass('treeLeftMenu', false);
treeLeftMenu.setTreeHeightDelta(-205);
treeLeftMenu.m_iDefaultExpandedLevel = 1;treeLeftMenu.setExpandCollapseNames('Expand All','Collapse All');
treeLeftMenu.startTree( true );
  treeLeftMenu.startParentNode('Default mainpage','"#"','','common/directoryBlue', { "onmouseover":"link('','index',this);" });
  treeLeftMenu.startParentNode('karel_hpp_doc','"#"','','common/directoryBlue', { "onmouseover":"link('_dir','karel_hpp_doc/karel_hpp_doc0',this);" });
  treeLeftMenu.startParentNode('Classes','"#"','','common/classesBlue');
  treeLeftMenu.addNode('Box','"#"','','common/class', { "onmouseover":"link('_class','karel_hpp_doc/Box0',this);" });
  treeLeftMenu.addNode('Robot','"#"','','common/class', { "onmouseover":"link('_class','karel_hpp_doc/Robot0',this);" });
  treeLeftMenu.addNode('World','"#"','','common/class', { "onmouseover":"link('_class','karel_hpp_doc/World0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Functions','"#"','','common/functionsBlue');
  treeLeftMenu.addNode('clreol','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/clreol122',this);" });
  treeLeftMenu.addNode('clrscr','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/clrscr122',this);" });
  treeLeftMenu.addNode('delay','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/delay243606788',this);" });
  treeLeftMenu.addNode('fatal_Error','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/fatal_Error86138908',this);" });
  treeLeftMenu.addNode('get_Error','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/get_Error122',this);" });
  treeLeftMenu.addNode('gotoxy','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/gotoxy231090242',this);" });
  treeLeftMenu.addNode('has_Error','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/has_Error122',this);" });
  treeLeftMenu.addNode('set_Error','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/set_Error60979',this);" });
  treeLeftMenu.addNode('set_Speed','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/set_Speed60979',this);" });
  treeLeftMenu.addNode('show_Board','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/show_Board252067370',this);" });
  treeLeftMenu.addNode('show_Error','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/show_Error189216495',this);" });
  treeLeftMenu.addNode('show_Screen','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/show_Screen246775574',this);" });
  treeLeftMenu.addNode('show_Text','"#"','','common/function', { "onmouseover":"link('_member','karel_hpp_doc/show_Text189216495',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Attributes','"#"','','common/attributesBlue');
  treeLeftMenu.addNode('baseDelay','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/baseDelay0',this);" });
  treeLeftMenu.addNode('box_now','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/box_now0',this);" });
  treeLeftMenu.addNode('debug_txt','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/debug_txt0',this);" });
  treeLeftMenu.addNode('error_code','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/error_code0',this);" });
  treeLeftMenu.addNode('error_txt','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/error_txt0',this);" });
  treeLeftMenu.addNode('has_debug','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/has_debug0',this);" });
  treeLeftMenu.addNode('has_Text','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/has_Text0',this);" });
  treeLeftMenu.addNode('message','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/message0',this);" });
  treeLeftMenu.addNode('msg_board','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/msg_board0',this);" });
  treeLeftMenu.addNode('msg_txt','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/msg_txt0',this);" });
  treeLeftMenu.addNode('robot_now','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/robot_now0',this);" });
  treeLeftMenu.addNode('stepDelay','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/stepDelay0',this);" });
  treeLeftMenu.addNode('world','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/world0',this);" });
  treeLeftMenu.addNode('world_now','"#"','','common/variable', { "onmouseover":"link('_member','karel_hpp_doc/world_now0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Types','"#"','','common/typesBlue');
  treeLeftMenu.addNode('ref_Box','"#"','','common/type', { "onmouseover":"link('_member','karel_hpp_doc/ref_Box0',this);" });
  treeLeftMenu.addNode('ref_Robot','"#"','','common/type', { "onmouseover":"link('_member','karel_hpp_doc/ref_Robot0',this);" });
  treeLeftMenu.addNode('ref_World','"#"','','common/type', { "onmouseover":"link('_member','karel_hpp_doc/ref_World0',this);" });
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endTree();
treeLeftMenu.readStateFromCookie();
document.write("</div>\n");
document.write("<div class=\"paragraphLeftMenu\">Miscellaneous</div>\n");
document.write("<div id=\"divID24\" class=\"leftMenuTreeInActive\"><a id=\"aID24\" href=\"#\" OnMouseOver=\"link('_statsindex','common/statistics/index',this)\" class=\"leftMenuLinkInActive\">Statistics</a></div>\n");
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
