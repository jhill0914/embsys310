# How much total ROM your program is occupying?
464 bytes

# How much total RAM your program is using?
8196 bytes

# What part of your program is using the most ROM?
main.o is using the most ROM, and it is all code

# What part of your program is using the most RAM?
8192 of the 8196 bytes are linker created, so that would be the stack

# Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources?
For a small program such as this, you could reduce the size of the stack.  Also, minimizing the use of global / module level variables, as they are allocated from RAM.  Use local variables as much as possible, as they are allocated from the stack, which doesn't change in size
