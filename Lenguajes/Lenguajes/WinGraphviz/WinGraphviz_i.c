

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sun Dec 17 05:42:40 2006
 */
/* Compiler settings for .\WinGraphviz.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IBinaryImage,0xFFF6CEBE,0xBD9B,0x4C3A,0xA2,0x74,0x12,0xE6,0x00,0xB6,0xBD,0x10);


MIDL_DEFINE_GUID(IID, IID_IDOT,0xA1080582,0xD33F,0x486E,0xBD,0x5F,0x58,0x19,0x89,0xA3,0xC7,0xE9);


MIDL_DEFINE_GUID(IID, IID_INEATO,0xB41D4C33,0x882C,0x4534,0x83,0x52,0xEE,0x98,0x13,0x23,0xCD,0x96);


MIDL_DEFINE_GUID(IID, IID_ITWOPI,0xB22DD1A2,0x6884,0x47AA,0x9C,0xAA,0x8E,0x35,0xC1,0x15,0x4A,0x5C);


MIDL_DEFINE_GUID(IID, LIBID_WINGRAPHVIZLib,0x052DB09C,0x95F7,0x43BD,0xB7,0xF8,0x49,0x23,0x73,0xD1,0x15,0x1E);


MIDL_DEFINE_GUID(CLSID, CLSID_DOT,0x55811839,0x47B0,0x4854,0x81,0xB5,0x0A,0x00,0x31,0xB8,0xAC,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_NEATO,0x1F25D86C,0x95BC,0x4E33,0xA1,0x77,0xEE,0x8D,0xAB,0xEF,0x8B,0x04);


MIDL_DEFINE_GUID(CLSID, CLSID_BinaryImage,0x6B3F62C8,0x80CE,0x470D,0xB2,0xE4,0x0B,0xA4,0x2A,0x03,0x52,0x28);


MIDL_DEFINE_GUID(CLSID, CLSID_TWOPI,0x684811FB,0x0523,0x420F,0x9E,0x8F,0xA5,0x45,0x2C,0x65,0xA1,0x9C);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



