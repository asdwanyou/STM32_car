#ifndef __MOTOR_H
#define __MOTOR_H
#define	MOTOR_IN1_LOW			(GPIO_ResetBits(GPIOA,GPIO_Pin_3 ))
#define	MOTOR_IN1_HIGH		(GPIO_SetBits(GPIOA, GPIO_Pin_3))
#define	MOTOR_IN2_LOW			(GPIO_ResetBits(GPIOA, GPIO_Pin_4))
#define	MOTOR_IN2_HIGH		(GPIO_SetBits(GPIOA, GPIO_Pin_4))

#define	MOTOR_IN3_LOW			(GPIO_ResetBits(GPIOB, GPIO_Pin_5))
#define	MOTOR_IN3_HIGH		(GPIO_SetBits(GPIOB, GPIO_Pin_5))
#define	MOTOR_IN4_LOW			(GPIO_ResetBits(GPIOB, GPIO_Pin_6))
#define	MOTOR_IN4_HIGH		(GPIO_SetBits(GPIOB, GPIO_Pin_6))

#define ENA PAout(2)
#define IN1 PAout(3)
#define IN2 PAout(4)
#define IN3 PAout(5)
#define IN4 PAout(6)
#define ENB PAout(7)
void DoubleMotorInit(void);
void LEFTMOTORz(void);
void LEFTMOTORf(void);
void RIGHTMOTORz(void);
void RIGHTMOTORf(void);
void ALLM_STOP(void);
void go(void);
void left(void);
void right(void);
void avoid1(void);
void avoid2(void);
void room1(void);
void room2(void)

#endif
