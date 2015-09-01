#pragma once

template <bool t_bVertical = true>
// begin mod dxzl 8/2015
// this is to allow compilation with Visual Studio 2015's atlmfc library
//class CHydraSplitterWindowT : public CSplitterWindowImpl<CHydraSplitterWindowT<t_bVertical>, t_bVertical>
class CHydraSplitterWindowT : public CSplitterWindowT<t_bVertical>
// end mod dxzl 8/2015
{
public:
	DECLARE_WND_CLASS_EX(_T("WTL_HydraSplitterWindow"), CS_DBLCLKS, COLOR_WINDOW)

  // Overrides
  void DrawSplitterBar(CDCHandle dc)
  {
	  RECT rect;
	  if(GetSplitterBarRect(&rect))
	  {
		  dc.FillRect(&rect, COLOR_3DFACE);
		  // draw FLAT edge if needed
		  if((GetExStyle() & WS_EX_CLIENTEDGE) != 0)
			  dc.DrawEdge(&rect, EDGE_RAISED, BF_FLAT | t_bVertical ? (BF_LEFT | BF_RIGHT) : (BF_TOP | BF_BOTTOM));
	  }
  }

};

typedef CHydraSplitterWindowT<true>    CHydraSplitterWindow;
typedef CHydraSplitterWindowT<false>   CHydraHorSplitterWindow;
