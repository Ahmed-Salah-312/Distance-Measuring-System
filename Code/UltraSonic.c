#include "ultrasonic.h"
#include <util/delay.h>
#include "gpio.h"
#include "icu.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_timeHigh = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RAISING);
	}
}

void Ultrasonic_init(void)
{
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(ULTRASONIC_TR_PORT_ID, ULTRASONIC_TR_PIN_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TR_PORT_ID, ULTRASONIC_TR_PIN_ID ,LOGIC_LOW);
	_delay_us(1);
	GPIO_writePin(ULTRASONIC_TR_PORT_ID, ULTRASONIC_TR_PIN_ID ,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TR_PORT_ID, ULTRASONIC_TR_PIN_ID ,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	uint16 ULTRASONIC_Distance = 0;

	Ultrasonic_Trigger();

	while(g_edgeCount != 2)
	{
	}

	g_edgeCount = 0;
	ULTRASONIC_Distance =  (float)g_timeHigh / 58.8  ;
	return ULTRASONIC_Distance;
}
