//
// Created by 星星 on 2021/4/30.
//

#include <stdbool.h>
#include "pump.h"

uint16_t state;//默认封闭
uint32_t amount;//ml
bool flag=false;//中断标志点
bool SteeringValve(uint16_t st)//转换阀
{
    //防止工作出错
    HAL_TIM_PWM_Stop(Pump_PWM);
    HAL_Delay(100);
    HAL_TIM_PWM_Stop(Areversing);
    HAL_TIM_PWM_Stop(Breversing);
    HAL_Delay(100);
    //中断启动
    switch(st)
    {
        case LOCK:HAL_NVIC_EnableIRQ(A0IT);HAL_NVIC_EnableIRQ(B0IT);break;
        case IN:HAL_NVIC_EnableIRQ(A1IT);HAL_NVIC_EnableIRQ(B1IT);break;
        case OUT:HAL_NVIC_EnableIRQ(A2IT);HAL_NVIC_EnableIRQ(B2IT);break;
        default:return 1;
    }
    //转向
    HAL_TIM_PWM_Start(Areversing);
    while(!flag);
    flag=false;
    HAL_TIM_PWM_Start(Breversing);
    while(!flag);
    flag=false;
    switch(st)
    {
        case LOCK:HAL_NVIC_DisableIRQ(A0IT);HAL_NVIC_DisableIRQ(B0IT);break;
        case IN:HAL_NVIC_DisableIRQ(A1IT);HAL_NVIC_DisableIRQ(B1IT);break;
        case OUT:HAL_NVIC_DisableIRQ(A2IT);HAL_NVIC_DisableIRQ(B2IT);break;
        default:return 1;
    }
    return 0;
}

