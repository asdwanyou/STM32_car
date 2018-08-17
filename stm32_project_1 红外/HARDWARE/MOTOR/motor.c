#include "motor.h"
#include "stm32f10x.h"
//#include "sys.h"
#include "delay.h"
#include "laser.h"
#include "exti.h"
#include "huoyan.h"
#include "huidu.h"
#include "fan.h"
extern u16 flag;
void DoubleMotorInit(void)
{
	GPIO_InitTypeDef		GPIO_InitStructure ;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;    //in1
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;           //in2
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;         //in3
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;        //in4
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);       //��ʼǰ��  //ENA ENB ���pwm 
}

void LEFTMOTORz(void)
{
	MOTOR_IN1_LOW;
	MOTOR_IN2_HIGH;

}

void LEFTMOTORf(void)
{
	MOTOR_IN1_HIGH;
	MOTOR_IN2_LOW;
}
void RIGHTMOTORz(void)
{
	MOTOR_IN3_HIGH;
	MOTOR_IN4_LOW;
}

void RIGHTMOTORf(void)
{
	MOTOR_IN3_LOW;
	MOTOR_IN4_HIGH;
}

void ALLM_STOP(void)
{
	MOTOR_IN1_LOW;
	MOTOR_IN2_LOW;
	MOTOR_IN3_LOW;
	MOTOR_IN4_LOW;

}

void go(void)
{
  IN1=0;
	IN2=1;
	IN3=0;
	IN4=1;
	
}

void left(void)
{
	ENB=1;IN3=0;IN4=1;
	ENA=0;
			
//			TIM_SetCompare3(TIM2,160);                               //����
//			TIM_SetCompare2(TIM3,155);                                 //����
//      delay_ms(20000);
//	     ALLM_STOP();                                                             //����2
//	
//	
}

void right(void)
{
	ENA=1;
	IN1=0;IN2=1;
	ENB=0;
		
	
	
	
			
//	    TIM_SetCompare3(TIM2,155);                               //����
//			TIM_SetCompare2(TIM3,160);                                 //����
//      delay_ms(20000);
//	                                                                  //����2
//		  ALLM_STOP();  
	
}
void avoid1(void)
{
	if(L5 == 0)
	{
		ALLM_STOP();
		
	}
	else if(L1==0&&L2==0&&L3==0&&L4==0)    
	{
		go();
		return ;		//ֱ�еĵ���������*/     //����
	}
  else if(L3==0&&L4==1)		
	{
		right();
		return;          
	}
	else if(L3==1&&L4==1&&L5==1&&L1==0&&L2==0)
	{
		right();   //ԭ��ת //�ٿ���
		EXTI_Close();   //�ص��ж� �����������һ������ĳ���
	}
}
void avoid2(void)
{


}
void room1(void)
{
	go();
	while(1)
	{
		if(L5==0&&L1&&L2==0)
		{
			right(); //�����ת���������ܹ���λ��ֱ��
		}
		else  if((huoyan1==0||huoyan2==0||huoyan3==0)&&(huidu1==0||huidu2==0))
		{
			miehuo();
		} 
		if(huducishu==?) //���￼���ſڵĻҶ��Ƿ��¼������
			break; //������������
	}
}
void room2(void)
{
	go();
	if(L1==0&&L2==0)
	{
		go();
	}

}

