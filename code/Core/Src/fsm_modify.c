/*
 * fsm_modify.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */


#include "fsm_modify.h"

void fsm_modify_run(){
	switch (status){
		case MOD_RED:
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_SET);
			// display mode 02
			if (timer_led_flag == 1){
				HAL_GPIO_TogglePin(RE1_GPIO_Port, RE1_Pin);
				HAL_GPIO_TogglePin(RE2_GPIO_Port, RE2_Pin);
				setTimerLed(500);
			}

			seg_buffer[0] = 0x40;
			seg_buffer[1] = 0x24;
			seg_buffer[2] = 0x40;
			seg_buffer[3] = 0x40;

			if (isButton1Pressed()){
				status = MOD_YELLOW;
			}

			if (isButton3Pressed()){

			}
			break;

		case MOD_YELLOW:

			//display mode 03
			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_SET);
			if (timer_led_flag == 1){
				HAL_GPIO_TogglePin(YE1_GPIO_Port, YE1_Pin);
				HAL_GPIO_TogglePin(YE2_GPIO_Port, YE2_Pin);
				setTimerLed(500);
			}

			seg_buffer[0] = 0x40;
			seg_buffer[1] = 0x30;
			seg_buffer[2] = 0x40;
			seg_buffer[3] = 0x40;

			if (isButton1Pressed()){
				status = MOD_GREEN;
			}

			break;

		case MOD_GREEN:
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_SET);
			//display mode 04
			if (timer_led_flag == 1){
				HAL_GPIO_TogglePin(GR1_GPIO_Port, GR1_Pin);
				HAL_GPIO_TogglePin(GR2_GPIO_Port, GR2_Pin);
				setTimerLed(500);
			}

			seg_buffer[0] = 0x40;
			seg_buffer[1] = 0x19;
			seg_buffer[2] = 0x40;
			seg_buffer[3] = 0x40;

			if (isButton1Pressed()){
				status = RED_GREEN;
			}
	}
}

