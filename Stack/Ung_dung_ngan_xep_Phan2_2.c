
#include <stdio.h>
#include <string.h>
#define MaxLength 100
typedef int ElementType;
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
ElementType top(Stack S){
	if(!emptyStack(S))
		return S.Element[S.Top_idx];
}
void pop(Stack *pS){
	if(!emptyStack(*pS)){
		pS->Top_idx++;
	}
}
void push(ElementType x, Stack *pS){
	pS->Top_idx--;
	pS->Element[pS->Top_idx]=x;
}
int ktChuoi(){
	char x[100];
	fgets(x, 100, stdin);
	x[strlen(x)-1]='\0';
	Stack S;
	makenullStack(&S);
	int i;
	for (i=0; i<strlen(x); i++){
		if(x[i]=='(')
			push(x[i], &S);
		if(x[i]==')'){
			if(emptyStack(S)){
				return 0;
			}
			else {
				pop(&S);
			}
		}
	}
	if(emptyStack(S))
		return 1;
	else return 0;
}

float tinhGiatri(char x[]){
	int i;
	Stack S;
	makenullStack(&S);
	float T=0;
	for (i=0; i<strlen(x); i++){
		if('0'<=x[i] && x[i]<='9'){
			int k=x[i]-48;
			push(k, &S);
		}
		if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
			int a=top(S);
			pop(&S);
			int b=top(S);
			pop(&S);
			switch (x[i]){
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
			push(T, &S);
		}
		
	}
	return top(S);
}
void inThaplucphan(int n){
	Stack S;
	makenullStack(&S);
	while(n!=0){
		push(n%16, &S);
		n/=16;
	}	
	while(!emptyStack(S)){
		if(10<=top(S) && top(S)<=15)
			printf("%c", top(S)+55);
		else
			printf("%d", top(S));
		pop(&S);
	}
}
int mucUutien(char op){
   if (op=='+' || op=='-')
       return 1;
   else if (op=='*' || op=='/')
       return 2;
}
void chuyenHauto(char trungto[], char hauto[]){
	Stack S;
	makenullStack(&S);
	int i, u=0;
	for(i=0; i<strlen(trungto); i++){
		if(('0'<=trungto[i] && trungto[i]<='9')||
			('a'<=trungto[i] && trungto[i]<='z')||
			('A'<=trungto[i] && trungto[i]<='Z'))
		{
			hauto[u]=trungto[i];
			u++;
		}
		if(trungto[i]=='('){
			push(trungto[i], &S);
		}
		if(trungto[i]==')'){
			while(!emptyStack(S) && top(S)!='('){
				hauto[u]=top(S);
				u++;
				pop(&S);
			}
			pop(&S);
		}
		if(trungto[i]=='+' || trungto[i]=='-' || trungto[i]=='*' || trungto[i]=='/'){
			while(!emptyStack(S) && top(S)!='(' && mucUutien(trungto[i])<=mucUutien(top(S))){
				hauto[u]=top(S);
				pop(&S);
				u++;
			}
			push(trungto[i], &S);
		}
	}
	while(!emptyStack(S) && top(S)!='('){
		hauto[u]=top(S);
		pop(&S);
		u++;
	}
}
int main(){ //(3 + 4) / 2
	char inExp[50],posExp[50];
fgets(inExp,50,stdin);
if(inExp[strlen(inExp)-1]=='\n'){
    inExp[strlen(inExp)-1]='\0';
}
chuyenHauto(inExp,posExp);
printf("%s",posExp);;
	return 0;
}
