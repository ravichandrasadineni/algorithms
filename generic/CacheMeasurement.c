#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define KB 1024
#define MB 1024 * 1024

int main(int argc, char *argv[]) {
    unsigned int steps = atoi(argv[1]);
    static int arr[256 * 1024 * 1024];
    int lengthMod;
    unsigned int i;
    double timeTaken;
    clock_t start;

	    lengthMod = atoi(argv[2]) - 1;
	    for (i = 0; i < steps; i++) {
	        arr[(i * 16) & lengthMod] *= 10;
            arr[(i * 16) & lengthMod] /= 10;
	    }
    return 0;
}
