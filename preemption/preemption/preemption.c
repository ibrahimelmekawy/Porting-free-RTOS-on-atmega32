#include <avr/io.h>
#define  F_CPU 8000000ul
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
void task1(void *pv);
void task2(void *pv);
int main(void)
{
	char x=7;
	char y=6;
	/*create the tasks */
	xTaskCreate(task1,"mohamed",100,&x,1,NULL);
	xTaskCreate(task2,"zaghloul",100,&y,2,NULL);
	/*start os*/
	vTaskStartScheduler();
	while(1)
	{
		
	}
}


void task1(void *pv)
{
	/*some initializations*/
	DDRD|=(1<<*((char*)pv));
	while(1)
	{
		PORTD^=(1<<*((char*)pv));
		_delay_ms(1000);
	}
}
void task2(void *pv)
{
	vTaskDelay(4000);
	/*some initializations*/
	DDRD|=(1<<*((char*)pv));
	while(1)
	{
		PORTD^=(1<<*((char*)pv));
		_delay_ms(1000);
	}
}

