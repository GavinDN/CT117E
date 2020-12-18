#include "stm32f10x.h"
#include "io.h"

void KEY_Init(void)//������ʼ������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//ʹ��PA,PB���ŵ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8;
	//��PA0��PA8��PB1��PB2��ģʽ����Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void LED_Init(void)//LED��ʼ������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = 0xff00;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	GPIOD->ODR |= (1<<2);
	GPIOC->ODR |= 0xff00;
	GPIOC->ODR &= ~(1<<2);
}

void KEY_Read(void)
{
	static int i = 0;
	static int Led_Disp1 = 0x0100;
 	static u16 key1_sum = 0,key2_sum = 0;

	if(KEY1 == 0)//�ж�B1�Ƿ���
	{
		key1_sum++;				
		if(key1_sum == 1)//B1�����̰�
		{												
			GPIOC->ODR = ~(Led_Disp1<<i);//��ˮ��λ��
			GPIOD->ODR |= (1<<2);//������	
			GPIOD->ODR &=~(1<<2);//�ر�����
			i++;
			if(i==8)i=0;									
		}
		if(key1_sum == 40)//B1��������
		{									
			GPIOC->ODR ^= 0x8000;
			GPIOD->ODR |= (1<<2);//������	
			GPIOD->ODR &=~(1<<2);//�ر�����	
			key1_sum = 30;//500msִ��һ��							
		}		
	}
	else key1_sum = 0;

	if(KEY2 == 0)//�ж�B2�Ƿ���
	{
		key2_sum++;				
		if(key2_sum == 1)//B2�����̰�
		{	
			i--;
			if(i<1)i=8;						
			GPIOC->ODR = ~(Led_Disp1<<(i-1));//��ˮ��λ��
			GPIOD->ODR |= (1<<2);//������	
			GPIOD->ODR &=~(1<<2);//�ر�����									
		}
		if(key2_sum == 40)//B1��������
		{									
			GPIOC->ODR ^= (1<<15);
			GPIOD->ODR |= (1<<2);//������	
			GPIOD->ODR &=~(1<<2);//�ر�����	
			key2_sum = 39;//50msִ��һ��								
		}			
	}
	else key2_sum = 0;

//	GPIOC->ODR = ~(Led_Disp1<<i);//��ˮ��λ��
//	GPIOD->ODR |= (1<<2);//������	
//	GPIOD->ODR &=~(1<<2);//�ر�����
}
