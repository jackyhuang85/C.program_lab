/*	EE231002 Lab04. Deciphering Roman Numerals
	104061203, Xuan-Jie Huang
	Date:2015/10/19
*/
#include <stdio.h>

int main(void){
	char a;								//declare "a" for the input
	int val=0, i_chk, x_chk, c_chk;		//"val" means total value,
										//"chk"="check point". 1=true,0=false
    printf("Input a Roman Numeral: ");	//prompt for the input

	i_chk=0, x_chk=0, c_chk=0;								//initial

	while((a=getchar()) != '\n'){		//read the character.
										//If it is end of text, exit the loop.
		switch(a) {						//judge the condition of "a"
			case 'I':					//If "a" is 'I'
				val += 1;				//plus 1 to total value
				i_chk = 1;				//check point,
										//meaning 'I' has been read.
				break;
			case 'V':
				if(i_chk == 0) val+=5;	//check the check point,
				else{					//if check point is "true"
					val += 3;			//meaning there would be 'IV'
					i_chk = 0;			//else, just return 5 to sum.
				}
				break;
			case 'X':
				if(i_chk == 0){			//check the check point,
					val += 10;          //if check point is "true"
					x_chk = 1;            //meaning there would be 'IX'
				}                       //else, just return 10 to sum.
				else {					//and let check point be "true"
					val += 8;
					i_chk = 0;
				}
				break;
			case 'L':
				if(x_chk == 0) val += 50;	//check the check point,
				else{                   //if check point is "true"
					val += 30;          //meaning there would be 'XL'
					x_chk = 0;            //else, just return 50 to sum.
				}
				break;
			case 'C':
				if(x_chk == 0){			//check the check point,
					val += 100;         //if check point is "true"
					c_chk = 1;            //meaning there would be 'XC'
				}                       //else, just return 100 to sum.
				else {                  //and let check point be "true"
					val += 80;
					x_chk = 0;
				}
				break;
			case 'D':					//check the check point,
				if(c_chk == 0)val += 500;	//if check point is "true"
				else{                   //meaning there would be 'CD'
					val += 300;         //else, just return 500 to sum.
					c_chk = 0;
				}
				break;
			case 'M':					//check the check point,
				if(c_chk == 0)val +=1000; //if check point is "true"
				else{                   //meaning there would be 'CM'
					val += 800;         //else, just return 1000 to sum.
					c_chk = 0;
				}
				break;
			default:
				break;
		}
	}
	printf("The value is: %d\n",val);	//print out the answer
	return 0;							//end of process
}
