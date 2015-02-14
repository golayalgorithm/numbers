#include <iostream>
#include <sys/time.h>

#include "numbers.h"

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


int main(int argc, char **argv) {

    
    int n = 10000;
    
    int numbers[n];
    
    cout << "fast algorithm" << endl;
    
    BEGIN_TIME;
    primeNumbers(numbers,n);
    //for (int i=0; i<n; i++) {
    //    cout << numbers[i] << " ";
    //}
    //cout << endl;
    END_TIME;
    
        cout << "checking array..." << endl;
    bool success = true;
    BEGIN_TIME;
    for (int i=0; i<n; i++) {
        if (!isPrime(numbers[i])) {
            success = false;
            break;
        }
    }
    if (success) {
        cout << "success" << endl;
    } else {
        cout << "fail" << endl;
    }
    END_TIME;
    
    
    cout << "slow algorithm" << endl;
    BEGIN_TIME;
    primeNumbersSlow(numbers,n);
    END_TIME;
    
    cout << "checking array..." << endl;
    success = true;
    BEGIN_TIME;
    for (int i=0; i<n; i++) {
        if (!isPrime(numbers[i])) {
            success = false;
            break;
        }
    }
    if (success) {
        cout << "success" << endl;
    } else {
        cout << "fail" << endl;
    }
    END_TIME;

    
    return 0;
}
