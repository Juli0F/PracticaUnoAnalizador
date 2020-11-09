/****************************************************************************
 
    PROGRAM: IDOT.h
 
    PURPOSE: Handle DOT (directed graph) interface
 
    FUNCTIONS:		
        
    COMMENTS:
        
 
****************************************************************************/


#ifndef __IDOT_H_
#define __IDOT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDOT
//##ModelId=3F78401C0319

class ATL_NO_VTABLE CDOT :
            public CComObjectRootEx<CComSingleThreadModel>,
            public CComCoClass<CDOT, &CLSID_DOT>,
            public IDispatchImpl<IDOT, &IID_IDOT, &LIBID_WINGRAPHVIZLib>,
            public ISupportErrorInfoImpl< &IID_IDOT >
{

public:
    //##ModelId=3F78401C034E
    CDOT() {
        m_codepage = GetOEMCP();
    }



    DECLARE_REGISTRY_RESOURCEID(IDR_DOT)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CDOT)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(IDOT)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    // ISupportsErrorInfo
    //##ModelId=3F78401C034F
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

    // IDOT

public:
    //##ModelId=3F78401C0355
    STDMETHOD(ToEMF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C035F
    STDMETHOD(get_Codepage)(/*[out, retval]*/ long *pVal);
    //##ModelId=3F78401C0362
    STDMETHOD(put_Codepage)(/*[in]*/ long newVal);
    //##ModelId=3F78401C0369
    STDMETHOD(ToJPEG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C036D
    STDMETHOD(ToWBMP)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0374
    STDMETHOD(ToISMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C0378
    STDMETHOD(ToIMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C037F
    STDMETHOD(ToCMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);

    //##ModelId=3F78401C0383
    STDMETHOD(ToBinaryGraph)(/*[in]*/BSTR Source , /*[in]*/long Type,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C038B
    STDMETHOD(ToVRML)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);

    //##ModelId=3F78401C0393
    STDMETHOD(ToSVGZ)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C039D
    STDMETHOD(ToPNG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C03A6
    STDMETHOD(ToGIF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C03B0
    STDMETHOD(ToPS)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);

    //##ModelId=3F78401C03BA
    STDMETHOD(Validate)(/*[in]*/BSTR Source,/*[out,retval]*/VARIANT_BOOL* Result);
    //##ModelId=3F78401C03C4
    STDMETHOD(ToSvg)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C03CE
    STDMETHOD(ToPlainExt)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C03D8
    STDMETHOD(ToPlain)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C03E2
    STDMETHOD(ToCanon)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401D0004
    STDMETHOD(ToDot)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401D000E
    STDMETHOD(ToTextGraph)(/*[in]*/BSTR Source , /*[in]*/long Type,/*[out,retval]*/BSTR* Result);

private:
    //##ModelId=3F78401D0022
    char m_err[255] ;
    //##ModelId=3F78401D0023
    long m_codepage ;
};

#endif //__DOT_H_
