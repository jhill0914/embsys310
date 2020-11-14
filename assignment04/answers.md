# What assembly instructions are produced when writing to a bit-band address?
1)  Set value of R0 to 1
2)  Load bitband address into R1
3)  Write value of R0 (1) into address stored in R1 (bit-band address)

# What instructions were produced when not using bit-band address?
When not using bit-band address, the value of the GPIO register had to be loaded and the appropriate bit(s) modified before writing the full register value back to the GPIO register

# How does the calling function **func2** pass values to **func1**?
4 of the parameters are passed in registers R0-R3, with the 5th parameter on the stack

# What extra code did the compiler generate before calling **func1**?
1)  Load 5th parameter value into R0
2)  Store R0 (5th parameter) on the stack
3)  Load 1st through 4th parameter values into R0-R3

# What extra code did the compiler generate inside **func1**?
1)  Save current value of R4 onto stack
2)  Load value of offset 4 on stack (passed parameter 5) into R4
3)  Before returning, pop R4 off the stack to restore the value it had before the function was called

# Other observations?
Parameter 5 stayed on the stack through the call to func1, and the calling function was the one that popped it off the stack when it returned
