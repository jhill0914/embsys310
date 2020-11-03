

#define GPIOA_BASE   0x48000000
#define RCC_AHB2ENR (*((unsigned int*)0x4002104c))
#define GPIOA_MODER (*((unsigned int*)GPIOA_BASE))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define MODE_MASK(bit) ~(0x3 << (bit * 2))
#define MODE_GPIO(bit) (0x01 << (bit * 2))

#define BIT(bitpos) (1 << bitpos)

#define GPIO5_ON   (GPIOA_ODR |= BIT(5))
#define GPIO5_OFF  (GPIOA_ODR &= ~BIT(5))

#define MORSE_UNIT 100000
#define MORSE_SHORT MORSE_UNIT
#define MORSE_LONG  MORSE_UNIT * 3

#define DELAY(counts) { int counter = 0;  while (counter < counts) ++counter; }

// morse code letters encoded as:
//  bit 2:0 = number of blips
//  bit 7:3 = 0 for short, 1 for long, in reverse order (bit 3 is first blip to be sent)
#define MORSE_ENCODE(numBlips, pattern) (pattern << 3 | numBlips)
#define MORSE_J MORSE_ENCODE(4, 0xE)
#define MORSE_E MORSE_ENCODE(1, 0x0)
#define MORSE_F MORSE_ENCODE(4, 0x4)
#define MORSE_R MORSE_ENCODE(3, 0x2)
#define MORSE_Y MORSE_ENCODE(4, 0xD)

void sendMorseLetter(unsigned char morseChar)
{
    int blipCount = morseChar & 0x7;
    unsigned char pattern = morseChar >> 3;
    unsigned int delay;
    
    for (int x = 0; x < blipCount; ++x)
    {
        // turn LED on
        GPIO5_ON;
        
        // wait for either 1 or 3 morse units, depending on 0 or 1 in right-most bit
        delay = (pattern & 0x1) ? MORSE_LONG : MORSE_SHORT;
        pattern >>= 1;
        DELAY(delay);
            
        // turn LED off
        GPIO5_OFF;
        
        // wait for 1 morse unit
        DELAY(MORSE_SHORT);
    }
    
    // space between letters is 3 units, but we already waited one at the end of the loop,
    // so we need to wait 2 more units
    DELAY(MORSE_UNIT * 2);
}

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
        sendMorseLetter(MORSE_J);
        sendMorseLetter(MORSE_E);
        sendMorseLetter(MORSE_F);
        sendMorseLetter(MORSE_F);
        sendMorseLetter(MORSE_R);
        sendMorseLetter(MORSE_E);
        sendMorseLetter(MORSE_Y);
        
        // need to wait for 7 total units, already waited 3 in the function, so have
        // to wait 4 more
        DELAY(MORSE_UNIT * 4);
    }
    return 0;
}

