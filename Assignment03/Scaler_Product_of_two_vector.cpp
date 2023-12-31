#include<stdio.h>
#include<omp.h>
#include <stdlib.h>
#define n 1000

//The reduction(+:sum) clause is added to the parallel for directive. This clause indicates 
//that each thread should have its own local copy of the sum variable, and after the loop is completed, 
//these local copies will be combined into a single shared sum variable using the addition (+) operation.

void sort(int v[]){
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			
			if(v[j]>v[j+1]){
				int temp=v[j];
				 v[j]=v[j+1];
				 v[j+1]=temp;
			}
		}
	}
}

void sortDec(int v[]){
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-1-i;j++){
			if(v[j]<v[j+1]){
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
}

int main(){
	// n=1000
	    int nums1[n], nums2[n];
    for (int i = 0; i<n; i++)
    {
        nums1[i] = 10;
    }
    for (int i = 0; i<n; i++)
    {
        nums2[i] = 20;
    }
    double stime=omp_get_wtime();
    // sort(nums1);
    // sortDec(nums2);
  
    
	int result=0;
//	int no=get_thread_no;
	#pragma omp parallel for reduction(+:result)
	for(int i=0;i<4;i++){
		result+=nums1[i]*nums2[i];
	}

    double etime=omp_get_wtime();
//	#pragma omp parallel for reduction(+:result)
//    for (int i = 0; i < size; i++) {
//        result += vector1[i] * vector2[i];
//    }
   printf("%f %f",etime ,stime);
    printf("and time is %f", etime-stime);
	return 0;
}
