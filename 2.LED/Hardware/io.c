#include "stm32f10x.h"
#include "io.h"

void LED_Init()//用寄存器配置
{ 
    //定义一个结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	//时钟使能APB2总线上GPIOD和GPIOC 端口的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);


    //把PD2引脚配置为输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);

	//把PC8~PC15的引脚配置为输出，直接使用GPIO_Pin去配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  = 0xff00;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);


    
	GPIOD->ODR |= (1<<2);//打开锁存
	GPIOC->ODR |= 0Xff00;//LED全灭
	GPIOD->ODR &= ~(1<<2);//关闭锁存
}
