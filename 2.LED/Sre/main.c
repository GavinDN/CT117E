#include "stm32f10x.h"
#include "lcd.h"
#include "io.h"

u32 TimingDelay = 0;

void Delay_Ms(u32 nTime);

//Main Body
int main(void)
{	
	STM3210B_LCD_Init();
	LCD_Clear(Blue);
	LCD_SetBackColor(Blue);
	LCD_SetTextColor(White);
	
	SysTick_Config(SystemCoreClock/1000);
	LED_Init();

	while(1)
	{
		GPIOC->ODR ^= 0xaa00;//PC8~PC15用来控制8个LED
		GPIOD->ODR |= (1<<2);
		GPIOD->ODR &= ~(1<<2);
		Delay_Ms(1000);//1s延时

	}
}

//
void Delay_Ms(u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);	
}
