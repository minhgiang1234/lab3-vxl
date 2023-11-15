/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */


#include <button3.h>
#include "main.h"

int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;
int Key3Reg3 = NORMAL_STATE;
int TimerForKeyPress3 = 0;
int button3_flag = 0;

int isButton3Pressed(){
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void getKey3Input(){
	Key3Reg0 = Key3Reg1;
	Key3Reg1 = Key3Reg2;
	Key3Reg2 = HAL_GPIO_ReadPin(BU3_GPIO_Port, BU3_Pin);

	if ((Key3Reg0 == Key3Reg1) && (Key3Reg1 == Key3Reg2)){
		if (Key3Reg3 != Key3Reg2){ // nhấn thả
			Key3Reg3 = Key3Reg2;
			if (Key3Reg2 == PRESSED_STATE){
				button3_flag = 1;
				TimerForKeyPress3 = 200;

			}
		}else { // nhấn giữ
			TimerForKeyPress3 --;
			if (TimerForKeyPress3 == 0){
				if (Key3Reg2 == PRESSED_STATE){
					button3_flag = 1;
				}
				TimerForKeyPress3 = 200;
			}
		}
	}
}
