/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

void delay1(void);
void delay2(void);
void delay3(void);

int main(void)
{
SystemInit();
		SystemCoreClockUpdate();
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef gpioInitStruct;
	
    GPIO_StructInit(&gpioInitStruct);
    gpioInitStruct.GPIO_Pin = GPIO_Pin_13;
    gpioInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpioInitStruct);
	
    GPIO_StructInit(&gpioInitStruct);
    gpioInitStruct.GPIO_Pin = GPIO_Pin_14;
    gpioInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOC, &gpioInitStruct);
	
	  GPIO_StructInit(&gpioInitStruct);
    gpioInitStruct.GPIO_Pin = GPIO_Pin_15;
    gpioInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOC, &gpioInitStruct);

    while(1)
    {
   	 //GPIO_WriteBit(GPIOC, GPIO_Pin_13, 0);
   	 GPIO_SetBits(GPIOC,GPIO_Pin_13);
   	 delay1();
   	 //GPIO_WriteBit(GPIOC, GPIO_Pin_13, 1);
   	 GPIO_ResetBits(GPIOC,GPIO_Pin_13);
   	 delay1();
			
		 //GPIO_WriteBit(GPIOC, GPIO_Pin_14, 0);
   	 GPIO_SetBits(GPIOC,GPIO_Pin_14);
   	 delay2();
   	 //GPIO_WriteBit(GPIOC, GPIO_Pin_14, 1);
   	 GPIO_ResetBits(GPIOC,GPIO_Pin_14);
   	 delay2();
			
		 //GPIO_WriteBit(GPIOC, GPIO_Pin_15, 0);
   	 GPIO_SetBits(GPIOC,GPIO_Pin_15);
   	 delay2();
   	 //GPIO_WriteBit(GPIOC, GPIO_Pin_15, 1);
   	 GPIO_ResetBits(GPIOC,GPIO_Pin_15);
   	 delay2();
    }
}

void delay1(void)
{
	// Red
  volatile unsigned int i;
  for(i=0;i<0x640000;i++){
  }
}

void delay2(void)
{
	// Green
  volatile unsigned int i;
  for(i=0;i<0x50000;i++){
  }
}

void delay3(void)
{
	// Yellow
  volatile unsigned int i;
  for(i=0;i<0x320000;i++){
  }
}
