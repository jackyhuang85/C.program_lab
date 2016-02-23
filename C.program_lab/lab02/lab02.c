/*	EE231002 Lab02 Currency Exchange, II
	ID:104061203, Name: Xuan-Jie Huang
	Date: 104/10/05
*/
#include <stdio.h>

int main(){
	int a;							//'a' means total USD

	printf("Enter USD amount: ");	//prompt for the total USD
	scanf("%d",&a);		//read the value of a(USD)
	printf("To pay:\n");//print out "To pay: "
	if((a/1000)>0){
	//check if a particular type of dollar bill is required.-(1)
		if(a/1000==1){
			printf("%3d $1000 bill\n",a/1000);
		}	//check the number of the type of dollar bill is only one or more.
			//If it is only one, print out the answer without 's'.-(2)
		else {
			printf("%3d $1000 bills\n",a/1000);
		}
		a%=1000;
			//All the particular type of dollar bill have been exchanged.-(3)
	}

	if((a/100)>0){ 	//same as-(1)
		if(a/100==1){
			printf("%3d $100 bill\n",a/100);	//same as-(2)
		}
		else {
			printf("%3d $100 bills\n",a/100);
		}
		a%=100;		//same as- (3)
	}
	if((a/50)>0){ 	//same as-(1)
		if(a/50==1) {
			printf("%3d $50 bill\n",a/50);		//same as-(2)
		}
		else {
			printf("%3d $50 bills\n",a/50);
		}
		a%=50;		//same as-(3)
	}
	if((a/20)>0){	//same as-(1)
		if(a/20==1) {
			printf("%3d $20 bill\n",a/20);		//same as-(2)
		}
		else {
			printf("%3d $20 bills\n",a/20);
		}
		a%=20;		//same as-(3)
	}
	if((a/10)>0){	//same as-(1)
		if(a/10==1) {
			printf("%3d $10 bill\n",a/10);		//same as-(2)
		}
		else {
			printf("%3d $10 bills\n",a/10);
		}
		a%=10;		//same as-(3)
	}
	if((a/5)>0){	//same as-(1)
	    if(a/5==1) {
			printf("%3d $5 bill\n",a/5);			//same as-(2)
		}
		else {
			printf("%3d $5 bills\n",a/5);
		}
		a%=5;		//same as-(3)
	}
    if((a/2)>0){	//same as-(1)
	    if(a/2==1) {
			printf("%3d $2 bill\n",a/2);			//same as-(2)
		}
		else {
			printf("%3d $2 bills\n",a/2);
		}
		a%=2;		//same as-(3)
	}
	if(a>0){		//same as-(1)
		if(a==1) {
			printf("%3d $1 bill\n",a);				//same as-(2)
		}
		else {
			printf("%3d $1 bill\n",a);
		}
	}
	return 0;		//end of process
}


