/*
 * button2.h
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#ifndef INC_BUTTON2_H_
#define INC_BUTTON2_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKey2Input();
int isButton2Pressed();


#endif /* INC_BUTTON2_H_ */
