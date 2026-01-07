#include "Int_OLED.h"
#include "Int_DS18B20.h"
#include "Com_Util.h"
void main()
{
    Int_OLED_Init();
    Int_OLED_Clear();
    while (1) {
        Int_OLED_ShowNum(0, 0, Int_DS18B20_GetTemperature());
        Com_Util_Delay1ms(500);
    }
}
////
// #include "Int_OLED.h"

// int main()
// {

//     Int_OLED_Init();
//     Int_OLED_Clear();
//     Int_OLED_ShowStr(0, 0, "yange!");
//     Int_OLED_ShowNum(0, 1, -135678);
//     // Int_OLED_ShowStr(0,1,"12345678");
    
   
//     while (1)
//     {
//         /* code */
//     }
 
// }

//EEProm写入并读取

// 点阵LED显示定时器

// #include "Dri_Timer0.h"
// #include <STC89C5xRC.H> 
// #include "Dri_Timer0.h"
// #include "Int_LEDMatrix.h"
// #include "Com_Util.h"
// #include "Int_EEPROM.h"
// u8 picture[26]={0xF8,0x0A,0xEC,0xAF,0xEC,0x8A,0xF8,0x00,
//     0x10,0xF9,0x97,0xF1,0x88,0xAA,0xFF,0xAA,
//     0X88,0X00,0X14,0X0A,0XF5,0X92,0X92,0XF5,
//     0X0A,0X14};
//  u8 buffer[26];
// void main()
// {
//     u8 i;

//     Dri_Timer0_Init();
//     Int_LEDMatrix_Init();
   
//     // Int_EEPROM_WriteBytes(0,picture,26);
//     // Com_Util_Delay1ms(10);
//     Int_EEPROM_ReadBytes(0,buffer,26);
//     while (1)
//     {
        
//         for(i=0;i<26;i++)
//         {
//              Int_LEDMatrix_Shift(buffer[i]);
//              Com_Util_Delay1ms(200);
//         }
//     }
// }
//串口定时器
// #include "Dri_UART.h"
// #include <STC89C5xRC.H> 
// #include "Com_Util.h"
// #include <STRING.H>
// #include <Dri_Timer0.h>
// void main()
// {
//     char str[16];
//     Dri_Timer0_Init();
//     Dri_UART_Init();
//     while (1)
//     {
//         // Dri_Uart_SendStr("hello");
//         // Com_Util_Delay1ms(1000);
//         /* code */
//         if(Dri_UART_ReceiveString(str))
//         {
//             if(strcmp(str,"on")==0)
//         {
//             P0=0x00;
//             Dri_Uart_SendStr("hello");
//         }
//         else if(strcmp(str,"off")==0)
//         {
//             P0=0xFF;
//             Dri_Uart_SendStr("ni hew");
//         }
//         else{
// Dri_Uart_SendStr("ni heewffw");
//         }
//         }
//     }
    

// }


//串口定时器
// #include "Dri_UART.h"
// #include <STC89C5xRC.H> 
// #include "Com_Util.h"
// #include <STRING.H>
// #include <Dri_Timer0.h>
// void main()
// {
//     char str[16];
//     Dri_Timer0_Init();
//     Dri_UART_Init();
//     while (1)
//     {
//         // Dri_Uart_SendStr("hello");
//         // Com_Util_Delay1ms(1000);
//         /* code */
//         if(Dri_UART_ReceiveString(str))
//         {
//             if(strcmp(str,"on")==0)
//         {
//             P0=0x00;
//             Dri_Uart_SendStr("hello");
//         }
//         else if(strcmp(str,"off")==0)
//         {
//             P0=0xFF;
//             Dri_Uart_SendStr("ni hew");
//         }
//         else{
// Dri_Uart_SendStr("ni heewffw");
//         }
//         }
//     }
    

// }

// 点阵LED显示定时器
// #include "Dri_Timer0.h"
// #include <STC89C5xRC.H> 
// #include "Dri_Timer0.h"
// #include "Int_LEDMatrix.h"
// #include "Com_Util.h"
// u8 picture[26]={0xF8,0x0A,0xEC,0xAF,0xEC,0x8A,0xF8,0x00,
//     0x10,0xF9,0x97,0xF1,0x88,0xAA,0xFF,0xAA,
//     0X88,0X00,0X14,0X0A,0XF5,0X92,0X92,0XF5,
//     0X0A,0X14};
// void main()
// {
 
//        Dri_Timer0_Init();
//     Int_LEDMatrix_Init();


//     while (1)
//     {
//         u8 i;
//         for(i=0;i<26;i++)
//         {
//              Int_LEDMatrix_Shift(picture[i]);
//              Com_Util_Delay1ms(200);
//         }
//     }
// }
//点阵LED显示定时器
// #include "Dri_Timer0.h"
// #include <STC89C5xRC.H> 
// #include "Dri_Timer0.h"
// #include "Int_LEDMatrix.h"

// void main()
// {
//     u8 pic[8]={
//         0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80
//     };
//        Dri_Timer0_Init();
//     Int_LEDMatrix_Init();
//     Int_LEDMatrix_SetPic(pic);
 

//     while (1)
//     {
//         // Int_LEDMatrix_Refresh();
//         /* code */
//     }
// }
// // LED点阵
// #include "Dri_Timer0.h"
// #include <STC89C5xRC.H> 

// #include "Int_LEDMatrix.h"


// void main()
// {
//     u8 pic[8]={
//         0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80
//     };
//     Int_LEDMatrix_Init();
//     Int_LEDMatrix_SetPic(pic);
//     while (1)
//     {
//         Int_LEDMatrix_Refresh();
//         /* code */
//     }
    
// }
//定时器
// #include "Dri_Timer0.h"
// #include <STC89C5xRC.H> 
//  #include "Com_Util.h"
//  #define LED P00
// void LEd_Blink()
// {
// static u32 count=0;
// count++;
// if(count>=1000)
// {
//     count=0;
//     LED=~LED;
// }
// }
// void main()
// {
//     Dri_Timer0_Init();
//     Dri_Timer0_RegisterCallback(LEd_Blink);
//     while (1)
//     {
//         /* code */
//     }
    
// }



/**
 * *********************************************
 * 
 * 8051 blink demo
 * 
 * PIN: P11
 * 
 * *********************************************



 //外部中断
// #include <STC89C5xRC.H> 
// #include "Int_KeyMatrix.h"
// #include "Int_DigitalTube.h"
// #include "Com_Util.h"
// #include "Int_Buzzer.h"

// #define LED P00
//外部中断0
// void INT0_Init()
// {   
//     //启用中断
//     EA=1;
//     EX0=1;
//     //触发方式（下降沿）
//     IT0=1;
// }
//  void main()
// {
//     INT0_Init();
//     while (1)
//     {
//         /* code */ 
//     }
    
    
// }
// void INT0_Handler()  interrupt 0
// {
//     Com_Util_Delay1ms(10);
//     if (P32==0)
//     {
            
//     LED=~LED;
//     }

// }
//独立按键
/*
#include <STC89C5xRC.H> 

#include "Int_Key.h"

#define LED1 P00
#define LED2 P01

#define LED3 P02

#define LED4 P03

void main()
{
    while (1)
    {
        if(Int_Key_IsSW1Pressed())
        {
            LED1=~LED1;
        }
         if(Int_Key_IsSW2Pressed())
        {
            LED2=~LED2;
        }
         if(Int_Key_IsSW3Pressed())
        {
            LED3=~LED3;
        }
         if(Int_Key_IsSW4Pressed())
        {
            LED4=~LED4;
        }
    }
    
}
*/

//数码管显示
/*#include <STC89C5xRC.H> 
#include <intrins.h>

#include "Int_DigitalTube.h"

void main()
{
   Int_DigitalTube_Init();
    Int_DigitalTube_DisplayNum(0);
    while (1)
    {
        Int_DigitalTube_Refresh();
      
    }
    
    // set T0 1ms
  
}

*/