/****************************************************************************
 
    PROGRAM: IBinaryImage.h
 
    PURPOSE: Handle Binary Image interface
 
    FUNCTIONS:		
        
    COMMENTS:
        
 
****************************************************************************/


#ifndef __BINARYIMAGE_H_
#define __BINARYIMAGE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBinaryImage
//##ModelId=3F78401D0036

class ATL_NO_VTABLE CBinaryImage :
            public CComObjectRootEx<CComMultiThreadModelNoCS>,
            public CComCoClass<CBinaryImage, &CLSID_BinaryImage>,
            public IDispatchImpl<IBinaryImage, &IID_IBinaryImage, &LIBID_WINGRAPHVIZLib>,
    public ISupportErrorInfoImpl< &IID_IBinaryImage > {

public:
    //##ModelId=3F78401D0075
    CBinaryImage() {
        m_pUnkMarshaler = NULL;
        m_buf = NULL;
        m_size = 0;
        m_Picture = NULL;
        //		m_size_left = 0;

    }

    //##ModelId=3F78401D0076
    ~CBinaryImage();

    //##ModelId=3F78401D0087
    CComPtr<IUnknown> m_pUnkMarshaler;




    DECLARE_REGISTRY_RESOURCEID(IDR_BINARYIMAGE)
    DECLARE_GET_CONTROLLING_UNKNOWN()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CBinaryImage)
    COM_INTERFACE_ENTRY (IBinaryImage)
    COM_INTERFACE_ENTRY (IDispatch)
    COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
    END_COM_MAP()
    // ISupportsErrorInfo
    //##ModelId=3F78401D008B
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

    //##ModelId=3F78401D0090
    HRESULT FinalConstruct() {
        return CoCreateFreeThreadedMarshaler(
                   GetControllingUnknown(), &m_pUnkMarshaler.p);
    }

    //##ModelId=3F78401D0091
    void FinalRelease() {
        m_pUnkMarshaler.Release();
    }


    // IBinaryImage

public:
    //##ModelId=3F78401D0092
    STDMETHOD(ToBase64String)(/*[out,retval]*/BSTR* Result);
    /*
    	STDMETHOD(Read)(void* pv,  ULONG cb,  ULONG* pcbRead);	
     
    	STDMETHOD(Write)(   void const* pv,  ULONG cb,  ULONG* pcbWritten);
     
    	STDMETHOD(Seek)(   LARGE_INTEGER dlibMove,  DWORD dwOrigin,  ULARGE_INTEGER* plibNewPosition);
     
    	STDMETHOD(SetSize)(   ULARGE_INTEGER libNewSize);
     
    	STDMETHOD(CopyTo)(   IStream* pstm,  ULARGE_INTEGER cb,  ULARGE_INTEGER* pcbRead,  ULARGE_INTEGER* pcbWritten);
     
    	STDMETHOD(Commit)(   DWORD grfCommitFlags);
     
    	STDMETHOD(Revert)();
     
    	STDMETHOD(LockRegion)(   ULARGE_INTEGER libOffset,  ULARGE_INTEGER cb,  DWORD dwLockType);
     
    	STDMETHOD(UnlockRegion)(   ULARGE_INTEGER libOffset,  ULARGE_INTEGER cb,  DWORD dwLockType);
     
    	STDMETHOD(Stat)(   STATSTG* pstatstg,  DWORD grfStatFlag);
     
    	STDMETHOD(Clone)(   IStream** ppstm);
    */

    //##ModelId=3F78401D009A
    STDMETHOD(get_Picture)(/*[out, retval]*/ IPictureDisp* *pVal);

    //##ModelId=3F78401D009D
    STDMETHOD(get_Type)(/*[out, retval]*/ BSTR *pVal);
    //##ModelId=3F78401D00A4
    STDMETHOD(Save)(/*[in]*/BSTR FilePath,/*[out,retval]*/VARIANT_BOOL * Result);
    //##ModelId=3F78401D00AE
    STDMETHOD(Dump)(/*[in]*/IStream * stream,/*[out,retval]*/VARIANT_BOOL * Result);
    //##ModelId=3F78401D00B2
    BOOL Load(FILE * pFile,char * ImageType);

private:
    //##ModelId=3F78401D00BA
    void setImageType(char * ImageType);

    //##ModelId=3F78401D00BC
    unsigned char * m_buf;
    //HGLOBAL m_buf;

    //##ModelId=3F78401D00C2
    ULONG m_size;
    //##ModelId=3DB2181002FF

    //##ModelId=3F78401D00C3
    char m_type[16];

    //##ModelId=3F78401D00CD
    IPictureDisp* m_Picture;
};

#endif //__BINARYIMAGE_H_
