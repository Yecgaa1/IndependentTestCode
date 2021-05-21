/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Export ed types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define USART_REC_LEN  			100
extern uint8_t USART2_RX_BUF[100],aRxBuffer1[100],Sbus_flag;
extern uint16_t USART2_RX_STA;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MPU6050INT_Pin_Pin GPIO_PIN_2
#define MPU6050INT_Pin_GPIO_Port GPIOC
#define MPU6050INT_Pin_EXTI_IRQn EXTI2_IRQn
#define PPM_Pin GPIO_PIN_3
#define PPM_GPIO_Port GPIOC
#define PPM_EXTI_IRQn EXTI3_IRQn
#define A1_Pin GPIO_PIN_4
#define A1_GPIO_Port GPIOA
#define A2_Pin GPIO_PIN_5
#define A2_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_7
#define B1_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_4
#define B2_GPIO_Port GPIOC
#define C1_Pin GPIO_PIN_5
#define C1_GPIO_Port GPIOC
#define C2_Pin GPIO_PIN_0
#define C2_GPIO_Port GPIOB
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
