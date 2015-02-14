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

    
    int n = 1000;
    
    int numbers[n];
    
    cout << "fast algorithm" << endl;
    
    BEGIN_TIME;
    primeNumbers(numbers,n);
    END_TIME;
    
    cout << "slow algorithm" << endl;
    BEGIN_TIME;
    primeNumbersSlow(numbers,n);
    END_TIME;
    
    return 0;
}
