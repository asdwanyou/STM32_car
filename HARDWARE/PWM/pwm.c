#include "pwm.h"
#include "stm32f10x.h"
void  PWM_Init(u16 arrL,u16 pscL,u16 arrR, u16 pscR)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//初始化结构体
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);   //ENA tim2 ch3  //使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);     //ENB tim3 ch2 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
/**********************************************************************************/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);  //初始化ENAio口
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);//初始化ENBio口
/*********************************************************************************/	
	TIM_TimeBaseStructure.TIM_Period = arrL;
	TIM_TimeBaseStructure.TIM_Prescaler =pscL;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);//初始化TIM2
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure); // TIM2 ch3
	//TIM_CtrlPWMOutputs(TIM3,ENABLE);///MOE 高级定时器才需要
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_Cmd(TIM2, ENABLE);//ENA
/*********************************************************************************/
	/*TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //初始化 TIM3 ch2  
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure); 
	//TIM_CtrlPWMOutputs(TIM2,ENABLE);///????MOE????? 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_Cmd(TIM3, ENABLE);// ENB*/        //库函数无效 原因未知 改为寄存器版本

 
	RCC->APB1ENR|=1<<1;       //TIM3时钟使能
	 
	GPIOA->CRL&=0X0FFFFFFF;//PA7输出
	 
	GPIOA->CRL|=0XB0000000;//复用功能输出 PWM模式
	 
	TIM3->ARR=arrR;               //ok         
	// 可能是
	 
	TIM3->PSC=pscR;
	 
	TIM3->CCMR1|=7<<12;  //CH2 PWM2模式(低电平为占空比) ///？待验证  //ok
	 
	TIM3->CCMR1|=1<<11; //CH2预装载使能
	 
	TIM3->CCER|=1<<4;   //OC2 输出使能
	 
	TIM3->CR1=0x80; //ARPE使能
	 
	TIM3->CR1|=0x01;    //使能定时器3  //ok 正常工作
}
