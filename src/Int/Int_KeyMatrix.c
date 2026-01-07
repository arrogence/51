#include "Int_KeyMatrix.h"

u8 Int_KeyMatrix_CheckSW()
{
    u8 i;
    u8 j;
    u8 lines[4]={0xFE,0xFD,0xFB,0xF7};
    u8 colums[4]={0x10,0x20,0x40,0x80};
    for(i=0;i<4;i++)
    {
        P2=lines[i];

       
        for(j=0;j<4;j++)
        {
            if((P2&colums[j])==0x00)
            {
                 Com_Util_Delay1ms(10);
        if((P2&colums[j])==0x00)
        {
            while((P2&colums[j])==0x00);
            return 5+j+4*i;
        }
            }
        }
       
    
    }
    return 0;
}