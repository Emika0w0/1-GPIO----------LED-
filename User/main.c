/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	

  uint8_t LED1 = 0;
  uint8_t LED2 = 0;
  uint8_t LED3 = 0;

	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();

  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
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
		LED1_ON;			  // ��
    SOFT_DELAY;
    LED1_OFF;		   // ��


    LED1 = 0;
    LED2 = 1;
    LED3 = 0;
    Usart_SendByte( DEBUG_USARTx,LED2);
		LED2_ON;			 // ��
		SOFT_DELAY;
		LED2_OFF;		   // ��


    LED1 = 0;
    LED2 = 0;
    LED3 = 1;
    Usart_SendByte( DEBUG_USARTx,LED3);
    LED3_ON;			 // ��
		SOFT_DELAY;
		LED3_OFF;		   // ��

	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
