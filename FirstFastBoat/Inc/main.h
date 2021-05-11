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
volatile uint8_t rx_len = 0;             //接收�??帧数据的长度
volatile uint8_t recv_end_flag = 0;    //�??帧数据接收完成标�??
uint8_t rx_buffer[200]={0};   //接收数据缓存
#define BUFFER_SIZE 255
typedef struct {

    uint16_t rawdata[16];       //根据sbus协议，一帧包�?16通道，每通道11位（0-2047�?
    uint8_t percent[16];        //我的天地飞遥控器实际rawdata范围�?340-1704，中间�??1024，这里还原遥控器的百分比
    uint8_t flag_refresh;  //解析代码每次成功解析数据都会将此变量设为1，�?�择使用
} rc_data_t;

rc_data_t rc_data;
static void sbus_decoder_get_frame(uint8_t* buf);
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
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
