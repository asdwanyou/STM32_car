#ifndef __LASER_H
#define __LASER_H

#define L1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
#define L2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define L3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define L4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define L5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)

void Laser_Init(void);


#endif
