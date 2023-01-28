# Assignment 1
by Jackie Lin

To run the code:
```
$ g++ -std=c++11 -pthread primeFinder.cpp
$ ./a.out
```

This program is to find the total number of primes, sum of primes, top ten primes from least to greatest, as well as the efficency of finding theses factors through multi-threading. 

Initial Attemtpts Issues
```
*Initial method in finding prime was too time consuming in handling the given number range, which for my computer was unable to succesffully produce an output, which was proabably also do to my inclusion of double forloops

*Threads were not able to successfuly run the problem in our desired time, as each of the 8 threads weren't each handling their set inputs

*First attempt in including sieve of eratosthenes algorithm was not producing successful output(Which was successfully solved due to several syntax errors)
```

Solutions and its Efficieny
```
* Implementation of the Sieve of Eratosthenes algorithm which is old algorithm for finding all prime numbers  to any given limit, which in out case is from 1 to 100000000. Given that we ignore all the numbers up to 2, each numbers are marked off which is a multiple of that given number. Which radiaclly reduced our runtime from our brute force method of checking each num through a for loop function call.

*Further updates to sieve function, was checking a given number that are sqaure root of the max, which is due to the fact that a given number can be checked to be a prime number if a given divisor less than the sqaure root is checked. 

*Inclusion of multiple threas and sieve algorithm produced an output with an ouput, with a runtime average of 134 seconds, whihc was succesfully lowered to an avaerage of 1.4602 seconds, after minor syntax and logical errors. 

```

Output

(Results are given through a file output called "primeResults.txt")

```
Example output

1.20465e+06s 5761455 279209790387276
99999787 99999821 99999827 99999839 99999847 99999931 99999941 99999959 99999971 99999989 

```


