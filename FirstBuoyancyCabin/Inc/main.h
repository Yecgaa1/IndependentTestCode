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

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Areversing_Pin GPIO_PIN_0
#define Areversing_GPIO_Port GPIOA
#define Breversing_Pin GPIO_PIN_1
#define Breversing_GPIO_Port GPIOA
#define A0_Pin GPIO_PIN_4
#define A0_GPIO_Port GPIOA
#define A0_EXTI_IRQn EXTI4_IRQn
#define A1_Pin GPIO_PIN_5
#define A1_GPIO_Port GPIOA
#define A1_EXTI_IRQn EXTI9_5_IRQn
#define Pump_PWM_Pin GPIO_PIN_6
#define Pump_PWM_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_7
#define B2_GPIO_Port GPIOA
#define B2_EXTI_IRQn EXTI9_5_IRQn
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOB
#define B1_EXTI_IRQn EXTI0_IRQn
#define B0_Pin GPIO_PIN_1
#define B0_GPIO_Port GPIOB
#define B0_EXTI_IRQn EXTI1_IRQn
#define A2_Pin GPIO_PIN_2
#define A2_GPIO_Port GPIOB
#define A2_EXTI_IRQn EXTI2_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
