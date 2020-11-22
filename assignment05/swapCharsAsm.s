/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping 2 characters
*******************************************************************************/   

    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making divAsm available to other modules.
    PUBLIC swapPointersAsm
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Swap 2 characters
C Prototype     : int swapCharsAsm(char *c1, char *c2)
                : Where c1 and c2 are the characters to swap
Parameters      : R0: char *c1, first character
                : R1: char *c2, second character
Return value    : R0, 0 if chars are equal, 1 if not equal
*******************************************************************************/  
  
swapCharsAsm:

    LDRB R2, [R0]       // load value at address stored in c1 into R2
    LDRB R3, [R1]       // load value at address stored in c2 into R3
    STRB R2, [R1]       // store contents of R2 (*c1) into address stored in c2
    STRB R3, [R0]       // store contents of R3 (*c2) into address stored in c1
    CMP R2, R3          // compare values of R2 (*c1) and R3 (*c2)
    ITE EQ              // IF-THEN block
    MOVEQ R0, #0        // if R2 and R3 are equal, set R0 (return) to 0
    MOVNE R0, #1        // if R2 and R3 are not equal, set R0 to 1
    
    BX LR               // return (with function result in R0)


/*******************************************************************************
Function Name   : swapPointersAsm
Description     : Swap 2 pointers
C Prototype     : void swapCharsAsm(int **p1, int **p2)
                : Where p1 and p2 are the pointers to swap
Parameters      : R0: int **p1, first pointer
                : R1: int **p2, second pointer
Return value    : None
*******************************************************************************/  
  
swapPointersAsm:

    LDR R2, [R0]       // load value at address stored in p1 into R2
    LDR R3, [R1]       // load value at address stored in p2 into R3
    STR R2, [R1]       // store contents of R2 (*p1) into address stored in p2
    STR R3, [R0]       // store contents of R3 (*p2) into address stored in p1
    
    BX LR               // return

    END
