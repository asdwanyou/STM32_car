#ifndef __LASER_H
#define __LASER_H

#define PB5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
#define PB6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define PB7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define PB8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define PB9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
//#define PB5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
//#define PB6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
//#define PB7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
//#define PB8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
//#define PB9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
void Laser_Init(void);
void avoid(void);


#endif
