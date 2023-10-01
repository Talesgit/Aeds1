function WriteLeftMenu(divID, aID, divClassName, aClassName)
{
document.write("<div id=\"divID144\" class=\"headerLeftMenuInActive\"><a id=\"aID144\" href=\"#\" OnMouseOver=\"link('_dir','karel_hpp_doc0',this)\" class=\"leftMenuLinkHeadInActive\">karel_hpp_doc</a></div>\n");
document.write("<div id='leftmenutree' class='treeLeftMenu'>\n");
var treeLeftMenu = new TreeClass('treeLeftMenu', false);
treeLeftMenu.setTreeHeightDelta(-205);
treeLeftMenu.m_iDefaultExpandedLevel = 1;treeLeftMenu.setExpandCollapseNames('Expand All','Collapse All');
treeLeftMenu.startTree( true );
  treeLeftMenu.startParentNode('Default mainpage','"#"','','../common/directoryBlue', { "onmouseover":"link('','../index',this);" });
  treeLeftMenu.startParentNode('karel_hpp_doc','"#"','','../common/directoryBlue', { "onmouseover":"link('_dir','karel_hpp_doc0',this);" });
  treeLeftMenu.startParentNode('Classes','"#"','','../common/classesBlue');
  treeLeftMenu.addNode('Box','"#"','','../common/class', { "onmouseover":"link('_class','Box0',this);" });
  treeLeftMenu.addNode('Robot','"#"','','../common/class', { "onmouseover":"link('_class','Robot0',this);" });
  treeLeftMenu.addNode('World','"#"','','../common/class', { "onmouseover":"link('_class','World0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Functions','"#"','','../common/functionsBlue');
  treeLeftMenu.addNode('clreol','"#"','','../common/function', { "onmouseover":"link('_member','clreol122',this);" });
  treeLeftMenu.addNode('clrscr','"#"','','../common/function', { "onmouseover":"link('_member','clrscr122',this);" });
  treeLeftMenu.addNode('delay','"#"','','../common/function', { "onmouseover":"link('_member','delay243606788',this);" });
  treeLeftMenu.addNode('fatal_Error','"#"','','../common/function', { "onmouseover":"link('_member','fatal_Error86138908',this);" });
  treeLeftMenu.addNode('get_Error','"#"','','../common/function', { "onmouseover":"link('_member','get_Error122',this);" });
  treeLeftMenu.addNode('gotoxy','"#"','','../common/function', { "onmouseover":"link('_member','gotoxy231090242',this);" });
  treeLeftMenu.addNode('has_Error','"#"','','../common/function', { "onmouseover":"link('_member','has_Error122',this);" });
  treeLeftMenu.addNode('set_Error','"#"','','../common/function', { "onmouseover":"link('_member','set_Error60979',this);" });
  treeLeftMenu.addNode('set_Speed','"#"','','../common/function', { "onmouseover":"link('_member','set_Speed60979',this);" });
  treeLeftMenu.addNode('show_Board','"#"','','../common/function', { "onmouseover":"link('_member','show_Board252067370',this);" });
  treeLeftMenu.addNode('show_Error','"#"','','../common/function', { "onmouseover":"link('_member','show_Error189216495',this);" });
  treeLeftMenu.addNode('show_Screen','"#"','','../common/function', { "onmouseover":"link('_member','show_Screen246775574',this);" });
  treeLeftMenu.addNode('show_Text','"#"','','../common/function', { "onmouseover":"link('_member','show_Text189216495',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Attributes','"#"','','../common/attributesBlue');
  treeLeftMenu.addNode('baseDelay','"#"','','../common/variable', { "onmouseover":"link('_member','baseDelay0',this);" });
  treeLeftMenu.addNode('box_now','"#"','','../common/variable', { "onmouseover":"link('_member','box_now0',this);" });
  treeLeftMenu.addNode('debug_txt','"#"','','../common/variable', { "onmouseover":"link('_member','debug_txt0',this);" });
  treeLeftMenu.addNode('error_code','"#"','','../common/variable', { "onmouseover":"link('_member','error_code0',this);" });
  treeLeftMenu.addNode('error_txt','"#"','','../common/variable', { "onmouseover":"link('_member','error_txt0',this);" });
  treeLeftMenu.addNode('has_debug','"#"','','../common/variable', { "onmouseover":"link('_member','has_debug0',this);" });
  treeLeftMenu.addNode('has_Text','"#"','','../common/variable', { "onmouseover":"link('_member','has_Text0',this);" });
  treeLeftMenu.addNode('message','"#"','','../common/variable', { "onmouseover":"link('_member','message0',this);" });
  treeLeftMenu.addNode('msg_board','"#"','','../common/variable', { "onmouseover":"link('_member','msg_board0',this);" });
  treeLeftMenu.addNode('msg_txt','"#"','','../common/variable', { "onmouseover":"link('_member','msg_txt0',this);" });
  treeLeftMenu.addNode('robot_now','"#"','','../common/variable', { "onmouseover":"link('_member','robot_now0',this);" });
  treeLeftMenu.addNode('stepDelay','"#"','','../common/variable', { "onmouseover":"link('_member','stepDelay0',this);" });
  treeLeftMenu.addNode('world','"#"','','../common/variable', { "onmouseover":"link('_member','world0',this);" });
  treeLeftMenu.addNode('world_now','"#"','','../common/variable', { "onmouseover":"link('_member','world_now0',this);" });
treeLeftMenu.endParentNode();
  treeLeftMenu.startParentNode('Types','"#"','','../common/typesBlue');
  treeLeftMenu.addNode('ref_Box','"#"','','../common/type', { "onmouseover":"link('_member','ref_Box0',this);" });
  treeLeftMenu.addNode('ref_Robot','"#"','','../common/type', { "onmouseover":"link('_member','ref_Robot0',this);" });
  treeLeftMenu.addNode('ref_World','"#"','','../common/type', { "onmouseover":"link('_member','ref_World0',this);" });
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endParentNode();
treeLeftMenu.endTree();
treeLeftMenu.readStateFromCookie();
document.write("</div>\n");
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
