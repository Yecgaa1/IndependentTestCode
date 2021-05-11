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
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <board-st_discovery.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

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
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE); //启动串口收完数据后的闲时中断（开了自己不会默认停下）
    HAL_UART_Receive_DMA(&huart2, rx_buffer, BUFFER_SIZE);
    TIM1->CCR1 = 500;
    TIM1->CCR2 = 500;
    TIM1->CCR3 = 500;
    TIM1->CCR4 = 500;
    //默认占空�??
    mpu_test();//�??螺仪初始化，TODO：陀螺仪测试
    uint16_t command = 0, speed = 500;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while (1) {
/*      //Sbus 解码触发
  if (recv_end_flag) //接收到DMA数据准备解码
        {
            if (rx_buffer[25] == 0x00 && rx_buffer[0] == 0x0f) {      //当前缓存数据满足0x0f�??头且0x00结尾
                //uint8_t buf_frame[25] = {0};
                //memcpy(buf_frame, rx_buffer+q, 25-q);
                //memcpy(buf_frame+25-q, buf, q);
                sbus_decoder_get_frame(rx_buffer);
                recv_end_flag = 0;
                HAL_UART_Receive_DMA(&huart2, rx_buffer, BUFFER_SIZE);//重置size的计数！
            }
        }*/
        if (command != 0)//手动命令,swd修改
            switch (command) {
                case (1)://修改速度占空�??
                    TIM1->CCR1 = speed;
                    TIM1->CCR2 = speed;
                    TIM1->CCR3 = speed;
                    TIM1->CCR4 = speed;
                    break;
                case (2)://�??始尝试下�??
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


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == MPU6050INT_Pin_Pin) //mpu6050数据就绪
    {
        gyro_data_ready_cb();
    }
    else if(GPIO_Pin==PPM_Pin)
    {
        PPM_Time = TIM3->CNT;
        TIM3->CNT = 0;				//读取完之后清空，该值每1us加1
        if(PPM_Okay==1)
        {
            PPM_Sample_Cnt++;
            PPM_Databuf[PPM_Sample_Cnt-1]=PPM_Time;
            if(PPM_Sample_Cnt>=8)//接收到8通道
                PPM_Okay=0;
        }
        if(PPM_Time>=2050)//确认是下一次数据
        {
            PPM_Okay=1;
            PPM_Sample_Cnt=0;
        }
    }
}

/*//SBus解码代码
 * static void sbus_decoder_get_frame(uint8_t *buf)        //传入�??帧数据，解析成各个�?�道数据，一帧长度必然是25字节
{
    rc_data.rawdata[0] = ((buf[1] | buf[2] << 8) & 0x07FF);
    rc_data.rawdata[1] = ((buf[2] >> 3 | buf[3] << 5) & 0x07FF);
    rc_data.rawdata[2] = ((buf[3] >> 6 | buf[4] << 2 | buf[5] << 10) & 0x07FF);
    rc_data.rawdata[3] = ((buf[5] >> 1 | buf[6] << 7) & 0x07FF);
    rc_data.rawdata[4] = ((buf[6] >> 4 | buf[7] << 4) & 0x07FF);
    rc_data.rawdata[5] = ((buf[7] >> 7 | buf[8] << 1 | buf[9] << 9) & 0x07FF);
    rc_data.rawdata[6] = ((buf[9] >> 2 | buf[10] << 6) & 0x07FF);
    rc_data.rawdata[7] = ((buf[10] >> 5 | buf[11] << 3) & 0x07FF);
    rc_data.rawdata[8] = ((buf[12] | buf[13] << 8) & 0x07FF);
    rc_data.rawdata[9] = ((buf[13] >> 3 | buf[14] << 5) & 0x07FF);
    rc_data.rawdata[10] = ((buf[14] >> 6 | buf[15] << 2 | buf[16] << 10) & 0x07FF);
    rc_data.rawdata[11] = ((buf[16] >> 1 | buf[17] << 7) & 0x07FF);
    rc_data.rawdata[12] = ((buf[17] >> 4 | buf[18] << 4) & 0x07FF);
    rc_data.rawdata[13] = ((buf[18] >> 7 | buf[19] << 1 | buf[20] << 9) & 0x07FF);
    rc_data.rawdata[14] = ((buf[20] >> 2 | buf[21] << 6) & 0x07FF);
    rc_data.rawdata[15] = ((buf[21] >> 5 | buf[22] << 3) & 0x07FF);
    uint8_t i;
    for (i = 0; i < 16; i++) {
        rc_data.percent[i] = (rc_data.rawdata[i] - 340) * 100 / (1704 - 340);//计算比例
    }
    rc_data.flag_refresh = 1;//完成解码标志位，TODO：改变对应�?�度
}*/


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
