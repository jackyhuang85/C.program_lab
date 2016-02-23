/*	EE231002 Lab03 Pythagorean Triples
	104061203, Xuan-Jie Huang
	Date:2015/10/12
*/
#include <stdio.h>
#include <math.h>
int main(void){
	int a=2,b=2,c,count=0;		//initial the value of three sides
    FILE *file = fopen("test.txt", "w");
	for(a=2;a<=b;a++){				//use loop to find the numbers matching
		for(b=a;b<=20000;b++){
			c=sqrt(a*a+b*b);
			//use "squared root" to find the length of third side

							//tramsform the double type into integer type

			if(c>20000) break;		//the maximum of number is 20000
			if(a*a+b*b==c*c){
				count++;		//count how many answer have been found
				printf("Pythangorean Triple #%d is (%d,%d,%d)\n",count,a,b,c);
				//print out if the numbers match.
				fprintf(file, "Pythangorean Triple #%d is (%d,%d,%d)~",count,a,b,c);
			}

		}
	}
    fclose(file);
	printf("Total number of Pythagorean triples found is %d\n",count);
	//print out the number of the answers found totally
	return 0; //end of process
}
