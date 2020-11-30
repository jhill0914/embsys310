
#include "stm32l475xx.h"

int counter = 0;

int main()
{
    unsigned int nTemp;
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // set GPIOA_MODER, GPIO5 to output
    nTemp = GPIOA->MODER & ~GPIO_MODER_MODE5_Msk;
    nTemp |= GPIO_MODER_MODE5_0;
    GPIOA->MODER = nTemp;
    
    while (1)
    {
        while (counter < 100000) 
            ++counter;

        counter = 0;
        
        // toggle GPIO5 using XOR
        GPIOA->ODR ^= GPIO_ODR_OD5;
    }
    //return 0;
}

