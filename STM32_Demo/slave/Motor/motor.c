#include "stm32f1xx.h"
#include "math.h"
#include "motor.h" 
#include "tim.h"

#define PWM_LIMIT	21000

/*************************************************/
/*****************  电机转向设置  ******************/
/*************************************************/
static void fwd1(void)
{	//motor1正转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
}
static void fwd2(void)
{	//motor2正转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_SET);
}
static void fwd3(void)
{	//motor3正转
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12, GPIO_PIN_SET);
}
static void fwd4(void)
{	//motor4正转
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9, GPIO_PIN_RESET);
}
/*%%%%%%%%%%%%%%%%%%%%*/
static void back1(void)
{	//motor1反转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_SET);
}
static void back2(void)
{	//motor2反转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
}
static void back3(void)
{	//motor3反转
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12, GPIO_PIN_RESET);
}
static void back4(void)
{	//motor4反转
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9, GPIO_PIN_SET);
}
/*%%%%%%%%%%%%%%%%%%%%*/
static void stop1(void)
{	//motor1停转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
}
static void stop2(void)
{	//motor2停转
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
}
static void stop3(void)
{	//motor3停转
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12, GPIO_PIN_RESET);
}
static void stop4(void)
{	//motor4停转
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9, GPIO_PIN_RESET);
}

/*************************************************/
/*****************  电机输出设置  ******************/
/*************************************************/
static int my_abs_int(int a)
{	//取绝对值并限幅
	if(a < 0)
		a = -a;
	if(a > PWM_LIMIT) a = PWM_LIMIT;
	
	return a;
}
/*%%%%%%%%%%%%%%%%%%%%*/
void set_PWM(int Pwm1, int Pwm2, int Pwm3, int Pwm4)
{	//设置转向和占空比
	if(Pwm1 > 0)		fwd1();
	else if(Pwm1 < 0)	back1();
	else				stop1();
	
	if(Pwm2 > 0)		fwd2();
	else if(Pwm2 < 0)	back2();
	else				stop2();
	
	if(Pwm3 > 0)		fwd3();
	else if(Pwm3 < 0)	back3();
	else				stop3();
	
	if(Pwm4 > 0)		fwd4();
	else if(Pwm4 < 0)	back4();
	else				stop4();
	
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, my_abs_int(Pwm1));
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, my_abs_int(Pwm2));
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, my_abs_int(Pwm3));
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, my_abs_int(Pwm4));
}

/*************************************************/
/***************  Mecanum运动学解算  ***************/
/*************************************************/
/*
*	接触地面姿态：				|		俯视姿态：
*			front				|				front
*	motor1	//  \\	motor2		|		motor1	\\  //	motor2
*								|
*								|
*	motor3	\\  //	motor4		|		motor3	//  \\	motor4
*			 back				|				 back
*/
void Backward_Kinematics(float X, float Y, float Z, float *wheel_speed)
{	//后向解算（CNT, CNT, rad/s --> CNT）
	wheel_speed[0] =  X + Y - Z*dic*speedmap;
	wheel_speed[1] = -X + Y + Z*dic*speedmap;
	wheel_speed[2] = -X + Y - Z*dic*speedmap;
	wheel_speed[3] =  X + Y + Z*dic*speedmap;
}
/*%%%%%%%%%%%%%%%%%%%%*/
void Forward_Kinematics(float *wheel_speed, float *X, float *Y, float *Z)
{	//前向解算（cm --> cm, cm, rad）
	*X = ( wheel_speed[0] - wheel_speed[1] - wheel_speed[2] + wheel_speed[3]) / (4.0f);
	*Y = ( wheel_speed[0] + wheel_speed[1] + wheel_speed[2] + wheel_speed[3]) / (4.0f);
	*Z = (-wheel_speed[0] + wheel_speed[1] - wheel_speed[2] + wheel_speed[3]) / (4.0f*dic);
	
	*Z = fmodf(*Z, 2.0f*pi);
	if(*Z < -pi)		*Z += 2.0f*pi;
	else if(*Z > pi)	*Z -= 2.0f*pi;
}
