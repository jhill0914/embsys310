# Why use two's complement to represent negative numbers?

Representing negative numbers in two's complement form allows all arithmetic operations to occur correctly, regardless of sign.  For instance, adding a number and its two's complement produces a result of zero, which is the desired result.

One's complement was used on older computers, but presented challenges with certain operations depending on the sign of the numbers involved.  Adding a number and its one's complement produces a result of all binary 1s, so an additional operation of adding 1 to the result is required when one of the numbers is negative.  One's complement also requires a negative zero value, which complicates things further.  
