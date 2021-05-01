//
// Created by 星星 on 2021/4/30.
//

#ifndef FIRSTBUOYANCYCABIN_PUMP_H
#define FIRSTBUOYANCYCABIN_PUMP_H

//#include <stdbool.h>
//#include "stdio.h"
#include <tim.h>

#define LOCK 0
#define IN 1
#define OUT 2

#define Areversing &htim2,Areversing_Pin//水泵前端,CRR1
#define Breversing &htim2,Breversing_Pin//水泵后端,CRR2
#define Pump_PWM &htim2,Pump_PWM_Pin//水泵,CRR3

#define A0IT EXTI4_IRQn
#define A1IT EXTI9_5_IRQn
#define A2IT EXTI2_IRQn
#define B0IT EXTI1_IRQn
#define B1IT EXTI0_IRQn
#define B2IT EXTI9_5_IRQn

extern uint16_t state;//默认封闭
extern uint32_t amount;//ml
extern bool flag;
//变量命名上采用了A0对应B0对应关闭水路的状态,以此类推
/*!
 * 转向阀更改方向
 * @param st 目标状态
 * @return 0为成功,1为错误
 */
bool SteeringValve(uint16_t st);


#endif //FIRSTBUOYANCYCABIN_PUMP_H
