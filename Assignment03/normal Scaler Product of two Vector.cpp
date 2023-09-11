#include<stdio.h>
#include<omp.h>
#include <stdlib.h>
#define n 100000

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
	
	    int nums1[n], nums2[n];
    for (int i = 0; i<n; i++)
    {
        nums1[i] = 10;
    }
    for (int i = 0; i<n; i++)
    {
        nums2[i] = 20;
    }
    
    sort(nums1);
    sortDec(nums2);
    int sum=0;
    double stime=omp_get_wtime();
    for(int i=0;i<n;i++){
    	sum+=nums1[i]+nums2[i];
	}
	double etime=omp_get_wtime();
    
	printf("sum is %d execution time : %f ",sum,etime-stime);
	return 0;
}
