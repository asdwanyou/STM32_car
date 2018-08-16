#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
//#include "led.h"
#include "pwm.h"
#include "motor.h"
#include "laser.h"
#include "exti.h"
#include "huoyan.h"
#include "huidu.h"
extern u16 huiducishu;
u16 key;
u16 flag=0;
void miehuo();
void home();
void fengshan();
int main(void)
{
	ENA =0;
	ENB =0;
	PWM_Init(199,1999,199,1999);   //不确定是调频还是调占空比来改变两轮差别 已引出 以后修改
	TIM_SetCompare3(TIM2,165);    //左轮
	TIM_SetCompare2(TIM3,166);  //右轮
	delay_init();
	DoubleMotorInit();
	go();
	delay_ms(41248); //调时间到过道
	EXTIX_Init();         //从这里到room1 中间的路径在avoid1 里 //需要测试每个红外是否能引发中断 （灵敏度）
  room1();
	//EXTI_Close();  //这里只是保证中断完全关闭
	while(flag)
	{
		go();
		if(L5==0)
		{
			ALLM_STOP();
		  right(); //要么原地转（要么离墙远一些固定右轮偏转）//如果能够保证L5能识别到C房间的墙就好了
			ALLM_STOP();
			if(L5==0)
			{
				left();
				if(L1==0&&L2==0)
				{
					left();
					room2();
          flag=0;				
				}
			}
		}             //这里是个问题 没有贴墙走 需要多调�
	}
		
	while(1)    //从房间B出来 以后
	{
		if(L1==0&&L2==0&&L5==0)
		{right();}
		else if(huiducishu==?)   //灰度检测到房间 或者  if(huidu1==0)  注意复位
		{room2();}
		else if(L1==1&&L2==0)
		{left();}
		if()  //这里找到一个代表D房间能走完的标志
			goto loop1; 
	}
	loop1:key=1;
	while(key)
	{while(1){home();}}

}
void miehuo()
{
    int n,k;
	       if((huoyan1==0||huoyan2==0||huoyan3==0)&&(huidu3==0||huidu4==0))//????????????
		   {
            for(n=0;n<2000;n++)
            {
								ALLM_STOP();          // ??2000tick
            }
				duojixuanzhuan();         //?????
				for(a=0;a<12000;a++)
				{  
					
					fengshan(1,0,90);   //  ??? 12000tick
				}
				fengshan(1,1,90);    //???
		    }
                delay(150);
				for(m=0;m<2000;m++)
				{
					  if(huoyan1==0||huoyan2==0||huoyan3==0)  //!!!!??????
					 {
					   for(k=0;k<25;k++)
						{
		                   fengshan(1,0,90);       
						   duojixuanzhuan();          //???
                        }
					    //miehuo();   //???
					 }
					 else
					 fengshan(1,1,90);	  //???		
				}	
	flag=1;
} void home()
{
	if()


}
void duojixuanzhuan(u16 arrM,u16 pscM,u16 cpn)
{





}
void fengshan()