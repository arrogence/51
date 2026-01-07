#include "Dri_Timer0.h"
#include <STC89C5xRC.H> 
#include "Com_Util.h"
#include <STDIO.H>
#define LED1 P00
#define MAT_CALLBACK_COUNT 4
static Timer0_Callback s_callbacks[MAT_CALLBACK_COUNT];
void Dri_Timer0_Init()
{
        u8 i;
    EA=1;
    ET0=1;

    TMOD&=0XF0;
    TMOD|=0X01;

    TL0=64614;
    TH0=64614>>8;

    TR0=1;

    for(i=0;i<MAT_CALLBACK_COUNT;i++)
    {
        s_callbacks[i]=NULL;
    }
}

bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    u8 i;
    for(i=0;i<MAT_CALLBACK_COUNT;i++)
    {
        if(s_callbacks[i]==callback)
        {
            return 1;
        }
    }
        for(i=0;i<MAT_CALLBACK_COUNT;i++)
    {
        if(s_callbacks[i]==NULL)
        {
            s_callbacks[i]=callback;
            return 1;
        }
    }
    return 0;
}

bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    u8 i;
    for(i=0;i<MAT_CALLBACK_COUNT;i++)
    {
        if(s_callbacks[i]==callback)
        {
            s_callbacks[i]=NULL;
            return 1;
        }
    }
    return 0;
}

void Dir_Timer0_Handler() interrupt 1
{
   u8 i;
    TL0=64614;
    TH0=64614>>8;
    for(i=0;i<MAT_CALLBACK_COUNT;i++)
    {
        if(s_callbacks[i]!=NULL)
        {
                s_callbacks[i]();
        }
    
    }
 

}