
#define GPIOA_BASE   0x48000000
#define RCC_AHB2ENR (*((unsigned int*)0x4002104c))
#define GPIOA_MODER (*((unsigned int*)GPIOA_BASE))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define MODE_MASK(bit) ~(0x3 << (bit * 2))
#define MODE_GPIO(bit) (0x01 << (bit * 2))

#define BIT(bitpos) (1 << bitpos)


int counter = 0;

int func1(int n1, int n2, int n3, int n4, int n5);
void func2(void);

int main()
{
    unsigned int nTemp;
    
    // call test function
    func2();
    
    nTemp = RCC_AHB2ENR;
//    RCC_AHB2ENR = nTemp | 0x1; // RCC_AHB2ENR:  Enable clock for GPIOA
    // use bit-band address instead
    *((unsigned int *)((0x42000000) + (0x2104c * 32) + (0 * 4))) = 0x1;
    
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
//    return 0;
}

int func1(int n1, int n2, int n3, int n4, int n5)
{
    int sum = n1 + n2 + n3 + n4 + n5;
    
    return sum;
}

void func2(void)
{
    int x = func1(17, 33, 234, 1, 29);
}