#include "huidu.h"
#include "stm32f10x.h"
#include "delay.h"
u16 huiducishu;
void HUIDU_Init(void)
{
	GPIO_InitTypeDef		GPIO_InitStructure ;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;    //灰度1
	 
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);    	//灰度2 //待修改  //
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //灰度3
	GPIO_Init(GPIOC,&GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; ////灰度4
	GPIO_Init(GPIOC,&GPIO_InitStructure); 
}
void huidu(void)
{
	   if(huidu1==0)
	 {
	   delay_ms(20);
		 if(huidu1==0)   
			{
				huiducishu++;   
			}
	 }
 }
