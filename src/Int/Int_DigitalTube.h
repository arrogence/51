#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__
#include "Com_Util.h"
#include <STC89C5xRC.H>
#define SMG_EN P36
#define LED_EN P34

void Int_DigitalTube_Init();
void Int_DigitalTube_Refresh();
void Int_DigitalTube_DisplayNum(u32 num);
static void Int_DigitalTube_DisplaySingle(u8 position, u8 num_code);
#endif