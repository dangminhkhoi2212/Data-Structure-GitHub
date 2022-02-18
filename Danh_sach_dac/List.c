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

//void insertList(ElementType x, Position P, List *L){
//	if (P==MaxLength)
//		printf("Danh sach day");
//	else if (P<first(*L) || P>endList(*L))
//		printf("Khong hop le!");
//	else{	
//		ElementType i;
//		for (i= L->Last; i>=P; i--){
//			L->Elements[i]=L->Elements[i-1];
//		}
//		L->Elements[P-1]=x;
//		L->Last++;
//	}
//
//}

void insertList(ElementType x, Position P, List *pL){
	Position I;
	for (I=pL->Last; I>=P; I--){
		pL->Elements[I]=pL->Elements[I-1];
	}
	pL->Elements[P-1]=x;
	pL->Last++;
}
//void deleteList(Position P, List *L){
//	if (P<first(*L) || P>endList(*L))
//		printf("Khong hop le!");
//	else if (emptyList(*L))
//			printf("Danh sach rong");
//	else{
//		ElementType i;
//		for (i=P; i<L->Last; i++){
//			L->Elements[i-1]=L->Elements[i];
//		}
//		L->Last--;
//		
//	}
//	
//}

ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}


//Position locate(ElementType x, List L){
//	Position i=1;
//	while(i!=endList(L)){
//		if (L.Elements[i-1]==x)
//			return i;
//		else i++;
//	}
//	
//}

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



void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last]=x;
	pL->Last++;
	
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
ElementType member(ElementType x, List L){
	ElementType p;
	for(p=1; p<=L.Last; p++){
		if(x==L.Elements[p-1])
			return 1;
	}
	return 0;
}
//
//void unionSet(List L1,List L2, List *pL){
//	makenullList(pL);
//	ElementType p;
//	for (p=1; p<=L1.Last; p++){
//		insertSet(L1.Elements[p-1], pL);
//	}
//	for (p=1; p<=L2.Last; p++){
//		if(member(L2.Elements[p-1], *pL)==0){
//			insertSet(L2.Elements[p-1], pL);
//		}
//	}
//}

//void removeAll(ElementType x, List *pL){
//	Position p;
//	deleteList(locate(x, *pL), pL);
//	for (p=1; p<=pL->Last; p++){
//		if(locate(x, *pL)==p)
//			deleteList(p, pL);
//	}
//}

//void printOddNumbers(List L){
//	Position P;
//	for (P=1; P<=L.Last;P++){
//		if(L.Elements[P-1]%2!=0)
//			printf("%d ", L.Elements[P-1]);
//	}
//}

//void copyEvenNumbers(List L1, List *pL2){
//	makenullList(pL2);
//	Position p;
//	for(p=1; p<=L1.Last; p++){
//		if (L1.Elements[p-1]%2==0){
//			insertList(L1.Elements[p-1], pL2->Last+1, pL2);
//		}
//	}	
//}



float TBC(List L){
	Position P;
	float S=0;
	for(P=1;P<=L.Last;P++){
		S+=L.Elements[P-1];
	}
	return (S*1.0)/L.Last;
}

void deletefirst(ElementType x,List *L){
	deleteList(locate(x,*L), L);
}

//void readList(List *L){
//	scanf("%d", &L->Last);
//	Position P;
//	for (P=1; P<=L->Last; P++ ){
//		scanf("%d", &L->Elements[P-1]);
//	}
//}

void printList(List L){
	Position P;
	for (P=1; P<=L.Last; P++){
		printf("%d ", L.Elements[P-1]);
	}
	printf("\n");
}



void deleteAll(ElementType x, List *L){
	Position P;
		for (P=1; P<=L->Last; P++){
			if (L->Elements[P-1]==x){
				deleteList(P, L);
				P--;
			}		
	}
}

void normalize(List *pL){
	Position P,I;
	P=1; 
	while (P!=pL->Last+1){
		I=P+1;
		while (I!=pL->Last+1){
			if (pL->Elements[I-1]==pL->Elements[P-1]){
				deleteList (I, pL);
			}
			else I++;
		}
		P++;
	}
}

float getAvg(List L){
	Position P;
	if (L.Last==0){
		return  -10000.0000;
	}
	float S=0;
	for(P=1; P<=L.Last; P++){
		S+=L.Elements[P-1];
	}
	return S*1.0/L.Last;
}
void dsRong(List *L){
	L->Last=0;
}
void readList(List *pL){
    Position P;
    ElementType x, n;
    makenullList(pL);
    scanf("%d", &n);
    for (P=1; P<=n; P++){
    	scanf("%d", &x);
        insertList(x,pL->Last+1, pL);
    }
}
void difference(List L1, List L2, List *pL){
    Position P, I;
    dsRong(pL);
    for (P=1; P<=L1.Last ; P++){
    	for (I=1; I<=L2.Last; I++){
    		if (member(L1.Elements[P-1], L2)==0){
    			insertSet(L1.Elements[P-1], pL);
    			break;
			}
		}
	}
}


void sort(List *pL){
	Position P, I;
	ElementType temp;
	for (P=1; P<=pL->Last; P++){
		for (I=P+1; I<=pL->Last; I++){
			if(pL->Elements[P-1]>pL->Elements[I-1]){
				temp=pL->Elements[P-1];
				pL->Elements[P-1]=pL->Elements[I-1];
				pL->Elements[I-1]=temp;
			}
		}
	}
}

void intersection(List L1, List L2, List *pL){
	Position P, I;
	makenullList(pL);
	for (P=1; P<=L1.Last; P++){
		for(I=1; I<=L2.Last; I++){
			if (member(L1.Elements[P-1], L2))
				insertSet(L1.Elements[P-1], pL);
				break;
		}
	}
}

void readSet(List *pL){
	Position P;
	ElementType n, x;
	scanf("%d", &n);
	makenullList(pL);
	for (P=1; P<=n; P++){
		scanf ("%d", &x);
		if (member(x, *pL)==0)
			insertSet(x, pL);
	}
}

void copyEvenNumbers(List L1, List *pL2){
	Position P;
	makenullList(pL2);
	for (P=1; P<=L1.Last; P++){
		if (L1.Elements[P-1]%2==0)
			insertList(L1.Elements[P-1],pL2->Last+1, pL2);
	}
}

Position locate(ElementType x, List L){
	Position P;
	for (P=1; P<=L.Last; P++){
		if (x=L.Elements[P-1])
			return P;
	}
	return L.Last++;
}

void printOddNumbers(List L){
	Position P=1;
	while(P<=L.Last){
		if (L.Elements[P-1]%2!=0)
			printf("%d", L.Elements[P-1]);
		P++;
	}
}

void unionSet(List L1, List L2, List *pL){
	Position P=1, I;
	makenullList(pL);
	while(P!=L1.Last){
		insertSet(L1.Elements[P-1], pL);
		P++;
	}
	P=1;
	while(P!=L2.Last){
		if (member(L2.Elements[P-1], *pL)==0)
			insertSet(L2.Elements[P-1], pL);
		P++;
	}
}
int main(){			
List L1,L2;
int i;
makenullList(&L1);
insertList(-7, L1.Last+1, &L1);
insertList(6, L1.Last+1, &L1);
insertList(-70, L1.Last+1, &L1);
insertList(21, L1.Last+1, &L1);
insertList(29, L1.Last+1, &L1);

copyEvenNumbers(L1, &L2);

for(i=0;i<L1.Last;i++){
    printf("%d ",L1.Elements[i]);
}
printf("\n");
for(i=0;i<L2.Last;i++)
   { printf("%d ",L2.Elements[i]);}
}


