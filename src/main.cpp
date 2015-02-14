#include <iostream>
#include <sys/time.h>

#include "numbers.hpp"

using namespace std;

#define BEGIN_TIME {\
	struct timeval t1,t2;\
	double elapsedTime;\
	gettimeofday(&t1,NULL);


#define END_TIME \
	gettimeofday(&t2,NULL);\
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;\
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;\
	cout << "elapsed time: " << elapsedTime << " ms." << endl;\
}

void printArray(int numbers[], int size);

int main(int argc, char **argv) {

    
    int n = 10000;
    
    int printing = 10;
    int steps = n/printing;
    
    
    int numbers[n];
    
    
    BEGIN_TIME;
    primeNumbers(numbers,n);
    END_TIME;

    for (int i=1; i<=n; i += steps) {
        cout << ordinal(i) << " prime number: " << numbers[i-1] << endl;
    }
       
    return 0;
}

void printArray(int numbers[], int size) {
    for (int i=0; i<size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
