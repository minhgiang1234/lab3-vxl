/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */


#include <button1.h>
#include "main.h"

int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;
int Key1Reg3 = NORMAL_STATE;
int TimerForKeyPress1 = 0;
int button1_flag = 0;

int isButton1Pressed(){
	if (button1_flag == 1) {
		button1_flag = 0;

		return 1;
	}
	return 0;
}

void getKey1Input(){
	Key1Reg0 = Key1Reg1;
	Key1Reg1 = Key1Reg2;
	Key1Reg2 = HAL_GPIO_ReadPin(BU1_GPIO_Port, BU1_Pin);

	if ((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2)){
		if (Key1Reg3 != Key1Reg2){ // nhấn thả
			Key1Reg3 = Key1Reg2;
			if (Key1Reg2 == PRESSED_STATE){
				button1_flag = 1;
				TimerForKeyPress1 = 200;

			}
		}else {
			TimerForKeyPress1 --;
			if (TimerForKeyPress1 == 0){
				if (Key1Reg2 == PRESSED_STATE){
					button1_flag = 1;
				}
				TimerForKeyPress1 = 200;
			}
		}
	}
}
