#include "stm32f10x.h"
#include "huoyan.h"
#include "huidu.h"
#include "sys.h"
#include "motor.h"
#include "fan.h"
#include "delay.h"
extern u16 flag;
void Fan_Init(void)
{
 //ENC in5 in6
	
	GPIO_InitTypeDef		GPIO_InitStructure ;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //ENC
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;    
	 
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;  //IN5
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);          	//待修改  //

  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//IN6
	GPIO_Init(GPIOC,&GPIO_InitStructure);        

	GPIO_ResetBits(GPIOC,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3); 
}
void miehuo(void)
{
    u16 n,k,a,m;
	       if((huoyan1==0||huoyan2==0||huoyan3==0)&&(huidu3==0||huidu4==0))//确认到达火焰处
		   {
            for(n=0;n<2000;n++)
            {
								ALLM_STOP();          // ??2000tick 停下来
            }
				duojixuanzhuan();         //开舵机
				for(a=0;a<12000;a++)
				{  
					
					fengshan(1);   //  ??? 12000tick  风扇转动
				}
				fengshan(0);    //??? 风扇关闭
		    }
         delay_ms(150);
				for(m=0;m<2000;m++)
				{
					  if(huoyan1==0||huoyan2==0||huoyan3==0)  //!!!!??????
					 {
					   for(k=0;k<25;k++)
						{
		           fengshan(1);       
						   duojixuanzhuan();          //???
            }
					 }
					 else
					 fengshan(0);	  
				}	
	flag=1;
}
void duojixuanzhuan(void)
{
	TIM_SetCompare4(TIM3,175); 
//	delay_ms();
}

void fengshan(u16 c)
{
	if(c==1)
	{
  ENC=1;
	IN5=1;
	IN6=0; //需要正反转方向调试
	}
	else if(c==0)
	{
		ENC=0;
		IN5=0;
		IN6=0;
	}
}
