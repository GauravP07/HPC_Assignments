#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int num_terms;
    printf("enter upto num_terms");
    scanf("%d",&num_terms);
    
    double pi_aprox=0;
    omp_set_num_threads(num_terms);
    int sign=1;
    
    #pragma omp parallel 
    {
    	int no=omp_get_thread_num();
    	
    	double term=1.0/(2*no+1);
    	pi_aprox+=sign*term;
    	sign= -sign;
	}
	
	 pi_aprox *= 4.0;

    printf("%f",pi_aprox);
    return 0;
}

