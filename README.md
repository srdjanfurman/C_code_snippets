# C_code_snippets

## Nth_left_truncatable_prime

**Description**
```
This is a program in C for an embedded system that reads in a single integer, n (1 ≤ n ≤ 2166), and outputs the nth left-truncatable prime.
https://en.wikipedia.org/wiki/Truncatable_prime
```
**Example:**
```
The input 10 should give the output 47; the input 100 should give the output 5167; the input 1000 should give the output 8391283.
```
**Tests**
```
Platform 1:
    PC, i5, 8G.

Compiler:
    GCC (gcc -Wall -Ofast -o Nth_left_truncatable_prime Nth_left_truncatable_prime.c -lrt)

Application name:
    Nth_left_truncatable_prime

Usage:
    Nth_left_truncatable_prime <nth_ltp>

Example:
    Elapsed time during execution:
    ./Nth_left_truncatable_prime 2166
  	Time duration: 0.044493 sec.
	  Number = 999962683

Memory usage during execution:
    valgrind --tool=massif --heap=yes --stacks=yes --time-unit=B ./Nth_left_truncatable_prime 2166

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
	main_STM32.c

Elapsed time during execution is approximately 1 second for the 2166-th LTP.
```
