/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	

  uint8_t LED1 = 0;
  uint8_t LED2 = 0;
  uint8_t LED3 = 0;

	/* LED 端口初始化 */
	LED_GPIO_Config();

  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();

  while (1)
  {

    LED1 = 1;
    LED2 = 0;
    LED3 = 0;
    Usart_SendByte( DEBUG_USARTx,LED1);
    Usart_SendByte( DEBUG_USARTx,"LED1");
    Usart_SendByte( DEBUG_USARTx,"LED1");
    Usart_SendByte( DEBUG_USARTx,"LED1");
		LED1_ON;			  // 亮
    SOFT_DELAY;
    LED1_OFF;		   // 灭


    LED1 = 0;
    LED2 = 1;
    LED3 = 0;
    Usart_SendByte( DEBUG_USARTx,LED2);
		LED2_ON;			 // 亮
		SOFT_DELAY;
		LED2_OFF;		   // 灭


    LED1 = 0;
    LED2 = 0;
    LED3 = 1;
    Usart_SendByte( DEBUG_USARTx,LED3);
    LED3_ON;			 // 亮
		SOFT_DELAY;
		LED3_OFF;		   // 灭

	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
