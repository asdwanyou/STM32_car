#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
//#include "led.h"
#include "pwm.h"
#include "motor.h"

int main(void)
{
	ENA =0;
	ENB =0;
	PWM_Init(179,3599,179,3599);   //不确定是调频还是调占空比来改变两轮差别 已引出 以后修改
	
	delay_init();
	DoubleMotorInit();
	TIM_SetCompare3(TIM2,160);
	TIM_SetCompare2(TIM3,160);
	while(1)
	{
		DoubleMotorInit();
		IN1=0;
		IN2=1;
		IN3=0;
		IN4=1;
		delay_ms(20000);
		DoubleMotorInit();
		IN1=1;
		IN2=0;
		IN3=1;
		IN4=0;
		delay_ms(20000);
	}






}
