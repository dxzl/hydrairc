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

#include "StdAfx.h"
#include "HydraIRC.h"

CListener::CListener(CEventManager *pEventManager)
{
  Start(pEventManager);
}

CListener::CListener(void)
{
  m_pEventManager = NULL;
}

void CListener::Start(CEventManager *pEventManager)
{
  ATLASSERT(pEventManager); // passed a NULL
  m_pEventManager = pEventManager;
  m_pEventManager->AddListener(this);
}

void CListener::Stop(void)
{
  if (m_pEventManager)
    m_pEventManager->RemoveListener(this);
  m_pEventManager = NULL;
}

CListener::~CListener(void)
{
  Stop();
}
