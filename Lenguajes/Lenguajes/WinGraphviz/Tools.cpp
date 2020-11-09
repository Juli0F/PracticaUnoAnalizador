/****************************************************************************
 
    PROGRAM: tools.cpp
 
    PURPOSE: toolbox for atl/com
 
    FUNCTIONS:
 
        FILEtoBSTR() - 	
		DebugPrint() -
		DebugPrintInt() -
        
    COMMENTS:
        
        
 
****************************************************************************/

#include "stdafx.h"
#include "Tools.h"

/**
 * This function raise a Dialbox and display message
 * 
 * @name : DebugPrint
 * @author ood Tsen
 * @version 0.1, 10/17/2002
 */
void DebugPrint(char * buf) {
#ifdef _DEBUG
    MessageBox(NULL,buf,"debug",MB_OK);
#endif
}

/**
 * This function raise a Dialbox and display message as integer
 * 
 * @name : DebugPrintInt
 * @author ood Tsen
 * @version 0.1, 10/17/2002
 */
void DebugPrintInt(int i) {
    //#ifdef _DEBUG
    char buf[20];
    _itoa(i,buf,10);
    MessageBox(NULL,buf,"debug",MB_OK);
    //#endif
}

BOOL FILEtoBSTRW(FILE * pFile,BSTR * pString) {
    if (!pFile)
        return false;

    USES_CONVERSION;

    unsigned long intSizeOfFile;

    intSizeOfFile=0;

    intSizeOfFile = ftell(pFile) - 1;

    int isfirst = 0;


    if(intSizeOfFile > 0 ) {
        int intTmp;
        int intCount;

        unsigned long intPos;

        intTmp=0;
        intPos=0;
        intCount=0;

        CComBSTR result;

        wchar_t buf[255] = {0};

        rewind(pFile);

        memset(buf,0,255);

        while(!feof(pFile)) {

            intTmp = fgetc(pFile);

            buf[intPos] = intTmp;



            if(intPos == 249 || (intTmp == '\n' )) {
                if(intTmp == '\n') {
                    buf[intPos] = 13;
                    //					intPos++;
                    //					buf[intPos] = 10;
                }

                intCount ++;

                result.Append(W2BSTR(buf));

                memset(buf,0,255);
                intPos = 0;

            } else {
                intPos++;
            }
        }

        if(intPos > 1)
            result.Append(W2BSTR(buf));

        if(pString)
            SysFreeString(*pString);

        result.CopyTo( pString);

        return true;

    } else {
        return false;
    }
}

/**
 * This function read from FILE structure , and put it in a string
 * 
 * @name : FILEtoBSTR
 * @author ood Tsen
 * @version 0.1, 10/17/2002
 */
BOOL FILEtoBSTR(FILE * pFile,BSTR * pString) {
    if (!pFile)
        return false;

    USES_CONVERSION;

    unsigned long intSizeOfFile;

    intSizeOfFile=0;

    intSizeOfFile = ftell(pFile) - 1;

    int isfirst = 0;


    if(intSizeOfFile > 0 ) {
        int intTmp;
        int intCount;

        unsigned long intPos;

        intTmp=0;
        intPos=0;
        intCount=0;

        CComBSTR result;

        char buf[255] = {0};

        rewind(pFile);

        memset(buf,0,255);

        while(!feof(pFile)) {

            intTmp = fgetc(pFile);

            buf[intPos] = intTmp;



            if(intPos == 249 || (intTmp == '\n' )) {
                if(intTmp == '\n') {
                    buf[intPos] = 13;
                    //					intPos++;
                    //					buf[intPos] = 10;
                }

                intCount ++;

                result.Append(T2BSTR(buf));

                memset(buf,0,255);
                intPos = 0;

            } else {
                intPos++;
            }
        }

        if(intPos > 1)
            result.Append(T2BSTR(buf));

        if(pString)
            SysFreeString(*pString);

        result.CopyTo( pString);

        return true;

    } else {
        return false;
    }

}

