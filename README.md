# C_code_snippets

## nth_left_truncatable_prime

**Description**
```
The input of the program is a single integer, (1 ≤ n ≤ 2166), and the output is an n-th left-truncatable prime.
https://en.wikipedia.org/wiki/Truncatable_prime
```
**Example:**
```
input = 10, output = 47; input = 100, output = 5167; input = 1000, output = 8391283.
```
**Tests**
```
Platform 1:
    PC, i5, 8G.

Compiler:
    GCC (gcc -Wall -Ofast -o nth_left_truncatable_prime nth_left_truncatable_prime.c -lrt)

Application name:
    nth_left_truncatable_prime

Usage:
    nth_left_truncatable_prime <nth_ltp>

Example:
    Elapsed time during execution:
    ./nth_left_truncatable_prime 2166
  	Time duration: 0.044493 sec.
	  Number = 999962683

Memory usage during execution:
    valgrind --tool=massif --heap=yes --stacks=yes --time-unit=B ./nth_left_truncatable_prime 2166

    KB
3.977^        #                                                               
     |        #                                                               
     |        #                                                               
     |        #                                                               
     |        #                                                               
     |       :#                                                               
     | @     :#                                                               
     | @  :  :#                                                    :          
     | @  : ::#                                                    ::         
     | @  : ::#                                                    ::         
     | @: : ::#                                                    :::        
     | @: : ::#::            @                      :              :::        
     | @: : ::#::            @                      :              :::        
     | @: ::::#::     @ :    @                ::: :::@ : :::       :::        
     | @: ::::#::    :@ : @::@:::      ::@:::@:::::::@ :::@:      ::::        
     |:@::::::#::::: :@:::@: @ :::@::@@::@:::@:::::::@::::@:      ::::   :    
     |:@::::::#::: : :@:::@: @ :::@::@ ::@:::@:::::::@::::@:      ::::   :    
     |:@::::::#::: :::@:::@: @ :::@::@ ::@:::@:::::::@::::@:     ::::::  :    
     |:@::::::#::: : :@:::@: @ :::@::@ ::@:::@:::::::@::::@:::   :::::@::::@::
     |:@::::::#::: : :@:::@: @ :::@::@ ::@:::@:::::::@::::@:::::::::::@::::@::
   0 +----------------------------------------------------------------------->KB
     0                                                                   337.8

Peak memory usage: 3.977 kB.

Total number of bytes allocated/deallocated on the heap and stack(s): 337.8 kB

################################################################################

Platform 2:
	MCU:
		STM32F401RET6
	Board:
		http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/LN1847/PF260000?icmp=nucleo-ipf_pron_pr-nucleo_feb2014&sc=nucleoF401RE-pr
	Compiler:
		Pre-built GNU toolchain from ARM Cortex-M & Cortex-R processors (Cortex-M0/M0+/M3/M4/M7, Cortex-R4/R5/R7)

Source code:
	ltp_main.c

The elapsed time during execution is approximately 1 second for the 2166-th LTP.
```

## weighted_moving_average_filter

**Description**
```
A weighted average is an average that has multiplying factors to give different weights to data at different positions in the sample window.
https://en.wikipedia.org/wiki/Moving_average
```
**Example:**
```
Input data set: 0, 1, 5, 50, 200, 500, 1000, 500, 200, 50, 5, 1, 0.
Expected output data set: 0, 0, 1, 18, 81, 230, 513, 563, 480, 336, 188, 71, 21.
```
