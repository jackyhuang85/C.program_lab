/*	EE231002 Lab10. GCD and LCM
	104061203, Xuan-Jie Huang
	Date: 2015/11/30
*/
#include <stdio.h>
#define S 50

/*	This function factorizes the input N into its prime factors	*
 *	(factors array) and their associated powers (power array). 	*/
void factorize(int N, int factors[S], int power[S]){		
	int i;
	int powerNum = 0, flag_factor = 0, flag_power = 0;

	for(i = 2 ; i <= N ; i++){						//Find the prime factors
		powerNum = 0;								//from 2 to N.And calculate
		while(N % i == 0){							//the power number of each
			N /= i;									//factors;afterward, put 
			powerNum++;								//them into the factors 
		}											//arrays and power arrays.
		if(powerNum != 0){
			factors[flag_factor] = i;
			power[flag_power] = powerNum;
			flag_power++;
			flag_factor++;
		}
	}
	factors[flag_factor] = 1;
	power[flag_power] = 1;
}

/*	This function takes two factors arrays and two power arrays *
 *	to produce two output arrays: one for GCD factors and the	*
 *	other for GCD power.										*/
void GCD(int Afactors[S], int Apower[S], int Bfactors[S], int Bpower[S], int Cfactors[S], int Cpower[S]){
	int flag_A = 0, flag_B = 0, flag_C = 0;
	
	while(Afactors[flag_A] != 1 && Bfactors[flag_B] != 1){
		if(Afactors[flag_A] == Bfactors[flag_B]){	//To get the GCD, start
			Cfactors[flag_C] = Afactors[flag_A];	//from searching the factor
			if(Apower[flag_A] < Bpower[flag_A]){	//arrays of them at same
				Cpower[flag_C] = Apower[flag_A];	//time. If two factors 
			}										//found are same, choose
			else{									//the one whose power 
				Cpower[flag_C] = Bpower[flag_B];	//number is bigger, and put
			}										//it into GCD array, then
			flag_A++;								//continue.
			flag_B++;								
			flag_C++;								//If they are different,
		}											//ignore them and keep 
		else if(Afactors[flag_A] > Bfactors[flag_B]){
			flag_B++;								//trying to find the next
		}											//same factors.
		else{								
			flag_A++;								//The searching process
		}											//will complete as both "1"
	}												//in factors array are
	Cfactors[flag_C] = 1;							//found.
	Cpower[flag_C] = 1;
}

/*	This function takes two factors arrays and two power arrays	*
 *	to produce two output arrays: one for LCM factors and the 	*
 *	other for LCM power.										*/
void LCM(int Afactors[S], int Apower[S], int Bfactors[S], int Bpower[S], int Cfactors[S], int Cpower[S]){
	int flag_A = 0, flag_B = 0, flag_C = 0;
	
	while(Afactors[flag_A] != 1 || Bfactors[flag_B] != 1){	//To get the LCM, 
		if(Afactors[flag_A] == Bfactors[flag_B]){			//start from 
			Cfactors[flag_C] = Afactors[flag_A];			//searching the
			if(Apower[flag_A] < Bpower[flag_B]){			//factors of two
				Cpower[flag_C] = Bpower[flag_B];			//at the same time.
			}												//If the factors
			else{											//are same, choose
				Cpower[flag_C] = Apower[flag_A];			//whose the power
			}												//number is less,
			flag_A++;										//then continue.
			flag_B++;										//If they are not
			flag_C++;										//same, choose
		}													//both them, put
		else if(Afactors[flag_A] > Bfactors[flag_B]){		//in ascending
			if(Bfactors[flag_B] != 1){						//order, then
				Cfactors[flag_C] = Bfactors[flag_B];		//continue.
				Cpower[flag_C] = Bpower[flag_B];
				flag_B++;									//If once find "1"
				flag_C++;									//, which means 
			}												//there is no more
			else{											//factors of the
				Cfactors[flag_C] = Afactors[flag_A];		//number. So stop
				Cpower[flag_C] = Apower[flag_A];			//finding the  
				flag_A++;									//factors of one,
				flag_C++;									//keep finding
			}												//the factors of
		}													//another one.
		else{
			if(Afactors[flag_A] != 1){						//The searching
				Cfactors[flag_C] = Afactors[flag_A];		//process will
				Cpower[flag_C] = Apower[flag_A];			//complete as both
				flag_A++;									//"1" in arrays be
				flag_C++;									//found.
			}
			else{
				Cfactors[flag_C] = Bfactors[flag_B];
				Cpower[flag_C] = Bpower[flag_B];
				flag_B++;
				flag_C++;
			}
		}
	}
	Cfactors[flag_C] = 1;
	Cpower[flag_C] = 1;
}

/*	This function prints out the factors and power arrays in 	*
 *	product of prime factor form and the integer calculated 	*
 *	using this product from.									*/
void write(int factors[S], int power[S]){
	int i ,flag = 0, first = 1, yes = 0;
	int N = 1;
	
	while(factors[flag] != 1){						//To print out the factors
		if(power[flag] != 0){						//and power array in 
			if(!yes){								//product of prime factor 
				printf("=");						//form, start from first
				yes = 1;							//element in factors array.
			}										//If the power number 
			if(power[flag] == 1){					//associated with the
				if(!first) {						//factors is 1, then just
					printf("*");					//print out the factor
				}									//without the power. If 
				printf(" %d ", factors[flag]);		//else, print out it with
			}										//the power.
			else{									//Finally, calculate the
				if(!first) {						//number by two arrays.
					printf("*");
				}
				printf(" %d^%d ", factors[flag], power[flag]);
			}
			first = 0;
		}
		for(i = 0 ; i < power[flag]; i++){
			N *= factors[flag];
		}
		flag++;

	}
	printf("= %d\n", N);
}

/*	Main Function: Program starts from here. It requires two	*	
 *	numbers which will be proceeded, and the answer will be 	*
 *	printed out.												*/
int main(void){
	int A, B;
	int Afactors[S], Apower[S], Bfactors[S], Bpower[S];
	int GCDfactors[S], LCMfactors[S], GCDpower[S], LCMpower[S];

	printf("input A: ");						//Prompt two numbers.
	scanf("%d", &A);
	printf("input B: ");
	scanf("%d", &B);
	factorize(A, Afactors, Apower);				//Factorize both them.
	factorize(B, Bfactors, Bpower);
	printf("  A ");								//Print out both them in
	write(Afactors, Apower);					//products of prime factors
	printf("  B ");								//form.
	write(Bfactors, Bpower);
	printf("  GCD(A,B) ");						//Print out their GCD and LCM in
	GCD(Afactors, Apower, Bfactors, Bpower, GCDfactors, GCDpower);
	write(GCDfactors, GCDpower);				//products of prime factors
	printf("  LCM(A,B) ");						//form.
	LCM(Afactors, Apower, Bfactors, Bpower, LCMfactors, LCMpower);
	write(LCMfactors, LCMpower);
	return 0;
}

