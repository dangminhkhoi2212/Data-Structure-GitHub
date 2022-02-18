#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLength 100
typedef int ElementType;
typedef struct {
	ElementType Element[MaxLength];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Front=-1;
	pQ->Rear=-1;
}
int emptyQueue(Queue Q){
	return Q.Front==-1;
}
int fullQueue(Queue Q){
	return Q.Rear-Q.Front==MaxLength-1;
}
void enQueue(ElementType x, Queue *pQ){
	if(!fullQueue(*pQ)){
		if(emptyQueue(*pQ))
			pQ->Front=0;
		if(pQ->Rear==MaxLength-1){
			int i;
			for(i=pQ->Front; i<=pQ->Rear; i++){
				pQ->Element[i-pQ->Front]=pQ->Element[i];
			}
			pQ->Rear-=pQ->Front;
			pQ->Front=0;
		}
		pQ->Rear++;
		pQ->Element[pQ->Rear]=x;
	}
//	else printf("Da day!");
}

void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ)){
		pQ->Front++;
		if(pQ->Front>pQ->Rear)
			makenullQueue(pQ);
	}
}

ElementType front(Queue Q){
	return Q.Element[Q.Front];
}
void read(int n, Queue *pQ){
	makenullQueue(pQ);
	int i, x;
	for (i=0; i<n; i++){
		scanf("%d", &x);
		enQueue(x, pQ);
	}
}
void print(Queue *pQ){
	while(!emptyQueue(*pQ)){
		printf("%d ", front(*pQ));
		deQueue(pQ);
	}
	printf("\n");
}
//int CV(Queue *pQ1, Queue *pQ2){
//	int i, j;
//	int time=0;
//	for (i=pQ1->Front; i<=pQ2->Rear; i++){
//		for (j=pQ2->Front; j<=pQ2->Rear; j++){
//			if(front(*pQ1)==front(*pQ2)){
//				time++;
//				deQueue(pQ1);
//				deQueue(pQ2);
//			}
//			else{
//				int x=front(*pQ1);
//				deQueue(pQ1);
//				enQueue(x, pQ1);
//				time++;
//			}
//		}
//	}
//	return time;
//}
void nhapCV(){
	int i, n;
	scanf("%d", &n);
	char CV[100];
	Queue k;
	makenullQueue(&k);
	char x;
	for (i=0; i<n; i++){
		scanf("\n%c",&CV[i]);
		if(CV[i]=='E'){
			int giatri;
			scanf("%d", &giatri);
			enQueue(giatri, &k);
		}
	}
	Queue KQ;
	makenullQueue(&KQ);
	for(i=0; i<n; i++){
		if(CV[i]=='E'){
			enQueue(front(k), &KQ);
			deQueue(&k);
			printf("%d\n", KQ.Rear-KQ.Front+1);
		}
		else if(CV[i]=='D'){
			if(emptyQueue(KQ)){
				printf("-1 ");
			}	
			else printf("%d ", front(KQ));
			deQueue(&KQ);
			if(emptyQueue(KQ))
				printf("0\n");
			else printf("%d\n",KQ.Rear-KQ.Front+1);
		}
		
	}
}
void nhapQueue(int n, Queue *pQ){
	makenullQueue(pQ);
	int i,x;
	for(i=0;i<n;i++){
		scanf("%d", &x);
		enQueue(x,pQ);
	}
}
void  thuchien(Queue Q1, Queue Q2){
	int n=0;
	while (!emptyQueue(Q1)){
		if(front(Q1)!=front(Q2)){
			enQueue(front(Q1),&Q1);
			deQueue(&Q1);
			n++;
		}
		if(front(Q1)==front(Q2)){
			deQueue(&Q1);
			deQueue(&Q2);
			n++;
		}
	}
	printf("%d", n);	
}

int main (){
	int n;
	Queue Q1,Q2;
	scanf ("%d\n", &n);
	nhapQueue(n,&Q1);
	nhapQueue(n,&Q2);
	thuchien(Q1,Q2);
return 0;
}
