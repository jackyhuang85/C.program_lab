/*	EE231002 Lab09. Word Processing
	104061203, Xuan-Jie Huang
	Date: 2015/11/23
*/

#include <stdio.h>
#include <stdlib.h>

int FirstLine=1;
char buffer[10];
int wordlen(char *word){
	int i;

	for(i = 0;word[i]!='\0';i++);
	return i;
}
/* the following function print out a paragraph line by line				*
 *	 Input: char *para, is the string of a paragraph,						*
 *			int len, is the number of characters for the first out put line.
 *	 Output: the paragraph is printed directly using printf or puts,		*
 *			 no return value is needed.										*
 *	 Side effects: the contents of the paragraph can be modified by this	*
 				   function.												*/
void printLine(char *para,int len,char ch){
	static int chlen = 0;
	
	if(FirstLine==1){
		printf("    ");
		chlen += 4;
		FirstLine=0;
	}
	if(chlen + wordlen(para) > 64){
		printf("\n");
		chlen = 0;
	}
	if(ch=='\n'){
		FirstLine=1;
		chlen = 0;
	}
	printf("%s", para);
	chlen += wordlen(para)+1;
}
void process(char *str, const int len){
	char pro_str[len];
	static isbuffer=0;
	int NumSpace;
	int i,j=0;

	if(str[len-1]!=' ' && str[len-2]!=' '){
		for(i = len; str[i]!=' ' ;++i){
			buffer[j]=str[i];
			isbuffer=1;
		}
}
void reset_word(char *word){
	int i;

	for(i = 0; i < 20 ; i++){
		word[i]='\0';
	}
}
int NotEOF(char *word){
	if(word[0]=='E' && word[1]=='O'){
		if(word[2]=='F' && word[3]=='\0'){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]){
	int length = atoi(argv[argc-1]), i = 0, end = 0;
	char str[length+1], ch;
	
	while(end!=1){
		if(ch=getchar() != '\n' && i<=64){
			str[i] = ch;
			i++;
		}
		else{
			if(NotEOF(str)){
				process(str);
			}
			else end=1;
			
	}
	printf("\n");
	return 0;
}
