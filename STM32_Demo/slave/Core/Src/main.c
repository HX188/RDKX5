/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "PID.h"
#include "motor.h"
#include "ws2812.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mpu6050.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
uint8_t Rx_Buffer1[BUF_SIZE];
uint8_t Rx_Buffer3[BUF_SIZE];

float clk_s = 0.0f, clk_bias = 0.0f;
int CNT[4] = {0};
int I_CNT[4] = {0};
float _I_CNT = 0.0f;
float pitch = 0.0f, roll = 0.0f, yaw = 0.0f;
float yaw_bias = 0.0f;

float Locationset_X = 0.0f, Locationset_Y = 0.0f, Yawset = 0.0f;
float Carspeedset_X = 0.0f, Carspeedset_Y = 0.0f, Carspeedset_Z = 0.0f;
float Wheelspeed[4] = {0.0f};
float Pwmset[4] = {0.0f};

int mpu_flag = 1, loc_flag = 0;
int PIDmode_flag = 0, Lightmode_flag = 0;
int light8_num = 0;

/*%%%%%%%%%%%%%%%%%%%%*/
int receive_value(uint8_t *Rxdata, const char *title, float *data)
{	//数据接收
	float out_int = 0.0f, out_float = 0.0f;
	const char *value = strstr((const char*)Rxdata, title);
	if(value != NULL) {
		value += strlen(title);
		int sign = 1;
		if(*value == '-') {
			sign = -1;
			value++;
		}
		while (*value >= '0' && *value <= '9') {
			out_int = out_int * 10 + (*value - '0');
			value++;
		}
		if (*value == '.') {
			value++;
			float factor = 0.1f;
			while (*value >= '0' && *value <= '9') {
				out_float += (*value - '0') * factor;
				factor *= 0.1f;
				value++;
			}
		}
		*data = sign * (out_int + out_float);
		return 1;
	}
	return 0;
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART1)
    {
		if(receive_value(Rx_Buffer1, "wake_angle=", &Yawset)) {			//语音唤醒
			Yawset -= wake_bias;
			if(Yawset < 0.0f) Yawset += 360.0f;
			else if(Yawset > 360.0f) Yawset -= 360.0f;
			if(Yawset > 180.0f) Yawset -= 360.0f;
			Locationset_X = 0.0f;
			Locationset_Y = 0.0f;
			mpu_flag = 1;
			loc_flag = 1;
			PIDmode_flag = 1;
			Lightmode_flag = 9;
		} else if(receive_value(Rx_Buffer1, "speed=", &Carspeedset_Y)){	//目标跟随和APP遥控
			receive_value(Rx_Buffer1, "rotate=", &Carspeedset_Z);
			const char *trip = strstr((const char*)Rx_Buffer1, "trip");
			if(trip != NULL)	Lightmode_flag = 8;	//若摔倒
			else				Lightmode_flag = 7;
			if(!receive_value(Rx_Buffer1, "cross=", &Carspeedset_X)) {	//遥控才有corss
				Carspeedset_X = 0.0f;
				Lightmode_flag = 2;
			}
			Carspeedset_X *= 100;
			Carspeedset_Y *= 100;
			Carspeedset_Z *= 400;
			PIDmode_flag = 2;
		} else {														//语音和手势控制
			const char *order = strstr((const char*)Rx_Buffer1, "order=");
			if(order != NULL) {
				switch(order[6]) {
					case '1':
						Locationset_X = 0.0f;
						Locationset_Y = 40.0f;
						Yawset = 0.0f;
						Lightmode_flag = 5;
						break;
					case '2':
						Locationset_X = 0.0f;
						Locationset_Y = -40.0f;
						Yawset = 0.0f;
						Lightmode_flag = 6;
						break;
					case '3':
						Locationset_X = -40.0f;
						Locationset_Y = 0.0f;
						Yawset = 0.0f;
						Lightmode_flag = 3;
						break;
					case '4':
						Locationset_X = 40.0f;
						Locationset_Y = 0.0f;
						Yawset = 0.0f;
						Lightmode_flag = 4;
						break;
					case '5':
						Locationset_X = 0.0f;
						Locationset_Y = 0.0f;
						Yawset = 90.0f;
						Lightmode_flag = 3;
						break;
					case '6':
						Locationset_X = 0.0f;
						Locationset_Y = 0.0f;
						Yawset = -90.0f;
						Lightmode_flag = 4;
						break;
					default:
						break;
				}
				mpu_flag = 1;
				loc_flag = 1;
				PIDmode_flag = 1;
			}
		}
		
		memset(Rx_Buffer1, 0, BUF_SIZE);
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1, Rx_Buffer1, BUF_SIZE);
		__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
	}
	else if(huart->Instance == USART3)
    {
			
		memset(Rx_Buffer3, 0, BUF_SIZE);
		HAL_UARTEx_ReceiveToIdle_IT(&huart3, Rx_Buffer3, BUF_SIZE);
	}
}
/*%%%%%%%%%%%%%%%%%%%%*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		clk_s += 0.01f;
		/*****读编码器*****/
		CNT[0] = (int)__HAL_TIM_GET_COUNTER(&htim1);
		__HAL_TIM_SET_COUNTER(&htim1, 0);
		CNT[1] = (int)__HAL_TIM_GET_COUNTER(&htim2);
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		CNT[2] = (int)__HAL_TIM_GET_COUNTER(&htim3);
		__HAL_TIM_SET_COUNTER(&htim3, 0);
		CNT[3] = (int)__HAL_TIM_GET_COUNTER(&htim8);
		__HAL_TIM_SET_COUNTER(&htim8, 0);
		for(int i=0; i<4; i++) {
			if(CNT[i] > 32768) {CNT[i] -= 65536;}
			I_CNT[i] += CNT[i];
		}
		if(loc_flag) {
			for(int i=0; i<4; i++) I_CNT[i] = 0;
			loc_flag = 0;
		}
		
		/*****读MPU6050*****/
		mpu_dmp_get_data(&pitch, &roll, &yaw);
		if(mpu_flag) {
			clk_bias = clk_s;
			yaw_bias = yaw;
			mpu_flag = 0;
		}
		yaw = yaw - yaw_bias - yaw_k*(clk_s-clk_bias);	//消零漂
		if(yaw < 0.0f) {
			yaw += 360.0f;
		} else if(yaw > 360.0f) {
			yaw -= 360.0f;
		}
		if(yaw > 180.0f) yaw -= 360.0f;	//区间转换
		
		/*****PWM_out*****/
		if(PIDmode_flag == 1) {
			PID_mode1(Locationset_X, Locationset_Y, Yawset, yaw, I_CNT, Wheelspeed, CNT, Pwmset);
			set_PWM((int)Pwmset[0], (int)Pwmset[1], (int)Pwmset[2], (int)Pwmset[3]);
		} else if(PIDmode_flag == 2) {
			PID_mode2(Carspeedset_X, Carspeedset_Y, Carspeedset_Z, Wheelspeed, CNT, Pwmset);
			set_PWM((int)Pwmset[0], (int)Pwmset[1], (int)Pwmset[2], (int)Pwmset[3]);
		}
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_TIM1_Init();
	MX_TIM2_Init();
	MX_TIM3_Init();
	MX_TIM5_Init();
	MX_TIM6_Init();
	MX_TIM8_Init();
	MX_USART1_UART_Init();
	MX_I2C1_Init();
	MX_USART3_UART_Init();
	MX_SPI1_Init();
	/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start(&htim5);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
	
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_1|TIM_CHANNEL_2);
	
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, Rx_Buffer1, BUF_SIZE);
	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);
	HAL_UARTEx_ReceiveToIdle_IT(&huart3, Rx_Buffer3, BUF_SIZE);
	
	while(MPU_Init()){
	}
	//printf("MPU_Init finished!\n");
	while(mpu_dmp_init()){
	}
	//printf("mpu_dmp_init finished!\n");
	HAL_Delay(200);
	
	HAL_TIM_Base_Start_IT(&htim6);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		switch(Lightmode_flag) {
			case 1:	//渐变纯色
			  RGBset_mode1(clk_s);
			  break;
			case 2:	//渐变流水
			  RGBset_mode2(clk_s);
			  break;
			case 3:	//左转向灯
			  RGBset_mode3(0x80, 0x80, 0x00, clk_s);
			  break;
			case 4:	//右转向灯
			  RGBset_mode4(0x80, 0x80, 0x00, clk_s);
			  break;
			case 5:	//前进指示灯
			  RGBset_mode5(0x80, 0x80, 0x00, clk_s);
			  break;
			case 6:	//后退指示灯
			  RGBset_mode6(0x80, 0x80, 0x00, clk_s);
			  break;
			case 7:	//模拟眼睛（跟随）
			  RGBset_mode7(0x00, 0x00, 0x80, Yawset, clk_s);
			  break;
			case 8:	//摔倒警示灯
			  RGBset_mode8(clk_s);
			  light8_num ++;
			  if(light8_num >50) {
				  Lightmode_flag = 7;
				  light8_num = 0;
			  }
			  break;
			case 9:	//模拟眼睛（直视）
			  RGBset_mode7(0x00, 0x00, 0x80, 0, clk_s);
			  break;
			default:
			  break;
		}
		HAL_Delay(10);
	/* USER CODE END WHILE */

	/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	* in the RCC_OscInitTypeDef structure.
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
		printf("Error!!!\n");
		HAL_Delay(500);
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
