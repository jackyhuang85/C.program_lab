/*	EE231002 Lab08. Blackjack
	104061203, Xuan-Jie Huang
	Date:2015/11/16
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10000

double E(int point){
	int i, k;
	double sum = 0;

	for(i = 0 ; i < N ; i++){
		k = rand() % 13 + 1;
		if (point < 11 && k == 1) k += 10;
		else if (k > 10) k = 10;
		sum += point + k;
	}
	return sum / N;
}
double Busted(int point){
    int i, k;
    double num_busted = 0, result;

    for(i = 0 ; i < N ; i++){
        k = rand() % 13 + 1;
        if (point < 11 && k == 1) k += 10;
		else if (k > 10) k = 10;
		if( ( point + k ) > 21 ) num_busted++;
    }
    result = (num_busted / N) * 100;
    return result;
}
double probability(void){
    int i, point, k, num_ace;
    double succeed = 0;

    for(i = 0 ; i < N ; i++){
        point = 0,num_ace = 0;
        while(point < 21){
            k = rand() % 13 + 1;
            if(k > 10) k = 10;
            else if(k == 1){
                num_ace++;
                k = 11;
            }
            point += k;
            if(point > 21 && num_ace != 0){
                point -= 10;
                num_ace--;
            }
        }
        if(point == 21) succeed++;
    }
    return succeed / N * 100;
}
int main(void){
	int i;

	printf("Points\tE(hit)\t%% Busted\n");
	for(i = 2 ; i < 21 ; i++){
		printf("%4d\t %5.2lf\t  %5g\n", i, E(i), Busted(i));
	}
	printf("Probability of getting 21 points is %5g%%\n", probability());
	return 0;
}
