#ifndef __MOTOR_H
#define __MOTOR_H
#include "stm32f1xx.h"

#define pi 			3.1415926536f
#define toangle 	57.2957795131f				//rad --> angle
#define Pulse_Num 	122880.0f					//1024×30×4
#define L 			16.82f
#define W 			19.65f
#define D			7.7f
#define dic			(L + W) / 2.0f
#define speedmap	0.01f*Pulse_Num / (pi*D)	//cm/s --> CNT
#define locationmap	(pi*D) / Pulse_Num			//I_CNT --> cm

void set_PWM(int Pwm1, int Pwm2, int Pwm3, int Pwm4);	//设置转向和占空比
void Backward_Kinematics(float X, float Y, float Z, float *wheel_speed);	//后向解算
void Forward_Kinematics(float *wheel_speed, float *X, float *Y, float *Z);	//前向解算

#endif
