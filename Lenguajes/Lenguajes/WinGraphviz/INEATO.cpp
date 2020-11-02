/****************************************************************************
 
    PROGRAM: IDOT.cpp
 
    PURPOSE: COM Interface of Dot Engine.
 
    FUNCTIONS:
 
        ToTextGraph() - support dot textformat output
        
    COMMENTS:
        
 
****************************************************************************/

#include "stdafx.h"
#include "WinGraphviz.h"
#include "INEATO.h"
#include "IBinaryImage.h"

#include "tools.h"
#include "ASSERT.H"

extern "C" int Output_lang;
extern "C" FILE * NEATORander(const char * pchCmd,char * pchType,long codepage);
extern "C" void dotneato_terminate2(void);

extern "C" BOOL isError();
extern "C" char * getErrMsg();
extern "C" void ResetErr();

void raiseCOMError(REFGUID IID,char * source,char * description);

/**
 * This function return IID_INEATO.
 * 
 * @name : InterfaceSupportsErrorInfo
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401C024A
STDMETHODIMP CNEATO::InterfaceSupportsErrorInfo(REFIID riid) {
    static const IID* arr[] = {
                                  &IID_INEATO,
                              };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }

    return S_FALSE;
}

/**
 * support neato textformat output.
 * 
 * @name : ToTextGraph
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C02E7
STDMETHODIMP CNEATO::ToTextGraph(BSTR Source,long intType, BSTR *Result) {
    try {
        USES_CONVERSION;
        const char * pchCmd = OLE2T(Source);
        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_SVG :
                pFile = NEATORander(pchCmd,"svg",m_codepage);
                break;

                case GRAPHVIZ_PS :
                pFile = NEATORander(pchCmd,"ps",m_codepage);
                break;

                case GRAPHVIZ_CMAP :
                pFile = NEATORander(pchCmd,"cmap",m_codepage);
                break;

                case GRAPHVIZ_ISMAP :
                pFile = NEATORander(pchCmd,"ismap",m_codepage);
                break;

                case GRAPHVIZ_IMAP :
                pFile = NEATORander(pchCmd,"imap",m_codepage);
                break;

                case GRAPHVIZ_ATTRIBUTED_DOT :
                pFile = NEATORander(pchCmd,"dot",m_codepage);
                break;

                case GRAPHVIZ_CANONICAL_DOT :
                pFile = NEATORander(pchCmd,"canon",m_codepage);
                break;

                case GRAPHVIZ_PLAIN	:
                pFile = NEATORander(pchCmd,"plain",m_codepage);
                break;

                case GRAPHVIZ_PLAIN_EXT :
                pFile = NEATORander(pchCmd,"plain-ext",m_codepage);
                break;

                default:
                pFile = NEATORander(pchCmd,"dot",m_codepage);

        };

        if (isError())
            throw getErrMsg();

        if (!pFile)
            throw getErrMsg();

        if (!FILEtoBSTR(pFile,Result))
            throw "NEATO internal error:FILEtoBSTR";

        dotneato_terminate2();

        return S_OK;

    } catch(char * errmsg) {

        raiseCOMError(IID_INEATO,"WinGraphviz.NEATO",errmsg);

        dotneato_terminate2();

        return E_UNEXPECTED;
    }
}

/**
 * support directed graph dot-format output.
 * 
 * @name : ToDot
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C02D3
STDMETHODIMP CNEATO::ToDot(BSTR Source,BSTR* Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_ATTRIBUTED_DOT,Result);
}

/**
 * support directed graph canon-format output.
 * 
 * @name : ToCanon
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C02DD
STDMETHODIMP CNEATO::ToCanon(BSTR Source,BSTR* Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_CANONICAL_DOT,Result);
}

/**
 * support directed graph plain-format output.
 * 
 * @name : ToPlain
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C02C9
STDMETHODIMP CNEATO::ToPlain(BSTR Source, BSTR *Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_PLAIN,Result);
}

/**
 * support directed graph plain-ext format output.
 * 
 * @name : ToPlainExt
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C02BF
STDMETHODIMP CNEATO::ToPlainExt(BSTR Source, BSTR *Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_PLAIN_EXT,Result);
}

/**
 * support directed graph svg-format output.
 * 
 * @name : ToSvg
 * @author ood Tsen
 * @version 0.1, 09/11/2002
 */
//##ModelId=3F78401C02B5
STDMETHODIMP CNEATO::ToSvg(BSTR Source, BSTR *Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_SVG,Result);
}

/**
 * check DOT-language.
 * 
 * @name : Validate
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C02AC
STDMETHODIMP CNEATO::Validate(BSTR Source,VARIANT_BOOL* Result) {
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
 * support directed graph PostScript-format output.
 * 
 * @name : ToPS
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C02A3
STDMETHODIMP CNEATO::ToPS(BSTR Source,BSTR* Result) {
    // TODO: Add your implementation code here

    return ToTextGraph(Source,GRAPHVIZ_PS,Result);

}

/**
 * support directed graph GIF-format output.
 * 
 * @name : ToGIF
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C029A
STDMETHODIMP CNEATO::ToGIF(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_GIF,Result);
}

/**
 * support directed graph PNG-format output.
 * 
 * @name : ToPNG
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C0291
STDMETHODIMP CNEATO::ToPNG(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_PNG,Result);
}

/**
 * support directed graph SVGZ output.
 * 
 * @name : ToSVGZ
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C028D
STDMETHODIMP CNEATO::ToSVGZ(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_SVGZ,Result);
}

/**
 * support directed graph VRML-format output.
 * 
 * @name : ToVRML
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C0284
STDMETHODIMP CNEATO::ToVRML(BSTR Source,BSTR* Result) {

    return E_NOTIMPL;
}

/**
 * support directed graph Binary-Image output.
 * 
 * @name : ToBinaryGraph
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C027D
STDMETHODIMP CNEATO::ToBinaryGraph(BSTR Source, long intType, IBinaryImage* *Result) {
    try {
        USES_CONVERSION;
        const char * pchCmd = OLE2CA(Source);
        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_PNG :
                pFile = NEATORander(pchCmd,"png",m_codepage);
                break;

                case GRAPHVIZ_GIF :
                pFile = NEATORander(pchCmd,"gif",m_codepage);
                break;

                case GRAPHVIZ_SVGZ :
                pFile = NEATORander(pchCmd,"svgz",m_codepage);
                break;

                case GRAPHVIZ_WBMP :
                pFile = NEATORander(pchCmd,"wbmp",m_codepage);
                break;

                case GRAPHVIZ_JPEG :
                pFile = NEATORander(pchCmd,"jpg",m_codepage);
                break;

                default:
                pFile = NEATORander(pchCmd,"png",m_codepage);

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

        raiseCOMError(IID_INEATO,"WinGraphviz.NEATO",errmsg);

        dotneato_terminate2();

        return E_UNEXPECTED;
    }
}

/**
 * support client-side image map.
 * 
 * @name : ToCMAP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C0279
STDMETHODIMP CNEATO::ToCMAP(BSTR Source, BSTR *Result) {
    return ToTextGraph(Source,GRAPHVIZ_CMAP,Result);

}

/**
 * support image map.
 * 
 * @name : ToIMAP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C0272
STDMETHODIMP CNEATO::ToIMAP(BSTR Source, BSTR *Result) {
    return ToTextGraph(Source,GRAPHVIZ_IMAP,Result);

}

/**
 * support image map.
 * 
 * @name : ToISMAP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C026B
STDMETHODIMP CNEATO::ToISMAP(BSTR Source, BSTR *Result) {
    return ToTextGraph(Source,GRAPHVIZ_ISMAP,Result);

}

/**
 * support wireless BitMap.
 * 
 * @name : ToWBMP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C0267
STDMETHODIMP CNEATO::ToWBMP(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_WBMP,Result);
}

/**
 * support JPEG.
 * 
 * @name : ToJPEG
 * @author ood Tsen
 * @version 0.1, 01/20/2003
 */
//##ModelId=3F78401C0260
STDMETHODIMP CNEATO::ToJPEG(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_JPEG,Result);
}

//##ModelId=3F78401C0255
STDMETHODIMP CNEATO::get_Codepage(long *pVal) {
    memcpy(pVal,&m_codepage,sizeof(m_codepage));

    return S_OK;
}

//##ModelId=3F78401C025D
STDMETHODIMP CNEATO::put_Codepage(long newVal) {
    if(newVal > 0)
        m_codepage = newVal;

    return S_OK;
}

//##ModelId=3F78401C0251
STDMETHODIMP CNEATO::ToEMF(BSTR Source, IBinaryImage **Result) {
    return ToBinaryGraph(Source,GRAPHVIZ_EMF,Result);

}
