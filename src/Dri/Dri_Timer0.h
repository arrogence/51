#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__
typedef void (*Timer0_Callback)(void);
void Dri_Timer0_Init();
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback);
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback);
#endif