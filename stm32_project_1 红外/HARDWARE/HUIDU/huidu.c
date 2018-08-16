#include "huidu.h"
#include "stm32f10x.h"
#include "delay.h"
u16 huiducishu;
void HUIDU_Init(void)
{
	GPIO_InitTypeDef		GPIO_InitStructure ;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;    //»Ò¶È1
	 
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);          	//»Ò¶È2 //´ýÐÞ¸Ä  //
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
