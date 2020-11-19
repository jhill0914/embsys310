# 1a. Explain what the “main” function does in order to setup the input arguments prior to
calling the swap_pointer() function?

The main() function sets up the integer values and the pointers on the stack, and sets R0 and R1 to the stack address of the integer pointers

# 1b. What are the values in R0 & R1 when swap_pointer() is called?

R0 is the address of pX (on the stack), and R1 is the address of pY (on the stack)

# 1c. Share a screen shot of the local variables inside of “main” after the function
swap_pointer() returns

!(swap_pointers.jpg)

