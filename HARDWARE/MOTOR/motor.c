#include "motor.h"
#include "stm32f10x.h"
//#include "sys.h"
#include "delay.h"

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
	
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);       //��ʼǰ��  //ENA ENB ���pwm 
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
       GPIO_SetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_4);
       GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3); 
}

void left(void)
{
       GPIO_SetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_4);
       GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_2); 	// �̶����ֵ�ת��
			 delay_ms(20000);
			 DoubleMotorInit();                                       // ����1
	
			
//			TIM_SetCompare3(TIM2,160);                               //����
//			TIM_SetCompare2(TIM3,155);                                 //����
//      delay_ms(20000);
//	     ALLM_STOP();                                                             //����2
//	
//	
}

void right(void)
{
      GPIO_SetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_4);
      GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_7);     //�̶�����
			delay_ms(20000);
	    DoubleMotorInit();                                          //����1
	
		
	
	
	
			
//	    TIM_SetCompare3(TIM2,155);                               //����
//			TIM_SetCompare2(TIM3,160);                                 //����
//      delay_ms(20000);
//	                                                                  //����2
//		  ALLM_STOP();  
			
	
}
