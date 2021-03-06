/*
******************************************************************************
File:     main.cpp
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2019-05-08

The MIT License (MIT)
Copyright (c) 2018 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
volatile int ticks=0;
extern "C" void SysTicks_Handler(){
	ticks++;
}

void delay_ms(int interval){
	int temp=ticks+interval;
	while (ticks<temp);
}


int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef a;
		a.GPIO_Mode=GPIO_Mode_OUT;
		a.GPIO_OType=GPIO_OType_PP;
		a.GPIO_Pin=GPIO_Pin_12;
		a.GPIO_PuPd=GPIO_PuPd_NOPULL;
		a.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &a);

	GPIO_InitTypeDef b;
		b.GPIO_Mode=GPIO_Mode_OUT;
		b.GPIO_OType=GPIO_OType_PP;
		b.GPIO_Pin=GPIO_Pin_13;
		b.GPIO_PuPd=GPIO_PuPd_NOPULL;
		b.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(GPIOB, &b);

	GPIO_InitTypeDef c;
		c.GPIO_Mode=GPIO_Mode_OUT;
		c.GPIO_OType=GPIO_OType_PP;
		c.GPIO_Pin=GPIO_Pin_14;
		c.GPIO_PuPd=GPIO_PuPd_NOPULL;
		c.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(GPIOC, &c);

	GPIO_InitTypeDef d;
		d.GPIO_Mode=GPIO_Mode_OUT;
		d.GPIO_OType=GPIO_OType_PP;
		d.GPIO_Pin=GPIO_Pin_15;
		d.GPIO_PuPd=GPIO_PuPd_NOPULL;
		d.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(GPIOD, &d);

	SysTick_Config(168000);


	while(1){
		GPIO_SetBits(GPIOA, GPIO_Pin_12);
		delay_ms(100);
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);

		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		delay_ms(100);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);

		GPIO_SetBits(GPIOC, GPIO_Pin_14);
		delay_ms(100);
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);

		GPIO_SetBits(GPIOD, GPIO_Pin_15);
		delay_ms(100);
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
	}

int i = 0;


  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used. 
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates 
  *  SCB->VTOR register.  
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /* TODO - Add your application code here */

  /* Initialize LEDs */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);

  /* Turn on LEDs */
  STM_EVAL_LEDOn(LED3);
  STM_EVAL_LEDOn(LED4);
  STM_EVAL_LEDOn(LED5);
  STM_EVAL_LEDOn(LED6);

  /* Infinite loop */
  while (1)
  {
	i++;
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
extern "C" void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
extern "C" uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
