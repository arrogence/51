#include "Int_LEDMatrix.h"
#include <STC89C5xRC.H> 
#include "Com_Util.h"
#define LED_MATRIX_EN P35 
#define LED_EN P34
#include "Dri_Timer0.h"
#define SER P10
#define SCK P12
#define RCK P11


static u8 s_buffer[8];
void Int_LEDMatrix_Init()
{
    LED_MATRIX_EN=0;
    LED_EN=0;

   
    Dri_Timer0_RegisterCallback(Int_LEDMatrix_RefreshByTimer0);
}

void Int_LEDMatrix_SetPic(u8 pic[])
{
    u8 i;
    for(i=0;i<8;i++)
    {
        s_buffer[i]=pic[i];
    }
}

void Int_LEDMatrix_Refresh()
{
    u8 i;
    for(i=0;i<8;i++)
    {
        P0=0xFF;
        if(i==0)
        {
            SER=1;
        }
        else{
            SER=0;
        }
        SCK=0;
        SCK=1;

        RCK=0;
        RCK=1;

        P0=~s_buffer[i];
        Com_Util_Delay1ms(1);
    }
}

void Int_LEDMatrix_RefreshByTimer0()
{
     static u8 i=0;
     P0=0xFF;
        if(i==0)
        {
            SER=1;
        }
        else{
            SER=0;
        }
        SCK=0;
        SCK=1;

        RCK=0;
        RCK=1;

        P0=~s_buffer[i];
        i++;
        if(i==8){
            i=0;
        }
}

void Int_LEDMatrix_Shift(u8 pic)
{
    u8 i=7;
    for(i=7;i>0;i--)
    {
        s_buffer[i]=s_buffer[i-1];
     
    }
    s_buffer[0]=pic; 
}
