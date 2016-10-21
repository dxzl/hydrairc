// The GitHub Readme.md (as of 9/1/2015) says this entire project IS
// now under GPL and the OLD source-code license headers (below) are
// out-of-date! - Scott Swift

/*

  HydraIRC
  Copyright (C) 2002-2006 Dominic Clifton aka Hydra

  HydraIRC limited-use source license

  1) You can:
  1.1) Use the source to create improvements and bug-fixes to send to the
       author to be incorporated in the main program.
  1.2) Use it for review/educational purposes.

  2) You can NOT:
  2.1) Use the source to create derivative works. (That is, you can't release
       your own version of HydraIRC with your changes in it)
  2.2) Compile your own version and sell it.
  2.3) Distribute unmodified, modified source or compiled versions of HydraIRC
       without first obtaining permission from the author. (I want one place
       for people to come to get HydraIRC from)
  2.4) Use any of the code or other part of HydraIRC in anything other than 
       HydraIRC.
       
  3) All code submitted to the project:
  3.1) Must not be covered by any license that conflicts with this license 
       (e.g. GPL code)
  3.2) Will become the property of the author.

*/

// BEFORE DOING ANYTHING, read the README.txt files in:
// hydrairc\HydraIRC\atlmfc
// hydrairc\HydraIRC\ATLServer
// hydrairc\HydraIRC\wtl
// hydrairc\HydraIRC\libs\libxml2
// hydrairc\Installer

// You will need to download and install:
// Visual Studio 2015 Community: https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx
// ATLServer: https://atlserver.codeplex.com/downloads/get/11220
// WTL: http://sourceforge.net/projects/wtl/
// Windows 10 SDK (POSSIBLY): https://dev.windows.com/en-us/downloads/windows-10-sdk
// libxml2 "GNOME" version from github.com: https://github.com/GNOME/libxml2

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

//#define NOT_READ_THE_LICENSE
#ifdef NOT_READ_THE_LICENSE
#error ** You must read LICENSE.TXT **
#endif

//////////////////////////////////////////////////////////////////////////
//
// Configuration Options!
//

//Uncomment this for font script testing stuff, to be completed by Zann
//#define ZANN_FONTS

//Enables extra debug output
//#define VERBOSE_DEBUG

//Enables XP-Like menus
//Note: the context menus don't work right with this enabled due to the
//way that windows passes owner draw messages to the wrong windows.
//the implementation of the xp-like menus needs to be adjusted.
//--> this has now been fixed, but there's a maximized MDI window problem
//    to iron out first.
//--> additionally, checked items that have icons are not shown/drawn as
//    checked.
//#define USE_XPCOMMANDBAR

// Enables Tabbed MDI
#define USE_TABBEDMDI

//////////////////////////////////////////////////////////////////////////

// uncomment this when (and if) Hydra takes over my fork of HydraIRC (dxzl)
//#define RELEASE_VERSION

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <malloc.h>
#include <crtdbg.h>

#pragma once

// Change these values to use different versions
#define WINVER		0x0500
#define _WIN32_WINNT	0x0400 // only needed for WM_MOUSEWHEEL
#define _WIN32_IE	0x0501
#define _RICHEDIT_VER	0x0300 // 0x0300

#define _WTL_NO_CSTRING
//#define _WTL_NO_WTYPES

// ATL/GUI includes start here
#include <atlbase.h>
#include <atlstr.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlw.h>

#include <atlctrlx.h>
#include <atlsplit.h>

#include <atlmisc.h>

//#include <atlcom.h>

//#include <atlcoll.h>
//#include <atltypes.h>


#include <atlrx.h>  // RegExps

/////////////////////////////////////////////////////////////////////////
//
// 3rd Party Include Files
//

#include <FixedMDICommandBar.h>

#ifdef USE_XPCOMMANDBAR
#define _WTL_USE_MDI
#include <commandbarxp/atlctrlxp.h>
#include <commandbarxp/atlctrlxp2.h>
#endif

// Message pump for threads.
#include "asyncmessagepump.h"

// Tabs
#include "atlgdix.h"

#include "CustomTabCtrl.h"
#include "DotNetTabCtrl.h"
#include "TabbedFrame.h"

// Docking Windows
#include <DWAutoHide.h>
#include <sstream>
#include <sstate.h>
#include <dwstate.h>
#include <dbstate.h>
#include <DockingFrame.h>
#include <ExtDockingWindow.h>
#include <TabDockingBox.h>
#include <DockingFocus.h>
#include <VC7LikeCaption.h>

// Tabbed Docking Window (needs 3rd Party Tabs)
#include <TabbedDockingWindow.h>

#ifdef USE_TABBEDMDI
#define _TABBEDMDI_MESSAGES_EXTERN_REGISTER
#define _TABBEDMDI_MESSAGES_NO_WARN_ATL_MIN_CRT
#include "TabbedMDI.h"
#endif

// Dialog COntainer
#include <DlgContainer.h>

// Taskbar Icon Class (well, systray icon really...)
#include "taskbaricon.h"

// libxml
#include <libxml/parser.h>

// General Includes
#include <time.h>

// These are for using _open(), _write(), etc..
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>

// HydraIRC Stuff
#include <CList.h>
#include <CIDManager.h>
#include <CObjectManager.h>
#include <CBufferedFile.h>

// HydraControls
#include <HydraPaneContainer.h>
#include <HydraSplitter.h>

// Other WTL Misc controls
#include "gradientlabel\GradientLabel.h"

// Other GUI related items
#include <DropFileHandler.h>
