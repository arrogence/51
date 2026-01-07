#include "Int_DigitalTube.h"

static u8 s_buffer[8];

static u8 s_codes[] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};


void Int_DigitalTube_Init()
{
     SMG_EN=0;
    LED_EN=0;
}

void Int_DigitalTube_Refresh()
{
        u8 i;
    for(i=0;i<8;i++)
    {
        Int_DigitalTube_DisplaySingle(i,s_buffer[i]);
        Com_Util_Delay1ms(1);
    }
    
}

void Int_DigitalTube_DisplayNum(u32 num)
{
        u8 i;
    for(i=0;i<7;i++)
    {
        s_buffer[i]=0x00;
    }
    i=7;
    if(num==0)
    {
        s_buffer[7]=s_codes[0];
        return;
    }
    while(num>0)
    {
        s_buffer[i]=s_codes[num%10];
        num/=10;
        i--;
    }
}

static void Int_DigitalTube_DisplaySingle(u8 position, u8 num_code)
{
    P0=0x00;
    position<<=3;
    P1&=0xC7;
    P1|=position;
    P0=num_code;
}
