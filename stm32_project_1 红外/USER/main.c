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
	PWM_Init(199,1999,199,1999);   //²»È·¶¨ÊÇµ÷Æµ»¹ÊÇµ÷Õ¼¿Õ±ÈÀ´¸Ä±äÁ½ÂÖ²î±ğ ÒÑÒı³ö ÒÔºóĞŞ¸Ä
	TIM_SetCompare3(TIM2,165);    //×óÂÖ
	TIM_SetCompare2(TIM3,166);  //ÓÒÂÖ
	delay_init();
	DoubleMotorInit();
	go();
	delay_ms(41248); //µ÷Ê±¼äµ½¹ıµÀ
	EXTIX_Init();         //´ÓÕâÀïµ½room1 ÖĞ¼äµÄÂ·¾¶ÔÚavoid1 Àï //ĞèÒª²âÊÔÃ¿¸öºìÍâÊÇ·ñÄÜÒı·¢ÖĞ¶Ï £¨ÁéÃô¶È£©
  room1();
	//EXTI_Close();  //ÕâÀïÖ»ÊÇ±£Ö¤ÖĞ¶ÏÍêÈ«¹Ø±Õ
	while(flag)
	{
		go();
		if(L5==0)
		{
			ALLM_STOP();
		  right(); //ÒªÃ´Ô­µØ×ª£¨ÒªÃ´ÀëÇ½Ô¶Ò»Ğ©¹Ì¶¨ÓÒÂÖÆ«×ª£©//Èç¹ûÄÜ¹»±£Ö¤L5ÄÜÊ¶±ğµ½C·¿¼äµÄÇ½¾ÍºÃÁË
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
		}             //ÕâÀïÊÇ¸öÎÊÌâ Ã»ÓĞÌùÇ½×ß ĞèÒª¶àµ÷Ê
	}
		
	while(1)    //´Ó·¿¼äB³öÀ´ ÒÔºó
	{
		if(L1==0&&L2==0&&L5==0)
		{right();}
		else if(huiducishu==?)   //»Ò¶È¼ì²âµ½·¿¼ä »òÕß  if(huidu1==0)  ×¢Òâ¸´Î»
		{room2();}
		else if(L1==1&&L2==0)
		{left();}
		if()  //ÕâÀïÕÒµ½Ò»¸ö´ú±íD·¿¼äÄÜ×ßÍêµÄ±êÖ¾
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