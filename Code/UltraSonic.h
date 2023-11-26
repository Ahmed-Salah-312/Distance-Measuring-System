/*
 * UltraSonic.h
 *
 *  Created on: ٢١‏/١٠‏/٢٠٢٣
 *      Author: ZBOOK G3
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#define ULTRASONIC_TR_PORT_ID                 PORTB_ID
#define ULTRASONIC_TR_PIN_ID                  PIN5_ID

#define ULTRASONIC_ECHO_PORT_ID                 PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID                  PIN6_ID


void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);
volatile uint16 start_time, end_time, pulse_width;


#endif /* ULTRASONIC_H_ */




/*
 * ultrasonic.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Acer
 */
