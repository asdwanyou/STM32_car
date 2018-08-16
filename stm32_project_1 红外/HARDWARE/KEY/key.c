#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//    PA 15   key 1
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//    PC 5  key 0
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;//    PA 0   wk up 
	GPIO_Init(GPIOA,&GPIO_InitStructure);

//////////////////////////////////////////////////////////////////////
//                       初始化三个按键的IO口                       //
//////////////////////////////////////////////////////////////////////

}

u8 KEY_Scan(u8 mode)
{
	static u8 Key_up = 1;
	if(mode) Key_up = 1;
	if(Key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10);
		Key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}
	else if(KEY0==1&&KEY1==1&&WK_UP==0)Key_up=1;
		
	
		return 0;//!!!无按键按下
	}		
	
