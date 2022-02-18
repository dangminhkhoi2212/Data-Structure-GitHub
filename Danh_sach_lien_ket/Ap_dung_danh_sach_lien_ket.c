#include <stdio.h>
#include "PListLib.c"


void append(ElementType x, List *pL){
	insertList(x, first(*pL), pL);
}
int member(ElementType x, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while (P!=E){
		if (retrieve(P, L)==x)
			return 1;
		P=next(P, L);
	}
	return 0;
}
List read(){
	List L;
	makenullList(&L);

	ElementType x, n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		scanf("%d", &x);
		if (member(x, L)==0){
			append(x, &L);
//			insertList(x, endList(L), &L);
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

List taphop(List L1, List L2){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	E=endList(L1);
	for(P=first(L1); P!=E; P=next(P, L1)){
		if (member(retrieve(P, L1), L2)==0){
			insertList(retrieve(P, L1), endList(KQ), &KQ);
		}
	}
	return KQ;
}

List taphop2(List L1, List L2){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	E=endList(L1);
	for(P=first(L1); P!=E; P=next(P, L1)){
			insertList(retrieve(P, L1), endList(KQ), &KQ);
	}
	E=endList(L2);
	for(P=first(L2); P!=E; P=next(P, L2)){
		if (member(retrieve(P, L2), KQ)==0){
			insertList(retrieve(P, L2), endList(KQ), &KQ);
		}
	}
	return KQ;
}
void deleteFirst(ElementType x, List *pL){
	Position P, E;
	P=first(*pL);
	E=endList(*pL);
	while (P!=E){
		if (locate(x, *pL)==P){
			deleteList(P, pL);
			break;
		}
		P=next(P, *pL);
	}
}
int main(){
	List L1 ,L2, L ;
	L1=read();
	L2=read(&L2);
	print(L1);
	print(L2);
	L=taphop2(L1, L2);
	print(L);
	return 0;
}
