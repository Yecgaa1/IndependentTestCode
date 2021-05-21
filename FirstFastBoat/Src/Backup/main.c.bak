/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <board-st_discovery.h>
#include <string.h>
#include <stdio.h>
#include <sbus.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define USART_REC_LEN  			100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t USART2_RX_BUF[USART_REC_LEN]; //接收缓冲,�??????大USART_REC_LEN个字�??????.
uint16_t USART2_RX_STA = 0; //接收状�?�标�??????
uint8_t aRxBuffer1[2];
HAL_StatusTypeDef status=HAL_ERROR;
SBUS_CH_Struct SBUS_CH;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_I2C2_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
    uint8_t send[]="Hello";
    HAL_UART_Transmit(&huart1,send,sizeof(send),255);
    //HAL_UART_Transmit(&huart1,send,sizeof(send),255);
    HAL_Delay(1000);
    HAL_UART_Receive_IT(&huart2,aRxBuffer1,1);
    TIM1->CCR1 = 5000;
    TIM1->CCR2 = 5000;
    TIM1->CCR3 = 500;
    TIM1->CCR4 = 500;
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
    //默认占空�????????
    //mpu_test();//螺仪初始化，TODO：陀螺仪测试
    uint16_t command = 0, speed = 500;
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while (1) {


        if (command != 0)//手动命令,swd修改
            switch (command) {
                case (1)://修改速度占空�??????????????????
                    TIM1->CCR1 = speed;
                    TIM1->CCR2 = speed;
                    TIM1->CCR3 = speed;
                    TIM1->CCR4 = speed;
                    break;
                case (2)://�??????????????????始尝试下�??????????????????
                    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
                    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
                    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
                    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
                    HAL_Delay(500);
                    HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
                    HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
                    HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_3);
                    HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_4);
                    break;


            }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */
uint16_t PPM_Sample_Cnt=0;
uint32_t	 PPM_Time=0;
uint16_t PPM_Okay=0;
uint16_t PPM_Databuf[8]={0};
int i=0;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == MPU6050INT_Pin_Pin) //mpu6050数据就绪
    {
        gyro_data_ready_cb();
    }
/*    else if(GPIO_Pin==PPM_Pin)
    {
        i++;
        PPM_Time += TIM3->CNT;
        printf("%lu",PPM_Time);
        HAL_UART_Transmit(&huart1, (uint8_t *) PPM_Time, sizeof(PPM_Time), 255);
        //HAL_UART_Transmit(&huart1, (uint8_t *) ("Get"), 100, 255);
        TIM3->CNT = 0;				//读取完之后清空，该�?�每1us�????????????????1
        if(PPM_Okay==1)
        {
            PPM_Sample_Cnt++;
            PPM_Databuf[PPM_Sample_Cnt-1]=PPM_Time;
            if(PPM_Sample_Cnt>=8)//接收�????????????????8通道
                PPM_Okay=0;
        }
        if(PPM_Time>=2050)//确认是下�????????????????次数�????????????????
        {
            PPM_Okay=1;
            PPM_Sample_Cnt=0;
        }
    }*/
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    int i;
    while(&huart2 == huart)
    {
        USART2_RX_BUF[USART2_RX_STA] = aRxBuffer1[0];
        if (USART2_RX_STA == 0 && USART2_RX_BUF[USART2_RX_STA] != 0x0F)
        {
            HAL_UART_Receive_IT(&huart2,aRxBuffer1,1);
            break; //帧头不对，丢�??????
        }
        USART2_RX_STA++;
        if (USART2_RX_STA > USART_REC_LEN) USART2_RX_STA = 0;  ///接收数据错误,重新�??????始接�??????
        if (USART2_RX_BUF[0] == 0x0F && USART2_RX_BUF[24] == 0x00 && USART2_RX_STA == 25)	//接受完一帧数�??????
        {
            update_sbus(USART2_RX_BUF);
            for (i = 0; i<25; i++)		//清空缓存�??????
                USART2_RX_BUF[i] = 0;
            USART2_RX_STA = 0;
        }
        HAL_UART_Receive_IT(&huart2,aRxBuffer1,1);
        break;
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
