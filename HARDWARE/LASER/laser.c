#include "stm32f10x.h"

void Laser_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;    //红外的外部中断输入口 PB5~9
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_Init(GPIOB,&GPIO_InitStructure);               //ok
		
}
void avoid(void)
{
	//if(PB5 == 0)
	
   /*   if((PB5 == 1)&&(PA1 == 1)&&(PA2 == 1))
            up();
        if((PA0 == 0)&&(PA1 == 1)&&(PA2 == 0))
            left();
        if((PA0 == 1)&&(PA1 ==0)&&(PA2 ==1)) 
            left();                
        if(((PA0 == 1)&&(PA1 ==1)&&(PA2 ==0))||((PA0 == 1)&&(PA1 ==0)&&(PA2 ==0)))     //已定义端口
	
            left();
        if(((PA0 == 0)&&(PA1 ==1)&&(PA2 ==1))||((PA0 == 0)&&(PA1 ==0)&&(PA2 ==1)))    //待修改逻辑
            right();
        if((PA0 == 0)&&(PA1 == 0)&&(PA1 == 0))
           right();   */     
}
