/*	EE231002 Lab05. Permutations
	104061203, Xuan-Jie Huang
	Date:2015/10/26
*/

#include <stdio.h>
#define N 5

int main(void){
	int i,j,k,temp,count=0,sum=1;
	int A[N];								//Use array to store numbers

	for(i=0;i<N;i++){						//Initial the array,
		A[i]=i+1;							//filling number from 1 to N.
		sum*=A[i];							//Calculate how many permutations.
		printf("%d\n",A[i]);
	}
	for(count=1;count<sum;++count){			
		printf("permutation #%d:",count);	//Print out the count-th 
		for(i=0;i<N;i++){					//permutation
			printf(" %d",A[i]);
		}
		printf("\n");
		for(i=1;i<N;i++){					//Find the largest index j
			if(A[i-1]<A[i]){				//such that A[j]<A[j+1]
				j=i-1;
			}
		}
		for(i=j;i<N;i++){					//Find the largest index k
			if(A[j]<A[i]){					//such that A[j]<A[k]
				k=i;
			}
		}
		temp=A[j];							//Swap A[j] with A[k]
		A[j]=A[k];							
		A[k]=temp;
		for(i=j+1;i<=((N+j)/2);i++){		//Reverse sequence from A[j+1]
			temp=A[i];						//to A[N-1]. Find out the relative
			A[i]=A[N-(i-j)];				//between two index, then swap them
			A[N-i+j]=temp;					//one by one.
		}
	}	
	printf("permutation #%d:",sum);			//Print out the last permutation
	for(i=0;i<N;i++){
		printf(" %d",A[i]);
	}
	printf("\n Total number of permutations is %d\n",count);
											//Print out the total number 
	return 0;
}
