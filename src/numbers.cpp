#include <cmath>
#include <iostream> 

using namespace std;

int doubleIt(int n) {
    return n*2;
}

bool isPrime(unsigned int n) {
    if (n <= 1) {
        return false;
    }
    
    int start = sqrt(n);
    start = start % 2 == 0 ? start - 1 : start;
    for (int i=start; i > 2; i-=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int primeNumbersSlow(int numbers[], int size) {
    int current = 0;
    
    for (int i=0; i<size; i++) {
        int count = 0;
        for (int j=i; j>0; j--) {
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 2) {
            numbers[current] = i;
            current++;
        }
    }
    
    return size;
}

int primeNumbers(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }
    int current = 1;
    numbers[0] = 2;
    
    for (int i=3; current < size; i += 2) {
        bool prime = true;

            
        int start = sqrt(i);
        start = start % 2 == 0 ? start - 1 : start;
        for (int j=start; j > 2; j-=2) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        
        
        /*
        int max = sqrt(i);
        for (int j=0; numbers[j] < max; j++) {
            if (i % numbers[j] == 0) {
                prime = false;
                break;
            }
        }
        */
        
        if (prime) {
            numbers[current] = i;
            current++;
        }
    }
    
    return size;
} 
