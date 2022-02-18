#include<stdio.h>
#include"AListLib.c"
void insertSet(ElementType x, List *L){
	L->Elements[L->Last]=x; 
	L->Last++;
}
int member(ElementType x, List L){
	Position P;
	for (P=1; P<=L.Last; P++){
		if (x==L.Elements[P-1])
			return 1;
	}
	return 0;
}
void readList1(List *L){
	Position P;
	ElementType n, x;
	scanf("%d", &n);
	makenullList(L);
	for(P=1; P<=n; P++){
		scanf("%d", &x);
		if (member(x, *L)==0)
			insertSet(x, L);
	}
}
void readList2(List *L){
	Position P;
	ElementType n, x;
	scanf("%d", &n);
	makenullList(L);
	for(P=1; P<=n; P++){
		scanf("%d", &x);
		insertSet(x, L);
	}
}
void printList(List L){
	Position P;
	for (P=1; P<=L.Last; P++){
		printf("%d ", L.Elements[P-1]);
	}
	printf("\n");
}


void TapHop_khongtrung(List L1, List L2){
	Position P;
	for (P=1; P<=L1.Last; P++){
		printf("%d ", L1.Elements[P-1]);
	}
	for (P=1; P<=L2.Last; P++){
		if (member(L2.Elements[P-1], L1)==0 ){
			printf("%d ", L2.Elements[P-1]);
		}
	}
}
void TapHop_trung(List L1, List L2){
	Position P;
	for (P=1; P<=L1.Last; P++){
		if (member(L1.Elements[P-1], L2)){
			printf("%d ", L1.Elements[P-1]);
		}
	}
}

int countList(ElementType X, List L){
	Position P;
	ElementType count=0;
	
	for (P=first(L); P<endList(L); P=next(P, L)){
		if (X==L.Elements[P-1])
			count++;
	}
	return count;
}

void ascending(List *L){
	Position P, I;
	for (P=first(*L); P<endList(*L); P=next(P, *L)){
		for (I=next(P, *L); I<endList(*L); I=next(I, *L)){
			if (L->Elements[P-1]>L->Elements[I-1]){
				ElementType temp=L->Elements[P-1];
				L->Elements[P-1]=L->Elements[I-1];
				L->Elements[I-1]=temp;
			}
		}
	}
}

void odd_even(List L){
	Position P;
	for(P=1; P<=L.Last; P++){
		if (L.Elements[P-1]%2!=0)
			printf("%d ", L.Elements[P-1]);
	}
	printf("\n");
	P=first(L); 
	while(P!=endList(L)){
		if (L.Elements[P-1]%2==0)
			printf("%d ", L.Elements[P-1]);
		P=next(P, L);	
	}
}
int main(){
	List L1;
	readList2(&L1);
	printList(L1);
	odd_even(L1);
	return 0;
}
