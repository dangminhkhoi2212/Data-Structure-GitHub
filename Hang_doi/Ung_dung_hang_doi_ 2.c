#include<stdio.h>
#include "AStack.c"
#include "CAQueue.c"
#include <string.h>

int ktChuoi(char x[100]){
	Stack S;
	makenullStack(&S);
	Queue Q;
	makenullQueue(&Q);
	int i, n=strlen(x);
	for(i=0; i<n; i++){
		if('A'<=x[i]&& x[i]<='Z')
			x[i]+=32;
		if('a'<=x[i]&& x[i]<='z'){
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
void encode(char x[], char y[]){
	int i, n1=strlen(x), n2=strlen(y);
	Queue Q;
	makenullQueue(&Q);
	for(i=0; i<n2; i++){
		enQueue(y[i], &Q);
	}
	for(i=0; i<n1; i++){
		int k=front(Q)-'0';
		x[i]+=k;
		enQueue(front(Q), &Q);
		deQueue(&Q);
	}
	printf("%s", x);
}
void encode(char str[200],char Ma[10], char kq[])
{
    Queue Q; 
    makenullQueue(&Q);
    int i;
    for(i=0;i<strlen(Ma);i++)
    {
        enQueue(Ma[i],&Q);
    }
    for(i=0;i<strlen(str);i++)
    {
        int temp;
        temp=front(Q)-48;
        enQueue(front(Q),&Q);
        kq[i]+=temp;
        deQueue(&Q);
        printf("%c",str[i]);
        
    }
}

int main()
{
    char str[500];
    fgets(str,500,stdin);
    str[strlen(str)-1]='\0';
    char Ma[100];
    fgets(Ma,100,stdin); 
	Ma[strlen(Ma)-1]='\0';
    MaHoa(str,Ma);
	return 0;
}
