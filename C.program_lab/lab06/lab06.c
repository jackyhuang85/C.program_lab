/*	EE231002 Lab06. Latin Square
	104061203, Xuan-Jie Huang
	Date:2015/11/02
*/
#include <stdio.h>
#if !defined(N)
#define N 5
#endif

int count=0;									//count the number of answer

void PrintOutSquare(char square[N][N]){			//Function:
    int i, j;									//To print out the whole square
    printf("Latin Square %d\n", ++count);
    for(i = 0;i < N;i++){
        printf("  ");
        for(j = 0;j < N;j++){
            printf("%c ",square[i][j]);
        }
        printf("\n");
    }
}
int Check(char ch, char square[N][N], int row, int col){	//To check
    int i,j;												//if the character
    for(i = 0;i < row;i++){									//in the index
        if(square[i][col] == ch) return 0;					//repeatly appears
    }														//in the same row
    for(j = 0;j < col;j++){									//or column.
        if(square[row][j] == ch) return 0;					//If yes, return 0
    }														//If no, return 1
    return 1;
}
void FilltheBlock(int row,int col,char square[N][N]){		//To fill blocks:
    char i;													//Find the alphabet
    for(i = 'A';i < 'A' + N;i++){							//from 'A' to '*'.
        if(Check(i, square, row, col)==1){					//If the alphabet
            square[row][col] = i;							//is checked that
            if(row == N-1 && col == N-1){					//it isn't repeated
                PrintOutSquare(square);						//then it can be
            }												//filled in block.
            else{											//After, find the
                if(col == N-1) FilltheBlock(row + 1, 0, square); 	//next
                else FilltheBlock(row, col + 1, square);	//block.
            }												//If the block is
        }													//the last one,
    }														//print out the
}															//square.
int main(void){
    char square[N][N];										//set the matrix
    int i = 0, j = 0;										//fill from first
    FilltheBlock(i, j, square);
    printf("Total number of Latin Squares found is %d\n", count);
    return 0;												//print out 'count'
}															//and end.
