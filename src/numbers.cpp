#include <cmath>
#include <iostream> 

using namespace std;

int doubleIt(int n) {
    return n*2;
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
        if (prime) {
            numbers[current] = i;
            current++;
        }
    }
    
    return size;
} 
