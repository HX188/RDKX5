#ifndef __WS2812_H
#define __WS2812_H
#include "stm32f1xx.h"

#define WS2812_LED_NUM		8									//灯珠数量
#define WS2812_BUF_SIZE		WS2812_LED_NUM * 24 + 2				//单次字节数

void RGB_SetFullColor(uint8_t r, uint8_t g, uint8_t b);			//设置纯色
void RGBset_mode1(float time);	//渐变纯色
void RGBset_mode2(float time);	//渐变流水
void RGBset_mode3(uint8_t r, uint8_t g, uint8_t b, float time);	//左转向灯
void RGBset_mode4(uint8_t r, uint8_t g, uint8_t b, float time);	//右转向灯
void RGBset_mode5(uint8_t r, uint8_t g, uint8_t b, float time);	//前进指示灯
void RGBset_mode6(uint8_t r, uint8_t g, uint8_t b, float time);	//后退指示灯
void RGBset_mode7(uint8_t r, uint8_t g, uint8_t b, float bias, float time);	//模拟眼睛
void RGBset_mode8(float time);	//警示灯

#endif
