/*EE231002 Lab01 Currency Exchange
	ID 104061203,Name:Xuan-Jie Huang
	Date:09/21/2015*/
#include<stdio.h>


int main(void){
	float a,b; 	//a is USD,B is NT
	printf("Amount of USD to buy: ");	//prompt fo USD
	scanf("%f",&a);	//read USD
	b=32.57*a+100;	//calculate the amount of NT to buy USD
	printf("Total needs to pay: %.2f\n",b);	//print out "Total needs to pay" and the volume
	return 0;
}

