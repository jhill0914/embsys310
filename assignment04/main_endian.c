
int IsBigEndian()
{
    unsigned int testVal = 0x01020304;
    unsigned char *pTest = (unsigned char *)&testVal;
    
    // if the processor is big endian, *pTest will be 0x01 (MSB).  If little
    // endian, it will be 0x04 (LSB);
    return (*pTest == 0x01 ? 1 : 0);
}

int main()
{
    int test;
    
    if (IsBigEndian())
        test = 1;
    else
        test = 0;
    
    
    return 0;
}
