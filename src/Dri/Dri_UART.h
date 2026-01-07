 #ifndef __DRI_UART_H__
 #define  __DRI_UART_H__
void Dri_UART_Init();
void  Dri_UART_Send_Char(char c);
void Dri_Uart_SendStr(char *str);
// bit Dri_UART_ReceiveChar(char *c);
bit Dri_UART_ReceiveString(char *str);
 #endif