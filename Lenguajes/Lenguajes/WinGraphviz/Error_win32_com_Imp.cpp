/****************************************************************************
 
    PROGRAM: ErrorImp.cpp
 
    PURPOSE: Implement error process
 
    FUNCTIONS:
 
        errorPrintf() - throw a error message
		ErrPuts() - no implement
		ErrPutc() - no implement
        
    COMMENTS:
        
 
****************************************************************************/

#include "ErrorImp.h"

#include "ASSERT.H"
#include <atlbase.h>

char ERROR_MSG[255];

void DebugPrintf(char * buf) {
#if _DEBUG
    MessageBox(NULL,buf,"debug box",MB_OK);
#endif
}

/**
 * This function throw a error message.
 * 
 * @name : errorPrintf
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
void errorPrintf(FILE * f, const char * buf , ...) {

    USES_CONVERSION;

    va_list marker;
    char* name1 = NULL;
    char buf2[255] = {0};
    unsigned int cRemaining;

    va_start( marker, buf );
    vsprintf( buf2, buf,marker);
    va_end( marker );

    cRemaining = (sizeof(ERROR_MSG) - strlen(ERROR_MSG)) - 1;

    strncat(ERROR_MSG,buf2,cRemaining);

    //	if(strlen(buf2) > 1)
    //		throw buf2;

}

/**
 * This function throw a error message.
 * 
 * @name : ErrPuts
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
void ErrPuts(const char * buf, FILE *) {
    //	unsigned int cRemaining;
    //	cRemaining = (sizeof(ERROR_MSG) - strlen(ERROR_MSG)) - 1;

    //	strncat(ERROR_MSG,buf,cRemaining);
    sprintf(ERROR_MSG,"%s%s",ERROR_MSG,buf);


}

/**
 * This function throw a error message.
 * 
 * @name : ErrPutc
 * @author ood Tsen
 * @version 0.1, 11/21/2002
 */
int ErrPutc( int c, FILE *stream ) {

    sprintf(ERROR_MSG,"%s%c",ERROR_MSG,c);

    return 0;
}

BOOL isError() {
    //return FALSE;

    if(ERROR_MSG) {
        if(strlen(ERROR_MSG) > 2)
            return TRUE;
        else
            return FALSE;

    } else {
        return FALSE;
    }

}

char * getErrMsg() {

    return ERROR_MSG;
}

void ResetErr() {
    memset(ERROR_MSG,0,255);
}

void raiseCOMError(REFGUID IID,char * source,char * description) {
    ICreateErrorInfo * pcei = 0;
    IErrorInfo *pei = 0;
    HRESULT hr;

    hr = CreateErrorInfo(&pcei);
    assert(SUCCEEDED(hr));

    hr = pcei->SetGUID(IID);
    assert(SUCCEEDED(hr));

    hr = pcei->SetSource(A2BSTR(source));
    assert(SUCCEEDED(hr));

    hr = pcei->SetDescription (A2BSTR(description));
    assert(SUCCEEDED(hr));

    hr = pcei->QueryInterface(IID_IErrorInfo,(void**)&pei);
    assert(SUCCEEDED(hr));

    hr = SetErrorInfo(0,pei);
    assert(SUCCEEDED(hr));

    pei->Release() ;
    pcei->Release() ;
}
