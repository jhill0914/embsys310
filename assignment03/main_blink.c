
#define GPIOA_BASE   0x48000000
#define RCC_AHB2ENR (*((unsigned int*)0x4002104c))
#define GPIOA_MODER (*((unsigned int*)GPIOA_BASE))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define MODE_MASK(bit) ~(0x3 << (bit * 2))
#define MODE_GPIO(bit) (0x01 << (bit * 2))

#define BIT(bitpos) (1 << bitpos)


int counter = 0;

int main()
{
    unsigned int nTemp;
    
    nTemp = RCC_AHB2ENR;
    RCC_AHB2ENR = nTemp | 0x1; // RCC_AHB2ENR:  Enable clock for GPIOA
    
    // set GPIOA_MODER, GPIO5 to output
    nTemp = GPIOA_MODER;
    nTemp &= MODE_MASK(5);
    nTemp |= MODE_GPIO(5);
    GPIOA_MODER = nTemp;
    
    while (1)
    {
        while (counter < 100000) 
            ++counter;

        counter = 0;
        
        // toggle GPIO5 using XOR
        GPIOA_ODR ^= BIT(5);
    }
    return 0;
}

