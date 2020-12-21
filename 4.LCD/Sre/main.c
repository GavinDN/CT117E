#include "stm32f10x.h"
#include "lcd.h"

u32 TimingDelay = 0;

void Delay_Ms(u32 nTime);

//Main Body
int main(void)
{
	SysTick_Config(SystemCoreClock/1000);

	Delay_Ms(200);
	
	STM3210B_LCD_Init();
	LCD_Clear(Blue);
	LCD_SetBackColor(Blue);
	LCD_SetTextColor(White);
	

	LCD_DrawLine(120,0,320,Horizontal);
	LCD_DrawLine(0,160,240,Vertical);
	Delay_Ms(1000);
	LCD_Clear(Blue);

	LCD_DrawRect(70,210,100,100);
	Delay_Ms(1000);
	LCD_Clear(Blue);

	LCD_DrawCircle(120,160,50);
	Delay_Ms(1000);

	LCD_Clear(Blue);
	LCD_DisplayStringLine(Line4 ,(unsigned char *)"        Gavin       ");
	Delay_Ms(1000);

	LCD_SetBackColor(Blue);
	LCD_DisplayStringLine(Line0,(unsigned char *)"          I         ");	
	LCD_SetBackColor(Blue);
	LCD_DisplayStringLine(Line1,(unsigned char *)"         Have       ");	
	LCD_SetBackColor(Blue);								 
	LCD_DisplayStringLine(Line2,(unsigned char *)"          A         ");
	LCD_SetBackColor(Blue);
	LCD_DisplayStringLine(Line3,(unsigned char *)"        Dream       ");
	LCD_SetBackColor(Blue);
	LCD_DisplayStringLine(Line4,(unsigned char *)"        Today       ");
	LCD_SetBackColor(Blue);						
	LCD_DisplayStringLine(Line5,(unsigned char *)"          !         ");
	LCD_SetBackColor(Blue);	
	LCD_DisplayStringLine(Line6,(unsigned char *)"  Write  by  Gavin  ");
	LCD_SetBackColor(Blue);	
	LCD_DisplayStringLine(Line7,(unsigned char *)"        jluzh       ");	
	LCD_SetBackColor(Blue);	
	LCD_DisplayStringLine(Line8,(unsigned char *)"      2020.12.21    ");
	LCD_SetBackColor(Blue);		
	LCD_DisplayStringLine(Line9,(unsigned char *)"                    ");	
	
	while(1);
}

//
void Delay_Ms(u32 nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);	
}
