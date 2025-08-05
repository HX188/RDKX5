#ifndef __WS2812_H
#define __WS2812_H
#include "stm32f1xx.h"

#define WS2812_LED_NUM		8									//��������
#define WS2812_BUF_SIZE		WS2812_LED_NUM * 24 + 2				//�����ֽ���

void RGB_SetFullColor(uint8_t r, uint8_t g, uint8_t b);			//���ô�ɫ
void RGBset_mode1(float time);	//���䴿ɫ
void RGBset_mode2(float time);	//������ˮ
void RGBset_mode3(uint8_t r, uint8_t g, uint8_t b, float time);	//��ת���
void RGBset_mode4(uint8_t r, uint8_t g, uint8_t b, float time);	//��ת���
void RGBset_mode5(uint8_t r, uint8_t g, uint8_t b, float time);	//ǰ��ָʾ��
void RGBset_mode6(uint8_t r, uint8_t g, uint8_t b, float time);	//����ָʾ��
void RGBset_mode7(uint8_t r, uint8_t g, uint8_t b, float bias, float time);	//ģ���۾�
void RGBset_mode8(float time);	//��ʾ��

#endif
