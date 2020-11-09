/****************************************************************************
 
    PROGRAM: WinGraphviz.cpp
 
    PURPOSE: Implementation of DLL Exports.
 
    FUNCTIONS:		
		DllMain()
		DllCanUnloadNow()
		DllGetClassObject()
		DllRegisterServer()
		DllUnregisterServer()
      
    COMMENTS:
 
		Note: Proxy/Stub Information
		To build a separate proxy/stub DLL, 
		run nmake -f WinGraphvizps.mk in the project directory.
      
 
****************************************************************************/

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "WinGraphviz.h"

#include "WinGraphviz_i.c"
#include "IDOT.h"
#include "INEATO.h"
#include "IBinaryImage.h"
#include "ITWOPI.h"

extern "C" void dotneato_terminate2(void);

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_DOT, CDOT)
OBJECT_ENTRY(CLSID_NEATO, CNEATO)
OBJECT_ENTRY(CLSID_BinaryImage, CBinaryImage)
OBJECT_ENTRY(CLSID_TWOPI, CTWOPI)
END_OBJECT_MAP()

/**
 * DLL Entry Point.
 * 
 * @name : DllMain
 * @author 
 * @version 
 */

extern "C"
    BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        _Module.Init(ObjectMap, hInstance, &LIBID_WINGRAPHVIZLib);
        DisableThreadLibraryCalls(hInstance);

    } else if (dwReason == DLL_THREAD_ATTACH) {
        dotneato_terminate2();

    } else if (dwReason == DLL_THREAD_DETACH) {
        dotneato_terminate2();

    } else if (dwReason == DLL_PROCESS_DETACH) {
        dotneato_terminate2();
        _Module.Term();
    }

    return TRUE;    // ok
}

/**
 * Used to determine whether the DLL can be unloaded by OLE.
 * 
 * @name : DllCanUnloadNow
 * @author 
 * @version 
 */
STDAPI DllCanUnloadNow(void) {
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/**
 * Returns a class factory to create an object of the requested type.
 * 
 * @name : DllGetClassObject
 * @author 
 * @version 
 */
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) {
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/**
 * Adds entries to the system registry.
 * 
 * @name : DllRegisterServer
 * @author 
 * @version 
 */
STDAPI DllRegisterServer(void) {
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/**
 * Removes entries from the system registry.
 * 
 * @name : DllUnregisterServer
 * @author 
 * @version 
 */
STDAPI DllUnregisterServer(void) {
    return _Module.UnregisterServer(TRUE);
}


