#pragma once
#ifdef _WIN32
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "rpcrt4.lib")
#endif // _WIN32

//wxWidgets
#pragma warning(push)
#pragma warning(disable : 26812) //enums
#pragma warning(disable : 26495) //uninitialized variable
#pragma warning(disable : 26451) //arithmetic overflow
#pragma warning(disable : 26439) //nothrow
#pragma warning(disable : 28251) //WinMain
#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG

//from <wx/wxprec.h>
#include "wx/chartype.h"
#if defined(__WINDOWS__)
#include "wx/msw/wrapwin.h"
#include "wx/msw/private.h"
#endif
#if defined(__WXMSW__)
#include "wx/msw/wrapcctl.h"
#include "wx/msw/wrapcdlg.h"
#include "wx/msw/missing.h"
#endif
#include <wx/wx.h>
#include <wx/valnum.h>
#pragma warning(pop) 

#include <string>
