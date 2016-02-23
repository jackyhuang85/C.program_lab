/*  EE231002 Lab07. Matrix Determinants
    104061203, Xuan-Jie Huang
    Date: 2015/11/09
*/

#include <stdio.h>
#if !defined(N)
#define N 3
#endif

int matrix[N][N];

void input(void){
    int i, j;

    for(i = 0 ; i < N ; i++){
        for(j = 0 ; j < N ; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}
void PrintMatrix(void){
    int i, j;

    for(i = 0 ; i < N ; i++){
        printf(" ");
        for(j = 0 ; j < N ; j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}
int sum(void){
    int i, j, k, sum, total = 0;

    for(k = 0 ; k < N ; k++){
        sum = 1;
        for(i = k, j = 0 ; i < N && j < N ; i++, j++){
            sum *= matrix[i][j];
        }
        for(i = 0, j = N-k ; i < N && j < N ; i++, j++){
            sum *= matrix[i][j];
        }
        total += sum;
    }
    return total;
}
int minus(void){
    int i, j, k, sum, total = 0;

    for(k = 0 ; k < N ; k++){
        sum = 1;
        for(i = k, j = N-1 ; i < N && j >= 0 ; i++, j--){
            sum *= matrix[i][j];
        }
        for(i = k-1, j = 0 ; i >= 0 && j < N ; i--, j++){
            sum *= matrix[i][j];
        }
        total += sum;
    }
    return total;
}
int main(void){
    int ans;

    input();
    printf("Input matrix is\n");
    PrintMatrix();
    ans = sum() - minus();
    printf("Det = %d\n", ans);
    return 0;
}
