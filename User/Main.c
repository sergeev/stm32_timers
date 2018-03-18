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


// For timers
void delay1(void);
void delay2(void);
void delay3(void);
// For Servo
void delay_servo_pa_1_port(void);
void delay_servo_pa_2_port(void);
void delay_servo_pa_3_port(void);
void delay_servo_pa_4_port(void);
void delay_servo_pa_5_port(void);
void delay_servo_pa_6_port(void);

void set_pos(uint8_t pos);

// For Servo
#define SERVO_1_180 24200
#define SERVO_1_0		5800

#define SERVO_2_180 24200
#define SERVO_2_0		5800

#define SERVO_3_180 24200
#define SERVO_3_0		5800

#define SERVO_4_180 24200
#define SERVO_4_0		5800

#define SERVO_5_180 24200
#define SERVO_5_0		5800

#define SERVO_6_180 24200
#define SERVO_6_0		5800

int main(void)
{
SystemInit();
		SystemCoreClockUpdate();
		// Blinks GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, 	ENABLE);
		// Servo
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,		ENABLE);
		// Blinks
    GPIO_InitTypeDef gpioInitStruct;
		// Servo PORT
		GPIO_InitTypeDef PORT;
	
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
		
		// For Servo
		// Pin_1 = PA1(Diagram) A1(Board pin)
		PORT.GPIO_Pin = (GPIO_Pin_1);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i1;
		
		PORT.GPIO_Pin = (GPIO_Pin_2);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i2;
		
		PORT.GPIO_Pin = (GPIO_Pin_3);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i3;
		
		
		PORT.GPIO_Pin = (GPIO_Pin_4);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i4;
		
		PORT.GPIO_Pin = (GPIO_Pin_5);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i5;
		
		PORT.GPIO_Pin = (GPIO_Pin_6);
		PORT.GPIO_Mode = GPIO_Mode_AF_PP;
		PORT.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &PORT);
		TIM2->CCER |= (TIM_CCER_CC2E);
		TIM2->CCMR1|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
		TIM2->PSC = 6;
		TIM2->CR1 |= TIM_CR1_CEN;
		uint8_t i6;
		

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
			
		 // Servo 180
			for (i1=0;i1<=180;i1++) {
				delay_servo_pa_1_port();
      set_pos(i1);	}
				
			for (i2=0;i2<=180;i2++) {
				delay_servo_pa_2_port();
      set_pos(i2);	}
							
			for (i3=0;i3<=180;i3++) {
				delay_servo_pa_3_port();
      set_pos(i2);	}
							
			for (i4=0;i4<=180;i4++) {
				delay_servo_pa_4_port();
      set_pos(i4); }
				
			for (i5=0;i5<=180;i5++) {
				delay_servo_pa_5_port();
      set_pos(i5); }
								
			for (i6=0;i6<=180;i6++) {
				delay_servo_pa_6_port();
      set_pos(i6);
    }
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

// Servo delay function
void delay_servo_pa_1_port(void) {
  volatile uint32_t i1;
  for (i1=1; i1 != 0xFFFF; i1++)
    ;
 }

 void delay_servo_pa_2_port(void) {
  volatile uint32_t i2;
  for (i2=1; i2 != 0xFFFF; i2++)
    ;
 }
 
 void delay_servo_pa_3_port(void) {
  volatile uint32_t i3;
  for (i3=1; i3 != 0xFFFF; i3++)
    ;
 }
 
 void delay_servo_pa_4_port(void) {
  volatile uint32_t i4;
  for (i4=1; i4 != 0xFFFF; i4++)
    ;
 }
 
 void delay_servo_pa_5_port(void) {
  volatile uint32_t i5;
  for (i5=1; i5 != 0xFFFF; i5++)
    ;
 }
 
 void delay_servo_pa_6_port(void) {
  volatile uint32_t i6;
  for (i6=1; i6 != 0xFFFF; i6++)
    ;
 }

 // Position servo points
void set_pos(uint8_t pos) {
  uint32_t tmp=(SERVO_1_180 - SERVO_1_0) /180 ;
  TIM2->CCR2 = SERVO_1_0 + tmp * pos;
}
