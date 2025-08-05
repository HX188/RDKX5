#include "stm32f1xx.h"
#include "math.h"
#include "ws2812.h"
#include "spi.h"

#define TIM_ZERO	0xC0	//码元0
#define TIM_ONE		0xF8	//码元1

static uint8_t SPI_Buffer1[WS2812_BUF_SIZE];	//SPI1发送缓存
static uint8_t Pixelset[WS2812_LED_NUM][3] = {0x00};

/*************************************************/
/*****************  灯带颜色设置  ******************/
/*************************************************/
static void WS2812_Refresh(const uint8_t pixel[WS2812_LED_NUM][3])
{	//RGB数据编码到SPI码流并发送
	int idx = 1;
	SPI_Buffer1[0] = 0;					// 起始填充
	SPI_Buffer1[WS2812_BUF_SIZE-1] = 0;	// 结束填充

	for(int i=0; i<WS2812_LED_NUM; i++) {
		uint8_t g = pixel[i][1];
		uint8_t r = pixel[i][0];
		uint8_t b = pixel[i][2];

		for(int j=0; j<8; j++)
			SPI_Buffer1[idx++] = (g & (0x01 << (7-j))) ? TIM_ONE : TIM_ZERO;
		for(int j=0; j<8; j++)
			SPI_Buffer1[idx++] = (r & (0x01 << (7-j))) ? TIM_ONE : TIM_ZERO;
		for(int j=0; j<8; j++)
			SPI_Buffer1[idx++] = (b & (0x01 << (7-j))) ? TIM_ONE : TIM_ZERO;
	}

	HAL_SPI_Transmit_DMA(&hspi1, SPI_Buffer1, WS2812_BUF_SIZE);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGB_SetFullColor(uint8_t r, uint8_t g, uint8_t b)
{	//设置纯色
	uint8_t Pixel[WS2812_LED_NUM][3] = {0x00};
	for(int i=0; i<WS2812_LED_NUM; i++) {
		Pixel[i][0] = r;
		Pixel[i][1] = g;
		Pixel[i][2] = b;
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixel);
}

/*************************************************/
/*****************  发光模式设置  ******************/
/*************************************************/
void RGBset_mode1(float time)
{	//渐变纯色
	uint8_t r = 60*cosf(1.1f*time) + 60;
	uint8_t g = 60*cosf(-0.7f*time+2.1f) + 60;
	uint8_t b = 60*cosf(0.5f*time+4.2f) + 60;
	
	RGB_SetFullColor(r, g, b);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode2(float time)
{	//渐变流水
	for(int i=0; i<WS2812_LED_NUM; i++) {
		Pixelset[i][0] = 75*cosf(2.5f*time+0.8f*i) + 75;
		Pixelset[i][1] = 45*cosf(3.1f*time+0.8f*i+2.1f) + 45;
		Pixelset[i][2] = 35*cosf(-2.7f*time-0.8f*i+4.2f) + 35;
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode3(uint8_t r, uint8_t g, uint8_t b, float time)
{	//左转向灯
	uint8_t t = 20 * fmodf(time, 0.6f);
	for(int i=0; i<WS2812_LED_NUM; i++) {
		if(i == t) {
			Pixelset[i][0] = r;
			Pixelset[i][1] = g;
			Pixelset[i][2] = b;
		} else {
			Pixelset[i][0] = 0x00;
			Pixelset[i][1] = 0x00;
			Pixelset[i][2] = 0x00;
		}
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode4(uint8_t r, uint8_t g, uint8_t b, float time)
{	//右转向灯
	uint8_t t = 20 * fmodf(time, 0.6f);
	for(int i=0; i<WS2812_LED_NUM; i++) {
		if(i == WS2812_LED_NUM-t) {
			Pixelset[i][0] = r;
			Pixelset[i][1] = g;
			Pixelset[i][2] = b;
		} else {
			Pixelset[i][0] = 0x00;
			Pixelset[i][1] = 0x00;
			Pixelset[i][2] = 0x00;
		}
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode5(uint8_t r, uint8_t g, uint8_t b, float time)
{	//前进指示灯
	uint8_t t = 12 * fmodf(time, 0.6f);
	for(int i=0; i<WS2812_LED_NUM; i++) {
		if((i==t+WS2812_LED_NUM/2) || (i==WS2812_LED_NUM/2-t)) {
			Pixelset[i][0] = r;
			Pixelset[i][1] = g;
			Pixelset[i][2] = b;
		} else {
			Pixelset[i][0] = 0x00;
			Pixelset[i][1] = 0x00;
			Pixelset[i][2] = 0x00;
		}
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode6(uint8_t r, uint8_t g, uint8_t b, float time)
{	//后退指示灯
	uint8_t t = 12 * fmodf(time, 0.6f);
	for(int i=0; i<WS2812_LED_NUM; i++) {
		if((i==t && i<4) || (i==WS2812_LED_NUM-t && i>3)) {
			Pixelset[i][0] = r;
			Pixelset[i][1] = g;
			Pixelset[i][2] = b;
		} else {
			Pixelset[i][0] = 0x00;
			Pixelset[i][1] = 0x00;
			Pixelset[i][2] = 0x00;
		}
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode7(uint8_t r, uint8_t g, uint8_t b, float bias, float time)
{	//模拟眼睛
	float t = fmodf(time, 3.0f);
	int x = 0;
	if(bias > 1.0f)		x = 1;
	else if(bias < -1.0f)	x = -1;
	int id1 = WS2812_LED_NUM/2-x-2, id2 = WS2812_LED_NUM/2-x+1;
	for(int i=0; i<WS2812_LED_NUM; i++) {
		Pixelset[i][0] = 0x20;
		Pixelset[i][1] = 0x20;
		Pixelset[i][2] = 0x0C;
	}
	if(t<0.12f || (t>0.24f && t<0.36f) || t >0.48f) {
		Pixelset[id1][0] = r;
		Pixelset[id1][1] = g;
		Pixelset[id1][2] = b;
		Pixelset[id2][0] = r;
		Pixelset[id2][1] = g;
		Pixelset[id2][2] = b;
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
/*%%%%%%%%%%%%%%%%%%%%*/
void RGBset_mode8(float time)
{	//警示灯
	float t = fmodf(time, 0.4f);
	for(int i=0; i<WS2812_LED_NUM; i++) {
		Pixelset[i][0] = 0x00;
		Pixelset[i][1] = 0x00;
		Pixelset[i][2] = 0x00;
	}
	if(t<0.2f) {
		for(int i=0; i<WS2812_LED_NUM/2; i++) {
			Pixelset[i][0] = 0x6A;
			Pixelset[WS2812_LED_NUM-i-1][2] = 0x80;
		}
	}
	
	WS2812_Refresh((const uint8_t (*)[3])Pixelset);
}
