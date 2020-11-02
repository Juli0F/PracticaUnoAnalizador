/****************************************************************************
 
    PROGRAM: INEATO.h
 
    PURPOSE: Handle NEATO (undirected graph) interface
 
    FUNCTIONS:		
        
    COMMENTS:
        
 
****************************************************************************/


#ifndef __NEATO_H_
#define __NEATO_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNEATO
//##ModelId=3F78401C0215

class ATL_NO_VTABLE CNEATO :
            public CComObjectRootEx<CComSingleThreadModel>,
            public CComCoClass<CNEATO, &CLSID_NEATO>,
            public IDispatchImpl<INEATO, &IID_INEATO, &LIBID_WINGRAPHVIZLib>,
            public ISupportErrorInfoImpl< &IID_INEATO >
{

public:
    //##ModelId=3F78401C0249
    CNEATO() {
        m_codepage = GetOEMCP();
    }

    DECLARE_REGISTRY_RESOURCEID(IDR_NEATO)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CNEATO)
    COM_INTERFACE_ENTRY(INEATO)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    // ISupportsErrorInfo
    //##ModelId=3F78401C024A
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

    // INEATO

public:
    //##ModelId=3F78401C0251
    STDMETHOD(ToEMF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0255
    STDMETHOD(get_Codepage)(/*[out, retval]*/ long *pVal);
    //##ModelId=3F78401C025D
    STDMETHOD(put_Codepage)(/*[in]*/ long newVal);
    //##ModelId=3F78401C0260
    STDMETHOD(ToJPEG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0267
    STDMETHOD(ToWBMP)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C026B
    STDMETHOD(ToISMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C0272
    STDMETHOD(ToIMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C0279
    STDMETHOD(ToCMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C027D
    STDMETHOD(ToBinaryGraph)(/*[in]*/BSTR Source , /*[in]*/long Type,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C0284
    STDMETHOD(ToVRML)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);

    //##ModelId=3F78401C028D
    STDMETHOD(ToSVGZ)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C0291
    STDMETHOD(ToPNG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C029A
    STDMETHOD(ToGIF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* *Result);

    //##ModelId=3F78401C02A3
    STDMETHOD(ToPS)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);

    //##ModelId=3F78401C02AC
    STDMETHOD(Validate)(/*[in]*/BSTR Source,/*[out,retval]*/VARIANT_BOOL* Result);
    //##ModelId=3F78401C02B5
    STDMETHOD(ToSvg)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C02BF
    STDMETHOD(ToPlainExt)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C02C9
    STDMETHOD(ToPlain)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C02D3
    STDMETHOD(ToDot)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C02DD
    STDMETHOD(ToCanon)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C02E7
    STDMETHOD(ToTextGraph)(/*[in]*/BSTR Source,/*[in]*/long Type,/*[out,retval]*/BSTR * Result);

private:
    //##ModelId=3F78401C02FB
    long m_codepage ;
};

#endif //__NEATO_H_
