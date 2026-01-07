#include "Dri_UART.h"
#include <STC89C5xRC.H> 
#include "Com_Util.h"
#include "Dri_Timer0.h"
static bit s_is_sending=0;
static char s_buffer[16];
static u8 s_idle_count=0;
static u8 s_index=0;
static bit s_is_complete=0;
void Dri_UART_TIMER0Callback()
{
    s_idle_count++;
    if(s_index>0&&s_idle_count>=10)
    {
        s_is_complete=1;
    }
}
void Dri_UART_Init()
{
    //1.串口工作模式
    SM0=0;
    SM1=1;
    //波特率7
    PCON&=0X7F;

    TMOD&=0X0F;
    TMOD|=0X20;

    TL1=253;
    TH1=253;

    TR1=1;

    REN=1;
    SM2=0;

    EA=1;
    ES=1;

    RI=0;
    TI=0;
Dri_Timer0_RegisterCallback(Dri_UART_TIMER0Callback);
    

}

void Dri_UART_Send_Char(char c)
{
    while (s_is_sending==1);
    s_is_sending=1;

    
    SBUF=c;
}
void Dri_Uart_SendStr(char *str)
{
    while (*str!=0)
    {
            Dri_UART_Send_Char(*str);
            str++;
    }
    
}
bit Dri_UART_ReceiveString(char *str)
{
    if(s_is_complete==1)
    {
        u8 i;
        for(i=0;i<s_index;i++)
        {
            str[i]=s_buffer[i];
            

        }
        str[i]='\0';
        s_is_complete=0;
        s_index=0;
        return 1;
    }
    return 0;
}
// bit Dri_UART_ReceiveChar(char *c)
// {
//     if(s_buffer)
//     {
//         *c=s_buffer;
//         s_buffer=0;
//         return 1;
//     }else{
//         return 0;
//     }
// }
void Dri_UART_Handler() interrupt 4
{
    if(RI==1)
    {
        RI=0;
       s_buffer[s_index++]=SBUF;
       s_idle_count=0;
    }
    if(TI==1)
    {
        s_is_sending=0;
        TI=0;
    }
}