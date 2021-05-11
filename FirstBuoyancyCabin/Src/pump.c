//
// Created by 星星 on 2021/4/30.
//

#include <stdbool.h>
#include "pump.h"


struct state state;
struct pid {
    //5cm以上
    float kp5;
    float kd5;
    //以下
    float kp;
    float kd;
    float err;
    float err_last;

} pid;
bool flag = false;//中断标志点
bool SteeringValve(uint16_t st)//转换阀
{
    //防止工作出错
    HAL_TIM_PWM_Stop(Pump_PWM);
    HAL_Delay(100);
    HAL_TIM_PWM_Stop(Areversing);
    HAL_TIM_PWM_Stop(Breversing);
    HAL_Delay(100);
    //中断启动
    switch (st) {
        case LOCK:
            HAL_NVIC_EnableIRQ(A0IT);
            HAL_NVIC_EnableIRQ(B0IT);
            break;
        case IN:
            HAL_NVIC_EnableIRQ(A1IT);
            HAL_NVIC_EnableIRQ(B1IT);
            break;
        case OUT:
            HAL_NVIC_EnableIRQ(A2IT);
            HAL_NVIC_EnableIRQ(B2IT);
            break;
        default:
            return 1;
    }
    //转向
    HAL_TIM_PWM_Start(Areversing);
    while (!flag);
    flag = false;
    HAL_TIM_PWM_Start(Breversing);
    while (!flag);
    flag = false;
    //关闭中断并修改状态
    switch (st) {
        case LOCK:
            HAL_NVIC_DisableIRQ(A0IT);
            HAL_NVIC_DisableIRQ(B0IT);
            state.ValveState = LOCK;
            break;
        case IN:
            HAL_NVIC_DisableIRQ(A1IT);
            HAL_NVIC_DisableIRQ(B1IT);
            state.ValveState = LOCK;
            break;
        case OUT:
            HAL_NVIC_DisableIRQ(A2IT);
            HAL_NVIC_DisableIRQ(B2IT);
            state.ValveState = LOCK;
            break;
        default:
            return 1;
    }
    return 0;
}

bool Launch(float depth) {
    pid.err = depth - state.depth;
    float ccr;
    if (pid.err > 0)//需要下沉
    {
        if (SteeringValve(IN) == 1)
            return 1;

        //pid逻辑
        if (pid.err > 5)
            while (pid.err > 5) {
                ccr = pid.kp5 * pid.err + pid.kd5 * (pid.err - pid.err_last);
                htim2.Instance->CCR3 = ccr;
                pid.err_last = pid.err;
                //TODO:获取新的err
            }
        while (pid.err > 0.5) {
            ccr = pid.kp * pid.err + pid.kd * (pid.err - pid.err_last);
            htim2.Instance->CCR3 = ccr;
            pid.err_last = pid.err;
            //TODO:获取新的err
        }
    } else {
        if (SteeringValve(OUT) == 1)
            return 1;
        //pid逻辑
        if (pid.err > -5)
            while (pid.err > -5) {
                ccr = pid.kp5 * pid.err + pid.kd5 * (pid.err - pid.err_last);
                htim2.Instance->CCR3 = ccr;
                pid.err_last = pid.err;
                //TODO:获取新的err
            }
        while (pid.err > -0.5) {
            ccr = pid.kp * pid.err + pid.kd * (pid.err - pid.err_last);
            htim2.Instance->CCR3 = ccr;
            pid.err_last = pid.err;
            //TODO:获取新的err
        }
    }
    if (SteeringValve(LOCK) == 1)
        return 1;
    return 0;
}
