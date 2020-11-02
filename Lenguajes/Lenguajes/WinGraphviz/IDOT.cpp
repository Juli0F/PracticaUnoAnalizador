/****************************************************************************
 
    PROGRAM: IDOT.cpp
 
    PURPOSE: COM Interface of dot(directed graph) Engine.
 
    FUNCTIONS:
 
        ToTextGraph() - directed graph textformat output.
		ToBinaryGraph() - directed graph Binaryformat output.
        
    COMMENTS:
        
 
****************************************************************************/
#include "stdafx.h"
#include "WinGraphviz.h"
#include "IDOT.h"
#include "IBinaryImage.h"

#include "tools.h"

#include "ASSERT.H"


extern "C" int Output_lang;
extern "C" FILE * DOTRander(const char * pchCmd,char * pchType,long codepage);
extern "C" void dotneato_terminate2(void);

extern "C" BOOL isError();
extern "C" char * getErrMsg();
extern "C" void ResetErr();
extern "C" unsigned int DOT_CODEPAGE;

void raiseCOMError(REFGUID IID,char * source,char * description);

//void DebugPrint(const char *);
//BOOL FILEtoBSTR(FILE * pFile ,BSTR*);

/**
 * This function return IID_IDOT.
 * 
 * @name : InterfaceSupportsErrorInfo
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
//##ModelId=3F78401C034F
STDMETHODIMP CDOT::InterfaceSupportsErrorInfo(REFIID riid) {
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
 * support directed graph textformat output.
 * 
 * @name : ToTextGraph
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401D000E
STDMETHODIMP CDOT::ToTextGraph(BSTR Source, long intType, BSTR *Result) {
    try {
        USES_CONVERSION;

        const char * pchCmd = OLE2T(Source);



        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_SVG :
                pFile = DOTRander(pchCmd,_T("svg"),m_codepage);
                break;

                case GRAPHVIZ_PS :
                pFile = DOTRander(pchCmd,_T("ps"),m_codepage);
                break;

                case GRAPHVIZ_CMAP :
                pFile = DOTRander(pchCmd,_T("cmap"),m_codepage);
                break;

                case GRAPHVIZ_ISMAP :
                pFile = DOTRander(pchCmd,_T("ismap"),m_codepage);
                break;

                case GRAPHVIZ_IMAP :
                pFile = DOTRander(pchCmd,_T("imap"),m_codepage);
                break;

                case GRAPHVIZ_ATTRIBUTED_DOT :
                pFile = DOTRander(pchCmd,_T("dot"),m_codepage);
                break;

                case GRAPHVIZ_CANONICAL_DOT :
                pFile = DOTRander(pchCmd,_T("canon"),m_codepage);
                break;

                case GRAPHVIZ_PLAIN	:
                pFile = DOTRander(pchCmd,_T("plain"),m_codepage);
                break;

                case GRAPHVIZ_PLAIN_EXT :
                pFile = DOTRander(pchCmd,_T("plain-ext"),m_codepage);
                break;

                default:
                pFile = DOTRander(pchCmd,_T("dot"),m_codepage);

        };

        if (isError())
            throw getErrMsg();

        if (!pFile)
            throw getErrMsg();

        /*
        		switch(intType) {
        			case GRAPHVIZ_SVG :
        				if (!FILEtoBSTRW(pFile,Result))
        					throw "DOT internal error:FILEtoBSTR";
        				break;
        			default:
        				if (!FILEtoBSTR(pFile,Result))
        					throw "DOT internal error:FILEtoBSTR";
         
        		}
                
        */
        if (!FILEtoBSTR(pFile,Result))
            throw "DOT internal error:FILEtoBSTR";

        dotneato_terminate2();

        return S_OK;

    } catch(char * errmsg) {
        raiseCOMError(IID_IDOT,_T("WinGraphviz.DOT"),errmsg);

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
//##ModelId=3F78401D0004
STDMETHODIMP CDOT::ToDot(BSTR Source,BSTR* Result) {

    return ToTextGraph(Source,GRAPHVIZ_ATTRIBUTED_DOT,Result);
}

/**
 * support directed graph canon-format output.
 * 
 * @name : ToCanon
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C03E2
STDMETHODIMP CDOT::ToCanon(BSTR Source,BSTR* Result) {

    return ToTextGraph(Source,GRAPHVIZ_CANONICAL_DOT,Result);
}

/**
 * support directed graph plain-format output.
 * 
 * @name : ToPlain
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C03D8
STDMETHODIMP CDOT::ToPlain(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_PLAIN,Result);
}

/**
 * support directed graph plain-ext format output.
 * 
 * @name : ToPlainExt
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
//##ModelId=3F78401C03CE
STDMETHODIMP CDOT::ToPlainExt(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_PLAIN_EXT,Result);
}

/**
 * support directed graph svg-format output.
 * 
 * @name : ToSvg
 * @author ood Tsen
 * @version 0.1, 09/11/2002
 */
//##ModelId=3F78401C03C4
STDMETHODIMP CDOT::ToSvg(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_SVG,Result);
}

/**
 * check DOT-language.
 * 
 * @name : Validate
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C03BA
STDMETHODIMP CDOT::Validate(BSTR Source,VARIANT_BOOL* Result) {

    BSTR * out = 0;
    HRESULT hr;
    hr = ToTextGraph(Source,GRAPHVIZ_ATTRIBUTED_DOT,out);

    if(SUCCEEDED(hr) && !isError())
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
//##ModelId=3F78401C03B0
STDMETHODIMP CDOT::ToPS(BSTR Source,BSTR* Result) {

    return ToTextGraph(Source,GRAPHVIZ_PS,Result);

}

/**
 * support directed graph GIF-format output.
 * 
 * @name : ToGIF
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C03A6
STDMETHODIMP CDOT::ToGIF(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_GIF,Result);
}

/**
 * support directed graph PNG-format output.
 * 
 * @name : ToPNG
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C039D
STDMETHODIMP CDOT::ToPNG(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_PNG,Result);
}

/**
 * support directed graph SVGZ output.
 * 
 * @name : ToSVGZ
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C0393
STDMETHODIMP CDOT::ToSVGZ(BSTR Source,IBinaryImage* *Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_SVGZ,Result);
}

/**
 * support directed graph VRML-format output.
 * 
 * @name : ToVRML
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C038B
STDMETHODIMP CDOT::ToVRML(BSTR Source,BSTR* Result) {

    return E_NOTIMPL;
}

/**
 * support directed graph Binary-Image output.
 * 
 * @name : ToBinaryGraph
 * @author ood Tsen
 * @version 0.1, 10/13/2002
 */
//##ModelId=3F78401C0383
STDMETHODIMP CDOT::ToBinaryGraph(BSTR Source, long intType, IBinaryImage* *Result) {

    try {
        USES_CONVERSION;
        const char * pchCmd = OLE2T(Source);

        //		MessageBoxW(NULL,Source,L"",MB_OK);

        //		MessageBoxA(NULL,pchCmd,"",MB_OK);

        FILE * pFile;

        ResetErr();

        switch(intType) {

                case GRAPHVIZ_PNG :
                pFile = DOTRander(pchCmd,_T("png"),m_codepage);
                //pFile = DOTRander((const char *)wbuffer,_T("png"),m_codepage);
                break;

                case GRAPHVIZ_GIF :
                pFile = DOTRander(pchCmd,_T("gif"),m_codepage);
                break;

                case GRAPHVIZ_SVGZ :
                pFile = DOTRander(pchCmd,_T("svgz"),m_codepage);
                break;

                case GRAPHVIZ_WBMP :
                pFile = DOTRander(pchCmd,_T("wbmp"),m_codepage);
                break;

                case GRAPHVIZ_JPEG :
                pFile = DOTRander(pchCmd,_T("jpeg"),m_codepage);
                break;

                case GRAPHVIZ_EMF :
                pFile = DOTRander(pchCmd,_T("emf"),m_codepage);
                break;

                default:
                pFile = DOTRander(pchCmd,_T("png"),m_codepage);

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
                pImg->Load(pFile,_T("png"));
                break;

                case GRAPHVIZ_GIF :
                pImg->Load(pFile,_T("gif"));
                break;

                case GRAPHVIZ_SVGZ :

                pImg->Load(pFile,_T("svgz"));
                break;

                case GRAPHVIZ_WBMP :
                pImg->Load(pFile,_T("wbmp"));
                break;

                case GRAPHVIZ_JPEG :
                pImg->Load(pFile,_T("jpg"));
                break;

                case GRAPHVIZ_EMF :
                pImg->Load(pFile,_T("emf"));
                break;

                default:
                pImg->Load(pFile,_T("png"));

        };

        dotneato_terminate2();

        return S_OK;

    } catch(char * errmsg) {

        raiseCOMError(IID_IDOT,"WinGraphviz.DOT",errmsg);

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
//##ModelId=3F78401C037F
STDMETHODIMP CDOT::ToCMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_CMAP,Result);
}

/**
 * support image map.
 * 
 * @name : ToIMAP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C0378
STDMETHODIMP CDOT::ToIMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_IMAP,Result);
}

/**
 * support image map.
 * 
 * @name : ToISMAP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C0374
STDMETHODIMP CDOT::ToISMAP(BSTR Source, BSTR *Result) {

    return ToTextGraph(Source,GRAPHVIZ_ISMAP,Result);
}

/**
 * support wireless BitMap.
 * 
 * @name : ToWBMP
 * @author ood Tsen
 * @version 0.1, 11/14/2002
 */
//##ModelId=3F78401C036D
STDMETHODIMP CDOT::ToWBMP(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_WBMP,Result);
}

/**
 * support JPEG.
 * 
 * @name : ToJPEG
 * @author ood Tsen
 * @version 0.1, 01/20/2003
 */
//##ModelId=3F78401C0369
STDMETHODIMP CDOT::ToJPEG(BSTR Source, IBinaryImage **Result) {

    return ToBinaryGraph(Source,GRAPHVIZ_JPEG,Result);
}

//##ModelId=3F78401C035F
STDMETHODIMP CDOT::get_Codepage(long *pVal) {
    memcpy(pVal,&m_codepage,sizeof(m_codepage));

    return S_OK;
}

//##ModelId=3F78401C0362
STDMETHODIMP CDOT::put_Codepage(long newVal) {
    if(newVal > 0)
        m_codepage = newVal;

    return S_OK;
}

//##ModelId=3F78401C0355
STDMETHODIMP CDOT::ToEMF(BSTR Source, IBinaryImage **Result) {
    return ToBinaryGraph(Source,GRAPHVIZ_EMF,Result);

}
