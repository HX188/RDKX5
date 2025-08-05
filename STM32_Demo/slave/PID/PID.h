#ifndef __PID_H
#define __PID_H
#include "stm32f1xx.h"

typedef struct		//PID�ṹ��
{
	float kp;		//����ϵ��
	float ki;		//����ϵ��
	float kd;		//΢��ϵ��
	float ek;		//��ǰ���
	float ek1;		//��һ�����e(k-1)
	float ek2;		//���ϴ����e(k-2)
	float ek_sum;	//������
	float out;		//PID���ֵ
}PID_struct;

extern PID_struct motor_speed[4];
extern PID_struct car_location;
extern PID_struct car_yaw;
extern PID_struct car_rotate;

float PID_location(float target, float actualvalue, PID_struct *PID);	//λ�û�
float PID_yaw(float target, float actualvalue, PID_struct *PID);		//�ǶȻ��������ǣ�
float PID_rotate(float target, float actualvalue, PID_struct *PID);		//�ǶȻ�����̼ƣ�
float PID_increment(float target, float actualvalue, PID_struct *PID);	//�ٶȻ�
void PID_mode0(float targetx, float targety, float targetz, int *icnt, float *Wheelspeed, int *cnt, float *pwmset);
void PID_mode1(float targetx, float targety, float targetyaw, float yaw, int *icnt, float *wheelspeed, int *cnt, float *pwmset);
void PID_mode2(float targetx, float targety, float targetz, float *wheelspeed, int *cnt, float *pwmset);

#endif
