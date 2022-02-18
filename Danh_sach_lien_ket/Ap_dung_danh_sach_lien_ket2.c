#include <stdio.h>
#include "PListLib.c"

List nhap(){
	List L;
	makenullList(&L);
	int n;
	scanf("%d", &n);
	int i,x;
	for (i=1; i<=n; i++){
		scanf("%d", &x);
		insertList(x, endList(L), &L);
	}
	return L;
}

void in(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		printf("%d ", retrieve(P, L));
		P=next(P, L);
	}
	printf("\n");
}

List Chan(List L){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if (P->Next->Element%2==0)
			insertList(P->Next->Element, endList(KQ), &KQ);
		P=next(P, L);
	}
	return KQ;	
}
List Le(List L){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if (P->Next->Element%2!=0)
			insertList(P->Next->Element, endList(KQ), &KQ);
		P=next(P, L);
	}
	return KQ;	
}

void deleteX(ElementType x, List *pL){
	Position P, E;
	P=first(*pL);
	E=endList(*pL);
	while(P!=E){
		if(x==retrieve(P, *pL)){
			deleteList(P, pL);
		}
			
		else P=next(P, *pL);
		E=endList(*pL);
	}
}

void swap(Position P, Position T, List *pL){
	ElementType x, y;
	x=retrieve(P, *pL);
	y=retrieve(T, *pL);
	deleteList(P, pL);
	insertList(y, P,pL);
	deleteList(T, pL);
	insertList(x, T, pL);
}
void sort(List *pL){
	Position P, I, E;
	P=first(*pL);
	E=endList(*pL);
	while(P!=E){
		I=next(P, *pL);
		while(I!=E){
			if(retrieve(P, *pL)>retrieve(I, *pL)){
				swap(P, I, pL);
			}
			I=next(I, *pL);
			E=endList(*pL);
		}
		P=next(P, *pL);
	}
//	if(retrieve(P, *pL)<retrieve(previous(P, *pL), *pL)){
//		
//		insertList(retrieve(P,*pL), first(*pL), pL);
//		deleteList(P, pL);
//	}
}
int main(){
	List L;
	L=nhap();
	in(L);
	sort(&L);
	in(L);
	return 0;
}
