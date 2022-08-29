#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

typedef float (*f)(float, int);

f func[4] = {&f1, &f2, &f3, &f4}; 

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity){
    float sum = 0;
    float arg = 0;
    float frac = (float)(b-a)/n;

    for (int i = 0; i < n; i++)
    {
        arg = a+(i+0.5)*(b-a)/n;
        sum += func[functionid-1](arg, intensity);
    }

    return frac*sum;
    
}
int main (int argc, char* argv[]) {

    if (argc < 6) {
        fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>", argv[0]);
        return -1;
    }
    
    
    clock_t t; // t represents clock ticks which is of type 'clock_t'
    t = clock(); // start clock
    double r = calc_numerical_integration(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
    t = clock()-t; // end clock=
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds; CLOCKS_PER_SEC is the number of clock ticks per second
    fprintf(stdout, "%f", r);
    fprintf(stderr, "%f", time_taken);
    
    return 0;
}

