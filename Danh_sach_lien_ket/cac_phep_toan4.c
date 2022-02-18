#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}

Position first(List L){
	return L;
}
Position endList(List L){
	Position P;
	P=first(L);
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
void insertList(ElementType x, Position P, List *pL){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));

	T->Element=x;
	T->Next=P->Next;
	P->Next=T;
}
void deleteList(Position P, List *pL){
		Position T;
		T=P->Next;
		P->Next=T->Next;
		free(T);
}

void addFirst(ElementType x, List *pL){
	insertList(x, endList(*pL), pL);
}
Position next(Position P,List L){
	return P->Next;
}
Position previous(Position P, List L){
	Position I;
	I=first(L);
	while(I->Next!=P){
		I=I->Next;
	}
	return I;
}

ElementType retrieve(Position P, List L){
	return P->Next->Element;
}

void append(ElementType x, List *pL){
	insertList(x, endList(*pL), pL);
}

void sort(List *pL){
	Position P, E, I;
	E=endList(*pL);
	for(P=first(*pL); P!=E; P=next(P, *pL)){
		for(I=next(P, *pL); I!=E; I=next(I, *pL)){
			if (retrieve(P, *pL)>retrieve(I, *pL)){
				ElementType k;
				k=retrieve(P, *pL);
				P->Next->Element=retrieve(I, *pL);
				I->Next->Element=k;
			}
		}
	}
}

Position locate(ElementType x, List L){
	Position P;
	P=L;
	while(P->Next!=NULL){
		if (x==P->Next->Element)
			return P;
		P=P->Next;
	}
	return P;
}
int member(ElementType x, List L){
	Position P;
	P=L; 
	while(P->Next!=NULL){
		if (P->Next->Element==x)
			return 1;
		P=P->Next;
	}
	return 0;
}
void erase(ElementType x, List *pL){
	if(locate(x, *pL)->Next==NULL){
		printf("Not found %d\n", x);
	}
	else deleteList(locate(x, *pL), pL);
}

void readList(List *pL){
	makenullList(pL);
	int n, x,i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
//		append(x, pL);
		insertList(x, endList(*pL), pL);
	}
}
void copyEvenNumbers(List L1, List *pL2){
	makenullList(pL2);
	Position P, E;
	E=endList(L1);
	for(P=L1; P!=E; P=P->Next){
		if(P->Next->Element%2==0){
			append(retrieve(P, L1), pL2);
		}
	}
}

int main (){
List L1, L2;
Position p;
		
makenullList(&L1);

append(20, &L1);
append(21, &L1);
append(-5, &L1);
append(10, &L1);
append(-50, &L1);
	
	
copyEvenNumbers(L1, &L2);
	
p=L2;
while(p->Next!=NULL)
{		
		printf("%d ",p->Next->Element);
		p=p->Next;
}
	return 0;
}
