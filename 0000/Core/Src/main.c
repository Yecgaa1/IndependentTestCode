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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sbus.h"
#include "SEGGER_RTT.h"
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
uint8_t USART1_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.
uint16_t USART1_RX_STA = 0; //接收状态标记
uint8_t aRxBuffer1[2];	
HAL_StatusTypeDef status=HAL_ERROR;
SBUS_CH_Struct SBUS_CH;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void delay_us(int time);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
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
	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1,aRxBuffer1,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	//SEGGER_RTT_printf(0,"Test%d   %s %x\n",000,"123",0x10); 
  while (1)
  {
    /* USER CODE END WHILE */
		HAL_Delay(500);
		SEGGER_RTT_printf(0,"ch1  %d   %s %x\n",SBUS_CH.CH1,"123",0x10);
		SEGGER_RTT_printf(0,"ch2  %d   %s %x\n",SBUS_CH.CH2,"123",0x10);
		SEGGER_RTT_printf(0,"ch3  %d   %s %x\n",SBUS_CH.CH3,"123",0x10);
		SEGGER_RTT_printf(0,"ch4  %d   %s %x\n",SBUS_CH.CH4,"123",0x10);
		SEGGER_RTT_printf(0,"ch5  %d   %s %x\n",SBUS_CH.CH5,"123",0x10);
		SEGGER_RTT_printf(0,"ch6  %d   %s %x\n",SBUS_CH.CH6,"123",0x10);
		SEGGER_RTT_printf(0,"ch7  %d   %s %x\n",SBUS_CH.CH7,"123",0x10);
		SEGGER_RTT_printf(0,"ch8  %d   %s %x\n",SBUS_CH.CH8,"123",0x10);
		SEGGER_RTT_printf(0,"ch9  %d   %s %x\n",SBUS_CH.CH9,"123",0x10);
		SEGGER_RTT_printf(0,"ch10    %d   %s %x\n",SBUS_CH.CH10,"123",0x10);
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
}

/* USER CODE BEGIN 4 */
void delay_us(int time)
{    
   int i=0;  
   while(time--)
   {
      i=10;  //自己定义
      while(i--) ;    
   }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  int i;
  while(&huart1 == huart)
  {
    USART1_RX_BUF[USART1_RX_STA] = aRxBuffer1[0];
		if (USART1_RX_STA == 0 && USART1_RX_BUF[USART1_RX_STA] != 0x0F) 
		{
			HAL_UART_Receive_IT(&huart1,aRxBuffer1,1);			
			break; //帧头不对，丢掉
		}
		USART1_RX_STA++;
		if (USART1_RX_STA > USART_REC_LEN) USART1_RX_STA = 0;  ///接收数据错误,重新开始接收
		if (USART1_RX_BUF[0] == 0x0F && USART1_RX_BUF[24] == 0x00 && USART1_RX_STA == 25)	//接受完一帧数据
		{
			update_sbus(USART1_RX_BUF);
			for (i = 0; i<25; i++)		//清空缓存区
				USART1_RX_BUF[i] = 0;
			USART1_RX_STA = 0;
		}
		HAL_UART_Receive_IT(&huart1,aRxBuffer1,1);
		break;
  }
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if(&huart1 == huart)
  {
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
  while (1)
  {
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
