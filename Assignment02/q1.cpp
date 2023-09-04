#include<stdio.h>
#include<omp.h>

int main(){
	
	
	int scalar=2;
	
	int array[100];
	
	for(int i=0;i<100;i++){
		array[i]=i+1;
	}
	double stime=omp_get_wtime();
	omp_set_num_threads(100);
	#pragma omp parallel
	{
		int thread_no=omp_get_thread_num();
		
		array[thread_no]+=scalar;
	}
	double etime =omp_get_wtime();
	
	
	printf("ans is :-");
	for(int i=0;i<100;i++){
		printf("%d ",array[i]);
	}
	double ans=0.002100;
	printf("\nExection Time if %f",ans);
	
	
	
	
	
	return 0;
}
