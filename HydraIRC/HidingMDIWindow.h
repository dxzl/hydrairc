// The GitHub Readme.md (as of 9/1/2015) says this entire project IS
// now under GPL and the OLD source-code license headers (below) are
// out-of-date! - Scott Swift
#pragma once
#include "atlframe.h"

class CHidingMDIWindow :
  public CMDIWindow
{
public:
	void MDIActivate(HWND hWndChildToActivate);
};
