/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */


#include <button2.h>
#include "main.h"

int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;
int TimerForKeyPress2 = 0;
int button2_flag = 0;

int isButton2Pressed(){
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

void getKey2Input(){
	Key2Reg0 = Key2Reg1;
	Key2Reg1 = Key2Reg2;
	Key2Reg2 = HAL_GPIO_ReadPin(BU2_GPIO_Port, BU2_Pin);

	if ((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2)){
		if (Key2Reg3 != Key2Reg2){ // nhấn thả
			Key2Reg3 = Key2Reg2;
			if (Key2Reg2 == PRESSED_STATE){
				button2_flag = 1;
				TimerForKeyPress2 = 200;

			}
		}else {
			TimerForKeyPress2 --;
			if (TimerForKeyPress2 == 0){
				if (Key2Reg2 == PRESSED_STATE){
					button2_flag = 1;
				}
				TimerForKeyPress2 = 200;
			}
		}
	}
}
