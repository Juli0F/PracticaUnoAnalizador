

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "WinGraphviz.h"

#define TYPE_FORMAT_STRING_SIZE   127                               
#define PROC_FORMAT_STRING_SIZE   1075                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBinaryImage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBinaryImage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDOT_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDOT_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO INEATO_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO INEATO_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITWOPI_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITWOPI_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Save */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter FilePath */

/* 24 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */

/* 30 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dump */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x22 ),	/* 34 */
/* 56 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 58 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter stream */

/* 66 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Parameter Result */

/* 72 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x9 ),	/* 9 */
/* 92 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 100 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 102 */	NdrFcShort( 0x1 ),	/* 1 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 108 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 112 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Picture */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0xa ),	/* 10 */
/* 128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 134 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 144 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 148 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToBase64String */

/* 156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0xb ),	/* 11 */
/* 164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 170 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 172 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 174 */	NdrFcShort( 0x1 ),	/* 1 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Result */

/* 180 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToTextGraph */


	/* Procedure ToTextGraph */


	/* Procedure ToTextGraph */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x7 ),	/* 7 */
/* 200 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 208 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 216 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Type */


	/* Parameter Type */


	/* Parameter Type */

/* 222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 228 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToDot */


	/* Procedure ToCanon */


	/* Procedure ToDot */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 256 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 258 */	NdrFcShort( 0x1 ),	/* 1 */
/* 260 */	NdrFcShort( 0x1 ),	/* 1 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 264 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 270 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToCanon */


	/* Procedure ToDot */


	/* Procedure ToCanon */

/* 282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x9 ),	/* 9 */
/* 290 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 296 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 298 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 300 */	NdrFcShort( 0x1 ),	/* 1 */
/* 302 */	NdrFcShort( 0x1 ),	/* 1 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 306 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 312 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToPlain */


	/* Procedure ToPlain */


	/* Procedure ToPlain */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0xa ),	/* 10 */
/* 332 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 340 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 342 */	NdrFcShort( 0x1 ),	/* 1 */
/* 344 */	NdrFcShort( 0x1 ),	/* 1 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 348 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 354 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToPlainExt */


	/* Procedure ToPlainExt */


	/* Procedure ToPlainExt */

/* 366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0xb ),	/* 11 */
/* 374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 380 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 382 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 384 */	NdrFcShort( 0x1 ),	/* 1 */
/* 386 */	NdrFcShort( 0x1 ),	/* 1 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 390 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 394 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 396 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 400 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToSvg */


	/* Procedure ToSvg */


	/* Procedure ToSvg */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0xc ),	/* 12 */
/* 416 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 422 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 424 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 426 */	NdrFcShort( 0x1 ),	/* 1 */
/* 428 */	NdrFcShort( 0x1 ),	/* 1 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 432 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 438 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Validate */


	/* Procedure Validate */


	/* Procedure Validate */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0xd ),	/* 13 */
/* 458 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x22 ),	/* 34 */
/* 464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 466 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x1 ),	/* 1 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 474 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 478 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 480 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToPS */


	/* Procedure ToPS */


	/* Procedure ToPS */

/* 492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0xe ),	/* 14 */
/* 500 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 508 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 512 */	NdrFcShort( 0x1 ),	/* 1 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 516 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 518 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 520 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 522 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 524 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 526 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToGIF */


	/* Procedure ToGIF */


	/* Procedure ToGIF */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0xf ),	/* 15 */
/* 542 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 548 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 550 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x1 ),	/* 1 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 558 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 564 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 568 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToPNG */


	/* Procedure ToPNG */


	/* Procedure ToPNG */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x10 ),	/* 16 */
/* 584 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 592 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x1 ),	/* 1 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 600 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 606 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 610 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToSVGZ */


	/* Procedure ToSVGZ */


	/* Procedure ToSVGZ */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x11 ),	/* 17 */
/* 626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 634 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x1 ),	/* 1 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 642 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 648 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToVRML */


	/* Procedure ToVRML */


	/* Procedure ToVRML */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x12 ),	/* 18 */
/* 668 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 676 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 680 */	NdrFcShort( 0x1 ),	/* 1 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 684 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 690 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToBinaryGraph */


	/* Procedure ToBinaryGraph */


	/* Procedure ToBinaryGraph */

/* 702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x13 ),	/* 19 */
/* 710 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 716 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 718 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x1 ),	/* 1 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 726 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 728 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 730 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Type */


	/* Parameter Type */


	/* Parameter Type */

/* 732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 738 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 742 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 746 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToCMAP */


	/* Procedure ToCMAP */


	/* Procedure ToCMAP */

/* 750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x14 ),	/* 20 */
/* 758 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 766 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 768 */	NdrFcShort( 0x1 ),	/* 1 */
/* 770 */	NdrFcShort( 0x1 ),	/* 1 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 774 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 778 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 780 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 784 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToIMAP */


	/* Procedure ToIMAP */


	/* Procedure ToIMAP */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x15 ),	/* 21 */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 806 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 808 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	NdrFcShort( 0x1 ),	/* 1 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 816 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 822 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 826 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 830 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToISMAP */


	/* Procedure ToISMAP */


	/* Procedure ToISMAP */

/* 834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x16 ),	/* 22 */
/* 842 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 850 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 852 */	NdrFcShort( 0x1 ),	/* 1 */
/* 854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 858 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 862 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 864 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 868 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToWBMP */


	/* Procedure ToWBMP */


	/* Procedure ToWBMP */

/* 876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x17 ),	/* 23 */
/* 884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 892 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x1 ),	/* 1 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 900 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 904 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 906 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToJPEG */


	/* Procedure ToJPEG */


	/* Procedure ToJPEG */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x18 ),	/* 24 */
/* 926 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 934 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x1 ),	/* 1 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 942 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 948 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Codepage */


	/* Procedure get_Codepage */


	/* Procedure get_Codepage */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x19 ),	/* 25 */
/* 968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x24 ),	/* 36 */
/* 974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 984 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Codepage */


	/* Procedure put_Codepage */


	/* Procedure put_Codepage */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1012 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */


	/* Parameter newVal */

/* 1020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ToEMF */


	/* Procedure ToEMF */


	/* Procedure ToEMF */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1048 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Source */


	/* Parameter Source */


	/* Parameter Source */

/* 1056 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1060 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter Result */


	/* Parameter Result */


	/* Parameter Result */

/* 1062 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1066 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xe ),	/* Offset= 14 (18) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (6) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x4 ),	/* 4 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffde ),	/* Offset= -34 (2) */
/* 38 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 40 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 42 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 44 */	NdrFcLong( 0xc ),	/* 12 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 54 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 56 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 58 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 60 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 62 */	NdrFcShort( 0x6 ),	/* Offset= 6 (68) */
/* 64 */	
			0x13, 0x0,	/* FC_OP */
/* 66 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (18) */
/* 68 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x4 ),	/* 4 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (64) */
/* 78 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 80 */	NdrFcShort( 0x2 ),	/* Offset= 2 (82) */
/* 82 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 84 */	NdrFcLong( 0x7bf80981 ),	/* 2079852929 */
/* 88 */	NdrFcShort( 0xbf32 ),	/* -16590 */
/* 90 */	NdrFcShort( 0x101a ),	/* 4122 */
/* 92 */	0x8b,		/* 139 */
			0xbb,		/* 187 */
/* 94 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 96 */	0x0,		/* 0 */
			0x30,		/* 48 */
/* 98 */	0xc,		/* 12 */
			0xab,		/* 171 */
/* 100 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 102 */	NdrFcShort( 0x2 ),	/* Offset= 2 (104) */
/* 104 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 106 */	NdrFcLong( 0xfff6cebe ),	/* -602434 */
/* 110 */	NdrFcShort( 0xbd9b ),	/* -16997 */
/* 112 */	NdrFcShort( 0x4c3a ),	/* 19514 */
/* 114 */	0xa2,		/* 162 */
			0x74,		/* 116 */
/* 116 */	0x12,		/* 18 */
			0xe6,		/* 230 */
/* 118 */	0x0,		/* 0 */
			0xb6,		/* 182 */
/* 120 */	0xbd,		/* 189 */
			0x10,		/* 16 */
/* 122 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 124 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf_WinGraphviz_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IBinaryImage, ver. 0.0,
   GUID={0xFFF6CEBE,0xBD9B,0x4C3A,{0xA2,0x74,0x12,0xE6,0x00,0xB6,0xBD,0x10}} */

#pragma code_seg(".orpc")
static const unsigned short IBinaryImage_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    42,
    84,
    120,
    156
    };

static const MIDL_STUBLESS_PROXY_INFO IBinaryImage_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IBinaryImage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBinaryImage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IBinaryImage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IBinaryImageProxyVtbl = 
{
    &IBinaryImage_ProxyInfo,
    &IID_IBinaryImage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IBinaryImage::Save */ ,
    (void *) (INT_PTR) -1 /* IBinaryImage::Dump */ ,
    (void *) (INT_PTR) -1 /* IBinaryImage::get_Type */ ,
    (void *) (INT_PTR) -1 /* IBinaryImage::get_Picture */ ,
    (void *) (INT_PTR) -1 /* IBinaryImage::ToBase64String */
};


static const PRPC_STUB_FUNCTION IBinaryImage_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBinaryImageStubVtbl =
{
    &IID_IBinaryImage,
    &IBinaryImage_ServerInfo,
    12,
    &IBinaryImage_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDOT, ver. 0.0,
   GUID={0xA1080582,0xD33F,0x486E,{0xBD,0x5F,0x58,0x19,0x89,0xA3,0xC7,0xE9}} */

#pragma code_seg(".orpc")
static const unsigned short IDOT_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    192,
    240,
    282,
    324,
    366,
    408,
    450,
    492,
    534,
    576,
    618,
    660,
    702,
    750,
    792,
    834,
    876,
    918,
    960,
    996,
    1032
    };

static const MIDL_STUBLESS_PROXY_INFO IDOT_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDOT_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDOT_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDOT_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IDOTProxyVtbl = 
{
    &IDOT_ProxyInfo,
    &IID_IDOT,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToTextGraph */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToDot */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToCanon */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToPlain */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToPlainExt */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToSvg */ ,
    (void *) (INT_PTR) -1 /* IDOT::Validate */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToPS */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToGIF */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToPNG */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToSVGZ */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToVRML */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToBinaryGraph */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToCMAP */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToIMAP */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToISMAP */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToWBMP */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToJPEG */ ,
    (void *) (INT_PTR) -1 /* IDOT::get_Codepage */ ,
    (void *) (INT_PTR) -1 /* IDOT::put_Codepage */ ,
    (void *) (INT_PTR) -1 /* IDOT::ToEMF */
};


static const PRPC_STUB_FUNCTION IDOT_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDOTStubVtbl =
{
    &IID_IDOT,
    &IDOT_ServerInfo,
    28,
    &IDOT_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: INEATO, ver. 0.0,
   GUID={0xB41D4C33,0x882C,0x4534,{0x83,0x52,0xEE,0x98,0x13,0x23,0xCD,0x96}} */

#pragma code_seg(".orpc")
static const unsigned short INEATO_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    192,
    240,
    282,
    324,
    366,
    408,
    450,
    492,
    534,
    576,
    618,
    660,
    702,
    750,
    792,
    834,
    876,
    918,
    960,
    996,
    1032
    };

static const MIDL_STUBLESS_PROXY_INFO INEATO_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &INEATO_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO INEATO_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &INEATO_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _INEATOProxyVtbl = 
{
    &INEATO_ProxyInfo,
    &IID_INEATO,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToTextGraph */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToCanon */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToDot */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToPlain */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToPlainExt */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToSvg */ ,
    (void *) (INT_PTR) -1 /* INEATO::Validate */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToPS */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToGIF */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToPNG */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToSVGZ */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToVRML */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToBinaryGraph */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToCMAP */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToIMAP */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToISMAP */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToWBMP */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToJPEG */ ,
    (void *) (INT_PTR) -1 /* INEATO::get_Codepage */ ,
    (void *) (INT_PTR) -1 /* INEATO::put_Codepage */ ,
    (void *) (INT_PTR) -1 /* INEATO::ToEMF */
};


static const PRPC_STUB_FUNCTION INEATO_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _INEATOStubVtbl =
{
    &IID_INEATO,
    &INEATO_ServerInfo,
    28,
    &INEATO_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ITWOPI, ver. 0.0,
   GUID={0xB22DD1A2,0x6884,0x47AA,{0x9C,0xAA,0x8E,0x35,0xC1,0x15,0x4A,0x5C}} */

#pragma code_seg(".orpc")
static const unsigned short ITWOPI_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    192,
    240,
    282,
    324,
    366,
    408,
    450,
    492,
    534,
    576,
    618,
    660,
    702,
    750,
    792,
    834,
    876,
    918,
    960,
    996,
    1032
    };

static const MIDL_STUBLESS_PROXY_INFO ITWOPI_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ITWOPI_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITWOPI_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ITWOPI_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _ITWOPIProxyVtbl = 
{
    &ITWOPI_ProxyInfo,
    &IID_ITWOPI,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToTextGraph */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToDot */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToCanon */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToPlain */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToPlainExt */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToSvg */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::Validate */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToPS */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToGIF */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToPNG */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToSVGZ */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToVRML */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToBinaryGraph */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToCMAP */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToIMAP */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToISMAP */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToWBMP */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToJPEG */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::get_Codepage */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::put_Codepage */ ,
    (void *) (INT_PTR) -1 /* ITWOPI::ToEMF */
};


static const PRPC_STUB_FUNCTION ITWOPI_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ITWOPIStubVtbl =
{
    &IID_ITWOPI,
    &ITWOPI_ServerInfo,
    28,
    &ITWOPI_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _WinGraphviz_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_INEATOProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDOTProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITWOPIProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBinaryImageProxyVtbl,
    0
};

const CInterfaceStubVtbl * _WinGraphviz_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_INEATOStubVtbl,
    ( CInterfaceStubVtbl *) &_IDOTStubVtbl,
    ( CInterfaceStubVtbl *) &_ITWOPIStubVtbl,
    ( CInterfaceStubVtbl *) &_IBinaryImageStubVtbl,
    0
};

PCInterfaceName const _WinGraphviz_InterfaceNamesList[] = 
{
    "INEATO",
    "IDOT",
    "ITWOPI",
    "IBinaryImage",
    0
};

const IID *  _WinGraphviz_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _WinGraphviz_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _WinGraphviz, pIID, n)

int __stdcall _WinGraphviz_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _WinGraphviz, 4, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _WinGraphviz, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _WinGraphviz, 4, *pIndex )
    
}

const ExtendedProxyFileInfo WinGraphviz_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _WinGraphviz_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _WinGraphviz_StubVtblList,
    (const PCInterfaceName * ) & _WinGraphviz_InterfaceNamesList,
    (const IID ** ) & _WinGraphviz_BaseIIDList,
    & _WinGraphviz_IID_Lookup, 
    4,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

