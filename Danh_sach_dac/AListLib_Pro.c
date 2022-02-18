#include<stdio.h>

#define MaxLength 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLength];
	ElementType Last;
}List;

void makenullList(List *L){
	L->Last=0;
}

int emptyList(List L){
	return L.Last==0;
}

int fullList(List L){
	return L.Last==MaxLength;
}

Position first(List L){
	return 1;
}

Position endList(List L){
	return L.Last+1;
}

void insertList(ElementType x, Position P, List *L){
	if (P==MaxLength)
		printf("Danh sach day");
	else if (P<first(*L) || P>endList(*L))
		printf("Khong hop le!");
	else{	
		ElementType i;
		for (i= L->Last; i>=P; i--){
			L->Elements[i]=L->Elements[i-1];
		}
		L->Elements[P-1]=x;
		L->Last++;
	}

}


void deleteList(Position P, List *L){
	if (P<first(*L) || P>endList(*L))
		printf("Khong hop le!");
	else if (emptyList(*L))
			printf("Danh sach rong");
	else{
		ElementType i;
		for (i=P; i<L->Last; i++){
			L->Elements[i-1]=L->Elements[i];
		}
		L->Last--;
		
	}
	
}

ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}


Position locate(ElementType x, List L){
	Position i=1;
	while(i!=endList(L)){
		if (L.Elements[i-1]==x)
			return i;
		else i++;
	}
	
}

Position next(Position P, List L){
	if (P==L.Last)
		return endList(L);
	else if(P<first(L) || P>L.Last)
			printf("Khong xac dinh");
	else return P+1;
}

Position previous(Position P, List L){
	if (P==first(L) || P>endList(L))
		printf("Khong xac dinh");
	else return P-1;		  
}

void printList(List L){
	ElementType i;
	for (i=first(L)-1; i<=(L.Last); i++){
		printf("%d ", L.Elements[i]);
	}
}

void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last]=x;
	pL->Last++;
	
}
Position member(ElementType x, List L){
	ElementType p;
	for(p=1; p<=L.Last; p++){
		if(x==L.Elements[p-1])
			return p;
	}
	return L.Last++;
}

void unionSet(List L1,List L2, List *pL){
	makenullList(pL);
	ElementType p;
	for (p=1; p<=L1.Last; p++){
		insertSet(L1.Elements[p-1], pL);
	}
	for (p=1; p<=L2.Last; p++){
		if(member(L2.Elements[p-1], *pL)==0){
			insertSet(L2.Elements[p-1], pL);
		}
	}
}

//void removeAll(ElementType x, List *pL){
//	Position p;
//	deleteList(locate(x, *pL), pL);
//	for (p=1; p<=pL->Last; p++){
//		if(locate(x, *pL)==p)
//			deleteList(p, pL);
//	}
//}

void printOddNumbers(List L){
	Position P;
	for (P=1; P<=L.Last;P++){
		if(L.Elements[P-1]%2!=0)
			printf("%d ", L.Elements[P-1]);
	}
}

void copyEvenNumbers(List L1, List *pL2){
	makenullList(pL2);
	Position p;
	for(p=1; p<=L1.Last; p++){
		if (L1.Elements[p-1]%2==0){
			insertList(L1.Elements[p-1], pL2->Last+1, pL2);
		}
	}	
}
struct DonThuc{
    double he_so;
    int bac;
} ;
struct DaThuc{
    struct DonThuc A[100];
    int so_luong;
};



int main(){
	return 0;
}