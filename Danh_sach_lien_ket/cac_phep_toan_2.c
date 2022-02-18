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

Position next(Position P, List L){
	return P->Next;
}
Position previous(Position P, List L){
	Position E;
	E=L;
	while(E->Next!=P){
		E=E->Next;
	}
	return E;
}

ElementType retrieve(Position P, List L){
	if (P->Next!=NULL)
		return P->Next->Element;
}

Position locate(ElementType x, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while (P!=E){
		if (retrieve(P, L)==x)
			return P;
		P=next(P, L);
	}
	return P;
}
void insertList(ElementType x, Position P, List *pL){
	Position E;
	makenullList(&E);
	E->Element=x;
	E->Next=P->Next;
	P->Next=E;
}

void deleteList(Position P, List *pL){
	Position I;
	I=P->Next;
	P->Next=I->Next;
	free(I);
}
int member(ElementType x, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if (P->Next->Element==x)
			return 1;
		P=P->Next;
	}
	return 0;
	
}
void erase(ElementType x, List *pL){
	Position P, E;

	P=first(*pL);
	E=endList(*pL);
	if (locate(x, *pL)==E){
		printf("Not found %d\n", x);
	}
	else {
		while (P!=E){
			if (locate(x, *pL)==P){
				deleteList(P, pL);
				break;
			}
			P=next(P, *pL);
		}	
	}
}

void addFirst(ElementType x, List *pL){
	Position T;
	makenullList(&T);
	T->Element=x;
	T->Next=(*pL)->Next;
	(*pL)->Next=T;
}

void removeAll(ElementType x, List *pL){
	Position P, E;
	P=first(*pL);
	E=endList(*pL);

	while (P!=E){
		if (locate(x, *pL)==P){
			deleteList(P, pL);
			E=endList(*pL);
		}
		else  P=P->Next;	
	}
}
void deleteX(ElementType X, List *pL){
	Position P, E;
	P=first(*pL);
	E=endList(*pL);
	while (P!=E){
		if(locate(X, *pL)==P){
			deleteList(P, pL);
		}
		else P=P->Next;
	}
}

List readSet(){
	List L;
	makenullList(&L);
	ElementType n, x,i;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		scanf("%d", &x);
		if (member(x, L)==0){
			addFirst(x, &L);
		}
	}
	return L;
}

void print(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while (P!=E){
		printf("%d ", retrieve(P, L));
		P=next(P, L);
	}
	printf("\n");
	
}
void append(ElementType x, List *pL){
	insertList(x, endList(*pL), pL);
}
void hoanvi(ElementType *a, ElementType *b){
	ElementType c;
	c=*a;
	*a=*b;
}
void sort(List *pL){
	Position P, I, E;
	P=first(*pL);
	E=endList(*pL);
	while(P!=E){
		I=next(P, *pL);
		while(I!=E){
			if (retrieve(P, *pL)>retrieve(I, *pL)){
				ElementType TempK;
				TempK=retrieve(P, *pL);
				P->Next->Element=retrieve(I, *pL);
				I->Next->Element=TempK;
			}
			I=next(I, *pL);		
		}
		P=next(P, *pL);
	}
}

List intersection(List L1, List L2){
	List L;
	makenullList(&L);
	Position P,E;
	E=endList(L1);
	for (P=first(L1); P!=E; P=next(P, L1)){
			if (member(retrieve(P, L1), L2)){
				append(retrieve(P, L1), &L);
			}
	}
	return L;
}
int main(){
List L1,L2,L;
int i;
	
Position p;
makenullList(&L1);
makenullList(&L2);
for(i=1;i<=3;i++)
	append(i, &L1);
for(i=-10;i<=2;i++)
	append(i, &L2);
L = intersection(L1,L2);
p=L;
while(p->Next!=NULL)
{
		printf("%d ",p->Next->Element);
		p=p->Next;
}
	return 0;
}
