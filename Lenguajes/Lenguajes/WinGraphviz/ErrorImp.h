/****************************************************************************
 
    PROGRAM: ErrorImp.h
 
    PURPOSE: Implement error process
 
    FUNCTIONS:
 
		errorPrintf() - throw a error message
		ErrPuts() - no implement
		ErrPutc() - no implement
        
    COMMENTS:
        
 
****************************************************************************/

#ifndef		ERRORIMP_H
#define		ERRORIMP_H

#include    <stdio.h>

#define		ERROR_MSG_SIZE 255;

extern "C" void errorPrintf(FILE *, const char *, ...);

extern "C" void ErrPuts(const char *, FILE *);

extern "C" int ErrPutc( int c, FILE *stream );

extern "C" int isError();

extern "C" char * getErrMsg();

extern "C" void ResetErr();





#endif
