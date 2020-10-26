# Answers to Assignment 2 Quesions

1a.  counter = -2147483648  
1b.  R1 = 0x80000000  
1c.  ASPR.N = 1, because the most significant (sign) bit is set to 1;  ASPR.V = 1, because an overflow happened when 1 was added to the maximum positive value (0x7fffffff), and it rolled over to max negative value of 0x80000000
&nbsp;  

2a.  counter = 0  
2b.  ASPR.N = 0, because 0 is not negative;  ASPR.V = 0, because the value incremented from -1 to 0.  Even though the hex value rolled over from 0xffffffff to 0, the end result was -1 to 0 which is not an overflow but an actual expected condition  
&nbsp;

3a.  counter = 2147483648  
3b.  ASPN.N and ASPR.V are both 1, as in the overflow condition with the signed value.  At the low level of the ASPR register, it must assume that the values are signed and that the leftmost bit is the sign bit.  Signed vs unsigned handling must happen at a higher level  
&nbsp;

4a.  counter = 0  
4b.  ASPR.N and ASPR.V are both zero, as they were in question 2 when the counter incremented from 0xffffffff to 0.  Again, it seems that the ASPR registers assume that the values are signed, and the unsigned aspect is handled elsewhere  
&nbsp;

5a.  scope of counter is now global
5b.  no, counter is not in the Locals window
5c.  counter can be tracked in the Watch window
5d.  counter is at memory address 0x20000000
&nbsp;

6a.  counter = 4
6b.  The counter variable is stored at memory address 0x20000000.  p_int is a pointer that is set to point to that same memory address, 0x20000000.  Incrementing the value pointed to by p_int is the same as incremenenting counter, because they both reference the same memory location
&nbsp;

7a.  counter is still at address 0x20000000
7b.  memory address 0x20000000 is start of the SRAM address space, so it is stored in RAM
7c.  counter = 4
