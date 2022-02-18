#include <stdio.h>
#include "PListLib.c"


int member(ElementType x, List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if(x==retrieve(P, L))
			return 1;
		P=next(P, L);
	}
	return 0;
	
}
void read(List *pL){
	makenullList(pL);
	int i, n,x;
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		scanf("%d", &x);
//		if(member(x, *pL)==0)
			insertList(x, endList(*pL), pL);
	}
}

void print(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		printf("%d ", retrieve(P, L));
		P=next(P, L);
	}
	printf("\n");
}

List taphop(List L1, List L2){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	P=first(L1);
	E=endList(L1);
	while(P!=E){
		if (member(retrieve(P, L1), L2)==0){
			insertList(retrieve(P, L1),endList(KQ), &KQ);
		}
		P=next(P, L1);
	}
	return KQ;
	
}

float average(List L){
	Position P, E;
	P=first(L);
	E=endList(L);
	int avg=0;
	int count=0;
	while(P!=E){
		avg+=retrieve(P, L);
		count++;
		P=next(P, L);
	}
	return (float)avg/count;
}
List even(List L){
	List KQ;
	makenullList(&KQ);
	Position P, E;
	P=first(L);
	E=endList(L);
	while(P!=E){
		if(retrieve(P, L)%2==0)
			insertList(retrieve(P, L),endList(KQ), &KQ);
		P=next(P, L);
	}
	return KQ;
}
int main(){
	List L;
	read(&L);
	print(L);
	List L2;
	L2=even(L);
	print(L2);
	float avg;
	avg=average(L2);
	printf("%.3f", avg);
	return 0;
}
