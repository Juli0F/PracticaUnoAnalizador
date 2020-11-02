/****************************************************************************
 
    PROGRAM: IBinaryImage.cpp
 
    PURPOSE: COM Interface of image object.
 
    FUNCTIONS:
        
        
    COMMENTS:
        
 
****************************************************************************/

#include "stdafx.h"
#include "WinGraphviz.h"
#include "IBinaryImage.h"

#include "tools.h"
#include "ASSERT.H"

extern "C" unsigned char *base64_encode(const unsigned char *, int, int *);

void DebugPrintInt(short i) {
#ifdef _DEBUG
    char buf[20];
    _itoa(i,buf,10);
    MessageBox(NULL,buf,"debug",MB_OK);
#endif
}

/**
 * This function return IID_IBinaryImage.
 * 
 * @name : InterfaceSupportsErrorInfo
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D008B
STDMETHODIMP CBinaryImage::InterfaceSupportsErrorInfo(REFIID riid) {
    static const IID* arr[] = {
                                  &IID_IBinaryImage,
                              };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }

    return S_FALSE;
}

/**
 * This function return BOOL.
 * 
 * @name : Save
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D00A4
STDMETHODIMP CBinaryImage::Save(BSTR FilePath, VARIANT_BOOL * Result) {
    USES_CONVERSION;
    const char * pchPath = OLE2A(FilePath);

    FILE *stream;
    stream = fopen( pchPath, "wb" );

    if(! stream) {
        *Result = false;
        return S_FALSE;
    }

    fwrite( m_buf, sizeof(unsigned char ), m_size, stream );

    fclose( stream );

    *Result = true;

    return S_OK;
}

/**
 * This function return BOOL.
 * 
 * @name : Dump
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D00AE
STDMETHODIMP CBinaryImage::Dump(IStream * stream, VARIANT_BOOL * Result) {
    ULONG Written;

    if(stream && (m_size > 0)) {
        *Result = (VARIANT_BOOL)stream->Write(m_buf,m_size,&Written);
        return S_OK;

    } else {
        *Result = false;
        return S_OK;
    }

}

/**
 * This function return IPictureDisp.
 * 
 * @name : get_Picture
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D009A
STDMETHODIMP CBinaryImage::get_Picture(IPictureDisp* *Result) {
    //    if(strcmp(m_type,"gif")==0){

    LPVOID pvData = NULL;
    // alloc memory based on file size
    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, m_size);
    _ASSERTE(NULL != hGlobal);

    pvData = GlobalLock(hGlobal);
    _ASSERTE(NULL != pvData);

    _ASSERTE(NULL != hGlobal);

    _ASSERTE(NULL != m_buf);

    memcpy(pvData,m_buf,m_size);

    GlobalUnlock(hGlobal);

    LPSTREAM pstm = NULL;

    BOOL bSuccess = FALSE;

    bSuccess = SUCCEEDED(::CreateStreamOnHGlobal(hGlobal, TRUE, &pstm));

    //		if (m_Picture)
    //			m_Picture->Release();

    bSuccess = SUCCEEDED(::OleLoadPicture(pstm, m_size , TRUE, IID_IPictureDisp, (LPVOID *)&m_Picture));

    pstm->Release();

    *Result = m_Picture;

    return S_OK;
}

/**
 * This function return BSTR.
 * 
 * @name : get_Type
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D009D
STDMETHODIMP CBinaryImage::get_Type(BSTR *Result) {
    // TODO: Add your implementation code here
    USES_CONVERSION;

    if(m_size)
        *Result = A2BSTR(m_type);
    else
        *Result = A2BSTR("");

    return S_OK;
}

/**
 * This function return BOOL.
 * 
 * @name : Load
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D00B2
BOOL CBinaryImage::Load(FILE * pFile,char * ImageType) {

    if(!pFile)
        return false;

    int intSizeOfFile;

    intSizeOfFile = 0;

    fflush(pFile) ;

    intSizeOfFile = ftell(pFile) ;

    if(intSizeOfFile > 0) {

        m_buf =(unsigned char *) malloc(intSizeOfFile);

        if (m_buf) {
            memset(m_buf,0,intSizeOfFile);

            rewind(pFile);

            fread(m_buf,sizeof(unsigned char ), intSizeOfFile,pFile);

            m_size = intSizeOfFile;

            setImageType(ImageType);

        }
    }


    return true;
};

/**
 * This function sets the suffix of the image.
 * 
 * @name : setImageType
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D00BA
void CBinaryImage::setImageType(char * ImageType) {
    int sizeIn;
    sizeIn = sizeof(ImageType);

    int sizeSet;
    sizeSet = (sizeIn > 16) ? 16 : sizeIn;

    memcpy(m_type,ImageType,sizeSet);
}

/**
 * distructure CBinaryImage.
 * 
 * @name : ~CBinaryImage
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401D0076
CBinaryImage::~CBinaryImage() {
    if(m_buf)
        free(m_buf);
};


//##ModelId=3F78401D0092
STDMETHODIMP CBinaryImage::ToBase64String(BSTR *pString) {
    int len;
    char * string;
    int string_len;
    CComBSTR result;

    string = (char *)base64_encode(m_buf,m_size,&string_len);

    result.Append(T2BSTR(string));

    if(pString)
        SysFreeString(*pString);

    result.CopyTo( pString);

    free(string);

    return S_OK;
}
