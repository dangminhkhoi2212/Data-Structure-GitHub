#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef struct{
	Position Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	Position header;
	header=(struct Node*)malloc(sizeof(struct Node));
	header->Next=NULL;
	pQ->Front=header;
	pQ->Rear=header;
}
int emptyQueue(Queue Q){
	return Q.Front->Next==NULL;
}
ElementType front(Queue Q){
	return Q.Front->Next->Element;
}
void enQueue(ElementType x, Queue *pQ){
	pQ->Rear->Next=(struct Node*)malloc(sizeof(struct Node));
	pQ->Rear=pQ->Rear->Next;
	pQ->Rear->Element=x;
	pQ->Rear->Next=NULL;
}
void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ)){
		Position Temp;
		Temp=(struct Node*)malloc(sizeof(struct Node));
		Temp=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Temp);
	}
}
int main(){
	Queue Q;
	makenullQueue(&Q);
	printf("%d", front(Q));
}
