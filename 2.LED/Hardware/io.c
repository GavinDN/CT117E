#include "stm32f10x.h"
#include "io.h"

void LED_Init()//�üĴ�������
{ 
    //����һ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;
	//ʱ��ʹ��APB2������GPIOD��GPIOC �˿ڵ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);


    //��PD2��������Ϊ���
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);

	//��PC8~PC15����������Ϊ�����ֱ��ʹ��GPIO_Pinȥ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = 0xff00;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);


    
	GPIOD->ODR |= (1<<2);//������
	GPIOC->ODR |= 0Xff00;//LEDȫ��
	GPIOD->ODR &= ~(1<<2);//�ر�����
}
