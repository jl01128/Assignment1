//Jackie Lin 
//COP4520 - CONCEPTS PARALLEL DISTRIBUTED
// 01/24/2023

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <cmath>


//range for finding prime
#define maxPrime 100000000

//our desired thread count
#define threadNum 8

int main() {
    //initial attempt of finding prime
	//boolean array for indicating prime number
	bool* primes = (bool*)malloc(sizeof(bool) * maxPrime);

	//bool* primes = (bool*)calloc(n,sizeof(bool));
	
    int i;

    //set array as true for default
	for (i = 0; i < maxPrime; i++) {
		primes[i] = true;
	}
	
    //0 and 1 are not prime or composite, so set to false and not included for prime
	primes[0] = false; 
	primes[1] = false;

	//file output
	std::ofstream file("primeResults.txt");

	//free our memory
	free(primes);
	//close our file 
	file.close();

	return 0;
}

