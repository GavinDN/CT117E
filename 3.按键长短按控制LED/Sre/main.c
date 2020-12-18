#include "stm32f10x.h"
#include "lcd.h"
#include "io.h"

u32 TimingDelay = 0;
u8 KEY_Flag = 0;

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
	KEY_Init();
	while(1)
	{
		if(KEY_Flag)
		{
			KEY_Flag = 0;
			KEY_Read();
		}
	}
}

//
void Delay_Ms(u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);	
}
