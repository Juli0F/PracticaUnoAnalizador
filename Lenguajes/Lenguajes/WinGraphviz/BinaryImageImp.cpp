#include "StdAfx.h"
#include "WinGraphviz.h"
#include "BinaryImageImp.h"

MyImage::MyImage(FILE * pFile,char * ImageType) {
    m_buf = NULL;

    m_size = 0;

    if(!pFile)
        return;

    int intSizeOfFile;

    intSizeOfFile = 0;

    intSizeOfFile = ftell(pFile) - 1;

    if(intSizeOfFile > 0) {
        m_buf =(unsigned char *) malloc(intSizeOfFile);

        if (m_buf) {
            rewind(pFile);
            fread(m_buf,sizeof(unsigned char ), intSizeOfFile,pFile);
            m_size = intSizeOfFile;
            setImageType(ImageType);
        }
    }


    return;
};

boolean MyImage::Save(char * pchPath) {

    FILE *stream;
    stream = fopen( pchPath, "wb" );

    if(! stream)
        return false;

    fwrite( m_buf, sizeof(unsigned char ), m_size, stream );

    fclose( stream );

    return true;
};

MyImage::setImageType(char * ImageType) {
    int sizeIn;
    sizeIn = sizeof(ImageType);

    int sizeSet;
    sizeSet = (sizeIn > 16) ? 16 : sizeIn;

    memcpy(m_type,ImageType,sizeSet);
}


MyImage::~MyImage() {
    if(m_buf)
        free(m_buf);
};
