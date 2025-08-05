#include "stm32f1xx.h"
#include "math.h"
#include "PID.h"
#include "motor.h"

#define SPEED_LIMIT_MIN		-2032.0f
#define SPEED_LIMIT_MAX		 2032.0f
#define YAW_LIMIT_MIN		-90.0f
#define YAW_LIMIT_MAX		 90.0f
#define ROTATE_LIMIT_MIN	-120.0f
#define ROTATE_LIMIT_MAX	 120.0f

PID_struct motor_speed[4] = {{1.482f, 0.384f, 0.0f,   0.0f,0.0f,0.0f,0.0f,0.0f},
							 {1.086f, 0.343f, 0.0f,   0.0f,0.0f,0.0f,0.0f,0.0f},
							 {1.367f, 0.384f, 0.0f,   0.0f,0.0f,0.0f,0.0f,0.0f},
							 {1.285f, 0.368f, 0.0f,   0.0f,0.0f,0.0f,0.0f,0.0f}};

PID_struct car_location = {222.5f, 0.0f, 215.9f,   0.0f,0.0f,0.0f,0.0f,0.0f};
PID_struct car_yaw = {2.637f, 0.0f, 17.57f,   0.0f,0.0f,0.0f,0.0f,0.0f};
PID_struct car_rotate = {4.84f, 0.0f, 9.67f,   0.0f,0.0f,0.0f,0.0f,0.0f};

/*************************************************/
/******************	 λ��ʽPID  *******************/
/*************************************************/
//pwm=Kp*e(k)+Ki*��e(k)+Kd[e��k��-e(k-1)]
//λ�ñջ�����PD����������
float PID_location(float target, float actualvalue, PID_struct *PID)
{	//λ�û�
	PID->ek = target - actualvalue;
	if(PID->ek <= 0.3f && PID->ek >=-0.3f) {
		PID->ek = 0.0f;
	}
	PID->ek_sum += PID->ek;
	
	PID->out = PID->kp * PID->ek
			 + PID->ki * PID->ek_sum
			 + PID->kd * (PID->ek - PID->ek1);
	
	PID->ek1 = PID->ek;
	
	if(PID->out < SPEED_LIMIT_MIN)		PID->out = SPEED_LIMIT_MIN;
	else if(PID->out > SPEED_LIMIT_MAX)	PID->out = SPEED_LIMIT_MAX;
	
	
	return PID->out;
}
/*%%%%%%%%%%%%%%%%%%%%*/
float PID_yaw(float target, float actualvalue, PID_struct *PID)
{	//�ǶȻ��������ǣ�
	PID->ek = target - actualvalue;
	if(PID->ek > 180.0f) PID->ek -= 360.0f;
	else if(PID->ek < -180.0f) PID->ek += 360.0f;
	
	if(PID->ek <= 0.5f && PID->ek >=-0.5f) {
		PID->ek = 0.0f;
	}
	
	PID->ek_sum += PID->ek;
	
	PID->out = PID->kp * PID->ek
			 + PID->ki * PID->ek_sum
			 + PID->kd * (PID->ek - PID->ek1);
	
	PID->ek1 = PID->ek;
	
	if(PID->out < YAW_LIMIT_MIN)		PID->out = YAW_LIMIT_MIN;
	else if(PID->out > YAW_LIMIT_MAX)	PID->out = YAW_LIMIT_MAX;
	
	return PID->out;
}
/*%%%%%%%%%%%%%%%%%%%%*/
float PID_rotate(float target, float actualvalue, PID_struct *PID)
{	//�ǶȻ�����̼ƣ�
	PID->ek = target - actualvalue;
	if(PID->ek > 180.0f) PID->ek -= 360.0f;
	else if(PID->ek < -180.0f) PID->ek += 360.0f;
	
	if(PID->ek <= 0.3f && PID->ek >=-0.3f) {
		PID->ek = 0.0f;
	}
	
	PID->ek_sum += PID->ek;
	
	PID->out = PID->kp * PID->ek
			 + PID->ki * PID->ek_sum
			 + PID->kd * (PID->ek - PID->ek1);
	
	PID->ek1 = PID->ek;
	
	if(PID->out < ROTATE_LIMIT_MIN)			PID->out = ROTATE_LIMIT_MIN;
	else if(PID->out > ROTATE_LIMIT_MAX)	PID->out = ROTATE_LIMIT_MAX;
	
	return PID->out;
}
/*************************************************/
/******************	 ����ʽPID  *******************/
/*************************************************/
//pidout+=Kp[e(k)-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
//�ٶȱջ�����PI����������
float PID_increment(float target, float actualvalue, PID_struct *PID)
{	//�ٶȻ�
	PID->ek = target - actualvalue;
	
	PID->out += PID->kp * (PID->ek - PID->ek1)
			  + PID->ki * PID->ek
			  + PID->kd * (PID->ek - 2*PID->ek1 + PID->ek2);
  
	PID->ek2 = PID->ek1;
	PID->ek1 = PID->ek;  
	
	return PID->out;
}

/*************************************************/
/*******************  PID����  ********************/
/*************************************************/
static float my_distance(float x, float y)
{	//�����
	return sqrtf(x*x + y*y);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void PID_mode0(float targetx, float targety, float targetz, int *icnt, float *wheelspeed, int *cnt, float *pwmset)
{	//(cm, cm, angle, I_CNT, CNT --> PWM)
	float certainx = 0.0f, certainy= 0.0f, certainz= 0.0f;
	float map[4] = {0};
	
	for(int i=0; i<4; i++) map[i] = (float)icnt[i] * locationmap;
	Forward_Kinematics(map, &certainx, &certainy, &certainz);
	certainz *= toangle;
	
	float difx = targetx-certainx, dify = targety-certainy;
	float targetxy = my_distance(difx, dify);
	float angle_rad = atan2f(dify, difx);
	
	float speed = PID_location(targetxy, 0, &car_location);
	float speedz = PID_rotate(targetz, certainz, &car_rotate);
	
	Backward_Kinematics(speed*cosf(angle_rad), speed*sinf(angle_rad), speedz/toangle, wheelspeed);
	
	for(int i=0; i<4; i++){
		pwmset[i] = PID_increment(wheelspeed[i], cnt[i], &(motor_speed[i]));
		if(car_location.ek<0.1f && car_location.ek>-0.1f && car_rotate.ek<0.1f && car_rotate.ek>-0.1f) {
			motor_speed[i].out = 0.0f;	//����ٶȻ��������
		}
	}
}
/*%%%%%%%%%%%%%%%%%%%%*/
void PID_mode1(float targetx, float targety, float targetyaw, float yaw, int *icnt, float *wheelspeed, int *cnt, float *pwmset)
{	//(cm, cm, angle, angle, I_CNT, CNT --> PWM)
	float certainx = 0.0f, certainy= 0.0f, certainz= 0.0f;
	float map[4] = {0};
	
	for(int i=0; i<4; i++) map[i] = (float)icnt[i] * locationmap;
	Forward_Kinematics(map, &certainx, &certainy, &certainz);
	
	float difx = targetx-certainx, dify = targety-certainy;
	float targetxy = my_distance(difx, dify);
	float angle_rad = atan2f(dify, difx);
	
	float speed = PID_location(targetxy, 0, &car_location);
	float speedyaw = PID_yaw(targetyaw, yaw, &car_yaw);
	
	Backward_Kinematics(speed*cosf(angle_rad), speed*sinf(angle_rad), speedyaw/toangle, wheelspeed);
	
	for(int i=0; i<4; i++){
		pwmset[i] = PID_increment(wheelspeed[i], cnt[i], &(motor_speed[i]));
		if(car_location.ek<0.1f && car_location.ek>-0.1f && car_yaw.ek<0.1f && car_yaw.ek>-0.1f) {
			motor_speed[i].out = 0.0f;	//����ٶȻ��������
		}
	}
}
/*%%%%%%%%%%%%%%%%%%%%*/
void PID_mode2(float targetx, float targety, float targetz, float *wheelspeed, int *cnt, float *pwmset)
{	//(cm/s, cm/s, angle/s --> CNT)
	Backward_Kinematics(-targetx*speedmap, targety*speedmap, targetz/toangle, wheelspeed);
	
	for(int i=0; i<4; i++){
		pwmset[i] = PID_increment(wheelspeed[i], cnt[i], &(motor_speed[i]));
	}
}
