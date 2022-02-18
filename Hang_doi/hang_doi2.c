#include <stdio.h>
#include <string.h>

#define MaxLength 100
typedef int ElementType;
typedef struct {
	ElementType Element[MaxLength-1];
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
ElementType front(Queue Q){
	return Q.Element[Q.Front];
}
void enQueue(ElementType x, Queue *pQ){
	if(!fullQueue(*pQ)){
		if(emptyQueue(*pQ))
			pQ->Front=0;
		pQ->Rear=(pQ->Rear+1)%MaxLength;
		pQ->Element[pQ->Rear]=x;
	}
}
void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ)){
		if(pQ->Front==pQ->Rear)
			makenullQueue(pQ);
		else pQ->Front=(pQ->Front+1)%MaxLength;
	}
}

void MinhMinh(){
	int n, i;
	scanf("%d\n", &n);
	char a[100];
	Queue GT;
	makenullQueue(&GT);
	for(i=0; i<n; i++){
		scanf("%s", &a[i]);
		if(a[i]=='E'){
			int x;
			scanf("%d", &x);
			enQueue(x,&GT);	
		}	
	}
	Queue KQ;
	makenullQueue(&KQ);
	for(i=0; i<strlen(a); i++){
		if(a[i]=='E'){
			enQueue(front(GT), &KQ);
			deQueue(&GT);
			printf("%d\n", KQ.Rear-KQ.Front+1);
		}
		if(a[i]=='D'){
			if(emptyQueue(KQ))
				printf("-1 0\n");
			else {
				printf("%d ", front(KQ));
				printf("%d\n", KQ.Rear-KQ.Front);
				deQueue(&KQ);
			}
			
		}
	}
}
int main(){
	MinhMinh();
	return 0;
}
