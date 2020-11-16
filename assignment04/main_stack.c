#include <assert.h>
#include "stack.h"

int main()
{
    int testVal;
    int result1;
    int result2;
    
    // *******************************************************************
    // Test1: Try to pop a value from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    result1 = stack_empty();
    result2 = stack_pop(&testVal);
      
    // Assert:
    assert(1 == result1);
    assert(45 == testVal);

    // *******************************************************************
    // Test2: Pop a value from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    result1 = stack_push(99);
    result2 = stack_pop(&testVal);
      
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(99 == testVal);

    
    // *******************************************************************
    // Test3: Fill the stack, then retrieve all values in reverse order
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    stack_push(42);
    stack_push(7);
    stack_push(99);
      
    // Assert:
    assert(1 == stack_full());
    
    assert(0 == stack_pop(&testVal));
    assert(99 == testVal);
    
    assert(0 == stack_pop(&testVal));
    assert(7 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(42 == testVal);

    assert(1 == stack_empty());

    // *******************************************************************
    // Test4: Fill the stack, then try to add one more - should fail
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    stack_push(42);
    stack_push(7);
    stack_push(99);
    result1 = stack_push(127);
    
    // Assert:
    assert(-1 == result1);
    
    // make sure stack still functions properly after error
    assert(1 == stack_full());
    assert(0 == stack_pop(&testVal));
    assert(99 == testVal);
    
    assert(0 == stack_pop(&testVal));
    assert(7 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(42 == testVal);

    assert(1 == stack_empty());


    // *******************************************************************
    // Test5: Fill stack, pop one value, then push another value
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    stack_push(42);
    stack_push(7);
    stack_push(99);
    
    // Assert:
    assert(1 == stack_full());
    assert(0 == stack_empty());
    assert(0 == stack_pop(&testVal));
    assert(99 == testVal);
    assert(0 == stack_full());
    assert(0 == stack_empty());
    
    assert(0 == stack_push(127));
    assert(1 == stack_full());
           
    assert(0 == stack_pop(&testVal));
    assert(127 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(7 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(42 == testVal);

    assert(1 == stack_empty());


    // *******************************************************************
    // Test5: Fill stack, pop all values, then repeat
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testVal = 45;
    stack_init();
    
    // Act:
    stack_push(42);
    stack_push(7);
    stack_push(99);
    
    // Assert:
    assert(0 == stack_pop(&testVal));
    assert(99 == testVal);
    
    assert(0 == stack_pop(&testVal));
    assert(7 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(42 == testVal);

    assert(1 == stack_empty());
    
    assert(0 == stack_push(142));
    assert(0 == stack_push(999));
    assert(0 == stack_push(1233));
    assert(1 == stack_full());
        
    assert(0 == stack_pop(&testVal));
    assert(1233 == testVal);
    
    assert(0 == stack_pop(&testVal));
    assert(999 == testVal);

    assert(0 == stack_pop(&testVal));
    assert(142 == testVal);
    
    return 0;
}
