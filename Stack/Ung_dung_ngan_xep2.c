#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLength 100
typedef float ElementType;
typedef struct{
	ElementType Element[MaxLength];
	int Top_idx;
}Stack;

void makenullStack(Stack *pS){
	pS->Top_idx=MaxLength;
}
int emptyStack(Stack S){
	return S.Top_idx==MaxLength;
}
int full(Stack S){
	return S.Top_idx==0;
}

void push(ElementType x, Stack *pS){
	if(!full(*pS)){
		pS->Top_idx--;
		pS->Element[pS->Top_idx]=x;
	}
}
void pop(Stack *pS){
	if(!emptyStack(*pS)){
		pS->Top_idx++;
	}
}
ElementType top(Stack S){
	return S.Element[S.Top_idx];
}
void readStack(Stack *pS){
	makenullStack(pS);
	int n, i, x;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		push(x, pS);
	}
}
void printStack(Stack *pS){
	while(!emptyStack(*pS)){
		printf("%d ", top(*pS));
		pop(pS);
	}
}
int ktChuoi(){
	Stack C;
	makenullStack(&C);
	char *x;
	x=(char*) malloc(sizeof(char));
	fgets(x, 100, stdin);
	x[strlen(x)-1]='\0';
	int i;
	for(i=0; i<strlen(x); i++){
		if(x[i]=='(' || x[i]=='{' || x[i]=='['){
			push(x[i], &C);
		}
		if(x[i]==')' || x[i]=='}' || x[i]==']'){
			if(!emptyStack(C))
				pop(&C);
			else return 0;
		}
	}
	if(!emptyStack(C))
		return 0;
	else return 1;
}

float tinhGiatri(char x[]){
	int i, n=strlen(x);
	Stack PT;
	makenullStack(&PT);
	float T=0;
	for(i=0; i<n; i++){
		int k=x[i]-48;
		if(0<=k && k<=9){
			push(k, &PT);
		}
		if(x[i]== '+' || x[i]== '-' || x[i]== '*' || x[i]== '/'){
			int a=top(PT);
			pop(&PT);
			int b=top(PT);
			pop(&PT);
			switch(x[i]){
				case '+':
					T=b+a;
					break;
				case '-':
					T=b-a;
					break;
				case '*':
					T=b*a;
					break;
				case '/':
					T=b*1.0/a;
					break;
			}
			push(T, &PT);
		}
	}
	return top(PT);
}
int main(){


	if(ktChuoi()){
		printf("Dung");
	}       
	else printf("sai");
	return 0;
}
