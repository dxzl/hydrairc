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

#pragma once

template<class T, class TBase = CEdit, class TWinTraits = CControlWinTraits>
class ATL_NO_VTABLE CUsefulEditImpl	: public CWindowImpl<T, TBase, TWinTraits>
{
public:
  BOOL m_IgnoreInput;

  DECLARE_WND_SUPERCLASS(NULL, TBase::GetWndClassName())
	BEGIN_MSG_MAP(CUsefulEdit)
    MESSAGE_HANDLER(WM_CHAR, OnChar)
  END_MSG_MAP()


  LRESULT OnChar(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
  {
    //bHandled is TRUE to start with..
    if (!m_IgnoreInput)
      bHandled = FALSE;
    return FALSE;
  } 

	CUsefulEditImpl()
  {
    m_IgnoreInput = FALSE;
  }

  void IgnoreInput(BOOL Ignore = TRUE)
  {
    m_IgnoreInput = Ignore;
  }

};

class CUsefulEdit : public CUsefulEditImpl<CUsefulEdit>
{
public:
	DECLARE_WND_CLASS(_T("WTL_UsefulEdit"));
};
