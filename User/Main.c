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
void Init(void)
{ 
    GPIO_InitTypeDef GPIO_InitStructure;
                                                          // Включаем тактирование нужных модулей
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  // св.диод PA8

                                                          // мигалка св.диод PA8 (навешаный на вывод А8 - PA8 + 330 ом)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure); 

                                                          // настройка таймера Т4
    TIM_TimeBaseInitTypeDef Timer;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
    TIM_TimeBaseStructInit(&Timer);                       // незабываем эту строку для продвинутых таймеров

    Timer.TIM_Prescaler = ((72000000/2)/1000-1);
    Timer.TIM_Period = 2000;                              // прерывание 1 сек
    TIM_TimeBaseInit(TIM4, &Timer);                       // незабываем и эту строку

    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);            // Настраиваем таймер по (переполнению)
    TIM_Cmd(TIM4, ENABLE);                                // запуск
    NVIC_EnableIRQ(TIM4_IRQn);                            // Разрешаем прерывания от ТМ4 

}
void TIM4_IRQnHandler(void)
{                                                         //моргаем светодиодом дабы показать активность таймера
    GPIOA->ODR^=GPIO_Pin_8;
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);           // очищаем прерывания
}
int main (void)
{ Init();                                                 // Настройка всего
    while(1)
    { 
    }
}