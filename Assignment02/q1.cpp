#include<stdio.h>
#include<omp.h>

int main(){
	
	printf("enter size, scalar and elements");
	int size;
	scanf("%d",&size);
	int scalar;
	scanf("%d",&scalar);
	int array[size];
	
	for(int i=0;i<size;i++){
		scanf("%d",&array[i]);
	}
	omp_set_num_threads(size);
	#pragma omp parallel
	{
		int thread_no=omp_get_thread_num();
		array[thread_no]+=scalar;
	}
	
	printf("ans is :-");
	for(int i=0;i<size;i++){
		printf("%d",array[i]);
	}
	
	
	
	
	
	return 0;
}
