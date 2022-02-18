#include <stdio.h>
#include "PQueue.c"
#include <string.h>
int ktChuoi(char x[]){
	int i, n=strlen(x);
	Stack S;
	makenullStack(&S);
	Queue Q;
	makenullQueue(&Q);
	for(i=0; i<n; i++){
		if('A'<= x[i] && x[i]<='Z')
			x[i]+=32;
		if('a'<= x[i] && x[i]<='z'){
			push(x[i], &S);
			enQueue(x[i], &Q);
		}
	}
	while(!emptyStack(S)){
		if(top(S)!=front(Q))
			return 0;
		pop(&S);
		deQueue(&Q);
	}
	return 1;
}
void mahoaChuoi(char x[], char y[]){
	int i, n1=strlen(x), n2=strlen(y);
	Queue Q;
	makenullQueue(&Q);
	for(i=0; i<n2; i++){
		enQueue(y[i],&Q);
	}
	for(i=0; i<n1; i++){
		int k=front(Q)-48;
		x[i]+=k;
		enQueue(front(Q), &Q);
		deQueue(&Q);
		printf("%c", x[i]);
	}
}

int main(){
	char x[500];
	fgets(x, 500, stdin);
	x[strlen(x)-1]='\0';
	char y[100];
	fgets(y, 100, stdin);
	y[strlen(y)-1]='\0';
	mahoaChuoi(x, y);
	return 0;
}
