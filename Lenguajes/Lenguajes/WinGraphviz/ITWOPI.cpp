/****************************************************************************
 
    PROGRAM: ITWOPI.cpp
 
    PURPOSE: COM Interface of twopi(circle graph) Engine.
 
    FUNCTIONS:
 
        ToTextGraph() - directed graph textformat output.
		ToBinaryGraph() - directed graph Binaryformat output.
        
    COMMENTS:
        
 
****************************************************************************/

#include "stdafx.h"
#include "WinGraphviz.h"
#include "ITWOPI.h"
#include "IBinaryImage.h"

#include "tools.h"

#include "ASSERT.H"


extern "C" int Output_lang;
extern "C" FILE * TWOPIRander(const char * pchCmd,char * pchType,long codepage);
extern "C" void dotneato_terminate2(void);

extern "C" BOOL isError();
extern "C" char * getErrMsg();
extern "C" void ResetErr();

void raiseCOMError(REFGUID IID,char * source,char * description);


/**
 * This function return IID_IDOT.
 * 
 * @name : InterfaceSupportsErrorInfo
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C0165
STDMETHODIMP CTWOPI::InterfaceSupportsErrorInfo(REFIID riid) {
    static const IID* arr[] = {
                                  &IID_IDOT,
                              };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }

    return S_FALSE;
}

/**
 * Support Text-Graph.
 * 
 * @name : ToTextGraph
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01F0
STDMETHODIMP CTWOPI::ToTextGraph(BSTR Source, long intType, BSTR *Result) {

    try {
        USES_CONVERSION;

        const char * pchCmd = OLE2T(Source);

        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_SVG :
                pFile = TWOPIRander(pchCmd,"svg",m_codepage);
                break;

                case GRAPHVIZ_PS :
                pFile = TWOPIRander(pchCmd,"ps",m_codepage);
                break;

                case GRAPHVIZ_CMAP :
                pFile = TWOPIRander(pchCmd,"cmap",m_codepage);
                break;

                case GRAPHVIZ_ISMAP :
                pFile = TWOPIRander(pchCmd,"ismap",m_codepage);
                break;

                case GRAPHVIZ_IMAP :
                pFile = TWOPIRander(pchCmd,"imap",m_codepage);
                break;

                case GRAPHVIZ_ATTRIBUTED_DOT :
                pFile = TWOPIRander(pchCmd,"dot",m_codepage);
                break;

                case GRAPHVIZ_CANONICAL_DOT :
                pFile = TWOPIRander(pchCmd,"canon",m_codepage);
                break;

                case GRAPHVIZ_PLAIN	:
                pFile = TWOPIRander(pchCmd,"plain",m_codepage);
                break;

                case GRAPHVIZ_PLAIN_EXT :
                pFile = TWOPIRander(pchCmd,"plain-ext",m_codepage);
                break;

                default:
                pFile = TWOPIRander(pchCmd,"dot",m_codepage);

        };

        if (isError())
            throw getErrMsg();

        if (!pFile)
            throw getErrMsg();

        if (!FILEtoBSTR(pFile,Result))
            throw "TWOPI internal error:FILEtoBSTR";

        dotneato_terminate2();

        return S_OK;

    } catch(char * errmsg) {
        raiseCOMError(IID_ITWOPI,"WinGraphviz.TWOPI",errmsg);

        dotneato_terminate2();

        return E_UNEXPECTED;
    }
}

/**
 * Support DOT-Graph.
 * 
 * @name : ToDot
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01E7
STDMETHODIMP CTWOPI::ToDot(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_ATTRIBUTED_DOT,Result);
}

/**
 * Support Canon.
 * 
 * @name : ToCanon
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01E3
STDMETHODIMP CTWOPI::ToCanon(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_CANONICAL_DOT,Result);
}

/**
 * Support Plain.
 * 
 * @name : ToPlain
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01D9
STDMETHODIMP CTWOPI::ToPlain(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_PLAIN,Result);
}

/**
 * Support PlainExt.
 * 
 * @name : ToPlainExt
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01D0
STDMETHODIMP CTWOPI::ToPlainExt(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_PLAIN_EXT,Result);
}

/**
 * Support SVG.
 * 
 * @name : ToSvg
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01C8
STDMETHODIMP CTWOPI::ToSvg(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_SVG,Result);
}

/**
 * check DOT Language.
 * 
 * @name : Validate
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01BF
STDMETHODIMP CTWOPI::Validate(BSTR Source, VARIANT_BOOL *Result) {
    BSTR * out = 0;
    HRESULT hr;
    hr = ToTextGraph(Source,GRAPHVIZ_ATTRIBUTED_DOT,out);

    if(SUCCEEDED(hr))
        *Result=  TRUE;
    else
        *Result=  FALSE;

    return hr;
}

/**
 * Support Post-Script.
 * 
 * @name : ToPS
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01BB
STDMETHODIMP CTWOPI::ToPS(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_PS,Result);
}

/**
 * Support GIF.
 * 
 * @name : ToGIF
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01B3
STDMETHODIMP CTWOPI::ToGIF(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_GIF,Result);
}

/**
 * Support PNG.
 * 
 * @name : ToPNG
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01AB
STDMETHODIMP CTWOPI::ToPNG(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_PNG,Result);
}

/**
 * Support SVGZ.
 * 
 * @name : ToSVGZ
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C01A7
STDMETHODIMP CTWOPI::ToSVGZ(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_SVGZ,Result);
}

/**
 * Support VRML.
 * 
 * @name : ToVRML
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C019F
STDMETHODIMP CTWOPI::ToVRML(BSTR Source, BSTR *Result) {

    return E_NOTIMPL;
}

/**
 * Support BinaryGraph.
 * 
 * @name : ToBinaryGraph
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C0198
STDMETHODIMP CTWOPI::ToBinaryGraph(BSTR Source, long intType, IBinaryImage **Result) {

    try {
        USES_CONVERSION;
        const char * pchCmd = OLE2T(Source);

        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_PNG :
                pFile = TWOPIRander(pchCmd,"png",m_codepage);
                break;

                case GRAPHVIZ_GIF :
                pFile = TWOPIRander(pchCmd,"gif",m_codepage);
                break;

                case GRAPHVIZ_SVGZ :
                pFile = TWOPIRander(pchCmd,"svgz",m_codepage);
                break;

                case GRAPHVIZ_WBMP :
                pFile = TWOPIRander(pchCmd,"wbmp",m_codepage);
                break;

                case GRAPHVIZ_JPEG :
                pFile = TWOPIRander(pchCmd,"jpg",m_codepage);
                break;

                default:
                pFile = TWOPIRander(pchCmd,"png",m_codepage);

        };

        if (isError())
            throw getErrMsg();

        if (!pFile)
            throw getErrMsg();

        CBinaryImage * pImg;

        *Result = NULL;

        CBinaryImage::CreateInstance(Result);

        pImg = (CBinaryImage *)*Result;



        switch(intType) {

                case GRAPHVIZ_PNG :
                pImg->Load(pFile,"png");
                break;

                case GRAPHVIZ_GIF :
                pImg->Load(pFile,"gif");
                break;

                case GRAPHVIZ_SVGZ :

                pImg->Load(pFile,"svgz");
                break;

                case GRAPHVIZ_WBMP :
                pImg->Load(pFile,"wbmp");
                break;

                case GRAPHVIZ_JPEG :
                pImg->Load(pFile,"jpg");
                break;

                default:
                pImg->Load(pFile,"png");

        };

        dotneato_terminate2();

        return S_OK;

    } catch(char * errmsg) {

        raiseCOMError(IID_ITWOPI,"WinGraphviz.TWOPI",errmsg);

        dotneato_terminate2();

        return E_UNEXPECTED;
    }
}

/**
 * Support client side image map.
 * 
 * @name : ToCMAP
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C0194
STDMETHODIMP CTWOPI::ToCMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_CMAP,Result);
}

/**
 * Support image map.
 * 
 * @name : ToIMAP
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C018D
STDMETHODIMP CTWOPI::ToIMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_IMAP,Result);
}

/**
 * Support server side image map.
 * 
 * @name : ToISMAP
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C0189
STDMETHODIMP CTWOPI::ToISMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_ISMAP,Result);
}

/**
 * Support wireless BMP.
 * 
 * @name : ToWBMP
 * @author ood Tsen
 * @version 0.1, 01/09/2003
 */
//##ModelId=3F78401C0182
STDMETHODIMP CTWOPI::ToWBMP(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_WBMP,Result);
}

/**
 * support JPEG.
 * 
 * @name : ToJPEG
 * @author ood Tsen
 * @version 0.1, 01/20/2003
 */
//##ModelId=3F78401C017B
STDMETHODIMP CTWOPI::ToJPEG(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_JPEG,Result);
}

//##ModelId=3F78401C0175
STDMETHODIMP CTWOPI::get_Codepage(long *pVal) {
    memcpy(pVal,&m_codepage,sizeof(m_codepage));

    return S_OK;
}

//##ModelId=3F78401C0178
STDMETHODIMP CTWOPI::put_Codepage(long newVal) {
    if(newVal > 0)
        m_codepage = newVal;

    return S_OK;
}

//##ModelId=3F78401C016B
STDMETHODIMP CTWOPI::ToEMF(BSTR Source, IBinaryImage **Result) {
    return ToBinaryGraph(Source,GRAPHVIZ_EMF,Result);

}
