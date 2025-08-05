#ifndef __PID_H
#define __PID_H
#include "stm32f1xx.h"

typedef struct		//PID结构体
{
	float kp;		//比例系数
	float ki;		//积分系数
	float kd;		//微分系数
	float ek;		//当前误差
	float ek1;		//上一次误差e(k-1)
	float ek2;		//上上次误差e(k-2)
	float ek_sum;	//误差积分
	float out;		//PID输出值
}PID_struct;

extern PID_struct motor_speed[4];
extern PID_struct car_location;
extern PID_struct car_yaw;
extern PID_struct car_rotate;

float PID_location(float target, float actualvalue, PID_struct *PID);	//位置环
float PID_yaw(float target, float actualvalue, PID_struct *PID);		//角度环（陀螺仪）
float PID_rotate(float target, float actualvalue, PID_struct *PID);		//角度环（里程计）
float PID_increment(float target, float actualvalue, PID_struct *PID);	//速度环
void PID_mode0(float targetx, float targety, float targetz, int *icnt, float *Wheelspeed, int *cnt, float *pwmset);
void PID_mode1(float targetx, float targety, float targetyaw, float yaw, int *icnt, float *wheelspeed, int *cnt, float *pwmset);
void PID_mode2(float targetx, float targety, float targetz, float *wheelspeed, int *cnt, float *pwmset);

#endif
