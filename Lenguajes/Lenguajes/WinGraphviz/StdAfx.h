/****************************************************************************
 
    PROGRAM: StdAfx.h
 
    PURPOSE: include file for standard system include files,
			 or project specific include files that are used frequently,
			 but are changed infrequently
    FUNCTIONS:     
        
    COMMENTS:
        
 
****************************************************************************/


#if !defined(AFX_STDAFX_H__A5A7214F_9BD7_4CC2_9BA8_5D553667E7CB__INCLUDED_)
#define AFX_STDAFX_H__A5A7214F_9BD7_4CC2_9BA8_5D553667E7CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>

extern CComModule _Module;
#include <atlcom.h>
#include <stdio.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A5A7214F_9BD7_4CC2_9BA8_5D553667E7CB__INCLUDED)
