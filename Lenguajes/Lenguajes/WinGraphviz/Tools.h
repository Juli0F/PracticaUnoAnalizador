/****************************************************************************
 
    PROGRAM: Tools.h
 
    PURPOSE: toolbox for atl/com
 
    FUNCTIONS:
 
        FILEtoBSTR() - 	
		DebugPrint() -
		DebugPrintInt() -
        
    COMMENTS:
        
 
****************************************************************************/

#ifndef		TOOLS_H
#define		TOOLS_H


BOOL FILEtoBSTR(FILE * pFile ,BSTR*);

BOOL FILEtoBSTRW(FILE * pFile ,BSTR*);

extern void DebugPrint(const char *);

extern void DebugPrintInt(int i);

#endif /* DOTNEATO_H */
