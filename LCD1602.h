#include<stdio.h>
#include<stdint.h>

// Config
typedef struct
{
	volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
}RCC_Typedef;
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile const uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_Typedef;
typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile const uint32_t CALIB;
}SysTick_Typedef;
#define GPIOA ((GPIO_Typedef*) 0x40010800)
#define GPIOB ((GPIO_Typedef*) 0x40010C00)
#define GPIOC ((GPIO_Typedef*) 0x40011000)
#define GPIOD ((GPIO_Typedef*) 0x40011400)
#define GPIOE ((GPIO_Typedef*) 0x40011800)
#define GPIOF ((GPIO_Typedef*) 0x40011C00)
#define GPIOG ((GPIO_Typedef*) 0x40012000)
#define SysTick ((SysTick_Typedef*) 0xE000E010)
#define RCC ((RCC_Typedef*)0x40021000) //RCC_Typedef* RCC=0x40021000

// LCD func
void delay_us(uint32_t time);
void SysTick_Init();
#define commandport GPIOA->ODR
#define rs 10
#define e 9
#define dataport GPIOB->ODR
#define eset() GPIOA->BSRR|=(1<<e)
#define eclear() GPIOA->BRR|=(1<<e)
void lcd_pulse();
void lcd_sendcommand(uint32_t cmd);
void lcd_senddata(uint32_t data);
void lcd_initialize();
void lcd_printf(char c[]);
void delay1s(uint32_t time);
