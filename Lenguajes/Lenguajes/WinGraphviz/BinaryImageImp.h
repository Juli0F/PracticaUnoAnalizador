#ifndef __BINARYIMAGEIMP_H_
#define __BINARYIMAGEIMP_H_

#include "IBinaryImage.h"
#include "stdio.h"


class ATL_NO_VTABLE MyImage :
            public CComObjectRootEx<CComSingleThreadModel>,
            public CComCoClass<CBinaryImage, &CLSID_BinaryImage>,
            public IDispatchImpl<IBinaryImage, &IID_IBinaryImage, &LIBID_WINGRAPHVIZLib>
            //class MyImage : IDispatch
{

public:
    MyImage() {}

    ;
    MyImage(FILE *,char * ImageType);
    ~MyImage();
    boolean Save(char * );

private:
    setImageType(char * ImageType);

    unsigned char * m_buf;
    long m_size;
    char m_type[16];

};

#endif //__BINARYIMAGEIMP_H_
