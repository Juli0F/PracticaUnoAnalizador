/****************************************************************************
 
    PROGRAM: stdAfx.cpp
 
    PURPOSE: source file that includes just the standard includes.
 
    FUNCTIONS:       
        
    COMMENTS:
 
		stdafx.pch will be the pre-compiled header
		stdafx.obj will contain the pre-compiled type information
       
 
****************************************************************************/

#include "stdafx.h"

#ifdef _ATL_STATIC_REGISTRY
#include <statreg.h>
#include <statreg.cpp>
#endif

#include <atlimpl.cpp>
