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
#define maxNum 100000000

//our desired thread count
#define threadNum 8

//top ten 
#define topTen 10

void sieve(int thread, bool* primes);

int main() {

    //initial attempt of finding prime
	//boolean array for indicating prime number
	bool* nums = (bool*)malloc(sizeof(bool) * maxNum);
	
    int i;

    //set array as true for default
	for(i = 0; i < maxNum; i++) {
		nums[i] = true;
	}
	
    //0 and 1 are not prime or composite, so set to false and not included for prime
	nums[0] = false; 
	nums[1] = false;

	//start of our timer 
    double start = clock();

    //Implement our thead
	std::thread threads[threadNum];
    
	for(i = 0; i < threadNum; i++) {
		threads[i] = std::thread(sieve, i, nums);
	}
	
	//join our threads
	for(i = 0; i < threadNum; i++) {
		threads[i].join();
	}

	//end of our timer
    double end = clock();

	//total time to run threads
	double time = (end - start);


	unsigned long long primeSum = 0;
	int numPrimes = 0;
	
	//ignore 0 to 1
	//add up sum of prime
	//as well as the number of prime numbers
	for(int i = 2; i < maxNum; i++) {
		//check if it is a prime number
		if(nums[i]) {
			primeSum += i;
			numPrimes++;
		}
	}

	// holds our top ten prime numbers
	int topPrime[10];
	int t = topTen - 1;

	//10000000 is not prime
	//search for prime numbers starting from end
	//ends after our 10 top prime numbers are taken
	for(int i = maxNum - 1; t >= 0; i--) {
		//gets our top ten prime numbers starting from max
		if(nums[i]) {
			topPrime[t] = i;
			t--;
		}
	}

	// file ouptut contents
	std::ofstream file("primeResults.txt");

	//output text
	file << time << "s" << " " << numPrimes << " " << primeSum << std::endl;

	//print our laargest prime numbers from least to greatest
	for (int i = 0; i <= topTen-1; i++) {
		file << topPrime[i] << " ";
	}
	file << "\n";

	
	//free our memory
	free(nums);
	//close our file 
	file.close();

	return 0;
}

//sieve algortihm finds our primes
void sieve(int thread, bool* nums) {

    int i;
	//returns the smallest number greater than sqaure root of maxNum
    int temp = ceil(sqrt(maxNum));

	//
    for(i = thread; i <= temp; i += threadNum){
		//checks for prime nums through the given d
        if(nums[i]) {

			int a = i * i;
            int b = 0;

			//Update all multiples of "a" greater than the square of it numbers, which are
            //multiple of "a" and is less than p^2 have been marked
			while(a < maxNum) {
				nums[a] = false;
                b += 1;

				a = (i * i) + (b * i);
			}
		}
    }

}

