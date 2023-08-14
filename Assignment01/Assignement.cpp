#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	#pragma omp parallel
	{
	printf("Hello World from thread :-%d\n",omp_get_thread_num());
	}
	
	
	return 0;
}
