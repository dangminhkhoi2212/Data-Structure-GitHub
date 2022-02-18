#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
ElementType top(Stack S){
	return S.Element[S.Top_idx];
}
void pop(Stack *pS){
	if(!emptyStack(*pS)){
		pS->Top_idx++;
	}
}
void push(float x, Stack *pS){
	if(!full(*pS)){
		pS->Top_idx--;
		pS->Element[pS->Top_idx]=x;
	}
}
void readStack(Stack *pS){
	makenullStack(pS);
	int i, n, x;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
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

float tinhGiatri(char x[]){
	int i, n=strlen(x);
	float T=0;
	Stack PT;
	makenullStack(&PT);
	for (i=0; i<n; i++){
		int k=x[i]-48;
		if(0<=k && k<=9)
			push(k, &PT);
		if(x[i]=='+' || x[i]== '-' || x[i]=='*' || x[i]=='/'){
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
char st[50];
fgets(st,50,stdin);
if(st[strlen(st)-1]=='\n'){
    st[strlen(st)-1]='\0';
}
float gt=tinhGiatri(st);
printf("%.3f",gt);
return 0;       
}
