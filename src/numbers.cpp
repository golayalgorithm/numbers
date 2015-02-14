#include <cmath>
#include <iostream> 
#include <string>


using namespace std;

int doubleIt(int n) {
    return n*2;
}

bool isPrime(int n) {
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
    
    for (int i=2; current<size; i++) {
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
        
        int max = sqrt(i);
        for (int j=0; numbers[j] <= max; j++) {
            if (i % numbers[j] == 0) {
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


string ordinal(int n) {
    string result;
    
    string suffix[3];
    suffix[0] = "st";
    suffix[1] = "nd";
    suffix[2] = "rd";
    
    int digit = n % 10;
    
    result += to_string(n);
    
    if (digit >= 1 && digit <= 3) {
        result += suffix[digit-1];
    } else {
        result += "th";
    }
    
    return result;
}
