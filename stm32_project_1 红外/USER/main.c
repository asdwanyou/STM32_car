#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "pwm.h"
#include "motor.h"
#include "laser.h"
#include "exti.h"
#include "huoyan.h"
#include "huidu.h"
#include "fan.h"
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
	PWM_Init(199,1999,199,1999);   //��ȷ���ǵ�Ƶ���ǵ�ռ�ձ����ı����ֲ�� ������ �Ժ��޸�
	TIM_SetCompare3(TIM2,165);    //����
	TIM_SetCompare2(TIM3,166);  //����
	delay_init();
	DoubleMotorInit();
	PWM_DJ_Init(199,7199);

	go();
	delay_ms(41248); //��ʱ�䵽����
	EXTIX_Init();         //�����ﵽroom1 �м��·����avoid1 �� //��Ҫ����ÿ�������Ƿ��������ж� �������ȣ�
  room1();
	//EXTI_Close();  //����ֻ�Ǳ�֤�ж���ȫ�ر�
	while(flag)
	{
		go();
		if(L5==0)
		{
			ALLM_STOP();
		  right(); //Ҫôԭ��ת��Ҫô��ǽԶһЩ�̶�����ƫת��//����ܹ���֤L5��ʶ��C�����ǽ�ͺ���
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
		}             //�����Ǹ����� û����ǽ�� ��Ҫ����
	}
		
	while(1)    //�ӷ���B���� �Ժ�
	{
		if(L1==0&&L2==0&&L5==0)
		{right();}
		else if(huiducishu==?)   //�Ҷȼ�⵽���� ����  if(huidu1==0)  ע�⸴λ
		{room2();}
		else if(L1==1&&L2==0)
		{left();}
		if()  //�����ҵ�һ������D����������ı�־
			goto loop1; 
	}
	loop1:key=1;
	while(key)
	{while(1){home();}}

}
 void home()
{
	if(L5==0&&L1==0&&L2==0){
		left();
		ALLM_STOP();
		go();return;
	}else if()


}

