#include "exti.h"
#include "delay.h"
#include "laser.h"
#include "motor.h"
#include "huidu.h"
#include "led.h"      //test 

extern u16 huiducishu;
void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;     //初始化中断及优先级结构体

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  //外部中断使能AFIO时钟 ？ 
	
	Laser_Init();   //红外的io口初始化
	
	
	//GPIOB.5中断线初始化//GPIOB.6中断线初始化//GPIOB.7中断线初始化//GPIOB.8中断线初始//GPIOB.8中断线初始化//GPIOB.9中断线初始化
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9); //不能用或运算 ！会出错
	
  EXTI_InitStructure.EXTI_Line=EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8|EXTI_Line9;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//任意沿触发？********************
 	EXTI_InitStructure.EXTI_LineCmd = ENABLE; 
 	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	
	

 	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级1
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);
}
	 void EXTI9_5_IRQHandler(void)
{	
		led0= 0;delay_ms(5000);                            //测试用 是否开启中断
//	if(huiducishu==4)
//	{
//		avoid2();	
//		if(EXTI_GetITStatus(EXTI_Line5 != RESET))
//			 EXTI_ClearITPendingBit(EXTI_Line5); //清除LINE5上的中断标志位 
//		
//		if(EXTI_GetITStatus(EXTI_Line6 != RESET))
//			 EXTI_ClearITPendingBit(EXTI_Line6); //清除LINE6上的中断标志位  
//		
//		if(EXTI_GetITStatus(EXTI_Line7 != RESET))
//			 EXTI_ClearITPendingBit(EXTI_Line7); //清除LINE7上的中断标志位  //待修改
//		
//		if(EXTI_GetITStatus(EXTI_Line8 != RESET))
//			 EXTI_ClearITPendingBit(EXTI_Line8); //清除LINE8上的中断标志位  
//		
//		if(EXTI_GetITStatus(EXTI_Line9 != RESET))
//			 EXTI_ClearITPendingBit(EXTI_Line9); //清除LINE9上的中断标志位   //第二段避障
//	}
	//else
//	{
		avoid1();
  	if(EXTI_GetITStatus(EXTI_Line5 != RESET))
			 EXTI_ClearITPendingBit(EXTI_Line5); //清除LINE5上的中断标志位 
		
		if(EXTI_GetITStatus(EXTI_Line6 != RESET))
			 EXTI_ClearITPendingBit(EXTI_Line6); //清除LINE6上的中断标志位   //进入最困难房间的避障
		
		if(EXTI_GetITStatus(EXTI_Line7 != RESET))
			 EXTI_ClearITPendingBit(EXTI_Line7); //清除LINE7上的中断标志位  
		
		if(EXTI_GetITStatus(EXTI_Line8 != RESET))
			 EXTI_ClearITPendingBit(EXTI_Line8); //清除LINE8上的中断标志位  
		
		if(EXTI_GetITStatus(EXTI_Line9 != RESET))
			 EXTI_ClearITPendingBit(EXTI_Line9); //清除LINE9上的中断标志位 
///	}
		
}
void EXTI_Close(void)
{
	EXTI->IMR&=~(1<<5);                                          
	EXTI->EMR&=~(1<<5);                                           

	EXTI->IMR&=~(1<<5);                                          
	EXTI->EMR&=~(1<<5); 

	EXTI->IMR&=~(1<<5);                                          
	EXTI->EMR&=~(1<<5); 

	EXTI->IMR&=~(1<<5);                                          
	EXTI->EMR&=~(1<<5); 

	EXTI->IMR&=~(1<<5);                 //关闭line 5~9的中断                         
	EXTI->EMR&=~(1<<5); 
}

void EXTI_Open(void)
{
	EXTI->IMR|=1<<5; 
  EXTI->EMR|=1<<5;
	
	EXTI->IMR|=1<<6; 
  EXTI->EMR|=1<<6;

	EXTI->IMR|=1<<7; 
  EXTI->EMR|=1<<7;

	EXTI->IMR|=1<<8;                       //开启line 5~9的中断
  EXTI->EMR|=1<<8;

	EXTI->IMR|=1<<9; 
  EXTI->EMR|=1<<9;
}

	

