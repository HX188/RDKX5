# STM32_Demo
* 本目录下的子文件夹slave即为从控STM32端的代码工程。
* 开发平台：STM32CubeMX + Keil；
* 代码库：HAL库；
* 使用芯片：STM32F103RCT6；
* 高速晶振：8MHz；
* 系统时钟：72MHz；
* 建议将Tab size设置为4。

# STM32_Demo/MDK-ARM
* 包含工程文件slave.uvprojx。

# STM32_Demo/Core/Src
* 包含了主文件main.c，其中包括主函数逻辑和一些中断回调函数逻辑。
* 包含了串口初始化配置文件usart.c：启用USART1(波特率115200)并启用全局中断，用于和RDK端主控通讯；开启USART1_RX的DMA通道，从而减少CPU资源占用；启用USART1(波特率115200)并启用全局中断，作为调试串口。
* 包含了定时器初始化配置文件tim.c：启用TIM1、TIM2、TIM3、TIM8作为编码器计数器；启用TIM5输出四个通道的PWM；启用TIM6并开启全局中断，进行定时中断服务（10ms）。
* 包含了I2C和SPI外设以及GPIO的初始化配置文件。
* 包含了DMA初始化配置文件dma.c：进行USART1_RX和SPI1_MOSI的DMA配置。

# STM32_Demo/MPU6050DMP
* 包含了MPU6050模块的驱动代码，实现了从官方DMP库到HAL库移植操作。

# STM32_Demo/WS2812
* 包含了WS2812模块的驱动代码，封装了从RGB数据到SPI码流的编码函数；封装了各种模式的等效函数。

# STM32_Demo/Motor
* 包含了电机的驱动代码。
* 包含了Mecanum运动学解算函数，包括正向解算和逆向解算。

# STM32_Demo/PID
* 包含了各环PID函数，以及PID参数。
* 封装了PID串级控制函数。
