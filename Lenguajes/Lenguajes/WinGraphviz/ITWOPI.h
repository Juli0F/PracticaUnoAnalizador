// ITWOPI.h : Declaration of the CTWOPI

#ifndef __TWOPI_H_
#define __TWOPI_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTWOPI
//##ModelId=3F78401C002A

class ATL_NO_VTABLE CTWOPI :
            public CComObjectRootEx<CComSingleThreadModel>,
            public CComCoClass<CTWOPI, &CLSID_TWOPI>,
            public IDispatchImpl<ITWOPI, &IID_ITWOPI, &LIBID_WINGRAPHVIZLib>,
    public ISupportErrorInfoImpl< &IID_ITWOPI > {

public:
    //##ModelId=3F78401C0164
    CTWOPI() {
        m_codepage = GetOEMCP();
    }

    DECLARE_REGISTRY_RESOURCEID(IDR_TWOPI)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CTWOPI)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    COM_INTERFACE_ENTRY(ITWOPI)
    COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    // ISupportsErrorInfo
    //##ModelId=3F78401C0165
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

    // ITWOPI

public:
    //##ModelId=3F78401C016B
    STDMETHOD(ToEMF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0175
    STDMETHOD(get_Codepage)(/*[out, retval]*/ long *pVal);
    //##ModelId=3F78401C0178
    STDMETHOD(put_Codepage)(/*[in]*/ long newVal);
    //##ModelId=3F78401C017B
    STDMETHOD(ToJPEG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0182
    STDMETHOD(ToWBMP)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C0189
    STDMETHOD(ToISMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C018D
    STDMETHOD(ToIMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C0194
    STDMETHOD(ToCMAP)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C0198
    STDMETHOD(ToBinaryGraph)(/*[in]*/BSTR Source , /*[in]*/long Type,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C019F
    STDMETHOD(ToVRML)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01A7
    STDMETHOD(ToSVGZ)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C01AB
    STDMETHOD(ToPNG)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C01B3
    STDMETHOD(ToGIF)(/*[in]*/BSTR Source,/*[out,retval]*/IBinaryImage* * Result);
    //##ModelId=3F78401C01BB
    STDMETHOD(ToPS)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01BF
    STDMETHOD(Validate)(/*[in]*/BSTR Source,/*[out,retval]*/VARIANT_BOOL* Result);
    //##ModelId=3F78401C01C8
    STDMETHOD(ToSvg)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01D0
    STDMETHOD(ToPlainExt)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01D9
    STDMETHOD(ToPlain)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01E3
    STDMETHOD(ToCanon)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01E7
    STDMETHOD(ToDot)(/*[in]*/BSTR Source,/*[out,retval]*/BSTR* Result);
    //##ModelId=3F78401C01F0
    STDMETHOD(ToTextGraph)(/*[in]*/BSTR Source , /*[in]*/long Type,/*[out,retval]*/BSTR* Result);

private:
    //##ModelId=3F78401C01F9
    long m_codepage ;
};

#endif //__TWOPI_H_
