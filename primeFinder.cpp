//Jackie Lin 
//COP4520 - CONCEPTS PARALLEL DISTRIBUTED
// 01/24/2023

#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <fstream>

//range for finding prime
#define maxPrime 100000000

//our desired thread count
#define threadNum 8

int main() {
	// Prime array, all set to true by default
	bool* primes = (bool*)malloc(sizeof(bool) * maxPrime);

	//bool* primes = (bool*)calloc(n,sizeof(bool));
	
	for (int i = 0; i < maxPrime; i++) {
		primes[i] = true;
	}
	
	// 0 and 1 are not prime or composiste, so set to false and not included for prime
	primes[0] = false; 
	primes[1] = false;

	// Output to file
	std::string filename = "primeResults.txt";
	std::ofstream file(filename);

	//free our memory
	free(primes);
	//close our file 
	file.close();

	return 0;
}

