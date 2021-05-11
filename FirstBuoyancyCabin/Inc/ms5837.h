//
// Created by xtx on 2021/4/29.
//

#ifndef DEPTHSENSOR_MS5837_H
#define DEPTHSENSOR_MS5837_H

#include <stdint.h>
#include "stm32f1xx_hal.h"



#define Address 0xEC
#define RESET_AD 0x1E



void prom(void);
void convert(void);

extern float pressure,ctemp;
#endif //DEPTHSENSOR_MS5837_H
