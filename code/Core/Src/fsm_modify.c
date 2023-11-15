/*
 * fsm_modify.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */
#include "fsm_modify.h"

uint8_t num_in_bit[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
int chuc = 0;
int donvi = 0;
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
			seg_buffer[2] = num_in_bit[chuc];
			seg_buffer[3] = num_in_bit[donvi];

			if (isButton2Pressed()){
				donvi ++;
				if (donvi > 9) {
					chuc++;
					donvi = 0;
				}

				if (chuc > 9){
					chuc = 0;
				}
			}

			if (isButton3Pressed()){
				red_duration = chuc * 10 + donvi;
			}

			if (isButton1Pressed()){
				donvi = 0;
				chuc = 0;
				status = MOD_YELLOW;
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
			seg_buffer[2] = num_in_bit[chuc];
			seg_buffer[3] = num_in_bit[donvi];

			if (isButton2Pressed()){
				donvi ++;
				if (donvi > 9) {
					chuc++;
					donvi = 0;
				}

				if (chuc > 9){
					chuc = 0;
				}
			}

			if (isButton3Pressed()){
				yellow_duration = chuc * 10 + donvi;
			}

			if (isButton1Pressed()){
				donvi = 0;
				chuc = 0;
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
			seg_buffer[2] = num_in_bit[chuc];
			seg_buffer[3] = num_in_bit[donvi];

			if (isButton2Pressed()){
				donvi ++;
				if (donvi > 9) {
					chuc++;
					donvi = 0;
				}

				if (chuc > 9){
					chuc = 0;
				}
			}

			if (isButton3Pressed()){
				green_duration = chuc * 10 + donvi;
			}

			if (isButton1Pressed()){
				donvi = 0;
				chuc = 0;
				status = RED_GREEN;
			}
	}
}

