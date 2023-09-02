#include<stdio.h>
#include<omp.h>
#include <stdlib.h>


//The reduction(+:sum) clause is added to the parallel for directive. This clause indicates 
//that each thread should have its own local copy of the sum variable, and after the loop is completed, 
//these local copies will be combined into a single shared sum variable using the addition (+) operation.

int main(){
	int vec1[]={1,2,3,4};
	int vec2[]={4,3,2,1};
	
	int result=0;
//	int no=get_thread_no;
	#pragma omp parallel for reduction(+:result)
	for(int i=0;i<4;i++){
		result+=vec1[i]*vec2[i];
	}
	
//	#pragma omp parallel for reduction(+:result)
//    for (int i = 0; i < size; i++) {
//        result += vector1[i] * vector2[i];
//    }
    printf("%d",result);
	return 0;
}
