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
	return (L->Next==0);
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
	if (emptyList(*pL)==0){
		Position Temp;
		Temp=(struct Node*)malloc(sizeof(struct Node));
		Temp= P->Next;
		P->Next=Temp->Next;
	}
}

ElementType retrieve(Position P, List L){
//	if (P->Next!=NULL){
		return P->Next->Element;
//	}
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

//Position locate(ElementType x, List L){
//    Position P;
//    P=L;
//    int k=0;
//    while(P!= NULL){
//        if (P->Next->Element==x)
//            return P;
//        else P=P->Next;
//    }
//}

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

void readList(List *pL){
	makenullList(pL);
	int I;
	ElementType n,x;
	scanf("%d", &n);
	for (I=1; I<=n; I++){
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}

void printOddNumbers(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if (P->Next->Element%2!=0)
			printf("%d ", P->Next->Element);
		P=P->Next;
	}
}

void append(ElementType x, List *L){
	insertList(x, endList(*L), L);
}

void copyEvenNumbers(List L, List *pL){
	makenullList(pL);
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if (retrieve(P, L)%2==0){
			insertList(retrieve(P, L), endList(*pL), pL);
		}
		P=P->Next;
	}
}

void normalize(List *pL){
	Position P, E, I;
	P=first(*pL);
	E=endList(*pL);
	while(P!=E){
		I=next(P, *pL);
		while (I!=E){
			if (retrieve(P, *pL)==retrieve(I, *pL))
				deleteList(P, pL);
			I=next(I, *pL);
		}
		P=next(P, *pL);
	}
}

int member(ElementType x, List L){
	Position P, E;
	P=first(L);
	E= endList(L);
	while (P!=E){
		if(x==P->Next->Element)
			return 1;
		P=next(P, L);
	}
	return 0;
}

 
int main(){
	
	
List L1,L2,L;
int i;

Position p;
makenullList(&L1);
makenullList(&L2);
for(i=1;i<=3;i++)
   append(i, &L1);
for(i=1;i<=5;i++)
   append(i, &L2);
L = difference(L1,L2);
p=L;
while(p->Next!=NULL)
{
   printf("%d ",p->Next->Element);
   p=p->Next;
}
	return 0;
}
