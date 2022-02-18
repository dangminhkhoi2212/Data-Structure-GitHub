#include<stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
	(*pL)= (struct Node*) malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}

int emptyList(List L){
	return (L->Next==NULL);
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
Position next(Position P, List L){
	return P->Next;
}
Position previous(Position P, List L){
	Position E;
	E=P;
	P=first(L);
	while(P!=E){
		if (next(P, L)==E)
			return P;
		else P=next(P, L);
	}
}
void insertList(ElementType x, Position P, List *pL){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=x;
	T->Next=P->Next;
	P->Next=T;
}

void deleteList(Position P, List *pL){
	if (!emptyList(*pL)){
		Position Temp;
		Temp= P->Next;
		P->Next=Temp->Next;
		free(Temp);
	}
}

ElementType retrieve(Position P, List L){
	if(!emptyList(L))
		return P->Next->Element;
}

Position locate(ElementType x, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	
	while(P!=E){
		if (P->Next->Element==x){
			return P;
		}
		else P=P->Next;
	}
}


Position mylocate(ElementType x, int i, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	ElementType count=0;
	while(P!=E && count<i){
		if (retrieve(P, L)==x){
			count++;
		}
		P=next(P, L);
	}
	return P;
}


