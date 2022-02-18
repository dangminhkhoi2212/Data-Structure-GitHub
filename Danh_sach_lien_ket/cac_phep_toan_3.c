#include <stdio.h>
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

void insertList(ElementType x,Position P, List *pL){
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

Position next(Position P, List L){
	return P->Next;
}
Position previous(Position P, List L){
	Position I;
	for(I=first(L); I->Next!=NULL; I=next(I, L)){
		if(P==I)
			return I;
	}
}
void normalize(List *pL){
	Position P, I, E;
	P=first(*pL);
	E=endList(*pL);
	while(P!=E){
		I=next(P, *pL);
		while(I!=E){
			if (P->Next->Element==I->Next->Element){
				deleteList(I, pL);
			}
			else I=next(I, *pL);
		}
		P=next(P, *pL);
	}
}
ElementType retrieve(Position P, List L){
	return P->Next->Element;
}


void append(ElementType x, List *pL){
	insertList(x, endList(*pL), pL);
}

int member(ElementType x, List L){
	Position P;
	P=L;
	while(P->Next!=NULL){
		if (x==P->Next->Element)
			return 1;
		P=P->Next;
	}
	return 0;
}
List unionSet(List L1, List L2){
	List KQ;
	makenullList(&KQ);
	Position P;
	P=L1;
	while(P->Next!=NULL){
		append(P->Next->Element, &KQ);
		P=P->Next;
	}
	P=L2;
	while(P->Next!=NULL){
		if(!member(P->Next->Element, KQ))
			append(P->Next->Element, &KQ);
		P=P->Next;
	}
	return KQ;
}

float getAvg(List L){
	if(L->Next==NULL){
		return -10000;
	}
	Position P, E;
	P=L;
	float TB=0;
	int n=0;
	E=endList(L);
	while(P!=E){
		TB+=P->Next->Element;
		P=P->Next;
		n++;
	}
	return TB/n;
}
void copyEvenNumbers(List L1, List *pL2){
	makenullList(pL2);
	Position P, E;
	E=endList(L1);
	for(P=L1; P!=E; P=P->Next){
		if(P->Next->Element%2==0){
			append(P->Next->Element, pL2);
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

printf("&%d\n", endList(L1));

copyEvenNumbers(L1, &L2);
	
p=L2;
while(p->Next!=NULL)
{		
		printf("%d ",p->Next->Element);
		p=p->Next;
}
	return 0;
}


