//Jackie Lin 
//COP4520 - CONCEPTS PARALLEL DISTRIBUTED
// 01/24/2023

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <cmath>
//for our threads
#include <thread>
#include <pthread.h>


//range for finding prime
#define maxPrime 100000000

//our desired thread count
#define threadNum 8

void sieve(int thread, bool* primes);

int main() {
    //initial attempt of finding prime
	//boolean array for indicating prime number
	bool* nums = (bool*)malloc(sizeof(bool) * maxPrime);

	//bool* primes = (bool*)calloc(n,sizeof(bool));
	
    int i;

    //set array as true for default
	for(i = 0; i < maxPrime; i++) {
		nums[i] = true;
	}
	
    //0 and 1 are not prime or composite, so set to false and not included for prime
	nums[0] = false; 
	nums[1] = false;

    //Implement our thead
	std::thread threads[threadNum];

    
	for(i = 0; i < threadNum; i++) {
		threads[i] = std::thread(sieve, i, nums);
	}
	
	// Join threads
	for(i = 0; i < threadNum; i++) {
		threads[i].join();
	}

	//file output
	std::ofstream file("primeResults.txt");

	//free our memory
	free(nums);
	//close our file 
	file.close();

	return 0;
}

//sieve algortihm finds our primes
void sieve(int thread, bool* nums) {


}

