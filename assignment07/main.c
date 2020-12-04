
#include "stm32l475xx.h"

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup

int counter = 0;

void SysTick_Init(void);
void Delay(uint32_t delayMs);

int main()
{
    unsigned int nTemp;
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // set GPIOA_MODER, GPIO5 to output
    nTemp = GPIOA->MODER & ~GPIO_MODER_MODE5_Msk;
    nTemp |= GPIO_MODER_MODE5_0;
    GPIOA->MODER = nTemp;
    
    SysTick_Init();
    
    while (1)
    {
        // toggle GPIO5 using XOR
        GPIOA->ODR ^= GPIO_ODR_OD5;
        
        // delay for 1 second
        Delay(1000);
    }
    //return 0;
}

void SysTick_Init(void)
{
    SysTick->LOAD = (SYS_CLOCK_HZ / 1000) - 1;  // set tick at 1ms
    SysTick->VAL = 0;           // clear any current value
    SysTick->CTRL = 0x7;        // enable systick interrupt
}

static uint32_t m_delayCount;

void Delay(uint32_t delayMs)
{
    m_delayCount = delayMs;
    
    while (m_delayCount > 0) ;
}

void SysTick_Handler(void)
{
    __disable_irq();
    m_delayCount--;
    __enable_irq();
}

