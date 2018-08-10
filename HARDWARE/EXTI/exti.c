#include "exti.h"
#include "delay.h"
#include "laser.h"
#include "motor.h"

#include "led.h"      //test 

void EXTI_INF_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;     //��ʼ���жϼ����ȼ��ṹ��

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  //�ⲿ�ж�ʹ��AFIOʱ�� �� 
	
	Laser_Init();   //�����io�ڳ�ʼ��
	
	
	//GPIOB.5�ж��߳�ʼ��//GPIOB.6�ж��߳�ʼ��//GPIOB.7�ж��߳�ʼ��//GPIOB.8�ж��߳�ʼ//GPIOB.8�ж��߳�ʼ��//GPIOB.9�ж��߳�ʼ��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9); //�����û����� �������
	
  EXTI_InitStructure.EXTI_Line=EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8|EXTI_Line9;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
 	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���  ���������أ���������������********************
 	EXTI_InitStructure.EXTI_LineCmd = ENABLE; 
 	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	

 	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2   	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�1
 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);
}
	 void EXTI9_5_IRQHandler(void)
{	
		led0= 0;
	
	// avoid();
/*	if(EXTI_GetITStatus(EXTI_Line5 != RESET))
		 EXTI_ClearITPendingBit(EXTI_Line5); //���LINE5�ϵ��жϱ�־λ 
	
	if(EXTI_GetITStatus(EXTI_Line6 != RESET))
		 EXTI_ClearITPendingBit(EXTI_Line6); //���LINE6�ϵ��жϱ�־λ  
	
	if(EXTI_GetITStatus(EXTI_Line7 != RESET))
		 EXTI_ClearITPendingBit(EXTI_Line7); //���LINE7�ϵ��жϱ�־λ  //���޸�
	
	if(EXTI_GetITStatus(EXTI_Line8 != RESET))
		 EXTI_ClearITPendingBit(EXTI_Line8); //���LINE8�ϵ��жϱ�־λ  
	
	if(EXTI_GetITStatus(EXTI_Line9 != RESET))
		 EXTI_ClearITPendingBit(EXTI_Line9); //���LINE9�ϵ��жϱ�־λ  */
}

	

