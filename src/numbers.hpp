#ifndef NUMBERS_HPP_
#define NUMBERS_HPP_

#include <vector>
#include <string>

using namespace std;

int doubleIt(int n);

int primeNumbers(int numbers[], int size);
std::vector<int> primeNumbers(int size);

int primeNumbersSlow(int numbers[], int size);

bool isPrime(int n);

string ordinal(int n);

#endif /* NUMBERS_HPP_ */
