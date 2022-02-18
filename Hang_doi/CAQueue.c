#include <stdio.h>
#define MaxLength 500
typedef char ElementType;
typedef struct{
	ElementType Element[MaxLength];
	int Front, Rear;
}Queue;
	/*Queue*/
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
//void enQueue(ElementType x, Queue *pQ){
//	if(!fullQueue(*pQ)){
//		if(emptyQueue(*pQ))
//			pQ->Front=0;
//		if(pQ->Rear==MaxLength-1){
//			int i;
//			for(i=pQ->Front; i<=pQ->Rear; i++){
//				pQ->Element[i-pQ->Front]=pQ->Element[i];
//			}
//		}
//		pQ->Rear++;
//		pQ->Element[pQ->Rear]=x;
//	}
//}
void enQueue(ElementType x, Queue *pQ){
	if(!fullQueue(*pQ)){
		if(emptyQueue(*pQ))
			pQ->Front=0;
		pQ->Rear=(pQ->Rear+1)%(MaxLength-1);
		pQ->Element[pQ->Rear]=x;
	}
}
void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ)){
		pQ->Front=(pQ->Front+1)%(MaxLength-1);
		if(pQ->Front>pQ->Rear)
			makenullQueue(pQ);
	}
}
