/*
 * fsm_normal.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#include "fsm_normal.h"

void fsm_normal_run(){
	switch(status){
		case INIT:
			status = RED_GREEN;
			break;

		case RED_GREEN:
			//TODO
			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_RESET);

			if (timer1_flag == 1){
				status = RED_YELLOW;
				setTimer1(yellow_duration * 1000);
			}

			break;

		case RED_YELLOW:

			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_SET);

			if (timer1_flag == 1){
				status = GREEN_RED;
				setTimer1(green_duration * 1000);
			}
			break;

		case GREEN_RED:

			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_SET);

			if (timer1_flag == 1){
				status = YELLOW_RED;
				setTimer1(yellow_duration * 1000);
			}
			break;

		case YELLOW_RED:

			HAL_GPIO_WritePin(RE1_GPIO_Port, RE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RE2_GPIO_Port, RE2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YE1_GPIO_Port, YE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YE2_GPIO_Port, YE2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR1_GPIO_Port, GR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GR2_GPIO_Port, GR2_Pin, GPIO_PIN_SET);

			if (timer1_flag == 1){
				status = RED_GREEN;
				setTimer1(green_duration * 1000);
			}
			break;

	}
}
