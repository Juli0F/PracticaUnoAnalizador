/****************************************************************************
 
    PROGRAM: dotneato.c
 
    PURPOSE: addtion code for graphviz 1.8.10
 
    FUNCTIONS:
 
        dotneato_initialize2() - 
		dotneato_terminate2() - 
		DOTNEATOCheck() - 
		DOTRander() - 
		NEATORander() -
        
    COMMENTS:                
 
****************************************************************************/

#ifdef HAVE_CONFIG_H
#include "gvconfig.h"
#endif

#include	"windows.h"
#include    "circle.h"
#include	"dotneato.h"
#include	"render.h"
#include	"dotprocs.h"
#include	"neatoprocs.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif

#include "zlib.h"

#ifdef HAVE_LIBZ
gzFile Zfile;
#endif

#define bool int
#define true 1
#define false 0

char *Info[] = {
                   DOT_INFO_PROGRAM_NAME,
                   DOT_INFO_PROGRAM_VERSION,
                   DOT_INFO_PROGRAM_BUILDDATE
               };

unsigned int DOT_CODEPAGE;

void ResetErr();

/**
 * This function initial resource of DOT Engine.
 * 
 * @name : dotneato_initialize2
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
void dotneato_initialize2(char * pchType,long codepage) {

    char* tmpFileName = 0;

    char curPath[64] = {0};

    DWORD curPathLen = 0;

    curPathLen = GetCurrentDirectory(64,curPath);

    Output_lang = lang_select(pchType);

    //DOT_CODEPAGE = GetOEMCP();
    DOT_CODEPAGE = codepage;

#ifdef HAVE_LIBZ

    Zfile = NULL;
#endif

    rmtmp();

    Output_file = NULL;

    if (Output_file == NULL) {
        tmpFileName = _tempnam( curPathLen, "tmp" );

        Output_file = fopen(tmpFileName,"w+");

        free(tmpFileName);
        //Output_file = tmpfile();
    }

    aginit();

    if (! (agfindattr(agprotograph()->proto->n, "label")))
        agnodeattr(NULL,"label",NODENAME_ESC);

    ResetErr();

}

/**
 * This function release resource of DOT Engine.
 * 
 * @name : dotneato_terminate2
 * @author ood Tsen
 * @version 0.1, 09/06/2002
 */
void dotneato_terminate2(void) {

    _rmtmp();
    Output_file = NULL;
    Output_lang = 0;
    emit_eof();
};


int Check(char * pchCmd,long codepage) {
    //Step1:Declare
    graph_t *G;

    //Step2:Check initial state

    if (pchCmd == NULL)
        return NULL;

    //Step3:initial Values
    G = NULL;

    dotneato_initialize2("dot",codepage);

    G = agmemread(pchCmd);

    if(!G)
        return NULL;


    //Step4:Process
    dot_layout(G);

    //dotneato_terminate2();

    dot_cleanup(G);

    G = NULL;

    //Step.End:Return

    if(isError())
        return FALSE;
    else
        return TRUE;

};


/**
 * This function read a sequence of command and translate to
 * text-base graph.
 * 
 * @name : DOTRander
 * @author ood Tsen
 * @version 0.2, 25/01/2003
 */

FILE * DOTRander(char * pchCmd,char * pchType,long codepage) {

    //Step1:Declare
    graph_t *G;

    //Step2:Check initial state

    if (pchCmd == NULL)
        return NULL;

    //Step3:initial Values
    G = NULL;

    dotneato_initialize2(pchType,codepage);

    G = agmemread(pchCmd);

    if(!G)
        return NULL;


    //Step4:Process
    dot_layout(G);

    dotneato_write(G);

    //dotneato_terminate2();

    dot_cleanup(G);

    G = NULL;

    //Step.End:Return

    return Output_file;
}

/**
 * This function read a sequence of command and translate to
 * text-base graph.
 * 
 * @name : NEATORander
 * @author ood Tsen
 * @version 0.2, 25/01/2003
 */

FILE * NEATORander(char * pchCmd,char * pchType,long codepage) {

    //Step1:Declare
    graph_t *G;

    //Step2:Check initial state

    if (pchCmd == NULL)
        return NULL;

    //Step3:initial Values
    G = NULL;

    dotneato_initialize2(pchType,codepage);

    G = agmemread(pchCmd);

    if(!G)
        return NULL;

    //Step4:Process

    neato_layout(G);

    dotneato_write(G);

    neato_cleanup(G);

    //Step.End:Return

    return Output_file;
};

/**
 * This function read a sequence of command and translate to
 * text-base graph.
 * 
 * @name : TWOPIRander
 * @author ood Tsen
 * @version 0.2, 25/01/2003
 */
FILE * TWOPIRander(char * pchCmd,char * pchType,long codepage) {
    //Step1:Declare
    graph_t *G;

    //Step2:Check initial state

    if (pchCmd == NULL)
        return NULL;

    //Step3:initial Values
    G = NULL;

    dotneato_initialize2(pchType,codepage);

    G = agmemread(pchCmd);

    if(!G)
        return NULL;

    //Step4:Process

    twopi_layout(G);

    dotneato_write(G);

    twopi_cleanup(G);

    //Step.End:Return

    return Output_file;

}

