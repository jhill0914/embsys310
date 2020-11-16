// stack.c

#include "stack.h"

static int m_stack[STACK_SIZE];
static int m_stackPos;

void stack_init(void)
{
    m_stackPos = 0;
    for (int x = 0; x < STACK_SIZE; ++x)
        m_stack[x] = '\0';
}

int stack_push(int val)
{
    int retVal = -1;
    
    if (m_stackPos < STACK_SIZE)
    {
        m_stack[m_stackPos++] = val;
        retVal = 0;
    }
    return retVal;
}

int stack_pop(int *pVal)
{
    int retVal = -1;
    
    if (m_stackPos > 0)
    {
        *pVal = m_stack[--m_stackPos];
        retVal = 0;
    }
    return retVal;
}

int stack_full(void)
{
    return (m_stackPos < STACK_SIZE ? 0 : 1);
}

int stack_empty(void)
{
    return (m_stackPos == 0 ? 1 : 0);
}